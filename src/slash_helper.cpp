#include <iostream>
#include <fstream>
#include <string>

#define TAB_SIZE 8

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if(argc != 2) {
        std::cerr << "Usage: ./slash_helper.exe <argv[1]>" << std::endl;

        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;

        return 1;
    }

    std::ofstream output_file("slashed.out");
    if (!output_file.is_open()) {
        std::cerr << "Error: Could not create output file." << std::endl;

        return 1;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        int length = line.length();
        for(int i = 0; i < line.length(); i++) {
            if(line[i] == '\t')
                length += TAB_SIZE - 1;
        }

        int count = 0;
        if (line.empty())
            count = 80 / TAB_SIZE;
        else if(length < 80)
            count = 80 / TAB_SIZE * 10 - length / TAB_SIZE;

        for (int i = 0; i < count; i++)
            line += '\t';

        output_file << line << "\\\n";
    }

    input_file.close();
    output_file.close();

    std::cout << "Processing complete." << std::endl;

    return 0;
}
