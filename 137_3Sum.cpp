#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <climits> // INT_MAX
using namespace std;


vector<vector<int> > threeSum(vector<int> &num) {
  vector<vector<int> >res;
  if(num.size() <3) return res;
  sort(num.begin(), num.end());
  vector<int> triple(3, INT_MAX);
  int sum = 0;
  for(int first = 0; first < num.size()-2; first++){
    if(num[first] >0) return res;
    if(num[first] == triple[0]) continue;  // skipping duplicates
    triple[0] = num[first];
    sum = triple[0];
    for(int second = first+1; second < num.size()-1; second++){
      if(num[second] == triple[1]) continue;
      triple[1] = num[second];
      sum+=triple[1];
      if(sum > 0) cout << triple[0] << "," << triple[1] << endl;
      if(sum > 0) {sum-=num[second];break;}
      for(int third = num.size()-1; third>=second+1; third--){
	if(num[third] == triple[2]) continue;
	if(sum+num[third] == 0){
	  triple[2] = num[third];
	  res.push_back(triple);
	  break;
	}
	if(sum+num[third] < 0) break;
      }
      triple[2] = INT_MAX;
      sum-=num[second];
    }
    triple[1] = INT_MAX;    
  }

}

int main(){
  vector< vector<int> > result;
  vector<int> numbers;
  numbers.push_back(-4);
  numbers.push_back(-2);
  numbers.push_back(-2);
  numbers.push_back(-2);
  numbers.push_back(0);
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(2);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(4);
  numbers.push_back(6);
  numbers.push_back(6);
  result = threeSum(numbers);
  for(int i = 0; i < result.size(); i++)
    cout << "[" << result[i][0] << "," << result[i][1] << "," << result[i][2] << "]" << endl;
}
