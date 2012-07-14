#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Set
{
public:
  int front;
  std::string end;
  Set(int f, std::string e){
    this->front = f;
    this->end = e;
  }
};

void solve(const std::vector<Set>& vec);

int main(int argc, char *argv[])
{
  int x;
  char y[10];
  std::vector<Set> vec;
  while(~scanf("%d,%s\n", &x, y)) {
    std::string str(y);
    Set set(x, str);
    vec.push_back(set);
  }

  solve(vec);
  return 0;
}

void solve(const std::vector<Set>& vec) {
  std::map< std::string , int> table;
  table.insert(std::pair< std::string, int>("A", 0));
  table.insert(std::pair< std::string, int>("B", 0));
  table.insert(std::pair< std::string, int>("O", 0));
  table.insert(std::pair< std::string, int>("AB", 0));

  std::map< std::string , int >::iterator it;
  for (int i = 0; i < vec.size(); ++i) {
    table[vec[i].end] += 1;
  }

  std::cout << table["A"] << std::endl;  
  std::cout << table["B"] << std::endl;  
  std::cout << table["AB"] << std::endl;  
  std::cout << table["O"] << std::endl;  
}
