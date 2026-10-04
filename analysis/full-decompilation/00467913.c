
void FUN_00467913(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_00467999();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00635f6d(extraout_ECX + 0x80,8,0x40,FUN_00416e17);
  uVar1 = *(undefined4 *)(extraout_ECX + 0x28);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0040f6e0();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x1c);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_004d6053();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00468a63();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

