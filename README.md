# Quizzy

A quiz app with the following features: 

-   Start new quiz with different types of questions 
-   Change all user data
-   View complex statistics
-   View past quizzes history up to n-1 quizzes on demand
-   View score logs 
-   Add a theoretically unlimited number of users, admins and players
-   Switch between accounts easily
-   View all users in the system as an admin
-   Load different question types from file
-   Create different question types from the menu as an admin
-   View all questions and delete them based on question ID as an admin

For the full technical documenation refer to [Documentation](./Documentation.md).

## Contents

-   [Prerequisites](#Prerequisites)

-   [Behaviour](#Behaviour)
    -   [Structure](#Structure)
    -   [How it all comes together](#How-it-all-comes-together)

-   [Development Environment](#Development-Environment)
    -   [Testing](#Testing)

-   [V2](#V2)

-   [Contributing](#Contributing)

-   [Contributors](#Contributors)

## Prerequisites

-   Compiler: A GNU-based compiler
-   Compiler lang support: at least C++11

## Behaviour

This section describes how the program operates and how its structure comes together.

### Structure

```md
Structures/Classes:
- Question [MC, TF, Complete]
- Log [PlayerLog]
- Quiz
- User
```

```md
Utilities:
- File - File I/O handling
- IO - User Input/Output handling
- Log - Logging quizzes
- Misc - Helper functions such as StringIsEqual
- Question - Question utilities such as IsDuplicate
- Quiz - Responsible for starting and handling new quizzes
- String - String-only methods, probably will be moved into Misc
- User - All user-profile editing methods
```

### How it all comes together
Refer to the [Documentation](./Documentation.md).

## Development Environment

-   Codacy: For code style analysis
-   Testing: We're still searching for a testing framework/platform to use. 

## V2

> In development
>
> Version 2.0.0 is underway. This will include whole new structure and an enhanced, performant search algorithm. It'll also include a collection of new features such as multiple users with different account types. 

## Contributing

Any addition or improvement is welcome. We're by no means experts at C++ and have probably made a few mistakes here and there. Just open an issue to discuss whatever you're trying to achieve and then open a PR whenever you please. 

## Collaborators (no specific order)

[@KL13NT](https://github.com/KL13NT)

[@shaarawy962](https://github.com/shaarawy962)

[@AmrSamy19](https://github.com/AmrSamy19)

Omar Mostafa
