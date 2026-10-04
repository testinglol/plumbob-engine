
void FUN_004c7318(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_00580a92(unaff_EBP + -0x1c);
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004c2284();
    FUN_004c735a();
    return;
  }
  FUN_005824b6();
  FUN_004b8dd1();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

