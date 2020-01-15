#include <Windows.h>
#include <cstdio>
#include <tchar.h>

DWORD const DIR_DEPTH = 3;
DWORD const DIR_QTY = 3;
DWORD const FILES_QTY = 3;

WCHAR const DIR_PREFIX [] = L"DIR_";
WCHAR const FILE_PREFIX [] = L"FILE_";

BOOL IsDirExist(LPCWSTR dirPath) {
    DWORD nFileAttribs = GetFileAttributes(dirPath);
    if (nFileAttribs != INVALID_FILE_ATTRIBUTES) {
        return (nFileAttribs & FILE_ATTRIBUTE_DIRECTORY) != 0;
    }
    return FALSE;
}

void PopulateDirectory(LPCWSTR root, DWORD nDepthLevel, DWORD * const counter) {

    DWORD const BUF_SIZE = 512;
    WCHAR buffer[BUF_SIZE] = {0};

    if (nDepthLevel > 0) {
        for(DWORD i = 0; i < DIR_QTY; i++) {
            ZeroMemory(buffer, BUF_SIZE);
            wsprintf(buffer, L"%s\\%s%02d", root, DIR_PREFIX, i);
            if(!CreateDirectory(buffer, LPSECURITY_ATTRIBUTES(nullptr))) {
                // error occurred!
                DWORD nRes = GetLastError();
                if (nRes == ERROR_ALREADY_EXISTS) {
                    wprintf(L"[W] CreateDirectory: Directory %s already exist! (error %u)\n", buffer, nRes);
                }
                else if (nRes == ERROR_PATH_NOT_FOUND) {
                    wprintf(L"[E] CreateDirectory: Path not found: %s (error %u)\n", buffer, nRes);
                    break;
                }
                else {
                    wprintf(L"[E] CreateDirectory Error occured: %u\n", nRes);
                    break;
                }
            }
            if (counter != nullptr) *counter += 1;
            PopulateDirectory(buffer, nDepthLevel - 1, counter);
        }
    }

    for (DWORD i = 0; i < FILES_QTY; i++) {
        //WCHAR buffer[BUF_SIZE] = {0};
        ZeroMemory(buffer, BUF_SIZE);
        wsprintf(buffer, L"%s\\%s%02d.txt", root, FILE_PREFIX, i);
        HANDLE hFile = CreateFile(buffer, 
                                  GENERIC_WRITE,
                                  FILE_SHARE_READ,
                                  LPSECURITY_ATTRIBUTES(nullptr),
                                  CREATE_NEW,
                                  FILE_ATTRIBUTE_NORMAL,
                                  NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            // error occurred!
            DWORD nRes = GetLastError();
            if (nRes == ERROR_FILE_EXISTS) {
                wprintf(L"[W] CreateFile: File %s exists! (error %d)\n", buffer, nRes);
            }
            else {
                wprintf(L"[E] CreateFile: Error occured: %u\n", nRes);
            }
            break;
        }

        ZeroMemory(buffer, BUF_SIZE);
        wsprintf(buffer, L"Contents of a file %s\\%s%02d\nHello WinAPI!\n", root, FILE_PREFIX, i);
        DWORD nTextLen = _tcsclen(buffer);
        DWORD nBytesWritten = 0;
        BOOL bWriteRes = WriteFile(hFile, buffer, nTextLen*sizeof(WCHAR), &nBytesWritten, LPOVERLAPPED(nullptr));
        if (!bWriteRes) {
            // error occurred!
            DWORD nRes = GetLastError();
            wprintf(L"Write file: error occured: %u\n", nRes);
            CloseHandle(hFile);
            break;
        }

        if (hFile != INVALID_HANDLE_VALUE) {
            CloseHandle(hFile);
        }
        if (counter != nullptr) *counter += 1;
    }
}

int _tmain() {
    LPWSTR pszFileName = L"D:\\test2";
    DWORD counter = 0;

    if (!IsDirExist(pszFileName)) {
        if(!CreateDirectory(pszFileName, LPSECURITY_ATTRIBUTES(nullptr))) {
            // error occurred!
            DWORD nRes = GetLastError();
            wprintf(L"CreateDirectory Error occured: %u\n", nRes);
            return -1;
        }
    }
    PopulateDirectory(pszFileName, 5, &counter);

    return 0;
}