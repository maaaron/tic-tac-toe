#include <iostream>
#include <fstream>
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
    
    bool isFullRowPresent()
    {
      for(int row = 0; row < 3; row++)
        if(this->isRowFull(row))
          return true;
      return false;

    }

    bool isRowFull(int row)
    {
      if(this->game_board[row][0] == this->game_board[row][1] &&
          this->game_board[row][1] == this->game_board[row][2] &&
          this->game_board[row][0] != 0 )
        return true;
      return false;
    }

    bool isFullColumnPresent()
    {
      for(int col = 0; col < 3; col++)
      {
        bool colfull = this->isColumnFull(col);
        if(this->isColumnFull(col))
          return true;
      }
      return false;
    }

     bool isColumnFull(int col)
    {
      if(this->game_board[0][col] == this->game_board[1][col] &&
          this->game_board[1][col] == this->game_board[2][col] &&
          this->game_board[0][col] != 0)
        return true;
      return false;
    }

    bool isFullDiagonalPresent()
    {
      if(this->game_board[0][0] == this->game_board[1][1] &&
        this->game_board[1][1] == this->game_board[2][2] && 
        this->game_board[0][0] != 0 )
        return true;
      if(this->game_board[2][0] == this->game_board[1][1] &&
          this->game_board[1][1]== this->game_board[0][2] &&
          this->game_board[2][0] != 0 )
        return true;
      return false;
    }

};

class Game{
  public:
    Board* board;
    
    Game ()
    {
      this->board = new Board();
    }
    
    void presentCurrentMove(int i)
    {
      cout << "Aktualny ruch ";
      if(i%2 == 0)
        cout << "o";
      else
        cout << "x";
      cout << endl;
    }

    int announceWinner(int i)
    {
      if(i%2 == 0)
        cout << "Gratulacje! Wygralo kolko";
      else
        cout << "Gratulacje! Wygral krzyzyk";
      return i%2 + 1;
    }

    int announceDraw()
    {
      cout << "Remis!";
      return 0;
    }

    int runGame()
    {
      for(int i=0; i<9; i++)
      {
        this->board->showBoard();
        this->makeMove(i);
        if(this->isGameWon())
        {
          this->board->showBoard();
          return this->announceWinner(i);
        }
        this->saveGame();
      }
      this->board->showBoard();
      return this->announceDraw(); 
    }

    bool isMoveValid(int x, int y)
    { 
      if(x > 2 || x < 0 || y > 2 || y < 0 )
      {
        cout << "Chyba sie pomyliłes! Wpisz poprawną wartosc";
        return false;
      }
      if(this->board->game_board[x][y] != 0 )
      {
        cout << "Pole jest zajete!" << endl;
        return false;
      }
      return true;
    }
    
    void makeMove(int i)
    {
        int x, y;
        this->presentCurrentMove(i);
        do
        {
          cout <<"Wpisz x: ";
          cin >> x;
          cout <<"Wpisz y: ";
          cin >> y;
        }while(!this->isMoveValid(x, y));
        this->board->setValue(x, y, i%2+1);
    }

    bool isGameWon()
    {
      if(this->board->isFullColumnPresent()) return true;
      if(this->board->isFullDiagonalPresent()) return true;
      if(this->board->isFullRowPresent()) return true;
      return false;
    }

    void saveGame()
     {
        ofstream outfile ("load.txt");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                outfile << this->board->game_board[i][j];
            }
            outfile << endl;
        }
        outfile.close();
     }

     void loadGame(const char * path)
     {
       fstream plik;
       plik.open ( path, ios::in );
       string dane;
       if( plik.good() == true )
        {
          for(int i = 0; i < 3; i++)
          {  
            getline( plik,dane);
            cout << dane << endl;
          }
          plik.close();
        }
     }
};

int main() {
  Game* gameObject = new Game();
  gameObject->loadGame("SavedGame1.txt");
  //gameObject->saveGame();
  //gameObject->runGame();
  int a;
  cin >> a;
}