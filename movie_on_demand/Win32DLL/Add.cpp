#include "pch.h"

using namespace std;



extern "C" __declspec(dllexport) int Add(int x, int y)
{
	//��������
	return x + y;
}
