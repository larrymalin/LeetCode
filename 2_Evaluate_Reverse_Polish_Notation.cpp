#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

bool isOperator(string s){
  return s == "+" || s == "-" || s == "*" || s == "/";
}


int evalRPN(vector<string> &tokens) {
  stack<int> operands;
  for(int i = 0; i < tokens.size(); i++){
    if(isOperator(tokens[i])){
      int op1 = operands.top(); operands.pop(); 
      int op2 = operands.top(); operands.pop(); 
      //      cout << "pop " << op1 << endl; cout << "pop " << op2 << endl;
      int res = 0;
      if(tokens[i] == "+") res = op1 + op2;
      else if(tokens[i] == "-") res = op2 - op1;
      else if(tokens[i] == "*") res = op2 * op1;
      else if(tokens[i] == "/") res = op2 / op1;
      operands.push(res);
      //      cout << "pushing " << res << endl;
    }else{ 
      int op;
      stringstream(tokens[i]) >> op;
      operands.push(op);
      //      cout << "pushing " << op << endl;
    }
  }
  return operands.top();
}

int main(){
  vector<string> line;
  line.push_back("4");
  line.push_back("13");
  line.push_back("5");
  line.push_back("/");
  line.push_back("+");
  cout << evalRPN(line) << endl;


}
