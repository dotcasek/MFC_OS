// SingleFile.cpp : implementation file
//

#include "stdafx.h"
#include "SingleFile.h"
#include "afxdialogex.h"
#include "resource.h"


// CSingleFile dialog

IMPLEMENT_DYNAMIC(CSingleFile, CDialog)

CSingleFile::CSingleFile(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_SFILE, pParent)
	, m_filename(_T(""))
{

}

CSingleFile::~CSingleFile()
{
}

void CSingleFile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ET_FILENAME, m_filename);
}


BEGIN_MESSAGE_MAP(CSingleFile, CDialog)
	ON_BN_CLICKED(IDOK, &CSingleFile::OnBnClickedOk)
END_MESSAGE_MAP()


// CSingleFile message handlers


void CSingleFile::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
