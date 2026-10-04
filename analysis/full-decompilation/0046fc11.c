
int __thiscall FUN_0046fc11(int param_1,char param_2)

{
  int *piVar1;
  
  if (param_2 == -1) {
    param_2 = *(char *)(param_1 + 0x5d);
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x6c) + param_2 * 0xc);
  return (piVar1[1] - *piVar1) / 0xc;
}

