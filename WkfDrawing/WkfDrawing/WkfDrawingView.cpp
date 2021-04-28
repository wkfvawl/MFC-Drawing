// WkfDrawingView.cpp : CWkfDrawingView 类的实现
//

#include "stdafx.h"
#include "WkfDrawing.h"

#include "WkfDrawingDoc.h"
#include "WkfDrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


GPen GP={0,1,RGB(255,0,0),RGB(255,0,0),0,0,0};//结构体信息初始化

// CWkfDrawingView

IMPLEMENT_DYNCREATE(CWkfDrawingView, CView)

BEGIN_MESSAGE_MAP(CWkfDrawingView, CView)
	// 标准打印命令
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

// CWkfDrawingView 构造/析构

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
	// TODO: 在此处添加构造代码
	a.x=50;
	a.y=50;

}

CWkfDrawingView::~CWkfDrawingView()
{

}

BOOL CWkfDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWkfDrawingView 绘制

void CWkfDrawingView::OnDraw(CDC* pDC)//加载文件重绘函数
{
	int i;
	CWkfDrawingDoc* pDoc = GetDocument();
	pdc=new CClientDC(this);
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GPen g;
	//定义画笔
	POSITION pos = pDoc->Mylist.GetHeadPosition();
	for(i = 0;i<pDoc -> Mylist.GetCount();i++)
	{
		g = pDoc -> Mylist.GetNext(pos);
		CPen p(g.type,g.width,g.pencolor);
		pdc->SelectObject(&p);
		pdc->MoveTo(g.start.x,g.start.y);
	if(g.style==1)//画直线
	{
		pdc->SelectStockObject(NULL_BRUSH);
	   pdc->LineTo(g.end.x,g.end.y);
	}
	if(g.style==2)//画矩形
	{
		pdc->SelectStockObject(NULL_BRUSH);
		pdc->Rectangle(g.start.x,g.start.y,g.end.x,g.end.y);
	}
	if(g.style==3)//画圆形
	{
     
		pdc->SelectStockObject(NULL_BRUSH);
		pdc->Ellipse(g.start.x,g.start.y,g.end.x,g.end.y);
	}
	if(g.style==4)//画填充矩形
	{
		//pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(g.pencolor);
		pdc->SelectObject(&bsh);
		pdc->Rectangle(g.start.x,g.start.y,g.end.x,g.end.y);
		bsh.DeleteObject();
	}
	if(g.style==5)//画填充圆形
	{
		//pdc->SelectObject(&newBrush);
		CBrush bsh;
		bsh.CreateSolidBrush(g.pencolor);
		pdc->SelectObject(&bsh);
		pdc->Ellipse(g.start.x,g.start.y,g.end.x,g.end.y);
		bsh.DeleteObject();
	}
	if(g.style==6)//画圆角矩形
	{
     
		pdc->SelectStockObject(NULL_BRUSH);
		pdc->RoundRect(g.start.x,g.start.y,g.end.x,g.end.y,g.angle.x,g.angle.y);
	}
	if(g.style==7)//画填充圆角矩形
	{
        CBrush bsh;
		bsh.CreateSolidBrush(g.pencolor);
		pdc->SelectObject(&bsh);
		pdc->RoundRect(g.start.x,g.start.y,g.end.x,g.end.y,g.angle.x,g.angle.y);
		bsh.DeleteObject();
	}
	pdc->SelectObject(OldPen);
	}
	// TODO: 在此处为本机数据添加绘制代码
	// TODO: 在此处为本机数据添加绘制代码
	// TODO: 在此处为本机数据添加绘制代码
	
}


// CWkfDrawingView 打印

BOOL CWkfDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWkfDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CWkfDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CWkfDrawingView 诊断

#ifdef _DEBUG
void CWkfDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CWkfDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWkfDrawingDoc* CWkfDrawingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWkfDrawingDoc)));
	return (CWkfDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CWkfDrawingView 消息处理程序

void CWkfDrawingView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	MyDrawStyle = 1;
	pdc=new CClientDC(this);//构造对象
	b=false;
}

void CWkfDrawingView::OnRectangle()//画矩形
{
	MyDrawStyle = 2;
	pdc=new CClientDC(this);//构造对象
	b=false;
}
void CWkfDrawingView::OnCircle()//画空心圆形
{
	MyDrawStyle = 3;
	pdc=new CClientDC(this);//构造对象
	b=false;
}
void CWkfDrawingView::OnTrectangle()
{
	MyDrawStyle = 4;
	pdc=new CClientDC(this);//构造对象
	b=false;
}

void CWkfDrawingView::OnTcircle()
{
	MyDrawStyle = 5;
	pdc=new CClientDC(this);//构造对象
	b=false;
}
void CWkfDrawingView::OnYtrectangle()
{
	MyDrawStyle = 6;
	pdc=new CClientDC(this);//构造对象
	b=false;
}

void CWkfDrawingView::OnTytrectangle()
{
	MyDrawStyle = 7;
	pdc=new CClientDC(this);//构造对象
	b=false;
}

void CWkfDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
		MyStart = MyEnd = point;
		pdc=new CClientDC(this);
	    pdc->SetROP2(R2_NOTXORPEN);
	    b = true;
	    CView::OnLButtonDown(nFlags, point);
}
/*
1 画直线
2 画矩形
3画空心圆形
4.画填充矩形
5.画填充圆形
*/
void CWkfDrawingView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
		// TODO: 在此添加消息处理程序代码和/或调用默认值  
	pdc->SetROP2(R2_COPYPEN);//当前颜色覆盖背景颜色
	pdc->MoveTo(MyStart.x,MyStart.y);
	pdc->LineTo(point.x,point.y);
	g.c = GP.pencolor;
	b=false;//解除绘图关系
	CView::OnLButtonUp(nFlags, point);
	}
	else if(MyDrawStyle==2)
	{
        pdc->SetROP2(R2_COPYPEN);
		pdc->Rectangle(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		g.c = GP.pencolor;
		b=false;//解除绘图关系
	    CView::OnLButtonUp(nFlags, point);
	}
	else if(MyDrawStyle==3)
	{
		pdc->SetROP2(R2_COPYPEN);
		pdc->Ellipse(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y);
		g.c = GP.pencolor;
		b=false;//解除绘图关系
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
		b=false;//解除绘图关系
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
		b=false;//解除绘图关系
        CView::OnLButtonUp(nFlags, point);
	}
   else if(MyDrawStyle==6)
	{

        pdc->SetROP2(R2_COPYPEN);
		pdc->RoundRect(MyStart.x,MyStart.y,MyEnd.x,MyEnd.y,a.x,a.y);
		g.angle=a;
		g.c = GP.pencolor;
		b=false;//解除绘图关系
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
		b=false;//解除绘图关系
	    CView::OnLButtonUp(nFlags, point);
	}
     GetDocument()->Mylist.AddTail(g);//保存信息
	 Invalidate();
}



void CWkfDrawingView::OnPancolor()//画笔颜色设置
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg(0,CC_FULLOPEN);
	if(dlg.DoModal())
	{
		Pcolor = dlg.GetColor();//从颜色对话框中获取颜色信息
		GP.pencolor=Pcolor;
	}
	else if(dlg.DoModal()==IDCANCEL)
	{}
}

void CWkfDrawingView::OnTxt()
{
	// TODO: 在此添加命令处理程序代码
	CTxtlog dlg;
	if(dlg.DoModal()==IDOK){
		int X=dlg.MyX;
	    int Y=dlg.MyY;
		CString String=dlg.MyString;
		pdc=new CClientDC(this);//构造对象
		pdc->SetTextColor(GP.pencolor);//设置文件颜色
		 pdc->SelectObject(&MyFont);
		pdc->TextOut(X,Y,String);
	}
	else if(dlg.DoModal()==IDCANCEL)
	{}
}

void CWkfDrawingView::OnLineW()
{
	// TODO: 在此添加命令处理程序代码
	CLWidth dlg;
    if(dlg.DoModal()==IDOK)
	{
		GP.width=dlg.width;//更新画笔的宽度
		MyWidth=dlg.width;
	}
	else if(dlg.DoModal()==IDCANCEL)
	{}
}
/*
PS_SOLID 实线
PS_DASH 虚线
PS_DOT 点线
PS_DASHDOT 点化线
PS_DASHDOTDOT 双点化线 
*/

void CWkfDrawingView::OnSolid()//线条类型
{
	// TODO: 在此添加命令处理程序代码
	type=PS_SOLID;
	GP.type=type;
	pdc=new CClientDC(this);
}

void CWkfDrawingView::OnDash()
{
	// TODO: 在此添加命令处理程序代码
	type=PS_DASH;
	GP.type=type;
}

void CWkfDrawingView::OnDot()
{
	// TODO: 在此添加命令处理程序代码
	type=PS_DOT;
	GP.type=type;
	
}

void CWkfDrawingView::OnDashdot()
{
	// TODO: 在此添加命令处理程序代码
	type=PS_DASHDOT;
	GP.type=type;

}

void CWkfDrawingView::OnDashdotdot()
{
	// TODO: 在此添加命令处理程序代码
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
