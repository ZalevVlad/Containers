#pragma once

#include <memory>  // std::allocator

#include "s21_rb_tree.hh"
namespace s21 {

template <
    typename Key,
    typename T,
    typename Compare = std::less<Key>>
class map {
  // member types
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;

  // map elements are compared by key value
  struct value_compare {
    constexpr bool operator()(const_reference &lhs, const_reference &rhs) const {
      return lhs.first < rhs.first;
    }
  };
  using tree_type = rb_tree<value_type, value_compare>;

  using iterator = typename rb_tree<value_type, value_compare>::iterator;
  using size_type = std::size_t;

 public:
  /*
      Member functions
  */

  // default ctor
  map() = default;

  // init-list ctor
  map(const std::initializer_list<value_type> &items) {
    for (value_type value : items) {
      tree_.insert(value);
    }
  }

  // copy ctor
  map(const map &m) : tree_(m.tree_) {
  }

  // move ctor
  map(map &&m) : tree_(std::move(m.tree_)) {}

  // destructor
  ~map() = default;

  // copy assgiment
  map &operator=(const map &other) {
    tree_ = other.tree_;
    return *this;
  }

  // move assigment
  map &operator=(map &&other) {
    tree_ = std::move(other.tree_);
    return *this;
  }

  /*
      Element access
  */

  /*
  @brief Returns a reference to the mapped value of the element
  with specified key. If no such element exists, an exception
  of type std::out_of_range is thrown.
  @param key the key of the element to find.
  @return A reference to the mapped value of the requested element.
  */
  mapped_type &at(const key_type &key) {
    iterator it = tree_.find(value_type{key, mapped_type{}});
    if (it == tree_.end()) {
      throw std::out_of_range("No such element exists");
    }
    return (*it).second;
  }

  /*
  @brief Returns a reference to the value that is mapped to a key
  equivalent to key or x respectively, performing an insertion if
  such key does not already exist.
  @param key the key of the element to find
  @return A reference to the mapped value of the new element if
  no element with key key existed. Otherwise, a reference to
  the mapped value of the existing element whose key is equivalent
  to key.
  */
  mapped_type &operator[](const key_type &key) {
    iterator it = tree_.find(value_type{key, mapped_type{}});
    if (it == tree_.end()) {
      auto res = tree_.insert(value_type{key, mapped_type{}});
      it = res.first;
    }
    return (*it).second;
  }

  /*
      Iterators
  */

  iterator begin() const {
    return tree_.begin();
  }

  iterator end() const {
    return tree_.end();
  }

  /*
      Capacity
  */

  bool empty() const {
    return tree_.empty();
  };

  size_type size() const {
    return tree_.size();
  };

  size_type max_size() const {
    return tree_.max_size();
  };

  /*
      Modifiers
  */

  // clears the content
  void clear() {
    tree_.clear();
  }

  // inserts node and returns iterator to where
  // the element is in the container and bool
  // denoting whether the insertion took place
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree_.insert(value);
  }

  // inserts value by key and returns iterator to where
  // the element is in the container and bool
  // denoting whether the insertion took place
  std::pair<iterator, bool> insert(const Key &key, const mapped_type &obj) {
    return tree_.insert(value_type{key, obj});
  }

  // inserts an element or assigns to the current element if the key already exists
  // @return The bool component is true if the insertion took place and false if the
  // assignment took place. The iterator component is pointing at the element that
  // was inserted or updated.
  std::pair<iterator, bool> insert_or_assign(const Key &key, const mapped_type &obj) {
    iterator it = tree_.find(value_type{key, obj});
    bool insert = true;
    // если it!=end значит изменяем значение по итератору
    // иначе вставляем элемент (дважды поиск, а че поделать)
    if (it != tree_.end()) {
      (*it).second = obj;
      insert = false;
    }
    else{
      it = tree_.insert(value_type{key, obj}).first;
    }
    return std::pair<iterator, bool>(it, insert);
  }

  // erases element at iterator
  void erase(iterator it) {
    tree_.erase(it);
  }

  //	swaps the contents
  void swap(map &other) {
    tree_.swap(other.tree_);
  }

  // splices nodes from another container
  void merge(map &other) {
    tree_.merge(other.tree_);
  }

  /*
      Lookup
  */

  // @brief Checks if there is an element with key equivalent to key
  // in the container.
  // @param key key value of the element to search for.
  // @return true if there is such an element, otherwise false.
  bool contains(const key_type &key) {
    return tree_.contains(value_type{key, mapped_type{}});
  }

  /*
      Insert many
  */

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    return tree_.insert_many(args...);
  }

 private:
  tree_type tree_;
};

}  // namespace s21