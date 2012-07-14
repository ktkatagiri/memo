#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
  std::string str;
  while(std::cin >> str) {
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;
  }
  return 0;
}
