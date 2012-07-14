#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

#define X_LEN 12
#define Y_LEN 12

std::vector< std::pair<int, int> > Neighbourhoods(4);

void init() {
  Neighbourhoods[0] = std::pair<int, int>(-1, 0);
  Neighbourhoods[1] = std::pair<int, int>(0, 1);
  Neighbourhoods[2] = std::pair<int, int>(1, 0);
  Neighbourhoods[3] = std::pair<int, int>(0, -1);
}

int solve_bfs(int figure[12][12]);

int main(int argc, char *argv[])
{
  init();

  int figure[12][12];
  std::string str;
  
  while (getline(std::cin ,str)) {
    if(str.empty()) continue;
    for (int y = 0; y < Y_LEN; ++y) {
      for(int x = 0; x < X_LEN; ++x) {
	figure[y][x] = (int)(str[x] - '0');
      }
      getline(std::cin, str);
    }

    int result = solve_bfs(figure);
    std::cout << result << std::endl;
  }

  return 0;
}

int solve_bfs(int figure[12][12])
{
  int result = 0;
  for (int i = 0; i < X_LEN; ++i) {
    for (int j = 0; j < Y_LEN; ++j) {
      if(figure[i][j]==0) continue;

      ++result;
      std::queue< std::pair<int, int> > que;
      que.push(std::pair<int, int>(i, j));

      while(!que.empty()) {
	int y = que.front().first;
	int x = que.front().second;
	que.pop();
	
	figure[y][x] = 0;
	
	for (std::vector<std::pair<int, int> >::iterator it = Neighbourhoods.begin();
	     it != Neighbourhoods.end();
	     ++it) {
	  int dy = y + it->first;
	  int dx = x + it->second;
	  if(dx < 0 || dx >=12 || dy < 0 || dy >= 12) continue;
	  if(figure[dy][dx] == 0) continue;
	  que.push( std::pair<int,int>(dy,dx));
	}
      }

    }
  }
  // std::cout << result << std::endl;
  return result;
}

