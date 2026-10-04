
void FUN_004ff25e(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    FUN_005b8680(extraout_ECX);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

