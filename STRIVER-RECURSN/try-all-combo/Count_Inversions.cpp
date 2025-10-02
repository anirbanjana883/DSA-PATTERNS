Count Inversions

broute force approach : 
class Solution {
  public:
    // time complexity: O(n^2)
    // space complexity: O(1)
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int count =0;
        for(int i =0;i<arr.size();i++)
        {
            for(int j = i+1;j<arr.size();j++)
            {
                if(arr[i]>arr[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};

 approach 2: 

class Solution {
  public:
    // Time Complexity: O(n^2) in the worst case.
    // Space Complexity: O(n) due to the use of two stacks.
     // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        stack<int> stk1, stk2;
        int ans = 0;
        
        // arr[] = [2, 4, 1, 3, 5] take it and understand
        for(int i = arr.size()-1; i >= 0; i--){
            
            // Find the correct position of curr element, to order in ASC
            while(!stk1.empty() && stk1.top() < arr[i]){
                stk2.push(stk1.top());
                stk1.pop();
                ans++;
            }
            stk1.push(arr[i]);
            // copy all elements from stk2 to stk1
            
            while(!stk2.empty()){
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        
        return ans;
    }
};

// approach 3: using merge sort
class Solution {
  public:
    // time complexity: O(nlogn)
    // space complexity: O(n)
     // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        stack<int> stk1, stk2;
        int ans = 0;
        
        // arr[] = [2, 4, 1, 3, 5] take it and understand
        for(int i = arr.size()-1; i >= 0; i--){
            
            // Find the correct position of curr element, to order in ASC
            while(!stk1.empty() && stk1.top() < arr[i]){
                stk2.push(stk1.top());
                stk1.pop();
                ans++;
            }
            stk1.push(arr[i]);
            // copy all elements from stk2 to stk1
            
            while(!stk2.empty()){
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        
        return ans;
    }
};