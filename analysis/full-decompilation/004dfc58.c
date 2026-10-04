
void FUN_004dfc58(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_005ed911();
  *extraout_ECX = 0;
  FUN_0052ea87(extraout_ECX[0x26],extraout_ECX[0x27]);
  uVar1 = extraout_ECX[0x26];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d9122();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d9122();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005d9122();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d9122();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

