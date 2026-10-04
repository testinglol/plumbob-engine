
undefined4 * FUN_00489f7b(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00492ad8();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = uVar1;
  extraout_ECX[0xe] = 1;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0x17) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x5d) = 0;
  *extraout_ECX = &PTR_FUN_00667dfc;
  pvVar2 = operator_new(0x44);
  *(void **)(unaff_EBP + 8) = pvVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004935b7(extraout_ECX);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xc] = iVar3;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
    FUN_00493b7b(extraout_ECX[0xe]);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 10) = 1;
  extraout_ECX[0x18] = 0;
  return extraout_ECX;
}

