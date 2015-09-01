/**********|**********|**********|
Program: GanQiTzeOthello.cpp
Course: TCP1101 Programming Fundamental
Year: 2015/16 Trimester 1
Name: Gan Qi Tze
ID: 1142700525
Email: ganqitze@gmail.com
Phone: 010-2527511
**********|**********|**********/
#include <iostream>
#include <string>
#include <fstream>		//file creation, open, load
#include <cstdlib>		//system call library
#include <sstream>		//istreamstring purpose
using namespace std;
int menu;				//menu selection
int row;
int x_marker(0);
int o_marker(0);
char turn('X');
char col;
string command;
string gameboard("  |---+---+---+---+---+---+---+---|\n");
char board[8][8] = {{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
void banner();
void menubar();
void display_board();
void help();
int gameplay();
int check_move_possible(int& marker_flip, int& row, int& col);
int marker_flip(0);
int check_win();
bool win =false;
bool draw = false;
bool super_1_limit=false;
bool super_2_limit=false;
bool super_3_limit=false;
int score(int& x_marker, int& o_marker);
// int save();
// ifstream in_stream;
// int check_legal_move();

// int check_legal_move(){
// 	int count;
// 	for (a=0; a<8 && a>=0;a++){
// 		for (b=0; b<8 && b>=0; b++){
// 			board[a][b]=turn;
// 			count = check_move_possible( marker_flip, row, col);
// 		}
// 	}
// 	if (count == 0){
// 		//next player
// 		// cout blah blah blah
// 	}
// 	else return;
// }

int main(){
	banner ();	
	menubar();
	cin >> menu;		//selection of menu
	cout << endl;
	system("CLS");		
	switch(menu){
		case 1:
			board[4][3]='0';
			board[4][4]='X';
			board[3][3]='X';
			board[3][4]='0';
			score( x_marker, o_marker);
			display_board();
			gameplay();
			break;
		case 2: 
			// inFile.open("a.txt");
			// break;
		case 3:
			help();
			system("pause");		//press any key to continue...
			system("CLS");
			main();
			break;
		case 4: 
			exit(0);		//exit the program
		default:
			main();
		}
	}

void banner (){			//banner of the game
	string banner(" --------------------------------------");
	cout << endl << banner << endl;
	cout << "|           THE OTHELLO GAME          |" << endl;
	cout << banner << endl;
}

void menubar(){			//menu of the game
	cout << " Welcome to THE OTHELLO GAME!!" << endl;
	cout << " Select and input the representing number."<<endl;
	cout << " 1. New Game" << endl;
	cout << " 2. Load a game" << endl;
	cout << " 3. Help" << endl;
	cout << " 4. Quit" << endl;
	cout << "Selection: ";
}

void display_board(){ 		//game board
	for(int row=0; row<=7; row=row+1){
		cout << gameboard << 8 - row;
		for(int col=0; col<=7; col=col+1){	
			cout << " | " << board[7-row][col];			
		}
		cout <<" |" << endl;
	}	
	cout << gameboard ;
	cout <<" "<<"   a"<<"   b"<<"   c"<<"   d"<<"   e"<<"   f"<<"   g"<<"   h"<<endl;
	cout << endl << " Score:		0 = " << o_marker << "	X = "<< x_marker <<endl;
	cout << " Current Player:	" << turn << endl;
	cout << " ==>  " ;
}

void help(){			//help menu content
	cout << " Just input your desired position for your marker.\n" 
	<< " For example, F3.\n After the input marker, input Next for next player.\n"
	<< " If you wish to return to menu, input Menu.\n You can resume game by select again 1. New Game.\n"
	<< " Although it is NOT a complete game, but Enjoy!\n"; 
}

// int save(){
// ifstream in_a;
// ofstream out_a;
// }
// load --> in_a.open("Filename.dat");
// output --> out_a.open("Filename.dat");
// in_a >> first >> second >> third;
// out_a << "one number = " << out number;
//read slide

// int super(){
// 	int super_number;
// 	cout << "\n Super 1 : 4 corner belong to you. " << endl
// 	<< " Super 2 : It allow you to erase any row you like. " << endl
// 	<< " Super 3 : The game will anounce you win with 1/3 chance.\n\n"
// 	<< " Which super power do you wish to use? ==> ";
// 	cin >> super_number;
// 	switch(super_number){
// 		case 1:
// 		if(super_1_limit==false){
// 			super_1_limit=true;
// 			board[0][0]=turn;
// 			board[0][7]=turn;
// 			board[7][7]=turn;
// 			board[7][0]=turn;
// 		}
// 		else{
// 			cout << " Error. Please input again." <<endl;
// 			super();
// 		}
// 		break;
// 		case 2: 
// 		int erase_row;
// 		if (super_2_limit == false){
// 			super_2_limit =true;
// 			cout << " Which row do you wish to erase? ==> ";
// 			cin >> erase_row;
// 			for(int k=0; k<8 && k>=0; k++){
// 					board[erase_row-1][k]=' ';
// 			}		
// 		}
// 		else{
// 			cout << " Error. Please input again." <<endl;
// 			super();
// 		}	
// 		break;
// 		case 3:
// 		if (super_3_limit == false){
// 			super_3_limit = true;
// 			int probability = (rand()%3);
// 			cout << probability;
// 			if (probability ==2 ){
// 				for(int i=0; i<8; i++){
// 					for(int j=0; j<8; j++){
// 						board[i][j]=turn;
// 					}
// 				}
// 			}
// 		}
// 		else{
// 			cout << " Error. Please input again." <<endl;
// 			super();
// 		}
// 		break;
// 		default:
// 		cout << " Error. Please input again." <<endl;
// 		super();
// 		break;
// 	}
// }


int check_move_possible(int& marker_flip, int& row, int& col){
	int c;
	int r;
	int marker_placed=-1;
	marker_flip=0;
	if (board[row][col]!=' ' )
		return 0;	
	{
		marker_placed=-1;				//right
		for (c=col+1; c<8 && board[row][c]!=' ' && board[row][c]!=turn; c++){
			if (board[row][c]!=turn)
				marker_placed=c ;
		}
		if(board[row][c]!=turn)
			marker_placed=-1;
		if (marker_placed!=-1 && marker_placed>=col+1){
			for (int c = col + 1;marker_placed>=c; c++){				
				board[row][c] = turn;
				marker_flip++;
			}
		}
	}{	marker_placed=-1;				//left
		for(c=col-1; c>=0 && board[row][c]!=' '&& board[row][c]!=turn; c--){
			if (board[row][c]!=turn)
				marker_placed=c;
		}
		if(board[row][c]!=turn)
			marker_placed=-1;
		if (marker_placed!=-1 && marker_placed<=col-1){
			for (int c = col - 1;marker_placed<=c; c--){
				board[row][c] = turn;
				marker_flip++;
			}
		}

	}{	marker_placed=-1;
		int r;				//above
		for(r=row+1; r<8 &&  board[r][col] != turn && board[r][col] != ' '  ; r++){
			if(board[r][col]!=turn)
				marker_placed=r;
		}
		if(board[r][col]!=turn)
			marker_placed=-1;
		if (marker_placed!=-1 && marker_placed>=row+1){
			for (int r = row + 1;marker_placed>=r; r++){
				board[r][col] = turn;
				marker_flip++;
			}
		}
	}{	marker_placed=-1;			//below
		for(r=row-1;r>=0 && board[r][col]!=' ' && board[r][col]!=turn ;r--){
			if (board[r][col]!=turn)
				marker_placed=r;
		}
		if(board[r][col]!=turn)
			marker_placed=-1;
		if (marker_placed!=-1 && marker_placed<=row-1){
			for (int r = row - 1;marker_placed<=r; r--){
				board[r][col] = turn;
				marker_flip++;
			}
		}
	}{	marker_placed=-1;
		c=col+1;			//diagonal up-right
		for(r=row+1; c<8 && r<8 && board[r][c]!=' ' && board[r][c]!=turn; r++){
			if (board[r][c]!=turn)
				marker_placed=c;
			c++;		
		}
		if(board[r][c]!=turn)
			marker_placed=-1;
		if (marker_placed!=-1 && marker_placed>=col+1){
			int r=row+1;
			for (int c = col + 1;marker_placed>=c; c++){
				board[r][c] = turn;
				marker_flip++;
				r++;
			}
		}
	}{	marker_placed=-1;
		c=col-1;				//diagonal down-left
		for(r=row-1;c>=0 && r>=0 && board[r][c]!=' ' && board[r][c]!=turn;r-- ){
			if (board[r][c]!=turn)
				marker_placed=c;
			c--;
		}
		if(board[r][c]!=turn)
			marker_placed=-1;
		if (marker_placed!=-1 && marker_placed<=col-1){
			r=row-1;
			for (int c = col - 1;marker_placed<=c; c--){
				board[r][c] = turn;
				marker_flip++;
				r--;
			}
		}
	}{	marker_placed=-1;
		c=col-1;				//diagonal up-left
		for(r=row+1;c>=0 && r<8 && board[r][c]!=' ' && board[r][c]!=turn;r++){
			if (board[r][c]!=turn)
				marker_placed=c;
			c--;			
		}
		if(board[r][c]!=turn)
			marker_placed=-1;
		if (marker_placed!=-1 && marker_placed<=col-1){
			r=row+1;
			for (int c = col -1;marker_placed<=c; c--){
				board[r][c] = turn;
				marker_flip++;
				r++;
			}
		}
	}{	marker_placed=-1;
		c=col+1;		 			//diagonal down-right
		for(r=row-1;c<8 && r>=0 && board[r][c]!=' ' && board[r][c]!=turn; r--){
			if (board[r][c]!=turn)
				marker_placed=c;
			c++;		
		}
		if(board[r][c]!=turn)
			marker_placed=-1;
		if (marker_placed!=-1 && marker_placed>=col+1){
			r=row-1;
			for (int c = col +1;marker_placed>=c; c++){
				board[r][c] = turn;
				marker_flip++;
				r--;
			}
		}
	}	
	if(marker_flip==0)
		board[row][col]=' ';

	return marker_flip;
}

int score(int& x_marker, int& o_marker){
	x_marker=0;
	o_marker=0;
 	for (int x=0; x<8 && x>=0; x++){
 		for ( int y=0; y<8 && y>=0; y++){
 			if(board[x][y]=='X'){
 				x_marker++;
 			}
 			else if(board[x][y]=='0'){
 				o_marker++;
 			}
 			else{;}
 		}
 	}
}

int check_win(){
	if(x_marker==0){
		turn = '0';
		win = true;
	}
	else if(o_marker == 0){
		turn ='X';
		win = true;
	}
	else{
		int i,j;
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if (board[i][j]==' '){
					return 0;
				}
			}
		}
			if (x_marker > o_marker){
				turn = 'X';
				win = true;
			}
			else if (x_marker < o_marker){
				turn ='0';
				win = true;
			}
			else if(x_marker == o_marker){
				draw=true;				
			}
	}
}



int gameplay(){	
	score(x_marker, o_marker);	
	check_win();
	if (!win && !draw){
		int a;				
		cin.sync();				//allow to input
		getline(cin,command);
		istringstream marker(command);		//separate the string input to both column and row		
		marker >> col >> row;
		for(int k=0; k<command.length(); k++){		//let all the string input to be lowercase
			command[k]=tolower(command[k]);
		}	
		if (command == "menu"){				//jump to menu
			system("CLS");
			main();
		}
		// else if (command=="save"){
		// 	save();
		// }
		else if(command == "next")					//turn to next player to make his move
		{	
			if(turn=='X'){
				turn='0';
			}
			else if(turn=='0'){
				turn='X';	
			}
			//system("CLS");
			score(x_marker, o_marker);
			display_board();
			gameplay();
		}
		else if(command == "super1")					//turn to next player to make his move
		{
			if(super_1_limit==false){
				super_1_limit=true;
				board[0][0]=turn;
				board[0][7]=turn;
				board[7][7]=turn;
				board[7][0]=turn;
				score(x_marker, o_marker);
				display_board();
				gameplay();
			}
			else{
				cout << " Error. Please input again." <<endl;
				gameplay();
			}
		}
		else if(command == "super2")					//turn to next player to make his move
		{	
			int erase_row;
			if (super_2_limit == false){
				super_2_limit =true;
				cout << " Which row do you wish to erase? ==> ";
				cin >> erase_row;
				for(int k=0; k<8 && k>=0; k++){
					board[erase_row-1][k]=' ';
				}
				score(x_marker, o_marker);
				display_board();
				gameplay();				
			}
			else{
				cout << " Error. Please input again." <<endl;
				gameplay();
			}
		}	
		else if(command == "super3")					//turn to next player to make his move
		{	
			if (super_3_limit == false){
				super_3_limit = true;
				int probability = (rand()%3);
				cout << probability;
				if (probability ==2 ){
					for(int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							board[i][j]=turn;
						}
					}
				}
				score(x_marker, o_marker);
				display_board();
				gameplay();
			}
			else{
				cout << " Error. Please input again." <<endl;
				gameplay();
			}			
		}	

		else{
			row =row -1;
			col=toupper(col);
			a = (int)col-65;			//convert the column input to ASCII
			int col;
			col = a;
			check_move_possible(marker_flip, row, col);

			if( marker_flip==0 || col<0 || col>7|| row < 0 || row > 7 || board[row][col]!=' '){
				cout << " Error. Please input again.\a" << endl;
				row = -1; col= -1;
				gameplay();
			}

			else if (col>=0 && col<=7 && row >= 0 && row <= 7 && board[row][col]==' ' )
			{ 		//make sure the input position is valid
				{	
					if (turn=='X'){	
						board[row][col] = turn;
						// x_marker=x_marker+marker_flip+1;
						// o_marker=o_marker-marker_flip;
						// if(super_2_limit)
						// 	turn='X';
						turn = '0';
					}
					else if (turn=='0'){
						board[row][col] = turn;
						// x_marker=x_marker-marker_flip;
						// o_marker=o_marker+marker_flip+1;
						// if(super_2_limit)
						// 	turn='0';
						turn = 'X';
					}
					else{
						cout << " Error. Please input again.\a" << endl;
						row = -1; col= -1;
					}
					
			// 		if(super_2_limit){
			// 	if(turn=='X'){
			// 	turn='0';
			// 	}
			// 	else if(turn=='0'){
			// 		turn='X';	
			// 	}
			// }
					//system("CLS");
					score(x_marker, o_marker);
					display_board();
					row = -1; col= -1;
					gameplay();

				}
			}
		}	
	}
	
	else if(win){
		cout << "\nGame Over! " << endl;
		cout << "Congratulation. Player " << turn << " Wins!" <<endl;
		cout << "Player X : " << x_marker << " point" << endl;
		cout << "Player 0 : " << o_marker << " point" << endl;
	}
	else if (draw){
		cout <<  "\nGame Over!" << endl
		<< "Draw! " << endl;
	}
}

