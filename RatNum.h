/* Written by Nyx Gonzalez, 2023
 *
 * RatNum is a immutable class that represents a rational number.
 * RatNum is represented as a fraction of two integers, a numerator and a
 * denominator. The denominator is represented with an unsigned integer to
 * ensure that it is always positive. The numerator is represented with a
 * signed integer to allow for negative numbers. RatNums are always stored
 * in reduced form. A denominator of 0 represents a number that is either
 * positive or negative infinity. A numerator of 0 and a denominator of 0
 * represents a number that is not a number (NaN).
 */

#include <cstdint>
#include <iostream>
#include "stdfloat.h"

#ifndef __RATNUM_H__
#define __RATNUM_H__

class RatNum {
private:
	int64_t numer;
	uint64_t denom;
public:
	// Constructors
	RatNum() : numer(0), denom(1) {}
	RatNum(int64_t n) : numer(n), denom(1) {}
	RatNum(int64_t n, uint64_t d);
	RatNum(const RatNum& r) : numer(r.numer), denom(r.denom) {}

	// Operators
	RatNum& operator=(const RatNum& r);
	RatNum operator+(const RatNum& r) const;
	RatNum operator-() const;
	RatNum operator-(const RatNum& r) const;
	RatNum operator*(const RatNum& r) const;
	RatNum operator/(const RatNum& r) const;
	bool operator==(const RatNum& r) const;
	bool operator<(const RatNum& r) const;

	// Accessors
	int64_t getNumer() const { return numer; }
	uint64_t getDenom() const { return denom; }
	float64_t getValue() const { return (float64_t)numer / (float64_t)denom; }
	bool isInteger() const { return denom == 1; }
	bool isPositive() const { return numer > 0; }
	bool isZero() const { return numer == 0; }
	bool isNegative() const { return numer < 0; }
	bool isInfinity() const { return numer != 0 && denom == 0; }
	bool isPosInfinity() const { return numer > 0 && denom == 0; }
	bool isNaN() const { return numer == 0 && denom == 0; }
	bool isNegInfinity() const { return numer < 0 && denom == 0; }

};

std::ostream& operator<<(std::ostream& os, const RatNum& r);
int64_t gcd(int64_t a, int64_t b);

#endif
