// 852. Peak Index in a Mountain Array
// we check for increasing or decreasing slopes and based on that we move hi or lo. 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int hi = n-1;
        int lo = 0;

        while(lo<=hi){
            int mid = lo +(hi-lo)/2;

            if((arr[mid] > arr[mid-1]) && (arr[mid] < arr[mid+1])) lo = mid+1;  // left<mid<right means increasing slope so go right
            else if((arr[mid] < arr[mid-1]) && (arr[mid] > arr[mid+1])) hi = mid-1;  // left>mid>right means decreasing slope so go left
            else return mid;
        }
        
        return -1;
    }
};