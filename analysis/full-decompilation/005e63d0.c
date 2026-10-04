
void FUN_005e63d0(void)

{
  int extraout_ECX;
  int unaff_EBP;
  int iStack_2c;
  
  FUN_00634c24();
  iStack_2c = *(int *)(unaff_EBP + 8);
  FUN_005d4956();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iStack_2c = 0x5e63f8;
  FUN_005d4d37();
  iStack_2c = unaff_EBP + -0x20;
  FUN_005b86bd();
  iStack_2c = unaff_EBP + -0x2c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005343fd(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  iStack_2c = 0x5e6426;
  FUN_005b8770();
  iStack_2c = *(int *)(unaff_EBP + 8);
  if (iStack_2c != *(int *)(extraout_ECX + 4)) {
    *(int **)(unaff_EBP + -0x10) = &iStack_2c;
    FUN_005e6a25();
    iStack_2c = unaff_EBP + -0x20;
    FUN_005b86bd();
    iStack_2c = unaff_EBP + -0x2c;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005e6e12(unaff_EBP + -0x10);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    iStack_2c = 0x5e646c;
    FUN_005b8770();
    iStack_2c = *(int *)(unaff_EBP + -0x10);
    if (iStack_2c != *(int *)(extraout_ECX + 0x10)) {
      *(int **)(unaff_EBP + -0x14) = &iStack_2c;
      FUN_005e6a6c();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_2c = 0x5e6490;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

