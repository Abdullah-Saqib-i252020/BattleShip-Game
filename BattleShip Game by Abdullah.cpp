#include<iostream>
#include <windows.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;



//======MUHAMMAD ABDULLAH SAQIB======
//BATTLESHIP GAME 


//GLOBAL
char playerBoard[10][10];
char computerBoard[10][10];
int Computer_ship = 5;
int Player_ship=5; 
int cmiss=0;
int cattack=0;
int player_color=2,computer_color=6;
int p1color,p2color;
int shipAttackComputer[5]={0,0,0,0,0};
int shipAttackPlayer[5]={0,0,0,0,0};
bool gameOver=false;
string game_playerNames[2];
int game_scores[2];
int game_totalPlayers=0;

char b1[10][10];
char b2[10][10];

//COLORS
const int BLACK = 0;
const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int MAGENTA = 5;
const int YELLOW = 6;
const int WHITE = 7;


//FUNCTION PROTOTYPES
void initializeBoard(char board[10][10]);
void placeShipsManually(char board[10][10],int shipcolor);
void clearBoard(char board[10][10]);
void setRandomShips(char board[10][10],int shipcolor);
void vsComputer(char playerBoard[10][10], char computerBoard[10][10]);
void clearScreen();
void setColor(int, int);
void computerAttack(char playerBoard[10][10], int &computerScore);
void updateScore(int &score);
void ForplayerAttack(char computerBoard[10][10],int&playerScore);
bool isValidateRandom(char board[10][10], int , int , int , bool );
void printThreeBoards(char leftBoard[10][10], char middleBoard[10][10], char rightBoard[10][10], bool hideShips);
void printboard1(char board[10][10],bool hideships);
void updateLeaderboard(string playerName, int score);
void showLeaderboard();


void displayResult(int player1Score, int player2Score);
void vsPlayer(char board1[10][10],char board2[10][10]);
void placeShipsManually(char board[10][10],int shipcolor);
int activeShip(char board[10][10]);
void playerAttack(char opponentBoard[10][10],int&playerScore);
void printboard(char board[10][10],bool hideships);
bool isValidateRandom1(char board[10][10], int row, int col, int size, bool orientation);
void setRandomShips1(char board[10][10],int shipcolor);
void showGameMenu();

int main()
{
  	srand(time(0));
	showGameMenu();
	return 0;
}

void showGameMenu()
{

int choice;
	cout<<"     -----------------------------------------"<<endl<<"     -----------------------------------------";
	cout<<endl<<"\t    WELCOME TO BATTLESHIP GAME"<<endl;
	cout<<"     -----------------------------------------"<<endl<<"     -----------------------------------------";
	cout<<endl<<endl<<endl<<"\t\t  MAIN MENU "<<endl<<"\t\t-------------"<<endl;
	cout<<"1- Start a new game."<<endl;
	cout<<"2- Instructions."<<endl;
	cout<<"3- View Leaderboard."<<endl;
	cout<<"4- Exit."<<endl;
	cout<<"Enter your choice (1-4): ";
	cin>>choice;
	
	bool btellchoice=false;
int tellchoice;

if(choice==1)
{
    while(btellchoice==false)
    {

        cout<<endl<<" With Whom Do You Want To Play ? Enter(1/2) : "<<endl<<"1. Player vs Computer"<<endl<<"2. Player vs Player"<<endl;
        cin>>tellchoice;

        if(tellchoice==1 || tellchoice==2)
        {
            btellchoice=true;
        }

        else
            cout<<endl<<"Invalid choice!! Try again."<<endl;
    }

    if(tellchoice==1)
    {
        clearScreen();
        string name1;

        cout<<"Now Your Opponent Is A Computer "<<endl;
        cout<<"Enter Player Name: ";
        cin>>name1;

        initializeBoard(playerBoard);
        int choice;
        cout<<"1- Want to place ships manually? "<<endl;
        cout<<"2- Want to place ships randomly? "<<endl;
        cin>>choice;

        if(choice==1)
        {
            placeShipsManually(playerBoard,player_color);
        }

        else if(choice==2)
        {
            clearBoard(playerBoard);
            setRandomShips(playerBoard, player_color);

            bool satisfied=false;
            char response;

            while(!satisfied)
            {
                cout<<endl<<"Are you satisfied with the random placement? (y/n): ";
                cin>>response;

                if(response=='y' || response=='Y')
                {
                    satisfied=true;
                    cout<<"Ship placement confirmed!"<<endl;
                }
                else if(response=='n' || response=='N')
                {
                    clearBoard(playerBoard);
                    setRandomShips(playerBoard, player_color);
                    cout<<"New random placement generated."<<endl;
                }
                else
                {
                    cout<<"Invalid input! Please enter 'y' or 'n'."<<endl;
                }
            }
        }

        initializeBoard(computerBoard);
        cout<<endl<<"Computer Board: "<<endl;
        setRandomShips(computerBoard,computer_color);
        cout<<endl;

        vsComputer(playerBoard, computerBoard);
    }

    //Student 2
    else
    {
        clearScreen();
        string name1,name2;
        int p1score,p2score;

        cout<<"Enter Player 1 Name : "<<endl;
        cin>>name1;
        cout<<"\nPlayer 1 Choose Your Battleship Colour : "<<endl;
        cout<<"1.Blue\n 2.Green\n 3.Cyan\n 4.Red\n 5.Yellow\n 6.black\n 7.White\n 8.Magenta\n"<<endl;
        cin>>p1color;

        cout<<"Enter Player 2 Name : "<<endl;
        cin>>name2;
        cout<<"\nPlayer 2 Choose Your Battleship Colour : "<<endl;
        cout<<"1.Blue\n 2.Green\n 3.Cyan\n 4.Red\n 5.Yellow\n 6.black\n 7.White\n 8.Magenta\n"<<endl;
        cin>>p2color;

        //player 1
        initializeBoard(b1);
        cout<<"Player 1 Place Your ships : "<<endl<<endl;
        int choice2;
        cout<<"1- Want to place ships manually? "<<endl;
        cout<<"2- Want to place ships randomly? "<<endl;
        cin>>choice2;

        if(choice2==1)
        {
            placeShipsManually(b1,p1color);
        }

        else if(choice2==2)
        {
            clearBoard(b1);
            setRandomShips1(b1, p1color);

            bool satisfied2=false;
            char response2;

            while(!satisfied2)
            {
                cout<<endl<<"Are you satisfied with the random placement? (y/n): ";
                cin>>response2;

                if(response2=='y' || response2=='Y')
                {
                    satisfied2=true;
                    cout<<"Ship placement confirmed!"<<endl;
                }
                else if(response2=='n' || response2=='N')
                {
                    clearBoard(b1);
                    setRandomShips1(b1, p1color);
                    cout<<"New random placement generated."<<endl;
                }
                else
                {
                    cout<<"Invalid input! Please enter 'y' or 'n'."<<endl;
                }
            }
        }

        clearScreen();
        //player 2
        initializeBoard(b2);
        cout<<"Player 2 Place Your ships : "<<endl<<endl;
        int choice3;
        cout<<"1- Want to place ships manually? "<<endl;
        cout<<"2- Want to place ships randomly? "<<endl;
        cin>>choice3;

        if(choice3==1)
        {
            placeShipsManually(b2,p2color);
        }

        else if(choice3==2)
        {
            clearBoard(b2);
            setRandomShips1(b2, p2color);

            bool satisfied3=false;
            char response3;

            while(!satisfied3)
            {
                cout<<endl<<"Are you satisfied with the random placement? (y/n): ";
                cin>>response3;

                if(response3=='y' || response3=='Y')
                {
                    satisfied3=true;
                    cout<<"Ship placement confirmed!"<<endl;
                }
                else if(response3=='n' || response3=='N')
                {
                    clearBoard(b2);
                    setRandomShips1(b2, p2color);
                    cout<<"New random placement generated."<<endl;
                }
                else
                {
                    cout<<"Invalid input! Please enter 'y' or 'n'."<<endl;
                }
            }
        }

        vsPlayer(b1,b2);
    }
}

	
	if (choice==2){
		cout<<"\t \t ------ INSTRUCTIONS ------"<<endl;
		cout<<"1- Place your ship on the board."<<endl;
		cout<<"2- You and the computer take turns firing shots. "<<endl;
		cout<<"3- 'O' means miss, 'X' means hit "<<endl;
		cout<<"4- Sink all enemy ships to sink"<<endl;
		cout<<"5- Your score is based on accuracy and speed"<<endl;
		cout<<"----------------------------------------------------"<<endl;
		cout<<"(Press any key to return to main menu)"<<endl;
	}
	if(choice==3){
		showLeaderboard();
	}
}

void updateLeaderboard(string playerName,int score)
{
    ofstream file("highscores.txt", ios::app);
    if(file)
    {file<<playerName<<" "<<score<<endl;}
    file.close();
}

void showLeaderboard()
{
    clearScreen();
    cout<<"=====LEADERBOARD====="<<endl;
    ifstream file("highscores.txt");
    if(!file)
    { cout<<"No scores saved yet!"<<endl;
      return;
    }
    string playerNames;
    int scores;
    int totalPlayers=1;
    while(file>>playerNames>>scores)
    {	cout<<totalPlayers<<"."<<playerNames<<"-"<<scores<<" points"<<endl;
        totalPlayers++;
    }
    file.close();
}





void ForplayerAttack(char computerBoard[10][10],int&playerScore)
{
    int row,col;
    bool validAttack=false;
    
    while(!validAttack)
    {
        cout<<"Enter coordinates (row column 0-9): ";
        cin>>row>>col;
        
        if(row<0||row>9||col<0||col>9)
        {
            cout<<"Invalid coordinates! Use 0-9."<<endl;
            continue;
        }
        
        if(computerBoard[row][col]=='X'||computerBoard[row][col]=='O')
        {
            cout<<"Already attacked! Try again."<<endl;
            continue;
        }
        
        validAttack=true;
    }
    
    if(computerBoard[row][col]=='A'||computerBoard[row][col]=='B'||computerBoard[row][col]=='D'||computerBoard[row][col]=='S'||computerBoard[row][col]=='P')
    {
        if(computerBoard[row][col]=='A')
        {
            if(shipAttackPlayer[0]<5)
            {
                shipAttackPlayer[0]++;
            }
            if(shipAttackPlayer[0]==4)
            {
                Computer_ship--;
                setColor(15,5);
                computerBoard[row][col]=='S';
                setColor(7,0);
            }
        }
        
        if(computerBoard[row][col]=='B')
        {
            if(shipAttackPlayer[1]<4)
            {
                shipAttackPlayer[1]++;
            }
            if(shipAttackPlayer[1]==3)
            {
                Computer_ship--;
                setColor(15,5);
                computerBoard[row][col]=='S';
                setColor(7,0);
            }
        }
        
        if(computerBoard[row][col]=='D')
        {
            if(shipAttackPlayer[2]<3)
            {
                shipAttackPlayer[2]++;
            }
            if(shipAttackPlayer[2]==2)
            {
                Computer_ship--;
                setColor(15,5);
                computerBoard[row][col]=='S';
                setColor(7,0);
            }
        }
        
        if(computerBoard[row][col]=='S')
        {
            if(shipAttackPlayer[3]<3)
            {
                shipAttackPlayer[3]++;
            }
            if(shipAttackPlayer[3]==2)
            {
                Computer_ship--;
                setColor(15,5);
                computerBoard[row][col]=='S';
                setColor(7,0);
            }
        }
        
        if(computerBoard[row][col]=='P')
        {
            if(shipAttackPlayer[4]<2)
            {
                shipAttackPlayer[4]++;
            }
            if(shipAttackPlayer[4]==1)
            {
                Computer_ship--;
                setColor(15,5);
                computerBoard[row][col]=='S';
                setColor(7,0);
            }
        }
        
        computerBoard[row][col]='X';
        playerScore+=10;
        cout<<"HIT! +10 points"<<endl;
    }
    else if(computerBoard[row][col]=='~')
    {
        computerBoard[row][col]='O';
        playerScore-=1;
        if(playerScore<0)
            playerScore=0;
        cout<<"MISS! -1 point"<<endl;
    }
    
    if(Computer_ship==0)
    {
        cout<<"Player wins. ";
        gameOver=true;
    }
    
    cout<<"Score: "<<playerScore<<endl;
}

void computerAttack(char playerBoard[10][10],int&computerScore)
{
    cout<<"computer attack function";
    int row,col;
    bool target=false;
    
    while(!target)
    {
        row=rand()%10;
        col=rand()%10;
        cout<<endl<<"row "<<row<<" col "<<col<<endl;
        cout<<"char at "<<playerBoard[row][col]<<endl;
        
        if(playerBoard[row][col]=='X'||playerBoard[row][col]=='O')
        {
            continue;
        }
        
        target=true;
    }

    if(playerBoard[row][col]=='~')
    {
        playerBoard[row][col]='O';
        cmiss++;
        updateScore(computerScore);
        cout<<"Computer MISSED at ("<<row<<","<<col<<")"<<endl;
    }
    else if(playerBoard[row][col]=='A'||playerBoard[row][col]=='B'||playerBoard[row][col]=='D'||playerBoard[row][col]=='S'||playerBoard[row][col]=='P')
    {
        if(playerBoard[row][col]=='A')
        {
            if(shipAttackComputer[0]<5)
            {
                shipAttackComputer[0]++;
            }
            if(shipAttackComputer[0]==4)
            {
                Player_ship--;
                setColor(15,5);
                (playerBoard[row][col]=='S');
                setColor(7,0);
            }
        }
        else if(playerBoard[row][col]=='B')
        {
            if(shipAttackComputer[1]<4)
            {
                shipAttackComputer[1]++;
            }
            if(shipAttackComputer[1]==3)
            {
                Player_ship--;
                setColor(15,5);
                (playerBoard[row][col]=='S');
                setColor(7,0);
            }
        }
        else if(playerBoard[row][col]=='D')
        {
            if(shipAttackComputer[2]<3)
            {
                shipAttackComputer[2]++;
            }
            if(shipAttackComputer[2]==2)
            {
                Player_ship--;
                setColor(15,5);
                (playerBoard[row][col]=='S');
                setColor(7,0);
            }
        }
        else if(playerBoard[row][col]=='S')
        {
            if(shipAttackComputer[3]<3)
            {
                shipAttackComputer[3]++;
            }
            if(shipAttackComputer[3]==2)
            {
                Player_ship--;
                setColor(15,5);
                (playerBoard[row][col]=='S');
                setColor(7,0);
            }
        }
        else if(playerBoard[row][col]=='P')
        {
            if(shipAttackComputer[4]<2)
            {
                shipAttackComputer[4]++;
            }
            if(shipAttackComputer[4]==1)
            {
                Player_ship--;
                setColor(15,5);
                (playerBoard[row][col]=='S');
                setColor(7,0);
            }
        }
        
        playerBoard[row][col]='X';
        cattack++;
        updateScore(computerScore);
        cout<<"Computer HIT at ("<<row<<","<<col<<")!"<<endl;
        
        if(Player_ship==0)
        {
            cout<<"Computer wins "<<endl;
            gameOver=true;
        }
    }
}

void updateScore(int&score)
{
    if(cattack==1)
    {
        score=score+10;
        cattack=0;
    }
    else if(cmiss==1)
    {
        score=score-1;
        cmiss=0;
    }
    
    if(score<0)
        score=0;
}

void vsComputer(char playerBoard[10][10],char computerBoard[10][10])
{
    int Player_score=0,computerScore=0;
    int turn=1;

    computer_color=5;

    while(!gameOver)
    {
        if(turn==1)
        {
            cout<<"Computer Turn:"<<endl;
            for(int i=0;i<6&& !gameOver;i++)
            {
                computerAttack(playerBoard,computerScore);
                printThreeBoards(playerBoard,playerBoard,computerBoard,false);
            }
            cout<<"Computer Score: "<<computerScore<<" | Player ships: "<<Player_ship<<endl;
            turn=0;
        }
        else
        {
            cout<<"Player Turn:"<<endl;
            for(int i=0;i<6&& !gameOver;i++)
            {
                ForplayerAttack(computerBoard,Player_score);
                printThreeBoards(computerBoard,computerBoard,playerBoard,false);
            }
            cout<<"Player Score: "<<Player_score<<endl;
            cout<<"Computer ships remaining: "<<Computer_ship<<endl;
            turn=1;
        }
    }

    cout<<"GAME OVER"<<endl;
    cout<<"Player Score: "<<Player_score<<endl;
    cout<<"Computer Score: "<<computerScore<<endl;

    if(Player_score>computerScore)
        cout<<"Player wins!"<<endl;
    else if(Player_score<computerScore)
        cout<<"Computer wins!"<<endl;
    else
        cout<<"Tie!"<<endl;
        
    updateLeaderboard("Player", Player_score);
	updateLeaderboard("Computer", computerScore);
}

void setRandomShips(char board[10][10],int shipcolor)
{
    int shipSizes[5]={5,4,3,3,2};
    srand(time(0));
    
    cout<<"Placing your ships randomly"<<endl;
    
    for(int i=0;i<5;i++)
    {
        bool placed=false;
        int row,col;
        bool horizontal;
        
        while(!placed)
        {
            row=rand()%10;
            col=rand()%10;
            horizontal=(rand()%2==0);
            
            if(isValidateRandom(board,row,col,shipSizes[i],horizontal))
            {
                if(horizontal)
                {
                    for(int j=0;j<shipSizes[i];j++)
                    {
                        if(shipSizes[i]==5)
                            board[row][col+j]='A';
                        if(shipSizes[i]==4)
                            board[row][col+j]='B';
                        if(shipSizes[i]==3&&i==2)
                            board[row][col+j]='D';
                        if(shipSizes[i]==3&&i==3)
                            board[row][col+j]='S';
                        if(shipSizes[i]==2)
                            board[row][col+j]='P';
                    }
                }
                else
                {
                    for(int j=0;j<shipSizes[i];j++)
                    {
                        if(shipSizes[i]==5)
                            board[row+j][col]='A';
                        if(shipSizes[i]==4)
                            board[row+j][col]='B';
                        if(shipSizes[i]==3&&i==2)
                            board[row+j][col]='D';
                        if(shipSizes[i]==3&&i==3)
                            board[row+j][col]='S';
                        if(shipSizes[i]==2)
                            board[row+j][col]='P';
                    }
                }
                
                placed=true;
                cout<<"Ship size "<<shipSizes[i]<<" is placed successfully!"<<endl;
            }
        }
    }
    
    bool hide=0;
    printboard1(board,hide);
}

bool isValidateRandom(char board[10][10],int row,int col,int size,bool orientation)
{
    if(row<0||row>=10||col<0||col>=10)
        return false;
    
    if(orientation==1&&(col+size>10))
        return false;
    
    if(orientation==0&&(row+size>10))
        return false;
    
    for(int i=0;i<size;i++)
    {
        if(orientation==1)
        {
            if(board[row][col+i]=='A'||board[row][col+i]=='B'||board[row][col+i]=='D'||board[row][col+i]=='S'||board[row][col+i]=='P')
                return false;
        }
        else
        {
            if(board[row+i][col]=='A'||board[row+i][col]=='B'||board[row+i][col]=='D'||board[row+i][col]=='S'||board[row+i][col]=='P')
                return false;
        }
    }
    
    return true;
}




void printThreeBoards(char leftBoard[10][10],char middleBoard[10][10],char rightBoard[10][10],bool hideShips)
{
    cout<<"                ENEMY BOARD                                     OPPONENT BOARD                                                       PLAYER BOARS                  "<<endl;
    cout<<"       0  1  2  3  4  5  6  7  8  9            0    1     2     3     4     5     6     7     8     9                      0  1  2  3  4  5  6  7  8  9"<<endl;
    cout<<"    +------------------------------+       +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+                +------------------------------+"<<endl;

    for(int row=0;row<10;row++)
    {
        cout<<"  "<<row<<" | ";
        
        for(int col=0;col<10;col++)
        {
            char ch=leftBoard[row][col];
            if(ch=='A' || ch=='B' || ch=='D'|| ch=='S'|| ch=='P')
                ch='~';
            else if(ch=='X')
                ch='X';
            else if(ch=='O')
                ch='O';
            else
                ch='~';
            cout<<ch<<"  ";
        }
        cout<<"| ";

        cout<<"  "<<row<<" ¦";
        for(int col=0;col<10;col++)
        {
            char cell=middleBoard[row][col];
            if(cell=='X')
            {
                setColor(15,12);
                cout<<"  X  ";
                setColor(7,0);
            }
            else if(cell=='O')
            {
                setColor(0,8);
                cout<<"  O  ";
                setColor(7,0);
            }
            else
            {
                setColor(15,1);
                cout<<"  ~  ";
                setColor(7,0);
            }
            cout<<"¦";
        }
        cout<<"  ";
        
        cout<<"  "<<row<<" | ";
        for(int col=0;col<10;col++)
        {
            char ch=rightBoard[row][col];
            if(ch=='A' || ch=='B' || ch=='D'|| ch=='S'|| ch=='P')
            {
                ch='S';
                cout<<ch<<"  ";
            }
            else if(ch=='X')
            {
                ch='X';
                cout<<ch<<"  ";
            }
            else if(ch=='O')
            {
                ch='O';
                cout<<ch<<"  ";
            }
            else
            {
                ch='~';
                cout<<ch<<"  ";
            }
        }
        cout<<"|"<<endl;

        if(row<9)
        {
            cout<<"    +------------------------------+       +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦               +------------------------------+"<<endl;
        }
    }
    cout<<"    +------------------------------+       +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+                +------------------------------+"<<endl;
}

void printboard1(char board[10][10],bool hideships)
{
    cout<<endl;
    cout<<"        0    1     2     3     4     5     6     7     8     9  "<<endl;
    cout<<"    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl;

    for(int row=0;row<10;row++)
    {
        cout<<"  "<<row<<" ¦";
        for(int col=0;col<10;col++)
        {
            char cell=board[row][col];
            if(cell=='A'||cell=='B'||cell=='D'||cell=='S'||cell=='P')
            {
                 setColor(0,player_color); 
                cout<<"  S  ";
                setColor(7,0);
            }
            else
            {
                setColor(7,1);
                cout<<"  ~  ";
                setColor(7,0);
            }
            cout<<"¦";
        }
        cout<<endl;
        
        if(row<9)
        {
            cout<<"    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦"<<endl;
        }
    }
    cout<<"    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl;
}



void placeShipsManually(char board[10][10],int shipcolor)
{
    string shipNames[5]={"Aircraft Carrier","Battleship","Destroyer","Submarine","Patrol Boat"};
    int shipSizes[5]={5,4,3,3,2};
    bool shipPlaced[5]={false,false,false,false,false};
    
    int shipsPlaced=0;
    int count=0;
 
    cout<<"Ships data:"<<endl;
    for(int i=0;i<5;i++)
    {
        if(!shipPlaced[i])
        {
            cout<<i+1<<". "<<shipNames[i]<<"(Size: "<<shipSizes[i]<<")"<<endl;
        }
        else
        {
            cout<<i+1<<". "<<shipNames[i]<<" placed"<<endl;
        }
    }
        
		
    while(count<5)
    {
        int shipChoice;
        cout<<"Select ship to place (1-5): ";
        cin>>shipChoice;
        
        while(shipChoice<1||shipChoice>5)
        {
            cout<<"INVALID INPUT! Enter Again : "<<endl;
            cin>>shipChoice;
        }
		
        int i=shipChoice-1;
        int size=shipSizes[i];
        
        if(shipPlaced[i]==true)
        {
            cout<<"This ship is already placed! Choose another "<<endl;
            continue;
        }

        int row,col;
        cout<<"Enter row: ";
        cin>>row;
        cout<<"Enter column: ";
        cin>>col;
        
        if(row<0||row>=10||col<0||col>=10)
        {
            cout<<"Invalid INPUT ! Enter again."<<endl;
            continue;
        }
		
		char direction;
        cout<<"Enter Direction of your ship (H for horizontal & V for vertical):"<<endl;
		cin>>direction;
		
		while((direction!='h'&&direction!='H')&&(direction!='V'&&direction!='v'))
		{
			cout<<"INVALID INPUT! Enter Again : "<<endl;
        	cin>>direction;
		}
		
		
		if((direction=='h'||direction=='H')&&(col+size>10))
		{
			cout<<"Ship is out of boundary ! Enter again."<<endl;
        	continue;
		}

		if((direction=='v'||direction=='V')&&(row+size>10))
		{
			cout<<"Ship is out of boundary ! Enter again."<<endl;
        	continue;
		}
		
		bool overlay=0;

		if(direction=='h'||direction=='H')
		{
    		for(int c=col;c<col+size;c++)
    		{
    			if(board[row][c]=='S')
    			{
    			    cout<<"Ship touch another ship! Enter again."<<endl;
                	overlay=1;
    				break;	
    			}
	      	}
    	}
    	else
    	{
    		for(int r=row;r<row+size;r++)
    		{
    			if(board[r][col]=='S')
    			{
    			    cout<<"Ship touch another ship! Enter again."<<endl;
                	overlay=1;
    				break;	
    			}
	    	}
     	}

		if(overlay==1)
		{
			continue;
		}
		
		if(direction=='h'||direction=='H')
		{ 
    		for(int c=col;c<col+size;c++)
    		{
    			board[row][c]='S';
    		}
        }
    	else
    	{
    		for(int r=row;r<row+size;r++)
    		{
    			board[r][col]='S';
    		}
        }
        
     	cout<<"Ship Placed."<<endl;
     	shipPlaced[i]=true;
		count++;
		
        bool hide=1;
        printboard(board,hide);	
	}
}

void clearBoard(char board[10][10]) 
	{
    	for(int i=0;i<10;i++)
		 {
        	for(int j=0;j<10;j++) 
			{
            	board[i][j] = '~';  
        	}
    	}
	}


//For clearing Screen
void clearScreen() {
   system("clear");  //For Mac /Linux;
	system("CLS"); //For Windows

}

// Set text and background color in Windows console
void setColor(int textColor, int bgColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}


void initializeBoard(char board[10][10]){

    // Initialize 10x10 board with water '~'
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            board[i][j] = '~';

  /*  board[2][3] = 'X'; //FOR Initializing the board with '~' in every cell
    board[7][8] = 'O'; 
*/
    // Print column headers (hardcoded)
    cout << "        0    1     2     3     4     5     6     7     8     9  " << endl;

    // Top border
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;

    // Row 0
    cout << "  0 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[0][i];
        setColor(7, 1); cout << "  ~  "; setColor(7,0); cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 1
    cout << "  1 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[1][i];
        setColor(7, 1); cout << "  ~  "; setColor(7,0); cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 2
    cout << "  2 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[2][i];
        if (cell == 'X') { setColor(15, 12); cout << "  X  "; setColor(7,0); }
        else { setColor(7, 1); cout << "  ~  "; setColor(7,0); }
        cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 3
    cout << "  3 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[3][i];
        setColor(7, 1); cout << "  ~  "; setColor(7,0); cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 4
    cout << "  4 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[4][i];
        setColor(7, 1); cout << "  ~  "; setColor(7,0); cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 5
    cout << "  5 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[5][i];
        setColor(7, 1); cout << "  ~  "; setColor(7,0); cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 6
    cout << "  6 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[6][i];
        setColor(7, 1); cout << "  ~  "; setColor(7,0); cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 7
    cout << "  7 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[7][i];
        if (cell == 'O') { setColor(0, 8); cout << "  O  "; setColor(7,0); }
        else { setColor(7, 1); cout << "  ~  "; setColor(7,0); }
        cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 8
    cout << "  8 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[8][i];
        setColor(7, 1); cout << "  ~  "; setColor(7,0); cout << "¦";
    }
    cout << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦" << endl;

    // Row 9
    cout << "  9 ¦"; 
    for (int i = 0; i < 10; i++)
    {
        char cell = board[9][i];
        setColor(7, 1); cout << "  ~  "; setColor(7,0); cout << "¦";
    }
    cout << endl;

    // Bottom border
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;


}

//Student 2
void vsPlayer(char board1[10][10],char board2[10][10])
{
    int p1score=0,p2score=0;
    int p1ship=5,p2ship=5;
    bool gameOver=false;
    int currentPlayer=1;
    
    while(!gameOver)
    {
        clearScreen();
        
        if(currentPlayer==1)
        {
            p2ship=activeShip(board2);
            int attack=p2ship+1;
            
            cout<<"PLAYER 1'S TURN"<<endl;
            cout<<"Your Board:"<<endl;
            
            clearScreen();
            printThreeBoards(board1,board1,board2,false);
            
            cout<<"Enemy Board:"<<endl;

            clearScreen();
            printThreeBoards(board2,board2,board1,false);
            
            cout<<"Player 1 Score: "<<p1score<<" | Enemy ships: "<<p2ship<<endl;
            cout<<"Shots: "<<attack<<endl;
            
            for(int shot=0;shot<attack;shot++)
            {
                cout<<"Shot "<<(shot+1)<<" of "<<attack<<endl;
                playerAttack(board2,p1score);
                 printThreeBoards(board2,board2,board1,false);
                
                
                int shipsBefore=p2ship;
                p2ship=activeShip(board2);
                
                if(p2ship<shipsBefore)
                {
                    cout<<endl;
					cout<<"You sunk an enemy ship!"<<endl;
                    cout<<"Enemy has "<<p2ship<<" ships left"<<endl;
                    attack=p2ship+1;
                    cout<<"Shots left: "<<(attack-shot-1)<<endl;
                }
                
                if(p2ship==0)
                {
                    cout<<"PLAYER 1 WINS! All enemy ships destroyed!"<<endl;
                    gameOver=true;
                    break;
                }
            }
            
            if(!gameOver)
            {
                currentPlayer=2;
            }
        }
        else
        {
            p1ship=activeShip(board1);
            int attack=p1ship+1;
            
            cout<<"PLAYER 2'S TURN"<<endl;
            
			cout<<"Your Board:"<<endl;
        
            clearScreen();
            printThreeBoards(board2,board2,board1,false);
           
			cout<<"Enemy Board:"<<endl;
        
            clearScreen();
            printThreeBoards(board1,board1,board2,true);
              
            cout<<"Player 2 Score: "<<p2score<<" | Enemy ships: "<<p1ship<<endl;
            cout<<"Shots: "<<attack<<endl;
            
            for(int shot=0;shot<attack;shot++)
            {
                cout<<"Shot "<<(shot+1)<<" of "<<attack<<endl;
                playerAttack(board1,p2score);
                 printThreeBoards(board1,board1,board2,false);
                
                int shipsBefore=p1ship;
                p1ship=activeShip(board1);
                
                if(p1ship<shipsBefore)
                {
                    cout<<"You sunk an enemy ship!"<<endl;
                    cout<<"Enemy has "<<p1ship<<" ships left"<<endl;
                    attack=p1ship+1;
                    cout<<"Shots left: "<<(attack-shot-1)<<endl;
                }
                
                if(p1ship==0)
                {
                    cout<<"PLAYER 2 WINS! All enemy ships destroyed!"<<endl;
                    gameOver=true;
                    break;
                }
            }
            
            if(!gameOver)
            {
                currentPlayer=1;
            }
        }
    }
    
    cout<<"GAME OVER"<<endl;
    displayResult(p1score,p2score);
    updateLeaderboard("Player1", p1score);
	updateLeaderboard("Player2", p2score);  
}
void displayResult(int player1Score, int player2Score)
{
    cout<<"Player 1 Score: "<<player1Score<<endl;
    cout<<"Player 2 Score: "<<player2Score<<endl;
    
    if(player1Score>player2Score)
    {
        cout<<"Player 1 wins!"<<endl;
    }
    else if(player2Score>player1Score)
    {
        cout<<"Player 2 wins!"<<endl;
    }
    else
    {
        cout<<"Tie!"<<endl;
    }
}

int activeShip(char board[10][10])
{
    bool check[10][10]={false};
    int shipCount=0;
    
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(board[i][j]=='S'&&!check[i][j])
            {
                shipCount++;
                int k=j;
                while(k<10&&board[i][k]=='S') // horizontally ship ko check kre ga
                {
                    check[i][k]=true; // jitne S milte gae unme true store krte jow
                    k++;
                }
                k=i;
                while(k<10&&board[k][j]=='S') //vertically check now
                {
                    check[k][j]=true;
                    k++;
                }
            }
        }
    }
    return shipCount;
}


void playerAttack(char opponentBoard[10][10],int&playerScore)
{
    int row,col;
    bool validAttack=false;
    
    while(!validAttack)
    {
        cout<<"Enter coordinates (row column 0-9): ";
        cin>>row>>col;
        
        if(row<0||row>9||col<0||col>9)
        {
            cout<<"Invalid coordinates! Use 0-9."<<endl;
            continue;
        }
        
        if(opponentBoard[row][col]=='X'||opponentBoard[row][col]=='O')
        {
            cout<<"Already attacked! Try again."<<endl;
            continue;
        }
        
        validAttack=true;
    }
    
    if(opponentBoard[row][col]=='S')
    {
        opponentBoard[row][col]='X';
        playerScore+=10;
        cout<<"HIT! +10 points"<<endl;
        
    }
    else
    {
        opponentBoard[row][col]='O';
        playerScore-=1;
        if(playerScore<0)playerScore=0;
        cout<<"MISS! -1 point"<<endl;
    }
    
    cout<<"Score: "<<playerScore<<endl;
}


void printboard(char board[10][10],bool hideships)
{
    cout << endl;
    cout << "        0    1     2     3     4     5     6     7     8     9  " << endl;
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;

    for(int row=0;row<10;row++){
        cout<<"  "<<row<<" ¦";
        for(int col=0;col<10;col++){
            char cell=board[row][col];
            
            if(cell=='S'){
                 setColor(0,15); 
                cout<<"  S  ";
                setColor(7,0);
            } else {
                setColor(7,1);
                cout<<"  ~  ";
                setColor(7,0);
            }
            cout<<"¦";
        }
        cout<<endl;
        
        if(row<9){
            cout<<"    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----¦"<<endl;
        }
    }
    cout<<"    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+"<<endl;
}


void setRandomShips1(char board[10][10],int shipcolor){
    int shipSizes[5]={5,4,3,3,2};
    srand(time(0));
    
    cout<<"Placing your ships randomly"<<endl;
    for(int i=0;i<5;i++){
    		
    	bool placed=false;
		int row,col;
		bool horizontal;	
    	
        while(!placed){
        	row=rand()%10;
        	col=rand()%10;
        	horizontal=(rand()%2==0);
        	
        	if(isValidateRandom1(board,row,col,shipSizes[i],horizontal)){
    	    	if(horizontal){
                     for(int j=0;j<shipSizes[i];j++){
                        board[row][col+j]='S';
                    }
                }
				else{
                    for(int j=0;j<shipSizes[i];j++){
                        board[row+j][col]='S';
                    }
                }
                placed=true;
                cout<<"Ship size "<<shipSizes[i]<<" is placed successfully!"<<endl;
			}
		} 
	}
	bool hide=0;
	printboard(board,hide);	
}
	
bool isValidateRandom1(char board[10][10],int row,int col,int size,bool orientation)
{
		if(row<0||row>=10||col<0||col>=10){
        	return false;
		}
		
		if(orientation==1&&(col+size>10)){
        	return false;
		}
		
		if(orientation==0&&(row+size>10)){
        	return false;
		}
		
		for(int i=0;i<size;i++){
        	if(orientation==1){
           		 if(board[row][col+i]=='S') 
					return false;
        	}
			else{
            	if(board[row+i][col]=='S') 
					return false;
        		}
    	}
		
    	return true;	
}



