#ifndef TEXTFEATURES_H
#define TEXTFEATURES_H
#include "MorphologyHolder.h"
//#include "libs/AgramtabLib/RusGramTab.h"

#include <cmath>
#include <map>
#include "Ngramms.h"




class TextFeatures {
  static const int first_sentence_words_considered = 2;
  static const int word_length_limit = 20 ; 
  private:
    CMorphologyHolder* holder_;
  public:
    vector<int> POS_statistic_;
    vector<vector<int> > POS_position_statistic_;
    long long symbols_num_;
    int words_num_;
    int sentences_num_;
    NgramCollection bigramms_;
    NgramCollection trigramms_;
    vector<int> words_lengths_;
    map <int,int> words_frequencies_;
    vector <string> lemms_id_;
    TextFeatures(CMorphologyHolder* holder): 
        holder_(holder), 
        POS_statistic_(rPartOfSpeechCount, 0), 
        symbols_num_(0),
        words_num_(0),
        sentences_num_(0),
        bigramms_(2),
        trigramms_(3),
        words_lengths_(word_length_limit + 1, 0),
        words_frequencies_(){
      POS_position_statistic_.resize(first_sentence_words_considered, vector<int>(rPartOfSpeechCount, 0));
     }
                                                   
    bool BuildDictionary(const string &fout_name);
    int GetLemmID(string lemm);
    void ProcessGraphanInfo(const CGraphmatFile* Gr, int LineNo );
    void ProcessMorphInfo(const CFormInfo& info, int word_position);
    void Output();
};
#endif
