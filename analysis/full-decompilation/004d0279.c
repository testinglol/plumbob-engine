
void FUN_004d0279(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00668d74;
  extraout_ECX[0x35] = &PTR_LAB_00668d44;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  FUN_004d0d45();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  uVar1 = extraout_ECX[0x462];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x45f];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x6c] = &PTR_LAB_00667884;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e8cc5();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

