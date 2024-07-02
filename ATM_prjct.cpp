#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

/* ATM
  Check Balance
  Cash Withdraw
  User Details
  Update Mobile No.
*/

class atm
{
private: // private member variables
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public: // public member functions
    // setData function is setting the data into the private member variables
    void setData(long int account_no_a, string name_a, int PIN_a, double balance_a, string mobile_no_a)
    {
        // Assigning the formal arguments to the private member variables
        account_no = account_no_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }

    // getAccountNo function returning the user's account no.
    long int getAccuntNo()
    {
        return account_no;
    }

    // getName function is returning the user's name
    string getName()
    {
        return name;
    }

    // getPIN function is returning the user's PIN
    int getPIN()
    {
        return PIN;
    }

    // getBalance function is returning the user's balance
    double getBalance()
    {
        return balance;
    }

    // get function is returning the user's Mobile No.
    string getMobileNo()
    {
        return mobile_no;
    }

    // setMobileNo function is updating the user's mobile no.
    void setMobileNo(string prev_mobileNo, string new_mobileNo)
    {
        if (prev_mobileNo == mobile_no) // It will check old mobile no.
        {
            mobile_no = new_mobileNo; // It will update the no. with new if matches
            cout << "Succesfully Updated Mobile No. ";
            getch(); // It hold the screen until user press any key
        }
        else
        {
            cout << endl
                 << " Incorrect Old Mobile No. ";
            getch();
        }
    }
    // cashWithdraw function is used to withdraw money from ATM
    void cashWithdraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance) // Check entered amount validity
        {
            balance -= amount_a;
            cout << endl
                 << "Please Collect Your Cash";
            cout << endl
                 << "Available Balance: " << balance;
            getch();
        }
        else
        {
            cout << endl
                 << "Invalid Input or Insufficient Balance";
            getch();
        }
    }
};

int main()
{
    int choice = 0, enterPIN;
    long int enterAccountNo;
    system("cls"); // Used to clean the screen

    // Created object
    atm user1;
    user1.setData(1234567, "ABCD", 9876, 50000.500, "9833763921"); // Set user details

    do
    {
        system("cls");
        cout << endl
             << "*****Welcome to ATM*****" << endl;
        cout << "Enter Your Account No. " << endl;
        cin >> enterAccountNo;

        cout << endl
             << "Enter Your PIN" << endl;
        cin >> enterPIN;

        // Check whether enter values matches with user details
        if ((enterAccountNo == user1.getAccuntNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");
                // User Interface
                cout << endl
                     << "*****Welcome to ATM*****" << endl;
                cout << "Select Options " << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdraw" << endl;
                cout << "3. Show User Details" << endl;
                cout << "4. Update Mobile No." << endl;
                cout << "5. Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << endl
                         << "Your Bank Balance is: " << user1.getBalance();
                    getch();
                    break;

                case 2:
                    cout << endl
                         << "Enter the amount: " << endl;
                    cin >> amount;
                    user1.cashWithdraw(amount); // Calling cashWithdraw function
                                                // passing the withdraw amount
                    break;

                case 3:
                    cout << endl
                         << "User Details are: " << endl;
                    cout << "Account No. " << user1.getAccuntNo() << endl;
                    cout << "Name " << user1.getName() << endl;
                    cout << "Balance " << user1.getBalance() << endl;
                    cout << "Mobile No. " << user1.getMobileNo() << endl;

                    getch();
                    break;

                case 4:
                    cout << endl
                         << "Enter Old Mobile No. ";
                    cin >> oldMobileNo;
                    cout << endl
                         << "Enter New Mobile No. ";
                    cin >> newMobileNo;

                    user1.setMobileNo(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    exit(0);

                default: // Handle invalid user inputs
                    cout << endl
                         << "Enter Valid Data";
                }
            } while (1); // Condition will always TRUE and loop is capable of running infinity times
        }
        else
        {
            cout << endl
                 << " User Details are Invalid ";
            getch();
        }
    } while (1);

    return 0;
}