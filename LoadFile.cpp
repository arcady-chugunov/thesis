#include "LoadFile.h"
#include <iostream>


int LoadFile(const string &fin_name, CMorphologyHolder* Holder) 
{
  // ===============  LOADING DICTS ================
  
  MorphLanguageEnum Language;
  
  GetLanguageByString("RUSSIAN", Language);

  //fprintf (stderr, "Loading dictionaries \n");

  if (!Holder->LoadGraphanAndLemmatizer(Language))
  {
    fprintf (stderr, "Cannot load  RUSSIAN morphology of \n");
    return 1;
  };



  FILE * fp = fopen (fin_name.c_str(), "r");
  if (!fp)
  {
    printf ("  Cannot open %s \n", fin_name.c_str() );
    return 1;
  };
  
    int CountOfWords;
  
  if (!Holder->GetMorphology(fin_name, true, CountOfWords)) 
    {
      printf ("  Cannot process %s \n", fin_name.c_str() );
    }

    //printf ("  Found %i items\n", Holder->m_PlmLines.m_Items.size() );
    //  morphology
    //  save
    //std::string LemFile = MakeFName(fin_name, "lem");
    //printf ( "  Save to %s\n", LemFile.c_str() );
   // Holder->m_PlmLines.SaveToFile(LemFile);
    //std:: cout << Holder->m_Graphan.GetTokensCount() << "END";
  fclose(fp);
  
  return 0;
}