#include <iostream>

using namespace std;

int main() {
  int n, p;
  cin >> n;
  cin >> p;
  int res = min(p / 2, n / 2 - p / 2);
  cout << res << endl;
  return 0;
}
