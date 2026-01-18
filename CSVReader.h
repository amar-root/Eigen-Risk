#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>
#include <fstream>

class CSVReader {
public:
    bool open(const std::string& filePath);
    bool readRow(std::vector<std::string>& columns);
    void close();

private:
    std::ifstream file;
};

#endif
