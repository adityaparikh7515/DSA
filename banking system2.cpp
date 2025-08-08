//This project is a simple banking system that demonstrates the core concepts of polymorphism, encapsulation, and inheritance in object-oriented programming.
//It allows users to create different types of bank accounts (like Saving and Fixed Deposit), perform transactions, calculate interest, and retrieve account information.

#include<iostream>
using namespace std;

//------------------ BankAccount Base class ------------------

class BankAccount {

protected:
    long long AccountNumber;
    string AccountHolderName;
    double balance;

public:
							// method to get account information from user
    void get_info() {
        cout<<"Enter your name: ";
        cin>>AccountHolderName;
        cout<<"Enter your account number: ";
        cin>>AccountNumber;
        cout<<endl;
        balance = 0;
    }
							// method to deposit amount
    void deposit() {
        double amount;
        cout<<"Enter amount you want to deposit: ";
        cin>>amount;
         if(amount>0){				// entered amount must be in positive value
         
         	 balance += amount;    // balance=balance+amount
        cout<<"Your balance is " << balance << " rs" <<endl;
		 } else{
		 	cout<<"invalid amount entered"<<endl;
		 }
       
    }
    
							// method to withdraw amount from balance
    void withdraw() {
        double amount;
        cout<<"Enter amount you want to withdraw: ";
        cin>>amount;
        if(amount>0){
		
        if (amount < balance) {          			// Allow withdrawal only if the entered  amount is less than balance
            balance -= amount;
            cout<<"You withdraw: " << amount << " rs" <<endl;
            cout<<"Your remaining balance: " << balance << " rs" <<endl;
        } else {
            cout<<"Insufficient balance! Available: " << balance << " rs" <<endl;
        }
    }
    else{
    	cout<<"enter valid amount";
	}
}
							// method to show current balance
    void getBalance() {
        cout<<"Your Current Balance is: " << balance << " rs" <<endl;
    }

							// method to dispaly Account Information
    void displayAccountInfo() {
        cout<<"Account holder name is: " << AccountHolderName <<endl;
        cout<<"Account number : " << AccountNumber <<endl;
        cout<<"Current balance is: " << balance << " rs" <<endl;
    }
};

	//---------- Derived class:SavingAccount inherit to BankAccount----------
	
class SavingAccount : public BankAccount {
public:
	
			//method to calculate interest for Saving Account
			
    void calculateInterest(double interestRate) {
        double interest = balance * interestRate;     
        balance += interest; 
        cout<<"Interest added: Rs. " << interest <<endl;
        cout<<"New balance after interest: Rs. " << balance <<endl;
    }
};

	// ----------Derived class:Fixed Deposit Account inherit to BankAccount----------
	
class FixedDepositAccount : public BankAccount {

protected:
    int term;
    double interestRate;

public:
	
         // method to calculate interest for Fixed Diposit Account
         
    void calculateInterest() {
        double amount;
        int term;
        double interestRate = 0.06;  // 6% interest
 			
 		
		
        cout<<"Enter amount for fixed deposit: ";
        cin>>amount;
        if(amount>0){
        cout<<"Enter duration time (in months) for fixed deposit: ";
        cin>>term;

        double interest = amount * interestRate * (term / 12.0);
        amount += interest;

        cout<<"Interest added (Fixed Deposit): Rs." << interest <<endl;
        cout<<"New balance after interest: Rs." << amount <<endl;
    }  else{
    	cout<<"please enter valid amount";
	}
     }	
};

      // ---------------- Main function start here ----------------      
	    
int main() {
	

    cout << "\t\t\t\t\t\t\t\t     Welcome to MyBank App     " << endl <<endl;
    

		//  switch case for selecting  account type
    int accChoice;
    cout<<"Press 1 for Saving Account"<<endl;
    cout<<"Press 2 for Fixed Deposit"<<endl<<endl;
    cout<<"select Account Type: ";
    cin>>accChoice;
    cout<<endl;

    switch (accChoice) {

    case 1: {
        SavingAccount saving;       // Saving Account object
        saving.get_info();

			//switch case for selecting Banking Operation
			
        int choice;
        do {
            cout<<"\n----Menu----\n" <<endl;
            cout<<"Press 1 for Deposit" <<endl;
            cout<<"Press 2 for Withdraw" <<endl;
            cout<<"Press 3 for Get Balance" <<endl;
            cout<<"Press 4 for Display Account Info" <<endl;
            cout<<"Press 0 for Exit\n" <<endl;
            cout<<"please select your choice: ";
            cin>>choice;
            cout<<endl;

            switch (choice) {
            case 1:
                saving.deposit();
                break;
            case 2:
                saving.withdraw();
                break;
            case 3:
                saving.getBalance();
                break;
            case 4:
                saving.displayAccountInfo();
                break;
            case 0:
                cout<<"Exiting..." <<endl;
                break;
            default:
                cout<<"Invalid choice" <<endl;
                break;
            }

        } while (choice != 0);

        saving.calculateInterest(0.02); // 2% interest
        cout<<"\nProgram has been terminated successfully." <<endl;
        break;
    }

    case 2: {
        FixedDepositAccount fd;	// Fixed Diposit Account object
        fd.get_info();
        fd.calculateInterest();
        cout<<"\nProgram has been terminated successfully." << endl;
        break;
    }

    default:
        cout<<"Invalid account type!" <<endl;
        break;
    }

    return 0;
    
}
\
