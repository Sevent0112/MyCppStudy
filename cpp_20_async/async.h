#pragma once
#include<iostream>
#include<string>
#include<mingw.future.h>
#include<mingw.mutex.h>
#include<mingw.thread.h>


std::string fetchDataFromDB(std::string query);

void use_async();

int my_task();

void use_package();

