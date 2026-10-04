
int * FUN_005e5157(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0050904a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = (int)&PTR_FUN_006741a4;
  extraout_ECX[0x35] = (int)&PTR_LAB_00674194;
  FUN_005d499c(uVar2);
  FUN_005d499c(*(undefined4 *)(unaff_EBP + 0xc));
  (**(code **)(*extraout_ECX + 0x168))();
  extraout_ECX[0x39] = *(int *)(unaff_EBP + 0x10);
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  iVar1 = FUN_005dd5e1(0xbc,0xbc,0xbc);
  extraout_ECX[0x3a] = iVar1;
  FUN_005e57d4(0xbc,0xbc,0xbc);
  iVar1 = *(int *)(unaff_EBP + 0x14);
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x45] = iVar1;
  iVar1 = *(int *)(unaff_EBP + 0x18);
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x46] = iVar1;
  *(undefined1 *)(extraout_ECX + 0x47) = 0;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x40] = 0;
  uVar2 = FUN_005e74ca(0);
  FUN_005dde6d(uVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

