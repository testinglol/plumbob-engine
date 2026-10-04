
void __thiscall FUN_005c1186(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0x10);
  *param_2 = param_1;
  param_2[1] = iVar1 - iVar2 >> 5;
  return;
}

