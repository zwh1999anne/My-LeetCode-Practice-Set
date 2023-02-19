/* Use Prim's Algorithm to Build a Minimum Spanning Tree */

#define pii pair<int, int>
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        unordered_map<int, vector<pii>> graph;
        unordered_set<int> added_vertices;
        priority_queue<pii, vector<pii>, greater<pii>> curr_edges;

        for(int i = 0; i <= wells.size(); i++){
            graph[i] = vector<pii> {};
        }
        
        for(int i = 0; i < wells.size(); i++){
            graph[0].push_back({wells[i], i+1});
        }

        for(vector<int> pipe : pipes){
            int ind1 = pipe[0];
            int ind2 = pipe[1];
            int cost = pipe[2];
            graph[ind1].push_back({cost, ind2});
            graph[ind2].push_back({cost, ind1});
        }

        added_vertices.insert(0);
        for(pii e: graph[0]){
            curr_edges.push(e);
        }

        int total_cost = 0;
        while(added_vertices.size() < wells.size() + 1){
            int next_ver = -1;
            while(!curr_edges.empty()){
                pii edge = curr_edges.top();
                curr_edges.pop();
                if(added_vertices.find(edge.second) == added_vertices.end()){
                    cost += edge.first;
                    next_ver = edge.second;
                    break;
                }
            }
            added_vertices.insert(next_ver);
            for(pii e: graph[next_ver]){
            curr_edges.push(e);
            }
        }
        return total_cost;
    }
};
