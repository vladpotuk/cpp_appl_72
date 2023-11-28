#include "functions.h"

int main() {
    const std::string inputFilename = "input.txt";
    const std::string outputFilename = "output_reverse.txt";

    reverseCopyFileContent(inputFilename, outputFilename);

    return 0;
}
