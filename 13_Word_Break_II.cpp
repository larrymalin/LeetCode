#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;


bool markDP(string s, unordered_set<string> &dict, vector<bool> &dp) {
  if(s.size()==0) return true;
  if(dict.empty()) return false;
  for(int i = s.size()-1; i>=0; i--)
    for(int len = 1; len <= s.size(); len++){
      int start = i - len + 1;
      if(start < 0) break;
      if(dict.find(s.substr(start, len))!=dict.end() && dp[i+1])
	dp[start] = true;
    }
  return dp[0];
}

void findAllResult(string s, int start, vector<bool> dp, unordered_set<string> &dict, string result, vector<string> &results){
  if(start == s.size()){
    results.push_back(result.substr(0, result.size()-1));
    return;
  }
  for(int i = start; i < s.size(); i++){
    if(!dp[i+1]) continue;
    string word = s.substr(start, i - start + 1);
    if(dict.find(word)!=dict.end())
      findAllResult(s, i+1, dp, dict, result+word +" ", results);
  }
  

}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
  vector<string> res;
  vector<bool> dp(s.size()+1, false);
  dp[s.size()] = true;
  if(dict.empty() || s.size()==0 || !markDP(s, dict, dp)) return res;
  cout << "found" << endl;
  findAllResult(s, 0,  dp, dict, "", res);
  return res;
}

int main(){
  string s = "leetcode";
  unordered_set<string> dict = {"le", "leet", "etc", "leetc", "de", "code", "lee", "ode", "tcode"};

  vector<string> result = wordBreak(s, dict);
  for(int i = 0; i < result.size(); i++)
    cout << result[i] << endl;
}
