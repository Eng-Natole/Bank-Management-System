Bank Management System (BMS) 💳🏦
Overview
Welcome to the Bank Management System (BMS), a simple yet efficient system implemented in C++. This system enables users to manage banking operations such as account creation, transactions, and customer records. Designed for both administrators and regular users, it offers different levels of access and functionality.

Features 🚀
Account Management:
👁️ View customer accounts
✍️ Register new customer accounts
✏️ Edit existing customer accounts
❌ Delete customer accounts
🔍 Search customer accounts by account number or name
Transactions:
💰 Balance inquiry
💵 Cash deposit
💳 Cash withdrawal
💸 Fund transfer
User Authentication:
🔑 Login system for both administrators and users
🔒 Password protection for secure access
Miscellaneous:
📝 About section with team details
🚪 Logout functionality
How to Use ⚙️
Prerequisites
A C++ compiler (e.g., GCC, Clang, MSVC)
A terminal or command prompt to run the program
Compilation
To compile the program, use the following command:

bash
Copy
Edit
g++ -o bms main.cpp
Running the Program
Once compiled, run the program using:

bash
Copy
Edit
./bms
User Interface 🖥️
Welcome Screen
Upon starting the program, you'll be greeted with a welcome screen where you can choose your account type (Administrator or User).

Login 🔑
Enter the username and password:

Administrator:
Username: a
Password: a
User:
Username: user
Password: user
Main Menu 📋
Administrator:
👁️ View customer accounts
✍️ Register new customer accounts
✏️ Edit customer accounts
❌ Delete customer accounts
🔍 Search customer accounts
💳 Perform transactions
🚪 Log out
ℹ️ About us
User:
💳 Perform transactions
🚪 Log out
Transactions:
💰 Balance inquiry
💵 Cash deposit
💳 Cash withdrawal
💸 Fund transfer
Logout:
You can log out at any time. Upon logging out, a thank-you message will be displayed, along with the logout time.

Code Structure 🧑‍💻
Classes
bms Class: Handles the main functionality of the Bank Management System. It manages user authentication, account management, and transactions.

record Class: Represents a customer record with attributes such as name, account number, phone number, address, email, and balance.

Key Functions 🔑
authenticate(): Handles user login and authentication.
menu(): Displays the main menu based on the user type (Administrator or User).
view(): Displays all customer accounts.
add(): Registers a new customer account.
edit(): Edits an existing customer account.
del(): Deletes a customer account.
srch(): Searches for a customer account by account number or name.
transactions(): Handles banking transactions like balance inquiry, deposit, withdrawal, and fund transfer.
menuexit(): Logs out the user and exits the program.
Team Members 👩‍💻👨‍💻
This project was developed by:

Natnael Getachew
Eyob Tesfaye Metaferiya
Marta Dereje
Betelhem Kassahun
Mekdes Demisse

License 📄
Feel free to modify and distribute it as per the license terms.

Acknowledgments 🙏
This project was developed as part of a 2nd-year academic assignment.
Special thanks to our instructors and peers for their invaluable support and feedback
