#pragma once


// SplashDialog dialog

class SplashDialog : public CDialog
{
	DECLARE_DYNAMIC(SplashDialog)

public:
	SplashDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~SplashDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPLASH_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	afx_msg void OnClose();
};
