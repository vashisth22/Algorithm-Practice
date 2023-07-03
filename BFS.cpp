//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code herevector<int>ans;
        
         vector<int>ans;
        
        //Step-1 An array to track visited nodes
        bool visited[V+1];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        
        
        //Step-2 push the source (0 here) in queue & mark it visited
        queue<int>q;
        q.push(0);
        visited[0]=true;
        
        //Step-3 Run a loop while q is non empty
        while(!q.empty()){
            //Get the front of queue & pop it
            int u=q.front();
            q.pop();
            
            //Push this node in our ans
            ans.push_back(u);
            
            //Now push the adjacent nodes in q one by one
            for(int x:adj[u]){
                
                //visit it only if not already visited
                if(visited[x]==false){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return ans;
        
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends