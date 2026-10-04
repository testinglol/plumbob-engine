
void FUN_005eed93(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-2] = &PTR_LAB_0067547c;
  extraout_ECX[-1] = &PTR_LAB_00675470;
  *extraout_ECX = &PTR_FUN_00675458;
  extraout_ECX[2] = &PTR_LAB_00675450;
  extraout_ECX[0x10] = &PTR_FUN_00675400;
  uVar1 = extraout_ECX[0xba];
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_006321f0(uVar1);
  extraout_ECX[0xba] = 0;
  FUN_005d69da();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005ec00f();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005eed47();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005f060f();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005d9122();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005eeb73();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

