
// MFCSingleViewOpenGLView.h : interface of the CMFCSingleViewOpenGLView class
//

#pragma once

#include <gl/GL.h>
#include <gl/GLU.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

class CMFCSingleViewOpenGLView : public CView
{
protected: // create from serialization only
	CMFCSingleViewOpenGLView();
	DECLARE_DYNCREATE(CMFCSingleViewOpenGLView)

// Attributes
public:
	CMFCSingleViewOpenGLDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCSingleViewOpenGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg BOOL OnEraseBkgnd(CDC* pDC);
  afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in MFCSingleViewOpenGLView.cpp
inline CMFCSingleViewOpenGLDoc* CMFCSingleViewOpenGLView::GetDocument() const
   { return reinterpret_cast<CMFCSingleViewOpenGLDoc*>(m_pDocument); }
#endif

