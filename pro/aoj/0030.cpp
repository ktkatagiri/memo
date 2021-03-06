#include <iostream>

class Aoj0030
{
private:
  int _sol; // Sum of Integer
  int _resCount; // Counter Member
public:
  // main
  int run() {
    int n,s;

    while(std::cin >> n >> s) {
      if (n==0 && s==0) {
	break;
      }
      // set need member vals
      _resCount = 0;
      _sol = s;

      // solve
      solve(n, s);
    }
    return 0;
  }

  // Deep First Search
  void dfs(int begin, int depth, int sum) {
    // if depth is 0 then end; and sum equal _sol return _resCount
    if (depth == 0) {
      if (_sol == sum) { _resCount++; }
    } else {
      for (int i = begin + 1; i < 10; ++i) {
	dfs(i, depth - 1, sum + i);
      }
    }
  }
  void solve(int n, int s) {
    // 0->9 rotate
    for (int i = 0; i < 10; ++i){
      dfs(i, n - 1, i);
    }
    std::cout << _resCount << std::endl;
  }
  Aoj0030(){
    // set member
    _resCount = 0;
  };
};

int main()
{
  (*(new Aoj0030)).run();
  return 0;
}

