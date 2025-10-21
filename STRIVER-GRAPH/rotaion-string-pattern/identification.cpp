How to identify this pattern ::

1 . asks about numbers or words
2 . all digit or char can be chnage din the same way
3 . you have to reach a trget number 
4 . in minimum steps or number 
5 . or find max min of these states
6 . often leads to finite number of states
7 . we can solve the problem using dfs or bfs 


similar problems 

1. minimum genetic mutation (done)
2. open the lock (done)
3. word ladder 1 (done)
4. word ladder 2 (done)
5. sliding puzzle
6. lexicogrphically smallest string after operation (done)
7. Sequential Digits (Leetcode)
8. Print all Jumping Numbers smaller than or equal to a given value [GFG]


// right shift( rotate  right ) ans string b times in a cool fashion 

abc -> cba -> acb 

void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }