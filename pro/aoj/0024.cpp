#include <iostream>
#include <cmath>

int solve(double limit_v) { // d: ガラスが割れる最低の速度
  double limit_t = limit_v / 9.8; // ガラスが割れる速度が出るまでの時間 
  double limit_y = 4.9 * limit_t * limit_t; //  ガラスが割れる速度が出るまでの距離 

  // std::cout << limit_y << std::endl; //
  int floor_number = limit_y / 5 + 2; // 1階->0m, 2階->5m, 3階->10m...

  return floor_number;
}

int main()
{
  double d;
  while (std::cin >> d) {
    int result = solve(d);
    std::cout << result << std::endl;
  }
  return 0;
}
