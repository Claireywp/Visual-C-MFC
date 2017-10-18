#if !defined(AFX_DIALOG1_H__34D066DC_8A03_4793_B5E5_EB0327E40E40__INCLUDED_)
#define AFX_DIALOG1_H__34D066DC_8A03_4793_B5E5_EB0327E40E40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialog1 dialog

class CDialog1 : public CDialog
{
// Construction
public:
	CDialog1(CWnd* pParent = NULL);   // standard constructor

	CString a;

// Dialog Data
	//{{AFX_DATA(CDialog1)
	enum { IDD = IDD_DIALOG1 };
	CButton	m_Hoo2;
	CButton	m_Hoo1;
	CButton	m_Xl;
	CButton	m_Sex;
	CEdit	m_Name;
	CComboBox	m_Mz;
	CEdit	m_Home;
	CEdit	m_Age;
	CString	m_strAge;
	CString	m_strHome;
	CString	m_nMz;
	CString	m_strName;
	int		m_nSex;
	int		m_nXl;
	BOOL	m_aihao1;
	BOOL	m_aihao2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialog1)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnSex2();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnXl4();
	afx_msg void OnHoo1();
	afx_msg void OnHoo2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1_H__34D066DC_8A03_4793_B5E5_EB0327E40E40__INCLUDED_)
