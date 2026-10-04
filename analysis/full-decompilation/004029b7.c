
int __thiscall FUN_004029b7(int param_1,int param_2)

{
  if (param_2 + 0x54 != *(int *)(param_1 + 4)) {
    FUN_00403046(param_2 + 0x54,*(int *)(param_1 + 4),param_2);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x54;
  return param_2;
}

