#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>

template <class T>
inline void swap(T& a, T& b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

class Set
{
public:
  char front;
  char end;
  Set(char f, char e){
    this->front = f;
    this->end = e;
  }
};

char solve(const std::vector<Set>& vec);

int main(int argc, char *argv[])
{
  char x,y;
  std::vector<Set> vec;
  // input
  while(~scanf("%c,%c\n", &x, &y)) {
    Set set(x, y);
    //    std::cout << x << y << std::endl;
    vec.push_back(set);
  }
  
  std::cout << solve(vec) << std::endl;
  return 0;
}

char solve(const std::vector<Set>& vec) {
  std::map<char, bool> table;
  table.insert(std::map<char, bool>::value_type('A', true));
  table.insert(std::map<char, bool>::value_type('B', false));
  table.insert(std::map<char, bool>::value_type('C', false));

  for (int i = 0; i < vec.size(); ++i) {
    // std::cout << vec[i].front << vec[i].end << std::endl;
    swap(table[vec[i].front], table[vec[i].end]);
  }

  char result;
  std::map<char, bool>::iterator it = table.begin();
  while (it != table.end()) {
    if((*it).second) {
      result = (*it).first;
      break;
    }
    ++it;
  }
  return result;
}
