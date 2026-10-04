
int * __thiscall FUN_005414d4(int *param_1,int *param_2)

{
  int *piVar1;
  
  if (*param_2 != 0) {
    piVar1 = (int *)(*param_2 + 0x58);
    *piVar1 = *piVar1 + 1;
  }
  if (*param_1 != 0) {
    FUN_0053c286();
  }
  *param_1 = *param_2;
  return param_1;
}

