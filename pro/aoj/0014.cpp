#include <iostream>

int square(int x, int y) {
  return x * y;
}

int main(int argc, char *argv[])
{
  int d;
  while(std::cin >> d) {
    long result = 0;
    for(int x = 0; x < 600; x += d) {
      // std::cout << x << ", ";
      result += square(d, x*x);
    }
    std::cout << result << std::endl;
  }
  
  return 0;
}
