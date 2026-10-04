
int FUN_005d8c94(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  iVar1 = FUN_00401742(0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  FUN_005d8d21(iVar1 + 8,*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

