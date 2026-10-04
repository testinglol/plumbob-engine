
void FUN_004c735a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00576e56();
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

