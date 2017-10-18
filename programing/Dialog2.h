#if !defined(AFX_DIALOG2_H__39F01795_7863_4D93_8554_5CC4A2F9F57D__INCLUDED_)
#define AFX_DIALOG2_H__39F01795_7863_4D93_8554_5CC4A2F9F57D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog2 dialog

class CDialog2 : public CDialog
{
// Construction
public:
	CDialog2(CWnd* pParent = NULL);   // standard constructor
	CString a;

// Dialog Data
	//{{AFX_DATA(CDialog2)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_XL;
	CEdit	m_Ad;
	CEdit	m_Mz;
	CEdit	m_Ah;
	CEdit	m_Sex;
	CEdit	m_Name;
	CEdit	m_Age;
	CString	m_nAge;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog2)
	virtual void OnOK();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG2_H__39F01795_7863_4D93_8554_5CC4A2F9F57D__INCLUDED_)
