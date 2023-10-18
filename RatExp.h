#include "RatFunc.h"
#include "RatNum.h"
#include "stdfloat.h"
#include <cmath>

#ifndef __RATEXP_H__
#define __RATEXP_H__

class RatExp : public RatFunc {
protected:
	RatNum base;
	RatFunc* inner;
public:
	RatExp() : base(RatNum(2)), inner(nullptr) {}
	RatExp(RatNum b);
	float64_t eval(float64_t x) const { 
		return std::pow(base.getValue(), inner ? inner->eval(x) : x);
	}
};

#endif
