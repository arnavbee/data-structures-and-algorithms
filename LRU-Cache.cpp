

// class LRUCache {
// public:
//     list<int> dll; 
//     map<int, pair<list<int>::iterator, int>> cache; 
//     int capacity;
    
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }
    
//     void makeMostRecentlyUsed(int key) {
//         dll.erase(cache[key].first);
//         dll.push_front(key);
//         cache[key].first = dll.begin();
//     }
    
//     int get(int key) {
//         if(!cache.count(key))
//             return -1;
        
//         makeMostRecentlyUsed(key);
//         return cache[key].second;
//     }
    
//     void put(int key, int value) {
//         if(cache.count(key)) {
//             cache[key].second = value;
//             makeMostRecentlyUsed(key);
//         } else {
//             dll.push_front(key);
//             cache[key] = {dll.begin(), value};
//             capacity--;
//         }
        
//         if(capacity < 0) {
//             cache.erase(dll.back());
//             dll.pop_back();
//             capacity++;
//         }
//     }
// };