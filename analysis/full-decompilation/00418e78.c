
int __thiscall FUN_00418e78(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00418c28(param_2,0);
  if (piVar1 != *(int **)(param_1 + 4)) {
    if (param_4 != 0) {
      piVar1[4] = param_4;
    }
    if ((0 < (int)param_3) && (param_3 <= (uint)((piVar1[1] - *piVar1) / 0x5c))) {
      return param_3 * 0x5c + -0x5c + *piVar1;
    }
  }
  return 0;
}

