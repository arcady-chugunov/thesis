#pragma once
#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;

class Lemm_collection
{
public:
  Lemm_collection();
  Lemm_collection(vector<string> *doc_str_in);
  
  map<int, map<int, int> > LDC_map;
  vector<string> *doc_str;
  
  void Init(vector< vector<int> > &doc_collection, const string &fout_name);
  void Init_from_file(vector<vector<int> > &doc_collection, const string &fin_name);

  int Compute_IF(int lemm_id, const vector<int> &doc);
  int Compute_DF(int lemm_id);
  int Compute_CLF(int lemm_id, int freq);
  double Compute_ICLF(int lemm_id, int freq);
  
  double Compute_IFQ(const vector<int> &frag, const vector<int> &query, const vector<int> &doc);
  double Compute_IQF(const vector<int> &frag, const vector<int> &query, const vector<int> &doc);

  double Compute_FM1(const vector<int> &frag, const vector<int> &query, const vector<int> &doc);
  double Compute_FM2(const vector<int> &frag, const vector<int> &query, const vector<int> &doc);
};

