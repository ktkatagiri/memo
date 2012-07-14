#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cmath>

// std::map<int,int> solve(const std::string& str);

int main(int argc, char *argv[])
{
  int number, day;
  std::map<int, std::set<int> > p, q;
  bool nextFalg = false;
  std::string str;

  while(getline(std::cin, str)){
    if (str.empty()){
      nextFalg = true;
      continue;
    }

    sscanf(str.c_str(),"%d,%d",&number, &day);
    
    if(!nextFalg) { p[number].insert(day+100); }
    else {
      if(p[number].size()>0){
	if(q[number].size() == 0) q[number] = p[number];
	q[number].insert(day);
      }
    }
  }

  for(std::map<int, std::set<int> >::iterator it = q.begin();
      it != q.end();
      it++){
    std::cout << it->first << " " << it->second.size() << std::endl;
  }
  return 0;
}

// std::map<int,int> solve(const std::string& str)
// {
//   return result;
// }

