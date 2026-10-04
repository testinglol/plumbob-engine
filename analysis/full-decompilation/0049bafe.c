
void FUN_0049bafe(int param_1,int param_2,int *param_3,undefined4 param_4,int *param_5)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  undefined4 uVar13;
  int local_14;
  int local_8;
  
  piVar1 = param_3;
  if (((param_3 != (int *)0x0) && (cVar2 = (**(code **)(*param_3 + 0x20))(0x40), cVar2 != '\0')) &&
     (cVar2 = FUN_004b465e(), cVar2 != '\0')) {
    if (param_5 == (int *)0x0) {
      iVar9 = param_3[5];
      iVar11 = param_3[6];
      iVar3 = param_3[7];
      local_14 = param_3[8];
    }
    else {
      iVar9 = *param_5;
      iVar11 = param_5[1];
      iVar3 = param_5[2];
      local_14 = param_5[3];
    }
    local_8 = 0;
    param_5 = (int *)0x0;
    local_14 = local_14 - iVar11;
    iVar3 = iVar3 - iVar9;
    iVar11 = 0;
    iVar9 = 0;
    if (param_1 < DAT_006f0bc2) {
      local_8 = DAT_006f0bc2 - param_1;
    }
    if ((int)DAT_006f0bc6 <= iVar3 + param_1) {
      param_5 = (int *)((iVar3 - DAT_006f0bc6) + 1 + param_1);
    }
    if (param_2 < DAT_006f0bc0) {
      iVar11 = DAT_006f0bc0 - param_2;
    }
    if ((int)DAT_006f0bc4 <= local_14 + param_2) {
      iVar9 = (local_14 - DAT_006f0bc4) + 1 + param_2;
    }
    iVar3 = iVar3 - ((int)param_5 + local_8);
    local_14 = local_14 - (iVar9 + iVar11);
    param_2 = param_2 + iVar11;
    iVar10 = DAT_006f0bbc / 2;
    param_5 = (int *)(DAT_006f0bcc + (param_2 * iVar10 + local_8 + param_1) * 2);
    iVar9 = DAT_006f0bd4 / 2;
    param_1 = DAT_006f0bd0 + (param_2 * iVar9 + local_8 + param_1) * 2;
    uVar4 = (**(code **)(*param_3 + 0xd0))();
    uVar4 = uVar4 >> 1;
    iVar5 = (**(code **)(*param_3 + 0xcc))();
    puVar12 = (ushort *)(iVar5 + (uVar4 * iVar11 + local_8) * 2);
    uVar7 = param_3[9];
    if (((uint)param_3[10] >> 1 & 1) == 0) {
      param_3 = (int *)param_2;
      local_8 = local_14;
      if (0 < local_14) {
        do {
          uVar13 = param_4;
          iVar11 = (int)param_3;
          FUN_004cebb0(param_4,param_3);
          uVar7 = FUN_0049a73d(uVar13,iVar11);
          if (0 < iVar3) {
            puVar8 = puVar12;
            local_14 = iVar3;
            do {
              if (uVar7 <= *(ushort *)((int)puVar8 + (param_1 - (int)puVar12))) {
                *(ushort *)((int)puVar8 + ((int)param_5 - (int)puVar12)) = *puVar8;
              }
              puVar8 = puVar8 + 1;
              local_14 = local_14 + -1;
            } while (local_14 != 0);
          }
          local_8 = local_8 + -1;
          param_5 = (int *)((int)param_5 + iVar10 * 2);
          param_1 = param_1 + iVar9 * 2;
          puVar12 = puVar12 + uVar4;
          param_3 = (int *)((int)param_3 + 1);
        } while (local_8 != 0);
      }
    }
    else {
      param_3 = (int *)param_2;
      if (0 < local_14) {
        do {
          uVar13 = param_4;
          iVar11 = (int)param_3;
          FUN_004cebb0(param_4,param_3);
          uVar6 = FUN_0049a73d(uVar13,iVar11);
          if (0 < iVar3) {
            puVar8 = puVar12;
            local_8 = iVar3;
            do {
              if ((*puVar8 != uVar7) &&
                 (uVar6 <= *(ushort *)((param_1 - (int)puVar12) + (int)puVar8))) {
                *(ushort *)(((int)param_5 - (int)puVar12) + (int)puVar8) = *puVar8;
              }
              puVar8 = puVar8 + 1;
              local_8 = local_8 + -1;
            } while (local_8 != 0);
          }
          local_14 = local_14 + -1;
          param_5 = (int *)((int)param_5 + iVar10 * 2);
          param_1 = param_1 + iVar9 * 2;
          puVar12 = puVar12 + uVar4;
          param_3 = (int *)((int)param_3 + 1);
        } while (local_14 != 0);
      }
    }
    (**(code **)(*piVar1 + 0x24))(0x40);
  }
  return;
}

