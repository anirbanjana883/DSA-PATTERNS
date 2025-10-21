when to apply difference array 

%%%% the same thing we have done in segment tree but its implementation is harder
so we use this diierence array technique

=>  $ famous technique
    $ efficiently apply range update to an array
    $ helps to do multiple update at constant time 

    => => very useful for range modification problem

    example 

    Input: nums = [0,0,0,0,0],   size N 
    queries = [[1,3,2],[2,4,3],[0,2,-2]]  size Q
    output nums = [-2,0,3,5,3]


    broute force approach 
    just check all the query and do whatever question ask
    to update this time complexity will be O(Q*N) (broute force)

    optimised approach: difference array techique

    {generalised formula} ====>

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

    1. [L,R,X]  arr[L]+=X;
                arr[R+1]-=X; (R+1<N) r should be valid 
    2. take cumulative sum

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

    see after applying this formula you will gwt the same result
    as broute force approach but time complexity will be O(Q+N)

    Input: nums = [0,0,0,0,0],   
    queries = [[1,3,2],[2,4,3],[0,2,-2]]

    [1,3,2] ->  {0,2,0,0,-2}
    [2,4,3] ->  {0,2,3,0,-2}
    [0,2,-2] ->  {-2,2,3,2,-2}

    cumulative sum {-2,0,3,5,3}

    Time Complexity: O(Q + N) (linear in the size of the queries and the array).
    Space Complexity: O(1) (in-place updates with no extra storage).

    
    code ->  
    vector<int> diff_array(vector<int> arr, vector<vector<int>> queries) {    
        int N = arr.size(); // Define array size
        for (auto &query : queries) {
            int L = query[0];
            int R = query[1];
            int X = query[2];
    
            arr[L] += X;
            if (R + 1 < N) { // Check for R + 1 being out of bounds
                arr[R + 1] -= X;
            }
        }
    
        // Cumulative sum to finalize the array
        for (int i = 1; i < N; i++) {
            arr[i] += arr[i - 1];
        }
        return arr;
    }
    
