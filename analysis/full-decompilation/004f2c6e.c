
void FUN_004f2c6e(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x298,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2a4) = &PTR_FUN_006664e8;
  uVar1 = FUN_0041532c(0x10,0,unaff_EBP + -0x2a4);
  FUN_004ee9ce(uVar1);
  FUN_004a0820();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x188,0,0x104);
  *(undefined ***)(unaff_EBP + -0x194) = &PTR_FUN_006664e8;
  FUN_0046f847(&DAT_006cac9c,0xffffffff);
  FUN_0046f8e4(unaff_EBP + -0x194);
  *(undefined1 *)(unaff_EBP + -0x18) = 0;
  iVar2 = FUN_00412825(unaff_EBP + -0x2a4);
  if (iVar2 == 0) {
    for (iVar2 = *(int *)(unaff_EBP + -0x24); iVar2 != *(int *)(unaff_EBP + -0x20);
        iVar2 = iVar2 + 0x110) {
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x2a0);
      FUN_0046f824(unaff_EBP + -0x188,0,0x104);
      *(undefined ***)(unaff_EBP + -0x194) = &PTR_FUN_006664e8;
      FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
      FUN_005a3e90(iVar2,unaff_EBP + -0x194);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004a08ab();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

