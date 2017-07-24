// PathDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PathDialog.h"
#include "afxdialogex.h"
#include "resource.h"


// CPathDialog dialog

IMPLEMENT_DYNAMIC(CPathDialog, CDialog)

CPathDialog::CPathDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PATH_DIALOG, pParent)
	, m_et_path(_T(""))
{

}

CPathDialog::~CPathDialog()
{
}

void CPathDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ET_PATH, m_et_path);
}


BEGIN_MESSAGE_MAP(CPathDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CPathDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CPathDialog message handlers


void CPathDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_ET_PATH, m_et_path);

	//path = m_et_path.GetBuffer(m_et_path.GetLength());
	//m_et_path.ReleaseBuffer();

	CDialog::OnOK();

}
