
int FUN_00418c28(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  for (iVar1 = *extraout_ECX;
      (iVar1 != extraout_ECX[1] && (*(int *)(iVar1 + 0xc) != *(int *)(unaff_EBP + 8)));
      iVar1 = iVar1 + 0x14) {
  }
  if ((*(char *)(unaff_EBP + 0xc) != '\0') && (iVar1 == extraout_ECX[1])) {
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0041a7d3(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0041a82b();
    iVar1 = *extraout_ECX + -0x14 + ((extraout_ECX[1] - *extraout_ECX) / 0x14) * 0x14;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

