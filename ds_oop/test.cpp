#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Fortune {
    int id;
    std::string author;
    std::string description;
};

std::vector<Fortune> readCSV(const std::string& filename) {
    std::vector<Fortune> fortunes;
    std::ifstream file(filename);
    std::string line;

    // Skip header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string idStr, author, description;

        std::getline(ss, idStr, ',');
        std::getline(ss, author, ',');
        std::getline(ss, description, ',');

        Fortune fortune;
        fortune.id = std::stoi(idStr);
        fortune.author = author;
        fortune.description = description;

        fortunes.push_back(fortune);
    }

    return fortunes;
}

void writeLDIF(const std::vector<Fortune>& fortunes, const std::string& filename, const std::string& baseDN) {
    std::ofstream file(filename);

    for (const auto& fortune : fortunes) {
        file << "dn: cn=fortune-" << fortune.id << ",ou=Fortune," << baseDN << "\n";
        file << "objectClass: fortune\n";
        file << "objectClass: top\n";
        file << "cn: fortune-" << fortune.id << "\n";
        file << "author: " << fortune.author << "\n";
        file << "id: " << fortune.id << "\n";
        file << "description: " << fortune.description << "\n";
        file << "\n";
    }
}

int main() {
    std::string csvFilename = "/Users/chengpingfeng/Downloads/hw4.csv";
    std::string ldifFilename = "/Users/chengpingfeng/Downloads/fortunes.ldif";
    std::string baseDN = "dc=16,dc=nasa";

    std::vector<Fortune> fortunes = readCSV(csvFilename);
    writeLDIF(fortunes, ldifFilename, baseDN);

    std::cout << "Conversion complete. LDIF file written to " << ldifFilename << std::endl;

    return 0;
}
