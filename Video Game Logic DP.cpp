#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Juan Carlos Juárez 
//Video Game Logic Dynamic Programming

  int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) return 1;
        int dp[dungeon.size()][dungeon[0].size()];
       // dp[dungeon.size()-1][dungeon[0].size()-1]=dungeon[dungeon.size()-1][dungeon[0].size()-1];
        for(int ren=dungeon.size()-1; ren>=0; ren--){
            for(int col=dungeon[ren].size()-1; col>=0; col--){
                if(ren==dungeon.size()-1 && col==dungeon[ren].size()-1){
                    dp[ren][col]=min(0,dungeon[ren][col]);
                    continue;
                }
                int currVal=dungeon[ren][col];
                if(ren==dungeon.size()-1){
                    currVal+=dp[ren][col+1];
                }else if(col==dungeon[ren].size()-1){
                    currVal+=dp[ren+1][col];
                }else{
                    currVal+=max(dp[ren+1][col],dp[ren][col+1]);
                }
                if(currVal>=0){
                dp[ren][col]=0;
                }else{
                dp[ren][col]=currVal;
                }
            }
        }
        return abs(dp[0][0])+1;
    }
int main() {
  
}