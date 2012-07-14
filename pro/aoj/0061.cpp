#include <iostream>
#include <vector>
#include <map>

// class Set
// {
// public:
//   int front;
//   std::string end;
//   Set(int f, std::string e){
//     this->front = f;
//     this->end = e;
//   }
// };

void xorSwap (int& x, int& y) {
  if (x != y) { x ^= y; y ^= x; x ^= y; }
}
int solve(const int x, std::map<int, std::vector<int> >& dataset);

int main(int argc, char *argv[])
{
  int tmpx, tmpy;
  std::map<int, std::vector<int> > dataset;
  
  while (~scanf("%d,%d",&tmpx, &tmpy)) {
    if(tmpx==0&&tmpy==0) { break; }
    // std::cout << tmpx <<  " " << tmpy << std::endl;
    dataset[tmpy].push_back(tmpx);
    //}
  }
  
  while (~scanf("%d", &tmpx)) {
    std::cout << solve(tmpx, dataset) << std::endl;
  }

  return 0;
}
int solve(const int x,
	  std::map<int, std::vector<int> >& dataset)
{
  int result = 1;

  std::map<int, std::vector<int> >::reverse_iterator it = dataset.rbegin();

  for(; it != dataset.rend(); ++it) {
    bool isIncludeF = false;

    // each vecotr element
    for (int j = 0; j < (*it).second.size(); ++j) {
      //      std::cout << (*it).first << " " << (*it).second[j] << std::endl;
      
      if (((*it).second)[j] == x) {
      	isIncludeF = true;
      	break;
      }
    }
    if (isIncludeF) { break; }
    ++result;
  }

  return result;
}

