/// @file 176L51Grapg_table_and_list.cpp
/// @brief Реализация изменения пердставления графа (списки и таблицы смежности).
/// @author Бригада: Александр Кайгородов, Ануар Нурписов, Николай Фёдоров, Влада Харина, Вероника Ярышева.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph {
public:
    vector<vector<int>> table;
    vector<vector<int>> list;

    void table_to_list() {
        for (int i = 0; i < size(table); ++i) {
            vector<int> vertex;
            for (int j = 0; j < size(table); ++j) {
                if (table[i][j] != 0)
                    vertex.push_back(j);
            }

            list.push_back(vertex);
        }
    }
    void table_add (vector<vector<int>>& graph) {
        int n = size(graph);
        for (int i = 0; i < n; ++i)
        {
            vector<int> i_vector(n);
            table.push_back(i_vector);
            for (int j = 0; j < n; ++j) {
                table[i][j] = graph[i][j];
            }
        }
        table_to_list();
    }
    void list_to_table() {
        int n = size(list);

        for (int i = 0; i < n; ++i) {
            vector<int> i_vector(n);
            table.push_back(i_vector);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < size(list[i]); ++j) {
                table[i][list[i][j]] = 1;
            }
        }
    }

    void list_add(vector<vector<int>>& graph) {
        for (int i = 0; i < size(graph); ++i)
        {
            vector<int> i_vector(size(graph[i]));
            list.push_back(i_vector);
            for (int j = 0; j < size(graph[i]); ++j) {
                list[i][j] = graph[i][j];
            }
        }
        list_to_table();
    }
    



    
};
bool test_table_to_list(Graph& table, vector<vector<int>> &list1) {
    if (size(table.list) != size(list1)) {
        cout << "NOT OK" << endl;
        return false;
    }
    for (int i = 0; i < size(table.list); ++i) {
        if (size(table.list[i]) != size(list1[i])) {
            cout << "NOT OK" << endl;
            return false;
        }
        for (int j = 0; j < size(list1[i]); ++j) {
            if (table.list[i][j] != list1[i][j]) {
                cout << "NOT OK" << endl;
                return false;
            }
        }
    }
    cout << "OK" << endl;
    return true;
}

bool test_list_to_table(Graph& graph, vector<vector<int>>& table1) {
    if (size(graph.table) != size(table1)) {
        cout << "NOT OK" << endl;
        return false;
    }
    for (int i = 0; i < size(graph.table); ++i) {
        if (size(graph.table[i]) != size(table1[i])) {
            cout << "NOT OK" << endl;
            return false;
        }
        for (int j = 0; j < size(graph.table[i]); ++j) {
            if (graph.table[i][j] != table1[i][j]) {
                cout << "NOT OK" << endl;
                return false;
            }
        }
    }
    cout << "OK" << endl;
    return true;
}

int main() {
    //ТЕСТ 1:


    // Пример графа в виде таблицы смежности
    // Элементу [i][j] соответствует вес ребра между рёбрами i и j. 
    // У несмежных ребер значение [i][j] равно нулю
    vector<vector<int>> table1 = {
        vector<int>{0, 1, 1, 0, 0},
        vector<int>{1, 0, 0, 1, 0},
        vector<int>{1, 0, 0, 1, 1},
        vector<int>{0, 1, 1, 0, 1},
        vector<int>{0, 0, 1, 1, 0},
    };
    Graph graph1; // создание объекта типа Graph
    graph1.table_add(table1); // присваиваем значение таблице

    vector<vector<int>> list1 = {  //ожидаемый результат
        vector<int>{1, 2},
        vector<int>{0, 3},
        vector<int>{0, 3, 4},
        vector<int>{1, 2, 4},
        vector<int>{2, 3},
    };
    test_table_to_list(graph1, list1);  // проверка правильности table_to_list

    // проведём проверку list_to_table для того же графа, но нового объекта
    Graph graph2;
    graph2.list_add(list1);
    test_list_to_table(graph2, table1);

    //ТЕСТ 2:
    vector<vector<int>> table2 = {
        vector<int>{0, 1, 1, 1},
        vector<int>{1, 0, 0, 0},
        vector<int>{1, 0, 0, 1},
        vector<int>{1, 0, 1, 0}
    };
    vector<vector<int>> list2 = {
        vector<int>{1, 2, 3},
        vector<int>{0},
        vector<int>{0, 3},
        vector<int>{0, 2}
    };
    Graph graph1_2;
    graph1_2.table_add(table2);
    test_table_to_list(graph1_2, list2);

    Graph graph2_2;
    graph2_2.list_add(list2);
    test_list_to_table(graph2_2, table2);
}