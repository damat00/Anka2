#include "StdAfx.h"
#include "GrpVertexBufferStatic.h"

bool CStaticVertexBuffer::Create(int vtxCount, DWORD fvf, bool /*isManaged*/)
{
#ifdef ENABLE_DIRECTX9EX_UPDATE
	return CGraphicVertexBuffer::Create(vtxCount, fvf, D3DUSAGE_WRITEONLY, D3DPOOL_DEFAULT);
#else
	return CGraphicVertexBuffer::Create(vtxCount, fvf, D3DUSAGE_WRITEONLY, D3DPOOL_MANAGED_EX_FIX);
#endif
}

CStaticVertexBuffer::CStaticVertexBuffer()
{
}

CStaticVertexBuffer::~CStaticVertexBuffer()
{
}
