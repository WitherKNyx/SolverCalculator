#include "RatNum.h"
#include <cstdint>

int64_t gcd(int64_t a, int64_t b) {
	if (b == 0) {
		return 0;
	}
	while (b != 0) {
		int64_t t = b;
		b = a % b;
		a = t;
	}
	return a;
}

RatNum::RatNum(int64_t n, uint64_t d) {
	if (d == 0) {
		numer = n;
		denom = 0;
	} else {
		int64_t g = gcd(n, d);
		numer = n / g;
		denom = d / g;
	}
}

RatNum RatNum::operator+(const RatNum& rhs) const {
	return RatNum(numer * rhs.denom + rhs.numer * denom, denom * rhs.denom);
}

RatNum RatNum::operator-(const RatNum& rhs) const {
	return RatNum(numer * rhs.denom - rhs.numer * denom, denom * rhs.denom);
}

RatNum RatNum::operator-() const {
	return RatNum(-numer, denom);
}

RatNum RatNum::operator*(const RatNum& rhs) const {
	return RatNum(numer * rhs.numer, denom * rhs.denom);
}

RatNum RatNum::operator/(const RatNum& rhs) const {
	return RatNum(numer * rhs.denom, denom * rhs.numer);
}

bool RatNum::operator==(const RatNum& rhs) const {
	return numer == rhs.numer && denom == rhs.denom;
}

bool RatNum::operator<(const RatNum& rhs) const {
	return numer * rhs.denom < rhs.numer * denom;
}

std::ostream& operator<<(std::ostream& os, const RatNum& r) {
	if (r.isNaN()) {
		os << "NaN";
		return os;
	}
	os << r.getNumer();
	if (r.getDenom() != 1) {
		os << "/" << r.getDenom();
	}
	return os;
}
