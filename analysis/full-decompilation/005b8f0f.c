
int __thiscall FUN_005b8f0f(int param_1,undefined4 param_2,int param_3)

{
  if (*(char *)(param_1 + 0x1d) == '\0') {
    param_3 = 0;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xc) + 0x44))(param_2,&param_3);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_3;
    if (*(int *)(param_1 + 0x10) < *(int *)(param_1 + 0x18)) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x18);
    }
  }
  return param_3;
}

