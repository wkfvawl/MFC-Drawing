// WkfDrawing.h : WkfDrawing Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CWkfDrawingApp:
// �йش����ʵ�֣������ WkfDrawing.cpp
//

class CWkfDrawingApp : public CWinApp
{
public:
	CWkfDrawingApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWkfDrawingApp theApp;