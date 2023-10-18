#include <iostream>
#include <optional>
#include "RatNum.h"
#include "RatFunc.h"

#ifndef __RATTERM_H__
#define __RATTERM_H__

class RatTerm {
private:
  RatFunc* func;
  RatNum coeff;
  RatNum exp;

public:
  // Constructors
  RatTerm() : func(nullptr), coeff(RatNums::ZERO), exp(RatNums::ONE) {}
  RatTerm(const RatFunc& f, const RatNum& c = RatNums::ZERO, const RatNum& e = RatNums::ONE) : coeff(c), exp(e) {}
  RatTerm(const RatTerm& t) : func(t.func), coeff(t.coeff), exp(t.exp) {}

  // Accessors
  RatNum getCoeff() const { return coeff; }
  RatNum getExp() const { return exp; }

  // Operators
  RatTerm& operator=(const RatTerm& t);
  RatTerm operator-() const;
  RatTerm operator()(const RatNum& x) const;
};

std::ostream& operator<<(std::ostream& os, const RatTerm& t);

#endif 
