
void __thiscall FUN_004a48ba(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = param_1 + 0xc;
  *piVar1 = *piVar1 + param_2;
  if (*piVar1 < 0) {
    param_1[0xc] = 0;
  }
  (**(code **)(*param_1 + 0xc))();
  return;
}

