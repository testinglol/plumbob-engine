
uint __thiscall FUN_00411de1(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  uVar3 = FUN_005b8dba(*(undefined4 *)(param_2 + 4));
  return uVar3 % (uint)(iVar1 - iVar2 >> 2);
}

