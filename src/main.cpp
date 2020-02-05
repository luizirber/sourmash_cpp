#include <iostream>
#include "sourmash.hpp"

using namespace std;
using namespace sourmash;

int main() {
  MinHash mh(2, 2, false, false, false, 42, 0);
  MinAbundance ma(2, 2, false, false, false, 42, 0);

  mh.add_sequence("AAGTTGCA");
  cout << "mh: Sequence added " << "AAGTTGCA" << endl;
  cout << "MinHash size: " << mh.size() << endl;

  ma.add_sequence("AAAAAAAA");
  cout << "ma: Sequence added " << "AAAAAAAA" << endl;
  cout << "MinAbundance size: " << ma.size() << endl;

  cout << "in common (mh/mh): " << mh.count_common(mh) << endl;
  cout << "in common (mh/ma): " << mh.count_common(ma) << endl;

  return 0;
}
