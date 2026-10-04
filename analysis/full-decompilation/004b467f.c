
void __thiscall FUN_004b467f(int param_1,int *param_2)

{
  *param_2 = *param_2 - *(int *)(param_1 + 0x3c);
  param_2[1] = param_2[1] - *(int *)(param_1 + 0x40);
  param_2[2] = param_2[2] - *(int *)(param_1 + 0x3c);
  param_2[3] = param_2[3] - *(int *)(param_1 + 0x40);
  return;
}

