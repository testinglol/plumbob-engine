
undefined1 FUN_005777a5(void)

{
  undefined1 uVar1;
  void *pvVar2;
  int iVar3;
  int *extraout_ECX;
  int unaff_EBP;
  int iStack_30;
  undefined4 uStack_2c;
  
  FUN_00634c24();
  uStack_2c = 0x5777c0;
  pvVar2 = operator_new(0x4044);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  iVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 != (void *)0x0) {
    iVar3 = FUN_00579083();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0xd] = iVar3;
  iStack_30 = unaff_EBP + -0x28;
  uStack_2c = *(undefined4 *)(unaff_EBP + 8);
  FUN_00412ab1();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  uStack_2c = 0x5777fd;
  FUN_005b86bd();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401729();
  *(int **)(unaff_EBP + 0xc) = &iStack_30;
  FUN_005b86bd(unaff_EBP + -0x1c);
  FUN_00579152();
  uStack_2c = *(undefined4 *)(unaff_EBP + 0x10);
  iStack_30 = *(int *)(unaff_EBP + 8);
  uVar1 = (**(code **)(*extraout_ECX + 0xc))(extraout_ECX[0xd]);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

