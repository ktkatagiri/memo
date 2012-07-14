#include <iostream>
#include <algorithm>

bool confirm(int x, int y);

int main(int argc, char *argv[])
{
  int n, tri[3], max;

  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> tri[0] >> tri[1] >> tri[2];
    std::sort(tri);
    std::cout << confirm(tri[1],tri[2],tri[0]) ? "YES" : "NO" << std::endl;
  }
  return 0;
}

bool confirm(int x, int y, int z) {
  return (x * x + y * y == z * z) ? true : false;
}
