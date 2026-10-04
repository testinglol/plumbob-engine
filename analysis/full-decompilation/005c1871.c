
bool FUN_005c1871(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  bool bVar1;
  int iVar2;
  
  FUN_00634c24();
  iVar2 = *extraout_ECX;
  FUN_005c26e9(unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + 8));
  bVar1 = *(int *)(unaff_EBP + -0x10) == iVar2;
  if (bVar1) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar2 = unaff_EBP + -0x1c;
    FUN_005c2358(*(undefined4 *)(unaff_EBP + 8));
    FUN_005c2910(iVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046664c();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return !bVar1;
}

