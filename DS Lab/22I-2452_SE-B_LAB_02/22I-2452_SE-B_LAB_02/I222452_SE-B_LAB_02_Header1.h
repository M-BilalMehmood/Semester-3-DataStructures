#pragma once
#include<iostream>
#include<string>
#include"I222452_SE-B_LAB_02_Header2.h"
#include"I222452_SE-B_LAB_02_Header3.h"
#include"I222452_SE-B_LAB_02_Header4.h"
using namespace std;

template <typename T>
T if_smaller(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}