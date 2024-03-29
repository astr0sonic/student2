#include "max_value.h"
#include <algorithm>

using namespace std;


double calculateMaxValue(double* v, int n) {
	double miv = v[0], mav = v[0], k;
	for (int i = 1; i < n; i++)
	{
		if (v[i] == 0) {
			miv = min(0.0, miv);
			mav = max(0.0, mav);
		}
		else
			if (v[i] > 0) {
				mav = max({ mav + v[i], mav / v[i], mav * v[i] });
				miv = min({ miv - v[i], miv * v[i], miv / v[i] });
			}
			else {
				k = miv;
				miv = min({ miv + v[i], mav / v[i], mav * v[i] });
				mav = max({ mav - v[i], k * v[i], k / v[i] });
			}
	} return mav;
}
