
void __thiscall FUN_0047166d(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 100);
  iVar2 = *(int *)(param_1 + 0x60);
  *param_2 = param_1;
  param_2[1] = (iVar1 - iVar2 >> 2) + 1;
  return;
}

