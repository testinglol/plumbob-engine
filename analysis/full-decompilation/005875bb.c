
uint __fastcall FUN_005875bb(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  uVar3 = FUN_004096c2();
  uVar4 = FUN_005b8dba(uVar3);
  return uVar4 % (uint)(iVar1 - iVar2 >> 2);
}

