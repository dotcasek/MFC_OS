#pragma once


// CAttribDlg dialog

class CAttribDlg : public CDialog
{
	DECLARE_DYNAMIC(CAttribDlg)

public:
	CAttribDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAttribDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ATRIB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_readonly;
	int m_hidden;
	int m_archive;
	int m_system;
};
