#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

#include <sstream>

int solve(const std::string& str);

int main(int argc, char *argv[])
{
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    int ans = solve(str);
    std::cout << ans << std::endl;
  }
  // printf("%p",solve);
  return 0;
}

int solve(const std::string& str) {
  // correct word number
  std::string maxstr = str;
  std::string minstr = str;
  int max, min;

  std::sort(maxstr.begin(), maxstr.end(), std::greater<int>());
  std::sort(minstr.begin(), minstr.end());
  std::string buf;

  // 文字列→数値
  std::stringstream ss;
  ss << maxstr;
  ss >> max;
  ss.clear();

  ss << minstr; //.substr(foo);
  ss >> min;
  ss.clear();

  return max - min;
}

