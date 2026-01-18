#ifndef CAR_SALES_ANALYZER_H
#define CAR_SALES_ANALYZER_H

#include <string>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::string;
using std::vector;

class CarSalesAnalyzer {
public:
    void analyzeRow(const std::vector<std::string>& row);

    long getAudiChina2025Count() const;
    double getBMWRevenue2025() const;

    const unordered_map<string, long>& getAudiEuropeDistribution() const;
    const unordered_map<string, long>& getBMWEuropeDistribution() const;

private:
    long audiChina2025 = 0;
    double bmwRevenue2025 = 0.0;

    unordered_map<string, long> audiEurope;
    unordered_map<string, long> bmwEurope;
};

#endif
