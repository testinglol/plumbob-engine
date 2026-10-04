
void FUN_005223ca(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066cb60;
  extraout_ECX[0x35] = &PTR_LAB_0066cb30;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0052298a();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005a5e09();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e8cc5();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

