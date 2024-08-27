  int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suff = 1;
        int n = nums.size();

        int ans = INT_MIN;

        for(int i = 0; i<n; i++){
           if(pre == 0) {
            pre = 1;
           }

           if(suff == 0){
            suff = 1;
           }

           pre = pre * nums[i];
           suff = suff * nums[n - i - 1];

           ans = max(ans, max(pre, suff));

           
        }

        return ans;
        
    }