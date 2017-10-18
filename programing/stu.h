// stu.h : main header file for the STU application
//

#if !defined(AFX_STU_H__7B108FD5_4551_4A47_BFBA_4B667CE55A9A__INCLUDED_)
#define AFX_STU_H__7B108FD5_4551_4A47_BFBA_4B667CE55A9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStuApp:
// See stu.cpp for the implementation of this class
//

class CStuApp : public CWinApp
{
public:
	CStuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STU_H__7B108FD5_4551_4A47_BFBA_4B667CE55A9A__INCLUDED_)
