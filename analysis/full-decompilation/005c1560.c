
int FUN_005c1560(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c1719();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 8));
  FUN_005c178a(*(undefined4 *)(unaff_EBP + 0x10));
  uVar1 = FUN_005c166e(*(undefined4 *)(unaff_EBP + 0xc));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x1c) = uVar1;
  return extraout_ECX;
}

