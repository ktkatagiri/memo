#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
  int n;
  int debt = 100000; // 100k
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    debt += debt / 20;
    if (debt % 1000 > 0) { debt += (1000 - (debt % 1000)); }
  }
  std::cout << debt << std::endl;
  return 0;
}
