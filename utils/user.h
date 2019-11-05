#ifndef USER_UTILS_H
#define USER_UTILS_H

#include "../globals.h"


// Displays user score statistics
void DisplayStatistics() {
	LoggedInUser.DisplayUserStatistics();

	if (GetUserInput("Your choice") == 'b') MainMenu();
}



#endif