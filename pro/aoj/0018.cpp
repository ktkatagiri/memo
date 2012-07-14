#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

// delim = spacea only
std::vector<int> split(const std::string str) {
  std::vector<int> res;
  std::stringstream ss(str);
  int temp;
  while (ss >> temp) {
    res.push_back(temp);
  }
  return res;
}

int main(int argc, char *argv[])
{
  std::string str;
  while(std::getline(std::cin, str)) {
    std::vector<int> vec = split(str);
    std::sort(vec.begin(), vec.end(),std::greater<int>());

    std::vector<int>::iterator it = vec.begin();
    if (it != vec.end()) {
      std::cout << *it; ++it;
      for (; it != vec.end(); ++it) {
	std::cout << " " << *it;
      }
      std::cout << std::endl;
    }

  }
  return 0;
}
