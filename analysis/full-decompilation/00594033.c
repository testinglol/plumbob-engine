
int * __thiscall FUN_00594033(int *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_00633e5e((int)param_1 + *(int *)(*param_1 + 4) + 0x38);
  }
  param_1[1] = param_1[1] + 1;
  FUN_00633e74(param_2,param_3,param_4);
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x34) < 0) {
    FUN_00633e69((int)param_1 + *(int *)(*param_1 + 4) + 0x38);
  }
  return param_1;
}

