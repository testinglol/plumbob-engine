
void FUN_00527037(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066d3d4;
  extraout_ECX[0x35] = &PTR_LAB_0066d3c4;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_0052772d();
  uVar1 = extraout_ECX[0x46];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  uVar1 = extraout_ECX[0x43];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004054b4();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e359a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

