
void FUN_0043ab93(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-1] = &PTR_FUN_00667010;
  *extraout_ECX = &PTR_FUN_00667004;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  FUN_0043b7ef();
  uVar1 = extraout_ECX[0x49e];
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0040f621();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_0048c4c9();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX + 0x496;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005824b6();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005481b6();
  uVar1 = extraout_ECX[0x493];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x490];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[7];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040763c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

