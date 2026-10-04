
/* Library Function - Single Match
    public: virtual void * __thiscall CMiniDockFrameWnd::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __thiscall
CMiniDockFrameWnd::_scalar_deleting_destructor_(CMiniDockFrameWnd *this,uint param_1)

{
  ~CMiniDockFrameWnd(this);
  if ((param_1 & 1) != 0) {
    FUN_006321f0(this);
  }
  return this;
}

