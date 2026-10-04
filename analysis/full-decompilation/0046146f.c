
void __thiscall FUN_0046146f(int *param_1,int param_2)

{
  void *pvVar1;
  
  if (*param_1 != 0) {
    FUN_006321f0(*param_1);
  }
  *param_1 = 0;
  if (param_1[1] != 0) {
    FUN_006321f0(param_1[1]);
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_2;
  if (param_2 < 1) {
    param_1[3] = 0;
  }
  else {
    pvVar1 = operator_new(param_2 << 3);
    *param_1 = (int)pvVar1;
    pvVar1 = operator_new(param_1[3] * 4 - 4);
    param_1[1] = (int)pvVar1;
  }
  return;
}

