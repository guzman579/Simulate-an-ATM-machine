#include <iostream>

#include <cmath>

#include <string>

#include <ctime>

#include <cstdlib>

using namespace std;




int sign_inFun(double balanceArray[], int customers[]);

void showBalanceFun(double balanceArray[], int customerIndex);

void depositMoneyFun(double balanceArray[], int customerIndex);

void withdrawMoneyFun(double balanceArray[], int customerIndex);

int exitFun(double balanceArray[], int customerIndex);



int main()

{
	double balanceArray[] = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
	int customerIndex = -1;
	int customers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };		// account numbers
	int menuNumber;
	bool signed_in = false;
	bool signed_out = true;
	
	while (1)  {	// the main menu
	
		cout << "1.	Sign in" << endl;
		cout << "2.	Balance" << endl;
		cout << "3.	Deposit" << endl;
		cout << "4.	Withdraw" << endl;
		cout << "5.	Exit" << endl << endl;
		
		cout << "Select a number: ";
		cin >> menuNumber;
		
		if (menuNumber < 1 || menuNumber > 5)
			cout << "Error! Enter the number of an item in the menu." << endl << endl;
		
		else
		{	
			if (signed_in == false && menuNumber == 1)  {
				customerIndex = sign_inFun(balanceArray, customers);
				if (customerIndex >= customers[0] && customerIndex <= customers[9]) 
					signed_in = true;
			}

			if (signed_in == true && menuNumber == 2)
				showBalanceFun(balanceArray, customerIndex);

			if (signed_in == true && menuNumber == 3)
				depositMoneyFun(balanceArray, customerIndex);

			if (signed_in == true && menuNumber == 4)
				withdrawMoneyFun(balanceArray, customerIndex);

			if (signed_in == true && menuNumber == 5)  {
				signed_out = exitFun(balanceArray, customerIndex);
				if (signed_out)  {
				    signed_in = false;
				    customerIndex = -1;
				}
			}
		}
			
	}

}


int sign_inFun(double balanceArray[], int customers[])

{	// return the customer index (i.e. account number); otherwise, return -1.

    int signIn;

    cout <<"Enter your account number: " << endl;

    cin >>signIn;
	
	for (int i=0; i<10; i++)
		
		if (signIn == customers[i])  {
			cout << "You are signed in by the account number " << signIn << endl;
			return i;
		}
		
	return -1;

}


void showBalanceFun(double balanceArray[], int customerIndex)

{
    double lowBalance = 100;
	
	cout << "Your balance is: $" << balanceArray[customerIndex] << endl;
    if (balanceArray[customerIndex] < lowBalance)
        cout << "Low Balance" << endl;
}


void depositMoneyFun(double balanceArray[], int customerIndex)

{
	double depositAmount;
	int count = 0;
	
	while (1)  {

		cout << "How much do you want to deposit? $";

		cin >> depositAmount;
		
		if (depositAmount > 0)	{

			balanceArray[customerIndex] = balanceArray[customerIndex] + depositAmount;
			
			cout << "+++++++++++++++++++++++++" << endl;

			cout << "Deposit successful" << endl;

			showBalanceFun(balanceArray, customerIndex);
			
			break;
			
		}

		else
				
			cout << "Invalid amount! Please try again." << endl;
			
			count ++;
			
			if (count >= 2)		break;
		
	}

}

void withdrawMoneyFun(double balanceArray[], int customerIndex)

{

	double withdrawAmount;
	int count = 0;

	while (1)  {
		
		cout << "How much do you want to withdraw? $";

		cin >> withdrawAmount;
		
		if (withdrawAmount <= balanceArray[customerIndex])  {

			balanceArray[customerIndex] = balanceArray[customerIndex] - withdrawAmount;

			cout << "+++++++++++++++++++++++++" << endl;

			cout << "Withdraw successful" << endl;

			showBalanceFun(balanceArray, customerIndex);
			
			break;
        }
		
		else  {
			
			cout << "Error: beyond your balance" << endl;
			
			showBalanceFun(balanceArray, customerIndex);
			
			count ++;
			
			if (count >= 2)		break;
        }
		
	}
	
}

int exitFun(double balanceArray[], int customerIndex)

{	// return 1 if exit == 1; otherwise, return 0.

	int exit;

	cout << "Would you like to exit: 1=yes or 0=not" << endl;

	cin >> exit;

	if (exit == 1)

	{

		cout << "Good bye." << endl;

		return 1;
	}

	return 0;
	
}
