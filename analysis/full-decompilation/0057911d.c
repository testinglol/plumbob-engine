
/* Library Function - Single Match
    public: virtual __thiscall CParkingWnd::~CParkingWnd(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CParkingWnd::~CParkingWnd(CParkingWnd *this)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0057a116();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

