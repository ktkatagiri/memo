#include<iostream>
#include<set>
#include<queue>

using namespace std;

const int dx[] = {0, 1, 1, 0, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, 0};

set<pair<int, int> > S;

class State{
public:
  int y, x,cost;
  bool next(int d){
    if(cost == 0 )return false;
    cost--;
    y += dy[d];
    x += dx[d];
    pair<int, int> p = make_pair(y, x);
    if(S.find(p) == S.end()){
      // if(d==3) std::cout << x << ":"<< y;
      S.insert(p);
      return true;
    }
    return false;
  }
};

int main(){
  int t, n;
  while(cin >> t >> n){
    if(t == 0 && n == 0)break;
    S.clear();
    int sy, sx;
    for (int i = 0; i < n; ++i) {
      int ty, tx;
      cin >> tx >> ty;
      S.insert(make_pair(ty, tx));
    }

    cin >> sx >> sy;
    S.insert(make_pair(sy, sx));
    // cout << "2:" << S.size() << endl;
    queue<State> Q;
    std::cout << sx << sy;
    for(Q.push((State){sy, sx, t}); !Q.empty();Q.pop()){
      State now = Q.front();
      for(int i = 0; i < 6; ++i){
        State next = now;
        if(next.next(i)){
	  // std::cout << i;
          Q.push(next);
        }
      }
    }
    //cout << n << endl;
    cout << "ans:" << S.size() - n << endl;
  }
  return 0;
}
