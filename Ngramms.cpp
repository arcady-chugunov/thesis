#include "Ngramms.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
using std::ofstream;
using std::string;
using std::endl;



void NgramCollection::Output(ofstream& f) {
  for (size_t i = 0; i<ngrams_.size(); ++i) {
    if (ngrams_[i].count_ > 0) 
      f << ngrams_[i].ngramm << " " << ngrams_[i].count_ << endl;
  }
}

string NgramCollection::CleanWord(const string& word) {
  string cleaned_word = word;
  RemoveJo(&cleaned_word);
  RemoveHyphen(&cleaned_word);
  return cleaned_word;
}

void NgramCollection::RemoveJo( string* word) {
  size_t current_position = 0;
  size_t found_position;
  while ((found_position = word->find("¸", current_position)) != string::npos) {
    word->replace(found_position, 1, "å");
    current_position += found_position + 1;
  }
}

void NgramCollection::RemoveHyphen( string* word) {
  size_t current_position = 0;
  size_t found_position;
  while ((found_position = word->find("-", current_position)) != string::npos) {
    word->replace(found_position, 1, "");
    current_position += found_position;
  }
}

void NgramCollection::ProcessWord(const string& word_) {
  string word = CleanWord(word_);
  string current_ngramm;
  if (!last_read_symbols.empty()) current_ngramm += last_read_symbols;
  string::iterator current_symbol = word.begin();
  while (current_ngramm.size() < N_ - 1 && current_symbol < word.end()) {
    current_ngramm += *current_symbol;
    ++current_symbol;
  }
  for (; current_symbol < word.end(); ++current_symbol) {
    current_ngramm += *current_symbol;
    ++ngrams_[GetNGrammIndex(current_ngramm)].count_;
    ngrams_[GetNGrammIndex(current_ngramm)].ngramm = current_ngramm; //FIX !!
    current_ngramm.erase(current_ngramm.begin());
  }
  current_ngramm += " ";
  ++ngrams_[GetNGrammIndex(current_ngramm)].count_;
  ngrams_[GetNGrammIndex(current_ngramm)].ngramm = current_ngramm; //FIX !!
  current_ngramm.erase(current_ngramm.begin());
  last_read_symbols = current_ngramm;
}

size_t NgramCollection::GetNGrammIndex(const string& ngramm) {
  size_t index = 0;
  long long current_power = (long long)(pow(alphabet_size, (N_-1) * 1.0));
  for (string::const_iterator current_symbol = ngramm.begin(); current_symbol < ngramm.end(); ++current_symbol) {
    if (*current_symbol == ' ') {
      index += current_power * (alphabet_size - 1);
    } else {
      index += current_power * (*current_symbol - alphabet_first);
    }
    current_power /= alphabet_size;
  }
  return index;
}
