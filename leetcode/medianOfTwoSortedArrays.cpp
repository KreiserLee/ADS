class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        merge(nums1, nums2, nums3);
        int l3 = nums3.size();
        if (0 == l3 % 2)
            return (nums3[l3/2] + nums3[l3/2-1])/2.0;
        else
            return nums3[l3/2];
    }
    void merge(const vector<int> &nums1, const vector<int> &nums2, vector<int> &nums3) {
        int i = 0, j = 0;
        int l1 = nums1.size(), l2 = nums2.size();
        while(i < l1 && j < l2) {
            if (nums1[i] <= nums2[j])
                nums3.push_back(nums1[i++]);
            else
                nums3.push_back(nums2[j++]);
        }
        if (i == l1)
            while (j < l2)
                nums3.push_back(nums2[j++]);
        else
            while (i < l1)
                nums3.push_back(nums1[i++]);
    }
};