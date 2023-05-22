//
// Created by Yana Spirchina on 11.05.2023.
//

#include <fstream>
#include "Dictionary.h"

void nspace::Dictionary::insert(const std::string &word, const std::string &translate) {
    auto it = map.find(word);
    if (it != map.end()) {
        throw std::runtime_error("Word already exists!");
    }
    std::list<std::string> list1;
    list1.push_back(translate);
    map[word] = list1;
}

void print(std::string translate) {
    std::cout << translate << ", ";
}

void nspace::Dictionary::findTranslate(const std::string &word) {
    auto it = map.find(word);
    if (it == map.end()) {
        throw std::runtime_error("Word doesn't exist!");
    }

    std::for_each(map.find(word)->second.begin(), map.find(word)->second.end(), print);
}

void nspace::Dictionary::deleteWord(const std::string &word) {
    auto it = map.find(word);
    if (it == map.end()) {
        throw std::runtime_error("Word doesn't exist!");
    }
    map.find(word)->second.clear();
    map.erase(word);
}

void nspace::Dictionary::addTranslation(const std::string &word, const std::string &translate) {
    auto it = map.find(word);
    if (it == map.end()) {
        throw std::runtime_error("Word doesn't exist!");
    }

    auto item = std::find(map.find(word)->second.begin(), map.find(word)->second.end(), translate);
    if (item != map.find(word)->second.end()) {
        throw std::runtime_error("Translate already exists!");
    }

    map.find(word)->second.push_back(translate);
}

void nspace::Dictionary::deleteTranslate(const std::string &word, const std::string &translate) {
    auto it = map.find(word);
    if (it == map.end()) {
        throw std::runtime_error("Word doesn't exist!");
    }

    auto item = std::find(map.find(word)->second.begin(),
                          map.find(word)->second.end(), translate);
    if (item == map.find(word)->second.end()) {
        throw std::runtime_error("Translate doesn't exist!");
    }
    map.find(word)->second.remove(translate);
}

void nspace::Dictionary::dictionaryPrint() {
    std::for_each(map.begin(), map.end(), [](const auto &pair) {
        std::cout << pair.first << ": ";
        std::for_each(pair.second.begin(), pair.second.end(), print);
        std::cout << std::endl;
    });
}

void nspace::Dictionary::getDictionaryFromFile(const std::string &fileName) {

    std::ifstream file(fileName);
    std::string line;
    if (!file.is_open()) {
        throw std::runtime_error("Open file error!");
    }

    while (std::getline(file, line)) {
        std::string word;
        std::list<std::string> list;

        int i = 0;
        while (line[i] != ':') {
            word += line[i];
            i++;
        }

        i++;
        std::string str;
        for (size_t j = i; j <= line.length(); j++) {
            if (line[j] == ',' || j == line.length()) {
                list.push_back(str);
                str = "";
                if (j == line.length()) {
                    break;
                }
                j++;
            }
            str += line[j];
        }
        map.insert(std::make_pair(word, list));
    }
    std::cout << "Слова считаны" << std::endl;
    file.close();
}
