int maxArea(vector<int>& height) {
    int n = height.size();

    int i = 0;
    int j = n - 1;

    int maxWater = 0;

    // Iterate until the two pointers meet
    while (i < j) {
       
        // Calculate the width of the container formed by the two pointers
        int w = j - i;

        // Calculate the height of the container, which is the smaller of the two heights
        int h = min(height[i], height[j]);

        int area = h * w;

        // Update maxWater if the current area is larger than the previous max
        maxWater = max(maxWater, area);

        // Move the pointer pointing to the shorter height inward, to try and find a taller container
        if (height[i] > height[j]) {
            j--;
        } else {
            i++;
        }
    }

    return maxWater;
}
