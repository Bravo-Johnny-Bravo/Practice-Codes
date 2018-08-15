class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0;
        int high = nums1.size();
        
        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = (nums1.size() + nums2.size() + 1) / 2 - partition1;
            
            int left1 = (partition1 - 1 >= 0) ? nums1[partition1 - 1] : INT_MIN;
            int right1 = (partition1 < nums1.size()) ? nums1[partition1] : INT_MAX;
            int left2 = (partition2 - 1 >= 0) ? nums2[partition2 - 1] : INT_MIN;
            int right2 = (partition2 < nums2.size()) ? nums2[partition2] : INT_MAX;

            if (left1 > right2) {
                high = partition1 - 1;
            } else if (left2 > right1) {
                low = partition1 + 1;
            } else {
                int size = nums1.size() + nums2.size();
                if (size & 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + (double) min(right1, right2)) / 2;
                }
            }
        }
    }
};
