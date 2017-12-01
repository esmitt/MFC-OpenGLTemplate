
// MFCSingleViewOpenGLView.cpp : implementation of the CMFCSingleViewOpenGLView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSingleViewOpenGL.h"
#endif

#include "MFCSingleViewOpenGLDoc.h"
#include "MFCSingleViewOpenGLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSingleViewOpenGLView

IMPLEMENT_DYNCREATE(CMFCSingleViewOpenGLView, CView)

BEGIN_MESSAGE_MAP(CMFCSingleViewOpenGLView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
  ON_WM_CREATE()
  ON_WM_ERASEBKGND()
  ON_WM_SIZE()
END_MESSAGE_MAP()

// CMFCSingleViewOpenGLView construction/destruction

CMFCSingleViewOpenGLView::CMFCSingleViewOpenGLView()
{
	// TODO: add construction code here

}

CMFCSingleViewOpenGLView::~CMFCSingleViewOpenGLView()
{
}

BOOL CMFCSingleViewOpenGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCSingleViewOpenGLView drawing

void CMFCSingleViewOpenGLView::OnDraw(CDC* pDC)
{
	CMFCSingleViewOpenGLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  glClearColor(0.15f, 0.15f, 0.15f, 1.f);
  glLoadIdentity();
  glBegin(GL_TRIANGLES);
    glColor3f(1.f, 1.f, 0.2f);
    glVertex3f(-0.5f, -0.5f, -1.0f);
    glColor3f(1.f, 0.2f, 1.0f);
    glVertex3f(+0.5f, -0.5f, -1.0f);
    glColor3f(0.2f, 0.2f, 1.0f);
    glVertex3f(0.0f, 0.0f, -1.2f);
  glEnd();
  SwapBuffers(pDC->m_hDC);
}

void CMFCSingleViewOpenGLView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCSingleViewOpenGLView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCSingleViewOpenGLView diagnostics

#ifdef _DEBUG
void CMFCSingleViewOpenGLView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSingleViewOpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSingleViewOpenGLDoc* CMFCSingleViewOpenGLView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSingleViewOpenGLDoc)));
	return (CMFCSingleViewOpenGLDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSingleViewOpenGLView message handlers


int CMFCSingleViewOpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  if (CView::OnCreate(lpCreateStruct) == -1)
    return -1;

  // TODO:  Add your specialized creation code here
  CClientDC dc(this);

  PIXELFORMATDESCRIPTOR pfd;
  memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
  pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
  pfd.nVersion = 1;
  pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
  pfd.iPixelType = PFD_TYPE_RGBA;
  pfd.cColorBits = 32;
  pfd.cDepthBits = 32;
  pfd.iLayerType = PFD_MAIN_PLANE;

  int nPixelFormat = ChoosePixelFormat(dc.m_hDC, &pfd);

  if (nPixelFormat == 0) return false;

  BOOL bResult = SetPixelFormat(dc.m_hDC, nPixelFormat, &pfd);
  
  if (!bResult) return false;

  HGLRC tempContext = wglCreateContext(dc.m_hDC);
  wglMakeCurrent(dc.m_hDC, tempContext);

  //opengl init
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.15f, 0.15f, 0.15f, 1.f);
  return 0;
}


BOOL CMFCSingleViewOpenGLView::OnEraseBkgnd(CDC* pDC)
{
  // TODO: Add your message handler code here and/or call default

  return TRUE;
}


void CMFCSingleViewOpenGLView::OnSize(UINT nType, int cx, int cy)
{
  CView::OnSize(nType, cx, cy);

  // TODO: Add your message handler code here
  float ratio = cx / float(cy);
  glViewport(0, 0, cx, cy);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, ratio, 1, 10); //near 1, far 10, fov 70

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
