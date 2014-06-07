#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>

using namespace std;
class Weight {
public:
    int dist;
    int cost;
    bool operator < (const Weight& b) {
        return (dist == b.dist)?(cost<b.cost):dist < b.dist;
    }

    Weight operator + (const Weight& b) {
        return Weight(dist + b.dist, cost + b.cost);
    } 
    Weight():dist(500), cost(500){}
    Weight(int d, int c):dist(d), cost(c){}
};

class Node {
public:
    Weight weight;
    bool visited;
    int from;
    Node():weight(),visited(false){}
    Node(int d, int c):weight(d,c),visited(false){}
};

void print_path(vector<Node>& track, int s, int e) {
    if (track[e].from == -1) {
        printf("%d ", s);
        return;
    } else {
        print_path(track, s, track[e].from);
    }
    printf("%d ", e);
}

int main() 
{
    int n,m,s,d;
    Weight* adj[500][500] = {NULL};
    cin>>n>>m>>s>>d;
    int c1,c2,dist,cost;
    vector<Node> R(n); 
    for(int i=0; i<m; i++) {
        cin>>c1>>c2>>dist>>cost;
        adj[c1][c2]=adj[c2][c1] = new Weight(dist, cost);
    }
    R[s].weight.cost=0;
    R[s].weight.dist=0;
    R[s].from = -1;
    while (true) {
        int min=0;

        // try to find the first unvisited node
        while (min<n && R[min].visited)
            min++;
        // if all nodes have been visited, end
        if (min == n) break;

        // we assume the first unvisited node is the minimun node 
        // and try to find another if exists
        for (int i = min+1; i < n; i++) {
            if (!R[i].visited && R[i].weight < R[min].weight) {
                min = i;
            }
        }

        // now we get the min node, set flag, we will start to visit(read adj from) it!
        R[min].visited = true;

        // refresh dist and cost data of the nodes which are in min-node's adj list
        Weight* w = NULL;
        for (int j=0; j<n; j++) {
            if (( w = adj[min][j]) != NULL) {
                if (!R[j].visited) {
                    Weight nWeight = R[min].weight + *w;
                    if (nWeight < R[j].weight) {
                        R[j].weight = nWeight;
                        R[j].from = min;
                    }
                }
            }
        }
    }
    
    print_path(R, s, d);
    printf("%d %d\n", R[d].weight.dist, R[d].weight.cost);
    return 0;
}
