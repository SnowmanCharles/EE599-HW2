#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    std::cout << solution.PrintHelloWorld() << std::endl;
    std::cout << solution.add(0, 599) << std::endl;
    std::cout << solution.add("EE", "599") << std::endl;
    std::cout << solution.add("EE", 599) << std::endl;
    std::cout << solution.add(0, "EE") << std::endl;

    solution.printSizeOfNonDynamicArray();

    std::vector<int> arr = {1,1,2,2,3,1,2,5,6,2,3,4};
    solution.removeDuplicatesWithoutSet(arr);
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> arr1 = {1,1,2,2,3,1,2,5,6,2,3,4};
    solution.removeDuplicatesWithSet(arr1);
    for (int i : arr1) std::cout << i << " ";
    std::cout << std::endl;

    solution.reverseVector(arr1);
    for (int i : arr1) std::cout << i << " ";
    std::cout << std::endl;

    solution.removeOddNumbers(arr1);
    for (int i : arr1) std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> arr2 = solution.concateVectors(arr, arr1);
    for (int i : arr2) std::cout << i << " ";
    std::cout << std::endl;

    std::vector<int> arr3 = solution.intersectOfVectors(arr, arr1);
    for (int i : arr3) std::cout << i << " ";
    std::cout << std::endl;

    int a = 1, b = 2;
    solution.swap(a, b);
    std::cout << a << " " << b << std::endl;
    solution.swap(&a, &b);
    std::cout << a << " " << b << std::endl;

    std::string s = "EE599";
    solution.swapCharsInString(s, 1, 3);
    std::cout << s << std::endl;

    solution.swapCharsInString(s, 1, 3);
    solution.reverseString(s);
    std::cout << s << std::endl;

    solution.stringToLowerCase(s);
    std::cout << s << std::endl;

    std::cout << solution.isPalindrome("12321") << std::endl;

    std::cout << solution.isApproximatePalindrome("A man, a plan, a canal, Panama!") << std::endl;
    std::cout << solution.isApproximatePalindrome("Was it a car or a cat I saw?") << std::endl;
    std::cout << solution.isApproximatePalindrome("No 'x' in Nixon") << std::endl;

    std::string from = "aabbrr", to = "ccddee";
    std::unordered_map<char, char> map = solution.isMappable(from, to);
    for (const auto& entry : map) {
        std::cout << entry.first << "->" << entry.second << " || ";
    }
    std::cout << std::endl;

    std::vector<double> arr4 = {1,2,3,4,5,6}, arr5 = {637,231,123,43,69,69,43,900,10,7,21,99,0,500};
    std::cout << solution.findMedian(arr4) << " " << solution.findMedian(arr5) << std::endl;
    for (const auto& i : arr5) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}