#include <iostream>

namespace s=std;

int main() {
  enum color {red, green=3, blue} c;

  c = green;
  s::cout << c << s::endl;

  return 0;
}
