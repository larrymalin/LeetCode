#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

void reverseWords(string &s){
  stack<string> words;
  istringstream iss(s);
  while(iss){
    string word;
    iss >> word;
    //cout << "word " << word << endl;
    if(word.size()!=0)
      words.push(word);
  }
  //  cout << words.size()<< endl;

  string res;
  while(!words.empty()){
    res += words.top();
    words.pop();
    if(!words.empty()) res+=" ";
  }
  s = res;
}



int main(){
  string s = " the   sky is blue";
  reverseWords(s);
  cout << s << endl;
  return 0;
}
