
int * FUN_00526ef7(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0050904a();
  iVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x48] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *extraout_ECX = (int)&PTR_FUN_0066d3d4;
  extraout_ECX[0x35] = (int)&PTR_LAB_0066d3c4;
  FUN_005d499c(uVar1);
  FUN_005d499c(*(undefined4 *)(unaff_EBP + 0xc));
  (**(code **)(*extraout_ECX + 0x168))();
  extraout_ECX[0x39] = *(int *)(unaff_EBP + 0x10);
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  iVar3 = FUN_005dd5e1(0xbc,0xbc,0xbc);
  extraout_ECX[0x3a] = iVar3;
  FUN_005e57d4(0xbc,0xbc,0xbc);
  iVar3 = *(int *)(unaff_EBP + 0x14);
  extraout_ECX[0x4d] = *(int *)(unaff_EBP + 0x1c);
  iVar2 = *(int *)(unaff_EBP + 0x20);
  extraout_ECX[0x4a] = 0;
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x49] = 0;
  extraout_ECX[0x4e] = iVar2;
  *(undefined1 *)(extraout_ECX + 0x4f) = 0;
  extraout_ECX[0x50] = 0;
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    FUN_004054fa(**(int **)(unaff_EBP + 0x18) + iVar4);
    iVar4 = iVar4 + 0xc;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

