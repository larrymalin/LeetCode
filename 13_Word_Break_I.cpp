#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
  if(s.size()==0) return true;
  if(dict.empty()) return false;
  vector<bool> dp(s.size()+1, false);
  dp[s.size()] = true;
  for(int i = s.size()-1; i>=0; i--)
    for(int len = 1; len <= s.size(); len++){
      int start = i - len + 1;
      if(start < 0) break;
      if(dict.find(s.substr(start, len))!=dict.end() && dp[i+1])
	dp[start] = true;
    }
  return dp[0];
}


int main(){
  string s = "leetcode";
  unordered_set<string> dict = {"le", "leet", "etc", "leetc", "de", "tcode"};

  string result = wordBreak(s, dict) ? "TRUE":"FALSE" ;
  cout << result << endl;


}
