# V2.0 Documentation
This document describes the algorithms used and how the program handles user input. There are a few features to be added in the future should V3.0 be planned for release, such as exception handling and unit testing. 

## Contents
- [Starting The Program](#Starting-The-Program)
- [Menus](#Menus)
- [Scores & Limitations](#Scores-&-Limitations)
- [Starting a new quiz](#Starting-a-new-quiz)
- [Important Algorithms](#Important-Algorithms)
  - [Duplicate Detection](#Duplicate-Detection)
  - [Randomisation](#Randomisation)

## Starting The Program
Starting the program, if it’s the first time you've opened the program you’ll be asked to register a new admin account, if it isn’t you will be prompted to just log in using your username and password. The first and last names are not used for anything other than just display, while the username and password or used to make sure that your credentials are correct.

## Menus
After login you'll be faced with the main menu respective to your account type:
- Admin
  - View all questions: you will be presented with a list of all the questions in the program and a prompt to either delete a question or go back to the main menu
  - Add new question 
  - Load questions from file 
  - Display all users 
  - Add new user
- Player
  - Start a new quiz 
  - Display details if you last X quizzes 
  - Display your score statistics 
  - Display your scores
- Shared
  - Update user data
  - Switch account
  - Exit

## Scores & Limitations
User score is based on weights according to the following:
- MCQ: 2 points
- TFQ: 1 point
- Complete: 3 points

Each quiz is subject to the following limitations:
- 40% of the questions are MCQ
- 40% of the questions are TFQ
- 20% of the questions are Complete


## Starting a new quiz

> All user input is turned into lowercase.

At the beginning of each quiz, a new `Quiz` object is created. This object stores all the info regarding the ongoing quiz such as scores, questions counts, etc. At the end of each quiz, this `Quiz` object is dumped into a `Log` object and is used to calculate new statistics. `PlayerLogs` are used to display the history of quizzes. This may not be the best design possible, but it’s definitely scalable should we consider adding an `AdminLog`.

During quizzes, and depending on the type of question, a specific answer scheme will be requested. This specific schema is enforced using the `VerifyAnswer` function:
- MC: `a`, `b`, `c`, or `d`
- TF: `t`, `f`, `true`, or `false`
- Complete: input should have a `length` > `0`

If `VerifyAnswer` returns true, the user's answer is then taken to `CheckUserAnswer` which check whether the answer is correct. The result is then forwarded to `CalculateQuizScores` which also gets passed the `Quiz` object and recalculates its values. 


## Important Algorithms

There are a few algorithms that need to be understood in this program. Those include duplicate detection and randomisation.

### Duplicate Detection
> Before diving into the algorithms, make sure you understand what an `unordered_set` is and what a `vector` is, and the *technical* differences between them.

#### Assumptions

Let's assume we have a vector containing all the questions, called `QuestionPool`, we'll refer to it by just `Pool` from now on. Suppose that each question is just a string containing the question itself.

> In the real thing, `Pool` is a vector of `Question` objects.

Now let's assume we're adding 10 questions to the `Pool` that already exist. It's logical to not want duplicate questions in the system. Let's assume that those 10 questions already exist as the *last* 10 questions in the `Pool` and that we have a million questions in the `Pool`. 

#### Problem 
The most straightforward solution would be to loop through all of the `Pool`. Our loop will have to iterate over all the questions just to prove that we shouldn't add these questions again. 

> Note that elements are added in O(n) time in arrays and the like. And searching the array for existence of a question has a time complexity of O(n) as well.

We would have to iterate a million times per question just to prove that. (this number *could* increase to 2 million times if questions are not duplicates). We'd end up doing *up to* 20 million iterations to add just 10 questions. This is ***SLOW***.

#### Solution
Instead of using that slow algorithm, we can utilise `unordered_set`s. In arrays, adding elements to an array happens with a complexity of O(n), while in `unordered_set` it only takes O(1) time. Insertion also costs O(1) instead of O(n). This means that to check whether those 10 questions exist you'd need exactly 10 look-ups. And if there not duplicate, you'd need 10 look-ups, and 10 insertions, without the need to `iterate` over those million questions. 

### Randomisation
Now regarding the randomising functions. This algorithm is used to randomise the `Pool` and MCQ answers.

#### Problem
Imagine a vector of a million `Question` objects, which is quite complex. The most basic form of shuffling would be to generate a random integer and use it as an index in a loop. The downside to this approach though is it's relies heavily on chance which isn't inefficient. Randomising a million questions based on chance *will* at some point give duplicates, which will make the algorithm even slower because it'll have to recover from the duplicated number somehow, either be going back one iteration in the loop or some other way inefficient way. 


#### Solution
Let's assume that you have an array of integers. Those integers represent the indices of questions in the `Pool`. They're numbered from 0 to `n - 1` where `n` is the number of questions present in the `Pool`. This array will be called `PoolIndices`.  

Considering the fact that we have all indices for our `Pool`, instead of shuffling the main `Pool` and working complex data such as strings or our custom `Question` objects, we can shuffle an array of simple fixed-length integers. Those integers will be shuffled using `<algorithm>`'s `shuffle` and using the `default_random_engine`. 

`shuffle` is going to shuffle the array of indices `PoolIndices`. We can then use those indices to map (redirect) our question selection through it, going to random questions every time. Too obscure to understand? Let's consider the following example. Assume we want the question at index `0` in the `Pool`, after shuffling `PoolIndices`. Let's also assume we have 5 questions. So `PoolIndices` is going to look like `[0, 1, 2, 3, 4]` before shuffling. Assume that after the shuffling, it looks like this `[4, 2, 0, 3, 1]`. Now let's represent `Pool` by indices as `[0, 1, 2, 3, 4]`.

```
Grab question at index [0]
[4, 2, 0, 3, 1] // index [0] here refers to integer `4`.
Using `4` as index [4] to access the Pool: 
[0, 1, 2, 3, 4] // 4 is the last question in the Pool
```
We can see here that trying to go to the mapped index `0` actually redirects us to question at index 4 in the `Pool`. This is more efficient than shuffling the `Pool` itself and even more efficient than generating random numbers in a loop to give the impression of shuffling.

In practice, it goes like this:
1. Shuffle `PoolIndices`
2. Get `PoolIndices[i]` 
3. `PoolIndices[i] = x` where `x != i`
4. Use `PoolIndices[i]` to access `Pool` as `Pool[PoolIndices[i]]` which is equivalent to `Pool[x]` 
5. Return randomly selected question. 

The functions responsible for the shuffling are `ShuffleQuestionPoolIndices` and `ShuffleAnswerIndices`.

This is not the most efficient way but it is satisfactory for the complexity and scale of this project.
