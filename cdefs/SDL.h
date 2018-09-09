// keyboard

void *SDL_GetKeyboardFocus(void);
bool SDL_IsTextInputActive(void);
const uint8_t *SDL_GetKeyboardState(int *numkeys);

const char *SDL_GetScancodeName(enum SDL_Scancode scancode);
int SDL_GetScancodeFromName(const char *name);

int SDL_GetModState(void);

enum SDL_Keymod {
  KMOD_NONE = 0x0,
  KMOD_LSHIFT = 0x1,
  KMOD_RSHIFT = 0x2,
  KMOD_LCTRL = 0x40,
  KMOD_RCTRL = 0x80,
  KMOD_LALT = 0x100,
  KMOD_RALT = 0x200,
  KMOD_LGUI = 0x400,
  KMOD_RGUI = 0x800,
  KMOD_NUM = 0x1000,
  KMOD_CAPS = 0x2000,
  KMOD_MODE = 0x4000,
  KMOD_RESERVED = 0x8000,
};

// window

void SDL_GetWindowSize(void *window, int *w, int *h);

// GL

void *SDL_GL_GetProcAddress(const char *proc);

int SDL_GL_SetAttribute(int attr, int value);
int SDL_GL_GetAttribute(int attr, int *value);

typedef unsigned int  GLenum;
typedef unsigned char GLboolean;
typedef unsigned int  GLbitfield;
typedef void    GLvoid;
typedef signed char GLbyte;   /* 1-byte signed */
typedef short   GLshort;  /* 2-byte signed */
typedef int   GLint;    /* 4-byte signed */
typedef unsigned char GLubyte;  /* 1-byte unsigned */
typedef unsigned short  GLushort; /* 2-byte unsigned */
typedef unsigned int  GLuint;   /* 4-byte unsigned */
typedef int   GLsizei;  /* 4-byte signed */
typedef float   GLfloat;  /* single precision float */
typedef float   GLclampf; /* single precision float in [0,1] */
typedef double    GLdouble; /* double precision float */
typedef double    GLclampd; /* double precision float in [0,1] */

typedef GLenum (*pglGetError)(void);
typedef void (*pglEnable)(GLenum cap);
typedef void (*pglDisable)(GLenum cap);
typedef void (*pglHint)(GLenum target, GLenum mode);
typedef void (*pglTexImage2D)(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * data);
typedef void (*pglTexParameteri)(GLenum target, GLenum pname, GLint param);

// typedef void (*pglBindRenderbuffer)(GLenum target, GLuint renderbuffer);
// typedef void (*pglDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
// typedef void (*pglGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
// typedef void (*pglRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
// typedef void (*pglBindFramebuffer)(GLenum target, GLuint framebuffer);
// typedef void (*pglDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
// typedef void (*pglGenFramebuffers)(GLsizei n, GLuint *framebuffers);
// typedef GLenum (*pglCheckFramebufferStatus)(GLenum target);
// typedef void (*pglFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
// typedef void (*pglBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

// misc

int SDL_ShowCursor(int toggle);
