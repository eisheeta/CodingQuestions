
#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

//LEETCODE 684. Redundant Connection (USING UNION)
/*In this problem, a tree is an undirected graph that is connected and has no cycles.
The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), 
with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, 
that represents an undirected edge connecting nodes u and v.
Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v. */
int find1(vector<int> &parent,int i)
    {
        if(parent[i]== -1)
            return i;
        
        return find1(parent,parent[i]);
    }

     void union1(vector<int> &parent,int i,int j)
    {
        int x1=find1(parent,i);
        int x2=find1(parent,j);
        if(x1!=x2)
        {
            parent[x1]=x2;
        }
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int>s1;
        for(int i=0;i<edges.size();i++)
        {
            if(s1.count(edges[i][0])==0)
                s1.insert(edges[i][0]);
            
            if(s1.count(edges[i][1])==0)
                s1.insert(edges[i][1]);
        }
        vector<int>parent(s1.size()+1,-1);
        vector<int>ans;
        ans.push_back(1);
        
        for(int i=0;i<edges.size();i++)
        {
            int x1=find1(parent,edges[i][0]);
            int x2=find1(parent,edges[i][1]);
            if(x1==x2)
            {
                ans.clear();
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
            union1(parent,x1,x2);
        }
        return ans;
    }




//LEETCODE 994 ROTTING ORANGES
/*n a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.*/
int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        bool rotting = true, fresh = true;
        
        while (rotting) {
            rotting = fresh = false;
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!fresh && grid[i][j] == 1) 
                        fresh = true;
                    else if (grid[i][j] == count + 2) 
                    {
                        if (i > 0 && grid[i - 1][j] == 1)
                            rotting = grid[i - 1][j] = count + 3;
                        
                        if (i < n - 1 && grid[i + 1][j] == 1)
                            rotting = grid[i + 1][j] = count + 3;
                        
                        if (j > 0 && grid[i][j - 1] == 1)
                            rotting = grid[i][j - 1] = count + 3;
                        
                        if (j < m - 1 && grid[i][j + 1] == 1)
                            rotting = grid[i][j + 1] = count + 3;
                    }
                }
            }
            
            if (rotting) 
                count++;
        }
        
        return fresh ? -1 : count;
    }


//LEETCODE 1061 LEXICOGRAPHICALLY SMALLEST EQUIVALENT STRING (USING UNION)
/*Given strings A and B of the same length, we say A[i] and B[i] are equivalent characters. For example, if A = "abc" and B = "cde", then we have 'a' == 'c', 'b' == 'd', 'c' == 'e'.

Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'
Symmetry: 'a' == 'b' implies 'b' == 'a'
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'

*/

char find2(vector<char> &parent, char i)
    {
            int r = (i-'a' ) +1;

        if(parent[r]== -1)
            return i;
        
        return find2(parent, parent[r]);
    }
    
     void union1(vector<char> &parent, char i, char j)
    {
        int x1=find2(parent,i);
        int x2=find2(parent,j);
        if(x1!=x2 )
        {
            
            if(int(x1) < int(x2))
                parent[x1]=x2;
            
            else{
                parent[x2] = x1;
            }
        }
    }



//LEETCODE 200. Number of Islands
/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.*/
int dir[4][2]= {{1,0}, {0,1}, {-1, 0}, {0, -1}};
    
    void dfs(int x, int y, vector<vector<char>> &grid){

        grid[x][y] ='0';
    for(int d=0; d<4; d++){
        int i = x + dir[d][0];
        int j = y + dir[d][1];

        if(i>=0 && j>=0 && i< grid.size() && j<grid[0].size() && grid[i][j]=='1'){
            dfs(i, j, grid);
        }
    }

}


int numIslands(vector<vector<char>>& grid){
    
    int n = grid.size();
    if(n == 0){
        return 0;
    }
        int m = grid[0].size();
        int c=0;
        
    
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]  == '1')
                {   
                    c++;
                    dfs(i, j, grid);
                    
                }
                
            }
        }
        
        return c;
    }


//LEETCODE 695. Max Area of Island
/*Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally 
(horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)*/

int dfs1(int x, int y, vector<vector<int>> &grid){
int count=0;
    grid[x][y] =0;
    for(int d=0; d<4; d++){
        int i = x + dir[d][0];
        int j = y + dir[d][1];

        if(i>=0 && j>=0 && i< grid.size() && j<grid[0].size()){
            count += dfs1(i, j, grid);
        }
    }

    return count +1;
}


int maxAreaOfIsland(vector<vector<int>>& grid){

    int n = grid.size();
        int m = grid[0].size();
        int maxArea =0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]  == 1)
                {   
                    int area = dfs1(i, j, grid);
                    if(area > maxArea)
                        maxArea = area;
                }
                
            }
        }
        
        return maxArea;
}


//using DSU( UNION)
// int numIslands01(vector<vector<char>>& grid){
//     int n = grid.size();
//         int m = grid[0].size();
//         int c=0;
//         vector<int> par, size;

//         for(int i=0; i<n*m; i++){
//             par.push_back(i);
//         }

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] == '1'){
//                     c++;
//                     par.push_back(i*m +j);
//                     size.push_back(1);
//                 }
//             }
//         }

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] == '1'){
//                     if(j+1 < m && grid[i][j+1] == '1'){
//                         int p1 = findParent(i*m +j);
//                     }
//                 }
//             }}
// }

int main(){
return 0;
}
