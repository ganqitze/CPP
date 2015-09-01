/*
Lab06_pensionplans.cpp

Purpose :
- Create a simple financial application to calculate retirement plans
*/

#include <iostream>
#include <cstdlib> 
using namespace std;

void displayMenu()
{
	system("cls");
	cout <<endl;	
	cout << "+---------------------------------------+" << endl;
	cout << "|   Golden Years Financial Inc.		|" << endl; 
	cout << "|=======================================|" << endl;
	cout << "| Select:				|" << endl;
	cout << "|  1 => Display Data			|" << endl;
	cout << "|  2 => Change Data			|" << endl; 
	cout << "|---------------------------------------|" << endl;
	cout << "|  3 => One Lump Sum Withdrawal Plan 	|" << endl; 
	cout << "|  4 => Yearly Withdrawal Plan   	|" << endl; 
	cout << "|  5 => Comparison of Both Plans   	|" << endl; 
	cout << "|---------------------------------------|" << endl;
	cout << "|   Q => Quit				|" << endl; 
	cout << "+---------------------------------------+" << endl;
	cout << endl;
	cout << "Choice => ";
}


void displayData(int startingAge, int numOfYears, double lumpSumAmount, double yearlyAmount, double interestRate){

	cout << endl;
	cout << "Starting Age   = " << startingAge   << endl; 
	cout << "Nunber of Years  = " << numOfYears  << endl; 
	cout << "Lump Sum Amount = " << lumpSumAmount << endl; 
	cout << "Yearly Amount  = " << yearlyAmount  << endl; 
	cout << "Interest Rate (%) = " << interestRate << endl; cout << endl;
	system("pause");
}

void changeData(int& startingAge, int& numOfYears,	double& lumpSumAmount, double& yearlyAmount, double& interestRate){
	
	cout << endl;
	cout << "Starting Age = "; 
	cin	>> startingAge;
	cout << "Nunber of Years = ";
	cin	>> numOfYears;
	cout << "Lump Sum Amount = "; 
	cin	>> lumpSumAmount;
	cout << "Yearly Amount = "; 
	cin	>> yearlyAmount;
	cout << "Interest Rate (%) = ";
	cin	>> interestRate;
	system("pause");
}
void oneLumpSumWithdrawal( int startingAge, int numOfYears,
	double lumpSumAmount, double interestRate ){
	int age = startingAge;
	int lastAge = startingAge + numOfYears; 
	double cash = lumpSumAmount;
	cout << "Age |    Yearly Plan" <<endl;
	cout << "----+----------------" << endl;
	while (age <= lastAge)
	{
		cout.width(3);
		cout << age << " | "; 
		cout.width(15);
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << cash << endl;

		if (age != lastAge)
			cash = cash + cash*interestRate / 100.0; age++;
	}
}
void yearWithdrawal( int startingAge, int numOfYears,
	double yearlyAmount, double interestRate ){
	int age = startingAge;
	int lastAge = startingAge + numOfYears; 
	double cash = yearlyAmount;
	double totalamount;
	cout << "Age |    Yearly Plan" <<endl;
	cout << "----+----------------" << endl;
	while (age <= lastAge)
	{
		cout.width(3);
		cout << age << " | "; 
		cout.width(15);
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << cash << endl;

		if (age != lastAge){
			totalamount = cash + cash*interestRate / 100.0;
			cash =yearlyAmount+totalamount;
		} 
			age++;
	}
}
void compare( int startingAge, int numOfYears,double lumpSumAmount, double yearlyAmount, double interestRate )
	{
	int age = startingAge;
	int lastAge = startingAge + numOfYears; 
	double cashlump = lumpSumAmount;
	double cashyear = yearlyAmount;
	double totalamount = yearlyAmount;
	cout << "Age |   LumpSum Plan |	Yearly Plan" <<endl;
	cout << "----+----------------+----------------" << endl;
	while (age <= lastAge)
	{
		cout.width(3);
		cout << age << " | "; 
		cout.width(15);
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << cashlump << endl;
		cout.width(15);
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << cashyear << endl;

		if (age != lastAge){
			cashlump = cashlump + cashlump*interestRate / 100.0;
			totalamount=cashyear + cashyear*interestRate/100.0;
			cashyear =yearlyAmount+totalamount;
		}
			age++;
	}
	if(cashlump>cashyear){
		cout << "you are advised to choose the Lump Sum Plan!" <<endl;
	}	
	else{
		cout << "you are advised to choose the Yearly Plan!" <<endl;
	}
}

int main()
{
	int	startingAge(55); 
	int	numOfYears(20);
	double lumpSumAmount(400000); 
	double yearlyAmount(25000); 
	double interestRate(5);

	char choice;
	bool done = false; 
	do{
		displayMenu();
		cin >> choice;
		choice = toupper(choice);
		switch (choice)
		{
			case '1' : displayData(startingAge,numOfYears, lumpSumAmount,yearlyAmount,interestRate);
			break;
			case '2' : changeData(startingAge, numOfYears, lumpSumAmount, yearlyAmount, interestRate);
			break;
			case '3' : oneLumpSumWithdrawal(startingAge, numOfYears, lumpSumAmount,interestRate );
			system("pause");
			break;
			case '4' :yearWithdrawal(startingAge, numOfYears, yearlyAmount,interestRate );
			system("pause");
			break;
			case '5' : compare(startingAge, numOfYears, lumpSumAmount, yearlyAmount,interestRate );
			system("pause");
			break;
			case 'Q' : done = true;
			break;
			default	: cout << "Invalid selection, try again!" << endl; 
			system("pause");
			break;
		}
	} 
	while (!done);{

		cout << "Good Bye!" << endl; 
		cout << endl;

	}
	return 0;

}