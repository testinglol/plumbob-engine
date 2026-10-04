
void __thiscall FUN_004015e4(int *param_1,undefined1 param_2)

{
  int **ppiVar1;
  int *local_c;
  int *local_8;
  
  local_c = param_1;
  local_8 = param_1;
  if (param_1[1] + 1 == param_1[2]) {
    local_8 = (int *)(param_1[1] - *param_1);
    local_c = (int *)0x1;
    ppiVar1 = &local_c;
    if (local_8 != (int *)0x0) {
      ppiVar1 = &local_8;
    }
    FUN_00401674((int)*ppiVar1 + (int)local_8);
  }
  FUN_00401651(param_1[1] + 1);
  *(undefined1 *)param_1[1] = param_2;
  param_1[1] = param_1[1] + 1;
  return;
}

