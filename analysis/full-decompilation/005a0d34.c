
void FUN_005a0d34(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00462f2f(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x5c) = *(undefined4 *)(unaff_EBP + 0x48);
  FUN_005995fd();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

