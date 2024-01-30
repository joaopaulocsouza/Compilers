#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP


class Functions {
    public:
        Functions();  // Declaração do construtor
        int LexicAnalizer(std::vector<std::string> tokens);
        int GetColumn(char character);
};

#endif