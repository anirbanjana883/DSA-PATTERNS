912. Sort an Array

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
// it wil give tle you should implement merge or quick sort
// just for learning perpouse 
 class Solution {
public:
    void insert(vector<int>& v,int item){
        // base case
        // array is empty or last elementis less 
        // the item then directly push
        if(v.size() == 0 || v[v.size() - 1] <= item){
            v.push_back(item);
            return ;
        }
        // pop the last item and agin comapre
        int val = v[v.size() - 1];
        v.pop_back();
        insert(v, item);
        v.push_back(val);
        return ;
    }
    void sortTheArray(vector<int>& v){
        // base case
        if(v.size() == 1) return ;
        int temp = v[v.size() - 1];
        v.pop_back();
        sortTheArray(v);
        // now we have to insert the popped item
        insert(v , temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        sortTheArray(nums);
        return nums;
    }
};