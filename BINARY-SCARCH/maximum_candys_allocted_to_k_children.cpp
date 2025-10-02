2226. Maximum Candies Allocated to K Children


broute force approach :

time complexity o(n*n)

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int n=candies.size();
    
            int maxc=0;
    
            for(int i=0;i<n;i++){
                maxc=max(maxc,candies[i]);
            }
    
            // we will start from max element 
            for(int c=maxc;c>=1;c--){
                long long count=0;
    
                for(int i=0;i<n;i++){
                    count+=candies[i]/c;
                }
    
                if(count>=k) return c;
            }
            return 0;
        }
    };

approach 2: binary search on answer 

time complexity o(n*log(maxc))

class Solution {
    public:
        bool canDistribute(vector<int>& candies, int mid,long long k){
            int n=candies.size();
    
            for(int i=0;i<n;i++){
                k-=candies[i]/mid;
                if(k<=0) return true;
            }
            return k<=0;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            int n = candies.size();
    
            int maxc = 0;
    
            for (int i = 0; i < n; i++) {
                maxc = max(maxc, candies[i]);
            }
    
            // range defineing 
            int low =1;
            int high =maxc;
            long long result=0;
            while(low<=high){
                int mid=low+(high-low)/2;
    
                if(canDistribute(candies,mid,k)){
                    result=mid;
                    // but we will check for more large value
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            return result;
        }
    };