#ifndef LIB_REG_H
#define LIB_REG_H

#include <windows.h>

LSTATUS getUserPath(LPBYTE &lpData);
LSTATUS setUserPath(LPBYTE lpData);
LSTATUS getValue(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, LPBYTE &lpData);
LSTATUS setValue(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, LPBYTE lpData);

#endif //LIB_REG_H
