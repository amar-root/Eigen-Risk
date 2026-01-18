#include "CSVReader.h"
#include <sstream>

using namespace std;

bool CSVReader::open(const string& filePath) {
    file.open(filePath);
    if (!file.is_open()) return false;

    string header;
    getline(file, header); // skip header
    return true;
}

bool CSVReader::readRow(vector<string>& columns) {
    string line;
    if (!getline(file, line)) return false;

    stringstream ss(line);
    string value;
    columns.clear();

    while (getline(ss, value, ',')) {
        columns.push_back(value);
    }
    return true;
}

void CSVReader::close() {
    if (file.is_open())
        file.close();
}
