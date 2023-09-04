#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sum;

    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        sum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        
        for (int a = 1, c = 0; c < n; a++, c++) {
            for (int b = 1, d = 0; d < m; b++, d++) {
                sum[a][b] = matrix[c][d];
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int a, int b, int c, int d) {
        c++;
        d++;
        return sum[c][d] - sum[c][b] - sum[a][d] + sum[a][b];
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    NumMatrix obj(matrix);
    cout << obj.sumRegion(0, 0, 2, 2) << endl; // Should output 45
    cout << obj.sumRegion(1, 1, 2, 2) << endl; // Should output 28
    return 0;
}
