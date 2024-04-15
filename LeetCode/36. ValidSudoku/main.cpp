#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/
#if 0
//my solution:
bool isValidSudoku(std::vector<std::vector<char>>& board)
{
    std::map<char,int>ch_col;
    std::map<char,int>ch_row;
    std::map<char,int>ch_box;
    
    for(int i{};i<9;++i)
    {
        ch_col.clear();
        ch_row.clear();
        for(int j{};j<9;++j)
        {
            if(board[i][j]!='.')//check row
                ch_row[board[i][j]]++;
            if(board[j][i]!='.')//check column
                ch_col[board[j][i]]++;
        }
        for(auto a : ch_row)
            if(a.second>1)
                return false;
        for(auto a : ch_col)
            if(a.second>1)
                return false;
    }
    for(int di{};di<9;di+=3)
        for(int dj{};dj<9;dj+=3)
        {
            ch_box.clear();
            for(int i{};i<3;++i)
                for(int j{};j<3;++j)
                    if(board[di+i][dj+j]!='.')
                        ch_box[board[di+i][dj+j]]++;
            for(auto a : ch_box)
                if(a.second>1)
                    return false;
        }
    return true;
}
#endif
//faster solution
bool isValidSudoku(std::vector<std::vector<char>>& board) 
{
    std::unordered_set<int> nums;
    
    for (int r = 0; r < board.size(); ++r)
    {
        for (int c = 0; c < board[0].size(); ++c)
        {
            if (board[r][c] == '.')
            {
                continue;//if empty space - skip
            }
            
            const int num = board[r][c] - '0';//check, what number is in board[r][c] = 4[0][2]
            const int boxInd = (r / 3) * 3 + c / 3;                 //0
            
            const int rowKey = num * 1000 + (r+1) * 100;            //4000+100 = 4100 //abcd, where a=number; b=row; c=d=0;
            const int colKey = num * 1000 + (c+1) * 10;             //4000+300 = 4030 //abcd, where a=number; b=d=0; c=col;
            const int boxKey = num * 1000 + boxInd + 1;             //4000+0+1 = 4001 //abcd, where a=number; b=c=0; c=box
            

            /*
            so the logic:
            we mapping our element into 4 digits: abcd
            a - is for digit itself
            b - is for row key
            c - is for column key
            d - is for box key
            thus each of the digits are 1-9 - they will not interrupt neighbour-keys

            and if in the same key happens the same number - it will be found, which means that board is invalid
            */
            if (nums.find(rowKey) != nums.end() || nums.find(colKey) != nums.end() || nums.find(boxKey) != nums.end())
            {
                return false;
            }
            else
            {
                nums.insert(rowKey);
                nums.insert(colKey);
                nums.insert(boxKey);
            }
        }
    }
    
    return true;
}
int main()
{
    std::vector<std::vector<char>>a{{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
                                    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                    {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
                                    {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
                                    {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
                                    {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
                                    {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
                                    {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    std::cout<<isValidSudoku(a)<<std::endl;
    return 0;
}