#pragma once


// CPathDialog dialog

class CPathDialog : public CDialog
{
	DECLARE_DYNAMIC(CPathDialog)

public:
	CPathDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPathDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PATH_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_et_path;
	//TCHAR* path = nullptr;
	afx_msg void OnBnClickedOk();
};
