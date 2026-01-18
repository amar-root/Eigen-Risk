#include "CarSalesAnalyzer.h"
#include <string>

//using namespace std;
void CarSalesAnalyzer::analyzeRow(const vector<string>& row) {
    if (row.size() < 20) return;

    const string& saleDate = row[1];
    const string& country  = row[2];
    const string& region   = row[3];
    const string& brand    = row[8];
    double price = std::stod(row[19]);

    int year = std::stoi(saleDate.substr(0, 4));

    if (year == 2025 && brand == "Audi" && country == "China")
        audiChina2025++;

    if (year == 2025 && brand == "BMW")
        bmwRevenue2025 += price;

    if (year == 2025 && region == "Europe") {
        if (brand == "Audi")
            audiEurope[country]++;
        else if (brand == "BMW")
            bmwEurope[country]++;
    }
}

long CarSalesAnalyzer::getAudiChina2025Count() const {
    return audiChina2025;
}

double CarSalesAnalyzer::getBMWRevenue2025() const {
    return bmwRevenue2025;
}

const unordered_map<string, long>&
CarSalesAnalyzer::getAudiEuropeDistribution() const {
    return audiEurope;
}

const unordered_map<string, long>&
CarSalesAnalyzer::getBMWEuropeDistribution() const {
    return bmwEurope;
}
