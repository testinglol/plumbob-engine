
void FUN_005fda63(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  extraout_ECX[-2] = &PTR_LAB_00676850;
  extraout_ECX[-1] = &PTR_LAB_00676844;
  *extraout_ECX = &PTR_FUN_0067682c;
  extraout_ECX[2] = &PTR_LAB_00676824;
  extraout_ECX[0x10] = &PTR_LAB_00676794;
  iVar1 = extraout_ECX[-2];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  (**(code **)(iVar1 + 0x10))();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x15] = &PTR_FUN_00676868;
  FUN_006012ee();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d5951();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

