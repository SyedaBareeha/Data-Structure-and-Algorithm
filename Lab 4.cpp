#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;
};

int main()
{
    int n, m;

    cout << "Enter rows: ";
    cin >> n;

    cout << "Enter columns: ";
    cin >> m;

    vector<vector<int>> maze(n, vector<int>(m));

    srand(time(0));

    // Fill maze randomly with 0 and 1
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            maze[i][j]=rand()%2;
        }
    }

    maze[0][0]=0;
    maze[n-1][m-1]=0;

    cout<<"\nMaze:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }

    // Adjacency List
    vector<vector<int>> adj(n*m);

    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]==1)
                continue;

            int u=i*m+j;

            for(int k=0;k<8;k++)
            {
                int ni=i+dx[k];
                int nj=j+dy[k];

                if(ni>=0 && ni<n && nj>=0 && nj<m && maze[ni][nj]==0)
                {
                    int v=ni*m+nj;
                    adj[u].push_back(v);
                }
            }
        }
    }

    vector<int> parent(n*m,-1);
    vector<int> visited(n*m,0);

    queue<int> q;

    int start=0;
    int dest=n*m-1;

    visited[start]=1;
    q.push(start);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        if(u==dest)
            break;

        for(int v:adj[u])
        {
            if(!visited[v])
            {
                visited[v]=1;
                parent[v]=u;
                q.push(v);
            }
        }
    }

    if(!visited[dest])
    {
        cout<<"\nNo Path Exists.";
        return 0;
    }

    vector<int> path;

    for(int v=dest;v!=-1;v=parent[v])
        path.push_back(v);

    reverse(path.begin(),path.end());

    cout<<"\nPath:\n";

    for(int v:path)
    {
        cout<<"("<<v/m<<","<<v%m<<") ";
    }

    cout<<endl;

    return 0;
}