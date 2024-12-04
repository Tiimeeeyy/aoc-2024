#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int calculateSimilarityScore(std::vector<int> list1, std::vector<int> list2) {
  int similarityScore = 0;
  for (int i = 0; i < list1.size(); ++i) {
    int num = list1[i];
    int counter = 0;
    for (int j = 0; j < list1.size(); ++j) {
      if (list2[j] == num) {
        counter++;
      }
    }
   int intermediate = num * counter;
   similarityScore += intermediate; 
  }

  return similarityScore;
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
  int solution = calculateSimilarityScore(list1, list2);
  std::cout << solution;
  return 0;
}
