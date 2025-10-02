 240. Search a 2D Matrix II

All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.

1   4   7   11  15          each row is increasing
2   5   8   12  19          each column is increasing
3   6   9   16  22
10  13  14  17  24
18  21  23  26  30

approach 1-> o(n^2)
approach 2->

binary scarch on each row ofter cheaking the element is present in the row or not

class Solution {
public:
bool binary_scarch(vector<int>arr,int target){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]==target) return 1;
        else if (arr[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return 0;
}

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          // we are cheaking in each row if the element is betwen 
        // if yes we are doing binary scarchnin that row only
        int row_size=matrix.size();
        int col_size=matrix[0].size();
        bool res=0;
        for (int i=0;i<row_size;i++){
            // target lies bw this row
            if(matrix[i][0]<=target && target<=matrix[i][col_size-1]){
                   if (binary_scarch(matrix[i],target)) res=1;
            }
        }
        return res;
    }
};

 approach 3 most optimal approach -> 
time comp. o(n+m) s.c o(1)
  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        int col=matrix[0].size()-1;
        int n=matrix.size();
        while(row<n && col>=0){
            if(matrix[row][col] ==target) return 1;
            else if(matrix[row][col] <target) row ++;
            else col--;
        }
        return 0;
    }
};