
undefined4 * FUN_00525cfd(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0050904a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  *extraout_ECX = &PTR_FUN_0066d224;
  extraout_ECX[0x35] = &PTR_LAB_0066d214;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x44] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[0x3b] = 0;
  *(undefined1 *)(extraout_ECX + 0x47) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x11d) = 1;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x45] = 0;
  pvVar1 = operator_new(0x104);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0053511e();
  }
  extraout_ECX[0x3c] = iVar2;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 8) = iVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x4d] = 0x40000000;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x4e] = 0;
  return extraout_ECX;
}

