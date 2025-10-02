496. Next Greater Element I

aproach 1: broute force

time complexity: O(n1*n2)
space complexity: O(n1)

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size();
            int n2 = nums2.size();
            
            vector<int> result(n1, -1);
            unordered_map<int, int> mp; // number->index
            
            for(int i = 0; i < n2; ++i) {
                mp[nums2[i]] = i;
            }
    
            for(int i = 0; i < n1; ++i) {
                int curr_element = nums1[i];
                int idx_in_nums2 = mp[curr_element];
                
                for(int j = idx_in_nums2 + 1; j < n2; ++j) {
                    if(curr_element < nums2[j]) {
                        result[i] = nums2[j];
                        break; 
                    }
                }
            }
            
            return result;
        }
    };
    
Next Greater Element {gfg}  it is the actual question

better approach using stack

class Solution {
    // time complexity: O(2*N)
// space complexity: O(2*N)
    public:
      // Function to find the next greater element for each element of the array.
      vector<int> nextLargerElement(vector<int>& arr) {
      int n = arr.size();
      vector<int> nge(n);
      stack<int> st;
      
      for (int i = n - 1; i >= 0; i--) {
        // monotonically decreasing stack
          while (!st.empty() && st.top() <= arr[i]) {
              st.pop();
          }
          
          if (st.empty()) {
            nge[i] = -1;
          } else {
            nge[i] = st.top();
          }
          
          st.push(arr[i]);
      }
      return nge;
  }
  
  };


next Greater Element in Circular Array

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1); // Result initialized to -1
        stack<int> st;

        // Traverse the array twice (circular simulation)
        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = arr[i % n]; // Circular indexing

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (i < n) { // Only update result in the first pass
                if (!st.empty()) {
                    res[i] = st.top();
                }
            }

            st.push(curr);
        }

        return res;
    }
};
