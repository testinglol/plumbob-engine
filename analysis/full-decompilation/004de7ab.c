
int * __thiscall FUN_004de7ab(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (param_2 != 0) {
    iVar1 = FUN_00401742(param_2 * 0x11c);
  }
  *param_1 = iVar1;
  param_1[1] = iVar1;
  param_1[2] = param_2 * 0x11c + iVar1;
  return param_1;
}

