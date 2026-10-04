
undefined4 FUN_006105b0(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  
  piVar3 = param_1;
  iVar7 = 0;
  iVar8 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  if (0 < param_4) {
    local_2c = param_2 + param_4;
    iVar10 = -param_4;
    local_30 = param_4;
    do {
      local_30 = local_30 + -1;
      iVar4 = iVar10 + 1;
      if (iVar10 <= param_4) {
        param_1 = (int *)((param_4 - iVar4) + 2);
        iVar11 = param_2 + -2 + iVar4;
        do {
          if ((((-1 < iVar11) && (iVar9 = iVar10 + param_3, -1 < iVar9 + -1)) &&
              (iVar5 = *piVar3, iVar11 < *(int *)(iVar5 + 0x10))) &&
             (iVar9 + -1 < *(int *)(iVar5 + 0x14))) {
            iVar5 = (iVar11 + 1) * *(int *)(iVar5 + 0x18);
            uVar1 = *(uint *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar9 +
                             piVar3[1]);
            iVar8 = iVar8 + (uVar1 >> 0x18);
            local_40 = local_40 + (uVar1 >> 0x10 & 0xff);
            local_3c = local_3c + (uVar1 >> 8 & 0xff);
            local_38 = local_38 + (uVar1 & 0xff);
            iVar7 = iVar7 + 1;
          }
          iVar11 = iVar11 + 1;
          param_1 = (int *)((int)param_1 + -1);
        } while (param_1 != (int *)0x0);
      }
      if (iVar10 <= param_4) {
        param_1 = (int *)((param_4 - iVar4) + 2);
        iVar11 = param_2 + -2 + iVar4;
        do {
          if (((-1 < iVar11) && (iVar9 = local_30 + param_3, -1 < iVar9)) &&
             ((iVar5 = *piVar3, iVar11 < *(int *)(iVar5 + 0x10) && (iVar9 < *(int *)(iVar5 + 0x14)))
             )) {
            iVar5 = (iVar11 + 1) * *(int *)(iVar5 + 0x18);
            uVar1 = *(uint *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + (iVar9 + 1) * piVar3[2] +
                             piVar3[1]);
            iVar8 = iVar8 + (uVar1 >> 0x18);
            local_40 = local_40 + (uVar1 >> 0x10 & 0xff);
            local_3c = local_3c + (uVar1 >> 8 & 0xff);
            local_38 = local_38 + (uVar1 & 0xff);
            iVar7 = iVar7 + 1;
          }
          iVar11 = iVar11 + 1;
          param_1 = (int *)((int)param_1 + -1);
        } while (param_1 != (int *)0x0);
      }
      if (iVar4 <= local_30) {
        iVar11 = iVar10 + -1 + param_2;
        iVar5 = param_3 + iVar4;
        iVar9 = iVar4;
        do {
          if (((-1 < iVar11) && (iVar6 = iVar9 + -1 + param_3, -1 < iVar6)) &&
             ((iVar2 = *piVar3, iVar11 < *(int *)(iVar2 + 0x10) && (iVar6 < *(int *)(iVar2 + 0x14)))
             )) {
            iVar6 = (iVar10 + param_2) * *(int *)(iVar2 + 0x18);
            uVar1 = *(uint *)(((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar5 +
                             piVar3[1]);
            iVar8 = iVar8 + (uVar1 >> 0x18);
            local_40 = local_40 + (uVar1 >> 0x10 & 0xff);
            local_3c = local_3c + (uVar1 >> 8 & 0xff);
            local_38 = local_38 + (uVar1 & 0xff);
            iVar7 = iVar7 + 1;
          }
          iVar9 = iVar9 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar9 <= local_30);
      }
      if (iVar4 <= local_30) {
        iVar11 = param_2 + -1 + param_4;
        iVar10 = iVar4 + param_3;
        iVar9 = iVar4;
        do {
          if ((((-1 < iVar11) && (iVar5 = iVar9 + -1 + param_3, -1 < iVar5)) &&
              (iVar6 = *piVar3, iVar11 < *(int *)(iVar6 + 0x10))) &&
             (iVar5 < *(int *)(iVar6 + 0x14))) {
            iVar5 = *(int *)(iVar6 + 0x18) * local_2c;
            uVar1 = *(uint *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar10 +
                             piVar3[1]);
            iVar8 = iVar8 + (uVar1 >> 0x18);
            local_40 = local_40 + (uVar1 >> 0x10 & 0xff);
            local_3c = local_3c + (uVar1 >> 8 & 0xff);
            local_38 = local_38 + (uVar1 & 0xff);
            iVar7 = iVar7 + 1;
          }
          iVar9 = iVar9 + 1;
          iVar10 = iVar10 + 1;
        } while (iVar9 <= local_30);
      }
      param_4 = param_4 + -1;
      local_2c = local_2c + -1;
      iVar10 = iVar4;
    } while (0 < param_4);
  }
  return CONCAT31(CONCAT21(CONCAT11((char)(iVar8 / iVar7),(char)(local_40 / iVar7)),
                           (char)(local_3c / iVar7)),(char)(local_38 / iVar7));
}

