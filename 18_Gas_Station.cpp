#include <iostream>
#include <vector>
#include "stdlib.h"

using namespace std;

int canCompleteCircuit(vector<int>&gas, vector<int>&cost){
  int n = gas.size();
  for(int i = 0; i < n; i++)
    gas[i] = gas[i] - cost[i];
  int sum, len;
  for(int start = 0; start < n; start++){
    sum = 0;
    for(len = 0; len < n; len++){
      sum+=gas[(start+len)%n];
      if(sum < 0) break;
    }
    if(len==n) return start;
  }
  return -1;

}




int main(){
  vector<int> gas, cost;
  int i = 20;
  while(i-- >=0){
    gas.push_back(rand()%100);
    cost.push_back(rand()%100);
  }
  cout << canCompleteCircuit(gas, cost) << endl;

}
