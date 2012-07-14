#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

std::string solve(std::string str);

int main(int argc, char *argv[])
{
  std::string str;
  getline(std::cin, str);
  // std::cout << str << std::endl;
  std::cout << solve(str) << std::endl;

  return 0;
}

std::string solve(std::string str) {
  std::vector<int> words1, words2;
  words1.push_back(0);
  words2.push_back(0);
  // correct word number

  int n;
  while(n = str.find("peach", words1.back() + 5),
       ~n) {
    words1.push_back(n);
  }
  while (n = str.find("apple", words2.back() + 5),
	 ~n) {
    words2.push_back(n);
  }

  std::vector<int>::iterator it;

  it = words1.begin(); ++it;
  while(it != words1.end()) {
    int n = *it;
    str.replace(n,
		5,
		"apple");
    ++it;
  }
  
  it = words2.begin(); ++it;
  while(it != words2.end()) {
    int n = *it;
    str.replace(n, 5, "peach");
    ++it;
  }

  return str;
}
