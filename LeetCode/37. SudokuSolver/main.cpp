#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
#include <bits/stdc++.h>
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
void printSudoku(std::vector<std::vector<char>>& board);
std::vector<char> check(int x,int y,std::vector<std::vector<char>>& board)
{
    std::vector<bool>tmp{1,1,1,1,1,1,1,1,1,1};
    //delete all things, that is not belong [x,y]
    //in column
    for(int i=0;i<9;i++)
    {
        if(board[x][i]!='.')
        {
            tmp[board[x][i]-'0']=false;
        }
    }

    //in row
    for(int i=0;i<9;i++)
    {
        if(board[i][y]!='.')
        {
            tmp[board[i][y]-'0']=false;
        }
    }

    //in square
    int kx = x/3;
    int ky = y/3;
    for(int i=kx*3;i<kx*3+3;++i)
    {
        for(int j=ky*3;j<ky*3+3;++j)
        {
            if(board[i][j]!='.')
            {
                tmp[board[i][j]-'0']=false;
            }
        }
    }

    std::vector<char> result;
    for(int i=1;i<=9;++i)
    {
        if(tmp[i])
            result.push_back(static_cast<char>(i+'0'));
    }
    //std::cout<<x<<","<<y<<" : ";
    //for(auto a:result)
    //    std::cout<<a<<" ";
    //std::cout<<"\n";
    return result;
}

bool isValidSudokuAt(std::vector<std::vector<char>>& board, int x, int y, char v) 
{
    for(int i=0;i<9;++i)
        if(v==board[x][i])
            return false;
    for(int i=0;i<9;++i)
        if(v==board[i][y])
            return false;
    for (int i = (x / 3) * 3; i < (x / 3 + 1) * 3; i++)
		for (int j = (y / 3) * 3; j < (y / 3 + 1) * 3; j++)
			if (v == board[i][j])
                return false;
    return true;
}

void solution2(std::vector<std::vector<char>>& board, int x, int y, bool & f)
{
    if(f)
        return;
    if(board[x][y]!='.')
    {
        x++;
        if(x>8)
        {
            y++;
            x=0;
        }
        if(y>8)
        {
            f=true;
            return;
        }
        solution2(board, x, y, f);
    }
    else
    {
        char v = '1';
        while(!f && v != ('9'+1))
        {
            if(isValidSudokuAt(board, x, y, v))
            {
                board[x][y] = v;
                int i=x+1;
                int j=y;
                if(i>8)
                {
                    i=0;
                    j++;
                }
                if(j>8)
                {
                    f = true;
                    return;
                }
                solution2(board,i,j,f);
                if(!f)
                {
                    board[x][y]='.';
                }
            }
            v++;
        }
    }
}

void solveSudoku(std::vector<std::vector<char>>& board) 
{
    std::vector<std::tuple<int,int,std::vector<char>>> unknownElements;
    for(int i{};i<board.size();++i)
    {
        for(int j{};j<board[i].size();++j)
        {
            if(board[i][j]=='.')
            {
                unknownElements.push_back(std::make_tuple(i,j,check(i,j,board)));
            }
        }
    }
    while(true)
    {
        std::cout<<"step:\n";
        //printSudoku(board);
        bool flag1=false, flag2=false;
        for(int i=0;i<unknownElements.size();++i)
        {
            if(std::get<2>(unknownElements[i]).size() == 1)
            {
                board[std::get<0>(unknownElements[i])][std::get<1>(unknownElements[i])] = std::get<2>(unknownElements[i])[0];
                unknownElements.erase(unknownElements.begin()+i);
                i--;
                flag1=true;
            }
        }

        if(unknownElements.size()==0)
        {
            break;
        }
        //do update of unknown
        for(int i=0;i<unknownElements.size();++i)
        {
            std::get<2>(unknownElements[i]) = check(std::get<0>(unknownElements[i]),std::get<1>(unknownElements[i]),board);
        }
        //exclusive rule of a square
        std::vector<std::vector<std::tuple<int,int,std::vector<char>>>> squares(9);
        for(int i=0;i<unknownElements.size();++i)
        {
            int index = (std::get<0>(unknownElements[i])/3)*3+(std::get<1>(unknownElements[i])/3);
            squares[index].push_back(unknownElements[i]);
        }
        //for each square...
        for(int i=0;i<squares.size();++i)
        {
            std::vector<int> count(9);
            //find, which element is unique
            for(int j=0;j<squares[i].size();++j)
            {
                for(int t=0;t < std::get<2>(squares[i][j]).size();++t)
                {
                    count[std::get<2>(squares[i][j])[t]-'0'-1]++;
                }
            }
            int unique = -1;
            for(int j=0;j<9;++j)
            {
                if(count[j]==1)
                {
                    unique = j+1;
                    break;
                }
            }

            if(unique!=-1)
            {
                flag2=true;
                //find, where this element is
                std::vector<char>::iterator it;
                for(int j=0;j<squares[i].size();++j)
                {
                    it = std::find(std::get<2>(squares[i][j]).begin(),std::get<2>(squares[i][j]).end(),'0'+unique);
                    if(it != (std::get<2>(squares[i][j])).end())
                    {//if found

                        board[std::get<0>(squares[i][j])][std::get<1>(squares[i][j])] = ('0'+unique);
                        //delete element from 'unknowns' because we've discovered it;
                        auto findElemToDelete = std::find_if(unknownElements.begin(),unknownElements.end(),
                            [=](const std::tuple<int,int,std::vector<char>> el)
                            {
                                return (std::get<0>(el)==std::get<0>(squares[i][j]))&&(std::get<1>(el)==std::get<1>(squares[i][j]));
                            });
                            //[&squares](const std::tuple<int,int,std::vector<char>>& el)
                            //{
                            //    return (std::get<0>(el) == std::get<0>(squares[i][j]))&&(std::get<1>(el) == std::get<1>(squares[i][j]));
                            //});
                        if(findElemToDelete != unknownElements.end())
                        {
                            unknownElements.erase(findElemToDelete);
                        }
                        
                    }
                }
            }
        }
        if(unknownElements.size()==0)
        {
            break;
        }
        if(!flag1&&!flag2)
        {
            break;
        }
        //unknownElements.clear();
        /*
        */
        
        for(int i=0;i<unknownElements.size();++i)
        {

            std::get<2>(unknownElements[i]) = check(std::get<0>(unknownElements[i]),std::get<1>(unknownElements[i]),board);
        }

        
        
    }
    if(unknownElements.size()!=0)
    {
        //робимо алгоритм повного перебору
        bool flag = false;
        solution2(board,0,0,flag);
    }

}
void printSudoku(std::vector<std::vector<char>>& board)
{
    for(auto a:board)
    {
        for(auto b:a)
        {
            std::cout<<b<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}
int main()
{
    std::vector<std::vector<char>> b{{'.','.','9','7','4','8','.','.','.'},
                                     {'7','.','.','.','.','.','.','.','.'},
                                     {'.','2','.','1','.','9','.','.','.'},
                                     {'.','.','7','.','.','.','2','4','.'},
                                     {'.','6','4','.','1','.','5','9','.'},
                                     {'.','9','8','.','.','.','3','.','.'},
                                     {'.','.','.','8','.','3','.','2','.'},
                                     {'.','.','.','.','.','.','.','.','6'},
                                     {'.','.','.','2','7','5','9','.','.'}};
                                    
    std::cout<<"before:\n";
    printSudoku(b);
    solveSudoku(b);
    std::cout<<"after:\n";
    printSudoku(b);

}