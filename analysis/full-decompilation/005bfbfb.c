
void __thiscall FUN_005bfbfb(int *param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 0x7fffffff) {
    if (param_2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_00401742(param_2 * 2);
    }
    *param_1 = iVar1;
    param_1[1] = iVar1;
    param_1[2] = iVar1 + param_2 * 2;
  }
  else {
    FUN_005bdc67();
  }
  return;
}

