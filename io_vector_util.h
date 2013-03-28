#include <vector>
#include <iostream>

using std::vector;
using std::ostream;

template<typename T>
ostream& operator << (ostream& ostr, const vector<T> &v) {
  for (size_t it = 0; it < v.size(); ++it) {
    ostr << v[it] << ' ';
  }
  return ostr;
}





