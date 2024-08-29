#include <vector>
#include <map>
#include <algorithm>  // For the max function

int longestSubarrayWithSumK(std::vector<int> a, long long k) {
    
    std::map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i < a.size(); i++){
        sum += a[i];

        // Check if the current sum is equal to k
        if(sum == k){
            maxLen = std::max(maxLen, i + 1);
        }

        // Calculate the remainder
        long long rem = sum - k;

        // If remainder is found in map, update maxLen
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = std::max(maxLen, len);
        }

        // Store the first occurrence of the sum
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}




/// Optimal Solution 



int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Initialize two pointers: left and right, both starting at the beginning of the array
    int left = 0, right = 0;

    // Initialize sum with the first element of the array
    long long sum = a[0];

    // Variable to store the maximum length of subarray with sum k
    int maxLen = 0;

    // Get the size of the array
    int n = a.size();

    // Start sliding the window using the two pointers
    while(right < n) {

        // While the sum is greater than k, move the left pointer to the right
        // and subtract the elements that are no longer in the window from the sum
        while(left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // If the sum equals k, update maxLen to the maximum length found so far
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move the right pointer to the right to expand the window
        right++;

        // Add the new element to the sum if right hasn't gone out of bounds
        if(right < n) sum += a[right];
    }

    // Return the maximum length of subarray with sum k
    return maxLen;
}
