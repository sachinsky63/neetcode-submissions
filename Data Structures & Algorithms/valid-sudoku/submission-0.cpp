class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> rows;
        unordered_map<int,unordered_set<int>> cols;
        unordered_map<int,unordered_set<int>> squares; // r/3*3 + col/

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c] == '.'){
                    continue;
                }
                int box = (r/3)*3 + c/3;
                if(rows[r].find(board[r][c]) != rows[r].end() || 
                    cols[c].find(board[r][c]) != cols[c].end() ||
                    squares[box].find(board[r][c]) != squares[box].end()){
                        return false;
                }
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[box].insert(board[r][c]);
            }
       }
       return true;
    }
};
