#include "functions.h"
#include <iostream>

void reverseCopyFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    // Відкриття вхідного файлу
    FILE* inputFile;
    if (fopen_s(&inputFile, inputFilename.c_str(), "r") != 0) {
        std::cerr << "Error opening file: " << inputFilename << std::endl;
        return;
    }

    // Відкриття вихідного файлу
    FILE* outputFile;
    if (fopen_s(&outputFile, outputFilename.c_str(), "w") != 0) {
        std::cerr << "Error opening file: " << outputFilename << std::endl;
        fclose(inputFile);
        return;
    }

    // Читання рядків з вхідного файлу в масив
    const int maxLines = 1000;  // Припустимо, що у файлі не більше 1000 рядків
    char lines[maxLines][1024]; // Припустимо, що кожен рядок може бути довжиною до 1023 символів

    int lineCount = 0;
    while (lineCount < maxLines && fgets(lines[lineCount], sizeof(lines[lineCount]), inputFile)) {
        lineCount++;
    }

    // Запис рядків у зворотньому порядку в вихідний файл
    for (int i = lineCount - 1; i >= 0; i--) {
        fprintf(outputFile, "%s", lines[i]);
    }

    // Закриття файлів
    fclose(inputFile);
    fclose(outputFile);

    std::cout << "File content copied in reverse order from " << inputFilename << " to " << outputFilename << std::endl;
}
