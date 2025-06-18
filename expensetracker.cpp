#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

struct Expense {
    string date;
    string category;
    float amount;
};

vector<Expense> expenses;

void addExpense() {
    Expense e;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> e.date;
    cout << "Enter category: ";
    cin >> e.category;
    cout << "Enter amount: ";
    cin >> e.amount;
    expenses.push_back(e);
    cout << "✅ Expense added.\n";
}

void viewExpenses() {
    if (expenses.empty()) {
        cout << "⚠ No expenses recorded.\n";
        return;
    }

    cout << "\n📋 Detailed Expenses:\n";
    cout << "Date\t\tCategory\tAmount\n";
    for (const auto& e : expenses) {
        cout << e.date << "\t" << e.category << "\t\t" << e.amount << "\n";
    }

    // Compute daily totals and most expensive categories
    map<string, float> day_totals;
    map<string, map<string, float>> day_category_totals;

    for (const auto& e : expenses) {
        day_totals[e.date] += e.amount;
        day_category_totals[e.date][e.category] += e.amount;
    }

    cout << "\n📊 Daily Summaries:\n";
    for (const auto& dt : day_totals) {
        cout << "Date: " << dt.first << " | Total: " << dt.second;

        // Find most expensive category for the day
        string max_cat = "";
        float max_amt = 0;
        for (const auto& cat_pair : day_category_totals[dt.first]) {
            if (cat_pair.second > max_amt) {
                max_amt = cat_pair.second;
                max_cat = cat_pair.first;
            }
        }
        cout << " | Most Spent On: " << max_cat << " (" << max_amt << ")\n";
    }
}

void saveToJSON() {
    json j_expenses = json::array();
    for (const auto& e : expenses) {
        j_expenses.push_back({
            {"date", e.date},
            {"category", e.category},
            {"amount", e.amount}
        });
    }
    ofstream fout("expenses.json");
    fout << j_expenses.dump(4);
    fout.close();
    cout << "✅ Saved to expenses.json\n";
}

void loadFromJSON() {
    ifstream fin("expenses.json");
    if (!fin) {
        cout << "⚠ No existing JSON file found.\n";
        return;
    }
    json j_expenses;
    fin >> j_expenses;
    for (const auto& item : j_expenses) {
        Expense e;
        e.date = item.at("date").get<string>();
        e.category = item.at("category").get<string>();
        e.amount = item.at("amount").get<float>();
        expenses.push_back(e);
    }
    fin.close();
    cout << "✅ Loaded from expenses.json\n";
}

int main() {
    loadFromJSON();
    int choice;
    do {
        cout << "\n1. Add Expense\n2. View Expenses\n3. Save & Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: saveToJSON(); break;
            default: cout << "❌ Invalid choice\n";
        }
    } while (choice != 3);
    return 0;
}
