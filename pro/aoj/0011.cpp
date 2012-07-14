#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
  int w, n;

  std::cin >> w >> n;
  std::vector<int> longitudinal(w);

  for (int i = 0; i < w; ++i) { longitudinal[i] = i+1; }

  for (int i = 0; i < n; ++i) {
    int tmp1,tmp2;
    scanf("%d,%d",&tmp1,&tmp2);
    std::swap(longitudinal[tmp1-1], longitudinal[tmp2-1]);
  }

  for (int i = 0; i < longitudinal.size(); ++i) {
    std::cout << longitudinal[i] << std::endl;
  }

  return 0;
}
