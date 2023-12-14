#pragma once

#include<iostream>
#include<mingw.thread.h>
#include<mingw.condition_variable.h>
#include<mingw.mutex.h>


extern std::mutex mtx;
extern std::condition_variable cv1;
extern std::condition_variable cv2;

void cout1(int& num);

void cout2(int& num);