// Roundobj.cpp: CRoundobj 的实现

#include "stdafx.h"
#include "Roundobj.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

// CRoundobj
STDMETHODIMP CRoundobj::ERound(double a, double* b) {
	stringstream ss;
	ss << fixed << setprecision(2) << a;
	ss >> a;
	*b = a;
	return S_OK;
}

