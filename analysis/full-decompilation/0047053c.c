
void __thiscall FUN_0047053c(int param_1,uint param_2)

{
  int *piVar1;
  
  if ((0 < (int)param_2) &&
     (piVar1 = (int *)(param_1 + 0x60), param_2 <= (uint)(*(int *)(param_1 + 100) - *piVar1 >> 2)))
  {
    FUN_006321f0(*(undefined4 *)(*piVar1 + -4 + param_2 * 4));
    FUN_005db2f2(*piVar1 + -4 + param_2 * 4);
  }
  return;
}

