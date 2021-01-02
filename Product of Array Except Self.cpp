#include <iostream>
#include <vector>

using namespace std;

// Juan Carlos Juárez

vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        res.resize(nums.size());
        res[res.size()-1]=1;
        for(int i=res.size()-2; i>=0; i--)
            res[i]=res[i+1]*nums[i+1];
        int prev=1;
        for(int i=0; i<res.size(); i++){
            res[i]*=prev;
            prev*=nums[i];
        }
        return res;
    }

int main() {
 vector<int> myVec={1,2,3};
 myVec.erase(myVec.begin()+2);
 for (int x:myVec)
 cout << x << " ";
}