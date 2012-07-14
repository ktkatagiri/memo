#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

std::vector<int> solve(std::vector < std::vector<int> > dataset);

// 誤差丸め四捨五入
double round(double src, int n)
{
  double dst;
  
  dst = src * pow(10, -n - 1);
  dst = (double)(int)(dst + 0.5);
  
  return dst * pow(10, n + 1);
}

// 文字列分割
std::vector< std::string > split(const std::string &str, char delim) {
  std::vector< std::string> res;
  size_t current = 0, found;

  while((found = str.find_first_of(delim, current)) != std::string::npos){
    res.push_back(std::string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(std::string(str, current, str.size() - current));
  return res;
}

int main(int argc, char *argv[])
{
  std::string str;
  std::vector < std::vector<int> > dataset;
  std::vector<int> vec;

  while(std::cin >> str) {
    std::vector< std::string> str_vec = split(str, ',');

    for (int i = 0; i < str_vec.size(); ++i) {
      std::stringstream ss(str_vec[i]);
      int temp;
      ss >> temp;
      vec.push_back(temp);
    }
    dataset.push_back(vec);
    vec.clear();
  }

  vec = solve(dataset);
  std::cout << vec[0] << "\n" << vec[1] << std::endl;
  return 0;
}

std::vector<int> solve(std::vector < std::vector<int> > dataset) {
  std::vector<int> result(2);
  result[0] = 0;
  result[1] = 0;
  
  for (int i = 0; i < dataset.size(); ++i) {
    result[0] += dataset[i][0] * dataset[i][1];
    result[1] += dataset[i][1];
  }

  result[1] = (int)(round((double)result[1] / (double)dataset.size(), -1));
  return result;
}
