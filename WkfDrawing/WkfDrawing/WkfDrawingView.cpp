// WkfDrawingView.cpp : CWkfDrawingView ���ʵ��
//

#include "stdafx.h"
#include "WkfDrawing.h"

#include "WkfDrawingDoc.h"
#include "WkfDrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


GPen GP={0,1,RGB(255,0,0),RGB(255,0,0),0,0,0};//�ṹ����Ϣ��ʼ��

// CWkfDrawingView

IMPLEMENT_DYNCREATE(CWkfDrawingView, CView)

BEGIN_MESSAGE_MAP(CWkfDrawingView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_LINE, &CWkfDrawingView::OnLine)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_RECTANGLE, &CWkfDrawingView::OnRectangle)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_CIRCLE, &CWkfDrawingView::OnCircle)
	ON_COMMAND(ID_PANCOLOR, &CWkfDrawingView::OnPancolor)
	ON_COMMAND(ID_TXT, &CWkfDrawingView::OnTxt)
	ON_COMMAND(ID_Line_W, &CWkfDrawingView::OnLineW)
	ON_COMMAND(ID_TRECTANGLE, &CWkfDrawingView::OnTrectangle)
	ON_COMMAND(ID_TCIRCLE, &CWkfDrawingView::OnTcircle)
	ON_COMMAND(ID_SOLID, &CWkfDrawingView::OnSolid)
	ON_COMMAND(ID_DASH, &CWkfDrawingView::OnDash)
	ON_COMMAND(ID_DOT, &CWkfDrawingView::OnDot)
	ON_COMMAND(ID_DASHDOT, &CWkfDrawingView::OnDashdot)
	ON_COMMAND(ID_DASHDOTDOT, &CWkfDrawingView::OnDashdotdot)
	ON_COMMAND(ID_YTRECTANGLE, &CWkfDrawingView::OnYtrectangle)
	ON_COMMAND(ID_TYTRECTANGLE, &CWkfDrawingView::OnTytrectangle)
	ON_COMMAND(ID_FONT, &CWkfDrawingView::OnFont)
END_MESSAGE_MAP()

// CWkfDrawingView ����/����

CWkfDrawingView::CWkfDrawingView()
: my_point(0)
, MyDrawStyle(-1)
, MyStart(0)
, MyEnd(0)
, b(false)
, pdc(NULL)
, type(0)
, MyWidth(0)
, OldPen(NULL)
, a(0)
, MyFontName(_T(""))
{
	// TODO: �ڴ˴���ӹ������
	a.x=50;
	a.y=50;

}

CWkfDrawingView::~CWkfDrawingView()
{

}

BOOL CWkfDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CWkfDrawingView ����

void CWkfDrawingView::OnDraw(CDC* pDC)//�����ļ��ػ溯��
{
	int i;
	CWkfDrawingDoc* pDoc = GetDocument();
	pdc=new CClientDC(this);
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GPen g;
	//���廭��
	POSITION pos = pDoc->Mylist.GetHeadPosition();
	for(i = 0;i<pDoc -> Mylist.GetCount();i++)
	{
		g = pDoc -> Mylist.GetNext(pos);
		CPen p(g.type,g.width,g.pencolor);
		pdc->SelectObject(&p);
		pdc->MoveTo(g.start.x,g.start.y);
	if(g.style==1)//��ֱ��
	{
		pdc->SelectStockObject(NULL_BRUSH);
	   pdc->LineTo(g.end.x,g.end.y);
	}
	if(g.style==2)//������
	{
		pdc->SelectStockObject(NULL_BRUSH);
		pdc->Rectangle(g.start.x,g.start.y,g.end.x,g.end.y);
	}
	if(g.style==3)//��Բ��
	{
     
		pdc->SelectStockObject(NULL_BRUSH);
		pdc->Ellipse(g.start.x,g.start.y,g.end.x,g.end.y);
	}
	if(g.style==4)//��������
	{
		//pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(g.pencolor);
		pdc->SelectObject(&bsh);
		pdc->Rectangle(g.start.x,g.start.y,g.end.x,g.end.y);
		bsh.DeleteObject();
	}
	if(g.style==5)//�����Բ��
	{
		//pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(g.pencolor);
		pdc->SelectObject(&bsh);
		pdc->Ellipse(g.start.x,g.start.y,g.end.x,g.end.y);
		bsh.DeleteObject();
	}
	if(g.style==6)//��Բ�Ǿ���
	{
     
		pdc->SelectStockObject(NULL_BRUSH);
		pdc->RoundRect(g.start.x,g.start.y,g.end.x,g.end.y,g.angle.x,g.angle.y);
	}
	if(g.style==7)//�����Բ�Ǿ���
	{
        CBrush bsh;
		bsh.CreateSolidBrush(g.pencolor);
		pdc->SelectObject(&bsh);
		pdc->RoundRect(g.start.x,g.start.y,g.end.x,g.end.y,g.angle.x,g.angle.y);
		bsh.DeleteObject();
	}
	pdc->SelectObject(OldPen);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// CWkfDrawingView ��ӡ

BOOL CWkfDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CWkfDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CWkfDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CWkfDrawingView ���

#ifdef _DEBUG
void CWkfDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CWkfDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWkfDrawingDoc* CWkfDrawingView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWkfDrawingDoc)));
	return (CWkfDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CWkfDrawingView ��Ϣ�������

void CWkfDrawingView::OnLine()
{
	// TODO: �ڴ���������������
	MyDrawStyle = 1;
	pdc=new CClientDC(this);//�������
	b=false;
}

void CWkfDrawingView::OnRectangle()//������
{
	MyDrawStyle = 2;
	pdc=new CClientDC(this);//�������
	b=false;
}
void CWkfDrawingView::OnCircle()//������Բ��
{
	MyDrawStyle = 3;
	pdc=new CClientDC(this);//�������
	b=false;
}
void CWkfDrawingView::OnTrectangle()
{
	MyDrawStyle = 4;
	pdc=new CClientDC(this);//�������
	b=false;
}

void CWkfDrawingView::OnTcircle()
{
	MyDrawStyle = 5;
	pdc=new CClientDC(this);//�������
	b=false;
}
void CWkfDrawingView::OnYtrectangle()
{
	MyDrawStyle = 6;
	pdc=new CClientDC(this);//�������
	b=false;
}

void CWkfDrawingView::OnTytrectangle()
{
	MyDrawStyle = 7;
	pdc=new CClientDC(this);//�������
	b=false;
}

void CWkfDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
		MyStart = MyEnd = point;
		pdc=new CClientDC(this);
	    pdc->SetROP2(R2_NOTXORPEN);
	    b = true;
	    CView::OnLButtonDown(nFlags, point);
}
/*
1 ��ֱ��
2 ������
3������Բ��
4.��������
5.�����Բ��
*/
void CWkfDrawingView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*pdc->MoveTo(MyStart.x,MyStart.y);
	pdc->LineTo(MyEnd.x,MyEnd.y);*/
	if(!b)
    return ;
	CPen pen(GP.type, GP.width, GP.pencolor); 
    OldPen=pdc->SelectObject(&pen);
	if(MyDrawStyle==1)
	{
	pdc->SelectStockObject(NULL_BRUSH);
	pdc->MoveTo(MyStart.x,MyStart.y);
	pdc->LineTo(MyEnd.x,MyEnd.y);
	MyEnd=point;
	pdc->MoveTo(MyStart.x,MyStart.y);
	pdc->LineTo(MyEnd.x,MyEnd.y);
	}
	else if(MyDrawStyle==2)
	{
		pdc->SelectStockObject(NULL_BRUSH);
		pdc->Rectangle(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		MyEnd = point;
		pdc->Rectangle(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
	}
	else if(MyDrawStyle==3)
	{
        pdc->SelectStockObject(NULL_BRUSH);
		pdc->Ellipse(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		MyEnd = point;
		pdc->Ellipse(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
	}
	else if(MyDrawStyle==4)
	{
		//pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(GP.pencolor);
		pdc->SelectObject(&bsh);
		pdc->Rectangle(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		MyEnd = point;
		pdc->Rectangle(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		bsh.DeleteObject();
	}
	else if(MyDrawStyle==5)
	{
		//pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(GP.pencolor);
		pdc->SelectObject(&bsh);
		pdc->Ellipse(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		MyEnd = point;
		pdc->Ellipse(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		bsh.DeleteObject();
	}
	else if(MyDrawStyle==6)
	{
		pdc->SelectStockObject(NULL_BRUSH);
		pdc->RoundRect(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y,a.x,a.y);
		MyEnd = point;
		pdc->RoundRect(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y,a.x,a.y);
	}
    else if(MyDrawStyle==7)
	{
		CBrush bsh;
		bsh.CreateSolidBrush(GP.pencolor);
		pdc->SelectObject(&bsh);
		pdc->RoundRect(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y,a.x,a.y);
		MyEnd = point;
		pdc->RoundRect(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y,a.x,a.y);
		bsh.DeleteObject();
	}
	CView::OnMouseMove(nFlags, point);
}
void CWkfDrawingView::OnLButtonUp(UINT nFlags, CPoint point)
{

	GPen g;
	g.start = MyStart;
	g.end = MyEnd;
	g.width = MyWidth;
	g.type = type;
	g.style = MyDrawStyle;
	g.pencolor = GP.pencolor;
	if(MyDrawStyle==1)
	{
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ  
	pdc->SetROP2(R2_COPYPEN);//��ǰ��ɫ���Ǳ�����ɫ
	pdc->MoveTo(MyStart.x,MyStart.y);
	pdc->LineTo(point.x,point.y);
	g.c = GP.pencolor;
	b=false;//�����ͼ��ϵ
	CView::OnLButtonUp(nFlags, point);
	}
	else if(MyDrawStyle==2)
	{
        pdc->SetROP2(R2_COPYPEN);
		pdc->Rectangle(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		g.c = GP.pencolor;
		b=false;//�����ͼ��ϵ
	    CView::OnLButtonUp(nFlags, point);
	}
	else if(MyDrawStyle==3)
	{
		pdc->SetROP2(R2_COPYPEN);
		pdc->Ellipse(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		g.c = GP.pencolor;
		b=false;//�����ͼ��ϵ
	    CView::OnLButtonUp(nFlags, point);
	}
   else if(MyDrawStyle==4)
	{

        //pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(GP.pencolor);
		pdc->SetROP2(R2_COPYPEN);
		pdc->SelectObject(&bsh);
		pdc->Rectangle(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		g.c =GP.pencolor;
		b=false;//�����ͼ��ϵ
        CView::OnLButtonUp(nFlags, point);
	}
	else if(MyDrawStyle==5)
	{

        //pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(GP.pencolor);
		pdc->SetROP2(R2_COPYPEN);
		pdc->SelectObject(&bsh);
		pdc->Ellipse(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		g.c =GP.pencolor;
		b=false;//�����ͼ��ϵ
        CView::OnLButtonUp(nFlags, point);
	}
   else if(MyDrawStyle==6)
	{

        pdc->SetROP2(R2_COPYPEN);
		pdc->RoundRect(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y,a.x,a.y);
		g.angle=a;
		g.c = GP.pencolor;
		b=false;//�����ͼ��ϵ
	    CView::OnLButtonUp(nFlags, point);
	}
   else if(MyDrawStyle==7)
	{

        //pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(GP.pencolor);
		pdc->SetROP2(R2_COPYPEN);
		pdc->SelectObject(&bsh);
		pdc->RoundRect(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y,a.x,a.y);
		g.angle=a;
		g.c = GP.pencolor;
		b=false;//�����ͼ��ϵ
	    CView::OnLButtonUp(nFlags, point);
	}
     GetDocument()->Mylist.AddTail(g);//������Ϣ
	 Invalidate();
}



void CWkfDrawingView::OnPancolor()//������ɫ����
{
	// TODO: �ڴ���������������
	CColorDialog dlg(0,CC_FULLOPEN);
	if(dlg.DoModal())
	{
		Pcolor = dlg.GetColor();//����ɫ�Ի����л�ȡ��ɫ��Ϣ
		GP.pencolor=Pcolor;
	}
	else if(dlg.DoModal()==IDCANCEL)
	{}
}

void CWkfDrawingView::OnTxt()
{
	// TODO: �ڴ���������������
	CTxtlog dlg;
	if(dlg.DoModal()==IDOK){
		int X=dlg.MyX;
	    int Y=dlg.MyY;
		CString String=dlg.MyString;
		pdc=new CClientDC(this);//�������
		pdc->SetTextColor(GP.pencolor);//�����ļ���ɫ
		 pdc->SelectObject(&MyFont);
		pdc->TextOut(X,Y,String);
	}
	else if(dlg.DoModal()==IDCANCEL)
	{}
}

void CWkfDrawingView::OnLineW()
{
	// TODO: �ڴ���������������
	CLWidth dlg;
    if(dlg.DoModal()==IDOK)
	{
		GP.width=dlg.width;//���»��ʵĿ��
		MyWidth=dlg.width;
	}
	else if(dlg.DoModal()==IDCANCEL)
	{}
}
/*
PS_SOLID ʵ��
PS_DASH ����
PS_DOT ����
PS_DASHDOT �㻯��
PS_DASHDOTDOT ˫�㻯�� 
*/

void CWkfDrawingView::OnSolid()//��������
{
	// TODO: �ڴ���������������
	type=PS_SOLID;
	GP.type=type;
	pdc=new CClientDC(this);
}

void CWkfDrawingView::OnDash()
{
	// TODO: �ڴ���������������
	type=PS_DASH;
	GP.type=type;
}

void CWkfDrawingView::OnDot()
{
	// TODO: �ڴ���������������
	type=PS_DOT;
	GP.type=type;
	
}

void CWkfDrawingView::OnDashdot()
{
	// TODO: �ڴ���������������
	type=PS_DASHDOT;
	GP.type=type;

}

void CWkfDrawingView::OnDashdotdot()
{
	// TODO: �ڴ���������������
	type=PS_DASHDOTDOT;
	GP.type=type;
}




void CWkfDrawingView::OnFont()
{
	 CFontDialog dlg;
     if(IDOK==dlg.DoModal())
     {
            if(MyFont.m_hObject)
              MyFont.DeleteObject();
                MyFont.CreateFontIndirect(dlg.m_cf.lpLogFont);
                MyFontName=dlg.m_cf.lpLogFont->lfFaceName;
               //Invalidate();

        }
}
