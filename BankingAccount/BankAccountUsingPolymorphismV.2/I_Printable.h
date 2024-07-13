#ifndef I_PRINTABLE_H
#define I_PRINTABLE_H

#pragma once
#include <ostream>
using namespace std;

class I_Printable
{
    friend ostream &operator<<(ostream &os, const I_Printable &obj);
public:
    virtual ~I_Printable() = default;
    virtual void print(ostream &os) const = 0; 
};

#endif