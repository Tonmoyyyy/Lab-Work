#include <iostream>
using namespace std;

struct BankAccount {
  int account_number;
  string account_holder_name;
  double account_balance;
};

void create_account(BankAccount &account) {
  cout << "Enter the account number: ";
  cin >> account.account_number;
  cout << "Enter the account holder's name: ";
  cin >> account.account_holder_name;
  cout << "Enter the initial account balance: ";
  cin >> account.account_balance;
}

void deposit_money(BankAccount &account, double amount) {
  account.account_balance += amount;
  cout << "Deposit successful and New balance is " << account.account_balance << endl;
}

bool withdraw_money(BankAccount &account, double amount) {
  if (amount > account.account_balance) {
    cout << "Insufficient funds and Withdrawal failed." << endl;
    return false;
  }
  account.account_balance -= amount;
  cout << "Withdrawal successful and New balance is " << account.account_balance << endl;
  return true;
}

void display_account(BankAccount &account) {
  cout << "Account number: " << account.account_number << endl;
  cout << "Account holder's name: " << account.account_holder_name << endl;
  cout << "Account balance: " << account.account_balance << endl;
}

int main() {
  BankAccount my_account;
  create_account(my_account);

  int choice;
  double amount;

  while (true) {
    cout << "Menu:"<<endl;
    cout<<"1 Deposit money "<<endl;
    cout<<"2 Withdraw money "<<endl;
    cout<<"3 Display account details "<<endl;
    cout<<"4 Exit"<<endl;
    cout<<"Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
      cout << "Enter the amount to deposit: ";
      cin >> amount;
      deposit_money(my_account, amount);
    } else if (choice == 2) {
      cout << "Enter the amount to withdraw: ";
      cin >> amount;
      if (withdraw_money(my_account, amount)) {

        display_account(my_account);
      }
    } else if (choice == 3) {
      display_account(my_account);
    } else if (choice == 4) {
      cout << "Thank you" << endl;
      break;
    } else {
      cout << "Invalid choice Please try again" << endl;
    }
  }

  return 0;
}
