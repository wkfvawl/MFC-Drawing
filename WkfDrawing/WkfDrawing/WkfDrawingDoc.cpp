// WkfDrawingDoc.cpp : CWkfDrawingDoc ���ʵ��
//

#include "stdafx.h"
#include "WkfDrawing.h"

#include "WkfDrawingDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWkfDrawingDoc

IMPLEMENT_DYNCREATE(CWkfDrawingDoc, CDocument)

BEGIN_MESSAGE_MAP(CWkfDrawingDoc, CDocument)
END_MESSAGE_MAP()


// CWkfDrawingDoc ����/����

CWkfDrawingDoc::CWkfDrawingDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CWkfDrawingDoc::~CWkfDrawingDoc()
{
}

BOOL CWkfDrawingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CWkfDrawingDoc ���л�

void CWkfDrawingDoc::Serialize(CArchive& ar)
{
	int i;
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar<<Mylist.GetCount();
		GPen g;
		POSITION pos = Mylist.GetHeadPosition();
		for(i = 0;i<Mylist.GetCount();i++)
		{
			g = Mylist.GetNext(pos);
			ar<<g.type<<g.width<<g.pencolor<<g.c<<g.start<<g.end<<g.style<<g.angle;
		}
		
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		int count;
		ar>>count;
		GPen g;
		POSITION pos = Mylist.GetHeadPosition();
		for(i = 0;i<count;i++)
		{
			ar>>g.type>>g.width>>g.pencolor>>g.c>>g.start>>g.end>>g.style>>g.angle;
			Mylist.AddTail(g);
		}
	}
}


// CWkfDrawingDoc ���

#ifdef _DEBUG
void CWkfDrawingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWkfDrawingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWkfDrawingDoc ����
