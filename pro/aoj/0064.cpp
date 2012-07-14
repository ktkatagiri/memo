#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int solve(const std::string& str);

int main(int argc, char *argv[])
{
  int count = 0;
  std::string str;
  
  while (std::cin >> str){
    count += solve(str);
  }
  std::cout << count << std::endl;
  return 0;
}

int solve(const std::string& str)
{
  int result = 0;

  for (int i = 0; i <= str.size(); ++i) {
    int len = 0;

    if (str[i] >= '1' && str[i] <= '9') {

      for (int j = i; str[j] >= '0' && str[j] <= '9'; ++j) {
	++len;
      }

      int keta = len - 1;
      for (int j = i; j <= i + (len-1); ++j, --keta) {
	result += ((int)str[j] - (int)('0')) * (int)(pow(10, keta));
	// std::cout << "len:" << len << std::endl;
	// std::cout << "now:" << (int)str[j] - (int)('0') << std::endl;
	// std::cout << "result: " << result << std::endl;
      }
    }

    i += len;
  }
  return result;
}

