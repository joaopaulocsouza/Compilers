#ifndef DCMAT_HPP
#define DCMAT_HPP

struct DeclaredVar {
    bool exists;
    float value;
};

class DCMAT {
    public:
        DCMAT();
        void ShowSettings();
        void ResetSettings();
        void CreateHashItem(char *name, float value);
        DeclaredVar FindHashItem(char *name);
        void ShowSymbols();
};

#endif