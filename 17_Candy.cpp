#include <iostream>
#include <vector>
#include "stdlib.h"

using namespace std;



int candy(vector<int> &ratings) {
  vector<int> candies(ratings.size(), 1);
  int decending_start, decending_end;
  for(int i = 0; i < ratings.size()-1; i++){
    if(ratings[i] < ratings[i+1])
      candies[i+1] = candies[i] + 1;
    else if(ratings[i] == ratings[i+1]){
      continue;
    }else{
      decending_start = i;
      while(i+1 < ratings.size() && ratings[i] > ratings[i+1]) i++;
      decending_end = i;
      for(int j = decending_end-1; j >=decending_start; j--)
	candies[j] = max(candies[j], candies[j+1] + 1);
      i--; // start from the decending_end
    }
  }
  int sum=0;
  for(int i = 0; i < candies.size(); i++)
    sum+=candies[i];
  return sum;

}

int main(){
  vector<int> ratings;
  for(int i = 0; i < 10; i++)
    ratings.push_back(rand()%20);

  cout << candy(ratings) << endl;
  return 0;

}
