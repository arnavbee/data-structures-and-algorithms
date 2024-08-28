  int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n - 1;

        int maxWater = 0;

        while(i<j){
            int w = j - i;
            int h = min(height[i], height[j]);

            int area = h * w;

            maxWater = max(maxWater, area);

            if(height[i] > height[j]){
                j--;
            }

            else {
                i++;
            }


        }
        return maxWater;
    }