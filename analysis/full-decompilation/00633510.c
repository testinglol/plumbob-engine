
void __thiscall FUN_00633510(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((*(int *)(*(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0x4c) == -1) &&
     (iVar1 = FUN_00633c6a(param_2,param_3 | 1,param_4), iVar1 != 0)) {
    return;
  }
  FUN_00596bdf(*(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2);
  return;
}

