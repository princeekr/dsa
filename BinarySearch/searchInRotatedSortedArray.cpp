// 33. Search in Rotated Sorted Array
// so in this case we should know that either mid and left or mid and right side will be sorted fs and based on that we do our search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int hi = n-1;
        int lo = 0;

        while(lo<=hi){
            int mid  = lo + (hi-lo)/2;    //we do this instead of (lo+hi)/2 to avoid possible integer overflow

            if(nums[mid] == target) return mid;

            if(nums[lo] <= nums[mid]){   //we check for left sorted part
                if(target >= nums[lo] && target < nums[mid]) hi = mid-1;
                else lo = mid+1;
            }
            else{  //right sorted part
                if(target > nums[mid] && target <= nums[hi]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return -1;
    }
};
