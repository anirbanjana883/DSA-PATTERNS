checking prime number 

approach 1:

bool isPrime(int number) {
    if (number <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i <= number; i++) {
        if (number % i == 0) {
            return false; // If divisible by any number other than 1 and itself
        }
    }
    return true;
}

approach 2: more optimied

bool isPrime(int number) {
    if (number <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i <= number/2; i++) {
        if (number % i == 0) {
            return false; // If divisible by any number other than 1 and itself
        }
    }
    return true;
}

approach 3: optimal

bool isPrime(int number) {
    if (number <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i*i <= number; i++) {
        if (number % i == 0) {
            return false; // If divisible by any number other than 1 and itself
        }
    }
    return true;
}

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

SIEVE OF ERATOSTHENES :

you will be give a number you need to all the number in between if they are prime or not 

broute force aproach : 
time complexity o(n*root(n))
you need to check each number in between to see if they are prime or nota
and put it into an array

sieve of eratosthenes : 
for time complexity check codestruwithmik vedio.........
time complexity O(n*log(log(n)))

let you are given input as n:

you will take (n+1) size array and 
>mark all as true
>when ever you get one prime number its multiple should be marked as false


class Solution {
    public:
      vector<int> sieveOfEratosthenes(int n) {
          // Write Your Code here
          vector<int>isPrime(n+1,true);
          for(int i=2;i<=n;i++){
              if(isPrime[i]==true){
                  for(int j=2;i*j<=n;j++){
                      isPrime[i*j]=false;
                  }
              }
          }
          
          vector<int>result;
          for(int i=2;i<=n;i++){
              if(isPrime[i]==true){
                  result.push_back(i);
              }
          }
          return result;
          
      }
  };

  little bit optimisatiion 

  // User function Template for C++
class Solution {
    public:
      vector<int> sieveOfEratosthenes(int n) {
          // Write Your Code here
          isPrime[0] = isPrime[1] = false;
          vector<bool>isPrime(n+1,true);
          for(int i=2;i*i<=n;i++){
              if(isPrime[i]==true){
                  for(int j=2;i*j<=n;j++){
                      isPrime[i*j]=false;
                  }
              }
          }
          
          vector<int>result;
          for(int i=2;i<=n;i++){
              if(isPrime[i]==true){
                  result.push_back(i);
              }
          }
          return result;
          
      }
  };
follow up question->

2523. Closest Prime Numbers in Range 

differnece 