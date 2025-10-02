904. Fruit Into Baskets

for explantion you must watch streivers explanation of question

see you have only 2 basket 
and you can have only one type of frouit in to the basket 

approach 1 : extreme broute force solution 

time complexity o(n*n)
space complexity o(3)=o(1)

class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            // requirement of set ?? 
            // we can  store only 2 types of elemnt as we ahve 
            // onlt 2 basket to track that we need set 
            int n=fruits.size();
            int maxLength=0;
            for(int i=0;i<n;i++){
                set<int>st;
                for(int j=i;j<n;j++){
                    st.insert(fruits[j]);
                    if(st.size()<=2){ // only 2 types of element is there 
                        maxLength=max(maxLength,j-i+1);
                    }else{ // more then 2 types of element is there 
                        break;
                    }
                }
            }
            return maxLength;
        }
    };

approach 2 : optimised appproach

time complexity o(n+n)
space complexity o(3)=o(1)

why log(n) is not added to the add or delete element from the map 
bcoz size of map is 3 that is the rson it is near about constant 

class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int n=fruits.size();
            unordered_map<int,int>mp;
            int l=0;
            int r=0;
            int maxLength=0;
            while(l<n && r<n){
                mp[fruits[r]]++;
                if(mp.size()>2){ // not a valid subarray
                    while(mp.size()>2){ // this is taking exn time at worst possible case 
                        mp[fruits[l]]--;
                        if(mp[fruits[l]]==0){
                            mp.erase(fruits[l]);
                        }
                        l++;
                    }
                }else{
                    maxLength=max(maxLength,r-l+1);
                }
                r++;
            }
            return maxLength;
        }
    };

approach 2 : most optimised appproach

time complexity o(n)
space complexity o(3)=o(1
    class Solution {
        public:
            int totalFruit(vector<int>& fruits) {
                int n=fruits.size();
                unordered_map<int,int>mp;
                int l=0;
                int r=0;
                int maxLength=0;
                while(l<n && r<n){
                    mp[fruits[r]]++;
                    if(mp.size()>2){ // not a valid subarray
                        mp[fruits[l]]--;
                        if(mp[fruits[l]]==0){
                            mp.erase(fruits[l]);
                        }
                        l++;
                    }else{
                        maxLength=max(maxLength,r-l+1);
                    }
                    r++;
                }
                return maxLength;
            }
        };