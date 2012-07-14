#include <iostream>
#include <cmath>

class HitAndBlow
{
public:
  int hit;
  int blow;
  HitAndBlow(int _hit, int _blow) {
    this->hit = _hit;
    this->blow = _blow;
  };
  //  virtual ~HitAndBlow();
};

HitAndBlow* solve(int a1, int a2, int a3,int a4,
		 int b1,int b2,int b3,int b4) {

  int hit = 0, blow = 0;

  int ary_a[] = {a1, a2, a3, a4};
  int ary_b[] = {b1, b2, b3, b4};
  
  for (int i = 0; i < 4; ++i) {
    if (ary_a[i] == ary_b[i]) { ++hit; }
    
    for (int j = 0; j < 4; ++j) {
      if (i!=j && ary_a[i] == ary_b[j]) { ++blow; }
    }
  }
  
  //   std::cout << hit << std::endl;
  return new HitAndBlow(hit, blow);
}

int main()
{
  int a1, a2, a3, a4;
  int b1, b2, b3, b4;

  while (std::cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4) {
    HitAndBlow* result = solve(a1, a2, a3, a4, b1, b2, b3, b4);
    // HitAndBlow result = solve(a1, a2, a3, a4, b1, b2, b3, b4);
    std::cout << (*result).hit << " " << (*result).blow << std::endl;
    delete result;
  }
  return 0;
}
