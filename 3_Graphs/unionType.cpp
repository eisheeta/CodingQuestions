#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<math.h>

using namespace std;


vector<int> par;
vector<int> size1;

int findParent(int u )
{
    if (par[u] == u)
        return u;

    int p = findParent(par[u]);
    par[u] = p; //compression.
    return p;
}

void merge(int p1, int p2)
{
    if (size1[p1] < size1[p2])
    {
        par[p1] = p2;
        size1[p2] += size1[p1];
    }
    else
    {
        par[p2] = p1;
        size1[p1] += size1[p2];
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    vector<int> par, size;
    for (int i = 1; i <= edges.size(); i++)
    {
        par.push_back(i);
        size.push_back(1);
    }
    vector<int> ans;
    for (vector<int> ar : edges)
    {
        int p1 = findParent(ar[0]);
        int p2 = findParent(ar[1]);

        if (p1 != p2)
        {
            merge(p1, p2);
        }
        else
        {
            return ar;
        }
    }
    return ans;
}

string smallesteEquivalentString(string a, string b, string s){
    
    vector<int> par;
    int n = a.size();

    for(int i=0; i<26; i++){
        par.push_back(i);
    }

    for(int i=0; i<a.length(); i++)
    {
        int p1 = findParent(a[i]-'a');
        int p2 = findParent(b[i]-'a');
        int min1 = min(p1, p2);
        
        par[p1] = min1;
        par[p2] = min1;


    }

}

//leetcode 200  USING DSU(iNCOMPLETE)
int numIslands_01(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int countIslands = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
                countIslands++;
            par.push_back(i * m + j);
            size1.push_back(1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                if (j + 1 < m && grid[i][j + 1] == '1')
                {
                    int p1 = findParent(i * m + j);
                    int p2 = findParent(i * m + j + 1);
                    if (p1 != p2)
                    {
                        countIslands--;
                        merge(p1, p2);
                    }
                }

                if (i + 1 < n && grid[i + 1][j] == '1')
                {
                    int p1 = findParent(i * m + j);
                    int p2 = findParent((i + 1) * m + j);
                    if (p1 != p2)
                    {
                        countIslands--;
                        merge(p1, p2);
                    }
                }
            }
        }
    }
}

int islandPerimeter(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int islands = 0;
    int nbrs = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                islands++;
                if (j + 1 < m && grid[i][j + 1] == 1)
                    nbrs++;
                if (i + 1 < n && grid[i + 1][j] == 1)
                    nbrs++;
            }
        }
    }

    return islands * 4 - 2 * nbrs;
}


// void kruskalAlgoForMST(vector<vector<int>> &graph)
// {
//     sort(graph.begin(), graph.end(), [](vector<int> a, vector<int> b) -> {
//         return a[2] < b[2];
//     });
// }

int main(){
    return 0;
}