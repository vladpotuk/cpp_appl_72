#include "functions.h"
#include <iostream>

void reverseCopyFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    
    FILE* inputFile;
    if (fopen_s(&inputFile, inputFilename.c_str(), "r") != 0) {
        std::cerr << "Error opening file: " << inputFilename << std::endl;
        return;
    }

    
    FILE* outputFile;
    if (fopen_s(&outputFile, outputFilename.c_str(), "w") != 0) {
        std::cerr << "Error opening file: " << outputFilename << std::endl;
        fclose(inputFile);
        return;
    }

    
    const int maxLines = 1000;  
    char lines[maxLines][1024]; 

    int lineCount = 0;
    while (lineCount < maxLines && fgets(lines[lineCount], sizeof(lines[lineCount]), inputFile)) {
        lineCount++;
    }

    
    for (int i = lineCount - 1; i >= 0; i--) {
        fprintf(outputFile, "%s", lines[i]);
    }

    
    fclose(inputFile);
    fclose(outputFile);

    std::cout << "File content copied in reverse order from " << inputFilename << " to " << outputFilename << std::endl;
}
