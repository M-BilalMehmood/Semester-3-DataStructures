#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename T>
T if_smaller(T a, T b, T c)
{
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
		return c;
}