#include <gtest/gtest.h>

#include <map>

#include "../model/s21_map.hh"

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
    s21::map<int, int> a{{2, 2}, {4, 4}, {6, 6}, {8, 8},
                         {1, 1}, {3, 3}, {5, 5}, {7, 7}};
    std::map<int, int> b{{2, 2}, {4, 4}, {6, 6}, {8, 8},
                         {1, 1}, {3, 3}, {5, 5}, {7, 7}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {3, 3}, {5, 5}, {7, 7},
                         {2, 2}, {4, 4}, {6, 6}, {8, 8}};
    std::map<int, int> b{{1, 1}, {3, 3}, {5, 5}, {7, 7},
                         {2, 2}, {4, 4}, {6, 6}, {8, 8}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {9, 9}, {8, 8}, {7, 7}, {6, 6}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {9, 9}, {8, 8}, {7, 7}, {6, 6}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {5, 5},
                         {4, 4}, {3, 3}, {2, 2}, {1, 1}, {5, 5},
                         {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    std::map<int, int> b{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {5, 5},
                         {4, 4}, {3, 3}, {2, 2}, {1, 1}, {5, 5},
                         {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {6, 6}, {7, 7}, {8, 8}, {9, 9}};
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
    std::vector<std::pair<int, int>> vec{
        {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    for (auto val : vec) {
      a[val.first] = val.first;
      b[val.first] = val.first;
    }
    map_eq(a, b);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}};
    std::vector<std::pair<int, int>> vec{
        {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
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
  { s21::map<int, int> a{{1, 1}}; }
  { s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}}; }
  { s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}}; }
  { s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}}; }
  { s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}}; }
  { s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}}; }
}

TEST(Map, Clear) {
  {
    s21::map<int, int> a{{1, 1}};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{3, 3}, {3, 3}, {2, 2}, {2, 2}, {1, 1}, {1, 1}};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    a.clear();
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.empty(), true);
  }
  {
    s21::map<int, int> a{{1, 1}, {1, 1}, {1, 1}, {2, 2}, {2, 2}, {2, 2}};
    a.clear();
    EXPECT_EQ(a.size(), 0);
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
    std::map<int, int> b{{2, 2}, {4, 4}, {6, 6}, {8, 8},
                         {1, 1}, {3, 3}, {5, 5}, {7, 7}};
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
    std::map<int, int> b{{1, 1}, {3, 3}, {5, 5}, {7, 7},
                         {2, 2}, {4, 4}, {6, 6}, {8, 8}};
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
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {9, 9}, {8, 8}, {7, 7}, {6, 6}};
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
    std::map<int, int> b{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {5, 5},
                         {4, 4}, {3, 3}, {2, 2}, {1, 1}, {5, 5},
                         {4, 4}, {3, 3}, {2, 2}, {1, 1}};
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
    std::map<int, int> b{{2, 2}, {4, 4}, {6, 6}, {8, 8},
                         {1, 1}, {3, 3}, {5, 5}, {7, 7}};
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
    std::map<int, int> b{{1, 1}, {3, 3}, {5, 5}, {7, 7},
                         {2, 2}, {4, 4}, {6, 6}, {8, 8}};
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
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {9, 9}, {8, 8}, {7, 7}, {6, 6}};
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
    std::map<int, int> b{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {5, 5},
                         {4, 4}, {3, 3}, {2, 2}, {1, 1}, {5, 5},
                         {4, 4}, {3, 3}, {2, 2}, {1, 1}};
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
  std::vector<std::pair<int, int>> vec{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                                       {6, 6}, {7, 7}, {8, 8}, {9, 9}};
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
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
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
    a.insert_many(std::pair<int, int>{2, 2}, std::pair<int, int>{3, 3});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    a.insert_many(std::pair<int, int>{6, 6}, std::pair<int, int>{7, 7},
                  std::pair<int, int>{8, 8}, std::pair<int, int>{9, 9},
                  std::pair<int, int>{1, 1});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {6, 6}, {7, 7}, {8, 8}, {9, 9}, {1, 1}};
    a.insert_many(std::pair<int, int>{5, 5}, std::pair<int, int>{4, 4},
                  std::pair<int, int>{3, 3}, std::pair<int, int>{2, 2},
                  std::pair<int, int>{1, 1});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{1, 1}};
    std::map<int, int> c{{1, 1}, {2, 2}};
    a.insert_many(std::pair<int, int>{2, 2}, std::pair<int, int>{2, 2},
                  std::pair<int, int>{2, 2});
    map_eq(a, c);
  }
  {
    s21::map<int, int> a{{2, 2}, {4, 4}, {6, 6}, {8, 8}};
    std::map<int, int> c{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                         {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    a.insert_many(std::pair<int, int>{1, 1}, std::pair<int, int>{3, 3},
                  std::pair<int, int>{5, 5}, std::pair<int, int>{7, 7},
                  std::pair<int, int>{9, 9});
    map_eq(a, c);
  }
}