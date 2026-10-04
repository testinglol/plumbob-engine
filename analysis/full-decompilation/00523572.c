
void FUN_00523572(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066cd10;
  extraout_ECX[0x35] = &PTR_LAB_0066cd00;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_005236c6();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005a5e09();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005a5e09();
  uVar1 = extraout_ECX[0x3d];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x36];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_004d6053();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e359a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

