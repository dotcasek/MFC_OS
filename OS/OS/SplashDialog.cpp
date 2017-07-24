// SplashDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SplashDialog.h"
#include "afxdialogex.h"
#include "resource.h"


// SplashDialog dialog

IMPLEMENT_DYNAMIC(SplashDialog, CDialog)

SplashDialog::SplashDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SPLASH_DIALOG, pParent)
{

}

SplashDialog::~SplashDialog()
{
}

void SplashDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SplashDialog, CDialog)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// SplashDialog message handlers


void SplashDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	EndDialog(0);
	CDialog::OnTimer(nIDEvent);
}


void SplashDialog::OnPaint()
{
	CPaintDC dc(this); 
	SetTimer(1, 3000, NULL);
}


void SplashDialog::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnClose();
}
