#include <gtest/gtest.h>

#include <set>
#include <vector>

#include "../model/s21_set.hh"

template <typename T>
void set_eq(s21::set<T>& a, std::set<T>& b) {
  EXPECT_EQ(a.empty(), b.empty());
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.max_size(), b.max_size());
  auto ait = a.begin();
  auto bit = b.begin();
  while (bit != b.end()) {
    EXPECT_EQ(*ait, *bit);
    ait++;
    bit++;
  }
}

TEST(Set, DefaultConstructor) {
  s21::set<char> a;
  std::set<char> b;
  EXPECT_EQ(a.empty(), b.empty());
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.max_size(), b.max_size());
  EXPECT_EQ(a.begin(), a.end());
}

TEST(Set, InitializerListConstructor) {
  {
    s21::set<int> a{};
    std::set<int> b{};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1};
    std::set<int> b{1};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    std::set<int> b{1, 2, 3, 4, 5};
    set_eq(a, b);
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    std::set<int> b{5, 4, 3, 2, 1};
    set_eq(a, b);
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    std::set<int> b{3, 3, 2, 2, 1, 1};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    std::set<int> b{1, 1, 1, 1, 1};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    std::set<int> b{1, 1, 1, 2, 2, 2};
    set_eq(a, b);
  }
  {
    s21::set<int> a{2, 4, 6, 8, 1, 3, 5, 7};
    std::set<int> b{2, 4, 6, 8, 1, 3, 5, 7};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1, 3, 5, 7, 2, 4, 6, 8};
    std::set<int> b{1, 3, 5, 7, 2, 4, 6, 8};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    std::set<int> b{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    set_eq(a, b);
  }
  {
    s21::set<int> a{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    std::set<int> b{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1,  2,  3,  4,  5,  6,  7,  8,  9,
                    10, 11, 12, 13, 14, 15, 16, 17, 18};
    std::set<int> b{1,  2,  3,  4,  5,  6,  7,  8,  9,
                    10, 11, 12, 13, 14, 15, 16, 17, 18};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1,  100, 2,  99, 3,  98, 4,  97, 5,  96, 6,
                    95, 7,   94, 8,  93, 9,  92, 10, 91, 11, 90};
    std::set<int> b{1,  100, 2,  99, 3,  98, 4,  97, 5,  96, 6,
                    95, 7,   94, 8,  93, 9,  92, 10, 91, 11, 90};
    set_eq(a, b);
  }
  {
    s21::set<int> a{19, 20, 18, 21, 17, 22, 16, 23, 15, 24, 14, 23};
    std::set<int> b{19, 20, 18, 21, 17, 22, 16, 23, 15, 24, 14, 23};
    set_eq(a, b);
  }
}

TEST(Set, CopyConstructor) {
  {
    s21::set<int> a{};
    s21::set<int> b(a);
    std::set<int> c{};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1};
    s21::set<int> b(a);
    std::set<int> c{1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    s21::set<int> b(a);
    std::set<int> c{1, 2, 3, 4, 5};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    s21::set<int> b(a);
    std::set<int> c{5, 4, 3, 2, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    s21::set<int> b(a);
    std::set<int> c{3, 3, 2, 2, 1, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    s21::set<int> b(a);
    std::set<int> c{1, 1, 1, 1, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    s21::set<int> b(a);
    std::set<int> c{1, 1, 1, 2, 2, 2};
    a.clear();
    set_eq(b, c);
  }
}

TEST(Set, MoveConstructor) {
  {
    s21::set<int> a{};
    s21::set<int> b(std::move(a));
    std::set<int> c{};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1};
    s21::set<int> b(std::move(a));
    std::set<int> c{1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    s21::set<int> b(std::move(a));
    std::set<int> c{1, 2, 3, 4, 5};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    s21::set<int> b(std::move(a));
    std::set<int> c{5, 4, 3, 2, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    s21::set<int> b(std::move(a));
    std::set<int> c{3, 3, 2, 2, 1, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    s21::set<int> b(std::move(a));
    std::set<int> c{1, 1, 1, 1, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    s21::set<int> b(std::move(a));
    std::set<int> c{1, 1, 1, 2, 2, 2};
    a.clear();
    set_eq(b, c);
  }
}

TEST(Set, CopyAssigment) {
  {
    s21::set<int> a{};
    s21::set<int> b;
    b = a;
    std::set<int> c{};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1};
    s21::set<int> b;
    b = a;
    std::set<int> c{1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    s21::set<int> b;
    b = a;
    std::set<int> c{1, 2, 3, 4, 5};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    s21::set<int> b;
    b = a;
    std::set<int> c{5, 4, 3, 2, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    s21::set<int> b;
    b = a;
    std::set<int> c{3, 3, 2, 2, 1, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    s21::set<int> b;
    b = a;
    std::set<int> c{1, 1, 1, 1, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    s21::set<int> b;
    b = a;
    std::set<int> c{1, 1, 1, 2, 2, 2};
    a.clear();
    set_eq(b, c);
  }
}

TEST(Set, MoveAssigment) {
  {
    s21::set<int> a{};
    s21::set<int> b;
    b = std::move(a);
    std::set<int> c{};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1};
    s21::set<int> b;
    b = std::move(a);
    std::set<int> c{1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    s21::set<int> b;
    b = std::move(a);
    std::set<int> c{1, 2, 3, 4, 5};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    s21::set<int> b;
    b = std::move(a);
    std::set<int> c{5, 4, 3, 2, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    s21::set<int> b;
    b = std::move(a);
    std::set<int> c{3, 3, 2, 2, 1, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    s21::set<int> b;
    b = std::move(a);
    std::set<int> c{1, 1, 1, 1, 1};
    a.clear();
    set_eq(b, c);
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    s21::set<int> b;
    b = std::move(a);
    std::set<int> c{1, 1, 1, 2, 2, 2};
    a.clear();
    set_eq(b, c);
  }
}

TEST(Set, Iterators) {
  {
    s21::set<int> a{};
    std::set<int> b{};
  }
  { s21::set<int> a{1}; }
  { s21::set<int> a{1, 2, 3, 4, 5}; }
  { s21::set<int> a{5, 4, 3, 2, 1}; }
  { s21::set<int> a{3, 3, 2, 2, 1, 1}; }
  { s21::set<int> a{1, 1, 1, 1, 1}; }
  { s21::set<int> a{1, 1, 1, 2, 2, 2}; }
}

TEST(Set, Clear) {
  {
    s21::set<int> a{1};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
}

TEST(Set, Insert) {
  {
    s21::set<int> a{};
    std::set<int> b{1};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{1, 2, 3, 4, 5};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{5, 4, 3, 2, 1};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{3, 3, 2, 2, 1, 1};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{1, 1, 1, 1, 1};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{1, 1, 1, 2, 2, 2};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{2, 4, 6, 8, 1, 3, 5, 7};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{1, 3, 5, 7, 2, 4, 6, 8};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
  {
    s21::set<int> a{};
    std::set<int> b{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    std::set<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    set_eq(a, b);
  }
}

TEST(Set, Erase) {
  {
    s21::set<int> a{1};
    std::set<int> b{1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    std::set<int> b{1, 2, 3, 4, 5};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    std::set<int> b{5, 4, 3, 2, 1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    std::set<int> b{3, 3, 2, 2, 1, 1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    std::set<int> b{1, 1, 1, 1, 1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    std::set<int> b{1, 1, 1, 2, 2, 2};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{2, 4, 6, 8, 1, 3, 5, 7};
    std::set<int> b{2, 4, 6, 8, 1, 3, 5, 7};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{1, 3, 5, 7, 2, 4, 6, 8};
    std::set<int> b{1, 3, 5, 7, 2, 4, 6, 8};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    std::set<int> b{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    std::set<int> b{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
  {
    s21::set<int> a{18, 17, 16, 15, 14, 13, 12, 11, 10,
                    9,  8,  7,  6,  5,  4,  3,  2,  1};
    std::set<int> b{18, 17, 16, 15, 14, 13, 12, 11, 10,
                    9,  8,  7,  6,  5,  4,  3,  2,  1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      set_eq(a, b);
    }
  }
}

TEST(Set, Swap) {
  {
    s21::set<int> a{};
    s21::set<int> b{};
    std::set<int> c{};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{1};
    s21::set<int> b{};
    std::set<int> c{1};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    s21::set<int> b{};
    std::set<int> c{1, 2, 3, 4, 5};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    s21::set<int> b{};
    std::set<int> c{5, 4, 3, 2, 1};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    s21::set<int> b{};
    std::set<int> c{3, 3, 2, 2, 1, 1};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    s21::set<int> b{};
    std::set<int> c{1, 1, 1, 1, 1};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    s21::set<int> b{};
    std::set<int> c{1, 1, 1, 2, 2, 2};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{2, 4, 6, 8, 1, 3, 5, 7};
    s21::set<int> b{};
    std::set<int> c{2, 4, 6, 8, 1, 3, 5, 7};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{1, 3, 5, 7, 2, 4, 6, 8};
    s21::set<int> b{};
    std::set<int> c{1, 3, 5, 7, 2, 4, 6, 8};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    s21::set<int> b{};
    std::set<int> c{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
  {
    s21::set<int> a{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    s21::set<int> b{};
    std::set<int> c{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    std::set<int> d{};
    a.swap(b);
    set_eq(b, c);
    set_eq(a, d);
  }
}

TEST(Set, Merge) {
  {
    s21::set<int> a{};
    s21::set<int> b{};
    std::set<int> c{};
    a.merge(b);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1};
    s21::set<int> b{};
    std::set<int> c{1};
    a.merge(b);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1};
    s21::set<int> b{1};
    std::set<int> c{1};
    a.merge(b);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1, 1};
    s21::set<int> b{1, 1};
    std::set<int> c{1};
    a.merge(b);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1, 2};
    s21::set<int> b{2, 3};
    std::set<int> c{1, 2, 3};
    a.merge(b);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    s21::set<int> b{6, 7, 8, 9, 10};
    std::set<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.merge(b);
    set_eq(a, c);
  }
  {
    s21::set<int> a{6, 7, 8, 9, 10};
    s21::set<int> b{5, 4, 3, 2, 1};
    std::set<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.merge(b);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1};
    s21::set<int> b{2, 2, 2};
    std::set<int> c{1, 2};
    a.merge(b);
    set_eq(a, c);
  }
  {
    s21::set<int> a{2, 4, 6, 8};
    s21::set<int> b{1, 3, 5, 7, 9};
    std::set<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9};
    a.merge(b);
    set_eq(a, c);
  }
}

TEST(Set, Contains) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  {
    s21::set<int> a{};
    std::set<int> b{};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val), b.count(val) == 1);
    }
  }
  {
    s21::set<int> a{1};
    std::set<int> b{1};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val), b.count(val) == 1);
    }
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::set<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val), b.count(val) == 1);
    }
  }
  {
    s21::set<int> a{11, 12, 13, 14, 15};
    std::set<int> b{11, 12, 13, 14, 15};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val), b.count(val) == 1);
    }
  }
}

TEST(Set, Find) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  {
    s21::set<int> a{};
    std::set<int> b{};
    for (auto val : vec) {
      auto res = b.find(val);
      if (res == b.end()) {
        EXPECT_EQ(a.find(val), a.end());
      } else {
        EXPECT_NE(a.find(val), a.end());
        EXPECT_EQ(*a.find(val), *res);
      }
    }
  }
  {
    s21::set<int> a{1};
    std::set<int> b{1};
    for (auto val : vec) {
      auto res = b.find(val);
      if (res == b.end()) {
        EXPECT_EQ(a.find(val), a.end());
      } else {
        EXPECT_NE(a.find(val), a.end());
        EXPECT_EQ(*a.find(val), *res);
      }
    }
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::set<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto val : vec) {
      auto res = b.find(val);
      if (res == b.end()) {
        EXPECT_EQ(a.find(val), a.end());
      } else {
        EXPECT_NE(a.find(val), a.end());
        EXPECT_EQ(*a.find(val), *res);
      }
    }
  }
  {
    s21::set<int> a{11, 12, 13, 14, 15};
    std::set<int> b{11, 12, 13, 14, 15};
    for (auto val : vec) {
      auto res = b.find(val);
      if (res == b.end()) {
        EXPECT_EQ(a.find(val), a.end());
      } else {
        EXPECT_NE(a.find(val), a.end());
        EXPECT_EQ(*a.find(val), *res);
      }
    }
  }
}

TEST(Set, InsertMany) {
  {
    s21::set<int> a{};
    std::set<int> c{};
    a.insert_many();
    set_eq(a, c);
  }
  {
    s21::set<int> a{1};
    std::set<int> c{1};
    a.insert_many();
    set_eq(a, c);
  }
  {
    s21::set<int> a{1};
    std::set<int> c{1};
    a.insert_many(1);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1, 1};
    std::set<int> c{1};
    a.insert_many(1, 1);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1, 2};
    std::set<int> c{1, 2, 3};
    a.insert_many(2, 3);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    std::set<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.insert_many(6, 7, 8, 9, 10);
    set_eq(a, c);
  }
  {
    s21::set<int> a{6, 7, 8, 9, 10};
    std::set<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.insert_many(5, 4, 3, 2, 1);
    set_eq(a, c);
  }
  {
    s21::set<int> a{1};
    std::set<int> c{1, 2};
    a.insert_many(2, 2, 2);
    set_eq(a, c);
  }
  {
    s21::set<int> a{2, 4, 6, 8};
    std::set<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9};
    a.insert_many(1, 3, 5, 7, 9);
    set_eq(a, c);
  }
}

TEST(Set, Functional) {
  {
    s21::set<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::set<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    a.erase(a.find(8));
    c.erase(c.find(8));
    a.erase(a.find(7));
    c.erase(c.find(7));
    a.erase(a.find(6));
    c.erase(c.find(6));
    a.erase(a.find(10));
    c.erase(c.find(10));
    a.erase(a.find(9));
    c.erase(c.find(9));
    set_eq(a, c);
  }
}