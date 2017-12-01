
// MFCSingleViewOpenGL.h : main header file for the MFCSingleViewOpenGL application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCSingleViewOpenGLApp:
// See MFCSingleViewOpenGL.cpp for the implementation of this class
//

class CMFCSingleViewOpenGLApp : public CWinAppEx
{
public:
	CMFCSingleViewOpenGLApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSingleViewOpenGLApp theApp;
