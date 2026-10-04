
void FUN_00492fa7(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00668194;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00492ffc();
  uVar1 = extraout_ECX[6];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[3];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

