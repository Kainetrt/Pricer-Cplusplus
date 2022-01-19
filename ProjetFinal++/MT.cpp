#include <iostream>
#include "MT.h"

using namespace std;

MT MT::m_instance = MT();

MT::MT()
{
    cout << "Creation" << endl;
}

MT::~MT()
{
    cout << "Destruction" << endl;
}

MT& MT::Instance()
{
    return m_instance;
}

double MT::rand_unif()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

double MT::rand_norm()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d{ 0,1 };
    return d(gen);
}