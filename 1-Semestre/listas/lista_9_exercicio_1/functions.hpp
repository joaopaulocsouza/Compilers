#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP


class Functions {
    public:
        Functions();
        bool LexicAnalizer(std::vector<std::string> tokens);
        bool SyntaticAnalizer(std::string string, std::vector<std::string> tokens);
        std::string GetToken(std::vector<std::string> tokens);
        void eat(std::string t, std::vector<std::string> tokens);
        void E(std::vector<std::string> tokens);
        void L(std::vector<std::string> tokens);
        void S(std::vector<std::string> tokens);
        int GetColumn(char character);
};

#endif