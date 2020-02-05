#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
  std::string PrintHelloWorld();

  //Q1******************************************************************************************
  int add(int a, int b);
  std::string add(std::string a, std::string b);
  std::string add(std::string a, int b);
  std::string add(int a, std::string b);

  //Q2******************************************************************************************
  void printSizeOfNonDynamicArray();

  //Q3******************************************************************************************
  void removeDuplicatesWithoutSet(std::vector<int>& arr);
  void removeDuplicatesWithSet(std::vector<int>& arr);
  void reverseVector(std::vector<int>& arr);
  void removeOddNumbers(std::vector<int>& arr);
  std::vector<int> concateVectors(std::vector<int> arr1, std::vector<int> arr2);
  std::vector<int> intersectOfVectors(std::vector<int> arr1, std::vector<int> arr2);

  //Q4******************************************************************************************
  void swap(int& a, int& b);
  void swap(int *a, int *b);

  //Q5******************************************************************************************
  bool swapCharsInString(std::string& s, int a, int b);
  void reverseString(std::string& s);
  void stringToLowerCase(std::string& s);

  //Q6******************************************************************************************
  bool isPalindrome(std::string s);
  bool isApproximatePalindrome(std::string s);

  //Q7*****************************************************************************************
  std::unordered_map<char, char> isMappable(std::string from, std::string to);

  //Q8******************************************************************************************
  double findMedian(std::vector<double>& arr);
};

#endif