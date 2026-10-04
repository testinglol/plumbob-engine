
int * FUN_0054e56f(void)

{
  undefined4 uVar1;
  int *piVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006f5390 == (int *)0x0) {
    uVar1 = FUN_005d4956(s_Internal_Error__sPopup_is_NULL__006cdbe4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005dd9c8(uVar1);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    piVar2 = (int *)FUN_005dd99d();
  }
  else {
    (**(code **)(*DAT_006f5390 + 4))();
    FUN_0054fcb8(extraout_ECX + 0x194,extraout_ECX + 0x21c,0);
    piVar2 = DAT_006f5390;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar2;
}

