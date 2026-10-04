
uint FUN_00605e40(void)

{
  int iVar1;
  uint uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)((int)extraout_ECX + 0x15d) = 1;
  extraout_ECX[0x60] = *(int *)(iVar1 + 4);
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  (**(code **)(iVar1 + 0x14))(unaff_EBP + -0x14);
  extraout_ECX[0x1e] = 0x7c;
  extraout_ECX[0x1f] = 1;
  extraout_ECX[0x38] = 0x200;
  (**(code **)(*DAT_006fe8bc + 0x1c))();
  iVar1 = FUN_005eff44(extraout_ECX,0,0);
  if (iVar1 == 0) {
    *(undefined1 *)(extraout_ECX + 0x57) = 1;
    uVar2 = 1;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar2 = (**(code **)(*(int *)(unaff_EBP + -0x20) + 0x10))();
    extraout_ECX[1] = 0;
    uVar2 = uVar2 & 0xffffff00;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

