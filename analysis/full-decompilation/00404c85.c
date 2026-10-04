
void FUN_00404c85(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00635f6d(extraout_ECX + 0x5c,0xc,2,FUN_005b8770);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00405522();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

