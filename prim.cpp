#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999
#define V 8  // кількість вершин

// Матриця суміжності для твого варіанту
int G[V][V] = {
  {INF, 2, 9, 7, INF, INF, 5, INF},   // 1
  {2, INF, INF, INF, 9, INF, INF, INF}, // 2
  {9, INF, INF, 5, 2, 4, 4, INF},     // 3
  {7, INF, 5, INF, 9, 5, INF, INF},   // 4
  {INF, 9, 2, 9, INF, 3, INF, INF},   // 5
  {INF, INF, 4, 5, 3, INF, INF, 1},   // 6
  {5, INF, 4, INF, INF, INF, INF, 6}, // 7
  {INF, INF, INF, INF, INF, 1, 6, INF} // 8
};

int main() {
    int no_edge = 0;     // лічильник ребер
    bool selected[V];    // вершини, включені в дерево
    memset(selected, false, sizeof(selected));

    selected[0] = true;  // починаємо з вершини 1
    int x, y;
    int totalWeight = 0;

    cout << "Edge : Weight" << endl;

    // Всього буде V-1 ребро
    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j] < min) {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x + 1 << " - " << y + 1 << " : " << G[x][y] << endl;
        totalWeight += G[x][y];
        selected[y] = true;
        no_edge++;
    }

    cout << "Total weight of MST = " << totalWeight << endl;
    return 0;
}
