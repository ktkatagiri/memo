#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char *argv[])
{
  int n;
  while (std::cin >> n) {
    
    std::vector<bool> vec(n+1);
    for (int i = 0; i <= n; ++i) { vec[i] = true; }
    vec[0] = false;
    vec[1] = false; // not 1 is sosuu
    
    int n_sqrt = (int)(sqrt(n));
    
    // from 2
    for (int i = 2; i < n_sqrt+1; ++i) {
      // if number is false then
      if (!vec[i]) { continue; }
      
      // i * 2 : to self number avoid
      for (int j = i * 2; j <= n; j += i) {
	if (vec[j]) {
	  vec[j] = false;
	}
      }
    }
    
    int count = 0;
    for (int i = 0; i <= n; ++i) {
      if (vec[i])
      {
	++count;
	// std::cout << i << " ";
      }
    }
    // std::cout << std::endl;
    std::cout << count << std::endl;
  }
  
  return 0;
}
