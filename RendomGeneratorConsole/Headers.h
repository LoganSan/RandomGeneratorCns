#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <Windows.h>	//for Sleep()
#include <string>
#include <mutex>
#include <cstdlib>

const bool DEBUG = true;

//Show menu for user
int menu();

//Function for procedure the generation of random data
void generator();

//Tell user how to upload log in the programm
void loadingFromFile();

//Function that generate the data
void newThreadGenerator(int* piTurnsCount);


