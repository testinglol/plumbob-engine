
undefined4 * FUN_00488704(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00492ad8();
  extraout_ECX[0xb] = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0xc] = 0;
  *(undefined1 *)(extraout_ECX + 0xf) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x3d) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x3e) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x3f) = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x11] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0x19) = 0;
  *extraout_ECX = &PTR_FUN_00667d78;
  pvVar1 = operator_new(0x34);
  *(void **)(unaff_EBP + 8) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00488780(extraout_ECX);
  }
  extraout_ECX[0xc] = iVar2;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

