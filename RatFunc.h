#include "stdfloat.h"

#ifndef __RATFUNC_H__
#define __RATFUNC_H__

class RatFunc {
protected:
	RatFunc* inner;
public:
	virtual float64_t eval(float64_t x) const = 0;
};

#endif
