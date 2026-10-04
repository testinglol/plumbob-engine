
int * __thiscall FUN_004222bd(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = param_1 + 1;
  *piVar1 = 0;
  *piVar1 = 0;
  *param_1 = 0;
  FUN_004222ef(param_2,piVar1,param_1);
  *piVar1 = *piVar1 << 4;
  *param_1 = *param_1 << 4;
  return param_1;
}

