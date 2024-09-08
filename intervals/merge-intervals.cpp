 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        
        vector<vector<int>> result;


        for(int i = 0; i < n; i++){
           
            if(end >= intervals[i][0]){
            end = max(end, intervals[i][1]);
            }

            else  {
               result.push_back({start, end});
               start = intervals[i][0];
               end = intervals[i][1];
            }
        }

        result.push_back({start, end});

        return result;
        
    }



///



