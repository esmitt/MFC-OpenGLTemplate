
// MFCSingleViewOpenGLDoc.cpp : implementation of the CMFCSingleViewOpenGLDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSingleViewOpenGL.h"
#endif

#include "MFCSingleViewOpenGLDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCSingleViewOpenGLDoc

IMPLEMENT_DYNCREATE(CMFCSingleViewOpenGLDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCSingleViewOpenGLDoc, CDocument)
END_MESSAGE_MAP()


// CMFCSingleViewOpenGLDoc construction/destruction

CMFCSingleViewOpenGLDoc::CMFCSingleViewOpenGLDoc()
{
	// TODO: add one-time construction code here

}

CMFCSingleViewOpenGLDoc::~CMFCSingleViewOpenGLDoc()
{
}

BOOL CMFCSingleViewOpenGLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCSingleViewOpenGLDoc serialization

void CMFCSingleViewOpenGLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCSingleViewOpenGLDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCSingleViewOpenGLDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCSingleViewOpenGLDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCSingleViewOpenGLDoc diagnostics

#ifdef _DEBUG
void CMFCSingleViewOpenGLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCSingleViewOpenGLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCSingleViewOpenGLDoc commands
