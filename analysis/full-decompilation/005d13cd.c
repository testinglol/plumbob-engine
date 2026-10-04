
void __thiscall FUN_005d13cd(int param_1,uint param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  
  (**(code **)(*param_3 + 4))();
  piVar2 = (int *)(param_1 + 0xec);
  if (param_2 < (uint)(*(int *)(param_1 + 0xf0) - *piVar2 >> 2)) {
    piVar1 = *(int **)(*piVar2 + param_2 * 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))();
    }
    *(int **)(*piVar2 + param_2 * 4) = param_3;
  }
  else {
    FUN_005d15c0(&param_3);
  }
  return;
}

