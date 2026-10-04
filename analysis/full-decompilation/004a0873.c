
int FUN_004a0873(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x2c) = 0;
  return extraout_ECX;
}

