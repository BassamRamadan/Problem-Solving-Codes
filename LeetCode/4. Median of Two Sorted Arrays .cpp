class Solution {
public:
    int smallerArr1(int target,vector<int>* arr1,vector<int>* arr2){
        int l = 0,r = int((*arr1).size())-1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            int in = smallerArr2(arr1->operator[](mid),target - mid,arr2);
            if(mid + in == target)
                return  mid;
            if(mid + in  < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int smallerArr2(int target,int indx,vector<int>* arr){
        int l = 0,r = int((*arr).size())-1;
        int ans = 0;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if(arr->operator[](mid) == target){
                if(mid < indx){
                    l = mid + 1;
                    ans = max(ans,mid+1);
                }else{
                    r = mid - 1;
                }
            }else if(arr->operator[](mid) < target)
                l = mid + 1,ans = max(ans,mid+1);
            else
                r = mid - 1;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int size = (int(nums1.size())+int(nums2.size()));
        if(size&1){
            int a1 = smallerArr1(size/2, &nums1, &nums2);
            int b1 = smallerArr1(size/2, &nums2, &nums1);
            return a1 != -1 ? nums1[a1] : nums2[b1];
        }else{
            int a1 = smallerArr1(size/2, &nums1, &nums2);
            int a2 = smallerArr1(-1+size/2, &nums1, &nums2);
            int b1 = smallerArr1(size/2, &nums2, &nums1);
            int b2 = smallerArr1(-1+size/2, &nums2, &nums1);
            
            double ans = 0.0;
            if(a1 != -1 && b2 != -1) ans += nums1[a1] + nums2[b2];
            else if(a2 != -1 && b1 != -1) ans += nums1[a2] + nums2[b1];
            else if(a1 != -1) ans += nums1[a1] + nums1[a2];
            else ans = nums2[b1] + nums2[b2];

            return ans/2.;
        }
    }
};