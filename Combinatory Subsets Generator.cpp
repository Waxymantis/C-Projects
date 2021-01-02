#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Juan Carlos Juárez 
//Subsets Generator Given vector

void comb(vector<int> nums, int index, vector<int> curr, vector<vector<int>> &res){
        res.push_back(curr);
        for(int i=index; i<nums.size(); i++){
            if(i==index || nums[i]!=nums[i-1]){
                curr.push_back(nums[i]);
                comb(nums,i+1,curr,res);
                curr.erase(curr.end()-1);
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        comb(nums,0,curr,res);
        return res;
    }

int main() {
  
}