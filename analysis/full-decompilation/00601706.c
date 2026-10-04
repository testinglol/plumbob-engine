
void FUN_00601706(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 8);
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00602826(*(undefined4 *)(unaff_EBP + 8));
  iVar1 = FUN_0060783f();
  if (iVar1 == 1) {
    (**(code **)(*(int *)(extraout_ECX + 0x2c) + 4))();
  }
  iVar1 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

