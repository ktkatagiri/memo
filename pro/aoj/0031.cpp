#include <iostream>

using namespace std;

int main(){
  int weight;
  
  while(std::cin >> weight){
    int time = 1;
    while (weight != 0) {
      if (weight % 2 == 1) {
	std::cout << time;
	if (weight != 1) { std::cout << " "; }
      }
      weight /= 2;
      time *= 2;
    }
    std::cout << std::endl;
  }
}
