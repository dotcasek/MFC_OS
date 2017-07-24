#pragma once


// CRenameFile dialog

class CRenameFile : public CDialog
{
	DECLARE_DYNAMIC(CRenameFile)

public:
	CRenameFile(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRenameFile();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_old_file;
	CString m_new_file;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
