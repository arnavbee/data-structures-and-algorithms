int subarraysWithSumK(vector<int> a, int k) {
    int xr = 0; // This will store the XOR of the elements so far.
    map<int, int> mpp; // This map will keep track of the frequency of XOR values.
    mpp[0] = 1; // Initialize the map with 0 XOR having one occurrence. This handles cases where a subarray itself has XOR equal to `k`.

    int cnt = 0; // Initialize the count of subarrays with XOR equal to `k`.

    for (int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i]; // Compute the XOR up to the current element.

        int x = xr ^ k; // Calculate the value needed to achieve XOR `k` with the current XOR.

        cnt += mpp[x]; // If the required XOR exists in the map, add its frequency to the count.

        mpp[xr]++; // Update the map with the current XOR value.
    }

    return cnt; // Return the total count of subarrays with XOR equal to `k`.
}
