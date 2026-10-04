
int __thiscall FUN_0046fbe5(int param_1,char param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_2 == *(char *)(param_1 + 0x5d)) || (param_2 == -1)) {
    iVar1 = *(int *)(param_1 + 100) - *(int *)(param_1 + 0x60) >> 2;
  }
  return iVar1;
}

