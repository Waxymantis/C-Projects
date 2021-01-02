#include <iostream>
#include <vector>

// Juan Carlos Juárez
// Dynammic Programming Lesson

using namespace std;

//Fibonacci Sequence using Dynamic Programming - Bottom Up Approach.

//Steps to follow:
//1- Identify the base cases, which are those cases in which a recursive function reaches an end and *returns a proper value*. In this problem the base cases are that both the first and second numbers in the sequence are equal to 1, so we have two base cases, and we need to find the first input solutions scenarios that satisfy such base cases, which in this case become n=1 and n=2, which are the first and second numbers in the sequence. Therefore, all base cases shall be defined at the beginning for its filtration, and if they are not discarded, their values shall be stored and the program will run given the logic of the problem and the base cases themselves.

vector<long> fib(int n){
  vector<long> res; // Creation of storage
  if(n==1) return res={1}; // base case 1: the first number is equal to 1
  if(n==2) return res={1,1}; // base case 2: the second number is also equal to 1
  res.resize(n); // Definition of storage
  res[0]=1; // Storage of base case 1
  res[1]=1; // Storage of base case 2
  for(int i=2;i<n; i++){
    res[i]=res[i-1]+res[i-2];
  }
  return res;
}

int main() {
  vector<long> data;
  data=fib(20);
  for(long x:data)
  cout << x << endl;
}