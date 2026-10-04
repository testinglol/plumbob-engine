
bool __thiscall FUN_00603ffa(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = (uint)((*(int *)(param_1 + 0xd4) - *(int *)(param_1 + 0xd0)) / 0x1c) <= param_4;
  if (bVar3) {
    FUN_005d49b7(&DAT_006de560);
    FUN_005d49b7(&DAT_006de560);
  }
  else {
    iVar2 = param_4 * 0x1c;
    piVar1 = (int *)(iVar2 + 0x10 + *(int *)(param_1 + 0xd0));
    FUN_005b8775(*piVar1,*(int *)(iVar2 + 0x14 + *(int *)(param_1 + 0xd0)) - *piVar1);
    piVar1 = (int *)(iVar2 + 4 + *(int *)(param_1 + 0xd0));
    FUN_005b8775(*piVar1,*(int *)(iVar2 + 8 + *(int *)(param_1 + 0xd0)) - *piVar1);
  }
  return !bVar3;
}

