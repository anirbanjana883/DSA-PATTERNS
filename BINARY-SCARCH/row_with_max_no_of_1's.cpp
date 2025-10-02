2643. Row With Maximum Ones

class Solution {
public:
    int lower_bound(vector<int>arr,int n,int k){
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(arr[mid]>=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat[0].size();
        int count_max=0;
        int index=-1;
        for (int i=0;i<mat.size();i++){
                    sort(mat[i].begin(),mat[i].end());
            int ones=m-lower_bound(mat[i],m,1);
            if(ones>count_max){
                count_max=ones;
                index=i;
            }
        }
        return {index,count_max};
    }
};