 static bool comp(vector<int>& a, vector<int>& b) {
            return a[1] < b[1];  
            }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n == 0) return 0;

        int cnt = 1;

       sort(intervals.begin(), intervals.end(), comp);            
       int lastEndTime = intervals[0][1];

        for(int i = 1; i<n; i++){
            if(intervals[i][0] >= lastEndTime){
                cnt = cnt + 1;
                lastEndTime = intervals[i][1];
            }
        }

        return n - cnt;


    }