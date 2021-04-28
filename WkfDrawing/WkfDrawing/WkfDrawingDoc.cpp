// WkfDrawingDoc.cpp : CWkfDrawingDoc 类的实现
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


// CWkfDrawingDoc 构造/析构

CWkfDrawingDoc::CWkfDrawingDoc()
{
	// TODO: 在此添加一次性构造代码

}

CWkfDrawingDoc::~CWkfDrawingDoc()
{
}

BOOL CWkfDrawingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CWkfDrawingDoc 序列化

void CWkfDrawingDoc::Serialize(CArchive& ar)
{
	int i;
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
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
		// TODO: 在此添加加载代码
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


// CWkfDrawingDoc 诊断

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


// CWkfDrawingDoc 命令
