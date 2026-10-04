
void FUN_00622260(int *param_1,int *param_2,undefined1 *param_3,int param_4,uint param_5)

{
  byte *pbVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint local_1c;
  uint local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  uint local_c;
  uint local_8;
  int local_4;
  
  piVar2 = param_1;
  local_c = (uint)(param_5 != 2);
  local_8 = (uint)(param_5 != 1);
  iVar5 = *(int *)(*param_1 + 0x14) - param_4;
  if (param_4 < iVar5) {
    iVar7 = *(int *)(*param_1 + 0x10) - param_4;
    iVar9 = param_4;
    local_10 = iVar7;
    local_4 = iVar5;
    do {
      iVar10 = param_4;
      if (param_4 < iVar7) {
        do {
          iVar5 = FUN_00622880(piVar2,iVar10,iVar9,param_3,param_4);
          if ((local_c != 0) && (4 < iVar5)) {
            iVar7 = *(int *)(*param_2 + 0x18) * iVar10;
            *(undefined1 *)
             (((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3) + param_2[2] * iVar9 + param_2[1]) =
                 *param_3;
          }
          if (((local_8 != 0) && (iVar5 < 4)) &&
             (iVar5 = *(int *)(*piVar2 + 0x18) * iVar10,
             iVar5 = FUN_006227e0(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + piVar2[2] * iVar9 +
                                  piVar2[1],param_3), iVar5 != 0)) {
            param_5 = 0;
            param_1 = (int *)0x0;
            local_1c = 0;
            local_18 = 0;
            iVar5 = FUN_00622800(piVar2,iVar10,iVar9,0xffffffff,0xffffffff,param_3,1);
            if (iVar5 == 0) {
              iVar7 = *piVar2;
              iVar4 = *(int *)(iVar7 + 0x18) * (iVar10 + -1);
              uVar8 = (uint)*(byte *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) +
                                      (iVar9 + -1) * piVar2[2] + piVar2[1]);
              param_1 = (int *)(uint)*(byte *)(iVar7 + 0x2a + uVar8 * 4);
              pbVar1 = (byte *)(iVar7 + 0x28 + uVar8 * 4);
              param_5 = (uint)pbVar1[3];
              local_1c = (uint)pbVar1[1];
              local_18 = (uint)*pbVar1;
            }
            uVar8 = (uint)(iVar5 == 0);
            iVar5 = FUN_00622800(piVar2,iVar10,iVar9,0,0xffffffff,param_3,1);
            if (iVar5 == 0) {
              iVar5 = *(int *)(*piVar2 + 0x18) * iVar10;
              uVar6 = (uint)*(byte *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) +
                                      (iVar9 + -1) * piVar2[2] + piVar2[1]);
              pbVar1 = (byte *)(*piVar2 + 0x28 + uVar6 * 4);
              param_5 = param_5 + *(byte *)(*piVar2 + 0x2b + uVar6 * 4);
              param_1 = (int *)((int)param_1 + (uint)pbVar1[2]);
              local_1c = local_1c + pbVar1[1];
              local_18 = local_18 + *pbVar1;
              uVar8 = uVar8 + 1;
            }
            iVar5 = FUN_00622800(piVar2,iVar10,iVar9,1,0xffffffff,param_3,1);
            if (iVar5 == 0) {
              iVar5 = *(int *)(*piVar2 + 0x18) * (iVar10 + 1);
              uVar6 = (uint)*(byte *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) +
                                      (iVar9 + -1) * piVar2[2] + piVar2[1]);
              pbVar1 = (byte *)(*piVar2 + 0x28 + uVar6 * 4);
              param_5 = param_5 + *(byte *)(*piVar2 + 0x2b + uVar6 * 4);
              param_1 = (int *)((int)param_1 + (uint)pbVar1[2]);
              local_1c = local_1c + pbVar1[1];
              local_18 = local_18 + *pbVar1;
              uVar8 = uVar8 + 1;
            }
            iVar5 = FUN_00622800(piVar2,iVar10,iVar9,0xffffffff,0,param_3,1);
            if (iVar5 == 0) {
              iVar5 = *(int *)(*piVar2 + 0x18) * (iVar10 + -1);
              uVar6 = (uint)*(byte *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + piVar2[2] * iVar9
                                     + piVar2[1]);
              pbVar1 = (byte *)(*piVar2 + 0x28 + uVar6 * 4);
              param_5 = param_5 + *(byte *)(*piVar2 + 0x2b + uVar6 * 4);
              param_1 = (int *)((int)param_1 + (uint)pbVar1[2]);
              local_1c = local_1c + pbVar1[1];
              local_18 = local_18 + *pbVar1;
              uVar8 = uVar8 + 1;
            }
            iVar5 = FUN_00622800(piVar2,iVar10,iVar9,1,0,param_3,1);
            if (iVar5 == 0) {
              iVar5 = *(int *)(*piVar2 + 0x18) * (iVar10 + 1);
              uVar6 = (uint)*(byte *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + piVar2[2] * iVar9
                                     + piVar2[1]);
              pbVar1 = (byte *)(*piVar2 + 0x28 + uVar6 * 4);
              param_5 = param_5 + *(byte *)(*piVar2 + 0x2b + uVar6 * 4);
              param_1 = (int *)((int)param_1 + (uint)pbVar1[2]);
              local_1c = local_1c + pbVar1[1];
              local_18 = local_18 + *pbVar1;
              uVar8 = uVar8 + 1;
            }
            iVar5 = FUN_00622800(piVar2,iVar10,iVar9,0xffffffff,1,param_3,1);
            if (iVar5 == 0) {
              iVar5 = *(int *)(*piVar2 + 0x18) * (iVar10 + -1);
              uVar6 = (uint)*(byte *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) +
                                      (iVar9 + 1) * piVar2[2] + piVar2[1]);
              pbVar1 = (byte *)(*piVar2 + 0x28 + uVar6 * 4);
              param_5 = param_5 + *(byte *)(*piVar2 + 0x2b + uVar6 * 4);
              param_1 = (int *)((int)param_1 + (uint)pbVar1[2]);
              local_1c = local_1c + pbVar1[1];
              local_18 = local_18 + *pbVar1;
              uVar8 = uVar8 + 1;
            }
            iVar5 = FUN_00622800(piVar2,iVar10,iVar9,0,1,param_3,1);
            if (iVar5 == 0) {
              iVar5 = *(int *)(*piVar2 + 0x18) * iVar10;
              uVar6 = (uint)*(byte *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) +
                                      (iVar9 + 1) * piVar2[2] + piVar2[1]);
              pbVar1 = (byte *)(*piVar2 + 0x28 + uVar6 * 4);
              param_5 = param_5 + *(byte *)(*piVar2 + 0x2b + uVar6 * 4);
              param_1 = (int *)((int)param_1 + (uint)pbVar1[2]);
              local_1c = local_1c + pbVar1[1];
              local_18 = local_18 + *pbVar1;
              uVar8 = uVar8 + 1;
            }
            iVar5 = FUN_00622800(piVar2,iVar10,iVar9,1,1,param_3,1);
            if (iVar5 == 0) {
              iVar5 = *(int *)(*piVar2 + 0x18) * (iVar10 + 1);
              uVar6 = (uint)*(byte *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) +
                                      (iVar9 + 1) * piVar2[2] + piVar2[1]);
              pbVar1 = (byte *)(*piVar2 + 0x28 + uVar6 * 4);
              param_5 = param_5 + *(byte *)(*piVar2 + 0x2b + uVar6 * 4);
              param_1 = (int *)((int)param_1 + (uint)pbVar1[2]);
              local_1c = local_1c + pbVar1[1];
              local_18 = local_18 + *pbVar1;
              uVar8 = uVar8 + 1;
            }
            local_11 = (undefined1)(param_5 / uVar8);
            local_12 = (undefined1)((uint)param_1 / uVar8);
            local_13 = (undefined1)(local_1c / uVar8);
            local_14 = (undefined1)(local_18 / uVar8);
            uVar3 = FUN_00622990(&local_14,*piVar2 + 0x28);
            iVar5 = *(int *)(*param_2 + 0x18) * iVar10;
            *(undefined1 *)
             (((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + param_2[2] * iVar9 + param_2[1]) = uVar3;
          }
          iVar10 = iVar10 + 1;
          iVar5 = local_4;
          iVar7 = local_10;
        } while (iVar10 < local_10);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar5);
  }
  return;
}

