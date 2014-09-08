#include <iostream>

using namespace std;


bool isMatch(const char*s, const char *p){
  //  cout << "Comparing " << *s << " " << *p <<endl;
  const char* starPos = NULL;
  const char* ss = s;
  while(*s){
    if(*p == '?' || *p ==*s) {s++; p++; continue;}  // match 1 char from each
    if(*p == '*'){starPos = p++; ss = s; continue;} // mark where * starts
    // if not matched, trace back to where * starts, match (p, s+1);
    if(starPos){p = starPos + 1; s = ++ss; continue;}
    return false;
  }
  while(*p =='*') p++;  // trailing *'s
  return !*p;

 }


int main(){

  char *s1 = "aab";
  char *s2 = "c*a*b";
  if(isMatch(s1, s2)) cout << "WildCard Matched!" << endl;
  else cout << "Not Matched" << endl;


}
