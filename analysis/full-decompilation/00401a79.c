
void FUN_00401a79(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffff0;
  FUN_00401651(*(undefined4 *)(extraout_ECX + 4));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

