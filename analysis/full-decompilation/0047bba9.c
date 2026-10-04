
void FUN_0047bba9(int param_1,byte param_2,byte param_3,byte param_4)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  bool bVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  ushort uVar12;
  int iVar13;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar6 = param_1;
  local_10 = (int)((uint)param_3 * *(int *)(param_1 + 4) * *(int *)(param_1 + 8)) / 100;
  sVar1 = 0;
  if (0 < local_10) {
    local_14 = (uint)param_2;
    do {
      iVar13 = *(int *)(iVar6 + 8);
      uVar8 = FUN_0046f556();
      iVar3 = *(int *)(iVar6 + 4);
      uVar9 = FUN_0046f556();
      uVar10 = FUN_0046f556();
      param_1._0_2_ = CONCAT11((char)(uVar10 % local_14) + param_2,(undefined1)param_1);
      piVar11 = (int *)FUN_0047c7b7(&local_18,(int)(short)((short)(uVar8 % (iVar13 - 1U)) + 1));
      sVar1 = sVar1 + 1;
      *(int *)(*piVar11 + (short)((short)(uVar9 % (iVar3 - 1U)) + 1) * 4) = param_1;
    } while (sVar1 < local_10);
  }
  bVar5 = false;
  do {
    sVar1 = 0;
    if (0 < *(int *)(iVar6 + 8)) {
      do {
        local_c = 0;
        if (0 < *(int *)(iVar6 + 4)) {
          local_8 = 0;
          do {
            bVar5 = true;
            piVar11 = (int *)FUN_0047c7b7(local_1c,(int)sVar1);
            iVar13 = local_8 * 4;
            bVar2 = *(byte *)(iVar13 + 1 + *piVar11);
            uVar12 = (ushort)bVar2;
            if ((int)sVar1 < *(int *)(iVar6 + 8) + -1) {
              local_18 = sVar1 + 1;
              piVar11 = (int *)FUN_0047c7b7(local_20,local_18);
              local_10 = (int)(short)uVar12;
              bVar7 = *(byte *)(*piVar11 + 1 + iVar13);
              local_14 = (uint)param_4;
              bVar4 = param_4;
              if ((int)local_14 < (short)(ushort)bVar7 - local_10) {
LAB_0047bcd1:
                bVar7 = bVar4 + bVar2;
                bVar5 = false;
              }
              else if ((int)local_14 < local_10 - (short)(ushort)bVar7) {
                bVar4 = -param_4;
                goto LAB_0047bcd1;
              }
              param_1._0_2_ = CONCAT11(bVar7,(undefined1)param_1);
              piVar11 = (int *)FUN_0047c7b7(local_24,local_18);
              *(int *)(*piVar11 + iVar13) = param_1;
            }
            if (local_8 < *(int *)(iVar6 + 4) + -1) {
              piVar11 = (int *)FUN_0047c7b7(local_28,(int)sVar1);
              bVar7 = *(byte *)(iVar13 + 5 + *piVar11);
              bVar4 = param_4;
              if ((int)(uint)param_4 < (int)(short)(ushort)bVar7 - (int)(short)uVar12) {
LAB_0047bd3a:
                bVar7 = bVar4 + bVar2;
                bVar5 = false;
              }
              else if ((int)(uint)param_4 < (int)(short)uVar12 - (int)(short)(ushort)bVar7) {
                bVar4 = -param_4;
                goto LAB_0047bd3a;
              }
              param_1._0_2_ = CONCAT11(bVar7,(undefined1)param_1);
              piVar11 = (int *)FUN_0047c7b7(local_2c,(int)sVar1);
              *(int *)(*piVar11 + 4 + local_8 * 4) = param_1;
            }
            local_c = local_c + 1;
            local_8 = (int)(short)local_c;
          } while (local_8 < *(int *)(iVar6 + 4));
        }
        sVar1 = sVar1 + 1;
      } while ((int)sVar1 < *(int *)(iVar6 + 8));
    }
    if (bVar5) {
      return;
    }
  } while( true );
}

