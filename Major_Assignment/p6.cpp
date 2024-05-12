#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a point in the matrix
struct p6_point {
    int x, y;
};

ostream& operator<<(ostream& stream, const p6_point& point) {
    return stream << "(" << point.x << ", " << point.y << ")";
}

// Function to check if a point is within the bounds of the matrix
bool is_valid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// Function to recursively find all possible paths
void find_all_paths_util(vector<vector<int>>& matrix, p6_point curr, p6_point end, vector<p6_point>& path, vector<vector<bool>>& visited, vector<vector<p6_point>>& all_paths) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Mark current point as visited
    visited[curr.x][curr.y] = true;

    // Add current point to the path
    path.push_back(curr);

    // If we reached the end point, add the current path to allPaths
    if (curr.x == end.x && curr.y == end.y) {
        all_paths.push_back(path);
    }
    else {
        // Possible moves (up, down, left, right)
        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; ++i) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            // Check if the neighbor is within bounds, not visited, and is a valid path
            if (is_valid(newX, newY, rows, cols) && matrix[newX][newY] == 1 && !visited[newX][newY]) {
                find_all_paths_util(matrix, { newX, newY }, end, path, visited, all_paths);
            }
        }
    }

    // Backtrack
    path.pop_back();
    visited[curr.x][curr.y] = false;
}

// Function to find all possible paths using backtracking
vector<vector<p6_point>> find_all_paths(vector<vector<int>>& matrix, p6_point start, p6_point end) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Array to keep track of visited points
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Vector to store all possible paths
    vector<vector<p6_point>> allPaths;

    // Vector to store the current path
    vector<p6_point> path;

    // Find all possible paths recursively
    find_all_paths_util(matrix, start, end, path, visited, allPaths);

    return allPaths;
}

void p6_main(void) {
    vector<vector<int>> matrix = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };

    p6_point start = { 0, 0 };
    p6_point end = { 4, 4 };

    vector<vector<p6_point>> all_paths = find_all_paths(matrix, start, end);

    // Print all possible paths
    cout << "All possible paths:" << endl << endl;

    int counter = 0;

    for (const auto& path : all_paths) {
        cout << "======" << endl;

        cout << "Path #" << counter + 1 << endl << endl;

        for (const auto& point : path) { cout << point << " "; }
        cout << endl << "======" << endl << endl;
    }
}
