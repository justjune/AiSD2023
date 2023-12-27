/// @file 229L69Dijkstra.cpp
/// @brief Реализация алгоритма Дейкстры для поиска минимального пути во взвешанном графе.
/// @author Бригада: Александр Кайгородов, Ануар Нурписов, Николай Фёдоров, Влада Харина, Вероника Ярышева.

#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Graph_table {
private:
    vector<vector<int>> table;
public:
    Graph_table(vector<vector<int>>& graph) {
        int n = size(graph);
        for (int i = 0; i < n; ++i)
        {
            vector<int> i_vector(n);
            table.push_back(i_vector);
            for (int j = 0; j < n; ++j) {
                table[i][j] = graph[i][j];
            }
        }
    }
    int findMinDistance(int startVertex, int endVertex) {

        //Алгоритм Дейкстры

        int* pos = new int[size(table)];
        bool* node = new bool[size(table)];
        int min = 0, index_min = 0;
        for (int i = 0; i < size(table); ++i) {
            pos[i] = INT_MAX;
            node[i] = false;
        }
        pos[startVertex] = 0;
        for (int i = 0; i <= size(table); ++i) {
            min = INT_MAX;
            for (int j = 0; j < size(table); ++j) {
                if (!node[j] && pos[j] < min) {
                    min = pos[j];
                    index_min = j;
                }
            }
            node[index_min] = true;
            for (int j = 0; j < size(table); ++j) {
                if (!node[j] && table[index_min][j] > 0 && pos[index_min] + table[index_min][j] < pos[j])
                    pos[j] = pos[index_min] + table[index_min][j];
            }
        }
        return pos[endVertex];

    }
};



void runTest(Graph_table& graph, int startVertex, int endVertex, int expectedDistance) {
    int result = graph.findMinDistance(startVertex, endVertex);

    cout << "Expected: " << expectedDistance << " Result: " << result << endl;

    if (result == expectedDistance) {
        cout << "OK" << endl;
    }
    else {
        cout << "NOT OK" << endl;
    }

    cout << endl;
}

int main() {
    //ТЕСТ 1:


    // Пример графа в виде таблицы смежности
    // Элементу [i][j] соответствует вес ребра между рёбрами i и j.
    // У несмежных ребер значение [i][j] равно нулю
    vector<vector<int>> table1 = {
            vector<int>{0, 2, 6, 0, 0},
            vector<int>{2, 0, 0, 3, 0},
            vector<int>{6, 0, 0, 1, 1},
            vector<int>{0, 3, 1, 0, 4},
            vector<int>{0, 0, 1, 4, 0},
    };
    Graph_table graph1(table1); // создание объекта типа Graph_table по написанной таблице смежности

    // Запуск теста с ожидаемым результатом
    // 1-е поле: объект типа Graph_table
    // 2-е поле: начальная вершина
    // 3-е поле: вершина, расстояние до которой мы считаем
    // последнее поле: ожидаемый результат выполнения алгоритма Дейкстры
    runTest(graph1, 0, 3, 5);

    // тесты для того же вектора, ищущие расстояние между другими точками
    runTest(graph1, 0, 2, 6);
    runTest(graph1, 0, 4, 7);


    //ТЕСТ 2:

    vector<vector<int>> table2 = {
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };
    Graph_table graph2(table2);

    runTest(graph2, 0, 3, 19);

    runTest(graph2, 4, 5, 10);
    runTest(graph2, 3, 4, 9);
}