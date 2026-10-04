
void FUN_005ec00f(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00674dc8;
  iVar1 = extraout_ECX[0x16];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    extraout_ECX[0x16] = iVar1 + -1;
  }
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX[0x27];
  FUN_00542b02();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dfb96();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

