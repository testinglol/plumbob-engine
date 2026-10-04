
void FUN_004e9d38(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004e9c34(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x18);
  FUN_0046f8cb(*(undefined4 *)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

