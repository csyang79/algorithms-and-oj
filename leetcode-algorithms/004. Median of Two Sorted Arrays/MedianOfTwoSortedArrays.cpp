class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int len1 = nums1.size();
        const int len2 = nums2.size();
        const int totalLen = len1 + len2;
        if ((totalLen & 1) == 1)
            return findKth(nums1.cbegin(), len1, nums2.cbegin(), len2, totalLen / 2 + 1);
        else
            return (findKth(nums1.cbegin(), len1, nums2.cbegin(), len2, totalLen / 2) + \
                    findKth(nums1.cbegin(), len1, nums2.cbegin(), len2, totalLen / 2 + 1)) / 2.0;
    }
    typedef vector<int>::const_iterator It;
    double findKth(It it1, const int len1, It it2, const int len2, const int k)
    {
        if (len1 > len2)
            return findKth(it2, len2, it1, len1, k);
        if (len1 == 0)
            return *(it2 + k - 1);
        if (k == 1)
            return min(*it1, *it2);
        int num1 = min(len1, k / 2), num2 = k - num1;
        if (*(it1 + num1 - 1) < *(it2 + num2 - 1))
            return findKth(it1 + num1, len1 - num1, it2, len2, k - num1);
        else if (*(it1 + num1 - 1) > *(it2 + num2 - 1))
            return findKth(it1, len1, it2 + num2, len2 - num2, k - num2);
        else
            return *(it1 + num1 - 1);
    }
};
