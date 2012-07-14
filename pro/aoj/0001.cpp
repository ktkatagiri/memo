#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
  int n;
  std::vector<int> mountains;

  for (int i = 0; i < 10; ++i) {
    std::cin >> n;
    mountains.push_back(n);
  }
  std::sort(mountains.begin(), mountains.end());

  std::vector<int>::reverse_iterator rit = mountains.rbegin();
  for (int i = 0; i < 3; ++i) {
    std::cout << *rit << std::endl;
    ++rit;
  }
  return 0;
}
