#include <iostream>
#include "kmer_min_hash.hh"

using namespace std;

int main() {
  KmerMinHash mh(2, 2, false, 42, 0);
  KmerMinAbundance ma(2, 2, false, 42, 0);

  mh.add_sequence("AAGTTGCA");
  ma.add_sequence("AAAAAAAA");
  cout << "Sequence added" << endl;

  cout << "MinHash size: " << mh.size() << endl;
  cout << "MinAbundance size: " << ma.size() << endl;

  cout << "in common (mh/mh): " << mh.count_common(mh) << endl;
  cout << "in common (mh/ma): " << mh.count_common(ma) << endl;

  return 0;
}
