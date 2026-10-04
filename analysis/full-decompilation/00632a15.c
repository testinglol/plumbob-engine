
void __fastcall FUN_00632a15(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_00633e5e(iVar1 + 0x34);
  }
  iVar1 = FUN_006340b6();
  while (iVar1 != -1) {
    iVar1 = FUN_00636918(iVar1);
    if (iVar1 == 0) goto LAB_00632a73;
    iVar1 = FUN_00633ffa();
  }
  FUN_00596bdf(*(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 1);
LAB_00632a73:
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_00633e69(iVar1 + 0x34);
  }
  return;
}

