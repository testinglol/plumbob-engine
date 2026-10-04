
int * __thiscall FUN_00632520(int *param_1,char *param_2,char *param_3)

{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  size_t sVar7;
  int iVar8;
  int local_8;
  
  sVar4 = _strlen(param_2);
  sVar5 = _strlen(param_3);
  uVar2 = *(uint *)(*(int *)(*param_1 + 4) + 0x30 + (int)param_1);
  if (sVar5 + sVar4 < uVar2) {
    local_8 = (uVar2 - sVar5) - sVar4;
  }
  else {
    local_8 = 0;
  }
  if (((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0x24) & 10) == 0) &&
     (iVar6 = local_8 + -1, bVar3 = 0 < local_8, iVar8 = local_8, local_8 = iVar6, bVar3)) {
    do {
      iVar6 = FUN_0063268c(*(undefined1 *)((int)param_1 + *(int *)(*param_1 + 4) + 0x2c));
      if (iVar6 == -1) {
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        *puVar1 = *puVar1 | 6;
      }
      iVar8 = iVar8 + -1;
      local_8 = local_8 + -1;
    } while (iVar8 != 0);
  }
  if ((sVar4 != 0) &&
     (sVar7 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0x14))
                        (param_2,sVar4), sVar7 != sVar4)) {
    puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
    *puVar1 = *puVar1 | 6;
  }
  if (((*(byte *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) & 8) != 0) &&
     (iVar8 = local_8 + -1, bVar3 = 0 < local_8, iVar6 = local_8, local_8 = iVar8, bVar3)) {
    do {
      iVar8 = FUN_0063268c(*(undefined1 *)((int)param_1 + *(int *)(*param_1 + 4) + 0x2c));
      if (iVar8 == -1) {
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        *puVar1 = *puVar1 | 6;
      }
      iVar6 = iVar6 + -1;
      local_8 = local_8 + -1;
    } while (iVar6 != 0);
  }
  sVar4 = (**(code **)(**(int **)(*(int *)(*param_1 + 4) + 4 + (int)param_1) + 0x14))(param_3,sVar5)
  ;
  if (sVar4 != sVar5) {
    puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
    *puVar1 = *puVar1 | 6;
  }
  if (((*(byte *)(*(int *)(*param_1 + 4) + 0x24 + (int)param_1) & 2) != 0) && (0 < local_8)) {
    do {
      iVar6 = FUN_0063268c(*(undefined1 *)((int)param_1 + *(int *)(*param_1 + 4) + 0x2c));
      if (iVar6 == -1) {
        puVar1 = (uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1);
        *puVar1 = *puVar1 | 6;
      }
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return param_1;
}

