#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <cstdio>
#include<iomanip>
using namespace std;
int r;
int chkacc(int a);
class bms{
    //data encaptulation
    protected: // data hiding
         char id[20], password[15];
    private:
        int m;
    public: // data abstraction
      
        bms(){ //constructor
            system("color f4");
            cout<<"\n\n\n\n\n";
            cout<<setw(80)<<" WELCOME TO CBE BANKING SYSTEM\n  "<<endl;
            cout<<'\a';
                cout<<setw(70)<<"ACCOUNT TYPE\n"<<endl;
            cout<<setw(70)<<"[1] . ADMINISTRATOR "<<endl;
            cout<<setw(63)<<"[2] . USER \n\n"<<endl;
            cout<<setw(70)<<"Enter Your Choice .... ";
            cin>>m;
            if (m != 1 && m != 2) {
                system("cls");
                bms();
            }
            system("cls");
            authenticate();
        }
        void authenticate(){
            system("color f4");
            cout<<" WELCOME TO CBE BANKING SYSTEM "<<endl;
            login();
            if (verify() == 1) {
                if (m == 1)
                    menu();
                else
                    transactions();
            } else if (verify() == 0) {
                system("cls");
                cout<<"Incorrect Username / Password !!!!"<<endl;
                authenticate();
            }
        }
      void login(){ // Takes the user-name and password .
            cout<<"Enter The Username : ";
            cin>>id;
            cout<<"Enter The Password : ";
            cin>>password;
        }
        int verify(){ // verifies the user-name and password .
            char a;
            if (m == 1) {
                if ((strcmp(id, "a") == 0 && strcmp(password, "a") == 0)) {
                        cout<<"You Have Successfully Logged In : "<<'"'<<id<<'"'<<endl;
                    time_t t;
                    time(&t);
            cout<<"Logged In Time : "<<ctime(&t);
            cout<<"Press any key to continue .... ";
                    getch();
                    return 1;
                } else
                    return 0;
            } else if (m == 2) {
                if (strcmp(id, "user") == 0 && strcmp(password, "user") == 0) {
                   cout<<"You Have Successfully Logged In : "<<'"'<<id<<'"'<<endl;
                    time_t t;
                    time(&t);
            cout<<"Logged In Time : "<<ctime(&t);
                    cout<<"Press any key to continue .... ";
                    getch();
                    return 1;
                } else
                    return 0;
            }
            return 0;
        }
        void menu(){ // displays the main user interface screen of program .
            system("cls");
            cout<<" WELCOME TO MAIN MENU "<<endl;
              cout<<"[1] . View Customer Accounts"<<endl;
              cout<<"[2] . Customer Account Registration"<<endl;
              cout<<"[3] . Edit Customer Account"<<endl;
              cout<<"[4] . Delete Customer Account"<<endl;
              cout<<"[5] . Search Customer Account"<<endl;
              cout<<"[6] . Transaction"<<endl;
              cout<<"[7] . Log Out !!! "<<endl;   
              cout<<"[8] . About US "<<endl;
            cout<<"Please Enter Your Choice [1-8] : ";
            option();
        }
        void option() { // takes user choice and goes to desired function .
            int i;
            cin>>i;
            system("cls");
            switch (i) {
                case 1:
                    view();
                    break;
                case 2:
                    add();
                    break;
                case 3:
                    edit();
                    break;
                case 4:
                    del();
                    break;
                case 5:
                    srch();
                    break;
                case 6:
                    transactions();
                    break;
                case 7:
                 menuexit();
                    break;
                case 8:
                    about();
                    break;
                default:
                    menu();
            }
        }
        void view();
        void add();
        void edit();
        void del();
        void srch(){ //module for searching account ( 2 types by number and name )
            system("cls");
            int a;
            cout<<" SEARCH MENU "<<endl;
            cout<<"[1] . Search By Account "<<endl;
            cout<<"[2] . Search By Name "<<endl;
            cout<<"Enter Your Choice [1-2] : "<<endl;
            scanf("%d", &a);
            system("cls");
            if (a == 1) {
                search_acc();
            } else if (a == 2) {
                search_name();
            } else
                menu();
        }
        void search_acc();
        void search_name();
        void transactions(){ // displays screen for the transaction options and takes the user choice .
            system("CLS");  
            cout<<" TRANSACTION MENU "<<endl;
           cout<<"[1] . Balance Inquiry"<<endl;  
           cout<<"[2] . Cash Deposit"<<endl;
           cout<<"[3] . Cash Withdrawal"<<endl; 
            cout<<"[4] . Fund Transfer"<<endl;
            if (m == 1) {  
              cout<<"[5] . Main Menu"<<endl;
            } else {
              cout<<"[5] . Exit"<<endl;
            }
            cout<<"Please Enter Your Choice [1-5] : "<<endl;
            int a;
            scanf("%d", &a);
            switch (a) {
                case 1:
                    system("cls");
                    chkblnc();
                    break;
                case 2:
                    system("cls");
                    deposit();
                    break;
                case 3:
                    system("cls");
                    withdrawl();
                    break;
                case 4:
                    system("cls");
                    transfer();
                    break;
                case 5:
                    if (m == 1)
                        menu();
                    else
                        menuexit();
                        break;
                default:
                    transactions();
            }
        }
        void chkblnc();
        void deposit();
        void withdrawl();
        void transfer();
        void menuexit();
        void about(){
        
              cout<<" ABOUT US "<<endl;
              cout<<"It is a Simple Bank Management System Project for our 2nd year based on C++ programming language."<<endl;
               cout<<"Members of Team : "<<endl;
               cout<<"[1] . Natnael Getachew"<<endl;
               cout<<"[2] . Eyob Tesfaye Metaferiya"<<endl;
                cout<<"[3] . Marta Dereje"<<endl;
                 cout<<"[4] . Betelhem Kassahun "<<endl;
                  cout<<"[5] . Mekdes Demisse"<<endl;
                    cout<<"Press any key to return back to main menu. "<<endl;
                    char z = getch();
                    if (z == 13) {
                    menu();
            }
        }
};
class record{ //inheritance
    public:
	        char name[25];
        int account;
        char phone[15];
        char address[25];
        char email[35];
        char citiz[20];
        double blnc;
        char UserID[10];
};

// module for viewing account details
// Include iomanip header for setw()

void bms::view() {
    int i = 7;
    record rec;
    
    ifstream f;
    f.open("record.bin", ios::in | ios::binary);
    
    cout << " CUSTOMERS LIST\n"; 
    cout << "__________________________\n";  
    cout << setw(10) << "A/C No." << setw(20) << "Account Name" << setw(20) << "UserID" << setw(30) << "Email Address" <<setw(15) << "Phone No." << setw(15) << "Balance\n";

    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        cout << setw(8) << rec.account << setw(17) << rec.name<<setw(21) ;
        for (int r = 0; r < 10; r++) {
            cout << (int)rec.UserID[r];
        }
        cout << setw(20) << rec.email << setw(15) << rec.phone << setw(16) << rec.blnc << "ETB \n";
        i++;
    }
    
    f.close();
    
    int x;
    cout << "Press [Enter] to return back to main menu. \n";
    x = getch();
    if (x == 13) { // 13 = '\r' i.e carriage return
        menu();
         } else
        view();
    
};
//module for adding accounts.
void bms:: add(){
    char c;
    record rec;
    //app = append binary / write data to the file
    ofstream f;
    f.open("record.bin", ios::app | ios::binary); // data will be written at end of the file
    int i = 0, x;
    // first we evaluate body and check condition
    do {
        system("cls");
        cout<<"+==============================+"<<endl;
        cout<<" CUSTOMER ACCOUNT REGISTRATION "<<endl;
        cout<<"+==============================+"<<endl;
        cout<<"[1] . Enter Your Name : ";
        cin>>rec.name;
        cout<<"[2] . Enter Your Account Number: ";
        scanf(" %d", &rec.account);
        cout<<"[3] . Enter Your Phone Number : ";
        cin>>rec.phone;
        cout<<"[4] . Enter Your Address : ";
        cin>>rec.address;
        cout<<"[5] . Enter Your E-mail : ";
        cin>>rec.email;
        cout<<"[6] . Enter Amount To Deposit : ETB ";
        scanf(" %lf", &rec.blnc);
        srand(time(0)); //random number
        for (r = 0; r < 10; r++) {
            rec.UserID[r] = rand() % 10;
        }
        //write() = for writing binary data
        // reinterpret_cast - casting one pointer data type to another pointer data type
        //This helps to write contents in a class variable in the file and stores it in the variable rec.
        f.write(reinterpret_cast<char*>(&rec), sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is
      cout<<endl;
	    cout<<"============================================"<<endl;
        cout<<"CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL"<<endl;
         cout<<"============================================"<<endl;
         cout<<endl;
        i++;
        cout<<"Do You Want To Add Another Record ? (Y/N) : ";
        scanf(" %c", &c);
    } while (c == 'Y' || c == 'y');
    f.close();
    cout<<"Press any key to return back to main menu. "<<endl;
    char z = getch();
    if (z == 13) {
        menu();
    } else
        view();
}
//module to check whether the entered account is in the database or not
int chkacc(int a) {
    record rec;
    //read binary
    ifstream f;
    f.open("record.bin", ios::in | ios::binary);
    while (!f.eof(  )) {
        f.read(reinterpret_cast<char*>(&rec),sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is
        if (a == rec.account) {
            f.close();
            return 1;
        }
    }
    f.close();
    return 0;
}
// module for editing details.
void bms::edit(){
    record rec;
    ifstream f1;
    ofstream f2;
    int a, c;
re: //label for goto 
 cout<<"+==============================+"<<endl; 
    cout<<" EDIT CUSTOMER ACCOUNT "<<endl;  
     cout<<"+==============================+"<<endl;
      cout<<endl;
	  cout<<"Enter Your Account Number To Edit : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary); //read
        f2.open("new.bin", ios::app | ios::binary); //write
        while (f1.read(reinterpret_cast<char*>(&rec),sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec),sizeof(rec));
            else if (rec.account == a) {
                cout<<"Account Number Matched"<<endl;
                cout<<"Enter Your Details"<<endl;
                cout<<"[1] . Enter Your Name : ";
                cin>>rec.name;
                cout<<"[2] . Enter Your Account Number : ";
                scanf(" %d", &rec.account);
               cout<<"[3] . Enter Your Phone Number   : ";
                cin>>rec.phone;
                 cout<<"[4] . Enter Your Address        : ";
                cin>>rec.address;
                cout<<"[5] . Enter Your E-mail         : ";
                cin>>rec.email;
                f2.write(reinterpret_cast<char*>(&rec),sizeof(rec));
            }
        }
        f1.close();
        f2.close();
    }
    if (chkacc(a) == 0) {
        system("CLS");
    cout<<"Account Doesn't Exist. "<<endl;
      goto re; // unconditional jump statement goto <label>
    }
    remove("record.bin");
    rename("new.bin", "record.bin");
     cout<<endl;
     cout<<"+=======================================+"<<endl;
    cout<<"CUSTOMER ACCOUNT UPDATE SUCCESSFULL"<<endl;
     cout<<"+=======================================+"<<endl;
      cout<<endl;
    cout<<"Press any key to return back to main menu . "<<endl;
    getch();
    menu();
}
//module for deleting account
void bms::del(){
    record rec;
    ifstream f1;
    ofstream f2;
    int a, c;
re:  
    cout<<" DELETE CUSTOMER ACCOUNT "<<endl;   
	 cout<<"Enter Your Account Number To Delete : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        }
                f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("record.bin", ios::out | ios::binary); // write only
        f2.open("new.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char*>(&rec), sizeof(rec)))
            f1.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        f1.close();
        f2.close();
    } else if (chkacc(a) == 0) {
        system("CLS");
        cout<<"Account Doesn't Exist";
        goto re;
    } 
	cout<<endl;
	cout<<"+==============================+"<<endl;
    cout<<"CUSTOMER ACCOUNT DELETED SUCCESSFULLY"<<endl;
     cout<<"+==============================+"<<endl;
     cout<<endl;
    cout<<"Press any key to return back to main menu. ";
    getch();
    menu();
}
void bms::search_acc() {
        record rec;
        ifstream f;
        int b = 0;
        int a, x, interestRate = 0.06;
    re:
      cout<<" SEARCH CUSTOMER ACCOUNT "<<endl;
       cout<<"Enter Your Account Number To Search : ";
        scanf("%d", &a);
        if (chkacc(a) == 1) {
            f.open("record.bin", ios::in | ios::binary);
            while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
                if (rec.account == a) {
                    cout<<"Account Number Matched"<<endl;
                     cout<<"Detail Information of "<< rec.name<<endl;
                    cout<<"[1] . Account Number : "<< rec.account<<endl;
                    cout<<"[2] . Name           : "<< rec.name<<endl;
                    cout<<"[3] . UserID       : ";
                    for (r = 0; r < 10; r++) {
                        cout<<(int)rec.UserID[r];
                    }
                  cout<<"\n[4] . Phone Number   : "<< rec.phone<<endl;
                  cout<<"[5] . Address        : "<< rec.address<<endl;
                  cout<<"[6] . E-mail         : "<< rec.email<<endl;
                   cout<<"[7] . Citizenship No : "<< rec.citiz<<endl;
                    cout<<"[8] . Current Balance: "<< rec.blnc<<endl;
                    cout<<"[9] . Status         : ";
                    if (rec.blnc > 25){
                        cout<<"Active"<<endl;
                    } else{
                        cout<<"Inactive"<<endl;
                    }
                                cout<<"[10] . Acquired Interest: ";
                        double monthlyInterestRate = interestRate / 12;
                        double monthlyInterest = rec.blnc * monthlyInterestRate;
                        rec.blnc += monthlyInterest;
                        cout<<rec.blnc<<"ETB "<<endl;
                        cout<<endl;
                        break;
                } else
                    b = 1;
            }
            f.close();
        }
        if (chkacc(a) == 0) {
            system("CLS");
            cout<<"||||||| Account Doesn't Exist.|||||||| "<<endl;
            goto re;
        }
        cout<<"Press [ENTER] to return back to main menu. "<<endl;
        char z = getch();
        if (z == 13)
            menu();
        else
            srch();
}
void bms::search_name() {
    int i = 0, b, x, interestRate = 0.06;
    char nam[30];  
    cout<<" SEARCH CUSTOMER ACCOUNT "<<endl;   
	 cout<<"Enter Your Full Name To Search : ";
    cin>>nam;
    record rec;
    ifstream f;
    f.open("record.bin", ios::in | ios::binary);
    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        b = 0;
        strupr(rec.name);
        strupr(nam);
        if (strcmp(rec.name, nam) == 0) {
            cout<<"Account Number Matched"<<endl;
                cout<<"Detail Information of "<< rec.name<<endl;
            cout<<"[1] . Account Number : "<< rec.account<<endl;
            cout<<"[2] . Name           : "<< rec.name<<endl;
            cout<<"[3] . UserID         : ";
            for (r = 0; r < 10; r++) {
                cout<<(int)rec.UserID[r];
            }cout<<endl;
          cout<<"[4] . Phone Number   : "<< rec.phone<<endl;
           cout<<"[5] . Address        : "<< rec.address<<endl;
            cout<<"[6] . E-mail         : "<< rec.email<<endl;
            cout<<"[7] . Citizenship No : "<< rec.citiz<<endl;
            cout<<"[8] . Current Balance: "<< rec.blnc<<endl;
                cout<<"[9] . Status         : ";
            if (rec.blnc > 25){
                cout<<"Active"<<endl;
            } else{
                cout<<"Inactive"<<endl;
            }
                cout<<"[10] . Acquired Interest: ";
                double monthlyInterestRate = interestRate / 12;
                double monthlyInterest = rec.blnc * monthlyInterestRate;
                rec.blnc += monthlyInterest;
                cout<<rec.blnc<<"ETB "<<endl;
                cout<<endl;
            break;
        } else
            b = 1;
    }
    f.close();
    if (b == 1) {
        system("cls");
       cout<<"Account Doesn't Exist. "<<endl;
        search_name();
    }
    cout<<"Press [ENTER] to return back to main menu. "<<endl;
    char z = getch();
    if (z == 13)
        menu();
    else
        srch();
}
void bms:: chkblnc(){ // module for checking account balance and displaying it
    record rec;
    ifstream f;
    int a;  
    cout<<" BALANCE INQUIRY "<<endl;
    cout<<"Enter Your Account Number : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f.open("record.bin", ios::in | ios::binary);
        while (f.read(reinterpret_cast<char*>(&rec),sizeof(rec))) {
            if (rec.account == a) {
         cout<<"Your Balance is : ETB "<< rec.blnc<<endl;
            }
        }
        f.close();
    }
    if (chkacc(a) == 0) {
        system("cls");
        cout<<"Account Doesn't Exist."<<endl;
        chkblnc();
    }cout<<endl;
    cout<<"Press any key to return back to main menu. "<<endl;
    getch();
    transactions();
}
void bms::deposit() { // module for adding amount to a account
    int a;
    double b;
    record rec;
    ifstream f1;
    ofstream f2;  
    cout<<" CASH DEPOSIT "<<endl;
    cout<<"Enter Your Account Number : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
              cout<<"Enter The Amount To Deposit : ETB  ";
                scanf("%lf", &b);
                rec.blnc += b;
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            }
        }
        f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("record.bin", ios::out | ios::binary); // write only
        f2.open("new.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char*>(&rec), sizeof(rec)))
            f1.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        f1.close();
        f2.close();
    }
    if (chkacc(a) == 0) {
        system("CLS");
        cout<<"Account Doesn't Exist. "<<endl;
        deposit();
    }
	cout<<endl;
	cout<<"+============================+"<<endl;
    cout<<"CASH DEPOSIT SUCCESSFULL"<<endl;
    cout<<"+============================+"<<endl;
    cout<<endl;
    cout<<"Press any key to return back..."<<endl;
    getch();
    transactions();
}
void bms::withdrawl(){ // module to withdraw amount from account
    record rec;
    ifstream f1;
    ofstream f2;
    int a;
    double b, z;  
    cout<<" CASH WITHDRAWAL "<<endl;
    cout<<"Enter Your Account Number :";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        cout<<"Enter The Amount To Withdraw : ETB  ";
        scanf("%lf", &b);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                z = rec.blnc;
                if (b <= rec.blnc) {
                    rec.blnc -= b;
                    cout<<endl;
                    cout<<"+============================+"<<endl;
              cout<<"    CASH WITHDRAWAL SUCCESSFULL     "<<endl;
              cout<<"+============================+"<<endl;
              cout<<endl;
                }
                if (rec.blnc > 100){
                    rec.blnc -= 1;
                cout<<" 1ETB  withdrawn charge taken "<<endl;
                }
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            }
        }
        f1.close();
        f2.close();
        remove("record.bin");
        rename("new.bin", "record.bin");
        if (z < b) {
            system("CLS");
            cout<<"Current Balance is "<< z<<endl;
            cout<<"Entered amount exceeds current balance"<<endl;
            withdrawl();
        }
    }
    if (chkacc(a) == 0) {
        system("CLS");
        cout<<"Account Doesn't Exist."<<endl;
        withdrawl();
    }
    cout<<"     Press Any Key To Continue ....   ";
    getch();
    transactions();
}
void bms::transfer(){ // module for transfering amount from 1 acc to another
    int a;
    double b, z;
    record rec;
    ifstream f1;
    ofstream f2;
    f1.open("record.bin", ios::in | ios::binary);
    f2.open("new.bin", ios::out | ios::binary);  
    cout<<" CASH TRANSFER "<<endl;
    cout<<"Enter Your Account Number : ";
re:
    scanf("%d", &a);
    if (chkacc(a) == 0) {
        system("CLS");
        cout<<"Account Doesn't Exist."<<endl;
        goto re;
    } else if (chkacc(a) == 1) {
        cout<<"Enter The Amount To Transfer   : ETB  ";
        scanf("%lf", &b);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                if (b < rec.blnc) {
                    z = rec.blnc;
                    rec.blnc -= b;
                }
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            }
        }
    }
    f1.close();
    f2.close();
    remove("record.bin");
    rename("new.bin", "record.bin");
    if (b > z) {
   cout<<"Current Balance is ETB "<< z<<endl;
        cout<<"Entered amount exceeds current balance"<<endl;
        transactions();
    }
    f1.open("record.bin", ios::in | ios::binary);
    f2.open("new.bin", ios::out | ios::binary);
    cout<<"Enter Recipient Account Number : ";
    scanf("%d", &a);
    if (chkacc(a) == 0) {
        cout<<"Account Doesn't Exist."<<endl;
    } else if (chkacc(a) == 1) {
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                rec.blnc += b;
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            }
        }
        f1.close();
        f2.close();
        remove("record.bin");
        rename("new.bin", "record.bin");
    }
	cout<<endl;
	cout<<"+============================+"<<endl;
    cout<<"        CASH TRANSFER SUCCESSFULL        "<<endl;
    cout<<"+============================+"<<endl;
    cout<<endl;
    cout<<"        Press Any Key To Continue ....        ";
    getch();
    system("cls");
    transactions();
}

void bms::menuexit(){ //module for logging out of the program. 
    system("cls"); 
        cout<<" THANK YOU "<<endl; 
        cout<<"USER            :: "<< id<<endl; 
        time_t t; 
        time(&t); 
        cout<<"Logged Out Time :: "<< ctime(&t); 
        fflush(stdin); 
        getch(); 
        exit(0);}
int main()
{
    bms w;
   
     
    return 0;
}
