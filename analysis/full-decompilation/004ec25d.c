
undefined4 FUN_004ec25d(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x90) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046fc56();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar1 = FUN_004705f2(*(int *)(unaff_EBP + 8) + 1,0xffffffff);
  FUN_005d4bbf(uVar1);
  if (*(undefined1 **)(unaff_EBP + -0x1c) == &DAT_006de560) {
    uVar1 = 0x7a7d732e;
  }
  else {
    uVar1 = FUN_004096c2(&DAT_006c9ed0,unaff_EBP + -0x10);
    FUN_00634d24(uVar1);
    uVar1 = *(undefined4 *)(unaff_EBP + -0x10);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042004f();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

