// serialToolDlg.h : header file
//

#if !defined(AFX_SERIALTOOLDLG_H__F509B239_B86D_4EAF_B3C3_F5107833D18B__INCLUDED_)
#define AFX_SERIALTOOLDLG_H__F509B239_B86D_4EAF_B3C3_F5107833D18B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "8051IF.h"

/////////////////////////////////////////////////////////////////////////////
// CSerialToolDlg dialog

class CSerialToolDlg : public CDialog
{
// Construction
public:
	CSerialToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSerialToolDlg)
	enum { IDD = IDD_SERIALTOOL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerialToolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	C8051IF  m_8051If;

	// Generated message map functions
	//{{AFX_MSG(CSerialToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	void OnTimer(UINT nIDEvent);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.






#endif // !defined(AFX_SERIALTOOLDLG_H__F509B239_B86D_4EAF_B3C3_F5107833D18B__INCLUDED_)
