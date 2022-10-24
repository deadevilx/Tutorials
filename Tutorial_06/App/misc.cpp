
#include "misc.h"

unsigned long long n_sum(unsigned long long n) {
	if (n > 1)
		return n + n_sum(n - 1);
	else
		return n;
}
