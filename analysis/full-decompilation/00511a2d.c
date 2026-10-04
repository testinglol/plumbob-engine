
undefined4 FUN_00511a2d(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_004705f2(*(int *)(unaff_EBP + 0xc) + 1,0xffffffff);
  FUN_005d4bbf(uVar2);
  uVar2 = FUN_004705f2(1,0xffffffff);
  FUN_005d4bbf(uVar2);
  cVar1 = FUN_005117ea(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(extraout_ECX + 0x140));
  if (cVar1 == '\0') {
    FUN_005b86bd(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  else {
    if (*(undefined1 **)(unaff_EBP + -0x28) == &DAT_006de560) {
      FUN_005b86bd(unaff_EBP + -0x1c);
    }
    else {
      FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x28));
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

