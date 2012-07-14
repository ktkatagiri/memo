#include <iostream>

int gcd(int a, int b);
int lcm(int a, int b);

int main(int argc, char *argv[])
{
  int a, b, ans; // under 20 hundred million
  while(std::cin >> a >> b) {
    std::cout << gcd(a,b) << " " << lcm(a,b) << std::endl;
  }
  return 0;
}

int gcd(int a, int b) {
  int tmp;
  if ( (a <= 0) || (b <= 0) ) {
    return 0;
  } else if (a == b) {
    return a;
  } else if (a > b) {
    return gcd(a-b, b);
  } else {
    return gcd(a, b-a);
  }
}

int lcm(int a, int b) {
  int ret;
  if ( (a == 0) || (b == 0) ) {
    return 0;
  }
  ret = (b / gcd(a, b)) * a; // keep away overflow
  return ret;
}
