
void FUN_004bbf78(undefined4 *param_1,byte *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,uint *param_7,undefined4 *param_8)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  int *piVar11;
  int local_20;
  uint *local_10;
  uint local_c;
  int local_8;
  
  iVar5 = (int)param_7;
  DAT_006f0678 = 0;
  DAT_006f067c = 0;
  DAT_006f0680 = 0;
  DAT_006f0684 = 0;
  DAT_006f0688 = 0;
  iVar3 = (int)param_1 >> 5;
  if (iVar3 == 0) {
    local_c = (uint)param_1;
  }
  else {
    local_c = (int)param_1 + iVar3 * -0x20;
  }
  local_8 = 0;
  pbVar10 = param_2;
  if (0 < iVar3) {
    param_7 = &DAT_006f0678;
    do {
      param_2 = (byte *)0x0;
      iVar9 = local_8 << 6;
      do {
        iVar4 = (int)*(short *)(iVar5 + (uint)*pbVar10 * 2) + (int)param_6;
        *(short *)((int)&DAT_006f068c + iVar9) = (short)iVar4;
        pbVar1 = pbVar10 + 1;
        pbVar10 = pbVar10 + (int)param_8;
        *(undefined2 *)((int)&DAT_006f07cc + iVar9) =
             *(undefined2 *)((int)param_5 + (uint)*pbVar1 * 2);
        if (iVar4 <= (int)(uint)*(ushort *)(iVar9 + (int)param_4)) {
          *param_7 = *param_7 | 1 << ((byte)param_2 & 0x1f);
        }
        param_2 = (byte *)((int)param_2 + 1);
        iVar9 = iVar9 + 2;
      } while ((int)param_2 < 0x20);
      local_8 = local_8 + 1;
      param_7 = param_7 + 1;
    } while (local_8 < iVar3);
  }
  param_2 = (byte *)0x0;
  if (0 < (int)local_c) {
    iVar9 = local_8 << 6;
    do {
      iVar4 = (int)*(short *)(iVar5 + (uint)*pbVar10 * 2) + (int)param_6;
      *(short *)((int)&DAT_006f068c + iVar9) = (short)iVar4;
      pbVar1 = pbVar10 + 1;
      pbVar10 = pbVar10 + (int)param_8;
      *(undefined2 *)((int)&DAT_006f07cc + iVar9) =
           *(undefined2 *)((int)param_5 + (uint)*pbVar1 * 2);
      if (iVar4 <= (int)(uint)*(ushort *)(iVar9 + (int)param_4)) {
        (&DAT_006f0678)[local_8] = (&DAT_006f0678)[local_8] | 1 << ((byte)param_2 & 0x1f);
      }
      param_2 = (byte *)((int)param_2 + 1);
      iVar9 = iVar9 + 2;
    } while ((int)param_2 < (int)local_c);
  }
  bVar2 = true;
  iVar5 = 0;
  if (0 < iVar3) {
    piVar11 = &DAT_006f0678;
    iVar5 = iVar3;
    do {
      if ((bVar2) && (*piVar11 == -1)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      piVar11 = piVar11 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = iVar3;
    if (!bVar2) goto LAB_004bc13a;
  }
  if ((1 << ((byte)local_c & 0x1f)) + -1 == (&DAT_006f0678)[iVar5]) {
    if ((int)param_1 < 0x10) {
      puVar6 = &DAT_006f068c;
      for (uVar8 = ((uint)param_1 & 0x7fffffff) >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
        *param_4 = *puVar6;
        puVar6 = puVar6 + 1;
        param_4 = param_4 + 1;
      }
      for (uVar8 = (int)param_1 * 2 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)param_4 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        param_4 = (undefined4 *)((int)param_4 + 1);
      }
      puVar6 = &DAT_006f07cc;
      for (uVar8 = ((uint)param_1 & 0x7fffffff) >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
        *param_3 = *puVar6;
        puVar6 = puVar6 + 1;
        param_3 = param_3 + 1;
      }
      for (uVar8 = (int)param_1 * 2 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)param_3 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        param_3 = (undefined4 *)((int)param_3 + 1);
      }
      return;
    }
    FUN_005a92b0(param_4,&DAT_006f068c,(int)param_1 * 2);
    FUN_005a92b0(param_3,&DAT_006f07cc,(int)param_1 * 2);
    return;
  }
LAB_004bc13a:
  param_7 = (uint *)0x0;
  iVar5 = 0;
  if (0 < iVar3) {
    param_1 = param_4;
    local_10 = &DAT_006f0678;
    param_8 = param_3;
    param_5 = &DAT_006f07cc;
    param_6 = &DAT_006f068c;
    local_20 = iVar3;
    do {
      if (*local_10 == 0xffffffff) {
        FUN_005a92b0(param_1,param_6,0x40);
        FUN_005a92b0(param_8,param_5,0x40);
      }
      else {
        param_2 = (byte *)0x0;
        puVar6 = param_1;
        do {
          if ((*local_10 & 1 << ((byte)param_2 & 0x1f)) != 0) {
            *(undefined2 *)puVar6 =
                 *(undefined2 *)(((int)&DAT_006f068c - (int)param_4) + (int)puVar6);
            *(undefined2 *)(((int)param_3 - (int)param_4) + (int)puVar6) =
                 *(undefined2 *)(((int)&DAT_006f07cc - (int)param_4) + (int)puVar6);
          }
          param_2 = (byte *)((int)param_2 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 2);
        } while ((int)param_2 < 0x20);
      }
      param_8 = param_8 + 0x10;
      param_7 = (uint *)((int)param_7 + 0x20);
      param_6 = param_6 + 0x10;
      param_5 = param_5 + 0x10;
      param_1 = param_1 + 0x10;
      local_10 = local_10 + 1;
      local_20 = local_20 + -1;
      iVar5 = iVar3;
    } while (local_20 != 0);
  }
  param_2 = (byte *)0x0;
  if (0 < (int)local_c) {
    puVar7 = (undefined2 *)((int)param_4 + (int)param_7 * 2);
    do {
      if (((&DAT_006f0678)[iVar5] & 1 << ((byte)param_2 & 0x1f)) != 0) {
        *puVar7 = *(undefined2 *)((int)puVar7 + ((int)&DAT_006f068c - (int)param_4));
        *(undefined2 *)((int)puVar7 + ((int)param_3 - (int)param_4)) =
             *(undefined2 *)((int)puVar7 + ((int)&DAT_006f07cc - (int)param_4));
      }
      param_2 = (byte *)((int)param_2 + 1);
      puVar7 = puVar7 + 1;
    } while ((int)param_2 < (int)local_c);
  }
  return;
}

