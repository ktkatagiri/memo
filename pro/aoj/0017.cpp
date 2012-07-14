#include <iostream>
#include <cstdio>
// #include <cmath>
#include <string>
#include <vector>

bool solve(std::string str, std::vector<std::string> words) {
  for (std::vector <std::string > ::iterator it = words.begin();
       it != words.end(); ++it) {

    if(str.find(*it) != std::string::npos) {
      //std::cout << *it << std::endl;
      return true;
    }
  }
  return false;
}

std::string slideString(std::string str, int num) {
  // std::cout << num << std::endl;
  for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
    // std::cout << *it << std::endl;
    if ((*it) >= 'a' && (*it) <= 'z') {
      (*it) += num;
      // std::cout << *it << std::endl;
      if((*it) > 'z'){
	(*it) = ((*it) - 'z') + 'a';
      }
    }
  }
  return str;
}

int main(int argc, char *argv[])
{
  std::vector<std::string> words;
  words.push_back("the");
  words.push_back("this");
  words.push_back("that");
  std::string input_str;
  while (std::getline(std::cin, input_str)) {

    for (int i = 0; i <= 26; ++i) {
      // std::cout << input_str << std::endl;
      input_str = slideString(input_str, i);
      // std::cout << input_str << std::endl;
      
      if (solve(input_str, words)) {
	std::cout << input_str << std::endl;
	break;
      }
    }
  }
  
  return 0;
}

