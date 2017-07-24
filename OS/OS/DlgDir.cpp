// DlgDir.cpp : implementation file
//

#include "stdafx.h"
#include "DlgDir.h"
#include "afxdialogex.h"
#include "resource.h"


// CDlgDir dialog

IMPLEMENT_DYNAMIC(CDlgDir, CDialog)

CDlgDir::CDlgDir(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_DIR, pParent)
	, m_et_dir(_T(""))
{

}

CDlgDir::~CDlgDir()
{
}

void CDlgDir::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ET_DIR, m_et_dir);
}


BEGIN_MESSAGE_MAP(CDlgDir, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgDir::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgDir::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgDir message handlers


void CDlgDir::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_ET_DIR, m_et_dir);
	CDialog::OnOK();
}


void CDlgDir::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
