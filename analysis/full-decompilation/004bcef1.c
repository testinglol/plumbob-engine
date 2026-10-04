
void FUN_004bcef1(uint *param_1,byte *param_2,int param_3,uint *param_4,undefined4 *param_5,
                 undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  undefined4 *puVar14;
  int local_18;
  uint local_14;
  
  DAT_006f0678 = 0;
  DAT_006f067c = 0;
  DAT_006f0680 = 0;
  DAT_006f0684 = 0;
  DAT_006f0688 = 0;
  uVar8 = (int)param_1 * 2;
  puVar14 = (undefined4 *)(param_3 + (int)param_1 * -2 + 2);
  puVar10 = (undefined4 *)((int)param_4 + (int)param_1 * -2 + 2);
  iVar3 = (int)param_1 >> 5;
  uVar7 = (uint)param_1;
  if (iVar3 != 0) {
    uVar7 = (int)param_1 + iVar3 * -0x20;
  }
  iVar12 = (int)param_1 - 1;
  uVar11 = 1 << ((byte)(uVar7 - 1) & 0x1f);
  pbVar6 = param_2;
  local_14 = uVar7;
  if (-1 < (int)(uVar7 - 1)) {
    do {
      iVar4 = (int)*(short *)((int)param_7 + (uint)*param_2 * 2) + (int)param_6;
      *(short *)((int)&DAT_006f068c + iVar12 * 2) = (short)iVar4;
      pbVar6 = param_2 + (int)param_8;
      *(undefined2 *)((int)&DAT_006f07cc + iVar12 * 2) =
           *(undefined2 *)((int)param_5 + (uint)param_2[1] * 2);
      if (iVar4 <= (int)(uint)*(ushort *)((int)puVar10 + iVar12 * 2)) {
        (&DAT_006f0678)[iVar3] = (&DAT_006f0678)[iVar3] | uVar11;
      }
      uVar11 = uVar11 >> 1;
      iVar12 = iVar12 + -1;
      local_14 = local_14 - 1;
      param_2 = pbVar6;
    } while (local_14 != 0);
  }
  if (-1 < iVar3 + -1) {
    param_4 = &DAT_006f0678 + iVar3 + -1;
    local_18 = iVar3;
    do {
      param_2 = (byte *)0x80000000;
      local_14 = 0x20;
      do {
        iVar4 = (int)*(short *)((int)param_7 + (uint)*pbVar6 * 2) + (int)param_6;
        *(short *)((int)&DAT_006f068c + iVar12 * 2) = (short)iVar4;
        pbVar1 = pbVar6 + 1;
        pbVar6 = pbVar6 + (int)param_8;
        *(undefined2 *)((int)&DAT_006f07cc + iVar12 * 2) =
             *(undefined2 *)((int)param_5 + (uint)*pbVar1 * 2);
        if (iVar4 <= (int)(uint)*(ushort *)((int)puVar10 + iVar12 * 2)) {
          *param_4 = *param_4 | (uint)param_2;
        }
        param_2 = (byte *)((uint)param_2 >> 1);
        iVar12 = iVar12 + -1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
      param_4 = param_4 + -1;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
  }
  bVar2 = true;
  iVar12 = 0;
  if (0 < iVar3) {
    piVar13 = &DAT_006f0678;
    iVar12 = iVar3;
    do {
      if ((bVar2) && (*piVar13 == -1)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      piVar13 = piVar13 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    iVar12 = iVar3;
    if (!bVar2) goto LAB_004bd0b6;
  }
  if ((1 << ((byte)uVar7 & 0x1f)) + -1 == (&DAT_006f0678)[iVar12]) {
    if ((int)param_1 < 0x10) {
      puVar9 = &DAT_006f068c;
      for (uVar7 = ((uint)param_1 & 0x7fffffff) >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (uVar7 = uVar8 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      puVar10 = &DAT_006f07cc;
      for (uVar7 = ((uint)param_1 & 0x7fffffff) >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar14 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar14 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      return;
    }
    FUN_005a92b0(puVar10,&DAT_006f068c,uVar8);
    FUN_005a92b0(puVar14,&DAT_006f07cc,uVar8);
    return;
  }
LAB_004bd0b6:
  param_4 = (uint *)0x0;
  iVar12 = 0;
  if (0 < iVar3) {
    param_1 = &DAT_006f0678;
    param_5 = &DAT_006f07cc;
    param_6 = &DAT_006f068c;
    param_7 = puVar10;
    param_8 = puVar14;
    local_18 = iVar3;
    do {
      if (*param_1 == 0xffffffff) {
        FUN_005a92b0(param_7,param_6,0x40);
        FUN_005a92b0(param_8,param_5,0x40);
      }
      else {
        param_2 = (byte *)0x0;
        puVar9 = param_7;
        do {
          if ((*param_1 & 1 << ((byte)param_2 & 0x1f)) != 0) {
            *(undefined2 *)puVar9 =
                 *(undefined2 *)(((int)&DAT_006f068c - (int)puVar10) + (int)puVar9);
            *(undefined2 *)(((int)puVar14 - (int)puVar10) + (int)puVar9) =
                 *(undefined2 *)(((int)&DAT_006f07cc - (int)puVar10) + (int)puVar9);
          }
          param_2 = (byte *)((int)param_2 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 2);
        } while ((int)param_2 < 0x20);
      }
      param_8 = param_8 + 0x10;
      param_7 = param_7 + 0x10;
      param_6 = param_6 + 0x10;
      param_5 = param_5 + 0x10;
      param_4 = (uint *)((int)param_4 + 0x20);
      param_1 = param_1 + 1;
      local_18 = local_18 + -1;
      iVar12 = iVar3;
    } while (local_18 != 0);
  }
  param_2 = (byte *)0x0;
  if (0 < (int)uVar7) {
    puVar5 = (undefined2 *)((int)puVar10 + (int)param_4 * 2);
    do {
      if (((&DAT_006f0678)[iVar12] & 1 << ((byte)param_2 & 0x1f)) != 0) {
        *puVar5 = *(undefined2 *)((int)puVar5 + ((int)&DAT_006f068c - (int)puVar10));
        *(undefined2 *)((int)puVar5 + ((int)puVar14 - (int)puVar10)) =
             *(undefined2 *)((int)puVar5 + ((int)&DAT_006f07cc - (int)puVar10));
      }
      param_2 = (byte *)((int)param_2 + 1);
      puVar5 = puVar5 + 1;
    } while ((int)param_2 < (int)uVar7);
  }
  return;
}

