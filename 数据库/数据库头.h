#pragma once
#include<windows.h>
#include<stdbool.h>
#include<stdlib.h>
#include<cstdio>
#include<iostream>
#include<list>
#include <numeric>
#include <algorithm>
#include<stdbool.h>
#include<string>
#include<fstream>

using namespace std;
struct part
{
	long long number;
	char mima[20];
	char name[100];
	short sex;
	int date;
	long long dianhua;
	struct part *next;
};
#define lie 5
#define hang 21
class Hangban
{
public:
	char hangban_m[30];
	char hangban_b[20];
	char hangban_e[20];
	char hangban_t[15];
	int hangban_w[hang][lie];
	int hangbanp_price;
	int hangbanp_ding[hang][lie];
};
class Yonghu
{
public:
	char name[20];
	char hangban_m[30];
	int h, l;
};
