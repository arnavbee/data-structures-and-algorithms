    int findPlatform(int arr[], int dep[], int n)
     {
         sort(arr, arr + n);
         sort(dep, dep + n);
         
         int i = 0;
         int j = 0;
         
         
         int cnt = 0;
         
         int maxCount = 0;
         
         while(i < n && j < n){
             if(arr[i] <= dep[j]) {
             cnt++;
             i++; 
             }
           
             else{
                 cnt--;
                 j++;
             }
             
             maxCount = max(maxCount, cnt);
             
         }
         return maxCount;
     
    }