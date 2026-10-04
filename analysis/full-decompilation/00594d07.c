
void FUN_00594d07(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *(int *)(extraout_ECX + 0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if ((iVar1 != 0) && (DAT_006f75e4 != (code *)0x0)) {
    (*DAT_006f75e4)(iVar1);
  }
  if (*(int *)(extraout_ECX + 0x24) != 0) {
    FUN_005942ab();
  }
  *(undefined4 *)(extraout_ECX + 0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

