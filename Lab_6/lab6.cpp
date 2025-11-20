#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(){

    std::string input_line;
    std::cout << "Введіть рядок: " << std::endl;
    std::getline(std::cin, input_line);
    std::stringstream ss(input_line);
    std::string word;
    int word_count = 0;
    std::vector<int> word_lengths;

    while (ss >> word) {

        word_count++;
        word_lengths.push_back(word.length());
    }

    std::cout << "Загальна кількість слів: " << word_count << std::endl; 
    std::cout << "Масив з довжин слів: [ ";

    for (int i = 0; i < word_lengths.size(); i++){
        std::cout << word_lengths[i] << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}