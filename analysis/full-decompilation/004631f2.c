
/* Library Function - Single Match
    public: virtual __thiscall CMiniDockFrameWnd::~CMiniDockFrameWnd(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CMiniDockFrameWnd::~CMiniDockFrameWnd(CMiniDockFrameWnd *this)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0042286d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

