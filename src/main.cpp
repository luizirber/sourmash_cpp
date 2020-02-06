#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
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

  auto ma_abunds = ma.abunds();
  cout << "ma abunds: ";
  copy(ma_abunds.begin(),
       ma_abunds.end(),
       ostream_iterator<HashIntoType>(cout, " "));
  cout << endl;

  cout << "in common (mh/mh): " << mh.count_common(mh) << endl;
  cout << "in common (mh/ma): " << mh.count_common(ma) << endl;

  vector<HashIntoType> hashes {1, 2, 3, 4, 5, 6};
  cout << "hashes: ";
  copy(hashes.begin(),
       hashes.end(),
       ostream_iterator<HashIntoType>(cout, " "));
  cout << endl;

  vector<HashIntoType> abunds {2, 2, 2, 2, 2, 2};
  cout << "abunds: ";
  copy(abunds.begin(),
       abunds.end(),
       ostream_iterator<HashIntoType>(cout, " "));
  cout << endl;

  ma.set_abundances(hashes, abunds);

  auto mins = ma.mins();
  cout << "ma mins: ";
  copy(mins.begin(),
       mins.end(),
       ostream_iterator<HashIntoType>(cout, " "));
  cout << endl;

  ma_abunds = ma.abunds();
  cout << "ma abunds: ";
  copy(ma_abunds.begin(),
       ma_abunds.end(),
       ostream_iterator<HashIntoType>(cout, " "));
  cout << endl;

  return 0;
}
