
/* Library Function - Single Match
    public: virtual void * __thiscall CParkingWnd::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __thiscall CParkingWnd::_scalar_deleting_destructor_(CParkingWnd *this,uint param_1)

{
  ~CParkingWnd(this);
  if ((param_1 & 1) != 0) {
    FUN_006321f0(this);
  }
  return this;
}

