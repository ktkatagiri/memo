#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<string, int> > vector_pair;

class Aoj0041
 {
 private:

 public:
   int run() {
     vector<int> vals(4);
     string tmp;
     vector<pair<string, int> > m;

     while(true) {
       cin >> vals[0] >> vals[1] >> vals[2] >> vals[3];
       if(vals[0] == 0 || vals[1] == 0 || vals[2] == 0 || vals[3] == 0) break; // if 0 all
       m.clear();

       for(int i=0; i < 4; i++)
	 {
	   tmp = "";
	   tmp += vals[i] + '0';
	   m.push_back(make_pair(tmp, vals[i]));
	 }
       // output element
       cout << solve(m) << endl;
     }

     return 0;
   };
   
   string solve(vector_pair m) {
    if (m.size() == 1) {
      if (m.begin()->second == 10) { return m.begin()->first; }
      else { return "0"; }
    }
    
    for(vector_pair::iterator it = m.begin(); it != m.end(); it++) {
      for (vector_pair::iterator jt = m.begin(); jt != m.end(); jt++) {
	if (it == jt) continue;
	vector_pair tmp1, tmp2;
	string res;
	
	// 
	for (vector_pair::iterator kt = m.begin(); kt != m.end(); kt++) {
	  if (kt == it|| kt == jt) continue;
	  tmp1.push_back(*kt);
	}

	string exp;
	tmp2 = tmp1;
	exp = string("(") +it->first + " + " + jt->first + ")";
	tmp2.push_back(make_pair(exp, it->second + jt->second));
	res = solve(tmp2);
	if(res != "0") return res;
	
	tmp2 = tmp1;
	exp = string("(") +it->first + " - " + jt->first + ")";
	tmp2.push_back(make_pair(exp, it->second - jt->second));
	res = solve(tmp2);
	if(res != "0") return res;

	tmp2 = tmp1;
	exp = string("(") +it->first + " * " + jt->first + ")";
	tmp2.push_back(make_pair(exp, it->second * jt->second));
	res = solve(tmp2);
	if(res != "0") return res;
      }
    }
    return "0";
   };

   Aoj0041(){
   };
};

int main(int argc, char *argv[])
{
  
  (*(new Aoj0041())).run();

  return 0;
}
