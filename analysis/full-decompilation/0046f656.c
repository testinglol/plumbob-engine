
undefined4 * FUN_0046f656(void)

{
  int *piVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_00406570();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX + 0x2b;
  *(undefined4 *)(unaff_EBP + -0x14) = 0x11;
  do {
    FUN_0046f6df();
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x18;
    piVar1 = (int *)(unaff_EBP + -0x14);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  extraout_ECX[0x2b] = 0;
  *extraout_ECX = &PTR_FUN_00667680;
  FUN_0046f824(unaff_EBP + -0x20,0,8);
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_FUN_00666644;
  FUN_0046f847(0,0xffffffff);
  FUN_0046f8e4(unaff_EBP + -0x2c);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

