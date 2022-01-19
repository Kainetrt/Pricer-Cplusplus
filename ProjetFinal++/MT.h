#pragma once
#include <random>

class MT
{
public:
    static MT& Instance();
    double rand_unif();
    double rand_norm();
private:
    MT& operator= (const MT&) {}
    MT(const MT&) {}

    static MT m_instance;
    MT();
    ~MT();
};
