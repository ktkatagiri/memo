#include <iostream>

bool solve(double xA,double yA,double xB,double yB,
	   double xC,double yC,double xD,double yD);
int main(int argc, char *argv[])
{
  double xA, yA, xB, yB, xC, yC, xD, yD;

  while (std::cin >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD
	 && !(std::cin.eof())) {
    std::cout << (solve(xA, yA, xB, yB, xC, yC, xD, yD) ? "YES" : "NO") << std::endl;
  }
  return 0;
}
bool solve(double xA,double yA,double xB,double yB,
	   double xC,double yC,double xD,double yD)
{
  return ((xB-xA)*(xD-xC)+(yB-yA)*(yD-yC) == 0); 
}

