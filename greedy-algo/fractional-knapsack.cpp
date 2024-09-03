static bool comp(Item val1, Item val2) {
        return (double(val1.value) / val1.weight) > (double(val2.value) / val2.weight);
    }
    
double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, comp);
        
        double totVal = 0.0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= w) {
                totVal += arr[i].value;
                w -= arr[i].weight;
            } else {
                totVal += (double(arr[i].value) / arr[i].weight) * w;
                break;
            }
        }
    return totVal;
}