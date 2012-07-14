#include <iostream>

int N = 10;

int main(int argc, char *argv[])
{
  int a[] = {N,N};
  std::cout << a[1] << std::endl;
  for (int i = 0, x = 0; i < N; ++i, i++, x = i) {
    std::cout << x << std::endl;
  }
  return 0;
}
