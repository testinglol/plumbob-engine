
undefined1 FUN_00500045(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar3 = 0;
  FUN_0046f824(unaff_EBP + -0x110,0,0x104);
  *(undefined ***)(unaff_EBP + -0x11c) = &PTR_FUN_006664e8;
  uVar1 = FUN_0041532c(0,*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0x11c);
  FUN_004ee9ce(uVar1);
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_0046f71c(unaff_EBP + -0x11c,0);
  if (iVar2 == 0) {
    iVar2 = FUN_00470d31(unaff_EBP + -0x360,*(undefined4 *)(unaff_EBP + 8),
                         *(undefined4 *)(unaff_EBP + 0x14));
    if (iVar2 == 0) {
      uVar3 = 1;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

