#include "Lemm_collection.h"
#include "io_vector_util.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <time.h>

using std::find;
using std::endl;
using std::cout;
using std::ofstream;
using std::ifstream;
using std::scientific;


Lemm_collection::Lemm_collection() {
}

Lemm_collection::Lemm_collection(vector<string> *doc_str_in) {
  doc_str = doc_str_in;
}


void Lemm_collection::Init(vector<vector<int> > &doc_collection, const string &fout_name) {
  int iter_no = 0;
  //clock_t t;

  cout << "computing lemm frequencies..." << endl;

  for (size_t doc_id = 0; doc_id < doc_collection.size(); ++doc_id) {
    for (size_t it = 0; it < doc_collection[doc_id].size(); ++it) {
      if (doc_collection[doc_id][it] > 0)
        LDC_map[doc_collection[doc_id][it]][doc_id]++;
    }
  }

  ofstream fout(fout_name.c_str());
  for (size_t doc_id = 0; doc_id < doc_collection.size(); ++doc_id) {
    for (size_t it = 0; it < doc_collection[doc_id].size(); ++it) {
      fout << LDC_map[doc_collection[doc_id][it]][doc_id] << endl;
    }
  }

  fout.close();

  cout << "done!" << endl;
}


void Lemm_collection::Init_from_file(vector<vector<int> > &doc_collection, const string &fin_name) {

  cout << "computing lemm frequencies..." << endl;

  ifstream fin(fin_name.c_str());
  for (size_t doc_id = 0; doc_id < doc_collection.size(); ++doc_id) {
    for (size_t it = 0; it < doc_collection[doc_id].size(); ++it) {
      fin >> LDC_map[doc_collection[doc_id][it]][doc_id];
    }
  }

  fin.close();

  cout << "done!" << endl;
}


int Lemm_collection::Compute_IF(int lemm_id, const vector<int> &doc) {
  int res = 0;
  for (size_t it = 0; it < doc.size(); ++it) {
    if (lemm_id == doc[it] % 1000000)
      res++;
  }
  return res;
}

int Lemm_collection::Compute_DF(int lemm_id) {
  return LDC_map[lemm_id].size();
}

int Lemm_collection::Compute_CLF(int lemm_id, int freq) {
  int res = 1;
  size_t s = LDC_map[lemm_id].size();
  for (size_t doc_it = 0; doc_it < s; ++doc_it) {
    if (LDC_map[lemm_id][doc_it] >= freq) {
      res++;
    }
  }
  return res;
}

double Lemm_collection::Compute_ICLF(int lemm_id, int freq) {
  int tmp1 = Compute_DF(lemm_id);
  int tmp2 = Compute_CLF(lemm_id, freq);
  return (double)tmp1/(double)tmp2;
}



double Lemm_collection::Compute_IFQ(const vector<int> &frag, const vector<int> &query, const vector<int> &doc) {
  double res = 1;
  int freq = 0;
  vector<int> frag_edited;

  //cout << frag.size() << endl;

  for (size_t it = 0; it < frag.size(); ++it)
  {
    frag_edited.push_back(frag[it] % 1000000);
  }

  for (size_t q_it = 0; q_it < query.size(); ++q_it) {
    if (find(frag_edited.begin(), frag_edited.end(), query[q_it]) == frag_edited.end()) {
      freq = Compute_IF(query[q_it], doc);
      res += Compute_ICLF(query[q_it], freq);
    }
  }
  return res;
}

double Lemm_collection::Compute_IQF(const vector<int> &frag, const vector<int> &query, const vector<int> &doc) {
  double res = 0;
  int freq = 0;
  for (size_t f_it = 0; f_it < frag.size(); ++f_it) {
    if (find(query.begin(), query.end(), frag[f_it] % 1000000) == query.end()) {
      freq = Compute_IF(frag[f_it] % 1000000, doc);
      res += Compute_ICLF(frag[f_it] % 1000000, freq);
    }
  }
  return res;
}

double Lemm_collection::Compute_FM1(const vector<int> &frag, const vector<int> &query, const vector<int> &doc )
{
  double res = 1/Compute_IFQ(frag, query, doc)+(1e-18)*Compute_IQF(frag, query, doc);
  return res;
}

double Lemm_collection::Compute_FM2( const vector<int> &frag, const vector<int> &query, const vector<int> &doc )
{
  return 1/Compute_IFQ(frag, query, doc)+(1e-6)/Compute_IQF(frag, query, doc);
}
