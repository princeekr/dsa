//35. Search Insert Position
// if u understand the basic binary search then u wld know that lo always stays at a inserting position in the end. 
// so thats it do basic binary search and then return lo in end. 

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid] < target) lo = mid+1;
            else if(nums[mid] > target) hi = mid-1;
            else return mid;
        }
        
        return lo;
    }
};