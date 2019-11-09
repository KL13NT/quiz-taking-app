#ifndef USER_UTILS_H
#define USER_UTILS_H


// Displays user score statistics
// void DisplayStatistics() {
// 	LoggedInUser.DisplayUserStatistics();

// 	if (GetUserInput("Your choice") == 'b') MainMenu();
// }

void CreateNewUser(){
	cout << "Create new account. \n";
	string Type = StringToLowerCase(GetUserInput("Account Type [admin, player]"));
	string FirstName = GetUserInput("Firstname");
	string LastName = GetUserInput("Lastname");
	string Username = StringToLowerCase(GetUserInput("Username [case-insensitive]"));
	string Password = GetUserInput("Password");

	if(
		(Type == "admin" || Type == "player") &&
		FirstName.length() != 0 &&
		LastName.length() != 0 &&
		Username.length() != 0 &&
		Password.length() != 0
		){
			Users.push_back(User(FirstName, LastName, Username, Password,  Type == "admin"));
			return Login();
		}
	else {
		cout << "Input isn't adequate. Try again\n";
		return CreateNewUser();
	}
}

void UpdateAccountDetails(){
	string firstname = GetUserInput("New firstname");
	string lastname = GetUserInput("New lastname");
	string username = GetUserInput("New username");
	string password = GetUserInput("New password");
	UserProfile -> UpdateUserData(firstname, lastname, username, password);
}

void SwitchAccount(){
	string Answer = StringToLowerCase(GetUserInput("Do you wish to log out? [Y] or [N]o\n"));
	
	while(bool IsVal = false) {
		if (Answer == "Y" || Answer == "N") {
				IsVal = true;
		}
		else {
				IsVal = false;
				Answer = StringToLowerCase(GetUserInput("We didn't catch that, please enter again"));
		}
	}
	if(Answer == "Y"){
		cout << "Logged out successfully...\n";
		Answer = StringToLowerCase(GetUserInput("Do you wish to log in or register a new user?\n""[R for register || L for login]"));
		while(bool IsVal = false) {
			if (Answer == "R" || Answer == "L") {
				IsVal = true;
			} else {
				IsVal = false;
				Answer = StringToLowerCase(GetUserInput("We didn't catch that, please enter again"));
			}
		}
		if(Answer == "R")CreateNewUser();
		else Login();
		return MainMenu();
	}
	else return MainMenu();

}

#endif