3495. Minimum Operations to Make Array Elements Zero

class Solution {
public:
    // time q * (log(r)) r = max right range of query
    /*
    steps 
    1 - 3 = 1 step
    4 - 15 = 2 step
    16 - 63 = 3 step
    64 - 255 = 4 step
    4^( s - 1) - ( 4 ^ s ) - 1 = s step

    so if l given then  r = 4 * l - 1;
    */
    typedef long long ll;
    ll solve(int l , int r){
        ll L = 1;
        ll s = 1;
        ll step = 0;
        while( L <= r){
            ll R = 4*L - 1;
            ll start = max(L , (ll)l);
            ll end = min(R ,(ll)r);

            if(start <= end){
                step += (end - start + 1) * s;
            }
            s += 1;
            L *= 4;
        }
        return step;
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll result = 0;
        for ( auto &q : queries){
            int l = q[0];
            int r = q[1];

            ll steps = solve(l , r);
            result += (steps + 1) / 2; // ceil value 
        }
        return result;
    }
};