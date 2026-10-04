
void FUN_004830d6(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  uint local_8;
  
  iVar5 = *param_2;
  local_8 = 0;
  iVar2 = param_2[1] - iVar5 >> 3;
  param_2 = (int *)iVar5;
  if (iVar2 != 1) {
    do {
      puVar6 = &DAT_006c08dc;
      puVar3 = &DAT_006c5bd0;
      iVar4 = (int)param_2;
      FUN_006321fb(local_8);
      uVar1 = FUN_006323d0(puVar3);
      FUN_00483161(uVar1,iVar4,puVar6);
      FUN_006323d0(puVar6);
      local_8 = local_8 + 1;
      param_2 = (int *)((int)param_2 + 8);
    } while (local_8 < iVar2 - 1U);
  }
  if (iVar2 != 0) {
    iVar5 = iVar5 + -8 + iVar2 * 8;
    puVar3 = &DAT_006c08dc;
    uVar1 = FUN_006323d0(&DAT_006c5bc8);
    FUN_00483161(uVar1,iVar5,puVar3);
    FUN_006323d0(puVar3);
  }
  return;
}

