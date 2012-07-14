#include <iostream>
#include <map>
#include <vector>

int main(int argc, char *argv[])
{
  std::vector< std::vector<char> > bellTable;

  char chr = 'a'; // init
  for (int i = 0; i < 5; ++i) {
    std::vector<char> colum;
    for (int j = 0; j < 5; ++j) {
      colum.push_back(chr);
      ++chr;
    }
    bellTable.push_back(colum);
  }
  
  std::vector<char> colum;
  colum.push_back('z');
  colum.push_back('.');
  colum.push_back('?');
  colum.push_back('!');
  colum.push_back(' ');
  bellTable.push_back(colum);

  // for (char i = 0; i < bellTable.size(); ++i) {
  //   for (char j = 0; j < bellTable[i].size(); ++j) {
  //     std::cout << bellTable[i][j];
  //   }
  //   std::cout << std::endl;
  // }

  std::string message;

  while (std::cin >> message) {
    bool regular = true;
    // std::cout << message.size() << std::endl;
    if (message.size() % 2 != 0) {
      regular = false;
    }

    std::string retString = "";
    for (int i = 0; i < message.size() and regular; i += 2) {
      int a, b;
      a = message[i];
      b = message[i+1];

      if (a >= '1' and a <= '6' and
	  b >= '1' and b <= '5') {
	char x = a-'0';
	char y = b-'0';
	retString += bellTable[x-1][y-1];
      } else {
	regular = false;
      }
    }
    
    if (regular) {
      std::cout << retString << std::endl;
    } else {
      std::cout << "NA" << std::endl;
    }
  }
  return 0;
}
