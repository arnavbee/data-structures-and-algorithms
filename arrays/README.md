# Arrays

## 1. Longest Consecutive Sequence

Solution: [text](https://www.youtube.com/watch?v=CBFn7zWMOBQ)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }

        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i] - 1) != s.end()){
                continue;
            }

        else {
            int count = 0;
            int current = nums[i];
            while(s.find(current)!=s.end()){
                count++;
                current++;
            }

            ans = max(ans, count);
        }
        }

        return ans;

    }
};

## 2. Container with Most Water

Leetcode: [link](https://leetcode.com/problems/container-with-most-water/)



## 3. Longest Substring w/o Repeating Characters

Dry Run 

Let's do a dry run on the string "cadbzabcd":

Initial Setup:

str = "cadbzabcd"

set = {} (empty initially)
i = 0
j = 0
maxans = 0

- Iteration 1 (j = 0):
Character: 'c'
'c' is not in set, so:
Add 'c' to set: set = {'c'}
Update maxans = max(0, 0 - 0 + 1) = 1
Move j to 1

- Iteration 2 (j = 1):
Character: 'a'
'a' is not in set, so:
Add 'a' to set: set = {'c', 'a'}
Update maxans = max(1, 1 - 0 + 1) = 2
Move j to 2

- Iteration 3 (j = 2):
Character: 'd'
'd' is not in set, so:
Add 'd' to set: set = {'c', 'a', 'd'}
Update maxans = max(2, 2 - 0 + 1) = 3
Move j to 3

- Iteration 4 (j = 3):
Character: 'b'
'b' is not in set, so:
Add 'b' to set: set = {'c', 'a', 'd', 'b'}
Update maxans = max(3, 3 - 0 + 1) = 4
Move j to 4

- Iteration 5 (j = 4):
Character: 'z'
'z' is not in set, so:
Add 'z' to set: set = {'c', 'a', 'd', 'b', 'z'}
Update maxans = max(4, 4 - 0 + 1) = 5
Move j to 5

- Iteration 6 (j = 5):
Character: 'a'
'a' is in set (duplicate found), so:
Shrink the window by removing the character at i = 0 (which is 'c') from the set: set = {'a', 'd', 'b', 'z'}
Move i to 1 (next start index).
Still a duplicate: Remove 'a' from the set: set = {'d', 'b', 'z'}
Move i to 2 (next start index).
No more duplicates, add 'a' to set: set = {'d', 'b', 'z', 'a'}.
maxans remains 5.
Move j to 6.

- Iteration 7 (j = 6)
Character: 'b'
'b' is in set (duplicate found), so:
Shrink the window by removing 'd' from the set: set = {'b', 'z', 'a'}
Move i to 3.
Still a duplicate: Remove 'b' from the set: set = {'z', 'a'}
Move i to 4.
No more duplicates, add 'b' to set: set = {'z', 'a', 'b'}.
maxans remains 5.
Move j to 7.

- Iteration 8 (j = 7)
Character: 'c'
'c' is not in set, so:
Add 'c' to set: set = {'z', 'a', 'b', 'c'}
Update maxans = max(5, 7 - 4 + 1) = 5
Move j to 8.

- Iteration 9 (j = 8)
Character: 'd'
'd' is not in set, so:
Add 'd' to set: set = {'z', 'a', 'b', 'c', 'd'}
Update maxans = max(5, 8 - 4 + 1) = 5
j reaches the end of the string.

- Final Result:

The maximum length of a substring without repeating characters is 5, corresponding to the substring "cadbz".



## 4. No. of subarrays with given XOR as "k"

Let's do a dry run of the code using the array [4, 2, 2, 6, 4] with k = 6.

Initial State:
a = [4, 2, 2, 6, 4]
k = 6
xr = 0 (initial XOR value)
mpp = {0: 1} (map initialized with {0: 1})
cnt = 0 (initial count of subarrays with XOR equal to k)

- Iteration 1 (i = 0, a[0] = 4):

Compute xr:

xr = xr ^ a[0] = 0 ^ 4 = 4

Calculate x:

x = xr ^ k = 4 ^ 6 = 2

Update cnt:

mpp[2] is not in the map, so cnt remains 0.

Update the map:

mpp[xr] = mpp[4]++ => mpp = {0: 1, 4: 1}


- Iteration 2 (i = 1, a[1] = 2):

Compute xr:

xr = xr ^ a[1] = 4 ^ 2 = 6

Calculate x:

x = xr ^ k = 6 ^ 6 = 0

Update cnt:

mpp[0] = 1, so cnt = cnt + mpp[0] = 0 + 1 = 1

Update the map:

mpp[xr] = mpp[6]++ => mpp = {0: 1, 4: 1, 6: 1}



- Iteration 3 (i = 2, a[2] = 2):

Compute xr:

xr = xr ^ a[2] = 6 ^ 2 = 4

Calculate x:

x = xr ^ k = 4 ^ 6 = 2

Update cnt:

mpp[2] is not in the map, so cnt remains 1.

Update the map:

mpp[xr] = mpp[4]++ => mpp = {0: 1, 4: 2, 6: 1}



- Iteration 4 (i = 3, a[3] = 6):

Compute xr:

xr = xr ^ a[3] = 4 ^ 6 = 2

Calculate x:

x = xr ^ k = 2 ^ 6 = 4

Update cnt:

mpp[4] = 2, so cnt = cnt + mpp[4] = 1 + 2 = 3

Update the map:

mpp[xr] = mpp[2]++ => mpp = {0: 1, 4: 2, 6: 1, 2: 1}



- Iteration 5 (i = 4, a[4] = 4):

Compute xr:

xr = xr ^ a[4] = 2 ^ 4 = 6

Calculate x:

x = xr ^ k = 6 ^ 6 = 0

Update cnt:

mpp[0] = 1, so cnt = cnt + mpp[0] = 3 + 1 = 4

Update the map:

mpp[xr] = mpp[6]++ => mpp = {0: 1, 4: 2, 6: 2, 2: 1}

- Final Result:
After processing the entire array, the final value of cnt is 4.
Answer: There are 4 subarrays with XOR equal to k = 6.

Subarrays:
[4, 2] (XOR = 6)
[2, 2, 6] (XOR = 6)
[6] (XOR = 6)
[4, 2, 2, 6] (XOR = 6)

Thus, the function correctly counts 4 subarrays with an XOR sum of 6.






