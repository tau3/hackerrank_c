#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string special_characters = "!@#$%^&*()-+";

int count_missing(string pass, int n, int (*pred)(int)) {
  int res = 1;
  for (int i = 0; i < n; i++) {
    if ((*pred)(pass[i])) {
      res = 0;
      break;
    }
  }
  return res;
}

int is_special(int c) { return special_characters.find(c) != string::npos; }

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string password;
  getline(cin, password);

  int missing_count = count_missing(password, n, isdigit) +
                      count_missing(password, n, islower) +
                      count_missing(password, n, isupper) +
                      count_missing(password, n, is_special);

  int res = max(missing_count, 6-n);

  printf("%d\n", res);

  return 0;
}
