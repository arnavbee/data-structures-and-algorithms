class Solution {
public:
    int cnt = 0;

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;  // temporary array
        int left = low;    // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr

        // Storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        // Transferring all elements from temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);      // left half
        mergeSort(arr, mid + 1, high); // right half
        countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);    // merging sorted halves
    }

    int reversePairs(vector<int>& nums) {
        cnt = 0; // Reset the count for each new call
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
