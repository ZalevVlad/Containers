#include <gtest/gtest.h>

#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

#include "s21_containers.h"
#include "s21_containersplus.h"

using namespace s21;

template <typename T>
void map_eq(s21::map<T, T>& a, std::map<T, T>& b) {
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

TEST(Map, DefaultConstructor) {
  s21::map<char, char> a;
  std::map<char, char> b;
  EXPECT_EQ(a.empty(), b.empty());
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.max_size(), b.max_size());
  EXPECT_EQ(a.begin(), a.end());
}

TEST(Map, InitializerListConstructor) {
  {
    s21::map<int, int> a{};
    std::map<int, int> b{};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}};
    std::map<int, int> b{{1, 1}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    std::map<int, int> b{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    std::map<int, int> b{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    std::map<int, int> b{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    std::map<int, int> b{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{2, 2}, {4, 4}, {6, 6}, {8, 8}, {1, 1}, {3, 3}, {5, 5}, {7, 7}};
    std::map<int, int> b{{2, 2}, {4, 4}, {6, 6}, {8, 8}, {1, 1}, {3, 3}, {5, 5}, {7, 7}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {3, 3}, {5, 5}, {7, 7}, {2, 2}, {4, 4}, {6, 6}, {8, 8}};
    std::map<int, int> b{{1, 1}, {3, 3}, {5, 5}, {7, 7}, {2, 2}, {4, 4}, {6, 6}, {8, 8}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {9, 9}, {8, 8}, {7, 7}, {6, 6}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {9, 9}, {8, 8}, {7, 7}, {6, 6}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    std::map<int, int> b{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    map_eq(a, b);
  }
}

TEST(Map, CopyConstructor) {
  {
    s21::map<int, int> a{};
    s21::map<int, int> b(a);
    std::map<int, int> c{};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}};
    s21::map<int, int> b(a);
    std::map<int, int> c{{1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    s21::map<int, int> b(a);
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    s21::map<int, int> b(a);
    std::map<int, int> c{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    s21::map<int, int> b(a);
    std::map<int, int> c{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    s21::map<int, int> b(a);
    std::map<int, int> c{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    s21::map<int, int> b(a);
    std::map<int, int> c{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    a.clear();
    map_eq(b, c);
  }
}

TEST(Map, MoveConstructor) {
  {
    s21::map<int, int> a{};
    s21::map<int, int> b(std::move(a));
    std::map<int, int> c{};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}};
    s21::map<int, int> b(std::move(a));
    std::map<int, int> c{{1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    s21::map<int, int> b(std::move(a));
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    s21::map<int, int> b(std::move(a));
    std::map<int, int> c{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    s21::map<int, int> b(std::move(a));
    std::map<int, int> c{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    s21::map<int, int> b(std::move(a));
    std::map<int, int> c{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    s21::map<int, int> b(std::move(a));
    std::map<int, int> c{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    a.clear();
    map_eq(b, c);
  }
}

TEST(Map, CopyAssigment) {
  {
    s21::map<int, int> a{};
    s21::map<int, int> b;
    b = a;
    std::map<int, int> c{};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}};
    s21::map<int, int> b;
    b = a;
    std::map<int, int> c{{1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    s21::map<int, int> b;
    b = a;
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    s21::map<int, int> b;
    b = a;
    std::map<int, int> c{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    s21::map<int, int> b;
    b = a;
    std::map<int, int> c{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    s21::map<int, int> b;
    b = a;
    std::map<int, int> c{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    s21::map<int, int> b;
    b = a;
    std::map<int, int> c{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    a.clear();
    map_eq(b, c);
  }
}

TEST(Map, MoveAssigment) {
  {
    s21::map<int, int> a{};
    s21::map<int, int> b;
    b = std::move(a);
    std::map<int, int> c{};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}};
    s21::map<int, int> b;
    b = std::move(a);
    std::map<int, int> c{{1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    s21::map<int, int> b;
    b = std::move(a);
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    s21::map<int, int> b;
    b = std::move(a);
    std::map<int, int> c{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    s21::map<int, int> b;
    b = std::move(a);
    std::map<int, int> c{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    s21::map<int, int> b;
    b = std::move(a);
    std::map<int, int> c{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    a.clear();
    map_eq(b, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    s21::map<int, int> b;
    b = std::move(a);
    std::map<int, int> c{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    a.clear();
    map_eq(b, c);
  }
}

TEST(Multiset, At) {
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    for (auto val : b) {
      a.at(val.first) = val.second + 1;
      b.at(val.first) = val.second + 1;
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}};
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};
    for (auto val : c) {
      try {
        auto res = b.at(val.first);
        EXPECT_EQ(a.at(val.first), res);
      } catch (const std::out_of_range& e) {
        EXPECT_THROW(a.at(val.first), std::out_of_range);
      }
    }
  }
}

TEST(Map, OpeartorSqaredBrackets) {
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    for (auto val : b) {
      a[val.first] = val.second + 1;
      b[val.first] = val.second + 1;
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{};
    std::vector<std::pair<int, int>> vec{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    for (auto val : vec) {
      a[val.first] = val.first;
      b[val.first] = val.first;
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}};
    std::vector<std::pair<int, int>> vec{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    for (auto val : vec) {
      EXPECT_EQ(a[val.first], b[val.first]);
    }
  }
}

TEST(Map, Iterators) {
  {
    s21::map<int, int> a{};
    std::map<int, int> b{};
  }
  {
    s21::map<int, int> a{{1, 1}};
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  }
  {
    s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
  }
  {
    s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
  }
}

TEST(Map, Clear) {
  {
    s21::map<int, int> a{{1, 1}};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
}

TEST(Map, InsertValue) {
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{2, 2}, {4, 4}, {6, 6}, {8, 8}, {1, 1}, {3, 3}, {5, 5}, {7, 7}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {3, 3}, {5, 5}, {7, 7}, {2, 2}, {4, 4}, {6, 6}, {8, 8}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {9, 9}, {8, 8}, {7, 7}, {6, 6}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
}

TEST(Map, InsertKeyObj) {
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{2, 2}, {4, 4}, {6, 6}, {8, 8}, {1, 1}, {3, 3}, {5, 5}, {7, 7}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {3, 3}, {5, 5}, {7, 7}, {2, 2}, {4, 4}, {6, 6}, {8, 8}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {9, 9}, {8, 8}, {7, 7}, {6, 6}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{};
    std::map<int, int> b{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    std::map<int, int> c{};
    for (auto value : b) {
      auto apair = a.insert(value.first, value.second);
      auto cpair = c.insert(value);
      EXPECT_EQ(apair.first == a.end(), cpair.first == c.end());
      EXPECT_EQ(apair.second, cpair.second);
    }
    map_eq(a, b);
  }
}

TEST(Map, Contains) {
  std::vector<std::pair<int, int>> vec{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
  {
    s21::map<int, int> a{};
    std::map<int, int> b{};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val.first), b.count(val.first) > 0);
    }
  }
  {
    s21::map<int, int> a{{1, 1}};
    std::map<int, int> b{{1, 1}};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val.first), b.count(val.first) > 0);
    }
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    for (auto val : vec) {
      EXPECT_EQ(a.contains(val.first), b.count(val.first) > 0);
    }
  }
}

TEST(Map, InsertMany) {
  {
    s21::map<int, int> a{};
    std::map<int, int> c{};
    a.insert_many();
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{1, 1}};
    std::map<int, int> c{{1, 1}};
    a.insert_many();
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{1, 1}};
    std::map<int, int> c{{1, 1}};
    a.insert_many(std::pair<int, int>{1, 1});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}};
    std::map<int, int> c{{1, 1}};
    a.insert_many(std::pair<int, int>{1, 1}, std::pair<int, int>{1, 1});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}};
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}};
    a.insert_many(std::pair<int, int>{2, 2},
                  std::pair<int, int>{3, 3});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    a.insert_many(std::pair<int, int>{6, 6},
                  std::pair<int, int>{7, 7},
                  std::pair<int, int>{8, 8},
                  std::pair<int, int>{9, 9},
                  std::pair<int, int>{1, 1});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    a.insert_many(std::pair<int, int>{5, 5},
                  std::pair<int, int>{4, 4},
                  std::pair<int, int>{3, 3},
                  std::pair<int, int>{2, 2},
                  std::pair<int, int>{1, 1});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{1, 1}};
    std::map<int, int> c{{1, 1}, {2, 2}};
    a.insert_many(std::pair<int, int>{2, 2},
                  std::pair<int, int>{2, 2},
                  std::pair<int, int>{2, 2});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{2, 2}, {4, 4}, {6, 6}, {8, 8}};
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    a.insert_many(std::pair<int, int>{1, 1},
                  std::pair<int, int>{3, 3},
                  std::pair<int, int>{5, 5},
                  std::pair<int, int>{7, 7},
                  std::pair<int, int>{9, 9});
    map_eq(a, c);
  }
}

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
    s21::multiset<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    std::multiset<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
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
  {
    s21::multiset<int> a{1};
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
  }
}

TEST(Multiset, Clear) {
  {
    s21::multiset<int> a{1};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{1, 2, 3, 4, 5};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{5, 4, 3, 2, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{3, 3, 2, 2, 1, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{1, 1, 1, 1, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::multiset<int> a{1, 1, 1, 2, 2, 2};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
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
    s21::multiset<int> a{18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::multiset<int> b{18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
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
    s21::multiset<int> a{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    std::multiset<int> b{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2};
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
  s21::multiset<int> a{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};
  std::multiset<int> b{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};

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
  s21::multiset<int> a{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};
  std::multiset<int> b{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};

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
  s21::multiset<int> a{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};
  std::multiset<int> b{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9};

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
    s21::set<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    std::set<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    set_eq(a, b);
  }
  {
    s21::set<int> a{1, 100, 2, 99, 3, 98, 4, 97, 5, 96, 6, 95, 7, 94, 8, 93, 9, 92, 10, 91, 11, 90};
    std::set<int> b{1, 100, 2, 99, 3, 98, 4, 97, 5, 96, 6, 95, 7, 94, 8, 93, 9, 92, 10, 91, 11, 90};
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
  {
    s21::set<int> a{1};
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
  }
}

TEST(Set, Clear) {
  {
    s21::set<int> a{1};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{1, 2, 3, 4, 5};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{5, 4, 3, 2, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{3, 3, 2, 2, 1, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{1, 1, 1, 1, 1};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::set<int> a{1, 1, 1, 2, 2, 2};
    a.clear();
    EXPECT_EQ(a.size(), 0UL);
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
    s21::set<int> a{18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::set<int> b{18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
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

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}