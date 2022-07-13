#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

using namespace std;

string sha256(const string str);

#endif