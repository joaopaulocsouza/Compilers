#ifndef LINEARSCAN_HPP
#define LINEARSCAN_HPP


#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct ResultProps{
    int k;
    bool spill;
    std::vector<int> iterations;
};

class Register {
    public:
        std::string id;
        int start;
        int end;
        int reg;

        Register(){};
};


std::vector<Register *> actives;
std::map<int, bool> freeRegs;

class LinearScan{

    public:
        std::vector<Register *> registers;
        std::vector<ResultProps> results;
        int k;

        LinearScan(){
            k = 0;
        };

        void setK(int k){
            this->k = k;
        };

        void addRegister(char* id, int start, int end){
            Register *reg = new Register();
            reg->id = id;
            reg->start = start;
            reg->end = end;
            reg->reg = -1;
            registers.push_back(reg);
        };

        int getRegIndex(std::string id){
            for(int i = 0; i < registers.size(); i++){
                if(registers[i]->id == id){
                    return i;
                }
            }
            return -1;
        };

        void adjustActives(int current){
            for(auto ativo : actives){
                if(ativo->end <= current){
                    actives.erase(std::remove(actives.begin(), actives.end(), ativo), actives.end());
                    freeRegs[ativo->reg] = false;
                }
            }   
        };

        void alloc(int i){
            ResultProps result;

            for(int j = 0; j < i; j++){
                freeRegs[j] = false;
            }

            for(int j = 0; j < registers.size(); j++){
                Register* reg = registers[j];

                adjustActives(reg->start);
                adjustActives(reg->start);

                for(auto free : freeRegs){
                    if(free.second == false){
                        actives.push_back(reg);
                        reg->reg = free.first;
                        freeRegs[free.first] = true;
                        break;
                    }
                }

                if(reg->reg == -1){
                    Register* spill = reg;

                    for(int k = 0; k < actives.size(); k++){
                        Register* ativo = actives[k];
                        if(ativo->end > spill->end){
                            spill = ativo;
                            continue;
                        }else if(ativo->end == spill->end){
                            if(ativo->start > spill->start){
                                spill = ativo;
                                continue;
                            }else if(ativo->start == spill->start){
                                int indexSpill = getRegIndex(spill->id);
                                int indexAtivo = getRegIndex(ativo->id);

                                if(indexAtivo > indexSpill){
                                    spill = ativo;
                                    continue;
                                }
                            }
                        }
                    }

                    if(spill->id != reg->id){
                        actives.erase(std::remove(actives.begin(), actives.end(), spill), actives.end());
                        actives.push_back(reg);
                        reg->reg = spill->reg;
                        spill->reg = -1;
                    }
                    result.iterations.push_back(j);
                }

            }

            result.k = i;
            result.spill = result.iterations.size() > 0;
            results.push_back(result);

            std::cout << "K = " << i << "\n" << std::endl;

            for(int j = 0; j < registers.size(); j++){
                Register* reg = registers[j];

                if(reg->reg == -1){
                    std::cout << reg->id << ": " << "SPILL" << std::endl;
                    continue;
                }
                std::cout << reg->id << ": " << reg->reg << std::endl;
            }
            std::cout << "----------------------------------------" << std::endl;

            reset();
        };

        void reset(){
            for(auto reg : registers){
                reg->reg = -1;
            }
            actives.clear();
            freeRegs.clear();
        }

        void deleteRegisters(){
            for(auto reg : registers){
                delete reg;
            }
        }
};


#endif