4. Median of Two Sorted Arrays

Approach 1: Merge and Sort
====================================
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int >merged;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]) merged.push_back(nums1[i++]);
            else  merged.push_back(nums2[j++]);
        }
        while(i<n1) merged.push_back(nums1[i++]);
        while(j<n2) merged.push_back(nums2[j++]);
        
        int n=n1+n2;
        if(n% 2 ==1) return merged[n/2];
        return (double)((double)(merged[n/2]) +(double)(merged[n/2-1]))/2.0;
    }
};
Approach 2: Two-Pointer Method
====================================

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int ind2 = n / 2;
        int ind1 = n / 2 - 1;
        int cnt = 0;
        int ind2el = -1;
        int ind1el = -1;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (cnt == ind2)  ind2el = nums1[i];
                if (cnt == ind1)   ind1el = nums1[i];
                i++;
            } else {
                if (cnt == ind2)    ind2el = nums2[j];
                if (cnt == ind1)     ind1el = nums2[j];
                j++;
            }
            cnt++;
        }
        while (i < n1) {
            if (cnt == ind2)    ind2el = nums1[i];
            if (cnt == ind1)    ind1el = nums1[i];
            i++;
            cnt++;
        }
        while (j < n2) {
            if (cnt == ind2)   ind2el = nums2[j];
            if (cnt == ind1)    ind1el = nums2[j];
            j++;
            cnt++;
        }
        if (n % 2 == 1)      return ind2el;
        return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};

Approach 3: Binary Search
==========================

//T.C : O(log(min(m, n))
//S.C : O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0, high = m;
        while(low <= high) {
            
            int Px = low + (high-low)/2;
            int Py = (m+n+1)/2 - Px;
            
            int x1  = (Px == 0) ? INT_MIN : nums1[Px-1];
            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            
            int x2  = (Py == 0) ? INT_MIN : nums2[Py-1];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];
            
            if(x1 <= x4 && x2 <= x3) {
                if((m+n)%2 == 0)
                    return (max(x1, x2) + min(x3, x4))/2.0;
                
                return max(x1, x2);
            } else if(x1 > x4) {
                high = Px-1;
            } else {
                low = Px+1;
            }
        }
        
        return -1;
    }
};
