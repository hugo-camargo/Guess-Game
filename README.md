# 🎯 Guessing Game in C (with Binary Search Tree)

This is a terminal-based number guessing game implemented in C using a **Binary Search Tree (BST)**. The player defines an interval, and the game randomly selects a secret number within it. The player must guess the number, receiving hints ("higher" or "lower") after each attempt.

## 🌳 Why a Binary Search Tree?

Although the game logic does not rely on the BST to determine correctness, it uses the tree to simulate a structure that stores the range of possible numbers — fulfilling an academic requirement to utilize a **Tree Abstract Data Type (TAD)**.

## 🕹️ How the Game Works

1. The player defines a **minimum** and **maximum** number to set the guessing interval.
2. A **random secret number** is generated within that interval.
3. A **Binary Search Tree (BST)** is created with all numbers in the interval.
4. The player guesses until they find the correct number.
5. The score is calculated based on how quickly the number is guessed.

## ✅ Features

- Input validation to avoid invalid guesses
- Console feedback (higher/lower hints)
- Scoring system based on remaining attempts
- Option to play again after finishing a round
- Memory management with dynamic allocation and tree deallocation

## 🧠 Concepts Used

- Binary Search Tree (BST)
- Dynamic memory management (`malloc`, `free`)
- Random number generation (`rand()`, `srand()`)
- Structs and recursion in C

## 📦 File Structure

```
guess-game.c       # Main source code with all logic and game loop
```

## ⚙️ Requirements

- GCC or compatible C compiler
- Terminal or console to run the executable

## 🛠️ Compilation

To compile the game:

```bash
gcc guess-game.c -o guess_game
```

## ▶️ Running the Game

```bash
./guess_game
```

Follow the prompts in the terminal to start playing.

## 📝 License

This project is provided for educational purposes. No specific license is attached, but feel free to modify and reuse it for your academic work or personal projects.

---

Enjoy the challenge and try to beat your score!
