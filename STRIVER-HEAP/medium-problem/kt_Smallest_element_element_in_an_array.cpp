Kth smallest element in an array 

Solution 1: Sorting the Array

void kth_Largest_And_Smallest_By_AscendingOrder(vector<int>&arr, int k) {

    sort(arr.begin(), arr.end())  ;
    int n = arr.size()  ;

    cout << "kth Largest element " << arr[n - k] << ", " << 
    "kth Smallest element " << arr[k - 1];
}

Solution 2: Using Heap

class Solution {

public:

    void kth_Largest_MaxHeap(vector<int>&arr, int k) {

        priority_queue<int>pq ;
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }

        int f = k - 1 ;

        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }

        cout << "Kth Largest element " << pq.top() << "\n"  ;
    }

    void kth_Smallest_MinHeap(vector<int>&arr, int k) {

        priority_queue<int, vector<int>, greater<int>>pq ;
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i])  ;
        }

        int f = k - 1 ;

        while (f > 0) {
            pq.pop()  ;
            f-- ;
        }

        cout << "Kth Smallest element " << pq.top() << "\n"  ;
    }
} ;

Solution 3: Using Quickselect Algorithm

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    int l = left + 1;
    int r = right;
    while (l <= r) {
        if (arr[l] > pivot && arr[r] < pivot) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        if (arr[l] <= pivot) {
            l++;
        }
        if (arr[r] >= pivot) {
            r--;
        }
    }
    swap(arr[left], arr[r]);
    return r;
}

int kth_Smallest_Element(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1, kth;
    while (true) {
        int idx = partition(arr, left, right);
        if (idx == k - 1) {
            kth = arr[idx];
            break;
        }
        if (idx < k - 1) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }
    return kth;
}