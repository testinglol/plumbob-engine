
int * __thiscall FUN_004035e8(int param_1,char param_2)

{
  int *piVar1;
  
  if ((param_2 == '\0') || (piVar1 = (int *)(param_1 + 0x68), *(int *)(param_1 + 0x6c) == *piVar1))
  {
    piVar1 = (int *)(param_1 + 0x5c);
  }
  return piVar1;
}

