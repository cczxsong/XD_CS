// Traxffic.h : main header file for the TRAXFFIC application
//

#if !defined(AFX_TRAXFFIC_H__E38A4E5B_B0F7_441C_8577_B626610AC942__INCLUDED_)
#define AFX_TRAXFFIC_H__E38A4E5B_B0F7_441C_8577_B626610AC942__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTraxfficApp:
// See Traxffic.cpp for the implementation of this class
//

class CTraxfficApp : public CWinApp
{
public:
	int yellow_time;
	int redgreen_time;
	CTraxfficApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTraxfficApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTraxfficApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAXFFIC_H__E38A4E5B_B0F7_441C_8577_B626610AC942__INCLUDED_)
