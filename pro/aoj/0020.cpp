#include <iostream>
#include <string>

// Write a program which replace all the lower-case letters of a given text with the corresponding captital letters. 

int main()
{
  std::string str;
  while ( getline(std::cin, str) ) {
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
	if ( *it >= 'a' && *it <= 'z' ) {
	  *it = *it + ('A'-'a');
	}
    }
    
    std::cout << str << std::endl;
  }
  return 0;
}
