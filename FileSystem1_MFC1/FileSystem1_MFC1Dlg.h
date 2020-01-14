
// FileSystem1_MFC1Dlg.h : ���� ���������
//

#pragma once


// ���������� ���� CFileSystem1_MFC1Dlg
class CFileSystem1_MFC1Dlg : public CDialogEx
{
// ��������
public:
	CFileSystem1_MFC1Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILESYSTEM1_MFC1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

    CEdit m_editTarget;
    CListCtrl m_listFiles;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnList();
};
