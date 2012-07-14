#include <iostream>
#include <vector>
#include <algorithm>

bool confirm(int x, int y, int z);

int main(int argc, char *argv[])
{
  int n;
  std::vector<int> tri(3);

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> tri[0] >> tri[1] >> tri[2];
    std::sort(tri.begin(), tri.end());
    std::cout << (confirm(tri[0], tri[1],tri[2]) ? "YES" : "NO") << std::endl;
  }
  return 0;
}

bool confirm(int x, int y, int z) {
  // std::cout << x << y << z << std::endl;
  return (x * x + y * y == z * z) ? true : false;
}
