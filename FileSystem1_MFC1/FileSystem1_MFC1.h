
// FileSystem1_MFC1.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CFileSystem1_MFC1App:
// О реализации данного класса см. FileSystem1_MFC1.cpp
//

class CFileSystem1_MFC1App : public CWinApp
{
public:
	CFileSystem1_MFC1App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CFileSystem1_MFC1App theApp;