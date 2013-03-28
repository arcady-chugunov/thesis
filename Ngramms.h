#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using std::string;
using std::vector;
using std::ofstream;

struct NGramm {
  size_t index_;
  long long count_;
  string ngramm; //FIX
  NGramm() {}
  NGramm(size_t index): index_(index), count_(0), ngramm() {}
};

class NgramCollection {
private:
  string last_read_symbols;
public:
  static const int alphabet_first = 'à';
  static const int alphabet_size = 33;
  int N_;
  vector<NGramm> ngrams_;
  size_t GetNGrammIndex(const string& ngramm);
  NgramCollection(int N): last_read_symbols(" "), N_(N) {
    ngrams_.resize(size_t(pow(alphabet_size, N_ * 1.0)));
    for (size_t i = 0; i < ngrams_.size(); ++i) {
      ngrams_[i] = NGramm(i);
    }
  }
  void ProcessWord(const string& word);
  void Output(ofstream& f); //FIX
  string CleanWord(const string& word);
  void RemoveHyphen( string* word);
  void RemoveJo( string* word);
};
