
int __thiscall FUN_004102ab(int param_1,uint param_2)

{
  int iVar1;
  
  if (((int)param_2 < 0) ||
     ((uint)(*(int *)(param_1 + 0x130) - *(int *)(param_1 + 300) >> 2) <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 300) + param_2 * 4;
  }
  return iVar1;
}

