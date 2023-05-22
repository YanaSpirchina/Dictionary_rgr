//
// Created by Yana Spirchina on 11.05.2023.
//

#ifndef RGR_DICTIONARY_H
#define RGR_DICTIONARY_H

#include <iostream>
#include <map>
#include <list>

namespace nspace {
    class Dictionary {
    public:
        void getDictionaryFromFile(const std::string &fileName);

        void insert(const std::string &eng_word, const std::string &translate);

        void findTranslate(const std::string &eng_word);

        void deleteWord(const std::string &eng_word);

        void deleteTranslate(const std::string &eng_word, const std::string &translate);

        void addTranslation(const std::string &eng_word, const std::string &translate);

        void dictionaryPrint();

    private:
        std::map<std::string, std::list<std::string>> map;
    };
}


#endif //RGR_DICTIONARY_H
