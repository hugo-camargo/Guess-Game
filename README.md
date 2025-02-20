# Guess Game

This project is a number guessing game created in C using a tree data structure and pointers. In this game, the user selects a range of numbers, and a number is randomly generated within that range. The player (user) must guess the generated number. If the player makes an incorrect guess, the program will indicate whether the entered value is greater or lower than the target number, and the player will lose points for each attempt. The first player to guess correctly wins.

## Features

- Customizable number range selection
- Random number generation
- Hint system that indicates whether the guess is too high or too low
- Score system based on the number of attempts
- Winner determination based on correct guesses

## How to Play

1. The user defines the range (e.g., 1 to 100).
2. A random number is generated within this range.
3. The user starts guessing the number.
4. If the guess is incorrect, the program provides a hint (higher or lower).
5. The player loses points for each incorrect guess.
6. The first player to guess correctly wins!

## Instalation and Compilation

- Clone the repository: 
    git clone https://github.com/hugo-camargo/Guess-Game.git

- Compile code with GCC:
    Windows - gcc guess-game.c -o guess-game.exe
    Linux   - gcc guess-game.c -o guess-code

- Run the game:
    Windows - ./guess-game.exe
    Linux   - ./guess-game

Technologies Used

1. C language
2. Binary Search Tree (BST) for optimized guessing
3. Random Number Generation
4. Pointers & Dynamic Memory Allocation





