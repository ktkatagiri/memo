#include <iostream>
#include <vector>
#include <string>

bool solve(const std::string& str);

int main(int argc, char *argv[])
{
  int count = 0;
  std::string str;
  
  while (std::cin >> str){
    if (solve(str)) ++count;
  }
  std::cout << count << std::endl;
  return 0;
}

bool solve(const std::string& str)
{
  bool result = true;
  for (int i = 0, j = str.size() - 1; i <= str.size()/2; ++i, --j) {
    if(str[i] != str[j]) {
      result = false;
      break;
    }
  }
  return result;
}

