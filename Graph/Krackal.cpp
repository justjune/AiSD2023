#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

struct Vertex {
    char id;
    bool operator==(const Vertex& other) const {
        return (id == other.id);
    }
    bool operator<(const Vertex& other) const {
        return (id < other.id);
    }

    bool operator!=(const Vertex& other) const {
        return !(*this == other);
    }
};

struct Edge {
    Vertex u, v;
    int weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

struct Graph {
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    Graph(const std::vector<Vertex>& vertices, const std::vector<Edge>& edges) : vertices(vertices), edges(edges) {}
};

struct UnionFind {
    std::map<Vertex, Vertex> parent;
    Vertex find(Vertex x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void unite(Vertex x, Vertex y) {
        x = find(x);
        y = find(y);
        if (x != y)
            parent[y] = x;
    }
};

std::vector<Edge> Kruskal(std::vector<Edge>& edges, std::vector<Vertex>& vertices) {
    std::sort(edges.begin(), edges.end());
    UnionFind uf;
    for (Vertex& v : vertices) {
        uf.parent[v] = v;
    }
    std::vector<Edge> mst;
    for (Edge& e : edges) {
        if (uf.find(e.u) != uf.find(e.v)) {
            uf.unite(e.u, e.v);
            mst.push_back(e);
        }
    }
    return mst;
}

int main() {
    // Создали Вершины
    Vertex A('A'), B('B'), C('C'), D('D'), E('E');

    // Создали ребра
    Edge e1(A, B, 1), e2(A, C, 3), e3(B, C, 2), e4(B, D, 5), e5(C, D, 4), e6(D, E, 6);

    // Созадли граф из вершин и ребер
    Graph g({A, B, C, D, E}, {e1, e2, e3, e4, e5, e6});

    // Применяем алгоритм Краскала
    std::vector<Edge> mst = Kruskal(g.edges, g.vertices);

    // Выводим результат. 
    for (const Edge& e : mst) {
        std::cout << "Edge from vertex " << e.u.id << " to vertex " << e.v.id << " with weight " << e.weight << '\n';
    }

    return 0;
}