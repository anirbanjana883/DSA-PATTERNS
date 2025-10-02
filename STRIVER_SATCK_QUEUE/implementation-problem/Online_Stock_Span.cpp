901. Online Stock Span

class StockSpanner {
public:
    // time every next function is taking o( n )
    // space (no of next function call)
    StockSpanner() {
       
    }
    vector<int>arr;
    int next(int price) {        
        arr.push_back(price);
        int cnt = 1;
        // start checking from back 
        for(int i = arr.size() - 2 ; i >= 0 ; i--){
            if(arr[i] <= price ) cnt ++;
            else break;
        }
        return cnt ;
    }
};


class StockSpanner {
public:
    // time - o(2 * n)
    // space - o( n )
    // element , idx
    stack<pair<int,int>>st;
    int ind = -1;
    StockSpanner() {
        // everey time stockSpanner constructor is called 
        // ind veriable reinitialized 
        ind = -1;
    }
    int next(int price) {
        ind = ind + 1;
        while( !st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = (st.empty() ? ind + 1 : ind - st.top().second);
        st.push({price , ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */