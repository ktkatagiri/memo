#include <iostream>
// #include <vector>
// #include <algorithm>
#include <cmath>

// ２つの円の位置関係の求め方覚えておく

int solve(double xa, double ya, double ra, double xb, double yb, double rb) {
  double d = std::sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya));
  
  return (ra + rb < d) ? 0 : // 重なっていないとき(外)
    (ra < rb && d < rb - ra) ? -2 : // AがBの中にある
    (rb < ra && d < ra - rb) ? 2 : // BがAの中にある
    1; // 重なっている
}

int main()
{
  int n;
  std::cin >> n;
  
  int result = 0;
  double xa,ya,ra,xb,yb,rb;

  for (int i = 0; i < n; ++i) {
    std::cin >> xa >> ya >> ra >> xb >> yb >> rb;
    result = solve(xa,ya,ra,xb,yb,rb);
    std::cout << result << std::endl;
  }
  return 0;
}
