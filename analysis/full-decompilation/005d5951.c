
void FUN_005d5951(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  uint uVar1;
  
  FUN_00634c24();
  extraout_ECX[-2] = &PTR_LAB_00673820;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-1] = &PTR_LAB_00673814;
  *extraout_ECX = &PTR_FUN_006737fc;
  extraout_ECX[2] = &PTR_LAB_00673838;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined ***)(-(uint)(extraout_ECX != (undefined4 *)0x8) & (uint)(extraout_ECX + 2)) =
       &PTR_FUN_00673858;
  FUN_005d9122();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  uVar1 = -(uint)(extraout_ECX != (undefined4 *)0x8) & (uint)(extraout_ECX + -1);
  *(undefined ***)(-(uint)(uVar1 != 0) & uVar1 + 4) = &PTR_LAB_00673720;
  return;
}

