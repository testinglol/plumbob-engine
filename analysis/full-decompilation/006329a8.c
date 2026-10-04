
int * __thiscall FUN_006329a8(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 8) == 0) {
    iVar1 = *(int *)((int)param_1 + *(int *)(*param_1 + 4) + 4);
    if (*(int *)(iVar1 + 0x30) < 0) {
      FUN_00633e5e(iVar1 + 0x34);
    }
    iVar1 = FUN_005c4410(param_2);
    if (iVar1 == -1) {
      FUN_00596bdf(*(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2);
    }
    iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
    if (*(int *)(iVar1 + 0x30) < 0) {
      FUN_00633e69(iVar1 + 0x34);
    }
  }
  return param_1;
}

