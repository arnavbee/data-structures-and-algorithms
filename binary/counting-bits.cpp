    vector<int> result(n + 1);

        if(n == 0)
        return result;
        result[0] = 0;

        for(int i = 0; i <=n; i++){
            if(i%2 != 0){
                result[i] = result[i/2] + 1;
            }

            else {
                result[i] = result[i/2];
            }

        }

        return result;
        
    }