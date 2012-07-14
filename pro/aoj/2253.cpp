#include <iostream>
#include <set>
#include <queue>

// using namespace std;

const int dx[] = {0, 1, 1, 0, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, 0};

std::set<std::pair<int, int> > PointSet;

class Position{
public:
  int x, y, remain_step;

  bool next(int d) {
    if(remain_step == 0) { return false; }

    remain_step--;

    y += dy[d];
    x += dx[d];
    std::pair<int, int> p = std::make_pair(y, x);
    if(PointSet.find(p) == PointSet.end()){
      // if(d==3) std::cout << x << ":"<< y;
      PointSet.insert(p);
      return true;
    }
    return false;
  }
  Position(int _y, int _x, int _remain_step) {
    y = _y; x = _x; remain_step = _remain_step;
  }
};

class Aoj2253
{
public:
  void run() {
    int t,n;

    while(std::cin >> t >> n) {
      if(t == 0 && n == 0) { break; }
      PointSet.clear();
      int start_x, start_y;
      for (int i = 0; i < n; ++i) {
	int tx,ty;
	std::cin >> tx >> ty;
	PointSet.insert(std::make_pair(ty, tx));
      }

      std::cin >> start_x >> start_y;
      PointSet.insert(std::make_pair(start_y, start_x));

      // TO BFS
      std::queue<Position> qu;
      // std::cout << start_x << start_y;
      for(qu.push(*(new Position(start_y, start_x, t)));
	  !qu.empty(); qu.pop()) {
	Position current_position = qu.front();
	for (int i = 0; i < 6; ++i) {
	  Position next_position = current_position;
	  if (next_position.next(i)){
	    qu.push(next_position);
	  }
	}
      }
      //  std::cout << n << std::endl;
      std::cout << PointSet.size() - n << std::endl;
    }
  }
  Aoj2253(){
  }
};

int main()
{
  (*(new Aoj2253)).run();
  return 0;
}

