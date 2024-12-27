// Question 1
#include <bits/stdc++.h>
using namespace std;
int searchNumber(int k, vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) return i + 1;
    }
    return -1;
}

// Question 2
bool sortedArraySearch(vector<int>& arr, int k) {
    return binary_search(arr.begin(), arr.end(), k);
}

// Question 3
vector<int> findTargetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) result.push_back(i);
    }
    return result;
}

// Question 4
int searchInsertPosition(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

// Question 5
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq;
    for (int num : arr1) freq[num]++;
    vector<int> result;
    for (int num : arr2) {
        while (freq[num]--) result.push_back(num);
    }
    vector<int> rest;
    for (auto& [key, val] : freq) {
        while (val--) rest.push_back(key);
    }
    sort(rest.begin(), rest.end());
    result.insert(result.end(), rest.begin(), rest.end());
    return result;
}

// Question 6
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int moves = 0;
    for (int i = 0; i < seats.size(); i++) {
        moves += abs(seats[i] - students[i]);
    }
    return moves;
}

// Question 7
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result;
    for (int num : nums) result.push_back(num * num);
    sort(result.begin(), result.end());
    return result;
}

// Question 8
vector<int> commonInThreeSortedArrays(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    vector<int> result;
    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            if (result.empty() || result.back() != arr1[i]) result.push_back(arr1[i]);
            i++; j++; k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    return result.empty() ? vector<int>{-1} : result;
}

// Question 9
vector<int> sortEvenOddIndices(vector<int>& nums) {
    vector<int> evens, odds;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) evens.push_back(nums[i]);
        else odds.push_back(nums[i]);
    }
    sort(evens.begin(), evens.end());
    sort(odds.rbegin(), odds.rend());
    vector<int> result(nums.size());
    int e = 0, o = 0;
    for (int i = 0; i < nums.size(); i++) {
        result[i] = (i % 2 == 0) ? evens[e++] : odds[o++];
    }
    return result;
}

// Question 10
pair<int, int> leftMostAndRightMostIndex(vector<int>& nums, int x) {
    auto lower = lower_bound(nums.begin(), nums.end(), x);
    auto upper = upper_bound(nums.begin(), nums.end(), x);
    if (lower == nums.end() || *lower != x) return {-1, -1};
    return {lower - nums.begin(), upper - nums.begin() - 1};
}

// Question 11
bool searchIn2DMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = m * n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int val = matrix[mid / n][mid % n];
        if (val == target) return true;
        else if (val < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// Question 12
vector<int> firstAndLastPosition(vector<int>& nums, int target) {
    int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    if (start <= end && start < nums.size() && nums[start] == target) return {start, end};
    return {-1, -1};
}

// Question 13
int findMinInRotatedArray(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }
    return nums[low];
}

// Question 14
int smallestPositiveMissingNumber(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) return i + 1;
    }
    return n + 1;
}

// Question 15
int pairSumClosestToZero(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    int closestSum = INT_MAX;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < abs(closestSum) || (abs(sum) == abs(closestSum) && sum > closestSum)) {
            closestSum = sum;
        }
        if (sum < 0) left++;
        else right--;
    }
    return closestSum;
}

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Problem 16: Sort Items by Groups Respecting Dependencies
vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    vector<int> result;
    vector<vector<int>> groupItems(m + n);
    vector<int> groupIndegree(m + n, 0), itemIndegree(n, 0);
    vector<vector<int>> groupGraph(m + n), itemGraph(n);

    // Assign unique group IDs to standalone items
    for (int i = 0; i < n; i++) {
        if (group[i] == -1) group[i] = m++;
        groupItems[group[i]].push_back(i);
    }

    // Build graphs for items and groups
    for (int i = 0; i < n; i++) {
        for (int before : beforeItems[i]) {
            itemGraph[before].push_back(i);
            itemIndegree[i]++;
            if (group[before] != group[i]) {
                groupGraph[group[before]].push_back(group[i]);
                groupIndegree[group[i]]++;
            }
        }
    }

    // Topological sort for groups
    vector<int> sortedGroups;
    queue<int> groupQueue;
    for (int i = 0; i < m; i++) {
        if (groupIndegree[i] == 0) groupQueue.push(i);
    }
    while (!groupQueue.empty()) {
        int currGroup = groupQueue.front();
        groupQueue.pop();
        sortedGroups.push_back(currGroup);
        for (int neighbor : groupGraph[currGroup]) {
            if (--groupIndegree[neighbor] == 0) groupQueue.push(neighbor);
        }
    }

    if (sortedGroups.size() != m) return {};

    // Topological sort for items within each group
    for (int grp : sortedGroups) {
        vector<int> sortedItems;
        queue<int> itemQueue;
        for (int item : groupItems[grp]) {
            if (itemIndegree[item] == 0) itemQueue.push(item);
        }
        while (!itemQueue.empty()) {
            int currItem = itemQueue.front();
            itemQueue.pop();
            sortedItems.push_back(currItem);
            for (int neighbor : itemGraph[currItem]) {
                if (--itemIndegree[neighbor] == 0) itemQueue.push(neighbor);
            }
        }
        if (sortedItems.size() != groupItems[grp].size()) return {};
        result.insert(result.end(), sortedItems.begin(), sortedItems.end());
    }

    return result;
}

// Problem 17: Find the Kth Smallest Sum of a Matrix With Sorted Rows
int kthSmallest(vector<vector<int>>& mat, int k) {
    priority_queue<int> pq;
    pq.push(0);
    for (auto& row : mat) {
        priority_queue<int> nextPq;
        while (!pq.empty()) {
            int currSum = pq.top();
            pq.pop();
            for (int num : row) {
                nextPq.push(currSum + num);
                if (nextPq.size() > k) nextPq.pop();
            }
        }
        pq.swap(nextPq);
    }
    return pq.top();
}

// Problem 18: Merge k Sorted Lists
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    for (auto list : lists) {
        if (list) pq.push(list);
    }
    ListNode dummy(0), *tail = &dummy;
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = node;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

// Problem 19: Max Chunks To Make Sorted II
int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    vector<int> maxLeft(n), minRight(n);

    maxLeft[0] = arr[0];
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i - 1], arr[i]);
    }

    minRight[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        minRight[i] = min(minRight[i + 1], arr[i]);
    }

    int chunks = 0;
    for (int i = 0; i < n - 1; i++) {
        if (maxLeft[i] <= minRight[i + 1]) chunks++;
    }

    return chunks + 1;
}

// Ques 20

#include <vector>
#include <algorithm>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    vector<int> max_left(n), min_right(n);
    max_left[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        max_left[i] = max(max_left[i - 1], arr[i]);
    }
    min_right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        min_right[i] = min(min_right[i + 1], arr[i]);
    }
    int chunks = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (max_left[i] <= min_right[i + 1]) {
            chunks++;
        }
    }
    return chunks + 1;
}
