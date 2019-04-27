// TraxfficDlg.h : header file
//

#if !defined(AFX_TRAXFFICDLG_H__E6C356CA_55FC_4434_8A65_E7BDA228BB05__INCLUDED_)
#define AFX_TRAXFFICDLG_H__E6C356CA_55FC_4434_8A65_E7BDA228BB05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTraxfficDlg dialog

class CTraxfficDlg : public CDialog
{
// Construction
public:
	CTraxfficDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTraxfficDlg)
	enum { IDD = IDD_TRAXFFIC_DIALOG };
	int	m_redgreen_time;
	int	m_yellow_time;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTraxfficDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTraxfficDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton();
	afx_msg void OnChangeEdit4();
	afx_msg void OnChangeEdit5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAXFFICDLG_H__E6C356CA_55FC_4434_8A65_E7BDA228BB05__INCLUDED_)
