
int __thiscall FUN_0041f748(int param_1,short param_2)

{
  int iVar1;
  
  if ((uint)(int)param_2 < (uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc)) {
    iVar1 = *(int *)(param_1 + 4) + param_2 * 0xc;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  return iVar1;
}

