// Inflation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

/*
Program Overview:
This program takes input from the user, which includes the current price of an item, its price one year ago, and its price two years ago. It then calculates the inflation rates for the last year and two years ago. Finally, it determines whether the inflation trend is increasing or decreasing and outputs the results.

Input:
- The current price of the item
- The price of the item one year ago
- The price of the item two years ago

Output:
- Inflation rate for last year
- Inflation rate for two years ago
- Trend in inflation (increasing, decreasing, or stable)
*/

// Preconditions: None
// Postconditions: Modifies current_price, price_last_year, price_two_years_ago
void get_prices(float& current_price, float& price_last_year, float& price_two_years_ago);

// Preconditions: Requires valid prices for current year, last year, and two years ago
// Postconditions: Calculates inflation rates for last year and two years ago
void calculate_inflation_rates(float current_price, float price_last_year, float price_two_years_ago,
    float& inflation_rate_last_year, float& inflation_rate_two_years_ago);

// Preconditions: Requires valid inflation rates for last year and two years ago
// Postconditions: Outputs inflation rates and trend
void output_results(float inflation_rate_last_year, float inflation_rate_two_years_ago);

int main() {
    float current_price, price_last_year, price_two_years_ago;
    get_prices(current_price, price_last_year, price_two_years_ago);

    float inflation_rate_last_year, inflation_rate_two_years_ago;
    calculate_inflation_rates(current_price, price_last_year, price_two_years_ago,
        inflation_rate_last_year, inflation_rate_two_years_ago);

    output_results(inflation_rate_last_year, inflation_rate_two_years_ago);

    return 0;
}

void get_prices(float& current_price, float& price_last_year, float& price_two_years_ago) {
    cout << "Enter the current price of the item: ";
    cin >> current_price;
    cout << "Enter the price of the item one year ago: ";
    cin >> price_last_year;
    cout << "Enter the price of the item two years ago: ";
    cin >> price_two_years_ago;
}

void calculate_inflation_rates(float current_price, float price_last_year, float price_two_years_ago,
    float& inflation_rate_last_year, float& inflation_rate_two_years_ago) {
    inflation_rate_last_year = (current_price - price_last_year) / price_last_year;
    inflation_rate_two_years_ago = (price_last_year - price_two_years_ago) / price_two_years_ago;
}

void output_results(float inflation_rate_last_year, float inflation_rate_two_years_ago) {
    string trend;
    if (inflation_rate_last_year > inflation_rate_two_years_ago)
        trend = "increasing";
    else if (inflation_rate_last_year < inflation_rate_two_years_ago)
        trend = "decreasing";
    else
        trend = "stable";

    cout << "Inflation rate for last year: " << inflation_rate_last_year * 100 << "%" << endl;
    cout << "Inflation rate for two years ago: " << inflation_rate_two_years_ago * 100 << "%" << endl;
    cout << "The trend is " << trend << endl;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
