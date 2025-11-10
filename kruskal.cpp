#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define edge pair<int,int>

class Graph {
private:
    vector<pair<int, edge>> G; // усі ребра графа
    vector<pair<int, edge>> T; // ребра мінімального дерева (MST)
    int *parent;
    int V; // кількість вершин

public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};

// Ініціалізація графа
Graph::Graph(int V) {
    parent = new int[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;
    G.clear();
    T.clear();
}

// Додавання ребра
void Graph::AddWeightedEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}

// Пошук батьківської вершини (для DSU)
int Graph::find_set(int i) {
    if (i == parent[i])
        return i;
    return find_set(parent[i]);
}

// Об'єднання множин
void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}

// Основний алгоритм Крускала
void Graph::kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end()); // сортуємо за вагою (зростання)
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {
            T.push_back(G[i]); // додаємо до МКД
            union_set(uRep, vRep);
        }
    }
}

// Виведення результату
void Graph::print() {
    cout << "Edge : Weight\n";
    int total = 0;
    for (auto &e : T) {
        cout << e.second.first + 1 << " - " 
             << e.second.second + 1 << " : " 
             << e.first << endl;
        total += e.first;
    }
    cout << "Total weight = " << total << endl;
}

// Тестовий приклад для твого графа
int main() {
    Graph g(8);

    g.AddWeightedEdge(0, 1, 2);
    g.AddWeightedEdge(0, 3, 7);
    g.AddWeightedEdge(0, 6, 5);
    g.AddWeightedEdge(1, 4, 9);
    g.AddWeightedEdge(2, 3, 5);
    g.AddWeightedEdge(2, 4, 2);
    g.AddWeightedEdge(2, 5, 4);
    g.AddWeightedEdge(2, 6, 4);
    g.AddWeightedEdge(3, 4, 9);
    g.AddWeightedEdge(3, 5, 5);
    g.AddWeightedEdge(4, 5, 3);
    g.AddWeightedEdge(5, 7, 1);
    g.AddWeightedEdge(6, 7, 6);
    g.AddWeightedEdge(3, 4, 5);

    g.kruskal();
    g.print();

    return 0;
}
