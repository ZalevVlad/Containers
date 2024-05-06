#pragma once

#include "s21_rb_tree.hh"

namespace s21 {

template <
    typename Key,
    typename Compare = std::less<Key>>
class multiset {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename rb_tree<Key, Compare>::iterator;
  using size_type = std::size_t;

  using tree_type = rb_tree<Key, Compare>;

 public:
  /*
      Member functions
  */

  // default ctor
  multiset() = default;

  // init-list ctor
  multiset(std::initializer_list<value_type> const &items) {
    for (value_type value : items) {
      tree_.multiinsert(value);
    }
  }

  // copy ctor
  multiset(const multiset &ms) {
    this->merge(ms);
  }

  // move ctor
  multiset(multiset &&ms) : tree_(std::move(ms.tree_)) {}

  // destructor
  ~multiset() = default;

  // copy assigment
  multiset &operator=(const multiset &other) {
    tree_.clear();
    tree_.multimerge(other.tree_);
    return *this;
  }

  // move assigment
  multiset &operator=(multiset &&other) {
    tree_ = std::move(other.tree_);
    return *this;
  }

  /*
      Iterators
  */

  iterator begin() {
    return tree_.begin();
  }

  iterator end() {
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

  void clear() {
    tree_.clear();
  }

  iterator insert(const value_type &value) {
    return tree_.multiinsert(value);
  }

  void erase(iterator it) {
    tree_.erase(it);
  }

  void swap(multiset &other) {
    tree_.swap(other.tree_);
  }

  void merge(const multiset &other) {
    tree_.multimerge(other.tree_);
  }

  /*
      Lookup
  */

  size_type count(const Key &key) {
    return tree_.count(key);
  }

  /*
  @brief Finds an element with key equivalent to key.
  If there are several elements with the requested key
  in the container, any of them may be returned.
  @param key key value of the element to search for
  @return An iterator to the requested element.
  If no such element is found, past-the-end iterator
  is returned.
  */
  iterator find(const Key &key) {
    return tree_.find(key);
  }

  bool contains(const Key &key) {
    return tree_.contains(key);
  }

  // return range of elements matching a specific key
  std::pair<iterator, iterator> equal_range(const Key &key) {
    return tree_.equal_range(key);
  }

  // return an iterator to the first element not less than the given key
  iterator lower_bound(const Key &key) {
    return tree_.lower_bound(key);
  }

  // return an iterator to the first element greater than the given key
  iterator upper_bound(const Key &key) {
    return tree_.upper_bound(key);
  }

  //* Insert many *//
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    return tree_.multiinsert_many(args...);
  }

 private:
  tree_type tree_;
};

}  // namespace s21