#include <iostream>
#include <vector>
#include <string>
// #include <map>
// void xorSwap (int& x, int& y) {
//   if (x != y) { x ^= y; y ^= x; x ^= y; }
// }

int solve(const std::vector<int>& dataset);

int main(int argc, char *argv[])
{
  std::vector<int> dataset(10);
  std::string str;
  
  while (std::cin >> str){
    for (int i = 0; i < 10; ++i) {
      dataset[i] = (int)(str[i] - '0');
    }
    std::cout << solve(dataset) << std::endl;
  }

  return 0;
}

int solve(const std::vector<int>& dataset)
{
  if (dataset.size() == 1) {
    return dataset[0];
  } else {
    std::vector<int> dataset2(dataset.size() - 1);
    for (int i = 0; i < dataset2.size(); ++i) {
      dataset2[i] = (dataset[i] + dataset[i+1]) % 10;
      // std::cout << dataset2[i] << " ";
    }
    // std::cout << std::endl;
    return solve(dataset2);
  }
}

