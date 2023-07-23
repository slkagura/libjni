#include <iostream>

#include "Reg.h"

LSTATUS getUserPath(LPBYTE &lpData) {
    HKEY hKey = HKEY_CURRENT_USER;
    LPCSTR lpSubKey = "Environment";
    LPCSTR lpValueName = "Path";
    return getValue(hKey, lpSubKey, lpValueName, lpData);
}

LSTATUS setUserPath(LPBYTE lpData) {
    HKEY hKey = HKEY_CURRENT_USER;
    LPCSTR lpSubKey = "Environment";
    LPCSTR lpValueName = "Path";
    return setValue(hKey, lpSubKey, lpValueName, lpData);
}

LSTATUS getValue(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, LPBYTE &lpData) {
    // 打开
    REGSAM samDesired = KEY_WOW64_64KEY | KEY_READ;
    HKEY hkResult;
    LSTATUS result = RegOpenKeyExA(hKey, lpSubKey, 0, samDesired, &hkResult);
    std::cout << "RegOpenKeyExA " << "result: " << result << std::endl;

    // 查询
    if (result != ERROR_SUCCESS) {
        return result;
    }
    DWORD type = REG_EXPAND_SZ;
    DWORD cbData;
    RegQueryValueExA(hkResult, lpValueName, nullptr, &type, nullptr, &cbData);
    lpData = new unsigned char[cbData];
    result = RegQueryValueExA(hkResult, lpValueName, nullptr, &type, lpData, &cbData);
    std::cout << "RegQueryKeyExA " << "result: " << result << std::endl;
    std::cout << "               " << "data: " << lpData << std::endl;
    std::cout << "               " << "length: " << cbData << std::endl;

    // 关闭
    if (result != ERROR_SUCCESS) {
        return result;
    }
    result = RegCloseKey(hkResult);
    std::cout << "RegCloseKey " << "result: " << result << std::endl;

    // 返回
    return result;
}

LSTATUS setValue(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, LPBYTE lpData) {
    // 打开
    REGSAM samDesired = KEY_WOW64_64KEY | KEY_WRITE;
    HKEY hkResult;
    LSTATUS result = RegOpenKeyExA(hKey, lpSubKey, 0, samDesired, &hkResult);
    std::cout << "RegOpenKeyExA " << "result: " << result << std::endl;

    // 写入
    if (result != ERROR_SUCCESS) {
        return result;
    }
    DWORD type = REG_EXPAND_SZ;
    DWORD cbData = strlen((const char *) lpData);
    result = RegSetKeyValueA(hkResult, lpValueName, nullptr, type, lpData, cbData);
    std::cout << "RegSetKeyValueA " << "data: " << lpData << std::endl;
    std::cout << "                " << "length: " << cbData << std::endl;
    std::cout << "                " << "result: " << result << std::endl;

    // 关闭
    if (result != ERROR_SUCCESS) {
        return result;
    }
    result = RegCloseKey(hkResult);
    std::cout << "RegCloseKey " << "result: " << result << std::endl;

    // 返回
    return result;
}
