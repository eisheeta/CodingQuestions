#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Edge{
    public:
        int v=0;
        int w=0;

        Edge(int v, int w){
            this->v = v;
            this->w = w;
        }
};



int n=7;
vector<vector<Edge *>>graph(7, vector<Edge*>());

void addEdge(int u, int v, int w){
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void display(){
    for(int i=0; i<n; i++){

        cout<<i<<" ->";
        
        for(Edge *e: graph[i]){
            cout<<"("<<e->v<<", "<<e->w<<")";
        }
        cout<<endl;
    }
}

void createGraph(){
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);
    display();
}


//my method

// void removeVertex(int rem){
//     graph[rem].clear();
//     for(int i=0; i<n; i++){
        
//         for(Edge *e: graph[i]){
//             if(e->v == rem){
//                 e->v =-1;
//                 e->w = -1;
//             }
//         }
//     }
//     display();
// }

// void removeEdge(int u, int v){
//     for(Edge*e: graph[u]){
//         if(e->v == v)
//             {
//                 e->v = -1;
//              e->w = -1;
//             }
//     }

//     for(Edge*e: graph[v]){
//         if(e->v == u)
//             {
//             e->v = -1;
//             e->w = -1;
//             }
//     }
// }





int serachVertex(int u, int v)
{
    int idx = -1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i]->v == v)
        {
            idx = i;
            break;
        }
    }

    return idx;
}

void removeEdge(int u, int v)
{
    int vIdx = serachVertex(u, v);
    int uIdx = serachVertex(v, u);

    if (uIdx != -1)
    {
        graph[u].erase(graph[u].begin() + vIdx);
        graph[v].erase(graph[v].begin() + uIdx);
    }
}

void removeVertex(int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        int v = graph[u][i]->v;
        removeEdge(u, v);
    }
}

bool hasPath(int src, int desti, vector<bool> &vis, string ans)
{

    if (src == desti)
    {
        cout << ans + " " + to_string(desti) << endl;
        return true;
    }

    vis[src] = true;

    bool res = false;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            res = res || hasPath(e->v, desti, vis, ans + to_string(src) + " ");
    }

    return res;
}

int allPath(int src, int desti, vector<bool> &vis, string ans)
{

    if (src == desti)
    {
        cout << ans + to_string(desti) << endl;
        return 1;
    }
    vis[src] = true;

    int count = 0;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            count += allPath(e->v, desti, vis, ans + to_string(src) + " ");
    }

    vis[src] = false;

    return count;
}


void hamiltonianPath(int src, int osrc, int count, string ans){

    if(count == n-1){
        int vtx = serachVertex(src, osrc);
        if(vtx!=-1){
            cout<<"Cycle:" + ans <<endl;

        }
        else {
            cout<<"Path:" + ans;
        }
    }

    for(Edge* e: graph[src]){
        // if()
    }
}


void dfcregioncheck(int r, int c, int n, int m, vector<vector<char>> &board){
    if(board[r][c] != 'O'){
        return;
    }

    board[r][c] ='#';
    if(r-1 >=0){
        dfcregioncheck(r-1, c, n, m, board);
    }

    if(r+1 <n){
        dfcregioncheck(r+1, c, n, m, board);
    }

    if(c-1 >=0){
        dfcregioncheck(r, c-1, n, m, board);
    }

    if(c+1 <m){
        dfcregioncheck(r, c+1, n, m, board);
    }

}

void surroundRegions(vector<vector<char>> &board){
    if(board.size() == 0 ){
        return;
    }

    int n = board.size();
    int m = board[0].size();

    for(int i=0; i<n; i++){
        if(board[i][0]== 'O'){
            dfcregioncheck(i, 0, n, m, board);
        }
        if(board[i][m-1] == 'O'){
            dfcregioncheck(i, m-1, n, m, board);
        }
    }

    for(int j=0; j<m; j++){
        if(board[0][j] == 'O'){
            dfcregioncheck(0, j, n, m, board);
        }
        if(board[n-1][j] == 'O'){
            dfcregioncheck(n-1, j, n, m, board);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }

            if(board[i][j] == '#'){
                board[i][j] = 'O';
            }
        }
    }
}


//LEETCODE COUNT SERVERS
int count =0;
    
    int markVisited(int r, int c, int n, int m, vector<vector<int>>& grid){
        
        if(grid[r][c] != 0){
            return 1;
        }
        
        if(r-1 >=0 ){
            count += markVisited(r-1, c, n, m, grid);
        }
        if(r+1 <n ){
            count += markVisited(r+1, c, n, m, grid);
        }
        
        if(c-1 >=0 ){
            count+= markVisited(r, c-1, n, m, grid);
        }
        if(c+1 <m ){
            count += markVisited(r, c+1, n, m, grid);
        }
        
        return count;
    }
    
    int countServers(vector<vector<int>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int countno = 0;
        countno = markVisited(0, 0, n, m, grid);
        if(countno ==1){
            return 0;
        }
        return countno;
    }



//BREADTH FIRST SEARCH

void BFS(int src, vector<bool> &vis)
{
    queue<int> que;
    que.push(src);
    int level = 0;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            if (rvtx == 6)
            {
                cout << "destination at level: " << level << endl;
            }

            if (vis[rvtx])
            {
                cout << "Cycle wrt " + to_string(src) + " : " + to_string(rvtx) << endl;
                continue;
            }

            vis[rvtx] = true;
            for (Edge *e : graph[rvtx])
            {
                if (!vis[e->v])
                    que.push(e->v);
            }
        }
        level++;
    }
}


//Graphs no. of connected components
void GCC()
{
    vector<bool> vis(n, false);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            BFS(i, vis);
            count++;
        }
    }

    cout << "GCC: " << count << endl;

}


//LeetCode Graph Bipartite: Given an undirected graph, return true if and only if it is bipartite. 
//A graph is bipartite if we can split it's set of nodes into two independent subsets A and B 
//such that every edge in the graph has one node in A and another node in B.
//If the cycle has oddnumber of elements, it's not bi-partite

bool bipartite(int src, vector<int> vis){
    queue<pair<int, int>> que;
    que.push({src, 0});

    while(que.size()!=0){
        pair<int, int> rpair =  que.front();
        que.pop();

        int u = rpair.first;
        int c = rpair.second;

        if(vis[u] != -1 ){
            if( vis[u]!= c)//conflict
                return false;

            else 
                continue;
        }

        vis[u] = c;
        for(Edge*e: graph[u])
        {
            if(vis[e->v] == -1)
            {
                que.push({e->v, (c+1)%2});
            }
        }

    }
}
void bipartite(){
    vector<int> vis(n, -1);
    for(int i=0; i<n; i++){
        if(vis[i] == -1){
            cout<< (boolalpha) <<bipartite(i, vis)<<endl;
        }
    }
}

void solve(){
    createGraph();
    vector<bool> vis(n, false);
    //removeVertex(0);
    //removeEdge(1, 0);
    BFS(0, vis);

    GCC();
}

int main(){

    solve();
    return 0;
}