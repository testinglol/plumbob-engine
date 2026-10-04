
void FUN_0047b96c(int param_1,byte param_2,undefined4 param_3,uint param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  int local_8;
  
  iVar4 = param_1;
  uVar6 = (int)((param_4 & 0xff) * *(int *)(param_1 + 4) * *(int *)(param_1 + 8)) / 100;
  if (0 < (int)uVar6) {
    do {
      param_4 = uVar6;
      uVar6 = *(uint *)(iVar4 + 8);
      uVar7 = FUN_0046f556();
      uVar2 = *(uint *)(iVar4 + 4);
      uVar8 = FUN_0046f556();
      piVar9 = (int *)FUN_0047c7b7(&param_1,uVar7 % uVar6);
      param_4 = param_4 - 1;
      *(undefined4 *)(*piVar9 + (uVar8 % uVar2) * 4) = param_3;
      uVar6 = param_4;
    } while (param_4 != 0);
  }
  cVar5 = (char)param_5;
  bVar1 = (char)param_5 - 1;
  param_5 = CONCAT31(param_5._1_3_,bVar1);
  if (cVar5 != '\0') {
    iVar10 = bVar1 + 1;
    do {
      iVar11 = 0;
      local_8 = iVar10;
      if (0 < *(int *)(iVar4 + 8)) {
        do {
          param_1 = 0;
          if (0 < *(int *)(iVar4 + 4)) {
            do {
              piVar9 = (int *)FUN_0047c7b7(local_c,iVar11);
              param_4 = 0;
              iVar10 = param_1 * 4;
              param_5 = CONCAT22(param_5._2_2_,(ushort)*(byte *)(iVar10 + 1 + *piVar9));
              bVar3 = iVar11 < *(int *)(iVar4 + 8) + -1;
              if (bVar3) {
                piVar9 = (int *)FUN_0047c7b7(local_10,iVar11 + 1);
                param_5 = param_5 + CONCAT22((short)((uint)*piVar9 >> 0x10),
                                             (ushort)*(byte *)(*piVar9 + 1 + iVar10));
              }
              param_4 = (uint)bVar3;
              if (param_1 < *(int *)(iVar4 + 4) + -1) {
                piVar9 = (int *)FUN_0047c7b7(local_14,iVar11);
                param_5 = param_5 + CONCAT22((short)((uint)*piVar9 >> 0x10),
                                             (ushort)*(byte *)(*piVar9 + 5 + iVar10));
                param_4 = param_4 + 1;
              }
              if (0 < iVar11) {
                piVar9 = (int *)FUN_0047c7b7(local_18,iVar11 + -1);
                param_5 = param_5 + CONCAT22((short)((uint)*piVar9 >> 0x10),
                                             (ushort)*(byte *)(iVar10 + 1 + *piVar9));
                param_4 = param_4 + 1;
              }
              if (0 < param_1) {
                piVar9 = (int *)FUN_0047c7b7(local_1c,iVar11);
                param_5 = param_5 + CONCAT22((short)((uint)*piVar9 >> 0x10),
                                             (ushort)*(byte *)(iVar10 + -3 + *piVar9));
                param_4 = param_4 + 1;
              }
              param_3._0_2_ = CONCAT11((char)((short)param_5 / (short)param_4),(undefined1)param_3);
              piVar9 = (int *)FUN_0047c7b7(local_20,iVar11);
              param_1 = param_1 + 1;
              *(undefined4 *)(*piVar9 + iVar10) = param_3;
              iVar10 = local_8;
            } while (param_1 < *(int *)(iVar4 + 4));
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < *(int *)(iVar4 + 8));
      }
      iVar10 = iVar10 + -1;
      local_8 = iVar10;
    } while (iVar10 != 0);
  }
  iVar10 = 0;
  param_3._0_2_ = CONCAT11(param_2,(undefined1)param_3);
  if (0 < *(int *)(iVar4 + 8)) {
    do {
      iVar11 = 0;
      if (0 < *(int *)(iVar4 + 4)) {
        do {
          piVar9 = (int *)FUN_0047c7b7(&param_5,iVar10);
          if (param_2 < *(byte *)(*piVar9 + 1 + iVar11 * 4)) {
            piVar9 = (int *)FUN_0047c7b7(&param_4,iVar10);
            *(undefined4 *)(*piVar9 + iVar11 * 4) = param_3;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < *(int *)(iVar4 + 4));
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(iVar4 + 8));
  }
  return;
}

