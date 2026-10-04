
bool FUN_0060818d(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  bool bVar3;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + 8);
  FUN_005e76d4(unaff_EBP + -0x10,unaff_EBP + 8);
  iVar1 = *(int *)(unaff_EBP + -0x10);
  bVar3 = iVar1 != *(int *)(extraout_ECX + 0x10);
  if (bVar3) {
    FUN_005d499c(iVar1 + 0x14);
  }
  else {
    uVar2 = FUN_005d4956(s_arial_006d95e4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d499c(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar3;
}

