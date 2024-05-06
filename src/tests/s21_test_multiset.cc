#include <gtest/gtest.h>

#include <set>
#include <vector>

#include "../s21_containersplus.h"

template <typename T>
void multiset_eq(s21::multiset<T>& a, std::multiset<T>& b) {
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

TEST(Multiset, DefaultConstructor) {
  s21::multiset<char> a;
  std::multiset<char> b;
  EXPECT_EQ(a.empty(), b.empty());
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.max_size(), b.max_size());
  EXPECT_EQ(a.begin(), a.end());
}

TEST(Multiset, InitializerListConstructor) {
  {
    s21::multiset<int> a{};
    std::multiset<int> b{};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1};
    std::multiset<int> b{1};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    std::multiset<int> b{1, 2, 3, 4, 5};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    std::multiset<int> b{5, 4, 3, 2, 1};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    std::multiset<int> b{3, 3, 2, 2, 1, 1};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    std::multiset<int> b{1, 1, 1, 1, 1};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    std::multiset<int> b{1, 1, 1, 2, 2, 2};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{2, 4, 6, 8, 1, 3, 5, 7};
    std::multiset<int> b{2, 4, 6, 8, 1, 3, 5, 7};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 3, 5, 7, 2, 4, 6, 8};
    std::multiset<int> b{1, 3, 5, 7, 2, 4, 6, 8};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    std::multiset<int> b{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    std::multiset<int> b{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1,  2,  3,  4,  5,  6,  7,  8,  9,
                         10, 11, 12, 13, 14, 15, 16, 17, 18};
    std::multiset<int> b{1,  2,  3,  4,  5,  6,  7,  8,  9,
                         10, 11, 12, 13, 14, 15, 16, 17, 18};
    multiset_eq(a, b);
  }
}

TEST(Multiset, CopyConstructor) {
  {
    s21::multiset<int> a{};
    s21::multiset<int> b(a);
    std::multiset<int> c{};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1};
    s21::multiset<int> b(a);
    std::multiset<int> c{1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    s21::multiset<int> b(a);
    std::multiset<int> c{1, 2, 3, 4, 5};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    s21::multiset<int> b(a);
    std::multiset<int> c{5, 4, 3, 2, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    s21::multiset<int> b(a);
    std::multiset<int> c{3, 3, 2, 2, 1, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    s21::multiset<int> b(a);
    std::multiset<int> c{1, 1, 1, 1, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    s21::multiset<int> b(a);
    std::multiset<int> c{1, 1, 1, 2, 2, 2};
    a.clear();
    multiset_eq(b, c);
  }
}

TEST(Multiset, MoveConstructor) {
  {
    s21::multiset<int> a{};
    s21::multiset<int> b(std::move(a));
    std::multiset<int> c{};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1};
    s21::multiset<int> b(std::move(a));
    std::multiset<int> c{1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    s21::multiset<int> b(std::move(a));
    std::multiset<int> c{1, 2, 3, 4, 5};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    s21::multiset<int> b(std::move(a));
    std::multiset<int> c{5, 4, 3, 2, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    s21::multiset<int> b(std::move(a));
    std::multiset<int> c{3, 3, 2, 2, 1, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    s21::multiset<int> b(std::move(a));
    std::multiset<int> c{1, 1, 1, 1, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    s21::multiset<int> b(std::move(a));
    std::multiset<int> c{1, 1, 1, 2, 2, 2};
    a.clear();
    multiset_eq(b, c);
  }
}

TEST(Multiset, CopyAssigment) {
  {
    s21::multiset<int> a{};
    s21::multiset<int> b;
    b = a;
    std::multiset<int> c{};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1};
    s21::multiset<int> b;
    b = a;
    std::multiset<int> c{1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    s21::multiset<int> b;
    b = a;
    std::multiset<int> c{1, 2, 3, 4, 5};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    s21::multiset<int> b;
    b = a;
    std::multiset<int> c{5, 4, 3, 2, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    s21::multiset<int> b;
    b = a;
    std::multiset<int> c{3, 3, 2, 2, 1, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    s21::multiset<int> b;
    b = a;
    std::multiset<int> c{1, 1, 1, 1, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    s21::multiset<int> b;
    b = a;
    std::multiset<int> c{1, 1, 1, 2, 2, 2};
    a.clear();
    multiset_eq(b, c);
  }
}

TEST(Multiset, MoveAssigment) {
  {
    s21::multiset<int> a{};
    s21::multiset<int> b;
    b = std::move(a);
    std::multiset<int> c{};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1};
    s21::multiset<int> b;
    b = std::move(a);
    std::multiset<int> c{1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    s21::multiset<int> b;
    b = std::move(a);
    std::multiset<int> c{1, 2, 3, 4, 5};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    s21::multiset<int> b;
    b = std::move(a);
    std::multiset<int> c{5, 4, 3, 2, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    s21::multiset<int> b;
    b = std::move(a);
    std::multiset<int> c{3, 3, 2, 2, 1, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    s21::multiset<int> b;
    b = std::move(a);
    std::multiset<int> c{1, 1, 1, 1, 1};
    a.clear();
    multiset_eq(b, c);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    s21::multiset<int> b;
    b = std::move(a);
    std::multiset<int> c{1, 1, 1, 2, 2, 2};
    a.clear();
    multiset_eq(b, c);
  }
}

TEST(Multiset, Iterators) {
  {
    s21::multiset<int> a{};
    std::multiset<int> b{};
  }
  { s21::multiset<int> a{1}; }
  { s21::multiset<int> a{1, 2, 3, 4, 5}; }
  { s21::multiset<int> a{5, 4, 3, 2, 1}; }
  { s21::multiset<int> a{3, 3, 2, 2, 1, 1}; }
  { s21::multiset<int> a{1, 1, 1, 1, 1}; }
  { s21::multiset<int> a{1, 1, 1, 2, 2, 2}; }
}

TEST(Multiset, Clear) {
  {
    s21::multiset<int> a{1};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
}

TEST(Multiset, Insert) {
  {
    s21::multiset<int> a{};
    std::multiset<int> b{1};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{1, 2, 3, 4, 5};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{5, 4, 3, 2, 1};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{3, 3, 2, 2, 1, 1};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{1, 1, 1, 1, 1};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{1, 1, 1, 2, 2, 2};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{2, 4, 6, 8, 1, 3, 5, 7};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{1, 3, 5, 7, 2, 4, 6, 8};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{};
    std::multiset<int> b{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    std::multiset<int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(*apair, *cpair);
    }
    multiset_eq(a, b);
  }
}

TEST(Multiset, Erase) {
  {
    s21::multiset<int> a{1};
    std::multiset<int> b{1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    std::multiset<int> b{1, 2, 3, 4, 5};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    std::multiset<int> b{5, 4, 3, 2, 1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    std::multiset<int> b{3, 3, 2, 2, 1, 1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    std::multiset<int> b{1, 1, 1, 1, 1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    std::multiset<int> b{1, 1, 1, 2, 2, 2};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{2, 4, 6, 8, 1, 3, 5, 7};
    std::multiset<int> b{2, 4, 6, 8, 1, 3, 5, 7};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{1, 3, 5, 7, 2, 4, 6, 8};
    std::multiset<int> b{1, 3, 5, 7, 2, 4, 6, 8};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    std::multiset<int> b{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    std::multiset<int> b{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
  {
    s21::multiset<int> a{18, 17, 16, 15, 14, 13, 12, 11, 10,
                         9,  8,  7,  6,  5,  4,  3,  2,  1};
    std::multiset<int> b{18, 17, 16, 15, 14, 13, 12, 11, 10,
                         9,  8,  7,  6,  5,  4,  3,  2,  1};
    int size = a.size();
    for (int i = 0; i < size; i++) {
      a.erase(a.begin());
      b.erase(b.begin());
      multiset_eq(a, b);
    }
  }
}

TEST(Multiset, Swap) {
  {
    s21::multiset<int> a{};
    s21::multiset<int> b{};
    std::multiset<int> c{};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{1};
    s21::multiset<int> b{};
    std::multiset<int> c{1};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    s21::multiset<int> b{};
    std::multiset<int> c{1, 2, 3, 4, 5};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    s21::multiset<int> b{};
    std::multiset<int> c{5, 4, 3, 2, 1};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    s21::multiset<int> b{};
    std::multiset<int> c{3, 3, 2, 2, 1, 1};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    s21::multiset<int> b{};
    std::multiset<int> c{1, 1, 1, 1, 1};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    s21::multiset<int> b{};
    std::multiset<int> c{1, 1, 1, 2, 2, 2};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{2, 4, 6, 8, 1, 3, 5, 7};
    s21::multiset<int> b{};
    std::multiset<int> c{2, 4, 6, 8, 1, 3, 5, 7};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{1, 3, 5, 7, 2, 4, 6, 8};
    s21::multiset<int> b{};
    std::multiset<int> c{1, 3, 5, 7, 2, 4, 6, 8};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    s21::multiset<int> b{};
    std::multiset<int> c{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 9, 8, 7, 6};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
  {
    s21::multiset<int> a{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    s21::multiset<int> b{};
    std::multiset<int> c{6, 7, 8, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    std::multiset<int> d{};
    a.swap(b);
    multiset_eq(b, c);
    multiset_eq(a, d);
  }
}

TEST(Multiset, Merge) {
  {
    s21::multiset<int> a{};
    s21::multiset<int> b{};
    std::multiset<int> c{};
    a.merge(b);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1};
    s21::multiset<int> b{};
    std::multiset<int> c{1};
    a.merge(b);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1};
    s21::multiset<int> b{1};
    std::multiset<int> c{1, 1};
    a.merge(b);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1, 1};
    s21::multiset<int> b{1, 1};
    std::multiset<int> c{1, 1, 1, 1};
    a.merge(b);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1, 2};
    s21::multiset<int> b{2, 3};
    std::multiset<int> c{1, 2, 2, 3};
    a.merge(b);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    s21::multiset<int> b{6, 7, 8, 9, 10};
    std::multiset<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.merge(b);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{6, 7, 8, 9, 10};
    s21::multiset<int> b{5, 4, 3, 2, 1};
    std::multiset<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.merge(b);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1};
    s21::multiset<int> b{2, 2, 2};
    std::multiset<int> c{1, 2, 2, 2};
    a.merge(b);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{2, 4, 6, 8};
    s21::multiset<int> b{1, 3, 5, 7, 9};
    std::multiset<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9};
    a.merge(b);
    multiset_eq(a, c);
  }
}

TEST(Multiset, Count) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  {
    s21::multiset<int> a{};
    std::multiset<int> b{};
    for (auto val : vec) {
      EXPECT_EQ(a.count(val), b.count(val));
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 2, 3};
    std::multiset<int> b{1, 2, 3};
    for (auto val : vec) {
      EXPECT_EQ(a.count(val), b.count(val));
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 1, 1};
    std::multiset<int> b{1, 1, 1};
    for (auto val : vec) {
      EXPECT_EQ(a.count(val), b.count(val));
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2};
    std::multiset<int> b{1, 1, 1, 2, 2};
    for (auto val : vec) {
      EXPECT_EQ(a.count(val), b.count(val));
    }
    multiset_eq(a, b);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    std::multiset<int> b{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                         1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    for (auto val : vec) {
      EXPECT_EQ(a.count(val), b.count(val));
    }
    multiset_eq(a, b);
  }
}

TEST(Multiset, Find) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  {
    s21::multiset<int> a{};
    std::multiset<int> b{};
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
    s21::multiset<int> a{1};
    std::multiset<int> b{1};
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
    s21::multiset<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::multiset<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
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
    s21::multiset<int> a{11, 12, 13, 14, 15};
    std::multiset<int> b{11, 12, 13, 14, 15};
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

TEST(Multiset, Contains) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  {
    s21::multiset<int> a{};
    std::multiset<int> b{};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val), b.count(val) == 1);
    }
  }
  {
    s21::multiset<int> a{1};
    std::multiset<int> b{1};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val), b.count(val) == 1);
    }
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::multiset<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val), b.count(val) == 1);
    }
  }
  {
    s21::multiset<int> a{11, 12, 13, 14, 15};
    std::multiset<int> b{11, 12, 13, 14, 15};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val), b.count(val) == 1);
    }
  }
}

TEST(Multiset, EqualRange) {
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::multiset<int> a{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5,
                       6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};
  std::multiset<int> b{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5,
                       6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};

  for (auto val : vec) {
    s21::multiset<int> a{};
    std::multiset<int> b{};
    auto [ait, afinish] = a.equal_range(val);
    auto [bit, bfinish] = b.equal_range(val);
    for (; bit != bfinish; bit++, ait++) {
      EXPECT_EQ(*ait, *bit);
    }
  }
}

TEST(Multiset, LowerBound) {
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::multiset<int> a{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5,
                       6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};
  std::multiset<int> b{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5,
                       6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};

  for (auto val : vec) {
    auto ares = a.lower_bound(val);
    auto bres = b.lower_bound(val);
    for (; bres != b.end(); bres++, ares++) {
      EXPECT_EQ(*ares, *bres);
    }
    if (bres == b.end()) {
      EXPECT_EQ(ares, a.end());
    } else {
      EXPECT_EQ(*ares, *bres);
    }
  }
}

TEST(Multiset, UpperBound) {
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::multiset<int> a{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5,
                       6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};
  std::multiset<int> b{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5,
                       6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};

  for (auto val : vec) {
    auto ait = a.begin();
    auto ares = a.upper_bound(val);
    auto bit = b.begin();
    auto bres = b.upper_bound(val);
    for (; bit != bres; bit++, ait++) {
      EXPECT_EQ(*ait, *bit);
    }
    if (bres == b.end()) {
      EXPECT_EQ(ares, a.end());
    } else {
      EXPECT_EQ(*ares, *bres);
    }
  }
}

TEST(Multiset, InsertMany) {
  {
    s21::multiset<int> a{};
    std::multiset<int> c{};
    a.insert_many();
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1};
    std::multiset<int> c{1};
    a.insert_many();
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1};
    std::multiset<int> c{1, 1};
    a.insert_many(1);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1, 1};
    std::multiset<int> c{1, 1, 1, 1};
    a.insert_many(1, 1);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1, 2};
    std::multiset<int> c{1, 2, 2, 3};
    a.insert_many(2, 3);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    std::multiset<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.insert_many(6, 7, 8, 9, 10);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{6, 7, 8, 9, 10};
    std::multiset<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a.insert_many(5, 4, 3, 2, 1);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{1};
    std::multiset<int> c{1, 2, 2, 2};
    a.insert_many(2, 2, 2);
    multiset_eq(a, c);
  }
  {
    s21::multiset<int> a{2, 4, 6, 8};
    std::multiset<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9};
    a.insert_many(1, 3, 5, 7, 9);
    multiset_eq(a, c);
  }
}