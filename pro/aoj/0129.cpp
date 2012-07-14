#include <iostream>
#include <cmath>
#include <vector>

#define SQUARE(x) ((x)*(x))
#define EPS (1e-5)

// typedef complex<double> Point;
class Point
{
public:
  int x;
  int y;
  Point(){};
  Point(int _x, int _y) {
    x=_x;
    y=_y;
  };
};

class Circle
{
public:
  int x;
  int y;
  int r;
  Circle(){
  };
  Circle(int _x, int _y, int _r) {
    this->x = _x;
    this->y = _y;
    this->r = _r;
  }
};

bool isInCircle(Point p, Circle c) { // c内にpがあるか？
  double innerProduction = SQUARE(p.x + c.x) + SQUARE(p.y + c.y);
  return innerProduction < SQUARE(c.r) ? true : false;
}

bool isCrossCircleAndLine(Point a, Point b, Circle c) { // 円と線分が交わっているか？
  //ベクトル１： 円の中心からポイントAまで
  double vx1 = (c.x - a.x);
  double vy1 = (c.y - a.y);
  
  //ベクトル２：ポイントAからポイントBまで
  double vx2 = (a.x - b.x);
  double vy2 = (a.y - b.y);

  double n1 = vx1 * vx2 + vy1 * vy2;
  double n2 = vx2 * vx2 + vy2 * vy2;
  double n3 = vx1 * vx1 + vy1 * vy1;

  if(n1 < 0){
    return (SQUARE(a.x - c.x) + SQUARE(a.y - c.y) <= c.r*c.r) ? true : false;
  }
  else if(n1 > n2){
    return (SQUARE(b.x - c.x) + SQUARE(b.y - c.y) <= c.r*c.r) ? true : false;
  }
  else{
    if(n2 <= 0) return (n3 * n2 - n1 * n1 >= c.r * c.r * n2) ? true : false; 
    else return (n3 * n2 - n1 * n1 <= c.r * c.r * n2) ? true : false; 
  }
}

bool solve(Point a, Point b, Circle c) { // 危険ならtrue, 安全ならfalse 
  if (isInCircle(a, c) && isInCircle(b, c)) { return true; }

  return isCrossCircleAndLine(a, b, c) ? true : false;
}

int main(int argc, char *argv[])
{
  while (true) {
    int n;
    std::cin >> n;
    if (n==0) {break;}

    std::vector<Circle> circles(n);

    for (int i = 0; i < n; ++i) {
      std::cin >>  circles[i].x >> circles[i].y >> circles[i].r;
    }
    
    int m;
    std::cin >> m;
    std::vector<Point> vec_a(m), vec_b(m);
    bool dataset[m]; // safe(true) or unsafe(false)

    for (int i = 0; i < m; ++i) {
      std::cin >> vec_a[i].x >> vec_a[i].y >> vec_b[i].x >> vec_b[i].y;
      // all circle while
      for (int j = 0; j < circles.size(); ++j) {
	if(solve(vec_a[i], vec_b[i], circles[i])) {
	  dataset[i] = true;
	  break;
	}
      }
    }
    
    // 出力
    for (int i = 0; i < m; ++i) {
      std::cout << (dataset[i] ?  "Danger" : "Safe") << std::endl;
    }
  }

  return 0;
}
