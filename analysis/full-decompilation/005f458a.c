
undefined4 FUN_005f458a(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(int *)(extraout_ECX + 0x16c) - *(int *)(extraout_ECX + 0x168) & 0xfffffffcU) != 0) {
    iVar1 = *(int *)(*(int *)(extraout_ECX + 0x16c) + -4);
    *(int *)(extraout_ECX + 0x16c) = *(int *)(extraout_ECX + 0x16c) + -4;
    pvVar2 = operator_new(0x30);
    *(void **)(unaff_EBP + -0x14) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_005f4628();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    FUN_005f4839(uVar3);
    FUN_005f4a97(unaff_EBP + -0x10);
    FUN_005f47d3(iVar1);
    if (iVar1 != 0) {
      FUN_005b8770();
      FUN_006321f0(iVar1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

