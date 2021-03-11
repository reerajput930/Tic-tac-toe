#include <iostream>
#include<unistd.h>
#include <conio.h>
using namespace std;

void matrix_prient();
void board();
int addmark(char);
int check(char);
int turn = 1;
char matrix[3][3] = {{
                         ' ',
                         ' ',
                         ' ',
                     },
                     {
                         ' ',
                         ' ',
                         ' ',
                     },
                     {' ', ' ', ' '}};

int input;
int main()
{ 
     string p1,p2;
     cout<<"kindly Enter your name before start! "<<endl;
     cout<<"player 1 name: ";
     cin>>p1;
     cout<<"player 2 name: ";
     cin>>p2;
    char mark;
    for (int i = 1; i <= 9; i++)
    {
        system("cls");
        matrix_prient();
        board();
        if (turn)
            cout <<"player "<<p1<< " turn and mark 'O' " << endl;
        else
            cout <<"player "<<p2<< " turn and mark 'X' " << endl;
            
        cout << "enter your number by seeing the above filled matrix: ";
        cin >> input;

        //if invalid input
        while (input > 9 || input < 1)
        {
            cout << "invalid input! \n plz Re-Enter the input: ";
            cin >> input;
        }
        if (turn)
            mark = 'O';
        else
            mark = 'X';

        int invalid = addmark(mark);
        if (!invalid)
        {
            i--;
            continue;
        }

        int won =check(mark);

      if(won){
          system("cls");
          board();
          if(turn) cout<<"\t\t\t************* player 1 ("<<p1<<") won the game ************"<<endl;
          else cout<<"\t\t\t************* player 2 ("<<p2<<") won the game ************"<<endl;
          break;
      }
      if(i==9){
          system("cls");
          board();
          cout<<"\t\t\t******** match is drow ************\n";
          cout<<"play next round!"<<endl;
      }
       

        turn = !turn;
    }

    sleep(500);
    return 0;
}

void matrix_prient()
{
    
    cout << " 1   2 | 3 " << endl;
    cout << "----------" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "----------" << endl;
    cout << " 7 | 8 | 9 " << endl;
}
void board()
{
    cout<<"                                      Tic Tic Toe game \n\n";
    cout << "                                        " << matrix[0][0] << " | " << matrix[0][1] << " | " << matrix[0][2] << " " << endl;
    cout << "                                       -----------" << endl;
    cout << "                                        " << matrix[1][0] << " | " << matrix[1][1] << " | " << matrix[1][2] << " " << endl;
    cout << "                                       ------------" << endl;
    cout << "                                        " << matrix[2][0] << " | " << matrix[2][1] << " | " << matrix[2][2] << " " << endl;
}

int addmark(char mark)
{
    for (int i = 0, k = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++, k++)
        {
            if (k == input)
            {
                if (matrix[i][j] == ' ')
                {
                    matrix[i][j] = mark;
                    return 1;
                }
                else
                    return 0;
            }
        }
    }
}

int check(char mark){
    //three row
    if(matrix[0][0]==mark&&matrix[0][1]==mark&&matrix[0][2]==mark)
    return 1;
    if(matrix[1][0]==mark&&matrix[1][1]==mark&&matrix[1][2]==mark)
    return 1;
    if(matrix[2][0]==mark&&matrix[2][1]==mark&&matrix[2][2]==mark)
    return 1;

    //three column
    if(matrix[0][0]==mark&&matrix[1][0]==mark&&matrix[2][0]==mark)
    return 1;
    if(matrix[0][1]==mark&&matrix[1][1]==mark&&matrix[2][1]==mark)
    return 1;
    if(matrix[0][2]==mark&&matrix[1][2]==mark&&matrix[2][2]==mark)
    return 1;

    //two diagonals
    if(matrix[0][0]==mark&&matrix[1][1]==mark&&matrix[2][2]==mark)
    return 1;
    if(matrix[2][0]==mark&&matrix[1][1]==mark&&matrix[0][2]==mark)
    return 1;


    return 0;
}
