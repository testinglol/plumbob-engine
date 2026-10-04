
undefined4 * FUN_005f179a(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  FUN_005d48d9();
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x5a] = 0;
  extraout_ECX[0x5b] = 0;
  extraout_ECX[0x5c] = 0;
  extraout_ECX[0x5d] = 0;
  extraout_ECX[0x5e] = 0;
  extraout_ECX[0x5f] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *extraout_ECX = &PTR_FUN_0067558c;
  extraout_ECX[0x35] = *(undefined4 *)(unaff_EBP + -0x28);
  extraout_ECX[0x36] = *(undefined4 *)(unaff_EBP + -0x24);
  extraout_ECX[0x37] = *(undefined4 *)(unaff_EBP + -0x20);
  extraout_ECX[0x38] = *(undefined4 *)(unaff_EBP + -0x1c);
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x49] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x155) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x156) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x15d) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  extraout_ECX[0x4a] = 0;
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x50] = 0;
  extraout_ECX[0x51] = 0;
  extraout_ECX[0x4d] = 0;
  extraout_ECX[0x52] = 0;
  extraout_ECX[0x53] = 0;
  extraout_ECX[0x54] = 0;
  *(undefined1 *)(extraout_ECX + 0x55) = 1;
  *(undefined1 *)(extraout_ECX + 0x57) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x15e) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x15f) = 0;
  extraout_ECX[0x4e] = 0;
  pvVar1 = operator_new(0x24);
  *(void **)(unaff_EBP + -0x18) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f19e9();
  }
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005f4a70(unaff_EBP + -0x10);
  pvVar1 = operator_new(0x20);
  *(void **)(unaff_EBP + -0x18) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (pvVar1 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005ed88f();
  }
  *(undefined1 *)(unaff_EBP + -4) = 6;
  extraout_ECX[0x6d] = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x20))(&LAB_005f4217,extraout_ECX);
  }
  DAT_006fecb0 = DAT_006fecb0 + 1;
  *(undefined1 *)((int)extraout_ECX + 0x157) = 0;
  FUN_005481eb(1,0);
  *(undefined1 *)extraout_ECX[0x39] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x161) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x186) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x196) = 0;
  extraout_ECX[0x60] = 0;
  extraout_ECX[0x59] = 0;
  extraout_ECX[100] = 0;
  extraout_ECX[0x66] = 0;
  extraout_ECX[0x41] = 0;
  *(undefined1 *)(extraout_ECX + 0x58) = 1;
  FUN_005d4bbf(s_UI_Error_006d7bb0);
  FUN_005d4bbf(s_UI_Error_006d7bb0);
  *(undefined1 *)((int)extraout_ECX + 0x195) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x65) = 0;
  return extraout_ECX;
}

