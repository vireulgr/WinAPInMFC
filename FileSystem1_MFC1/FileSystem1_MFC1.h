
// FileSystem1_MFC1.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CFileSystem1_MFC1App:
// � ���������� ������� ������ ��. FileSystem1_MFC1.cpp
//

class CFileSystem1_MFC1App : public CWinApp
{
public:
	CFileSystem1_MFC1App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CFileSystem1_MFC1App theApp;