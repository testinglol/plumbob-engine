
int __thiscall FUN_005cb642(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_1 != param_2) {
    piVar1 = *(int **)(param_2 + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    piVar1 = *(int **)(param_1 + 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  }
  return param_1;
}

