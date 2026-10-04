
undefined4 * FUN_0048aefd(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00492ad8();
  extraout_ECX[0xb] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0xc) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x31) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x32) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x33) = 0;
  *(undefined1 *)(extraout_ECX + 0xd) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x35) = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[0x17] = 0;
  extraout_ECX[0x18] = 1;
  extraout_ECX[0x19] = 1;
  extraout_ECX[0x1a] = uVar1;
  extraout_ECX[0x1b] = 0;
  *(undefined1 *)(extraout_ECX + 0x1c) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x71) = 0;
  *extraout_ECX = &PTR_FUN_00667e78;
  pvVar2 = operator_new(0xe068);
  *(void **)(unaff_EBP + 8) = pvVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00493f54(extraout_ECX);
  }
  extraout_ECX[0x17] = iVar3;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

