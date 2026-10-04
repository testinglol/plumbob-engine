
undefined4 * FUN_005d58d8(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00673840;
  extraout_ECX[3] = 0;
  extraout_ECX[2] = &PTR_LAB_00673720;
  extraout_ECX[1] = &PTR_LAB_00673714;
  extraout_ECX[2] = &PTR_FUN_006736fc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d935e();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 0x10) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x11] = 0;
  extraout_ECX[0xf] = uVar1;
  extraout_ECX[4] = &PTR_LAB_00673838;
  *extraout_ECX = &PTR_LAB_00673820;
  extraout_ECX[1] = &PTR_LAB_00673814;
  extraout_ECX[2] = &PTR_FUN_006737fc;
  return extraout_ECX;
}

