
uint __thiscall FUN_005dd7aa(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  if (*(int **)(param_1 + 0x40) == (int *)0x0) {
    param_1 = param_1 & 0xffffff00;
  }
  else {
    param_1 = (**(code **)(**(int **)(param_1 + 0x40) + 0xe8))
                        (param_2 + *(int *)(param_1 + 0x7c),param_3 + *(int *)(param_1 + 0x80),
                         param_4);
  }
  return param_1;
}

