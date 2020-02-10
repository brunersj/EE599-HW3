#include "src/lib/solution.h"
#include "src/lib/academicrecord.h"
#include "src/lib/sll.h"
#include "gtest/gtest.h"
#include <vector>
#include <iostream>


// Q2
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

TEST(VectToSumTest, HandlesNegativeValues) {
  Solution solution;
  std::vector<int> v = {-1,-2,-3,-4,-5};
  int sum = -8;
  std::vector<int> actual = solution.VectToSum(v,sum);
  std::vector<int> expected = {2,4};
  EXPECT_EQ(expected, actual);
}

// Q3

TEST(SinglyLinkedListTest, HandlesEmptyTrue) {
  SinglyLinkedList sll;
  bool actual = sll.empty();
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesEmptyFalse) {
  SinglyLinkedList sll;
  sll.push_back(1);
  bool actual = sll.empty();
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesSizeEmpty) {
  SinglyLinkedList sll;
  int actual = sll.size();
  int expected = 0;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesSize1) {
  SinglyLinkedList sll;
  sll.push_back(1);
  int actual = sll.size();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesPushBack) {
  SinglyLinkedList sll;
  sll.push_back(4);
  sll.push_back(7);
  int actual = sll.back();
  int expected = 7;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesPushFront) {
  SinglyLinkedList sll;
  sll.push_front(4);
  sll.push_front(7);
  int actual = sll.front();
  int expected = 7;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesInsertAfter) {
  SinglyLinkedList sll;
  sll.push_back(4);
  sll.push_back(7);
  sll.insert_after(sll.head_->next, 8);
  int actual = sll.head_->next->next->val;
  int expected = 8;
  EXPECT_EQ(expected, actual);
}

// TEST(SinglyLinkedListTest, HandlesEraseHeadSize1) {
//   SinglyLinkedList sll;
  
// //   sll.push_back(5);
// //   sll.erase(sll.head_);
  
// //   sll.print();
//   testing::internal::GetCapturedStdout();
//   std::cout << "Empty list: {}";
//   std::string actual = testing::internal::GetCapturedStdout();
//   std::string expected = "Empty list: {}";
//   EXPECT_EQ(expected, actual);
// }

TEST(SinglyLinkedListTest, HandlesPopFront) {
  SinglyLinkedList sll;
  sll.push_back(1);
  sll.pop_front();
  int actual = sll.size();
  int expected = 0;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesBack) {
  SinglyLinkedList sll;
  sll.push_back(1);
  sll.push_back(5);
  sll.push_back(7);
  int actual = sll.back();
  int expected = 7;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesBackEmpty) {
  SinglyLinkedList sll;
  int actual = sll.back();
  int expected = INT32_MIN;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesFront) {
  SinglyLinkedList sll;
  sll.push_back(1);
  sll.push_back(5);
  sll.push_back(7);
  int actual = sll.front();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}

TEST(SinglyLinkedListTest, HandlesFrontEmpty) {
  SinglyLinkedList sll;
  int actual = sll.front();
  int expected = INT32_MIN;
  EXPECT_EQ(expected, actual);
}


// returns head when ith pointer is 0
TEST(SinglyLinkedListTest, HandlesIthPointerHead) {
  SinglyLinkedList sll;
  sll.push_back(3);
  sll.push_back(6);
  sll.push_back(8);
  ListNode* actual = sll.GetIthPointer(0);
  ListNode* expected = sll.head_;
  EXPECT_EQ(expected, actual);
}

// Q4
TEST(ValidBracketTest, HandlesValid1Set) {
  Solution solution;
  std::string input = "(a+b)";
  bool actual = solution.ValidBracket(input);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(ValidBracketTest, HandlesValid3Series) {
  Solution solution;
  std::string input = "(a+b)[c*d]{5g+h}";
  bool actual = solution.ValidBracket(input);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(ValidBracketTest, HandlesInvalid2Nested) {
  Solution solution;
  std::string input = "(7h+[5c)+7]";
  bool actual = solution.ValidBracket(input);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(ValidBracketTest, HandlesValid2Nested) {
  Solution solution;
  std::string input = "{2k+[5j]}";
  bool actual = solution.ValidBracket(input);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}


TEST(ValidBracketTest, HandlesValid2Nested2) {
  Solution solution;
  std::string input = "{2k++[5--*j]}";
  bool actual = solution.ValidBracket(input);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(ValidBracketTest, HandlesOpenBracket) {
  Solution solution;
  std::string input = "{2k++[5--*j";
  bool actual = solution.ValidBracket(input);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(ValidBracketTest, HandlesNoBracket) {
  Solution solution;
  std::string input = "a+b";
  bool actual = solution.ValidBracket(input);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

// Q5
TEST(AcademicRecordTest, PostIncrementLimit100){
    AcademicRecord actual(95,95,95);
    actual++;
    int expected = 100;
    EXPECT_EQ(expected, actual.GetMaths());
    EXPECT_EQ(expected, actual.GetComputers());
    EXPECT_EQ(expected, actual.GetPhysics());
}

TEST(AcademicRecordTest, PreIncrementLimit100){
    AcademicRecord actual(95,95,95);
    ++actual;
    int expected = 100;
    EXPECT_EQ(expected, actual.GetMaths());
    EXPECT_EQ(expected, actual.GetComputers());
    EXPECT_EQ(expected, actual.GetPhysics());
}

TEST(AcademicRecordTest, PostDecrementLimit0){
    AcademicRecord actual(5,5,5);
    actual--;
    int expected = 0;
    EXPECT_EQ(expected, actual.GetMaths());
    EXPECT_EQ(expected, actual.GetComputers());
    EXPECT_EQ(expected, actual.GetPhysics());
}

TEST(AcademicRecordTest, PreDecrementLimit0){
    AcademicRecord actual(5,5,5);
    --actual;
    int expected = 0;
    EXPECT_EQ(expected, actual.GetMaths());
    EXPECT_EQ(expected, actual.GetComputers());
    EXPECT_EQ(expected, actual.GetPhysics());
}

TEST(AcademicRecordTest, DefaultConstructor){
    AcademicRecord actual;
    int expected = 0;
    EXPECT_EQ(expected, actual.GetMaths());
    EXPECT_EQ(expected, actual.GetComputers());
    EXPECT_EQ(expected, actual.GetPhysics());
}

TEST(AcademicRecordTest, ParameterizedConstructor){
    AcademicRecord actual(85,90,82);
    EXPECT_EQ(85, actual.GetMaths());
    EXPECT_EQ(90, actual.GetComputers());
    EXPECT_EQ(82, actual.GetPhysics());
}

TEST(AcademicRecordTest, CopyConstructor){
    AcademicRecord expected(85,90,82);
    AcademicRecord actual(expected);

    EXPECT_EQ(85, actual.GetMaths());
    EXPECT_EQ(90, actual.GetComputers());
    EXPECT_EQ(82, actual.GetPhysics());
}

TEST(AcademicRecordTest, HandlesComparisonTrue){
    AcademicRecord s1(85,90,82);
    AcademicRecord s2(s1);
    bool actual = s1==s2;
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(AcademicRecordTest, HandlesComparisonFalse){
    AcademicRecord s1(85,90,82);
    AcademicRecord s2;
    bool actual = s1==s2;
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(AcademicRecordTest, HandlesPlusEqual){
    AcademicRecord actual(85,90,82);
    actual += 5;
    EXPECT_EQ(90, actual.GetMaths());
    EXPECT_EQ(95, actual.GetComputers());
    EXPECT_EQ(87, actual.GetPhysics());
}

TEST(AcademicRecordTest, HandlesPlusEqualLimit100){
    AcademicRecord actual(85,90,82);
    actual += 12;
    EXPECT_EQ(97, actual.GetMaths());
    EXPECT_EQ(100, actual.GetComputers());
    EXPECT_EQ(94, actual.GetPhysics());
}

TEST(AcademicRecordTest, HandlesMinusEqual){
    AcademicRecord s1(85,90,82);
    AcademicRecord s2(80,85,77);
    s1 -= 5;
    bool actual = s1==s2;
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(AcademicRecordTest, HandlesMinusEqualLimit0){
    AcademicRecord s1(5,5,5);
    AcademicRecord s2(0,0,0);
    s1 -= 10;
    bool actual = s1==s2;
    bool expected = true;
    EXPECT_EQ(expected, actual);
    EXPECT_EQ(0, s1.GetMaths());
    EXPECT_EQ(0, s1.GetComputers());
    EXPECT_EQ(0, s1.GetPhysics());
}

// AcademicRecord obj1, obj2;
//     obj1.SetMaths(5);
//     obj1.SetComputers(10);
//     obj1.SetPhysics(95);
//     cout << "Value before incrementation ::\n" << obj1.Print() << endl;
//     obj1++;
//     cout<< "Value after incrementation ::\n"<< obj1.Print() << endl;
//     obj1--;
//     cout<< "Value after decrementation ::\n"<< obj1.Print() << endl;
//     obj2=obj1;
//     cout<< "Value of Object 2::" << obj2.Print() << endl;
//     obj2+=50;
//     cout<< "Value of Object 2 after increasing marks by 50 for each subject::\n" << obj2.Print() << endl;
//     obj2-=30;
//     cout<< "Value of Object 2 after decreasing marks by 30 for each subject::\n" << obj2.Print() << endl;