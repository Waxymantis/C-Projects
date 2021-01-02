#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Juan Carlos Juárez 
//Sudoku Solver Adaptation Updated with revision

bool isValidSudoku(vector<vector<char>>& board) {
         map<string,int> myMap;
         char temp;
         int tempR=0,tempC=0;
         for(int ren=0; ren<9;ren++){
             for(int col=0; col<9; col++){
                 temp=board[ren][col];
                 if(temp!='.'){
                 tempR=ren/3;
                 tempC=col/3;
             if(myMap.count(to_string(temp)+"ren"+to_string(ren))||myMap.count(to_string(temp)+"col"+to_string(col))||myMap.count(to_string(temp)+"sub"+to_string(tempR)+"-"+to_string(tempC))){
                 return false;
             }
            myMap.insert({to_string(temp)+"ren"+to_string(ren),ren});
            myMap.insert({to_string(temp)+"col"+to_string(col),ren});
            myMap.insert({to_string(temp)+"sub"+to_string(tempR)+"-"+to_string(tempC),ren});
                 }
             }
         }
        return true;
    }

int main() {
  
}