// O(n) space and O(mn) time
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> columns;
        for(int i = 0; i < matrix.size(); i++) {
            bool isRawZero = false;
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    columns.insert(j);
                    isRawZero = true;
                }
            }
            if(isRawZero) {
                matrix[i] = vector<int> (matrix[i].size(), 0);
            }
        }
        for(auto c:columns) {
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][c] = 0;
        }
    }
};

// O(1) Space and O(mn) time, really good approach, basically map every zero to first column and row, so that we don't need to use a set/map to remember positions
// Also will have to remember if first row or column has zeros, so that we can set them later

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool isColumnZero = false, isRowZero = false; // to remember if first row and column has zeros
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0){
                isRowZero = true;
            }
        }
        for(int j=0; j<m; j++){
            if(matrix[0][j] == 0){
                isColumnZero = true;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0; // map the zeros to first row and column
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0; // set all the zeros here
                }
            }
        }
        if(isRowZero){ // set the first row zeros
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
        if(isColumnZero){ // set the first column zeros
            for(int j=0; j<m; j++){
                matrix[0][j] = 0;
            }
        }
    }
};
