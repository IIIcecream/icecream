#pragma once

#include "IACM.h"
#include <string>
using std::string;

//  ²ÂÊı×ÖÓÎÏ·
class BullsAndCows : public IACM
{
public:
    BullsAndCows(string secret, string guess) : m_sSecret(secret), m_sGuess(guess) {}
    virtual bool solve() override;

private:
    string getHint(string secret, string guess);

private:
    string m_sSecret;
    string m_sGuess;
};