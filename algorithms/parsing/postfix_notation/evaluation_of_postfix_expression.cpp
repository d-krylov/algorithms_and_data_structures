#include <cctype>
#include <iostream>
#include <stack>

using namespace std;

int main() {

  stack<int> s;

  string in;
  getline(cin, in);

  bool state = false;
  int temp = 0;

  for (char &ch : in) {
    if (isdigit(ch)) {
      temp = temp * 10 + (ch - '0');
      state = true;
    } else if (ch == ' ') {
      if (state) {
        s.push(temp);
        temp = 0;
        state = false;
      }
    } else {
      int r = s.top();
      s.pop();
      int l = s.top();
      s.pop();

      switch (ch) {
      case '+': {
        s.push(l + r);
        break;
      }
      case '-': {
        s.push(l - r);
        break;
      }
      case '*': {
        s.push(l * r);
        break;
      }
      case '/': {
        s.push(l / r);
        break;
      }
      }
    }
  }
  cout << s.top() << "\n";
}
