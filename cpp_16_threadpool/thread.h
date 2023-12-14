#pragma once
#include<mingw.thread.h>
#include<iostream>
#include<string>
#include<mingw.mutex.h>

std::mutex mtx;
void print(std::string str);
