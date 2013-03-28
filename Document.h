#pragma once
#include <vector>
#include "Lemm_collection.h"

using std::vector;

const int LENGTH_TRESHOLD = 50;
const int FRAGMENT_LENGTH_TRESHOLD = 20;

class Document
{
  struct FM1_sort_struct {
    Document* m;
    FM1_sort_struct(Document* p) : m(p) {};

    bool operator() (const vector<int> &v1, const vector<int> &v2) 
    {
      double tmp1 = m->global_lemm_coll->Compute_FM1(v1, *(m->query), m->tokens);
      double tmp2 = m->global_lemm_coll->Compute_FM1(v2, *(m->query), m->tokens);
      return (tmp1 > tmp2);
      //return true;
    }
  };

  struct FM2_sort_struct {
    Document* m;
    FM2_sort_struct(Document* p) : m(p) {};

    bool operator() (const vector<int> &v1, const vector<int> &v2) 
    {
      return m->global_lemm_coll->Compute_FM2(v1, *(m->query), m->tokens) < m->global_lemm_coll->Compute_FM2(v2, *(m->query), m->tokens);
    }
  };

public:
  Document();
  Document(Lemm_collection *global_lemm_coll_in, vector<int> *query_in, vector<int> &doc, vector<string> &doc_str_in);

  vector<int> tokens;
  vector<string> doc_str;
  vector<vector<int> > frags;
  Lemm_collection *global_lemm_coll;
  vector<int> *query;
  vector<vector<int> > annot_1;
  vector<vector<int> > annot_2;

  void Divide_into_frags();
  void Make_annotation();
  bool less_oper(const vector<int> &v1, const vector<int> &v2);
  void sort_me_totally(vector<vector<int> > &v, int low, int high);
  void Print_annotation(const string &fout_name, const vector<string> &doc_str);
  // bool Pred_FM1(vector<int> v1, vector<int> v2);
  //bool Pred_FM2(vector<int> v1, vector<int> v2);



};

