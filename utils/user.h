#ifndef USER_UTILS_H
#define USER_UTILS_H



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
		Password.length() != 0
		){
			if(IsDuplicateUser(Username)) {
				cout << "A user with this username already exists. Try another one.\n";
				return CreateNewUser();
			}
			IsFirstRun = false;
			Users.push_back(User(FirstName, LastName, Username, Password,  Type == "admin"));
		}
	else {
		cout << "Input isn't adequate. Try again\n";
		return CreateNewUser();
	}
}

void UpdateAccountDetails(){
	cout << MakeHeader("Update account details", 30);
	
	string FirstName = GetUserInput("New firstname");
	string LastName = GetUserInput("New lastname");
	
	string Username = GetUserInput("New username");
	string Password = GetUserInput("New password");

	if(FirstName.length() == 0 || LastName.length() == 0 || Username.length() == 0 || Password.length() == 0){
		cout << "Input cannot be empty. Try again\n";
		return UpdateAccountDetails();
	}
	if(IsDuplicateUser(Username)){
		cout << "An account with this username already exists, try using a different one.\n";
		return UpdateAccountDetails();
	}
	
	UpdateUserData(Users[LoggedinUserID], FirstName, LastName, Username, Password);
	cout << "Data updated successfully\n\n";
	
	UpdateGreeting();
}


#endif
