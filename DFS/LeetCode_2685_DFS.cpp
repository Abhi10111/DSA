class Solution {
public:
    int DFS(vector<vector<int>>& edges, vector<bool>& visited, int& edgeCount, int& nodeCount, int node){
        if(visited[node]){
            return 0;
        }
        nodeCount++;
        edgeCount+=edges[node].size();
        visited[node] = true;
        for(auto& x: edges[node]){
            DFS(edges, visited, edgeCount, nodeCount, x);
        }
        return edgeCount == nodeCount*(nodeCount-1);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<int> arr;
        vector<vector<int>> g(n);
        for(auto x: edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        int ans{0};
        int nc{0};
        int ec{0};
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans+=DFS(g, visited, ec, nc, i);
                nc=0;
                ec=0;
            }
        }
        return ans;
    }
};
