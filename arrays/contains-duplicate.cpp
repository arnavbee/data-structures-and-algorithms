    /// MAP APPROACH
    
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int num: nums){
            mp[num]++;

            if(mp[num] > 1){
                return true;
            }
        }

        return false;
        
    }



    //SET APPROACH

       bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {

            if (seen.find(num) != NULL) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};



/// WITHOUT SET MAP APPROACH

   bool containsDuplicate(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    int n = nums.size();

    for(int i = 1; i < n; i++){
        if(nums[i] == nums[i-1]){
            return true;
        }
    }
    
    return false;

        
    }

