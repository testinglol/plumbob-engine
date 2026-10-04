
void __thiscall FUN_00517abf(int param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xd4);
  if (piVar1 != (int *)0x0) {
    if ((char)piVar1[0x5a] != param_2) {
      *(char *)(piVar1 + 0x5a) = param_2;
      (**(code **)(*piVar1 + 0x168))();
    }
  }
  return;
}

