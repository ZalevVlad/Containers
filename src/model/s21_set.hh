#pragma once

#include "s21_rb_tree.hh"

namespace s21 {

template <
    typename Key,
    typename Compare = std::less<Key>>
class set {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reverence = const value_type&;
  using iterator = typename rb_tree<Key, Compare>::iterator;
  using size_type = std::size_t;

  using tree_type = rb_tree<Key, Compare>;

 public:
  /*
      Member functions
  */

  // default ctor
  set() = default;

  // init-list ctor
  set(std::initializer_list<value_type> const& items) {
    for (value_type value : items) {
      tree_.insert(value);
    }
  }

  // copy ctor
  set(const set& s) : tree_(s.tree_) {}

  // move ctor
  set(set&& s) : tree_(std::move(s.tree_)) {}

  // destructor
  ~set() = default;

  // copy assigment
  set& operator=(const set& other) {
    tree_ = other.tree_;
    return *this;
  }

  // move assigment
  set& operator=(set&& other) {
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

  std::pair<iterator, bool> insert(const value_type& value) {
    return tree_.insert(value);
  }

  // erases element at iterator
  void erase(const iterator it) {
    tree_.erase(it);
  }

  // swaps the contents
  void swap(set& other) {
    tree_.swap(other.tree_);
  }

  // splices nodes from another container
  void merge(set& other) {
    tree_.merge(other.tree_);
  }

  /*
      Lookup
  */

  bool contains(const key_type& key) {
    return tree_.contains(key);
  }

  iterator find(const key_type& key) {
    return tree_.find(key);
  }

  /*
      Insert many
  */

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    return tree_.insert_many(args...);
  }

 private:
  tree_type tree_;
};
}  // namespace s21