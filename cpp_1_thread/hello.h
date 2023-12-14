#pragma once

#include<iostream>
#include<string>
using namespace std;

char decrypt(const char &param);
char encrypt(const char &param);
void change(string &stringItem, char (*callbackFunction)(const char &));
