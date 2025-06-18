# C++ Expense Tracker (JSON-based)

This is a simple **command-line personal expense tracker** written in C++. It allows users to:

* Add expenses with date, category, and amount
* View detailed logs and daily summaries
* Save and load data from a local JSON file (`expenses.json`)

It uses the [nlohmann/json](https://github.com/nlohmann/json) library to handle JSON serialization.

---

## Features

* Add expenses interactively
* View all recorded expenses
* Show total expenses per day
* Highlight category-wise daily expense distribution
* Save and load persistent data to/from `expenses.json`

---

## Requirements

* C++ compiler (C++11 or later)
* nlohmann/json library

---

## Setup Instructions

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/expense-tracker-cpp.git
cd expense-tracker-cpp
```

---

### 2. Install Dependencies

This project uses the [nlohmann/json](https://github.com/nlohmann/json) library. You can install it using:

#### Option A: Using package manager (Linux)

```bash
sudo apt install nlohmann-json3-dev
```

#### Option B: Manual Header File

Download `json.hpp` from [here](https://github.com/nlohmann/json/releases) and place it in your project directory.

---

### 3. Compile the Program

Using `g++`:

```bash
g++ main.cpp -o tracker
```

Make sure `json.hpp` is in the same folder as `main.cpp` if not installed globally.

---

### 4. Run the Application

```bash
./tracker
```

You will see a menu:

```
1. Add Expense
2. View Expenses
3. Save & Exit
Choice:
```

Follow the prompts to add expenses, view history, and exit.

---

## Example Output

### Add Expense:

```
Enter date (YYYY-MM-DD): 2025-06-18
Enter category: Food
Enter amount: 200
✅ Expense added.
```

### View Expenses:

```
📋 Detailed Expenses:
Date        Category        Amount
2025-06-18  Food            200

📊 Daily Summaries:
Date: 2025-06-18 | Total: 200 | Most Spent On: Food (200)
```

---

## File Format

Saved as a JSON array:

```json
[
    {
        "date": "2025-06-18",
        "category": "Food",
        "amount": 200.0
    },
    {
        "date": "2025-06-18",
        "category": "Transport",
        "amount": 50.0
    }
]
```

File: `expenses.json` is created or updated automatically on exit.

---

## Notes

* Run the program in the same directory as `expenses.json` to auto-load data
* For cross-platform compatibility, compile using a C++17+ compiler if needed
* All amounts are in float; no currency formatting

---

## Author

**Trivardhan Rachakonda**
A simple expense tracker for daily personal finance analysis using C++

