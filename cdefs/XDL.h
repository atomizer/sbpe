enum XDL_WindowEvent {
  XDL_WINDOWEVENT_INVALID = 0x0,
  XDL_WINDOWEVENT_SIZE_CHANGED = 0x1,
  XDL_WINDOWEVENT_RESIZED = 0x2,
  XDL_WINDOWEVENT_FOCUS_LOST = 0x3,
};

// can't declare the actual functions here - they are not linkable at compile time
// declare only corresponding pointer types and argument types/enums
// create callables at runtime by casting symbol pointers to these types

// init
// void XDL_Init();
// void XDL_UnInit();

// window
// void XDL_CreateWindow(const char *title, const char *renderEngine, XDL_FullScreen fullScreen, int width, int height, bool vsync);
// void XDL_SetWindowSize(XDL_FullScreen fullScreen, int width, int height);
// void XDL_SetVsync(bool vsync);
typedef void (*pXDL_GetWindowSize)(int *width, int *height);

// drawing
typedef uint32_t XDL_Color;
typedef int32_t XDL_Flip;
typedef void (*pXDL_Clear)(XDL_Color color);
typedef void (*pXDL_Present)();
typedef void (*pXDL_DrawPoint)(int x, int y, XDL_Color color, enum BlendMode blendMode);
typedef void (*pXDL_DrawLine)(int x0, int y0, int x1, int y1, XDL_Color color, enum BlendMode blendMode);
typedef void (*pXDL_DrawRect)(int x, int y, int w, int h, XDL_Color color, enum BlendMode blendMode);
typedef void (*pXDL_FillRect)(int x, int y, int w, int h, XDL_Color color, enum BlendMode blendMode);
typedef void (*pXDL_DrawTri)(int x0, int y0, int x1, int y1, int x2, int y2, XDL_Color color, enum BlendMode blendMode);
typedef void (*pXDL_FillTri)(int x0, int y0, int x1, int y1, int x2, int y2, XDL_Color color, enum BlendMode blendMode);

// drawing2 - textures, text, numbers
typedef void (*XDL_LoadTextureDoneCallback)(unsigned int, void *);
typedef void (*XDL_LoadTextDoneCallback)(const char *, int, void *);
typedef void (*pXDL_LoadTextFile)(const char *textFilename, XDL_LoadTextDoneCallback callback, void *userData);
typedef void (*pXDL_LoadTextureFile)(const char *textureFilename, XDL_LoadTextureDoneCallback callback, void *userData);
typedef unsigned int (*pXDL_CreateTextTexture)(unsigned int oldTexture, const char *fontName, int size, XDL_Color color, const char *text, int outlineSize, XDL_Color outlineColor);
typedef int (*pXDL_CalculateTextWidth)(const char *fontName, int size, XDL_Color color, const char *text, int outlineSize);
typedef int (*pXDL_LineSpacing)(const char *fontName, int size, int outlineSize);
typedef void (*pXDL_QueryTexture)(unsigned int texture, int *width, int *height);
typedef void (*pXDL_DrawTexture)(unsigned int texture, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, int rotDegt, int rpx, int rpy, XDL_Flip flip, XDL_Color colorMod, enum BlendMode blendMode);
typedef unsigned int (*pXDL_GetNumberDict)(const char *fontName, int size, XDL_Color color, int outlineSize, XDL_Color outlineColor);
typedef void (*pXDL_DrawFromNumberDict)(unsigned int texture, int value, int sw, int sh, int dx, int dy, int dw, int dh);
typedef void (*pXDL_SizeFromNumberDict)(unsigned int texture, int value, int *width, int *height);
typedef void (*pXDL_DestroyTexture)(unsigned int texture);

// sound
// void XDL_SetSoundPrefix(const char *sfxPrefix);
// void XDL_SetSoundMixerChannels(int numChannels);
// void XDL_PlayMusic(const char *trackName);
// void XDL_LoadSound(const char *soundName);
// void XDL_LoadSounds(const char *soundPrefix);
// bool XDL_PlaySound(const char *soundName, int channel, double x, double y);
// void XDL_UnloadSounds(const char *soundPrefix);
// int XDL_VolumeSound(int volume);


// events
// typedef void (*XDL_KeyboardCallback)(int, XDL_Keycode, void *);
// typedef void (*XDL_MouseMoveCallback)(int, int, void *);
// typedef void (*XDL_MouseButtonCallback)(int, int, int, int, void *);
// typedef void (*XDL_TextInputCallback)(const char *, void *);
// typedef void (*XDL_WindowEventCallback)(XDL_WindowEvent, void *);
// typedef void (*XDL_GamepadCallback)(SDL_JoystickID, const char *, bool, void *);
// typedef void (*XDL_FinalizePurchaseCallback)(int, const char *);
// typedef void (*XDL_QuitCallback)(void *);
// void XDL_SetKeyboardCallback(XDL_KeyboardCallback callback);
// void XDL_SetMouseMoveCallback(XDL_MouseMoveCallback callback);
// void XDL_SetMouseButtonCallback(XDL_MouseButtonCallback callback);
// void XDL_SetTextInputCallback(XDL_TextInputCallback callback);
// void XDL_SetWindowEventCallback(XDL_WindowEventCallback callback);
// void XDL_SetGamepadCallback(XDL_GamepadCallback callback);
// void XDL_SetFinalizePurchaseCallback(XDL_FinalizePurchaseCallback callback);
// void XDL_SetQuitCallback(XDL_QuitCallback callback);
typedef void (*pXDL_DoEvents)();

// misc
// void XDL_SetMouseCursor(XDL_MouseCursor mouseCursor);
// void XDL_SetUserData(void *userData);
// char *XDL_LoadLocalData(const char *key, int *len);
// void XDL_SaveLocalData(const char *key, const char *data, int len);
// void XDL_OpenURL(const char *url, bool newWindow);
// void XDL_InitPurchase(int price, const char *description, const char *email, int purchaseId, bool isProd);
// int XDL_GetNumDraws();
// bool XDL_IsFullScreen();
// char *XDL_GetRenderEngine();
// char *XDL_GetWarnings();
// char *XDL_GetBrowser();
// char *XDL_GetPlatform();
// char *XDL_GetDebugInfo();
typedef void (*pXDL_TrackGAEvent)(const char *category, const char *action, const char *label, double value);

// callbacks
typedef void (*pmouseMoveCallback)(int x, int y, void *userData);
typedef void (*pmouseButtonCallback)(int x, int y, int button, int down, void *userData);
typedef void (*pwindowEventCallback)(enum XDL_WindowEvent event, void *userData);
