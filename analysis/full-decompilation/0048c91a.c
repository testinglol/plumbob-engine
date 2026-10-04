
void FUN_0048c91a(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_005a5e09();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635f6d(extraout_ECX + 0x1b,0xc,9,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0048e388();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0045fb18();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00667bd0;
  return;
}

