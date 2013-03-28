#include "Document.h"
#include "io_vector_util.h"
#include <algorithm>
#include <fstream>
#include <iostream>

using std::copy;
using std::sort;
using std::ofstream;
using std::endl;
using std::find;
using std::cout;


bool are_the_same(const vector<int> &frag1, const vector<int> &frag2) {
  int s = 0;
  for (int i; i < 6; ++i) {
    s += frag1[i] % 1000000 == frag2[i] % 1000000;
  }

  return s == 6;
}

Document::Document()
{
}

Document::Document(Lemm_collection *global_lemm_coll_in, vector<int> *query_in, vector<int> &doc, vector<string> &doc_str_in)
{
  global_lemm_coll = global_lemm_coll_in;
  query = query_in;
  doc_str = doc_str_in;
  //tokens = doc;
  for (size_t it = 0; it < doc.size(); ++it) {
    if (doc[it] > 0)
      tokens.push_back(doc[it]+1000000*it); //save the lemm id & its order number
    else //lemm = '.' or unknown word
      tokens.push_back(doc[it]);
  }
}

void Document::Divide_into_frags()
{
  int i = 0;
  vector<int> temp_sent;
 
  cout << "extracting fragments..." << endl;

  for (size_t token_it = 0; token_it < tokens.size(); ++token_it) {
    if (tokens[token_it] != -1) {
      temp_sent.push_back(tokens[token_it]);
    } else {
      if (temp_sent.size() < FRAGMENT_LENGTH_TRESHOLD) {
        frags.push_back(temp_sent);
      } else {
        vector<int> temp_frag;
        temp_frag.resize(FRAGMENT_LENGTH_TRESHOLD);
          copy(temp_sent.begin(), temp_sent.begin()+FRAGMENT_LENGTH_TRESHOLD, temp_frag.begin());
          frags.push_back(temp_frag);
      }
      temp_sent.clear();
    }
  }

  cout << "done!" << endl;
}

bool Document::less_oper(const vector<int> &v1, const vector<int> &v2) {
  double tmp1 = global_lemm_coll->Compute_FM1(v1, *query, tokens);
  double tmp2 = global_lemm_coll->Compute_FM1(v2, *query, tokens);
  return (tmp1 < tmp2);
}

void Document::sort_me_totally(vector<vector<int> > &v, int low, int high) {
  int i = low; 
  int j = high;
  vector<int> m_elem = v[(low+high)/2];

  do 
  {
    while((i < v.size()) && (less_oper(m_elem, v[i]))) 
      ++i;
    while((j >= 0) && (less_oper(v[j],m_elem))) 
      --j;
    if (i <= j) {
      v[i].swap(v[j]);
      i++;
      j--;
    }
  } while (i <= j);

  if(low < j) sort_me_totally(v, low, j);
  if(high > i) sort_me_totally(v, i, high);

}

void Document::Make_annotation() {
  vector<vector<int> > RF1(frags);
  vector<vector<int> > RF2(frags);

  /*FM1_sort_struct s1(this);
  FM2_sort_struct s2(this);*/

 cout << "building annotation..." << endl;

  sort_me_totally(RF1, 0, RF1.size()-1);
  //sort_me_totally(RF2, 0, RF2.size()-1);

  //sort(RF1.begin(), RF1.end(), s1);
  //sort(RF2.begin(), RF2.end(), s2);

  /*for (size_t it = 0; it < RF1.size(); ++it) {
    cout << global_lemm_coll->Compute_FM1(RF1[it], *query, tokens) << endl;
  }*/


 /* ofstream fout("debug_data.txt");
  for (size_t it = 0; it < RF1.size(); ++it) {
    for (size_t i = 0; i < RF1[it].size(); ++i) {
      fout << doc_str[RF1[it][i] / 1000000] << ' ';
    }
    fout << it << ' ' << endl;
  }
  fout.close();*/

  annot_1.push_back(RF1[0]);
  
  for (int n = 1, size_1 = (int)RF1[0].size(); (n < RF1.size()) && (size_1 < LENGTH_TRESHOLD); n++) {
    if (!are_the_same(RF1[n], RF1[n-1])) {
      annot_1.push_back(RF1[n]);
    }
    size_1 += (int)RF1[n].size();
  }
  /*for (int n = 0, size_2 = 0; size_2 < LENGTH_TRESHOLD; n++) {
    annot_2.push_back(RF2[n]);
    size_2 += (int)RF2[n].size();
  }*/

  cout << "done!" << endl;
}

void Document::Print_annotation(const string &fout_name, const vector<string> &doc_str) {
  ofstream fout;

  fout.open(fout_name.c_str());

  int lemma_pos;

  cout << "saving to " << fout_name << ".txt..." << endl;

  for (size_t i = 0; i < annot_1.size(); ++i) {
    for (size_t j = 0; j < annot_1[i].size(); ++j) {
      //lemma_pos = find(tokens.begin(), tokens.end(), annot_1[i][j]) - tokens.begin();
      lemma_pos = annot_1[i][j] / 1000000;
      fout << doc_str[lemma_pos] << ' ';
    }
    fout << "... " << endl;
  }

  cout << "done! see the result file!" << endl;
}
