#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <map>

using namespace std;


vector<int> twoSum(vector<int> &numbers, int target) {
  map<int,int> mapping; // map remaining to target and index
  vector<int> res(2);
  for(int i = 0; i < numbers.size(); i++){
    if(mapping.find(numbers[i])!=mapping.end()){
      res[0] = mapping[numbers[i]];
      res[1] = i+1;
      cout << res[0] << " " << res[1] << endl;
      return res;
    }else
      mapping[target - numbers[i] ] = i+1;
   }

  return res;
}

int main(){
  vector<int> numbers, result;
  numbers.push_back(3);  
  numbers.push_back(2);  
  numbers.push_back(4);  
  //  numbers.push_back(0);
  result = twoSum(numbers, 6);

  return 0;
}
