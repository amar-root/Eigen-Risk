#include "CSVReader.h"
#include "CarSalesAnalyzer.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSorted(const string& title,
                 const unordered_map<string, long>& data) {

    vector<pair<string, long>> vec(data.begin(), data.end());

    sort(vec.begin(), vec.end(),
         [](const auto& a, const auto& b) {
             return a.second > b.second;
         });

    cout << title << "\n";
    for (const auto& p : vec) {
        cout << "  " << p.first << " : " << p.second << "\n";
    }
    cout << "\n";
}

int main() {

    CSVReader reader;
    CarSalesAnalyzer analyzer;

    if (!reader.open("data/world_car_sales_1m.csv")) {
        cout << "Failed to open CSV file\n";
        return 1;
    }

    vector<string> row;
    while (reader.readRow(row)) {
        analyzer.analyzeRow(row);
    }

    reader.close();

    cout << "1. Audi cars sold in China (2025): "
         << analyzer.getAudiChina2025Count() << "\n\n";

    cout << "2. BMW total revenue in 2025: $"
         << analyzer.getBMWRevenue2025() << "\n\n";

    printSorted("Audi distribution in Europe (2025):",
                analyzer.getAudiEuropeDistribution());

    printSorted("BMW distribution in Europe (2025):",
                analyzer.getBMWEuropeDistribution());

    return 0;
}
