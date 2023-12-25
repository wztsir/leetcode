#include <iostream>
#include <vector>

using namespace std;

const int rows = 3;
const int cols = 8;

bool is_valid_move(int x, int y, vector<vector<bool>>& visited) {
    return x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y];
}

bool is_hamiltonian_path(vector<vector<bool>>& visited) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(i == rows-1 && j == cols-1)continue;
            if (!visited[i][j]) {
                return false; // 有节点未访问
            }
        }
    }

    return true; // 判断是否通过第2排第7列的节点
}

int count_hamiltonian_paths(int x, int y, vector<vector<bool>>& visited) {
    if (x == 2 && y == 7) {
        if (is_hamiltonian_path(visited)) {
            return 1; // 找到一条哈密顿回路
        }
        return 0; // 不满足哈密顿回路条件
    }

    int total_paths = 0;

    visited[x][y] = true;
    int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < 4; ++i) {
        int new_x = x + moves[i][0];
        int new_y = y + moves[i][1];

        if (is_valid_move(new_x, new_y, visited)) {
            total_paths += count_hamiltonian_paths(new_x, new_y, visited);
        }
    }

    visited[x][y] = false; // 回溯
    return total_paths;
}

int main() {
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int total_paths = count_hamiltonian_paths(0, 0, visited);

    cout << "Total Hamiltonian paths: " << total_paths << endl;

    return 0;
}

