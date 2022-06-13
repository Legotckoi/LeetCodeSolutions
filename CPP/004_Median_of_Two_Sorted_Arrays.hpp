class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t nums1Index = 0;
        size_t nums2Index = 0;
        size_t totalSize = nums1.size() + nums2.size();
        size_t median_index = totalSize / 2;
        double previous = 0;
        double current = 0;
        
        for (size_t i = 0; i < median_index + 1; ++i)
        {
            if (i == median_index)
            {
                previous = current;
            }
            
            if (nums1Index == nums1.size())
            {
                current = nums2.at(nums2Index);
                ++nums2Index;
                continue;
            }
            if (nums2Index == nums2.size())
            {
                current = nums1.at(nums1Index);
                ++nums1Index;
                continue;
            }
            
            if (nums1.at(nums1Index) < nums2.at(nums2Index))
            {
                current = nums1.at(nums1Index);
                ++nums1Index;
            }
            else
            {
                current = nums2.at(nums2Index);
                ++nums2Index;
            }
        }
        
        if (totalSize % 2 == 1)
        {
            return current;
        }
        
        return (current + previous) / 2;
    }
};
