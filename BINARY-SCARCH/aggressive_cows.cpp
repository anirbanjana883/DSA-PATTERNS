problem of patten  MIN_OF_MAX or MAX_OF_MIN

Aggressive Cows

one word : we are finding the bigger number in which distance wqe can place cow 
broute force  : t.c o((max-min)*n)
class Solution {
public:
    bool check_possible(vector<int>& arr, int dist, int k) {
        int cnt_cow = 1;
        int last = arr[0];
        for (int i = 1; i < arr.size(); i++) {  // Start from 1 to correctly place cows
            if (arr[i] - last >= dist) {
                last = arr[i];
                cnt_cow++;
            }
            if (cnt_cow >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n - 1] - stalls[0];  // Use proper high value for distance
        int maxDist = 0;

        for (int i = low; i <= high; i++) {
            if (check_possible(stalls, i, k)) {
                maxDist = i;
            } else {
                break; // No need to continue if i is not possible
            }
        }
        return maxDist;
    }
};
optimise dpparoach binary scarch t.c o(nlog n)

class Solution {
  public:
    bool cheak(vector<int>arr,int dist,int k){
        int cnt_cow=1;
        int last=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=dist){
                last=arr[i];
                cnt_cow++;
            }
            if(cnt_cow>=k) return 1;
        }
        return 0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        int max_dist=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(cheak(stalls,mid,k)){
                max_dist=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return max_dist;
    }
};