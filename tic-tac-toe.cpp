#include <iostream>
using namespace std;

class Board{
  public:
    int game_board[3][3];
    
    Board ()
    {   
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                this-> game_board[i][j] = 0;
    }
    
    void setValue(int x, int y, int value)
    {
      this->game_board[x][y] = value;
    }

    void showBoard()
    {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(game_board[i][j]== 0)
                cout << '-' << " ";
                if(game_board[i][j]== 1)
                cout << 'o' << " ";
                if(game_board[i][j]== 2)
                cout << 'x' << " ";
            }
            cout << endl;
        }
    }

    bool isRowFull(int row)
    {
      if(this->game_board[row][0] == this->game_board[row][1] == this->game_board[row][2] &&
        this->game_board[row][0] != 0 && this->game_board[row][1] != 0 && this->game_board[row][2] != 0)
        return true;
      return false;
    }
    
    bool isFullColumnPresent()
    {
      for(int row = 0; row < 3; row++)
        if(this->isRowFull(row))
          return true;
      return false;
      // for(int i=0; i<2; i++)
      //   if(this->game_board[i][0] == this->game_board[i+1][0] != 0)
      //     return true;
      // for(int i=0; i<3; i++)
      //   if(this->game_board[0][i] == this->game_board[0][i+1] != 0)
      //     return true;

    }

    
};

class Game{
  public:
    Board* board;
    
    Game ()
    {
      this->board = new Board();
    }
    
    void startGame()
    {
      for(int i=0; i<9; i++)
      {
        this->board->showBoard();
        this->makeMove(i);
        if(this->isGamefinished())
          cout << "Koniec";
      }
    }

    void makeMove(int i)
    {
        int x, y;
        cout <<"Wpisz x: ";
        cin >> x;
        cout <<"Wpisz y: ";
        cin >> y;
        this->board->setValue(x, y, i%2+1);
    }

    bool isGamefinished()
    {
      if(this->board->isFullColumnPresent()) return true;
      return false;
      // if((this->board->game_board[0][0]==this->board->game_board[0][1]==this->board->game_board[0][2]==1)||
      // (this->board->game_board[0][0]==this->board->game_board[0][1]==this->board->game_board[0][2])==2)
      //   return true;
      // else
      //   return false;
    }
};

int main() {
  Game* gameObject = new Game();
  gameObject->startGame();
  int a;
  cin >> a;
  return 0;
}