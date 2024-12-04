
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int calculateListDistance(std::vector<int> list1, std::vector<int> list2) {
  std::sort(list1.begin(), list1.end());
  std::sort(list2.begin(), list2.end());

  if (list1.size() != list2.size()) {
    std::cout << "Lists are not of the same size!";
    return 0;
  }
  int totalDifference = 0;
  for (int i = 0; i < list1.size(); ++i) {
    int calc = list1[i] - list2[i];
    int difference = std::abs(calc);
    totalDifference += difference;
  }

  return totalDifference;
}

int main(void) {
  std::ifstream inputFile("input.txt");
  std::vector<int> list1;
  std::vector<int> list2;

  if (inputFile.is_open()) {
    std::string line;
    while (std::getline(inputFile, line)) {
      std::istringstream iss(line);
      int first, second;
      if (iss >> first >> second) {
        list1.push_back(first);
        list2.push_back(second);
      } else {
        std::cerr << "Error reading line." << std::endl;
      }
    }
    inputFile.close();

  } else {
    std::cerr << "Unable to open file" << std::endl;
  }

  std::cout << "First numbers: ";
  for (int num : list1) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << "Second numbers: ";
  for (int num : list2) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  int solution = calculateListDistance(list1, list2);
  std::cout << solution;
  return 0;
}
