#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/*mini project - ATM
-> check balance
-> cash withdraw
-> user detail
-> update mobile no.
*/


class ATM {
    private:
        long int account_no;
        string name;
        int PIN;
        double balance;
        string mobile_no;

        public:
        // seter function
        void setData(long int account_no_a, string name_a, int PIN_a, double balance_a, string mobile_no_a)
        {
            account_no = account_no_a;
            name = name_a;
            PIN = PIN_a;
            balance = balance_a;
            mobile_no = mobile_no_a;
        }
//getaccountno function is retuning the user's account no.
long int getAccountno()
  {
    return account_no;
  }

  //getname function is returning the user's name
  string getName()
  {
    return name;
  }

  //getpin function is returning the user's pin
  int getPIN()
  {
    return PIN;
  }

// getbalance function is returning the user's balance
double getBalance()
{
    return balance;
}

// getmobile_no function is returning the user's mobile
string getMobileNO()
{
    return mobile_no;
}

// setMobileNO function is setting the user's mobile 
void setMobile(string mob_prev, string mob_new)
{
    if (mob_prev == mobile_NO)   //it will check old mobile no
    {
        mobile_NO = mob_new;   //and update with new ,if old
        cout << endl << "successfully update mobile no.";
        _getch();  //getch is used to hold the screen untill user press any key

    }
    else
    {
        cout << endl << "incorrect !!! old mobile no.";
        _getch();
    }
}

//cashWithdraw function is used to withdraw cash from
void cashwithdraw(int amount_a)
{
    if (amount_a > 0 && amount_a < balance) //check entered amount validity
    { 
        balance -= amount_a; //balance = balance - amount_a
        cout << endl << "please collect your cash";
        cout << endl << "Available balance :" << balance;
        _getch();  
     }

     else
     {
        cout << endl << "insufficient balance or invalid";
        _getch();
     }
}


};

//////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{int choice =0 , enterPIN;
long int enterAccountNO;

system("cls");

//created user object
atm user1;
//set user data 
user1.setdata(1234567, "tim", 1111, 45000.90 "9876543210");

do
{
    system("cls");

    cout << endl << "****welcome to ATM****" << endl;
    cout << endl << "enter your account no ";
    cin >> enterAccountNO;

    cout << endl << "enter PIN";
    cin >> enterPIN;


    // check whether enter values matches with user details
		if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
		{
			do
			{
				int amount = 0;
				string oldMobileNo, newMobileNo;

				system("cls");
				// user Interface
				cout << endl << "**** Welcome to ATM *****" << endl;
				cout << endl << "Select Options ";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;
				cin >> choice;						// taking user choice

				switch (choice)						// switch condition
				{
				case 1:								// if user presses 1 
					cout << endl << "Your Bank balance is :" << user1.getBalance(); 
													// getBalance is ... printing the users									bank balance
					_getch();
					break;


				case 2:									// if user presses 2
					cout << endl << "Enter the amount :";		
					cin >> amount;
					user1.cashWithDraw(amount);			// calling cashWithdraw function 
													    // passing the withdraw amount 
					break;


				case 3:										// if user presses 3
					cout << endl << "*** User Details are :- ";
					cout << endl << "-> Account no" << user1.getAccountNo();
					cout << endl << "-> Name      " << user1.getName();
					cout << endl << "-> Balance   " << user1.getBalance();
					cout << endl << "-> Mobile No." << user1.getMobileNo();
													// getting and printing user details
					_getch();
					break;


				case 4:								   //  if user presses 4
					cout << endl << "Enter Old Mobile No. ";
					cin >> oldMobileNo;							// take old mobile no

					cout << endl << "Enter New Mobile No. ";
					cin >> newMobileNo;							// take new mobile no

					user1.setMobile(oldMobileNo, newMobileNo);	// now set new mobile no
					break;

													// if user presses 5
				case 5:
					exit(0);						// exit application

				default:							// handle invalid user inputs
					cout << endl << "Enter Valid Data !!!";
				} 

			} while (1);				// MENU	   // condition will always TRUE and loop is										capable of running infinite times
		}

		else
		{
			cout << endl << "User Details are Invalid !!! ";
			_getch();
		}
	} while (1);						//LOGIN		// condition will always TRUE and loop is										capable of running infinite times

	return 0;
}



