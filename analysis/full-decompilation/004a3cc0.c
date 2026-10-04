
undefined4 * FUN_004a3cc0(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_004a42c7(unaff_EBP + -0xe,unaff_EBP + -0xd);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[5] = uVar1;
  extraout_ECX[4] = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_006686d4;
  extraout_ECX[6] = &LAB_004a3c1f;
  extraout_ECX[7] = &LAB_004a3c28;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = FUN_004a3c68;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = &LAB_004a3cae;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = &LAB_005fe26c;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 0;
  FUN_004a415d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

