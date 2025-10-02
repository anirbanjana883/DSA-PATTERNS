295. Find Median from Data Stream

class MedianFinder {
public:
    // time - 
    // space - o(n)
    // we require 2 heap 
    // we will divide data into two part 
    // left side maxheap
    // right side min heap
    priority_queue<int>left_max_heap;
    priority_queue<int,vector<int>,greater<int>>right_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) { // o(logn)
        if(left_max_heap.empty() || num < left_max_heap.top()){
            left_max_heap.push(num);
        }else{
            right_min_heap.push(num);
        }

        // always maintain left_max_heap size 1 less then right_min_heap
        if(abs((int) left_max_heap.size() - (int) right_min_heap.size()) > 1){
            // means left_max_heap has more then one extra elem then right
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }else if(left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() { // o(1)
        // if both heap has same no of elm 
        // -> even no of element 
        if(left_max_heap.size() == right_min_heap.size()){
            double mean = (left_max_heap.top() + right_min_heap.top()) / 2.0;
            return mean;
        }
        return left_max_heap.top();
    }
};

