/*
This program simulates an operating system

CIT 284 Adv C++

Derek Otcasek

5/13/2017

*/

#include <afxwin.h>
#include "resource.h"
#include "SplashDialog.h"
#include "afxdlgs.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include "PathDialog.h"
#include "DlgDir.h"
#include <afx.h>
#include "RenameFile.h"
#include "SingleFile.h"
#include "AttribDlg.h"

#define MAX_CFileDialog_FILE_COUNT 99
#define FILE_LIST_BUFFER_SIZE ((MAX_CFileDialog_FILE_COUNT * (MAX_PATH + 1)) + 1)

CListBox clb;
CString sPath = "C:\\";

// -----------------CWinApp----------------------//
class CMyApp : public CWinApp
{
	HACCEL m_hAccelTable;
public:
	virtual BOOL InitInstance() override;

	DECLARE_MESSAGE_MAP()
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
	afx_msg void OnPlaygameHenway();
	afx_msg void OnGamesBattleoffice();
	afx_msg void OnFileDisplayfile();
	afx_msg void OnFilePrint();
	afx_msg void OnFileClearscreen();
	afx_msg void OnMenu();
	afx_msg void OnHelpDate();
	afx_msg void OnHelpAbout();
	afx_msg void OnViewDisplaydirectory();
	afx_msg void OnViewChangedirectory();
	afx_msg void OnViewMakedirectory();
	afx_msg void OnViewRemovedirectory();
	afx_msg void OnFileRenamefile();
	afx_msg void OnFileCopyfile();
	afx_msg void OnFileDeletefile();
	afx_msg void OnFileExit();
	afx_msg void OnFileChangefileatrributes();
	afx_msg void OnFileEdit();
};

//-------------- Splash Window --------------//
class CPopUp : public CFrameWnd
{

public:
	CPopUp(CString message)
	{
		Create(NULL, message,
			WS_POPUPWINDOW | WS_CAPTION,
			CRect(400, 280, 580, 520), NULL, NULL,
			WS_EX_TOOLWINDOW);
	}
};

// ------------------ Main Window --------------- //
class CMyWnd : public CFrameWnd
{
	CMenu menu;

public:

	CMyWnd()
	{
		Create(WS_OVERLAPPED, _T("Windows Mania"));
		clb.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL,
			CRect(50, 40, 1000, 600), this, IDC_LISTBOX);
		menu.LoadMenu(IDR_MENU1);
		SetMenu(&menu);
	}
};

// ------------- Init App ------------------- //
BOOL CMyApp :: InitInstance() 
{
	m_hAccelTable = LoadAccelerators(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDR_ACCELERATOR1));

	m_pMainWnd = new CMyWnd;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	SplashDialog sp;
	sp.DoModal();

	return TRUE;
}
// ----------------- Accelerator handler ------------------ //
BOOL CMyApp::ProcessMessageFilter(int code, LPMSG lpMsg)
{
	if (code >= 0 && m_pMainWnd && m_hAccelTable) {

		if (::TranslateAccelerator(m_pMainWnd->m_hWnd, m_hAccelTable, lpMsg))
			return TRUE;
	}
	return CWinApp::ProcessMessageFilter(code, lpMsg);
}


CMyApp app; 

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
ON_COMMAND(ID_GAMES_HENWAY, &CMyApp::OnPlaygameHenway)
ON_COMMAND(ID_GAMES_BATTLEOFFICE, &CMyApp::OnGamesBattleoffice)
ON_COMMAND(ID_FILE_DISPLAYFILE, &CMyApp::OnFileDisplayfile)
ON_COMMAND(ID_FILE_PRINT, &CMyApp::OnFilePrint)
ON_COMMAND(ID_FILE_CLEARSCREEN, &CMyApp::OnFileClearscreen)
ON_COMMAND(ID_HELP_TIME, &CMyApp::OnMenu)
ON_COMMAND(ID_HELP_DATE, &CMyApp::OnHelpDate)
ON_COMMAND(ID_HELP_ABOUT, &CMyApp::OnHelpAbout)
ON_COMMAND(ID_VIEW_DISPLAYDIRECTORY, &CMyApp::OnViewDisplaydirectory)
ON_COMMAND(ID_VIEW_CHANGEDIRECTORY, &CMyApp::OnViewChangedirectory)
ON_COMMAND(ID_VIEW_MAKEDIRECTORY, &CMyApp::OnViewMakedirectory)
ON_COMMAND(ID_VIEW_REMOVEDIRECTORY, &CMyApp::OnViewRemovedirectory)
ON_COMMAND(ID_FILE_RENAMEFILE, &CMyApp::OnFileRenamefile)
ON_COMMAND(ID_FILE_COPYFILE, &CMyApp::OnFileCopyfile)
ON_COMMAND(ID_FILE_DELETEFILE, &CMyApp::OnFileDeletefile)
ON_COMMAND(ID_FILE_EXIT, &CMyApp::OnFileExit)
ON_COMMAND(ID_FILE_CHANGEFILEATRRIBUTES, &CMyApp::OnFileChangefileatrributes)
ON_COMMAND(ID_FILE_EDIT, &CMyApp::OnFileEdit)
END_MESSAGE_MAP()

// --------- Launches Henway if is in the current directory ------ //
void CMyApp::OnPlaygameHenway()
{
	CString fileName = sPath + "Henway.exe";
	CString path = sPath + "Henway.exe";
	
	if (GetFileAttributes(path) == INVALID_FILE_ATTRIBUTES) {
		AfxMessageBox(_T("ERROR:\nGame not in current Directory\nmust be \"executables\" in VS project folder"), MB_OK | MB_ICONERROR);
	}
	else {
		ShellExecute(0, _T("open"), fileName, path, NULL, SW_NORMAL);
	}
}

// --------- Launches BattleOffice if is in the current directory ------ //
void CMyApp::OnGamesBattleoffice()
{
	CString fileName = sPath + "BattleOffice.exe";
	CString path = sPath + "BattleOffice.exe";

	if (GetFileAttributes(path) == INVALID_FILE_ATTRIBUTES) {
		AfxMessageBox(_T("ERROR:\nGame not in current Directory\nmust be \"executables\" in VS project folder"), MB_OK | MB_ICONERROR);
	}
	else {
		ShellExecute(0, _T("open"), fileName, path, NULL, SW_NORMAL);
	}
}

// --------- Opens a file and displays its contents in the window ------ //

void CMyApp::OnFileDisplayfile()
{
	CString fileName;
	wchar_t* p = fileName.GetBuffer(FILE_LIST_BUFFER_SIZE);
	CFileDialog dlgFile(TRUE);
	OPENFILENAME& ofn = dlgFile.GetOFN();
	ofn.Flags |= OFN_ALLOWMULTISELECT;
	ofn.lpstrFile = p;
	ofn.nMaxFile = FILE_LIST_BUFFER_SIZE;

	dlgFile.DoModal();
	fileName.ReleaseBuffer();

	wchar_t* pBufEnd = p + FILE_LIST_BUFFER_SIZE - 2;
	wchar_t* start = p;
	while ((p < pBufEnd) && (*p))
		p++;
	if (p > start)
	{
		_tprintf(_T("Path to folder where files were selected:  %s\r\n\r\n"), start);
		p++;

		int fileCount = 1;
		while ((p < pBufEnd) && (*p))
		{
			start = p;
			while ((p < pBufEnd) && (*p))
				p++;
			if (p > start)
				_tprintf(_T("%2d. %s\r\n"), fileCount, start);
			p++;
			fileCount++;
			
		}
	}

	// open file in text mode
	// setText of window to file text
	std::fstream dataFile;
	dataFile.open(fileName, std::ios::in | std::ios::out);
	std::string line;

	CString text;
	clb.ResetContent();
	while (dataFile) {
		getline(dataFile, line);
		text = line.c_str();
		
		clb.AddString(text);
	}
}


// --------- Opens a dialog for printing ------ //
void CMyApp::OnFilePrint()
{
	CPrintDialog dlg(FALSE);
	dlg.DoModal();
}

// --------- clears the screen ------ //
void CMyApp::OnFileClearscreen()
{
	clb.ResetContent();

}

// --------- Opens a dialog to display current time ------ //
void CMyApp::OnMenu()
{
	CString t = CTime::GetCurrentTime().Format("%H:%M");
	AfxMessageBox(_T("Current time: " + t), MB_OK );
}

// --------- Opens a dialog to display the date ------ //
void CMyApp::OnHelpDate()
{
	CString s = CTime::GetCurrentTime().Format("%m/%d/%Y");
	AfxMessageBox(_T("Current date: " + s), MB_OK);
}

// --------- Opens a dialog to display about this app ------ //
void CMyApp::OnHelpAbout()
{
	AfxMessageBox(_T("WINDOWS MANIA \nCopyright bhcc 2017 \n Derek Otcasek"), MB_OK);
}

// --------- Displays the contents of the current directory in the window ------ //
void CMyApp::OnViewDisplaydirectory()
{
	if (sPath[sPath.GetLength()-1] != _T('\\')) {
		sPath += '\\';
	}

	CFileFind hFile;
	BOOL bFound = hFile.FindFile(sPath + _T("*.*"));

	CString name;

	if (GetFileAttributes(sPath) == INVALID_FILE_ATTRIBUTES) {
		AfxMessageBox(_T("ERROR:\nDirectory not found\n" + sPath), MB_OK | MB_ICONERROR);

	}
	else {
		clb.AddString("Showing Contents of " + sPath);

		while (bFound)
		{
			bFound = hFile.FindNextFile();
			if ((!hFile.IsDots()) )// && (hFile.IsDirectory())
			{
				name = hFile.GetFileName();

				clb.AddString(name);
			}
		}
	}
}

// --------- Opens a dialog to choose a different directory ------ //
void CMyApp::OnViewChangedirectory()
{
	if (sPath[sPath.GetLength() - 1] != _T('\\')) {
		sPath += '\\';
	}

	CPathDialog cpd;
	cpd.m_et_path = sPath;

	if (cpd.DoModal() == IDOK) {

		sPath = cpd.m_et_path;
	}
}

// --------- Creates a new directory in the current directory ------ //
void CMyApp::OnViewMakedirectory()
{
	CString dirName;
	CDlgDir dir;
	if (dir.DoModal() == IDOK) {
	
		dirName = dir.m_et_dir;


		if (!CreateDirectory(sPath + "\\" + dirName, NULL))
		{
			AfxMessageBox(_T("Create Directory failed"), MB_OK);
			return;
		}
		clb.AddString(_T("Directory Added"));
	}
}

// --------- Deletes an empty directory ------ //
void CMyApp::OnViewRemovedirectory()
{
	CString dirName;
	CDlgDir dir;
	if (dir.DoModal() == IDOK) {
	
		dirName = dir.m_et_dir;

		if (!RemoveDirectory(sPath + "\\" + dirName))
		{
			AfxMessageBox(_T("Remove Directory failed"), MB_OK);
			return;
		}
		clb.AddString(_T("Directory Removed"));
	}
}

// --------- Changes the name of a file in the current directory ------ //
void CMyApp::OnFileRenamefile()
{

	CString oldName, newName;

	CRenameFile rn;
	if (rn.DoModal() == IDOK) {

		oldName = rn.m_old_file;
		newName = rn.m_new_file;

		try
		{
			CFile::Rename(sPath + "\\" + oldName, sPath + "\\" + newName);
			clb.AddString(_T("File renamed successfullly"));

		}
		catch (CFileException* pEx)
		{
			TRACE(_T("File %20s not found, cause = %d\n"), oldName,
				pEx->m_cause);
			pEx->Delete();
			AfxMessageBox(_T("Rename failed"), MB_OK);

		}
	}
}

// --------- Creates a copy of a file in the current directory ------ //
void CMyApp::OnFileCopyfile()
{
	CString fileName;

	CSingleFile sf;
	if (sf.DoModal() == IDOK) {

		fileName = sf.m_filename;


		if (!CopyFile(sPath + "\\" + fileName, sPath + "\\" + fileName + _T("(copy)"), NULL))
		{
			AfxMessageBox(_T("Copy File failed"), MB_OK);
			return;
		}
		clb.AddString(_T("file Copied"));
	}
}

// --------- Deletes a file in the current directory ------ //
void CMyApp::OnFileDeletefile()
{

	CString fileName;

	CSingleFile sf;
	if (sf.DoModal() == IDOK) {

		fileName = sf.m_filename;

		if (AfxMessageBox(_T("Are you sure you want to delete\n" + fileName), MB_YESNO) == IDYES) {

			if (!DeleteFile(sPath + "\\" + fileName))
			{
				AfxMessageBox(_T("Delete failed"), MB_OK);
				return;
			}
			clb.AddString(_T("file Deleted"));
		}
	}
	
}

// --------- Exits the program ------ //
void CMyApp::OnFileExit()
{
	int result = AfxMessageBox(_T("Are you sure you want to exit?"), MB_ICONQUESTION | MB_YESNO);
	if (result == IDYES) {
		CMyApp::m_pMainWnd->DestroyWindow();
	}
}

// --------- Opens a dialog to change various file attributes ------ //
void CMyApp::OnFileChangefileatrributes()
{
	DWORD dwAttr;
	CString fileName, readonly, hidden, system, archive;
	CAttribDlg atg;

	dwAttr = GetFileAttributes(sPath + "\\" + fileName);


	if (atg.DoModal() == IDOK) {

		if (atg.m_readonly == 0) {
			SetFileAttributes(sPath + "\\" + fileName, dwAttr | FILE_ATTRIBUTE_READONLY);
		}
		else {
			SetFileAttributes(sPath + "\\" + fileName, dwAttr & ~FILE_ATTRIBUTE_READONLY);
		}

		dwAttr = GetFileAttributes(sPath + "\\" + fileName);

		if (atg.m_hidden == 0) {
			SetFileAttributes(sPath + "\\" + fileName, dwAttr | FILE_ATTRIBUTE_HIDDEN);
		}
		else {
			SetFileAttributes(sPath + "\\" + fileName, dwAttr & ~FILE_ATTRIBUTE_HIDDEN);
		}

		dwAttr = GetFileAttributes(sPath + "\\" + fileName);

		if (atg.m_system == 0) {
			SetFileAttributes(sPath + "\\" + fileName, dwAttr | FILE_ATTRIBUTE_SYSTEM);
		}
		else {
			SetFileAttributes(sPath + "\\" + fileName, dwAttr & ~FILE_ATTRIBUTE_SYSTEM);
		}

		dwAttr = GetFileAttributes(sPath + "\\" + fileName);

		if (atg.m_archive == 0) {
			SetFileAttributes(sPath + "\\" + fileName, dwAttr | FILE_ATTRIBUTE_ARCHIVE);
		}
		else {
			SetFileAttributes(sPath + "\\" + fileName, dwAttr & ~FILE_ATTRIBUTE_ARCHIVE);
		}

	}

	// --------- Opens a messagebox to display the attributes of the file ------ //

	CFileStatus status;
	CFile::GetStatus(sPath + "\\" + fileName, status);

	if ((status.m_attribute & 0x01) == 0x01)
		readonly = "true";
	else
		readonly = "false";
	if ((status.m_attribute & 0x02) == 0x02)
		hidden = "true";
	else
		hidden = "false";
	if ((status.m_attribute & 0x04) == 0x04)
		system = "true";
	else
		system = "false";
	if ((status.m_attribute & 0x04) == 0x20)
		archive = "true";
	else
		archive = "false";

	AfxMessageBox(_T("File Attributes\nRead only: " + readonly + "\n" +
		"hidden: " + hidden + "\n" +
		"system: " + system + "\n" +
		"archive: " + archive), MB_OK);

}

// --------- Opens a text file for editing ------ //
void CMyApp::OnFileEdit()
{
	CreateDirectory(_T("c:\\test\\"), NULL);
	CFile cfile_object( _T("c:\\test\\untitled.txt"), CFile::modeCreate|CFile:: modeReadWrite);
	ShellExecute(NULL, _T("open"), _T("c:\\test\\untitled.txt"), NULL, NULL, SW_NORMAL);
}
