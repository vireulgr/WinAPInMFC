#include <Windows.h>
#include <tchar.h>

    //Ошибка, текущий пользователь не является администратором компьютера!
    //Завершите сеанс работы и войдите в систему пользователем обладающим правами администратора; повторите установку.
    //Установка не может быть продолжена.

int _tmain() {
    LPWSTR lpFileName = L"D:\\prog\\vcs\\psbat\\*";
    HANDLE hFindFile;
    WIN32_FIND_DATA a;

    hFindFile = FindFirstFile(lpFileName, &a);
    if (hFindFile == INVALID_HANDLE_VALUE) {
        DWORD nRes = GetLastError();
        if (nRes == ERROR_PATH_NOT_FOUND || nRes == ERROR_FILE_NOT_FOUND) {
            wprintf(L"Error path not found; %d\n", nRes);
        }
        else {
            wprintf(L"Error occured; %d\n", nRes);
        }
        return nRes;
    }
    else {
        wprintf(L"FileName: %s\n", a.cFileName);
    }

    do {
        if ((a.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
            if (wcscmp(a.cFileName, L".") != 0
               && wcscmp(a.cFileName, L"..") != 0)
            {
                wprintf(L"%s\n", a.cFileName);
            }
            else {
                wprintf(L"found %s\n", a.cFileName);
            }
        }
        else {
            LARGE_INTEGER fileSize;
            fileSize.LowPart = a.nFileSizeLow;
            fileSize.HighPart = a.nFileSizeHigh;
            wprintf(L"%s %lld\n", a.cFileName, fileSize.QuadPart);
        }

    } while (FindNextFile(hFindFile, &a) != 0);

    DWORD nRes = GetLastError();
    if (nRes != ERROR_NO_MORE_FILES) {
        MessageBox(NULL, L"Error occurred!", L"Error", MB_OK | MB_ICONERROR);

    }

    FindClose(hFindFile);

    return 0;
}