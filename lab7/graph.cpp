

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef char str;
typedef int weight;

#define point 9

typedef struct Graph {
    str a[point];
    weight b[point][point];
    int numpoint, numside;
} Graph;

void DFS(Graph &G, int i);

void init(Graph &G) {
    G.numside = 15;
    G.numpoint = 9;

    str array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    for (int i = 0; i < G.numpoint; i++)
        G.a[i] = array[i];

    for (int i = 0; i < G.numpoint; i++) {
        for (int j = 0; j < G.numpoint; j++) {
            G.b[i][j] = 0;
        }
    }

    G.b[0][1] = 1;
    G.b[0][5] = 1;

    G.b[1][2] = 1;
    G.b[1][8] = 1;
    G.b[1][6] = 1;

    G.b[2][3] = 1;
    G.b[2][8] = 1;

    G.b[3][4] = 1;
    G.b[3][7] = 1;
    G.b[3][6] = 1;
    G.b[3][8] = 1;

    G.b[4][5] = 1;
    G.b[4][7] = 1;

    G.b[5][6] = 1;

    G.b[6][7] = 1;


    for (int i = 0; i < G.numpoint; i++) {
        for (int j = i+1; j < G.numpoint; j++) {
            if (G.b[i][j] == 1)
                G.b[j][i] = 1;
            else if (G.b[j][i] == 1)
                G.b[i][j] = 1;
        }
    }
}


int visited[point];

void DFSTraverse(Graph G) {
    for (int i = 0; i < G.numpoint; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < G.numpoint; i++) {
        if (!visited[i])
            DFS(G, i);
    }
    cout << endl; 
}


void DFS(Graph &G, int i) {
    visited[i] = 1;
    cout << G.a[i] << ' ';

    for (int j = 0; j < G.numpoint; j++) {
        if (G.b[i][j] == 1 && !visited[j])
            DFS(G, j);
    }
}


int visited2[point];

void BFS(Graph &G) {
    queue<int> q;
     
    for (int i = 0; i < G.numpoint; i++) {
        visited2[i] = 0;
    }

    for (int i = 0; i < G.numpoint; i++) {
        if (!visited2[i]) {
            visited2[i] = 1;
            cout << G.a[i] << ' ';
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int j = 0; j < G.numpoint; j++) {
                    if (!visited2[j] && G.b[curr][j] == 1) {
                        visited2[j] = 1;
                        cout << G.a[j] << ' ';
                        q.push(j);
                    }
                }
            }
        }
    }
    cout << endl; 
}


int main() {
    Graph G;
    init(G);
    
    DFSTraverse(G);

    Graph G2;
    init(G2);
    BFS(G2);

    return 0;
}



