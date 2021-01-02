#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Juan Carlos Juárez 
//Binary Search High Level Analysis

   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            vector<int> temp= nums1;
            nums1=nums2;
            nums2= temp;
        }
        int x=nums1.size(), y=nums2.size();
        int totalSize= x+y;
        int low=0, high=x;
        while(low<=high){
            int partX= (low+high)/2;
            int partY= (totalSize+1)/2 - partX;
            int leftX = (partX==0) ? INT_MIN : nums1[partX-1];
            int rightX = (partX==x) ? INT_MAX : nums1[partX];
            int leftY= (partY==0) ? INT_MIN : nums2[partY-1];
            int rightY= (partY==y) ? INT_MAX : nums2[partY];
            if(leftX <= rightY && leftY <= rightX){
                if(totalSize%2==0){
                    return (max(leftX,leftY)+min(rightX,rightY))/2.0;
                }else{
                    return double(max(leftX,leftY));
                }
            }else if(leftX>rightY){
                high=partX-1;
            }else{
                low=partX+1;
            }
        }
        return -1;
    }
int main() {
  
}