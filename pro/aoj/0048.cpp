#include <iostream>
#include <string>

std::string solve(const double& weight);

int main(int argc, char *argv[])
{
  double temp;
  // input
  while(std::cin >> temp) {
    std::cout << solve(temp) << std::endl;    
  }
  return 0;
}

std::string solve(const double& weight) {
  return (weight <= 48.00) ? "light fly" :
    (weight <= 51.00) ? "fly" :
    (weight <= 54.00) ? "bantam" :
    (weight <= 57.00) ? "feather" :
    (weight <= 60.00) ? "light" :
    (weight <= 64) ? "light welter" :
    (weight <= 69) ? "welter" :
    (weight <= 75) ? "light middle" :
    (weight <= 81) ? "middle" :
    (weight <= 91) ? "light heavy" : "heavy";
}
