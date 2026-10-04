
undefined4 FUN_00601e2a(void)

{
  int iVar1;
  int extraout_ECX;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 8);
  (**(code **)(iVar1 + 4))();
  uVar2 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_0060783f();
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(*(int *)(*(int *)(extraout_ECX + 4) + 4) + 8);
    FUN_0060287f();
  }
  iVar1 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

