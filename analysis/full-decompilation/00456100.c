
undefined4 * __thiscall FUN_00456100(undefined4 *param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  if ((param_3 < 0) || (31999 < param_3)) {
    param_1[1] = 0;
    param_1[2] = 0;
  }
  else {
    pvVar1 = operator_new(param_3 * 2);
    param_1[2] = pvVar1;
  }
  iVar2 = 0;
  if (0 < (int)param_1[1]) {
    do {
      *(undefined2 *)(param_1[2] + iVar2 * 2) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1[1]);
  }
  return param_1;
}

