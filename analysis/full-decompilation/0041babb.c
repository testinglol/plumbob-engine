
void FUN_0041babb(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX + 4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041dffb();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005481b6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

