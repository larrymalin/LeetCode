#include <iostream>
#include <vector>


using namespace std;


int singleNumber(int A[], int n) {

  int single = 0; 
  for(int i = 0; i < n; i++){
    single ^= A[i];
  }
  return single;
  

}


int main(){

  int A[] = {1,1,2,2,3,3,4,4,5}; 

  cout << singleNumber(A, 9) << endl;

}
