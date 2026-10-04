
void FUN_00483238(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0048c4c9();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x1c);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_00542b02();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

