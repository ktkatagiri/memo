#include <iostream>
#include <vector>

bool solve(const std::vector<int>& vec);
int main(int argc, char *argv[])
{
  std::vector<int> cards(3);

  while (std::cin >> cards[0] >> cards[1] >> cards[2]
	 && !(std::cin.eof())) {
    std::cout << (solve(cards) ? "YES" : "NO") << std::endl;
  }
  return 0;
}
bool solve(const std::vector<int>& vec)
{
  int count = 0;
  for(int i = 1; i < 11; i++){
    if(vec[0] != i &&
       vec[1] != i &&
       vec[2] != i &&
       vec[0] + vec[1] + i <= 20) {
      ++count;
    }
  }

  return (count>3);
}

