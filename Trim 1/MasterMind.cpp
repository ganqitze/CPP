/*
Lab05_guess.cpp A simple game
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int  num1, num2, num3, num4, trial; 
	

	cout << "Let us play!" << endl;
	cout << "Please enter 4 secret number (separated by spaces) => ";
	cin >> num1 >> num2 >> num3 >> num4;
	cout << "Now go get a friend and ask him/her to guess the numbers!" << endl;
	cout << "trial?" <<endl;
	cin >> trial;
	trial =trial+1;

	system("pause");
	system("cls");
	cout << "Let us see if you can read my mind!" << endl;

	
	int trialNum = 1;
	bool done = false;
	bool win = false;
	bool HP = false;
	bool hue = false;

	while ( !done)
	{
		int guess1, guess2, guess3, guess4;
		cout <<"your trial" <<trialNum;
		cout << "Please enter 4 number (separated by spaces) => ";
		cin >> guess1 >> guess2 >> guess3 >> guess4;

		int correct;
		correct = 0;	//reset to zero
		if (guess1 == num1)
		correct = correct + 1; 
		if (guess2 == num2)
		correct = correct + 1;
		if (guess3 == num3)
		correct = correct + 1; 
		if (guess4 == num4)
		correct = correct + 1;

		cout << "Number of correct guess = " << correct << endl; cout << endl;

		trialNum = trialNum + 1;
		if (correct == 4){
			win = true;
			done = true;			
			if (trialNum <= 6){
				if (trialNum <=3){
					HP = true;
				}
				hue = true;
			}			
		}
		if (trialNum == trial)
			done = true;
	}

	if (win){
		cout << "Congratulation!!" << endl;
		if(HP){
		cout << "You must be Harry Potter" << endl;
		}
		else if(hue){
			cout << "Not bad" << endl;
		}
		else{
			cout << "you being lucky"<< endl;
		}
	}
	else
		cout << "You lost!" << endl;
		cout << "you failed to read my mind....go learn from Harry Potter" <<endl;
		cout << "the ans is: " ;
		cout << num1 << "	" << num2 <<endl;


}