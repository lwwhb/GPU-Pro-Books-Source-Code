// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: VertShader.vsh ********

// File data
static const char _VertShader_vsh[] = 
	"attribute highp vec4  inVertex;\r\n"
	"attribute highp vec2  inTexCoord;\r\n"
	"\r\n"
	"uniform highp mat4  MVPMatrix;\r\n"
	"\r\n"
	"varying mediump vec2  TexCoord;\r\n"
	"\r\n"
	"void main()\r\n"
	"{\r\n"
	"\tgl_Position = MVPMatrix * inVertex;\r\n"
	"\tTexCoord = inTexCoord;\r\n"
	"}\r\n";

// Register VertShader.vsh in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_VertShader_vsh("VertShader.vsh", _VertShader_vsh, 221);

// ******** End: VertShader.vsh ********

// This file was created by Filewrap 1.1
// Little endian mode
// DO NOT EDIT

#include "../PVRTMemoryFileSystem.h"

// using 32 bit to guarantee alignment.
#ifndef A32BIT
 #define A32BIT static const unsigned int
#endif

// ******** Start: VertShader.vsc ********

// File data
A32BIT _VertShader_vsc[] = {
0x10fab438,0x16fd9e8d,0x30050100,0x2101,0xa9142cc2,0x0,0x0,0x7c020000,0x0,0x4000000,0x0,0x9000000,0x10002,0x0,0x20100,0x0,0x1,0x88010000,0x55535020,0x17,0x17c,0x1,0x0,0x80c,0x0,0x2,0x79,0x0,0x8,0x0,0xffffffff,0x0,0x76000a,0xffff,0x6,0x0,0x100000,0x0,0x0,0x0,0x0,0xfffc0000,0x0,0x0,0x0,0x20000,0xffffffff,0x100000,0x10006,0x0,0x10000,0x10001,0x10000,0x20002,0x10000,0x30003,0x10000,0x40004,0x10000,0x50005,0x10000,0x60006,0x10000,0x70007,
0x10000,0x80008,0x10000,0x90009,0x10000,0xa000a,0x10000,0xb000b,0x10000,0xc000c,0x10000,0xd000d,0x10000,0xe000e,0x10000,0xf000f,0x3f0000,0x40000,0x20000,0x2,0x1,0x80018001,0x80018001,0x0,0x0,0x2000000,0x1001a080,0x228a1,0x70000,0x80000000,0x80048001,0x8004,0x0,0x40000,0x10000,0x10001,0x10001,0x10404,0xfa100000,0xf000050b,0x10a83205,0xf020060d,0x38980605,0xf0004811,0x38820606,0xf0008a15,0x38820606,0xf040cc19,0x38a20205,0xe0600080,0x28831001,0x6,0x1000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x5000000,0x505f6c67,0x7469736f,0x6e6f69,0x5050100,0x10000,0x100,0xf0004,0x50564d00,0x7274614d,0x7869,0x31600,0x100,0x10000001,0xffff,0x65566e69,0x78657472,0x5000000,0x1000004,0x10000,0xf000400,0x65540000,0x6f6f4378,0x6472,0x50300,0x100,0x2000001,0x300,0x65546e69,0x6f6f4378,0x6472,0x40300,0x100,0x4040001,0x300,0x0,
};

// Register VertShader.vsc in memory file system at application startup time
static CPVRTMemoryFileSystem RegisterFile_VertShader_vsc("VertShader.vsc", _VertShader_vsc, 668);

// ******** End: VertShader.vsc ********

