
bool FUN_004cdb34(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  bool bVar5;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 8);
  iVar1 = *(int *)(unaff_EBP + 0xc);
  iVar2 = *(int *)(iVar4 + 0x1c);
  iVar3 = *(int *)(iVar1 + 0x1c);
  if (iVar2 == iVar3) {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005d499c(iVar4 + 4);
    FUN_005d499c(iVar1 + 4);
    iVar4 = FUN_0043017f(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
                         *(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14));
    bVar5 = iVar4 < 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    bVar5 = iVar2 < iVar3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar5;
}

