// WkfDrawingView.h : CWkfDrawingView ��Ľӿ�
//


#pragma once
#include "atltypes.h"
#include "afxwin.h"
#include "Txtlog.h"
#include "LWidth.h"



class CWkfDrawingView : public CView
{
protected: // �������л�����
	CWkfDrawingView();
	DECLARE_DYNCREATE(CWkfDrawingView)

// ����
public:
	CWkfDrawingDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CWkfDrawingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
private:
	CPoint my_point;//����
	afx_msg void OnLine();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int MyDrawStyle;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRectangle();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint MyStart;
	CPoint MyEnd;
	bool b;
	CClientDC* pdc;
	afx_msg void OnCircle();
	afx_msg void OnPancolor();
	COLORREF Pcolor;
	CBrush newBrush;
	CBrush oldBrush;
	afx_msg void OnTxt();
	afx_msg void OnLineW();
	afx_msg void OnTrectangle();
	afx_msg void OnTcircle();
	afx_msg void OnSolid();
	afx_msg void OnDash();
	afx_msg void OnDot();
	afx_msg void OnDashdot();
	afx_msg void OnDashdotdot();
	int type;//��������
	int MyWidth;//���ʿ��
	CPen* OldPen;
	afx_msg void OnYtrectangle();
	afx_msg void OnTytrectangle();
	CPoint a;
	afx_msg void OnFont();
	CFont MyFont;
	CString MyFontName;
};

#ifndef _DEBUG  // WkfDrawingView.cpp �еĵ��԰汾
inline CWkfDrawingDoc* CWkfDrawingView::GetDocument() const
   { return reinterpret_cast<CWkfDrawingDoc*>(m_pDocument); }
#endif

