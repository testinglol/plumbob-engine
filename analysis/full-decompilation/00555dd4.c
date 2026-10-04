
void FUN_00555dd4(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) == 0) goto LAB_00555f89;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x84) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x188,0,0x104);
  *(undefined ***)(unaff_EBP + -0x194) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x298,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2a4) = &PTR_FUN_006664e8;
  FUN_00425531(unaff_EBP + -0x2a4);
  uVar3 = *(undefined4 *)(unaff_EBP + -0x2a0);
  uVar2 = FUN_0041532c(10,unaff_EBP + -0x194);
  FUN_004ee9ce(uVar3,uVar2);
  FUN_0046f5cd();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar3 = FUN_0041532c(10,unaff_EBP + -0x194);
  uVar3 = FUN_0041532c(7,uVar3);
  FUN_004ee9ce(uVar3);
  iVar4 = FUN_0046f71c(unaff_EBP + -0x194,1);
  if (iVar4 == 0) {
    cVar1 = FUN_004067fa();
    if (cVar1 == '\0') goto LAB_00555ed3;
    FUN_0047034e(unaff_EBP + -0x4e8,6,0x53545223,0,0xffffffff);
    iVar4 = FUN_0046ffa4(0,1);
    if (iVar4 == 0) {
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005d5156(unaff_EBP + -0x18,&DAT_006c08e4,*(undefined4 *)(unaff_EBP + 8));
      FUN_004704a5(5,*(undefined4 *)(unaff_EBP + -0x18),0xffffffff);
      FUN_0046fd72();
      FUN_0046b7ee();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0046b2e6();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
LAB_00555ed3:
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0046b2e6();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_00470467();
LAB_00555f89:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

