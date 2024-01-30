#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP


class Functions {
    public:
        Functions();
        bool LexicalAnalizer(std::string string, std::vector<std::string> tokens);
        bool SyntaticAnalizer(std::string string, std::vector<std::string> tokens);
};

#endif