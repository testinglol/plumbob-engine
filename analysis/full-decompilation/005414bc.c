
void __thiscall FUN_005414bc(int *param_1,int *param_2)

{
  int *piVar1;
  
  if (*param_2 != 0) {
    piVar1 = (int *)(*param_2 + 0x58);
    *piVar1 = *piVar1 + 1;
  }
  *param_1 = *param_2;
  return;
}

