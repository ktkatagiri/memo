#include <iostream>

// vector, cross product
bool insidep(double x0, double y0,
	     double x1, double y1,
	     double xp, double yp) {
  return ((x1 - x0) * (yp - y0) - (xp - x0) * (y1 - y0) >= 0) ?
    true : false;
}

int main(int argc, char *argv[])
{
  double x1, y1, x2, y2, x3, y3, xp, yp;
  
  while(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp) {
    if ((insidep(x1, y1, x2, y2, xp, yp) &&
	 insidep(x2, y2, x3, y3, xp, yp) &&
	 insidep(x3, y3, x1, y1, xp, yp)) ||
	(!insidep(x1, y1, x2, y2, xp, yp) &&
	 !insidep(x2, y2, x3, y3, xp, yp) &&
	 !insidep(x3, y3, x1, y1, xp, yp))) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}
