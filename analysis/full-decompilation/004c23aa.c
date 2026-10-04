
void FUN_004c23aa(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00668838;
  iVar1 = extraout_ECX[0x53];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (iVar1 != 0) {
    FUN_005e3581();
    extraout_ECX[0x53] = 0;
  }
  DAT_006f0a70 = DAT_006f0a70 + -1;
  if (DAT_006f0a70 == 0) {
    piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
    (**(code **)(*piVar2 + 0x14))(DAT_006f0a6c);
    DAT_006f0a6c = 0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

