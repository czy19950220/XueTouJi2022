#ifndef CGAMMARAMP_H
#define CGAMMARAMP_H
/*
CGammaRamp class

Encapsulates the Gamma Ramp API and changes the brightness of
the entire screen.

Written by Nir Sofer.
http://www.nirsoft.net

*/
#include <QObject>
#include  <windows.h>

class CGammaRamp
{
public:
    CGammaRamp();
protected :
    HMODULE hGDI32;
    HDC hScreenDC;
    typedef  bool (WINAPI *Type_GetDeviceGammaRamp)(HDC hDC, LPVOID lpRamp);
    typedef  bool (WINAPI *Type_SetDeviceGammaRamp)(HDC hDC, LPVOID lpRamp);

    Type_GetDeviceGammaRamp pGetDeviceGammaRamp;
    Type_SetDeviceGammaRamp pSetDeviceGammaRamp;

public :
    ~CGammaRamp();
    bool LoadLibrary();
    void  FreeLibrary();
    bool LoadLibraryIfNeeded();
    bool SetDeviceGammaRamp(HDC hDC, LPVOID lpRamp);
    bool GetDeviceGammaRamp(HDC hDC, LPVOID lpRamp);
    bool SetBrightness(HDC hDC, WORD wBrightness);
};

#endif //#ifndef GAMMARAMP_H_
