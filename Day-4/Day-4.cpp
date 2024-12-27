// Ques 1

#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    } else {
        return edges[0][1];
    }
}

int main() {
    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {4, 2}};
    vector<vector<int>> edges2 = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};

    int center1 = findCenter(edges1);
    int center2 = findCenter(edges2);

    cout << "Center of the first graph: " << center1 << endl;
    cout << "Center of the second graph: " << center2 << endl;

    return 0;
}

// Ques 2

#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> inDegree(n + 1, 0);
    vector<int> outDegree(n + 1, 0);
    for (auto& t : trust) {
        outDegree[t[0]]++;
        inDegree[t[1]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == n - 1 && outDegree[i] == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> trust1 = {{1, 2}};
    vector<vector<int>> trust2 = {{1, 3}, {2, 3}};
    vector<vector<int>> trust3 = {{1, 3}, {2, 3}, {3, 1}};

    int judge1 = findJudge(2, trust1);
    int judge2 = findJudge(3, trust2);
    int judge3 = findJudge(3, trust3);

    return 0;
}


// Ques 3

#include <vector>
using namespace std;

void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != originalColor || image[sr][sc] == color) {
        return;
    }
    image[sr][sc] = color;
    floodFillHelper(image, sr + 1, sc, color, originalColor);
    floodFillHelper(image, sr - 1, sc, color, originalColor);
    floodFillHelper(image, sr, sc + 1, color, originalColor);
    floodFillHelper(image, sr, sc - 1, color, originalColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int originalColor = image[sr][sc];
    if (originalColor != color) {
        floodFillHelper(image, sr, sc, color, originalColor);
    }
    return image;
}

int main() {
    vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> image2 = {{0, 0, 0}, {0, 0, 0}};

    vector<vector<int>> result1 = floodFill(image1, 1, 1, 2);
    vector<vector<int>> result2 = floodFill(image2, 0, 0, 0);

    return 0;
}


// Ques 4

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == destination) {
            return true;
        }
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};

    bool result1 = validPath(3, edges1, 0, 2);
    bool result2 = validPath(6, edges2, 0, 5);

    return 0;
}

// Ques 5

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsOfGraph(vector<vector<int>>& adj) {
    vector<int> result;
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> result = bfsOfGraph(adj);
    
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}


// Ques 6

#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    vector<int> result;
    vector<bool> visited(adj.size(), false);
    dfs(0, adj, visited, result);
    return result;
}

int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> result = dfsOfGraph(adj);
    
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}

// Ques 7

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> result(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                result[i][j] = 0;
            }
        }
    }

    vector<int> directions = {-1, 0, 1, 0, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i], ny = y + directions[i + 1];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && result[nx][ny] == -1) {
                result[nx][ny] = result[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> result = updateMatrix(mat);

    for (auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

// Ques 8

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0), result;
    vector<vector<int>> adj(numCourses);

    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        indegree[pre[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int course = q.front();
        q.pop();
        result.push_back(course);

        for (int next : adj[course]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return result.size() == numCourses ? result : vector<int>();
}

int main() {
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;
    vector<int> order = findOrder(numCourses, prerequisites);

    for (int course : order) {
        cout << course << " ";
    }
    return 0;
}

// Ques 9

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
    if (index == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = dfs(board, word, i + 1, j, index + 1) ||
                 dfs(board, word, i - 1, j, index + 1) ||
                 dfs(board, word, i, j + 1, index + 1) ||
                 dfs(board, word, i, j - 1, index + 1);

    board[i][j] = temp;
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << (exist(board, word) ? "true" : "false") << endl;
    return 0;
}

// Ques 10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    
    vector<vector<int>> graph(n);
    vector<int> degree(n, 0);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) q.push(i);
    }

    while (n > 2) {
        int size = q.size();
        n -= size;
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (--degree[neighbor] == 1) q.push(neighbor);
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

int main() {
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    int n = 4;
    vector<int> result = findMinHeightTrees(n, edges);

    for (int root : result) {
        cout << root << " ";
    }
    return 0;
}


// Ques 11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, string> emailToName;

    string find(string x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(string x, string y) {
        string rootX = find(x);
        string rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (emailToName.find(email) == emailToName.end()) {
                    emailToName[email] = name;
                    parent[email] = email;
                }
                unionSets(account[1], email);
            }
        }

        unordered_map<string, vector<string>> merged;
        for (auto& pair : emailToName) {
            string root = find(pair.first);
            merged[root].push_back(pair.first);
        }

        vector<vector<string>> result;
        for (auto& pair : merged) {
            vector<string> emails = pair.second;
            sort(emails.begin(), emails.end());
            vector<string> account = {emailToName[emails[0]]};
            account.insert(account.end(), emails.begin(), emails.end());
            result.push_back(account);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    vector<vector<string>> result = solution.accountsMerge(accounts);

    for (auto& account : result) {
        for (auto& str : account) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}

// Ques 12

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            minutes++;
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    vector<vector<int>> grid3 = {{0,2}};

    cout << solution.orangesRotting(grid1) << endl;  // Output: 4
    cout << solution.orangesRotting(grid2) << endl;  // Output: -1
    cout << solution.orangesRotting(grid3) << endl;  // Output: 0

    return 0;
}


// Ques 13

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;
        
        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& ocean) {
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                ocean[x][y] = true;
                for (auto& dir : directions) {
                    int nx = x + dir.first, ny = y + dir.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !ocean[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                        q.push({nx, ny});
                    }
                }
            }
        };
        
        queue<pair<int, int>> pacificQueue, atlanticQueue;
        for (int i = 0; i < m; ++i) {
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, n - 1});
        }
        for (int j = 0; j < n; ++j) {
            pacificQueue.push({0, j});
            atlanticQueue.push({m - 1, j});
        }

        bfs(pacificQueue, pacific);
        bfs(atlanticQueue, atlantic);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> heights1 = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> heights2 = {{1}};
    
    vector<vector<int>> result1 = solution.pacificAtlantic(heights1);
    vector<vector<int>> result2 = solution.pacificAtlantic(heights2);

    for (auto& res : result1) {
        cout << "[" << res[0] << "," << res[1] << "] ";
    }
    cout << endl;

    for (auto& res : result2) {
        cout << "[" << res[0] << "," << res[1] << "] ";
    }
    cout << endl;

    return 0;
}


// Ques 14

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        
        auto dfs = [&](int x, int y, auto&& dfsRef) -> int {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;
            grid[x][y] = 0;
            int area = 1;
            area += dfsRef(x + 1, y, dfsRef);
            area += dfsRef(x - 1, y, dfsRef);
            area += dfsRef(x, y + 1, dfsRef);
            area += dfsRef(x, y - 1, dfsRef);
            return area;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, dfs));
                }
            }
        }
        
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    vector<vector<int>> grid2 = {{0,0,0,0,0,0,0,0}};
    
    cout << solution.maxAreaOfIsland(grid1) << endl;
    cout << solution.maxAreaOfIsland(grid2) << endl;

    return 0;
}


// Ques 15

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    double dfs(const string& start, const string& end, unordered_map<string, unordered_map<string, double>>& graph, unordered_map<string, bool>& visited) {
        if (graph[start].find(end) != graph[start].end()) {
            return graph[start][end];
        }
        
        for (auto& neighbor : graph[start]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                double result = dfs(neighbor.first, end, graph, visited);
                if (result != -1.0) {
                    return result * neighbor.second;
                }
            }
        }
        
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            double value = values[i];
            graph[A][B] = value;
            graph[B][A] = 1.0 / value;
        }
        
        vector<double> result;
        for (const auto& query : queries) {
            const string& C = query[0];
            const string& D = query[1];
            
            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                result.push_back(-1.0);
            } else {
                unordered_map<string, bool> visited;
                visited[C] = true;
                result.push_back(dfs(C, D, graph, visited));
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    vector<vector<string>> equations1 = {{"a","b"}, {"b","c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a","c"}, {"b","a"}, {"a","e"}, {"a","a"}, {"x","x"}};
    
    vector<vector<string>> equations2 = {{"a","b"}, {"b","c"}, {"bc","cd"}};
    vector<double> values2 = {1.5, 2.5, 5.0};
    vector<vector<string>> queries2 = {{"a","c"}, {"c","b"}, {"bc","cd"}, {"cd","bc"}};
    
    vector<vector<string>> equations3 = {{"a","b"}};
    vector<double> values3 = {0.5};
    vector<vector<string>> queries3 = {{"a","b"}, {"b","a"}, {"a","c"}, {"x","y"}};
    
    vector<double> result1 = solution.calcEquation(equations1, values1, queries1);
    vector<double> result2 = solution.calcEquation(equations2, values2, queries2);
    vector<double> result3 = solution.calcEquation(equations3, values3, queries3);
    
    for (double res : result1) {
        cout << res << " ";
    }
    cout << endl;
    
    for (double res : result2) {
        cout << res << " ";
    }
    cout << endl;
    
    for (double res : result3) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

// Ques 16

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].push_back({v, w});
        }
        
        // Create a distance array to track the minimum time for each node
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        // Min-heap to perform Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        while (!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (currDist > dist[node]) {
                continue;
            }
            
            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        // Find the maximum time it takes for all nodes to receive the signal
        int maxDist = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            maxDist = max(maxDist, dist[i]);
        }
        
        return maxDist;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> times1 = {{2,1,1},{2,3,1},{3,4,1}};
    int n1 = 4, k1 = 2;
    cout << solution.networkDelayTime(times1, n1, k1) << endl;  // Output: 2
    
    vector<vector<int>> times2 = {{1,2,1}};
    int n2 = 2, k2 = 1;
    cout << solution.networkDelayTime(times2, n2, k2) << endl;  // Output: 1
    
    vector<vector<int>> times3 = {{1,2,1}};
    int n3 = 2, k3 = 2;
    cout << solution.networkDelayTime(times3, n3, k3) << endl;  // Output: -1
    
    return 0;
}


// Ques 17

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            result.push_back(path);
        } else {
            for (int neighbor : graph[node]) {
                dfs(neighbor, graph, path, result);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(0, graph, path, result);
        return result;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> graph1 = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> result1 = solution.allPathsSourceTarget(graph1);
    for (const auto& path : result1) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    vector<vector<int>> graph2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    vector<vector<int>> result2 = solution.allPathsSourceTarget(graph2);
    for (const auto& path : result2) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}


// Ques 18

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] != node) {
            parent[node] = findParent(parent[node], parent);
        }
        return parent[node];
    }

    void unionNodes(int node1, int node2, vector<int>& parent, vector<int>& rank) {
        int root1 = findParent(node1, parent);
        int root2 = findParent(node2, parent);
        
        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if (findParent(u, parent) == findParent(v, parent)) {
                return edges[i];
            }
            unionNodes(u, v, parent, rank);
        }
        
        return {};
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> result1 = solution.findRedundantConnection(edges1);
    cout << result1[0] << " " << result1[1] << endl;

    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<int> result2 = solution.findRedundantConnection(edges2);
    cout << result2[0] << " " << result2[1] << endl;

    return 0;
}


// Ques 19

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;  // mark as visited
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n - 1 && y == n - 1) return steps;

                for (auto& dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;  // mark as visited
                        q.push({nx, ny});
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{0, 1}, {1, 0}};
    cout << solution.shortestPathBinaryMatrix(grid1) << endl;  // Output: 2

    vector<vector<int>> grid2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << solution.shortestPathBinaryMatrix(grid2) << endl;  // Output: 4

    vector<vector<int>> grid3 = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << solution.shortestPathBinaryMatrix(grid3) << endl;  // Output: -1

    return 0;
}


// Ques 20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        if (size[rootX] > size[rootY]) swap(rootX, rootY);
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
        return true;
    }

private:
    vector<int> parent, size;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind aliceUF(n), bobUF(n);
        vector<vector<int>> edgeTypes(3);
        int commonEdges = 0;

        for (auto& edge : edges) {
            int type = edge[0], u = edge[1] - 1, v = edge[2] - 1;
            if (type == 3) {
                if (aliceUF.unite(u, v)) commonEdges++;
                if (bobUF.unite(u, v)) commonEdges++;
            } else {
                edgeTypes[type - 1].push_back({u, v});
            }
        }

        for (auto& edge : edgeTypes[0]) {
            if (!aliceUF.unite(edge[0], edge[1])) return -1;
        }

        for (auto& edge : edgeTypes[1]) {
            if (!bobUF.unite(edge[0], edge[1])) return -1;
        }

        int totalEdges = edges.size();
        int usedEdges = commonEdges + countUsedEdges(aliceUF) + countUsedEdges(bobUF);
        return totalEdges - usedEdges;
    }

private:
    int countUsedEdges(UnionFind& uf) {
        int count = 0;
        for (int i = 0; i < uf.size.size(); ++i) {
            if (uf.find(i) == i) count++;
        }
        return count - 1;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges1 = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    cout << solution.maxNumEdgesToRemove(4, edges1) << endl;  // Output: 2

    vector<vector<int>> edges2 = {{3, 1, 2}, {3, 2, 3}, {1, 1, 4}, {2, 1, 4}};
    cout << solution.maxNumEdgesToRemove(4, edges2) << endl;  // Output: 0

    vector<vector<int>> edges3 = {{3, 2, 3}, {1, 1, 2}, {2, 3, 4}};
    cout << solution.maxNumEdgesToRemove(4, edges3) << endl;  // Output: -1

    return 0;
}
