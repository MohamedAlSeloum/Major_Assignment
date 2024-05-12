#include <iostream>
#include <vector>

#include "problem7.h"

using namespace std;

bool is_safe(const vector<vector<int>>& graph, int vertex, int color, const vector<int>& colors) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_util(const vector<vector<int>>& graph, int m, int vertex, vector<int>& colors) {
    if (vertex == graph.size()) {
        return true;
    }

    for (int color = 1; color <= m; ++color) {
        if (is_safe(graph, vertex, color, colors)) {
            colors[vertex] = color;
            if (graph_coloring_util(graph, m, vertex + 1, colors)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }

    return false;
}

bool graph_coloring(const vector<vector<int>>& graph, int m) {
    vector<int> colors(graph.size(), 0);
    if (graph_coloring_util(graph, m, 0, colors)) {
        return true;
    }
    return false;
}

void p7_main(void) {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3;

    cout << (graph_coloring(graph, m) ? "TRUE" : "FALSE") << endl; // Output: 1
}
