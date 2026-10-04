
void FUN_004d6581(void)

{
  char cVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar1 = FUN_005ed4a5(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if (cVar1 != '\0') {
    FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005ed6c0(unaff_EBP + -0x24,1,0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

