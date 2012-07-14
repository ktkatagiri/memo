#include <iostream>
#include <complex>

// input: Input consists of several datasets. In the first line, you are given the number of datasets n. There will be n lines where each line correspondgs to each dataset. Each dataset consists of eight real numbers: 

// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)

// cross product : a×b = |a||b|sinθ
double cross(std::complex<double> a, std::complex<double> b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}

int is_parallel(std::complex<double> a1,
		std::complex<double> a2,
		std::complex<double> b1,
		std::complex<double> b2) {
  return EQ( cross(a1-a2, b1-b2), 0.0 );
}

// bool solve(double x1, double y1,
// 	   double x2, double y2,
// 	   double x3, double y3,
// 	   double x4, double y4) {
  
// }

int main()
{
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    double x1,y1,x2,y2,x3,y3,x4,y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    std::complex<double> a1(x1,y1), a2(x2,y2), b1(x3,y3), b2(x4,y4);
    std::cout << (is_parallel(a1,a2,b1,b2) ? "YES" : "NO") << std::endl;
  }
  
  return 0;
}
