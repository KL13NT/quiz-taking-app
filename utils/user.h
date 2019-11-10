#ifndef USER_UTILS_H
#define USER_UTILS_H


// Displays user score statistics
// void DisplayStatistics() {
// 	LoggedInUser.DisplayUserStatistics();

// 	if (GetUserInput("Your choice") == 'b') MainMenu();
// }

bool IsDuplicateUser(string Username){
	for(User &Curr : Users){
		if(Curr.Username == Username) return true;
	}

	return false;
}

void CreateNewUser(){
	string Type;
	
	cout << MakeHeader("Register a new user", 30);
	
	if(IsFirstRun) {
		cout << "This is the first run, registering new admin.\n";
		Type = "admin";
		IsFirstRun = false;
	}
	else Type = StringToLowerCase(GetUserInput("Account Type [admin, player]"));

	string FirstName = GetUserInput("Firstname");
	string LastName = GetUserInput("Lastname");
	string Username = StringToLowerCase(GetUserInput("Username [case-insensitive]"));
	string Password = GetUserInput("Password");

	if(
		(Type == "admin" || Type == "player") &&
		FirstName.length() != 0 &&
		LastName.length() != 0 &&
		Username.length() != 0 &&
		Password.length() != 0 &&
		){
			while(!IsDuplicateUser(Username)) {
				Username = StringToLowerCase(GetUserInput("A user with this username already exists.\nTry another one.\nUsername [case-insensitive]"));
			}
			
			Users.push_back(User(FirstName, LastName, Username, Password,  Type == "admin"));
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
	cout << "Data updated successfully\n\n";
}


#endif
