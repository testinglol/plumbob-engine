
void __thiscall FUN_005cee2f(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x1d0) = param_2;
  piVar1 = *(int **)(*(int *)(param_1 + 0x60) + 0x38);
  (**(code **)(*piVar1 + 0x60))(piVar1,2,param_2);
  return;
}

