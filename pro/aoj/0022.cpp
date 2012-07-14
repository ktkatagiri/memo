#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int n;
  std::vector<int> vec;
  int temp = 0;
  while(std::cin >> n) {
    if(n==0) break;
    int x;
    vec.clear();

    for (int i = 0; i < n; ++i) {
      std::cin >> x;
      vec.push_back(x);
    }

    int max = vec[0];

    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i; j < n; ++j) {
	sum += vec[j];
	max = std::max(max, sum);
      }
    }

    std::cout << max << std::endl;
  }

  
  return 0;
}
