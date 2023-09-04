#include <windows.h>
#include <iostream>

// Fungsi untuk mendapatkan path instalasi Chrome dari registry
std::string GetChromePath() {
    HKEY hKey;
    char path[512];
    DWORD pathSize = sizeof(path);
    
    // Coba membaca registry untuk versi 64-bit
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\chrome.exe", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        if (RegQueryValueExA(hKey, "", NULL, NULL, (LPBYTE)path, &pathSize) == ERROR_SUCCESS) {
            RegCloseKey(hKey);
            return std::string(path);
        }
        RegCloseKey(hKey);
    }
    
    // Jika tidak ditemukan, kembalikan string kosong
    return "";
}

int main() {
    std::string chromePath = GetChromePath();
    
    if (chromePath.empty()) {
        std::cerr << "Google Chrome tidak ditemukan." << std::endl;
        return 1;
    }
    
    // Mencoba membuka Google Chrome
    HINSTANCE result = ShellExecuteA(NULL, "open", chromePath.c_str(), "http://www.google.com", NULL, SW_SHOWNORMAL);

    if (reinterpret_cast<intptr_t>(result) <= 32) {
        std::cerr << "Gagal membuka Google Chrome." << std::endl;
        return 1;
    }

    return 0;
}
      
