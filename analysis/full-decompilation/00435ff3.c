
void FUN_00435ff3(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = FUN_0046fbe5(0xffffffff);
  if (iVar1 == 0) {
    FUN_0046f824(unaff_EBP + -0x110,0,0x104);
    *(undefined ***)(unaff_EBP + -0x11c) = &PTR_FUN_006664e8;
    uVar2 = FUN_0041532c(9,unaff_EBP + -0x11c);
    uVar2 = FUN_0041532c(0,uVar2);
    FUN_004ee9ce(uVar2);
    FUN_0046f5cd();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar1 = FUN_0046f71c(unaff_EBP + -0x11c,0);
    if (iVar1 == 0) {
      FUN_00470383(unaff_EBP + -0x360,0x8e,0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046b2e6();
  }
  FUN_004705f2(*(undefined4 *)(unaff_EBP + 8),0xffffffff);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

