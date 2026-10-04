
undefined4 FUN_0054dd0a(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x84) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x188,0,0x104);
  *(undefined ***)(unaff_EBP + -0x194) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x298,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2a4) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x2a4);
  uVar2 = *(undefined4 *)(unaff_EBP + -0x2a0);
  uVar1 = FUN_0041532c(10,unaff_EBP + -0x194);
  FUN_004ee9ce(uVar2,uVar1);
  FUN_0046f5cd();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = FUN_0041532c(10,unaff_EBP + -0x194);
  uVar2 = FUN_0041532c(7,uVar2);
  FUN_004ee9ce(uVar2);
  iVar3 = FUN_0046f71c(unaff_EBP + -0x194,0);
  if (iVar3 == 0) {
    FUN_0047034e(unaff_EBP + -0x4e8,6,0x53545223,0,0xffffffff);
    iVar3 = FUN_0046ffa4(0,1);
    if (iVar3 == 0) {
      FUN_0046b7ee();
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar2 = FUN_004705f2(1,0xffffffff);
      FUN_005d4bbf(uVar2);
      uVar2 = FUN_004096c2();
      uVar2 = FUN_00635f62(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      goto LAB_0054de6e;
    }
  }
  uVar2 = 2;
LAB_0054de6e:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0046b2e6();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

