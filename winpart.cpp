#define secureWTRY

#include "wapi.hpp"

#ifdef WIN32
#include <Windows.h>
#include <processthreadsapi.h>
#include <psapi.h>
#include <cstdlib>
#include <cstring>
#pragma comment(lib, "Kernel32.lib")

char* __cdecl p(){
    char d[MAX_PATH];
    auto re = GetModuleFileNameExA(GetCurrentProcess(), NULL, d, MAX_PATH);
    if(re == 0) return nullptr;
    char* rt = (char*)malloc(sizeof(char) * (re + 2));
    if(rt == nullptr) return nullptr;
    rt[re + 1] = 00;
    #ifndef secureWTRY
    strncpy(rt, d, re);
    #else
    strncpy_s(rt, (1 + re) * sizeof(char), d, re);
    #endif
    return rt;
}
#endif
