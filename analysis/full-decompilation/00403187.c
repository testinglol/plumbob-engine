
void FUN_00403187(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(unaff_EBP + 0xc);
    FUN_004030b4(iVar2);
    *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(iVar2 + 0x4c);
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar2 + 0x50);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

