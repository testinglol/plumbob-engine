
void FUN_006033c5(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-3] = &PTR_FUN_00676acc;
  extraout_ECX[-2] = &PTR_LAB_00676ab4;
  extraout_ECX[-1] = &PTR_LAB_00676aa8;
  *extraout_ECX = &PTR_FUN_00676a90;
  extraout_ECX[2] = &PTR_LAB_00676a88;
  iVar1 = extraout_ECX[-2];
  *(undefined4 *)(unaff_EBP + -4) = 4;
  (**(code **)(iVar1 + 0x10))();
  if (extraout_ECX[0x12] != 0) {
    FUN_006321f0(extraout_ECX[0x12]);
    extraout_ECX[0x12] = 0;
    DAT_006fecc4 = 0;
  }
  (**(code **)(extraout_ECX[-3] + 0xb0))(0);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00604412();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d9122();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_006043dc();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d5951();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

