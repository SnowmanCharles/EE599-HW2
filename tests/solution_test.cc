#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
#include <unordered_map>

TEST(HelloWorldShould, ReturnHelloWorld) {
  Solution solution;
  std::string actual = solution.PrintHelloWorld();
  std::string expected = "**** Hello World ****";
  EXPECT_EQ(expected, actual);
}

//Q1************************************************************************************************
TEST(AddIntInt, ZeroInput) {
  Solution solution;
  EXPECT_EQ(0, solution.add(0, 0));
}

TEST(AddIntInt, NegativePositive) {
  Solution solution;
  EXPECT_EQ(1, solution.add(-1, 2));
}

TEST(AddIntInt, PositivePositive) {
  Solution solution;
  EXPECT_EQ(12, solution.add(3, 9));
}

TEST(AddStringString, BothEmpty) {
  Solution solution;
  EXPECT_EQ("", solution.add("", ""));
}

TEST(AddStringString, EmptyNonEmpty) {
  Solution solution;
  EXPECT_EQ("123", solution.add("", "123"));
}

TEST(AddStringString, NonEmptyEmpty) {
  Solution solution;
  EXPECT_EQ("123", solution.add("123", ""));
}

TEST(AddStringString, EmptyEmpty) {
  Solution solution;
  EXPECT_EQ("456123", solution.add("456", "123"));
}

TEST(AddStringInt, EmptyZero) {
  Solution solution;
  EXPECT_EQ("0", solution.add("", 0));
}

TEST(AddStringInt, EmptyNonZero) {
  Solution solution;
  EXPECT_EQ("99", solution.add("", 99));
}

TEST(AddStringInt, NonEmptyZero) {
  Solution solution;
  EXPECT_EQ("EE0", solution.add("EE", 0));
}

TEST(AddStringInt, NonEmptyNonZero) {
  Solution solution;
  EXPECT_EQ("EE599", solution.add("EE", 599));
}

TEST(AddIntString, ZeroEmpty) {
  Solution solution;
  EXPECT_EQ("0", solution.add(0, ""));
}

TEST(AddIntString, ZeroNonEmpty) {
  Solution solution;
  EXPECT_EQ("0EE", solution.add(0, "EE"));
}

TEST(AddIntString, NonZeroEmpty) {
  Solution solution;
  EXPECT_EQ("599", solution.add(599, ""));
}

TEST(AddIntString, NonZeroNonEmpty) {
  Solution solution;
  EXPECT_EQ("599EE", solution.add(599, "EE"));
}

//Q2************************************************************************************************

//Q3************************************************************************************************
TEST(RemoveDuplicatesWithoutSet, EmptyCase) {
  Solution solution;
  std::vector<int> vec = {};
  solution.removeDuplicatesWithoutSet(vec);
  EXPECT_EQ(0, vec.size());
}

TEST(RemoveDuplicatesWithoutSet, NonEmptyCase) {
  Solution solution;
  std::vector<int> vec = {1,2,1,2,3,2,4,1};
  solution.removeDuplicatesWithoutSet(vec);
  EXPECT_EQ(4, vec.size());
}

TEST(RemoveDuplicatesWithSet, EmptyCase) {
  Solution solution;
  std::vector<int> vec = {};
  solution.removeDuplicatesWithSet(vec);
  EXPECT_EQ(0, vec.size());
}

TEST(RemoveDuplicatesWithSet, NonEmptyCase) {
  Solution solution;
  std::vector<int> vec = {1,2,1,2,3,2,4,1};
  solution.removeDuplicatesWithSet(vec);
  EXPECT_EQ(4, vec.size());
}

//Q4************************************************************************************************
TEST(SwapWithReference, TestSwapWithReference) {
  Solution solution;
  int a = 1, b = -2;
  solution.swap(a, b);
  EXPECT_EQ(-2, a);
  EXPECT_EQ(1, b);
}

TEST(SwapWithPointer, TestSwapWithPointer) {
  Solution solution;
  int a = 1, b = -2;
  solution.swap(&a, &b);
  EXPECT_EQ(-2, a);
  EXPECT_EQ(1, b);
}
//Q5************************************************************************************************
TEST(SwapCharsInString, TestSwapCharsInString) {
  Solution solution;
  std::string s = "EE599";
  solution.swapCharsInString(s, 1, 3);
  EXPECT_EQ("E95E9", s);
}

TEST(SwapCharsInString, TestSwapCharsInStringOutOfBoundry) {
  Solution solution;
  std::string s = "EE599";
  solution.swapCharsInString(s, -1, 3);
  EXPECT_EQ("EE599", s);
}

TEST(ReverseString, TestReverseString) {
  Solution solution;
  std::string s = "EE599";
  solution.reverseString(s);
  EXPECT_EQ("995EE", s);
}

TEST(ReverseString, TestReverseStringEmpty) {
  Solution solution;
  std::string s = "";
  solution.reverseString(s);
  EXPECT_EQ("", s);
}

TEST(StringToLowerCase, TestStringToLowerCase) {
  Solution solution;
  std::string s = "EE599";
  solution.stringToLowerCase(s);
  EXPECT_EQ("ee599", s);
}

TEST(StringToLowerCase, TestStringToLowerCaseEmpty) {
  Solution solution;
  std::string s = "";
  solution.stringToLowerCase(s);
  EXPECT_EQ("", s);
}

//Q6************************************************************************************************
TEST(IsPalindrome, TestIsPalindromeFailer) {
  Solution solution;
  std::string s = "EE599";
  bool res = solution.isPalindrome(s);
  EXPECT_EQ(false, res);
}

TEST(IsPalindrome, TestIsPalindromeEmpty) {
  Solution solution;
  std::string s = "";
  bool res = solution.isPalindrome(s);
  EXPECT_EQ(true, res);
}

TEST(IsPalindrome, TestIsPalindromeSuccess) {
  Solution solution;
  std::string s = "9E5E9";
  bool res = solution.isPalindrome(s);
  EXPECT_EQ(true, res);
}

TEST(IsApproximatePalindrome, TestIsApproximatePalindromeFailer) {
  Solution solution;
  std::string s = "EE599";
  bool res = solution.isApproximatePalindrome(s);
  EXPECT_EQ(false, res);
}

TEST(IsApproximatePalindrome, TestIsApproximatePalindromeEmpty) {
  Solution solution;
  std::string s = "";
  bool res = solution.isApproximatePalindrome(s);
  EXPECT_EQ(true, res);
}

TEST(IsApproximatePalindrome, TestIsApproximatePalindromeSuccess) {
  Solution solution;
  std::string s = "9 E5E,9?";
  bool res = solution.isApproximatePalindrome(s);
  EXPECT_EQ(true, res);
}

//Q7************************************************************************************************
TEST(IsMappable, TestIsMappableSuccess) {
  Solution solution;
  std::string from = "aabbcc", to = "ddeeff";
  std::unordered_map<char, char> res = solution.isMappable(from, to);
  EXPECT_EQ('d', res['a']);
  EXPECT_EQ('e', res['b']);
  EXPECT_EQ('f', res['c']);
}

TEST(IsMappable, TestIsMappableFailure) {
  Solution solution;
  std::string from = "aabbcc", to = "ddeefg";
  std::unordered_map<char, char> res = solution.isMappable(from, to);
  EXPECT_EQ(0, res.size());
}

//Q8************************************************************************************************
TEST(FindMedian, TestFindMedianOddSize) {
  Solution solution;
  std::vector<double> vec = {3.3, 2.2, 1.1, 5.5, 4.4}, expectRes = {2.2, 1.1, 3.3, 4.4, 5.5};
  double res = solution.findMedian(vec);
  EXPECT_EQ(3.3, res);
  bool isEqual = true;
  for (int i = 0; i < 5; i++) {
    if (vec[i] != expectRes[i]) {
      res = false;
    }
  }
  EXPECT_EQ(true, isEqual);
}

TEST(FindMedian, TestFindMedianEvenSize) {
  Solution solution;
  std::vector<double> vec = {3.3, 2.2, 1.1, 5.5, 4.4, 0}, expectRes = {1.1 , 0, 2.2, 3.3, 4.4, 5.5};
  double res = solution.findMedian(vec);
  EXPECT_EQ(2.75, res);
  bool isEqual = true;
  for (int i = 0; i < 6; i++) {
    if (vec[i] != expectRes[i]) {
      res = false;
    }
  }
  EXPECT_EQ(true, isEqual);
}


//Q9************************************************************************************************
