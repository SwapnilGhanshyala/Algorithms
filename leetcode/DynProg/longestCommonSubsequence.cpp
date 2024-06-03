#include <iostream>
#include <vector>
using namespace std;
int lcs(string s, string t, int i, vector<int> &r) {
  char a = s[i];
  int len = t.size();
  vector<int> row(len, 0);
  for (int j = 0; j < len; j++)
    if (a == t[j])
      row[j] = 1 + r[j - 1];
    else {
      row[j] = max(r[j], row[j - 1]);
    }
  if (i == s.size() - 1)
    return row[len - 1];
  return lcs(s, t, i + 1, row);
}
int main() {
  string s = "coaching";
  string t = "coding";
  vector<int> r(t.size(), 0);
  cout << lcs(s, t, 0, r) << endl;
  return 0;
}