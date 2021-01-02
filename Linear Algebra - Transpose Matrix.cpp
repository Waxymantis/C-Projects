#include <iostream>
#include <vector>

using namespace std;

// Juan Carlos Juárez

void transpose(vector<vector<int>> &mat){
  for(int ren=0; ren<mat.size();ren++){
    for(int col=ren; col<mat.size();col++){
      if(ren!=col){
        int temp=mat[ren][col];
        mat[ren][col]=mat[col][ren];
        mat[col][ren]=temp;
      }
    }
  }
}

int main() {
  vector<vector<int>> mat;
  int size=0,data=0;
  cout << "Size of Square Matrix: First Insert Size, then insert all elements of the matrix";
  cin >> size;
  for(int ren=0; ren<size; ren++){
    vector<int> temp;
    for(int col=0; col<size; col++){
      cin >> data;
      temp.push_back(data);
    }
    mat.push_back(temp);
  }
  transpose(mat);
  for(int ren=0;ren<mat.size();ren++){
    for(int col=0;col<mat.size();col++){
      cout << mat[ren][col] << " ";
    }
    cout << endl;
  }
return 0;
}