
int FUN_00534aa8(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  iVar1 = FUN_00401742(0x48);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar1;
  FUN_00534e21(iVar1 + 0x10,*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

