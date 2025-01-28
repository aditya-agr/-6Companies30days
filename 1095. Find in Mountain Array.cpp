/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l=0, h=n-1;
        while(l<h){
            int mid = l + (h-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid+1;
            else
                h = mid;
        }

        int peak = l;
        int i=0, j=peak;
        while(i<=j){
            int mid = i + (j-i)/2;
            int temp = mountainArr.get(mid);
            if(temp == target)
                return mid;
            else if(temp > target)
                j = mid-1;
            else
                i = mid+1;
        }
        
        int x=peak+1, y=n-1;
        while(x<=y){
            int mid = x+(y-x)/2;
            int temp = mountainArr.get(mid);
            if(temp == target)
                return mid;
            else if(temp > target)
                x = mid+1;
            else
                y = mid-1;
        }
        return -1;
    }
};