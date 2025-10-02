                            TWO POINTER AND SLIDING WINDOW TECHNIQUE
##############################################################################################################

1.constant window:
    arr={-1 2 3 3 5 -1} k=4(element in window)
    initialze l=0 , r=k-1
    sum1=7 {-1 2 3 3 }
    sum2=13 { 2 3 3 5 }
    sum=10  { 3 3 5 -1}

    so the loop ends at when r is at lat element 
    TEMPLATE=>

    first calaulate sum(for loop)
    while(r<size){
        sum=sum-arr[i];
        l++;
        r++;
        sum=sum+arr[r];

        maxSum=max(maxSum,sum);
    }
##############################################################################################################

2.longest subarray/substring: [most important]
    *broute force 
    *better
    *optimal


    longest subarray with sum<=k
    arr={2 5 1 7 10} subarray-any consecutive portion of the array
    
    *broute force : generate all the subarray

        t.c O(N^2)
        s.c O(1)  depands on question

        maxLength=0;
        for(i=0;i<n;i++){
            sum=0;
            for(j=i;j<n;j++){
                sum=sum+arr[j];
                if(sum<=k){
                    maxLength=max(maxLength,j-i+1)
                }
                optimisation (if applicable)
                if(sum>k) break;
            } 
        }
        print(maxLength);

    *better : two pointer and sliding window
    
        t.c O(2*N)
        s.c O(1)  depands on question

        1. expand r
        2. shrink l

        expand till the condition does not violet
        once the condition is violeted 
        shrink till the condition meet again

        note that we start with window size 1(l=0,r=0)

        l=0 , r=0,sum=0,maxLen=0;
        while(r<size){

            sum=sum+arr[i];

            while(sum>k){  // invalid condititon check and increment
                sum=sum-arr[i];
                l=l+1;
            }

            if(sum<=k){
                maxLen=max(maxLen,r-l+1);
            }

            r=r+1;
        }
        print(maxLen)
        
    *optimal : applicable only we are asked max length
               not applicable when we are asked to print the subarray {then better approach will work}
    
        t.c O(N)
        s.c O(1) depands on question

        NOTICE, one thing when the subarray was violeting the condition 
        we are shrinking the subarray till the condition meet in better approach 
        but in that process we are shrinking till smallest length(which is obeying the condition) 

        BUT why to shrink till smallest ??? let we  got max length =3 next time 
        when we shrink we will shrink only upto length 3 bcoz we have to find greater length 
        may be 4,5,6 ..............  


        l=0 , r=0,sum=0,maxLen=0;
        while(r<size){

            sum=sum+arr[i];

            if (sum>k){  // invalid condititon check and increment
                sum=sum-arr[i];
                l=l+1;
            }

            if(sum<=k){
                maxLen=max(maxLen,r-l+1);
            }

            r=r+1;
        }
        print(maxLen)

##############################################################################################################
  
3.no of subarray with <condition>
        |
        |
        |--------------> these problems can be solved using pattern2 [but difficult]

        example: no of subarrays with < sum = k >   

        for [condition] which are [ constant ] it is tough 

        so what we can do is 

        x=no of subarray with sum <= k
        y=no of subarray with sum <= k-1
        ans =(x-y)

##############################################################################################################

4.shortest / minimum window <condition>
        rare question not much important

        first get the window which is valid 
        and then start shrinking till the window is valid 
        and get the smallest valid window