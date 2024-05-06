#ifndef S21_RB_TREE_HPP
#define S21_RB_TREE_HPP

#include <functional>        // std::less
#include <initializer_list>  // std::initializer_list
#include <limits>            // std::numeric_limits
#include <stdexcept>
#include <vector>

namespace s21 {

template <typename Key, typename Compare = std::less<Key>>
class rb_tree {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_referencce = const value_type&;

  using size_type = std::size_t;

  enum rb_tree_color { black,
                       red };

  struct node {
    node *parent_, *left_, *right_;
    value_type key_;
    rb_tree_color color_;
    node() : parent_(nullptr), left_(nullptr), right_(nullptr), key_(value_type{}), color_(rb_tree_color::red){};  // default ctor
    node(const node& other) = delete;
    node(const node&& other) = delete;
    node operator=(const node& other) = delete;
    node operator=(const node&& other) = delete;
    ~node() = default;

    node(const value_type& key) : parent_(nullptr), left_(nullptr), right_(nullptr), key_(key), color_(rb_tree_color::red){};
    node(const value_type& key, rb_tree_color color) : parent_(nullptr), left_(nullptr), right_(nullptr), key_(key), color_(color){};

    void switch_color() {
      if (color_ == black) {
        color_ = red;
      } else {
        color_ = black;
      }
    }
  };

  node* headptr_;
  // Узел end_ будет одновременно началом (в смысле структуры)
  // и концом ( в смысле итераторов).
  // Все остальные узлы, находятся в левом и правом одновременно поддеревьях узла end_.
  node* endptr_;
  std::size_t size_;
  Compare cmp_{};

 public:
  class iterator {
    friend class rb_tree;
    using value_type = Key;
    using difference_type = std::ptrdiff_t;
    using reference = Key&;
    using pointer = Key*;
    using iterator_category = std::bidirectional_iterator_tag;

    node* ptr_;

   public:
    iterator() = delete;
    iterator(node* nodeptr) : ptr_(nodeptr) {}
    // Copy ctor
    iterator(const iterator& other) { ptr_ = other.ptr_; }
    iterator(iterator&& other) {
      ptr_ = other.ptr_;
      other.ptr_ = nullptr;
    }
    // Copy assigment
    iterator& operator=(const iterator& other) {
      ptr_ = other.ptr_;
      return *this;
    }
    // Move assigment
    iterator& operator=(iterator&& other) {
      ptr_ = other.ptr_;
      other.ptr_ = nullptr;
      return *this;
    }
    // Destructible
    ~iterator() = default;

    value_type& operator*() {
      return ptr_->key_;
    }

    iterator operator++() {
      ptr_ = node_increment(this->ptr_) ;
      return *this;
    }

    iterator operator++(int) {
      iterator old(*this);
      this->ptr_ = node_increment(this->ptr_);
      return old;
    }

    iterator operator--() {
      ptr_ = node_decrement(this->ptr_) ;
      return *this;
    }

    iterator operator--(int) {
      iterator old(*this);
      this->ptr_ = node_decrement(this->ptr_);
      return old;
    }

    bool operator==(const iterator& other) const {
      return this->ptr_ == other.ptr_;
    }

    bool operator!=(const iterator& other) const {
      return this->ptr_ != other.ptr_;
    }
  };

  /*
      Member functions
  */

  // default ctor
  rb_tree() : headptr_(nullptr), endptr_(new node()), size_(0) {
    endptr_->parent_ = endptr_;
  }

  // init-list ctor
  // duplicates are not allowed
  rb_tree(std::initializer_list<value_type> init_list) : rb_tree() {
    for (value_type value : init_list) {
      insert(value);
    }
  }

  // copy ctor
  rb_tree(const rb_tree& other) : rb_tree() {
    for(auto key: other){
      insert(key);
    }
  }

  // move ctor
  rb_tree(rb_tree&& other) noexcept : rb_tree() {
    std::swap(endptr_, other.endptr_);
    std::swap(headptr_, other.headptr_);
    std::swap(size_, other.size_);
  }

  // destructor
  ~rb_tree() {
    clear();
    delete endptr_;
  }

  // copy assigment
  rb_tree& operator=(const rb_tree& other) {
    clear();
    for(auto key: other){
      insert(key);
    }
    return *this;
  }

  // move assigment
  rb_tree& operator=(rb_tree&& other) {
    clear();
    std::swap(endptr_, other.endptr_);
    std::swap(headptr_, other.headptr_);
    std::swap(size_, other.size_);
    return *this;
  }

  /*
      Iterators
  */

  iterator begin() const {
    return iterator(leftmost(endptr_));
  }

  iterator end() const {
    return iterator(endptr_);
  }

  /*
      Capacity
  */

  bool empty() const {
    return size_ == 0;
  }

  size_type size() const {
    return size_;
  }

  size_type max_size() const {
    // 5 memory allocations
    return std::numeric_limits<size_type>::max() / (sizeof(char*) * 2 * 5);
  }

  /*
      Modifiers
  */

  /// @brief Clears the content.
  void clear() {
    node* nodeptr = headptr_;
    node* to_delete = nullptr;
    if (nodeptr != nullptr) {
      while (nodeptr != endptr_) {
        if (nodeptr->left_) {
          nodeptr = nodeptr->left_;
        } else if (nodeptr->right_) {
          nodeptr = nodeptr->right_;
        } else {
          to_delete = std::exchange(nodeptr, nodeptr->parent_);
          delete_node(to_delete);
          delete to_delete;
        }
      }
    }
    endptr_->left_ = nullptr;
    endptr_->right_ = nullptr;
    headptr_ = nullptr;
    size_ = 0;
  }

  /// @brief Value duplicates ignores if already contains.
  /// @param value Value to insert
  /// @return Iterator to where the
  /// element is in the container and bool denoting
  /// whether the insertion took place.
  std::pair<iterator, bool> insert(const value_type& value) {
    node* x = new node(value);
    bool successfull = btree_insert(x);
    iterator it = end();
    if (successfull) {
      it = iterator(x);
      node* K = x;
      size_++;
      // Case 1: T is empty
      // If T is empty, we make K the root of the tree and color it black.
      if (K == headptr_) {
        K->color_ = black;
      }
      // Case 2: P is black.
      // If K's parent node P is black, it can not violate any properties.
      // Therefore, in this case, we do not need to do anything.
      else if (K->parent_->color_ == black) {
      }
      // Case 3: P is red.
      // If the parent node P is red, this violates the property 4.
      // P and K are now both red. The grandparent node G must be black node
      // because the tree before insertion must be a valid red-black tree.
      // To resolve this case, we need to check whether K's uncle U is red or black.
      else {
        while (K->parent_->color_ == red) {
          node* P = K->parent_;
          node* G = K->parent_->parent_;
          node* U;
          // P is right child
          if (G->right_ == P) {
            U = G->left_;
            // Case 3.2: P is red and U is black (or NULL)
            // This is more complicated than case 3.1. If th uncle node U is black
            // we need single or double tree rotations depending upon whether K is
            // a left or right child of P.
            if (U == nullptr or U->color_ == black) {
              // Case 3.2.1: P is right child of G and K is right child of P.
              // We first perform the left-rotation at G that makes G the new sibling S of K.
              // Next, we change the color of S to red anp P to black.
              if (K == P->right_) {
                left_rotation(G);
                P->switch_color();
                G->switch_color();  // is sibling S after rotation;
              }
              // Case 3.2.2: P is right child of G and K is left child of P.
              // In this case, we first do the right-rotation at P. This reduces it to the case
              // 3.2.1. We next use the rules given in case 3.2.1 to fix the tree.
              else {
                right_rotation(P);
                K = P;  // continue to fix the tree
              }
            }
            // Case 3.1: P is red and U is red too.
            // In this case, we flip the color of nodes P,U, and G. That means,
            // P becomes black, U becomes black and G becomes red.
            //
            // One thing we need to be careful in this case when G is a root of T.
            // If that is the case, we do not recolor G as it violates property 2.
            else {
              P->switch_color();
              U->switch_color();
              if (G != headptr_) {
                G->switch_color();
                K = G;
              }
            }
          }
          // mirror cases
          else {
            U = G->right_;
            // Case 3.2
            if (U == nullptr or U->color_ == black) {
              // Case 3.2.3: P is left child of G and K is left child of P.
              // This is the mirror of case 3.2.1. Therefore the solution is
              // symmetric to the solution of case 3.2.1
              if (K == P->right_) {
                right_rotation(G);
                P->switch_color();
                G->switch_color();  // is sibling S after rotation;
              }
              // Case 3.2.4: P is left child of G and K is right child op P.
              // This is the mirror of case 3.2.2. Therefore the solution is
              // symmetric to the solution of case 3.2.2
              else {
                left_rotation(P);
                K = P;  // continue to fix the tree
              }
            }
            // Case 3.1
            else {
              P->switch_color();
              U->switch_color();
              if (G != headptr_) {
                G->switch_color();
                K=G;
              }
            }
          }
        }
      }

    } else {
      delete x;
      return std::pair<iterator, bool>(end(), successfull);
    }
    
    return std::pair<iterator, bool>(it, successfull);
  }

  /// @brief Unlike insert, allows to insert duplicates.
  /// @param value Value to insert.
  /// @return Iterator to where the element is.
  iterator multiinsert(const value_type& value) {
    node* x = new node(value);
    btree_multiinsert(x);
    iterator it = iterator(x);
    node* K = x;
    size_++;
    // Case 1: T is empty
    // If T is empty, we make K the root of the tree and color it black.
    if (K == headptr_) {
      K->color_ = black;
    }
    // Case 2: P is black.
    // If K's parent node P is black, it can not violate any properties.
    // Therefore, in this case, we do not need to do anything.
    else if (K->parent_->color_ == black) {
    }
    // Case 3: P is red.
    // If the parent node P is red, this violates the property 4.
    // P and K are now both red. The grandparent node G must be black node
    // because the tree before insertion must be a valid red-black tree.
    // To resolve this case, we need to check whether K's uncle U is red or black.
    else {
      while (K->parent_->color_ == red) {
        node* P = K->parent_;
        node* G = K->parent_->parent_;
        node* U;
        // P is right child
        if (G->right_ == P) {
          U = G->left_;
          // Case 3.2: P is red and U is black (or NULL)
          // This is more complicated than case 3.1. If th uncle node U is black
          // we need single or double tree rotations depending upon whether K is
          // a left or right child of P.
          if (U == nullptr or U->color_ == black) {
            // Case 3.2.1: P is right child of G and K is right child of P.
            // We first perform the left-rotation at G that makes G the new sibling S of K.
            // Next, we change the color of S to red anp P to black.
            if (K == P->right_) {
              left_rotation(G);
              P->switch_color();
              G->switch_color();  // is sibling S after rotation;
            }
            // Case 3.2.2: P is right child of G and K is left child of P.
            // In this case, we first do the right-rotation at P. This reduces it to the case
            // 3.2.1. We next use the rules given in case 3.2.1 to fix the tree.
            else {
              right_rotation(P);
              K = P;  // continue to fix the tree
            }
          }
          // Case 3.1: P is red and U is red too.
          // In this case, we flip the color of nodes P,U, and G. That means,
          // P becomes black, U becomes black and G becomes red.
          //
          // One thing we need to be careful in this case when G is a root of T.
          // If that is the case, we do not recolor G as it violates property 2.
          else {
            P->switch_color();
            U->switch_color();
            if (G != headptr_) {
              G->switch_color();
                K=G;
            }
          }
        }
        // mirror cases
        else {
          U = G->right_;
          // Case 3.2
          if (U == nullptr or U->color_ == black) {
            // Case 3.2.3
            if (K == P->left_) {
              right_rotation(G);
              P->switch_color();
              G->switch_color();  // is sibling S after rotation;
            }
            // Case 3.2.4
            else {
              left_rotation(P);
              K = P;  // continue to fix the tree
            }
          }
          // Case 3.1
          else {
            P->switch_color();
            U->switch_color();
            if (G != headptr_) {
              G->switch_color();
                K=G;
            }
          }
        }
      }
    }
    return it;
  }

  void erase(const iterator it) {
    // Let S and P are sibling and parent nodes of K.
    node* K = it.ptr_;
    if (K == endptr_) {
      return;
    }
    --size_;
    // If K has 2 childs, it value swap with max node in left subtree
    if (K->left_ && K->right_) {
      node* Swappable = rightmost(K->left_);
      K->key_ = std::move(Swappable->key_);
      K = Swappable;  // Now K has 1 or 0 child
    }
    // K1 is a red node with one child. If the red node does not have
    // one child, then there is a black NIL element instead and the
    // black height of the red node is 1. Hence, on the other side
    // the black height must also be 1. But since a red node cannot
    // have a red child, its other child must be black. Since the
    // black height must be equal to 1, it can only be a black NIL
    // element, since the height will be higher in the case of a regular
    // black element.
    // Thus, the K1 case does not occur.

    // If K has 1 child (possible only if K is black)
    // If a black element does not have one child, then there is a black
    // NIL element with black height 1 instead. Therefore, there must be
    // a red node without children on the other side. To remove such an
    // element, just move the value of the red element to the black node,
    // the black height will be preserved.
    if (K->left_) {
      K->left_->color_ = black;
      K->left_->parent_ = K->parent_;
      if (K == headptr_) {
        K->parent_->left_ = K->left_;
        K->parent_->right_ = K->left_;
        headptr_ = K->left_;

      } else if (K == K->parent_->left_) {
        K->parent_->left_ = K->left_;
      } else {
        K->parent_->right_ = K->left_;
      }
      delete K;
      return;
    } else if (K->right_) {
      K->right_->color_ = black;
      K->right_->parent_ = K->parent_;
      if (K == headptr_) {
        K->parent_->left_ = K->right_;
        K->parent_->right_ = K->right_;
        headptr_ = K->right_;
      } else if (K == K->parent_->left_) {
        K->parent_->left_ = K->right_;
      } else {
        K->parent_->right_ = K->right_;
      }
      delete K;
      return;
    }

    // K has 0 childs.
    if (K->left_ == nullptr && K->right_ == nullptr) {
      // If K color is red.
      // Simply delete node, thus it is do not violate tree properties
      if (K->color_ == red) {
        delete_node(K);
        delete K;
      }
      // If K color is black.
      else {
        fixDelete(K);
      }
    }
  }

  //	swaps the contents
  void swap(rb_tree& other) {
    std::swap(headptr_, other.headptr_);
    std::swap(endptr_, other.endptr_);
    std::swap(size_, other.size_);
  }

  /// @brief Splices nodes from another tree.
  /// Doesn't support duplicates.
  void merge(const rb_tree& other) {
    for(auto key: other){
      insert(key);
    }
  }

  /// @brief Splices nodes from another multitree.
  /// Support duplicates.
  void multimerge(const rb_tree& other) {
    for(auto key: other){
      multiinsert(key);
    }
  }

  /*
      Lookup
  */

  /*
   * @brief Сhecks if there is an element with key equivalent to key in the containerю
   * @param key Value to search.
   * @return bool 1 - if contains, 0 - vice versa.
   */
  bool contains(const key_type& key) {
    node* curr = headptr_;
    [[maybe_unused]] node* prev;
    while (curr) {
      if (cmp_(key, curr->key_)) {
        prev = std::exchange(curr, curr->left_);
      } else if (cmp_(curr->key_, key)) {
        prev = std::exchange(curr, curr->right_);
      } else {
        return true;
      }
    }
    return false;
  }

  // An iterator to the requested element.
  // If no such element is found, past-the-end iterator is returned.
  iterator find(const key_type& key) {
    node* nodeptr = headptr_;
    iterator it(endptr_);
    while (nodeptr != nullptr) {
      if (cmp_(key, nodeptr->key_)) {
        nodeptr = nodeptr->left_;
      } else if (cmp_(nodeptr->key_, key)) {
        nodeptr = nodeptr->right_;
      } else {
        it = iterator(nodeptr);
        break;
      }
    }
    return it;
  }

  /*
  @brief Returns the number of elements mathcing specific key.
  */
  size_type count(const key_type& key) {
    size_type counter = 0;
    for (value_type value : *this) {
      if (value == key) {
        counter++;
      }
    }
    return counter;
  }

  /*
    @brief Returns a range containing all elements with the given key in the container.
  The range is defined by two iterators, one pointing to the first element that
  is not less than key and another pointing to the first element greater than key.
  Alternatively, the first iterator may be obtained with lower_bound(),
  and the second with upper_bound().
    @param key key value to compare the elements to.
    @return std::pair containing a pair of iterators defining the wanted range:
  the first pointing to the first element that is not less than key
  and the second pointing to the first element greater than key.
  If there are no elements not less than key, past-the-end iterator
  is returned as the first element. Similarly if there are no elements
  greater than key, past-the-end iterator is returned as the second element.
  */
  std::pair<iterator, iterator> equal_range(const key_type& key) {
    iterator start = begin(), end_iterator = end();
    while (cmp_(*start, key) && start != end_iterator) {
      start++;
    }
    iterator finish = start;
    while (!cmp_(key, *finish) && finish != end_iterator) {
      finish++;
    }
    return std::pair<iterator, iterator>(start, finish);
  }

  /*
    @brief Returns an iterator pointing to the first element that
  is not less than (i.e. greater or equal to) key.
    @param key key value to compare the elements to.
    @return Iterator pointing to the first element that
  is not less than key. If no such element is found, a
  past-the-end iterator is returned.
  */
  iterator lower_bound(const Key& key) {
    iterator it = begin(), end_iterator = end();
    while (cmp_(*it, key) && it != end_iterator) {
      it++;
    }
    return it;
  }

  /*
    @brief Returns an iterator pointing to the first element that
  is greater than (i.e. greater or equal to) key.
    @param key key value to compare the elements to.
    @return Iterator pointing to the first element that
  is greater than key. If no such element is found, a
  past-the-end iterator is returned.
  */
  iterator upper_bound(const Key& key) {
    iterator it = lower_bound(key), end_iterator = end();
    while (!cmp_(key, *it) && it != end_iterator) {
      it++;
    }
    return it;
  }

  /*
      Insert many
  */

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    std::vector<std::pair<iterator, bool>> vec;
    (vec.emplace_back(insert(std::forward<Args>(args))), ...);
    return vec;
  }



  template <typename... Args>
  std::vector<std::pair<iterator, bool>> multiinsert_many(Args&&... args) {
    std::vector<std::pair<iterator, bool>> vec;
    (vec.emplace_back(std::pair<iterator, bool>{multiinsert(std::forward<Args>(args)), true}), ...);
    return vec;
  }

 private:
  node* leftmost(node* ptr) const {
    while (ptr->left_) {
      ptr = ptr->left_;
    }
    return ptr;
  }

  node* rightmost(node* ptr) const {
    while (ptr->right_) {
      ptr = ptr->right_;
    }
    return ptr;
  }

  void left_rotation(node* x) {
    if (x->right_) {
      node* y = x->right_;
      x->right_ = y->left_;
      if (y->left_ != nullptr) {
        y->left_->parent_ = x;
      }
      y->left_ = x;

      y->parent_ = x->parent_;
      if (x->parent_ == endptr_) {
        headptr_ = y;
        endptr_->left_ = y;
        endptr_->right_ = y;
      } else if (x->parent_->left_ == x) {
        x->parent_->left_ = y;
      } else {
        x->parent_->right_ = y;
      }
      x->parent_ = y;
    }
  }

  void right_rotation(node* x) {
    if (x->left_) {
      node* y = x->left_;
      x->left_ = y->right_;
      if (y->right_ != nullptr) {
        y->right_->parent_ = x;
      }
      y->right_ = x;

      y->parent_ = x->parent_;
      if (x->parent_ == endptr_) {
        headptr_ = y;
        endptr_->left_ = y;
        endptr_->right_ = y;
      } else if (x->parent_->left_ == x) {
        x->parent_->left_ = y;
      } else {
        x->parent_->right_ = y;
      }
      x->parent_ = y;
    }
  }

  // To find the successor of a node x with key x.key, we do the following.
  // 1. If the right subtree of node x is non-empty, then the successor
  //    of x is just the leftmost node in x's right subtree.
  // 2. If the right subtree of node x is empty and x has a successor y,
  //    then y is the lowest ancestor of whose left child is also an ancestor of x.
  static node* node_increment(node* x) {
    // If x is the end_ node, then result will be smallest (leftmost node)
    if (x->right_ != 0) {
      x = x->right_;
      while (x->left_) {
        x = x->left_;
      }
    } else {
      node* y = x->parent_;
      while (x == y->right_) {
        x = y;
        y = y->parent_;
      }
      x = y;
    }
    return x;
  }

  //  см. инкремент
  static node* node_decrement(node* x) {
    // If x is the begin node (leftmost), then result will be end_ node.
    // If x is the end_ node, then result will be maximum (rightmost) node.
    if (x->left != 0) {
      x = x->left;
      while (x->right) {
        x = x->right;
      }
    } else {
      node* y = x->parent_;
      while (x == y->left_) {
        x = y;
        y = y->parent_;
      }
      x = y;
    }
    return x;
  }

  // binary tree insertion that violated red-black tree properties
  // duplicates are not allowed
  bool btree_insert(node* ptr) {
    if (headptr_) {
      node* curr = headptr_;
      node* parent = nullptr;
      while (curr) {
        if (cmp_(ptr->key_, curr->key_)) {
          parent = std::exchange(curr, curr->left_);
        } else if (cmp_(curr->key_, ptr->key_)) {
          parent = std::exchange(curr, curr->right_);
        } else {
          return false;
        }
      }

      // if insert key less parent node
      if (cmp_(ptr->key_, parent->key_)) {
        parent->left_ = ptr;
      } else {
        parent->right_ = ptr;
      }
      ptr->parent_ = parent;
    } else {
      headptr_ = ptr;
      headptr_->parent_ = endptr_;
      endptr_->left_ = headptr_;
      endptr_->right_ = headptr_;
    }
    return true;
  }

  // binary tree insertion that violated red-black tree properties
  // duplicates are allowed
  void btree_multiinsert(node* ptr) {
    if (headptr_) {
      node* curr = headptr_;
      node* parent = nullptr;
      while (curr) {
        // if insert key less current node key
        if (cmp_(ptr->key_, curr->key_)) {
          parent = std::exchange(curr, curr->left_);
        } else {
          parent = std::exchange(curr, curr->right_);
        }
      }

      // if insert key less or equal parent node
      if (cmp_(ptr->key_, parent->key_)) {
        parent->left_ = ptr;
      } else {
        parent->right_ = ptr;
      }
      ptr->parent_ = parent;

    } else {
      headptr_ = ptr;
      headptr_->parent_ = endptr_;
      endptr_->left_ = headptr_;
      endptr_->right_ = headptr_;
    }
  }

  // fix the rb tree modified by the delete operation
  void fixDelete(node* x) {
    // Let S and P are sibling and parent nodes of x.
    node *S, *P;
    bool double_leaf = true;
    if (x == headptr_) {
      delete_node(x);
      delete x;
      headptr_ = nullptr;
      x = nullptr;
    }
    while (x != headptr_ && x->color_ == black) {
      P = x->parent_;
      if (x == P->left_) {
        S = P->right_;
        if (S->color_ == red) {
          // Case 3.1: x's sibling S is red.
          // In this case, we switch the colors of S and x's parent and perform the left rotation
          // on x's parent. This reduces case 3.1 to case 3.2, 3.3, or 3.4.
          S->color_ = black;
          P->color_ = red;
          left_rotation(P);
          S = P->right_;
        }
        // Case 3.2: x's sibling S is black, and both of S's children are black.
        // The color of x's parent can be red or black. We switch the color of S to
        // red. If the color of x's parent is red, we change its color to black, and this
        // becomes the terminal case. Otherwise, we make x's parent a new x and
        // repeat the process from case 3.1.
        if (((S->left_ && S->left_->color_ == black) || S->left_ == nullptr) &&
            ((S->right_ && S->right_->color_ == black) || S->right_ == nullptr)) {
          if(double_leaf){
          delete_node(x);
          delete x;
          double_leaf = false;
          }

          S->color_ = red;
          if (P->color_ == red) {
            P->color_ = black;
            break;
          }
          P->color_ = black;
          x = P;
          continue;
        }
        // Case 3.3: x's sibling is black, S's left child is red, and S's right child is
        // black.
        // We can switch the colors of S and its left child S->left_ and then perform a right
        // rotation on s without violating any of the red-black properties. This transforms
        // the tree into case 3.4.
        else if ((S->left_ && S->left_->color_ == red) &&
                 ((S->right_ && S->right_->color_ == black) || S->right_ == nullptr)) {
          S->left_->color_ = black;
          S->color_ = red;
          right_rotation(S);
          S = P->right_;
        }
        // Case 3.4: x's sibling S is black, and S's right child is red.
        // This is a terminal case. We change the color of S's right child to black,
        // x's parent to black, and perform the left rotation on x's parent node. This
        // way we remove the extra black node on x.
        if ((S->right_ && S->right_->color_ == red) || S->right_ == nullptr) {
          S->color_ = x->parent_->color_;
          x->parent_->color_ = black;
          S->right_->color_ = black;
          left_rotation(x->parent_);

          if(double_leaf){
          delete_node(x);
          delete x;
          double_leaf = false;
          }
          x = headptr_;
        }
      } else {
        S = P->left_;
        if (S->color_ == red) {
          // Mirror case 3.1
          S->color_ = black;
          P->color_ = red;
          right_rotation(P);
          S = P->left_;
        }
        // Mirror case 3.2
        if (((S->right_ && S->right_->color_ == black) || S->right_ == nullptr) &&
            ((S->left_ && S->left_->color_ == black) || S->left_ == nullptr)) {
          if(double_leaf){
          delete_node(x);
          delete x;
          double_leaf = false;
          }

          S->color_ = red;
          if (P->color_ == red) {
            P->color_ = black;
            break;
          }
          P->color_ = black;
          x = P;
          continue;
        }
        // Mirror case 3.3
        else if ((S->right_ && S->right_->color_ == red) &&
                 ((S->left_ && S->left_->color_ == black) || S->left_ == nullptr)) {
          S->right_->color_ = black;
          S->color_ = red;
          left_rotation(S);
          S = P->left_;
        }
        // Mirror case 3.4
        if ((S->left_ && S->left_->color_ == black) || S->left_ == nullptr) {
          S->color_ = x->parent_->color_;
          x->parent_->color_ = black;
          S->left_->color_ = black;
          right_rotation(x->parent_);

          if(double_leaf){
          delete_node(x);
          delete x;
          double_leaf = false;
          }
          x = headptr_;
        }
      }
    }
  }

  // clear pointers of parent to given node
  // do not free nodeptr
  void delete_node(node* nodeptr) {
    if (nodeptr == headptr_) {
      endptr_->left_ = nullptr;
      endptr_->right_ = nullptr;
      headptr_ = nullptr;
    }
    if (nodeptr->parent_->left_ == nodeptr) {
      nodeptr->parent_->left_ = nullptr;
    } else {
      nodeptr->parent_->right_ = nullptr;
    }
  }


};

}  // namespace s21

#endif  // S21_RB_TREE_HPP