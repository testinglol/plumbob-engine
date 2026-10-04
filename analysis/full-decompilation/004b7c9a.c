
void FUN_004b7c9a(int *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 *puVar8;
  byte *pbVar9;
  int local_18;
  int local_14;
  byte *local_c;
  
  if (((DAT_006f065c != (int *)0x0) && (DAT_006f0660 != (int *)0x0)) &&
     (cVar3 = (**(code **)(*DAT_006f065c + 0x20))(0x40), cVar3 != '\0')) {
    cVar3 = (**(code **)(*DAT_006f0660 + 0x20))(0x40);
    if (cVar3 == '\0') {
      (**(code **)(*DAT_006f065c + 0x24))(0x40);
      return;
    }
    iVar1 = param_1[7];
    iVar2 = param_1[8];
    iVar7 = (iVar1 - DAT_006f065c[7]) + -3;
    local_18 = (iVar2 - DAT_006f065c[8]) + -3;
    iVar5 = (**(code **)(*param_1 + 0xcc))();
    uVar6 = (**(code **)(*param_1 + 0xd0))();
    uVar6 = uVar6 >> 1;
    param_1 = (int *)(iVar5 + (uVar6 * local_18 + iVar7) * 2);
    (**(code **)(*DAT_006f065c + 0xcc))();
    (**(code **)(*DAT_006f065c + 0xd0))();
    local_c = (byte *)(**(code **)(*DAT_006f0660 + 0xcc))();
    iVar5 = (**(code **)(*DAT_006f0660 + 0xd0))();
    iVar7 = (iVar1 + -3) - iVar7;
    local_18 = (iVar2 + -3) - local_18;
    if (*(int *)(DAT_006e486c + 0x34) == 2) {
      if (0 < local_18) {
        do {
          puVar8 = (undefined2 *)param_1;
          pbVar9 = local_c;
          local_14 = iVar7;
          if (0 < iVar7) {
            do {
              if (7 < *pbVar9) {
                uVar4 = FUN_0049a775(*pbVar9 >> 3);
                *puVar8 = uVar4;
              }
              pbVar9 = pbVar9 + 1;
              puVar8 = puVar8 + 1;
              local_14 = local_14 + -1;
            } while (local_14 != 0);
          }
          param_1 = (int *)((int)param_1 + uVar6 * 2);
          local_c = local_c + iVar5;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
    }
    else {
      local_14 = local_18;
      if (0 < local_18) {
        do {
          pbVar9 = local_c;
          puVar8 = (undefined2 *)param_1;
          local_18 = iVar7;
          if (0 < iVar7) {
            do {
              if (7 < *pbVar9) {
                uVar4 = FUN_0049a996(*pbVar9 >> 3);
                *puVar8 = uVar4;
              }
              pbVar9 = pbVar9 + 1;
              puVar8 = puVar8 + 1;
              local_18 = local_18 + -1;
            } while (local_18 != 0);
          }
          param_1 = (int *)((int)param_1 + uVar6 * 2);
          local_c = local_c + iVar5;
          local_14 = local_14 + -1;
        } while (local_14 != 0);
      }
    }
    (**(code **)(*DAT_006f065c + 0x24))(0x40);
    (**(code **)(*DAT_006f0660 + 0x24))(0x40);
  }
  return;
}

