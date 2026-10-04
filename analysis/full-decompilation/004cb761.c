
void __thiscall FUN_004cb761(int param_1,int *param_2)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2 == *(int *)(param_1 + 0x20)) {
    piVar1 = *(int **)(param_1 + 4);
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - *piVar1;
    FUN_005db2f2(piVar1);
    FUN_005db2f2(*(undefined4 *)(param_1 + 0x10));
  }
  piVar1 = param_2;
  FUN_0042eab4(param_2);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + *piVar1;
  param_2 = (int *)FUN_004cb715();
  FUN_0042eab4(&param_2);
  return;
}

