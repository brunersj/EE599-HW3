#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(VectToSumTest, HandlesConsecutiveVectWithSum) {
  Solution solution;
  std::vector<int> v = {1,2,3,4,5,6};
  int sum = 5;
  std::vector<int> actual = solution.VectToSum(v,sum);
  std::vector<int> expected = {0,3};
  EXPECT_EQ(expected, actual);
}

TEST(VectToSumTest, HandlesConsecutiveVectWithNoSum) {
  Solution solution;
  std::vector<int> v = {1,2,3,4,5,6};
  int sum = 12;
  std::vector<int> actual = solution.VectToSum(v,sum);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(VectToSumTest, HandlesNonConsecutiveVectWithSum) {
  Solution solution;
  std::vector<int> v = {2,5,3,7,6};
  int sum = 10;
  std::vector<int> actual = solution.VectToSum(v,sum);
  std::vector<int> expected = {2,3};
  EXPECT_EQ(expected, actual);
}

TEST(VectToSumTest, HandlesNonConsecutiveVectWithNoSum) {
  Solution solution;
  std::vector<int> v = {2,5,3,7,6};
  int sum = 19;
  std::vector<int> actual = solution.VectToSum(v,sum);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(VectToSumTest, HandlesNegSum) {
  Solution solution;
  std::vector<int> v = {2,5,3,7,6};
  int sum = -3;
  std::vector<int> actual = solution.VectToSum(v,sum);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(VectToSumTest, HandlesRepeatedValueWithSum) {
  Solution solution;
  std::vector<int> v = {2,5,3,7,3,6};
  int sum = 6;
  std::vector<int> actual = solution.VectToSum(v,sum);
  std::vector<int> expected = {2,4};
  EXPECT_EQ(expected, actual);
}

TEST(VectToSumTest, HandlesEmptyVector) {
  Solution solution;
  std::vector<int> v = {};
  int sum = 6;
  std::vector<int> actual = solution.VectToSum(v,sum);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}