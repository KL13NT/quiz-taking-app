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
    string firstname = GetUserInput("Please enter new firstname");
    string lastname = GetUserInput("Please enter new lastname");
    string username = GetUserInput("Please enter new username");
    string password = GetUserInput("Please enter new password");
    UserProfile -> UpdateUserData(firstname, lastname, username, password);
}

#endif