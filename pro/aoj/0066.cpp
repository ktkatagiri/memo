#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cmath>

struct CountTable
{
  int o;
  int x;
  int s;
};
char solve(const std::string& str);

int main(int argc, char *argv[])
{
  int result;
  std::string str;

  while(std::cin >> str){
    std::cout << solve(str) << std::endl;
  }
  return 0;
}
char solve(const std::string& str) {
  // std::cout << str << std::endl;

  for (int i = 0; i < 3; ++i) {
    int x;
    CountTable x_table = {0,0,0};
    CountTable y_table = {0,0,0};

    // diagonal
    if ((str[0]!='s' &&
	 (str[0]==str[4]&&str[4]==str[8])) ||
	(str[2]!='s' &&
	 (str[2]==str[4]&&str[4]==str[6])))
      {
	return str[4];
      }
    
    for (int j = 0; j < 3; ++j) {
      // std::cout << str[i+ j*3] << std::endl;
      if (str[i*3 + j] == 'x') ++(x_table.x);
      if (str[i*3 + j] == 'o') ++(x_table.o);
      if (str[i*3 + j] == 's') ++(x_table.s);

      if (str[i + j*3] == 'x') ++(y_table.x);
      if (str[i + j*3] == 'o') ++(y_table.o);
      if (str[i + j*3] == 's') ++(y_table.s);
    }
    // std::cout << x_table.x << std::endl;
    if (x_table.x==3 || y_table.x==3) return 'x';
    if (x_table.o==3 || y_table.o==3) return 'o';
  }

  return 'd';
}

