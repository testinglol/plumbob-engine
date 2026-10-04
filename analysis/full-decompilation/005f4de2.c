
void FUN_005f4de2(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00675734;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_005f4ff0();
  uVar1 = extraout_ECX[0x35];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

