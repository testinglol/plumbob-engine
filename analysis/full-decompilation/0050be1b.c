
int __thiscall FUN_0050be1b(int param_1,int param_2)

{
  if (param_2 + 0x48 != *(int *)(param_1 + 4)) {
    FUN_0050c140(param_2 + 0x48,*(int *)(param_1 + 4),param_2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x48;
  FUN_00430980();
  return param_2;
}

