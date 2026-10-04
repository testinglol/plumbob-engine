
undefined4 * FUN_0054866a(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e8c4a(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x48] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *extraout_ECX = &PTR_FUN_0066fd08;
  extraout_ECX[0x35] = &PTR_LAB_0066fcd8;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x45] = 0;
  _memset(extraout_ECX + 0x49,0x20,0);
  _memset(extraout_ECX + 0x52,0x14,0);
  extraout_ECX[0x51] = 0xffffffff;
  extraout_ECX[0x57] = 0;
  pvVar1 = operator_new(0x248);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00544cc2();
  }
  *(undefined1 *)(unaff_EBP + -4) = 7;
  extraout_ECX[0x6a] = piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))();
    (**(code **)(*(int *)extraout_ECX[0x6a] + 4))();
  }
  extraout_ECX[0x6c] = 0;
  extraout_ECX[0x6e] = DAT_006fea20;
  DAT_006fea20 = DAT_006f2a98;
  uVar3 = FUN_005e749a(0);
  FUN_005dde6d(uVar3);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

