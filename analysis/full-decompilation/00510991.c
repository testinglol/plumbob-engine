
void FUN_00510991(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066be60;
  extraout_ECX[0x35] = &PTR_LAB_0066be30;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0051134c();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00635f6d(extraout_ECX + 0x54,0x6c,7,thunk_FUN_00470467);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005a5e09();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e8cc5();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

