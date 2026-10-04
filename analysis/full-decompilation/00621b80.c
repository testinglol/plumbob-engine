
void FUN_00621b80(int *param_1,int *param_2,undefined4 *param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  uint local_1c;
  uint local_18;
  
  piVar3 = param_1;
  bVar10 = param_5 != 2;
  bVar11 = param_5 != 1;
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar7 = *(int *)(*param_1 + 0x14) - param_4;
  if (param_4 < iVar7) {
    iVar2 = param_4;
    iVar8 = param_4;
    do {
      for (; iVar2 < iVar1 - param_4; iVar2 = iVar2 + 1) {
        iVar4 = FUN_00622150(piVar3,iVar2,iVar8,param_3,param_4);
        if ((bVar10) && (4 < iVar4)) {
          iVar5 = *(int *)(*param_2 + 0x18) * iVar2;
          *(undefined4 *)
           (((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + param_2[2] * iVar8 + param_2[1]) = *param_3
          ;
        }
        if (((bVar11) && (iVar4 < 4)) &&
           (iVar4 = *(int *)(*piVar3 + 0x18) * iVar2,
           iVar4 = FUN_006220a0(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar8 +
                                piVar3[1],param_3), iVar4 != 0)) {
          param_5 = 0;
          param_1 = (int *)0x0;
          local_1c = 0;
          local_18 = 0;
          iVar4 = FUN_006220d0(piVar3,iVar2,iVar8,0xffffffff,0xffffffff,param_3,1);
          if (iVar4 == 0) {
            iVar5 = *(int *)(*piVar3 + 0x18) * (iVar2 + -1);
            pbVar6 = (byte *)(((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + (iVar8 + -1) * piVar3[2]
                             + piVar3[1]);
            param_5 = (uint)pbVar6[3];
            param_1 = (int *)(uint)pbVar6[2];
            local_1c = (uint)pbVar6[1];
            local_18 = (uint)*pbVar6;
          }
          uVar9 = (uint)(iVar4 == 0);
          iVar4 = FUN_006220d0(piVar3,iVar2,iVar8,0,0xffffffff,param_3,1);
          if (iVar4 == 0) {
            iVar4 = *(int *)(*piVar3 + 0x18) * iVar2;
            pbVar6 = (byte *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + (iVar8 + -1) * piVar3[2]
                             + piVar3[1]);
            param_5 = param_5 + pbVar6[3];
            param_1 = (int *)((int)param_1 + (uint)pbVar6[2]);
            local_1c = local_1c + pbVar6[1];
            local_18 = local_18 + *pbVar6;
            uVar9 = uVar9 + 1;
          }
          iVar4 = FUN_006220d0(piVar3,iVar2,iVar8,1,0xffffffff,param_3,1);
          if (iVar4 == 0) {
            iVar4 = *(int *)(*piVar3 + 0x18) * (iVar2 + 1);
            pbVar6 = (byte *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + (iVar8 + -1) * piVar3[2]
                             + piVar3[1]);
            param_5 = param_5 + pbVar6[3];
            param_1 = (int *)((int)param_1 + (uint)pbVar6[2]);
            local_1c = local_1c + pbVar6[1];
            local_18 = local_18 + *pbVar6;
            uVar9 = uVar9 + 1;
          }
          iVar4 = FUN_006220d0(piVar3,iVar2,iVar8,0xffffffff,0,param_3,1);
          if (iVar4 == 0) {
            iVar4 = *(int *)(*piVar3 + 0x18) * (iVar2 + -1);
            pbVar6 = (byte *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar8 +
                             piVar3[1]);
            param_5 = param_5 + pbVar6[3];
            param_1 = (int *)((int)param_1 + (uint)pbVar6[2]);
            local_1c = local_1c + pbVar6[1];
            local_18 = local_18 + *pbVar6;
            uVar9 = uVar9 + 1;
          }
          iVar4 = FUN_006220d0(piVar3,iVar2,iVar8,1,0,param_3,1);
          if (iVar4 == 0) {
            iVar4 = *(int *)(*piVar3 + 0x18) * (iVar2 + 1);
            pbVar6 = (byte *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar8 +
                             piVar3[1]);
            param_5 = param_5 + pbVar6[3];
            param_1 = (int *)((int)param_1 + (uint)pbVar6[2]);
            local_1c = local_1c + pbVar6[1];
            local_18 = local_18 + *pbVar6;
            uVar9 = uVar9 + 1;
          }
          iVar4 = FUN_006220d0(piVar3,iVar2,iVar8,0xffffffff,1,param_3,1);
          if (iVar4 == 0) {
            iVar4 = *(int *)(*piVar3 + 0x18) * (iVar2 + -1);
            pbVar6 = (byte *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + (iVar8 + 1) * piVar3[2] +
                             piVar3[1]);
            param_5 = param_5 + pbVar6[3];
            param_1 = (int *)((int)param_1 + (uint)pbVar6[2]);
            local_1c = local_1c + pbVar6[1];
            local_18 = local_18 + *pbVar6;
            uVar9 = uVar9 + 1;
          }
          iVar4 = FUN_006220d0(piVar3,iVar2,iVar8,0,1,param_3,1);
          if (iVar4 == 0) {
            iVar4 = *(int *)(*piVar3 + 0x18) * iVar2;
            pbVar6 = (byte *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + (iVar8 + 1) * piVar3[2] +
                             piVar3[1]);
            param_5 = param_5 + pbVar6[3];
            param_1 = (int *)((int)param_1 + (uint)pbVar6[2]);
            local_1c = local_1c + pbVar6[1];
            local_18 = local_18 + *pbVar6;
            uVar9 = uVar9 + 1;
          }
          iVar4 = FUN_006220d0(piVar3,iVar2,iVar8,1,1,param_3,1);
          if (iVar4 == 0) {
            iVar4 = *(int *)(*piVar3 + 0x18) * (iVar2 + 1);
            pbVar6 = (byte *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + (iVar8 + 1) * piVar3[2] +
                             piVar3[1]);
            param_5 = param_5 + pbVar6[3];
            param_1 = (int *)((int)param_1 + (uint)pbVar6[2]);
            local_1c = local_1c + pbVar6[1];
            local_18 = local_18 + *pbVar6;
            uVar9 = uVar9 + 1;
          }
          iVar4 = *(int *)(*param_2 + 0x18) * iVar2;
          *(uint *)(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + param_2[2] * iVar8 + param_2[1]) =
               CONCAT31(CONCAT21(CONCAT11((char)(param_5 / uVar9),(char)((uint)param_1 / uVar9)),
                                 (char)(local_1c / uVar9)),(char)(local_18 / uVar9));
        }
      }
      iVar8 = iVar8 + 1;
      iVar2 = param_4;
    } while (iVar8 < iVar7);
  }
  return;
}

