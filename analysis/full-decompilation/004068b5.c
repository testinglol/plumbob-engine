
uint FUN_004068b5(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_004659fc(0);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040690b(unaff_EBP + -0x18);
  iVar1 = *(int *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar2 = *(int *)(unaff_EBP + -0x18);
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1 - iVar2 >> 2 & 0xffff;
}

