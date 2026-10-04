
int * __thiscall FUN_00524b60(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x114);
  if (iVar1 == 0) {
    *param_2 = 0;
    param_2[1] = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x20);
    *param_2 = *(int *)(iVar1 + 0x1c) / 3;
    param_2[1] = iVar2 / 3;
  }
  return param_2;
}

