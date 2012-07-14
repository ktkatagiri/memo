#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>

int main(int argc, char *argv[])
{
  std::vector<double> p1(2), p2(2), p3(2);
  double a1, b1, c1, a2, b2, c2;

  double ans_x, ans_y, ans_r;

  int dataset_num;
  std::cin >> dataset_num;

  for (int i = 0; i < dataset_num; ++i) {
    std::cin >> p1[0] >> p1[1];
    std::cin >> p2[0] >> p2[1];
    std::cin >> p3[0] >> p3[1];
    
    a1 = 2 * (p2[0] - p1[0]);
    b1 = 2 * (p2[1] - p1[1]);
    c1 = p1[0] * p1[0] - p2[0] * p2[0] + p1[1] * p1[1] - p2[1] * p2[1];
    
    a2 = 2 * (p3[0] - p1[0]);
    b2 = 2 * (p3[1] - p1[1]);
    c2 = p1[0] * p1[0] - p3[0] * p3[0] + p1[1] * p1[1] - p3[1] * p3[1];
    
    ans_x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    ans_y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
    
    ans_r = std::sqrt(std::abs((ans_x - p1[0]) * (ans_x - p1[0]) +
			  (ans_y - p1[1]) * (ans_y - p1[1])));
    // std::cout << std::setprecision(3) << std::fixed <<
    //   ans_x << " " << ans_y << " " << ans_r << std::endl;
    printf("%.3f %.3f %.3f\n",ans_x ,ans_y ,ans_r);
  }

  return 0;
}
