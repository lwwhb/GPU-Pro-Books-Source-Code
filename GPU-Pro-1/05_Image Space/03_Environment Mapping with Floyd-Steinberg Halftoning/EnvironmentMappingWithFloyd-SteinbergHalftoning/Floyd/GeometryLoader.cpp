#include "DXUT.h"
#include "GeometryLoader.h"

GeometryLoader::GeometryLoader(void)
{
}

GeometryLoader::~GeometryLoader(void)
{
}

HRESULT GeometryLoader::LoadMeshFromFile(const wchar_t* dgbFileName, ID3D10Device* device, ID3DX10Mesh** mesh)
{
    // Open the file
    HANDLE file = CreateFile(dgbFileName, FILE_READ_DATA, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if( INVALID_HANDLE_VALUE == file )
        return DXUTERR_MEDIANOTFOUND;

    // Get the file size
    LARGE_INTEGER fileSize;
    GetFileSizeEx( file, &fileSize );
    UINT cBytes = fileSize.LowPart;

    // Allocate memory
    BYTE* meshData = new BYTE[ cBytes ];
    if( !meshData )
    {
        CloseHandle( file );
        return E_OUTOFMEMORY;
    }

    // Read in the file
	HRESULT hr = S_OK;
    DWORD dwBytesRead;
    if( !ReadFile( file, meshData, cBytes, &dwBytesRead, NULL ) )
        hr = E_FAIL;

    CloseHandle( file );

	if( SUCCEEDED(hr) )
    {
        hr = CreateMeshFromMemory(  device,
                                meshData,
                                cBytes,
								mesh);
        if( FAILED(hr) )
            delete [] meshData;
    }
	delete [] meshData;
    return hr;
}

HRESULT GeometryLoader::CreateMeshFromMemory(ID3D10Device* device, BYTE* data, unsigned int nBytes, ID3DX10Mesh** mesh)
{
	D3D10_INPUT_ELEMENT_DESC elements[20];
	
	BYTE* p = data;

	unsigned int nElements = 0;
	while(*p)
	{
		CopyMemory((void*)&elements[nElements], (void*)p, sizeof(D3D10_INPUT_ELEMENT_DESC));
		p += sizeof(D3D10_INPUT_ELEMENT_DESC);
		unsigned int semanticNameLength = strlen( (char*)p) + 1;
		char* semanticName = new char[semanticNameLength];
		strcpy(semanticName, (char*)p);
		p += semanticNameLength;
		elements[nElements].SemanticName = semanticName;
		nElements++;
	}
	p++;

	unsigned int nVertices = *(unsigned int*)p;
	p += sizeof(unsigned int);
	unsigned int nFaces = *(unsigned int*)p;
	p += sizeof(unsigned int);

	bool wideIndexBuffer = false;
	if(nFaces * 3 >= 0xffff)
		wideIndexBuffer = true;

	D3DX10CreateMesh(device, elements, nElements, elements[0].SemanticName, nVertices, nFaces, 
		wideIndexBuffer?D3DX10_MESH_32_BIT:0, mesh);

	for(unsigned int i=0; i<nElements; i++)
		delete [] elements[i].SemanticName;

	ID3DX10MeshBuffer* vertexBuffer;
	(*mesh)->GetVertexBuffer(0, &vertexBuffer);
/*	void* vbData;
	unsigned int vertexBufferByteSize;
	vertexBuffer->Map(&vbData, (SIZE_T*)&vertexBufferByteSize);
	CopyMemory((void*) vbData, (void*) p, vertexBufferByteSize);
	vertexBuffer->Unmap();*/
	unsigned int vertexBufferByteSize = vertexBuffer->GetSize();
	vertexBuffer->Release();

	(*mesh)->SetVertexData(0, p);
	p += vertexBufferByteSize ;


/*	ID3DX10MeshBuffer* indexBuffer;
	(*mesh)->GetIndexBuffer(&indexBuffer);
	void* ibData;
	unsigned int indexBufferByteSize;
	indexBuffer->Map(&ibData, (SIZE_T*)&indexBufferByteSize);
	CopyMemory((void*) ibData, (void*) p, indexBufferByteSize);
	indexBuffer->Unmap();
	indexBuffer->Release();*/
	unsigned int indexBufferByteSize = nFaces * 3 * sizeof(unsigned short);
	if(wideIndexBuffer)
		indexBufferByteSize = nFaces * 3 * sizeof(unsigned int);
	(*mesh)->SetIndexData(p, nFaces * 3);
	p += indexBufferByteSize;

	(*mesh)->CommitToDevice();
	return S_OK;
}