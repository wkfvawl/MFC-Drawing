// WkfDrawingDoc.h : CWkfDrawingDoc ��Ľӿ�
//

#include "Afxtempl.h"

#pragma once


class CWkfDrawingDoc : public CDocument
{
protected: // �������л�����
	CWkfDrawingDoc();
	DECLARE_DYNCREATE(CWkfDrawingDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CWkfDrawingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CList <GPen,GPen> Mylist;
};


