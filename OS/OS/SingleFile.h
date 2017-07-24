#pragma once


// CSingleFile dialog

class CSingleFile : public CDialog
{
	DECLARE_DYNAMIC(CSingleFile)

public:
	CSingleFile(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSingleFile();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_filename;
	afx_msg void OnBnClickedOk();
};
