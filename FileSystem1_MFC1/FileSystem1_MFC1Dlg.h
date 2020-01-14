
// FileSystem1_MFC1Dlg.h : файл заголовка
//

#pragma once


// диалоговое окно CFileSystem1_MFC1Dlg
class CFileSystem1_MFC1Dlg : public CDialogEx
{
// Создание
public:
	CFileSystem1_MFC1Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILESYSTEM1_MFC1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

    CEdit m_editTarget;
    CListCtrl m_listFiles;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnList();
};
