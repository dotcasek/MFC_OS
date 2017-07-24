// AttribDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AttribDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// CAttribDlg dialog

IMPLEMENT_DYNAMIC(CAttribDlg, CDialog)

CAttribDlg::CAttribDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_ATRIB, pParent)
	, m_readonly(0)
	, m_hidden(0)
	, m_archive(0)
	, m_system(0)
{

}

CAttribDlg::~CAttribDlg()
{
}

void CAttribDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_READONLY_ON, m_readonly);
	DDX_Radio(pDX, IDC_HIDDEN_ON, m_hidden);
	DDX_Radio(pDX, IDC_ARCHIVE_ON, m_archive);
	DDX_Radio(pDX, IDC_SYSTEM_ON, m_system);
}


BEGIN_MESSAGE_MAP(CAttribDlg, CDialog)
END_MESSAGE_MAP()


// CAttribDlg message handlers
