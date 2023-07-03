//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
     void  DFSrec(vector<int>adj[],int s,bool visited[],vector<int>&ans){
         
        //Step-3 Mark the source as visited
            visited[s]=true;
            ans.push_back(s);
            
        //Step-4 Now call it recusively for all adjacent of source
            for(int x:adj[s]){
                
                //Only if not visited before
                if(visited[x]==false)
                  DFSrec(adj,x,visited,ans);
            }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
       
       //Step-1 An array to mark visited nodes
       bool visited[V];
       for(int i=0;i<V;i++){
           visited[i]=false;
       }
       
       //Step-2 Call the DFS rec from 0
        DFSrec(adj,0,visited,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends