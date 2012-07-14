#include <cstdio>
#include <iostream>

int main(int argc, char *argv[])
{
  int a, b, c, d, e, f;
  double x, y;
  while(std::cin >> a >> b >> c >> d >> e >> f) {
    x = (double)(c*e - b*f)/(double)(a*e - b*d);
    y = (double)(c*d - a*f)/(double)(b*d - a*e);
    printf("%.3f %.3f\n", x+0.0, y+0.0); // 0.0 がないと -0.000みたいなことになる．
  }
  return 0;
}
