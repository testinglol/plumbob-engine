
/* Library Function - Single Match
    public: virtual __thiscall CSessionMapPtrToPtr::~CSessionMapPtrToPtr(void)
   
   Library: Visual Studio 2003 Release */

void __thiscall CSessionMapPtrToPtr::~CSessionMapPtrToPtr(CSessionMapPtrToPtr *this)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR__scalar_deleting_destructor__006681c8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00493b89();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00492fa7();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

