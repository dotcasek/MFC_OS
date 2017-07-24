#pragma once


// CDlgDir dialog

class CDlgDir : public CDialog
{
	DECLARE_DYNAMIC(CDlgDir)

public:
	CDlgDir(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgDir();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DIR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_et_dir;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
