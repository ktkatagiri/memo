class Set
{
public:
  int front;
  std::string end;
  Set(int f, std::string e){
    this->front = f;
    this->end = e;
  }
};


// 誤差丸め四捨五入
double round(double src, int n)
{
  double dst;
  
  dst = src * pow(10, -n - 1);
  dst = (double)(int)(dst + 0.5);
  
  return dst * pow(10, n + 1);
}

// 文字列分割
std::vector< std::string > split(const std::string &str, char delim) {
  std::vector< std::string> res;
  size_t current = 0, found;

  while((found = str.find_first_of(delim, current)) != std::string::npos){
    res.push_back(std::string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(std::string(str, current, str.size() - current));
  return res;
}

// under 50000
std::vector<int> makePrimes(int n) { // param n 以下の素数列を生成し，vector<int>で返す
  std::vector<bool> vec(n+1);
  std::vector<int> result;

  for (int i = 0; i <= vec.size(); ++i) { vec[i] = true; }
  vec[0] = false;
  vec[1] = false;

  int n_sqrt = (int)(sqrt(n));
  
  // from 2
  for (int i = 2; i < n_sqrt+1; ++i) {
    // if number is false then
    if (!vec[i]) { continue; }
    
    // i * 2 : to self number avoid
    for (int j = i * 2; j <= n; j += i) {
      if (vec[j]) {
	vec[j] = false;
      }
    }
  }
  
  for (int i = 0,
	 i < n; ++i) {
    if (vec[i])
      {
	result.push_back(i);
      }
  }

  return result;
}


// under 50000
std::vector<bool> makePrimeTable(int n) { // param n 以下の素数列を生成し，vector<int>で返す
  std::vector<bool> vec(n+1);

  for (int i = 0; i <= vec.size(); ++i) { vec[i] = true; }
  vec[0] = false;
  vec[1] = false;

  int n_sqrt = (int)(sqrt(n));
  
  // from 2
  for (int i = 2; i < n_sqrt+1; ++i) {
    // if number is false then
    if (!vec[i]) { continue; }
    
    // i * 2 : to self number avoid
    for (int j = i * 2; j <= n; j += i) {
      if (vec[j]) {
	vec[j] = false;
      }
    }
  }
  return vec;
}
