    int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int totalSum = n * (n + 1) / 2;
    int arraySum = 0;
    int missing;

    for(int num: nums){
        arraySum += num;
    }
    return totalSum - arraySum;
        
    }