
void FUN_004ec717(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006695e8;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_004ecb73();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635f6d(extraout_ECX + 0x48,0x6c,2,thunk_FUN_00470467);
  uVar1 = extraout_ECX[0x3c];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

