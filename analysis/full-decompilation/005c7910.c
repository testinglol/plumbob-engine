
int FUN_005c7910(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005bc36d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0x20) = 0;
  FUN_005bc54d();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005bc54d();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005bc54d();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005bc557(1000);
  FUN_005bc41e();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

