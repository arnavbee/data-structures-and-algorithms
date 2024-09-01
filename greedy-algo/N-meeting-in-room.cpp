 struct Data {
        int start;
        int end;
        int pos;
        
    };
        
        
    static bool comp(Data val1, Data val2){
        return val1.end < val2.end;
    }
  
    
    int maxMeetings(int n, int start[], int end[]) {
        Data arr[n];
        
        for(int i = 0; i < n; i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1;
        }
        
        sort(arr, arr + n, comp);
        
        int cnt = 1;
        int freeTime = arr[0].end;
        
        for(int i = 1; i <= n - 1; i++){
            if(arr[i].start > freeTime){
                cnt++;
                freeTime = arr[i].end;
            }
        }
        
        return cnt;
    }