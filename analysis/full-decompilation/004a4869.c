
void __thiscall FUN_004a4869(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = param_1 + 9;
  *piVar1 = *piVar1 + param_2;
  if (*piVar1 < 0) {
    *piVar1 = 0;
  }
  if (param_1[0xb] < *piVar1) {
    piVar1 = param_1 + 0xb;
  }
  param_1[0xe] = *piVar1;
  (**(code **)(*param_1 + 0xc))();
  return;
}

