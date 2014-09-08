#include <iostream>

using namespace std;


bool isMatch(const char*s, const char *p){
  cout << "Comparing " << *s << " " << *p <<endl;

  if(!s&&p) return false;
  if(*p=='\0') return (*s=='\0');

  // first check if next symbol is not *, i.e. ab
  if(*(p+1)!='*'){
    if(*p == *s || *p == '.' && *s!='\0') 
      return isMatch(s+1, p+1);
    else 
      return false;
  }
  // if next symbol is *, i.e. a*
  while(*p == *s || *p=='.' && *s!='\0'){
    if(isMatch(s, p+2)) return true;
    s++;
  }
  return isMatch(s, p+2);;
 }


int main(){

  char *s1 = "aab";
  char *s2 = "c*a*b";
  if(isMatch(s1, s2)) cout << "Regex Matched!" << endl;
  else cout << "Not Matched" << endl;


}
