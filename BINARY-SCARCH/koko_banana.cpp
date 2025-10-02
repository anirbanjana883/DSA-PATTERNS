  broute force approach->  KOKO EATING BANANA

class Solution {
public:
    int time(vector<int> piles,int timely){
        int require_time=0;
        for(int i=0;i<piles.size();i++){

          ****ceil function act on float value
          **** (piles[i] + timely - 1)/timely  this will work same as ceil

            require_time+=(piles[i] + timely - 1)/timely;
        }
        return require_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //  broute force solution
        sort(piles.begin(),piles.end());
        int n=piles.size();
        for(int i=1;i<=piles[n-1];i++){
            if(time(piles,i)<=h){
                return i;
            }
        }
        return -1;
    }
};
Input: piles = [3,6,7,11], h = 8
Output: 4

1  2 3 | 4 5 6 7 8 9 10 11 
*  * * | V V V V V V V   V  here you can see a pattern of not possible and not possible 
so you can think of binary scarch

binary scarch 

the fir thing you have to determine the *range* while applying binary scarch

class Solution {
public:
    long long getHoursToEatAll(vector<int>&piles, int bananasPerHour)
    {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int hoursToEatPile = ceil(piles[i] / (double)bananasPerHour);
            totalHours += hoursToEatPile;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int targetHours)
    {
        int low = 1, high = *(max_element(piles.begin(), piles.end()));
        int ans = -1;
        //================================================================
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            long long hoursToEatAll = getHoursToEatAll(piles, mid);
            
            if (hoursToEatAll <= targetHours)
            {
                ans = mid; //record the answer (this is the best we could record till curr step)
                high = mid - 1;
            }
            else low = mid + 1;
        }
        //=================================================================
        return ans;
    }
};



        int low = 1, high = *(max_element(piles.begin(), piles.end()));
 this above line can be avoided by the following function
      
       int find_max(vector<int>arr){
        int max_element=INT_MIN;
        for(auto it :arr){
            max_element=max(max_element,it);
        }
        return max_element;
    }