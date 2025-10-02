whenevr V V V V V *********
ans is possible for certain time and then ans is not possible for certain time then you can 
think of binary scarch to apply


whenever you know the range[in example it is 1-n] of ans and in questuin you have asked min or max something 
in that range think about this template 

Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int low=1;
        int high=x/2;
        int ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
  //  all the value lesser then mid was discarded
            if(mid<=x/mid){  <- chekabox
                ans=mid;
                low=mid+1;
            }
  //  all the value greater tehn mid was discarded
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};