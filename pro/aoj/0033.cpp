#include <iostream>
#include <vector>
#include <string>
#include <stack>

std::stack<int> g_st1;
std::stack<int> g_st2;

bool solve(std::vector<int> balls, int index) {
  if (index == balls.size()) { return true; }

  bool flag = false;
  if (g_st1.top() < balls[index]) {
    g_st1.push(balls[index]);
    flag = solve(balls, index + 1);
    g_st1.pop();
  }
  if (flag) { return true; }
  if (g_st2.top() < balls[index]) {
    g_st2.push(balls[index]);
    flag = solve(balls, index + 1);
    g_st2.pop();
  }
  if (flag) { return true; }
  return false;
}

int main()
{
  int n;
  std::cin >> n;

  std::vector<int> balls(10);
  g_st1.push(-1);
  g_st2.push(-1);

  while (std::cin >> balls[0] >> balls[1] >> balls[2] >>
	 balls[3] >> balls[4] >> balls[5] >> balls[6] >>
	 balls[7] >> balls[8] >> balls[9]) {

    std::string result = solve(balls, 0) ? "YES" : "NO";
    std::cout << result << std::endl;
  }
  return 0;
}
