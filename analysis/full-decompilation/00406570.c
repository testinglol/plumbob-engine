
undefined4 * FUN_00406570(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046597b();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00635e55(extraout_ECX + 3,0x14,8,&LAB_004065b6,&LAB_004065e8);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00666594;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

