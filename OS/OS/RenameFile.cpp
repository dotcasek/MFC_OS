// RenameFile.cpp : implementation file
//

#include "stdafx.h"
#include "RenameFile.h"
#include "afxdialogex.h"
#include "resource.h"


// CRenameFile dialog

IMPLEMENT_DYNAMIC(CRenameFile, CDialog)

CRenameFile::CRenameFile(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_RENAME, pParent)
	, m_old_file(_T(""))
	, m_new_file(_T(""))
{

}

CRenameFile::~CRenameFile()
{
}

void CRenameFile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ET_OLDFILE, m_old_file);
	DDX_Text(pDX, IDC_ET_NEWFILE, m_new_file);
}


BEGIN_MESSAGE_MAP(CRenameFile, CDialog)
	ON_BN_CLICKED(IDOK, &CRenameFile::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CRenameFile::OnBnClickedCancel)
END_MESSAGE_MAP()


// CRenameFile message handlers


void CRenameFile::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}


void CRenameFile::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
