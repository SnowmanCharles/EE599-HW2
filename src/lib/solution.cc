#include "solution.h"
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>

std::string Solution::PrintHelloWorld() { 
  return "**** Hello World ****"; 
}

//Q1******************************************************************************************
int Solution::add(int a, int b) {//O(x) where x is the number of bits represent a and b, for integers it's 32
  return a + b;
}

std::string Solution::add(std::string a, std::string b) {//O(m + n) where m and n are lengths of a and b
  return a + b;
}

std::string Solution::add(std::string a, int b) {//O(m + x)
  return a + std::to_string(b);
}

std::string Solution::add(int a, std::string b) {//O(x + n)
  return std::to_string(a) + b;
}

//Q2******************************************************************************************
void Solution::printSizeOfNonDynamicArray() {//O(1)
  int arr1[123];
  char arr2[456];
  float arr3[789];
  std::cout << sizeof(arr1) / 4 << std::endl;//O(1)
  std::cout << sizeof(arr2) << std::endl;//O(1)
  std::cout << sizeof(arr3) / 4 << std::endl;//O(1)
}

//Q3******************************************************************************************
void Solution::removeDuplicatesWithoutSet(std::vector<int>& arr) {//O(nlog(n)) where n is the length of the input vector
  if (arr.size() == 0) return;
  std::sort(arr.begin(), arr.end());
  std::vector<int> res;
  res.push_back(arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] != arr[i - 1]) {
      res.push_back(arr[i]);
    }
  }
  arr = res;
}

void Solution::removeDuplicatesWithSet(std::vector<int>& arr){//O(nlog(n)) where n is the length of the input vector
  if (arr.size() == 0) return;
  std::set<int> set;
  std::vector<int> temp;
  for (int num : arr) {
    if (set.count(num) == 0) {
      set.insert(num);
      temp.push_back(num);
    }
  }
  arr = temp;
}

void Solution::reverseVector(std::vector<int>& arr) {//O(n) where n is the length of the input vector
  if (arr.size() <= 1) return;
  int i = 0, j = arr.size() - 1;
  while (i < j) {
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
    i++;
    j--;
  }
}

void Solution::removeOddNumbers(std::vector<int>& arr) { //O(n) where n is the length of the input vector
  std::vector<int> temp;
  for (int i : arr) {
    if (i % 2 == 0) temp.push_back(i);
  }
  arr = temp;
}

std::vector<int> Solution::concateVectors(std::vector<int> arr1, std::vector<int> arr2) {//O(m + n)
  std::vector<int> res;
  for (int i : arr1) res.push_back(i);
  for (int i : arr2) res.push_back(i);
  return res;
}

std::vector<int> Solution::intersectOfVectors(std::vector<int> arr1, std::vector<int> arr2) {//O(m + n)
  std::vector<int> res;
  std::unordered_set<int> set;
  for (int i : arr1) set.insert(i);
  for (int i : arr2) {
    if (set.count(i) > 0) {
      res.push_back(i);
    }
  }
  return res;
}

//Q4******************************************************************************************
void Solution::swap(int& a, int& b) {//O(1)
  int temp = a;
  a = b;
  b = temp;
}

void Solution::swap(int *a, int *b) {//O(1)
  int temp = *b;
  *b = *a;
  *a = temp;
}

//Q5******************************************************************************************
bool Solution::swapCharsInString(std::string& s, int a, int b) {//O(1)
  int n = s.length();
  if (a < 0 || a >= n || b < 0 || b >= n) return false;
  char temp = s[a];
  s[a] = s[b];
  s[b] = temp;
  return true;
}

void Solution::reverseString(std::string& s) {//O(n)
  int i = 0, j = s.length() - 1;
  while (i < j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++; j--;
  }
}

void Solution::stringToLowerCase(std::string& s) {//O(n)
  for (char& c : s) {
    c = std::tolower(c);
  }
}

//Q6******************************************************************************************
bool Solution::isPalindrome(std::string s) {//O(n)
  int i = 0, j = s.length() - 1;
  while (i < j) {
    if (s[i] != s[j]) return false;
    i++; j--;
  }
  return true;
}

bool Solution::isApproximatePalindrome(std::string s) {//O(n)
  int i = 0, j = s.length() - 1;
  while (i < j) {
    if (std::ispunct(s[i]) || s[i] == ' ') {
      i++;
    } else if (std::ispunct(s[j]) || s[j] == ' ') {
      j--;
    } else if (std::toupper(s[i]) != std::toupper(s[j])) {
      return false;
    } else {
      i++; j--;
    }
  }
  return true;
}

//Q7******************************************************************************************
std::unordered_map<char, char> Solution::isMappable(std::string from, std::string to) {//O(n)
  std::unordered_map<char, char> map;
  if (from.length() != to.length()) return map;
  for (int i = 0; i < from.length(); i++) {
    if (map.count(from[i]) && map[from[i]] != to[i]) {
      map.clear();
      return map;
    }
    map[from[i]] = to[i];
  }
  return map;
 }

 //Q8******************************************************************************************
 double Solution::findMedian(std::vector<double>& arr) {//O(nlog(n))
   std::sort(arr.begin(), arr.end());
   int n = arr.size();

   int i = 0, j = (n - 1) / 2 - 1;
   while (i < j) {
     double temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
     i++; j--;
   }

   if (n % 2 == 0) {
     return (arr[n / 2] + arr[n / 2 - 1]) / 2;
   } else {
     return arr[n / 2];
   }
 }
