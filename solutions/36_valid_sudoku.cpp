/* https://leetcode.com/problems/valid-sudoku/
36. Valid Sudoku
Medium
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, bool> mmap;
        unordered_map<char, bool> mmap2;
        for(int i = 0; i<9;i++) {
            for(int j = 0;j<9;j++) {
                if(mmap.find(board[i][j])!= mmap.end()){
                    return false;
                }
                if(mmap2.find(board[j][i])!= mmap2.end())
                    return false;
                if(board[i][j]!='.')
                    mmap[board[i][j]] = true;
                if(board[j][i]!='.')
                    mmap2[board[j][i]] = true;
            }
            mmap.clear();
            mmap2.clear();
        }
        for(int x = 0;x<7;x+=3) {
            for(int y =0;y<7;y+=3) {
                for(int i = 0; i<3;i++) {
                    for(int j =0; j<3;j++) {
                        if(mmap.find(board[x+i][y+j])!= mmap.end()){
                            return false;
                        }
                        if(board[x+i][y+j]!='.')
                            mmap[board[x+i][y+j]] = true;
                    }
                }
                mmap.clear();
            }
        }
        return true;
    }
};