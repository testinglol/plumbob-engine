
void FUN_00465dc2(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = FUN_004096c2();
  FUN_005b86bd(uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f8cb(*(undefined4 *)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

