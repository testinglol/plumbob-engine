
uint __fastcall FUN_0040ff51(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_004096c2();
  uVar2 = FUN_005b8dba(uVar1);
  return uVar2 % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2);
}

