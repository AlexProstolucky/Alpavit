#include <iostream>
#include <thread>
#include <string>
#include <cctype>
#include <vector>
#include <windows.h>


const std::vector<char> ukrainianAlphabet = {
    'А', 'Б', 'В', 'Г', 'Ґ', 'Д', 'Е', 'Є', 'Ж', 'З',
    'И', 'І', 'Ї', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П',
    'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ',
    'Ь', 'Ю', 'Я'
};

void displayUkrainianAlphabet(int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        return;
    }
    if (startIndex < 0) {
        startIndex = 0;
    }
    if (startIndex > 0) {
        startIndex --;
    }
    if (endIndex >= ukrainianAlphabet.size()) {
        endIndex = ukrainianAlphabet.size() - 1;
    }

    for (int i = startIndex; i <= endIndex; ++i) {
        std::cout << ukrainianAlphabet[i] << " ";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    std::cout << "Введіть початковий індекс: ";
    int startIndex;
    std::cin >> startIndex;

    std::cout << "Введіть кінцевий індекс: ";
    int endIndex;
    std::cin >> endIndex;

    std::thread alphabetThread(displayUkrainianAlphabet, startIndex, endIndex);

    std::cout << "Головний потік працює..." << std::endl;

    alphabetThread.join();

    std::cout << "\nГоловний потік завершено." << std::endl;

    return 0;
}
