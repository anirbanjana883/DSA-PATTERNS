74. Search a 2D Matrix

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
        for (int i=0;i<row_size;i++){
            // target lies bw this row
            if(matrix[i][0]<=target && target<=matrix[i][col_size-1]){
                   return  binary_scarch(matrix[i],target);
            }
        }
        return 0;
    }
};

some optimisation->
hipothetically flatten the 2d array[ hipothetically only,ather wise t.c will increase o o(n*m)]into
 1d array time complexity o(log(n*m))

******TRICK*****
in 1d array if index is index
then in 2d array **[row=index / m]** and **[col=index % m]** where m is column number 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = (n * m) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / m, col = mid % m;

            if (matrix[row][col] == target)
                return 1;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
};