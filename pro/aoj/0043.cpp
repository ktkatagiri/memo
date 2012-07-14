#include <iostream>
#include <sstream>
#include <vector>
// #include <algorithm>
// #include <stack>

bool dfs(const std::vector<int>& pazzle);
bool includeVec(const std::vector<int>& vec, int n);

// 頭があるか？
std::vector<int> decisionHead(std::vector<int> pazzle) {
  std::vector<int> result;

  for (int i = 0; i < pazzle.size(); ++i) {    
    if (!includeVec(result, pazzle[i])) {
      for (int j = 0; j < pazzle.size(); ++j) {
	if(i != j && pazzle[i] == pazzle[j]) {
	  result.push_back(pazzle[i]);
	  break;
	}
      }
    }
  }
  return result;
}

bool includeVec(const std::vector<int>& vec, int n) {
  for (int i = 0; i < vec.size(); ++i) {
    if(vec[i] == n) { return true; }
  }
  return false;
}

// 順子を一つ覗いてdfsに渡す
bool shuntsuGet(const std::vector<int>& pazzle) {
  std::vector<int> vec; // 順子も一番上になりうるハイを集める

  for (int i = 0; i < pazzle.size(); ++i) {
    int count = 0;
    int key = pazzle[i];
    if(!includeVec(vec, pazzle[i])) {
      for (int j = 0; j < pazzle.size(); ++j) {
	if(pazzle[j] == key) {
	  ++count;
	  ++key;
	}
	if (count == 3) {
	  vec.push_back(pazzle[i]); break;
	}
      }
    }
  }

  std::vector<int> resultVec;
  // 全ての順子をつくれるハイの種類のパターンに対応
  for (int i = 0; i < vec.size(); ++i) {
    int count = 0;
    int key = vec[i];
    // pazzleの順番が昇順でないと機能しない
    for (int j = 0; j < pazzle.size(); ++j) {
      if (key != pazzle[j] || count >= 3) {
	resultVec.push_back(pazzle[j]);
      } else {
	++count;
	++key;
      }
    }

    if (dfs(resultVec)) {
      return true;
    }
    resultVec.clear();
  }

  return false;
}

// 刻子を一つ覗いてdfsに渡す
bool kotsuGet(const std::vector<int>& pazzle) {
  std::vector<int> vec; // 刻子をつくれるハイの種類を集める 
  std::vector<int> resultVec;

  for (int i = 0; i < pazzle.size(); ++i) {
    int count = 0;
    if(!includeVec(vec, pazzle[i])) {
      for (int j = 0; j < pazzle.size(); ++j) {
	if(pazzle[j] == pazzle[i]) {
	  ++count;
	}
	if (count == 3) {
	  vec.push_back(pazzle[i]); break;
	}
      }
    }
  }

  // 全ての刻子をつくれるハイの種類のパターンに対応
  for (int i = 0; i < vec.size(); ++i) {
    int count = 0;
    for (int j = 0; j < pazzle.size(); ++j) {
      if (vec[i] != pazzle[j] || count >= 3) {
	resultVec.push_back(pazzle[j]);
      } else {
	++count;
      }
    }
    if (dfs(resultVec)) {
      return true;
    }
    resultVec.clear();
  }

  return false;
}

// 深さ優先探索
bool dfs(const std::vector<int>& pazzle) { // 参照渡し
  if (pazzle.size() == 0) { return true; }
  if (shuntsuGet(pazzle)) { return true; }
  if (kotsuGet(pazzle)) { return true; }

  return false;
}

// 頭２つを覗いた肺を返す
std::vector<int> removeHead(const std::vector<int>& pazzle,
	       int head_num) {
  std::vector<int> result;
  int count = 0;
  for (int i = 0; i < pazzle.size(); ++i) {
    if(head_num != pazzle[i] || count >= 2) {
      result.push_back(pazzle[i]);
    } else {
      ++count;
    }
  }
  return result;
}

bool solve2(std::vector<int > pazzle){
    std::sort(pazzle.begin(), pazzle.end()); // 昇順ソート

    // 不正なハイのチェック
    for (int i = 0; i < pazzle.size(); ++i) {
      int count = 1;
      for (int j = 0; j < pazzle.size(); ++j) {
	if(i != j && pazzle[i] == pazzle[j]) {
	  ++count;
	  if (count > 4) {
	    // std::cout << "wrong" << std::endl;
	    return false;
	  }
	}
      }
    }


    std::vector<int> heads = decisionHead(pazzle); // 頭になりうる牌を得る

    for (int i = 0; i < heads.size(); ++i) {

      std::vector<int> handHai = removeHead(pazzle, heads[i]); // 頭2つ除く

      if (dfs(handHai)) { return true; }
    }
    return false;
}

std::vector<int> solve(std::vector<int> pazzle) {
  std::vector<int> result;

  for (int i = 1; i <= 9; ++i) {
    pazzle.push_back(i);
    if(solve2(pazzle)) {
      result.push_back(i);
    }
    pazzle.pop_back();
  }
  return result;
}

// vectorを受け取り要素を並べ文字列で返す
std::string joinVector(std::vector<int> vec) {
  std::string result;
  std::ostringstream os; // 書き込み
  
  for (int i = 0; i < vec.size(); ++i) {
    os << vec[i];
    if (i + 1 < vec.size()) { os << " "; }; // 先読み
  }
  result = os.str();
  return result;
}

int main(int argc, char *argv[])
{
  std::vector<int> pazzle;
  std::vector<int> result;
  std::string str;

  // 本体
  while(std::cin >> str) {
    for (int i = 0; i < str.size(); ++i) {
      pazzle.push_back((int)(str[i] - '0'));
    }
    
    result = solve(pazzle);

    std::cout << ((result.size() == 0) ? "0" : joinVector(result)) << std::endl;

    pazzle.clear();
  }
  return 0;
}
