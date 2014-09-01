#include <iostream>
#include <vector>


using namespace std;


int singleNumber(int A[], int n) {
  int single = 0; 
  int mask, sum; 

  for(int bit = 0; bit < 32; bit++){
    mask = (1 << bit);
    sum = 0;
    for(int i = 0; i < n; i++){
      if(A[i] & mask) sum++;
    }
    if(sum%3)
      single |= mask;
  }
  return single;
}


int main(){

  int A[] = {1,1,1,2,2,2,3,4,4,4,5,5,5}; 

  cout << singleNumber(A, 13) << endl;

}
