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
#include <stdlib.h>		//system call library
#include <sstream>		//istreamstring purpose
using namespace std;
int menu;				//menu selection
int row;
int x_marker(2);
int o_marker(2);
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

int main(){
	banner ();	
	menubar();
	cin >> menu;		//selection of menu
	cout << endl;
	system("CLS");		
	switch(menu){
		case 1:
			display_board();
			gameplay();
			break;
		case 2:
			help();
			system("pause");		//press any key to continue...
			system("CLS");
			main();
			break;
		case 3: 
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
	cout << " 2. Help" << endl;
	cout << " 3. Quit" << endl;
	cout << "Selection: ";
}
void display_board(){ 		//game board
	board[4][3]='0';
	board[4][4]='X';
	board[3][3]='X';
	board[3][4]='0';
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
	cout << " Just input your desired position for your marker.\n For example, F3.\n After the input marker, input Next for next player.\n If you wish to return to menu, input Menu.\n You can resume game by select again 1. New Game.\n Although it is NOT a complete game, but Enjoy!\n"; 
}
int gameplay(){			
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
	else if(command == "next"){			//turn to next player to make his move
		if(turn=='X'){
			turn='0';
		}
		else if(turn=='0'){
			turn='X';	
		}
		system("CLS");
		display_board();
		gameplay();
	}
	else{
		row =row -1;
		col=toupper(col);
		a = (int)col-65;			//convert the column input to ASCII
		int col;
		col = a;
		if (col>=0 && col<=7 && row >= 0 && row <= 7 && board[row][col]==' '){ 		//make sure the input position is valid
			{
				if (turn=='X'){
					board[row][col] ='X';
					x_marker=x_marker+1;
				}
				else if (turn=='0'){
					board[row][col] ='0';
					o_marker=o_marker+1;
				}
				else{
					cout << "error. please input again." << endl;
				}
				system("CLS");
				display_board();
				gameplay();
			}
		}	
		else if(col<0 || col>7|| row < 0 || row > 7 || board[row][col]!=' '){
			cout << "error. please input again." << endl;
			gameplay();
		}
	}	
}



