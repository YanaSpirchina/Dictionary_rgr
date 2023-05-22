#include <iostream>
#include "Dictionary.h"

int main() {
    nspace::Dictionary dictionary;
    size_t end = 1;
    size_t action = 0;

    std::cout << "1) Добавить новое слово" << '\n' << "2) Добавить перевод " << '\n' << "3) Найти перевод слова"
              << '\n' << "4) Удалить слово" << '\n' << "5) Удалить перевод" << '\n' << "6)Напечатать словарь" << '\n' <<
              "7)Добавить слова из файла" << '\n' << "8) Завершить работу со словарём" << '\n';
    while (end != 0) {
        std::cout << "\nВведите номер действия" << '\n';
        std::cin >> action;
        switch (action) {
            case 1: {
                std::cout << "Введите слово" << '\n';
                std::string word;
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, word);
                std::cout << "Введите перевод" << '\n';
                std::string translate;
                std::getline(std::cin, translate);
                dictionary.insert(word, translate);
                break;
            }
            case 2: {
                std::cout << "Введите слово" << '\n';
                std::string word;
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, word);
                std::cout << "Введите перевод" << '\n';
                std::string translation;
                std::getline(std::cin, translation);
                dictionary.addTranslation(word, translation);
                break;
            }
            case 3: {
                std::cout << "Введите слово" << '\n';
                std::string word;
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, word);
                dictionary.findTranslate(word);
                break;
            }
            case 4: {
                std::cout << "Введите слово" << '\n';
                std::string word;
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, word);
                dictionary.deleteWord(word);
                break;
            }
            case 5: {
                std::cout << "Введите слово" << '\n';
                std::string word;
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, word);
                std::cout << "Введите перевод" << '\n';
                std::string translate;
                std::getline(std::cin, translate);
                dictionary.deleteTranslate(word, translate);
                break;
            }
            case 6:
                dictionary.dictionaryPrint();
                break;
            case 7: {
                std::cout << "Введите название файла" << '\n';
                std::string fileName;
                std::cin.ignore(1024, '\n');
                std::getline(std::cin, fileName);
                dictionary.getDictionaryFromFile(fileName);
                break;
            }
            case 8:
                end = 0;
                break;
            default:
                std::cerr << "Неправильный номер операции" << '\n';
                return 1;
        }
    }

    return 0;
}
