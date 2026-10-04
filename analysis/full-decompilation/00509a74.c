
undefined4 * FUN_00509a74(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_0066ad44;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3b] = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = iVar1;
  if (iVar1 != 0) {
    FUN_004ce503(extraout_ECX);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x35) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xd5) = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  return extraout_ECX;
}

