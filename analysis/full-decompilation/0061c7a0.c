
undefined4 FUN_0061c7a0(int param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  byte *pbVar13;
  char *pcVar14;
  byte **ppbVar15;
  byte **ppbVar16;
  char *pcVar17;
  bool bVar18;
  byte *local_208;
  byte abStack_202 [2];
  undefined4 local_200 [128];
  
  uVar9 = 0xffffffff;
  pbVar8 = param_2;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    bVar1 = *pbVar8;
    pbVar8 = pbVar8 + 1;
  } while (bVar1 != 0);
  if (param_2[~uVar9 - 2] == 0x23) {
    uVar10 = 0xffffffff;
    do {
      pbVar8 = param_2;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pbVar8 = param_2 + 1;
      bVar1 = *param_2;
      param_2 = pbVar8;
    } while (bVar1 != 0);
    uVar10 = ~uVar10;
    pbVar8 = pbVar8 + -uVar10;
    pbVar13 = (byte *)local_200;
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pbVar13 = *(undefined4 *)pbVar8;
      pbVar8 = pbVar8 + 4;
      pbVar13 = pbVar13 + 4;
    }
    iVar6 = *(int *)(param_1 + 0x234);
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pbVar13 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      pbVar13 = pbVar13 + 1;
    }
    uVar3 = *(undefined1 *)(param_1 + 0x24c);
    abStack_202[~uVar9] = 0;
    *(undefined1 *)(param_1 + 0x24c) = 0;
    if ((iVar6 == 0) && (iVar6 = FUN_0061c7a0(param_1,local_200), iVar6 == 0)) {
      FUN_0061caa0(param_1,local_200,0,0,0,0,1);
      *(uint *)(*(uint *)(param_1 + 0x254) + 0x10) = ~*(uint *)(param_1 + 0x254);
    }
    *(undefined1 *)(param_1 + 0x24c) = uVar3;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x24c);
    if ((bVar1 == 0) ||
       ((((bVar4 = *param_2, bVar4 < 0x30 || (0x39 < bVar4)) && (bVar4 != 0x5c)) &&
        ((bVar4 != bVar1 && (bVar4 != 0x3f)))))) goto LAB_0061c94b;
    uVar9 = 0xffffffff;
    do {
      pbVar8 = param_2;
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      pbVar8 = param_2 + 1;
      bVar4 = *param_2;
      param_2 = pbVar8;
    } while (bVar4 != 0);
    uVar9 = ~uVar9;
    local_208 = (byte *)local_200;
    pbVar8 = pbVar8 + -uVar9;
    pbVar13 = (byte *)local_200;
    for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pbVar13 = *(undefined4 *)pbVar8;
      pbVar8 = pbVar8 + 4;
      pbVar13 = pbVar13 + 4;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pbVar13 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      pbVar13 = pbVar13 + 1;
    }
    if ((((byte)local_200[0] == 0x5c) || ((byte)local_200[0] == bVar1)) ||
       ((byte)local_200[0] == 0x3f)) {
      uVar9 = 0xffffffff;
      pcVar12 = &DAT_006c10a0;
      do {
        pcVar17 = pcVar12;
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        pcVar17 = pcVar12 + 1;
        cVar2 = *pcVar12;
        pcVar12 = pcVar17;
      } while (cVar2 != '\0');
      uVar9 = ~uVar9;
      iVar6 = -1;
      pcVar12 = (char *)local_200;
      do {
        pcVar14 = pcVar12;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar14 = pcVar12 + 1;
        cVar2 = *pcVar12;
        pcVar12 = pcVar14;
      } while (cVar2 != '\0');
      pcVar12 = pcVar17 + -uVar9;
      pcVar17 = pcVar14 + -1;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar17 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    FUN_00635858(&local_208,&DAT_006c8db0,*(undefined4 *)(param_1 + 0x250));
    uVar9 = 0xffffffff;
    ppbVar15 = &local_208;
    do {
      ppbVar16 = ppbVar15;
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      ppbVar16 = (byte **)((int)ppbVar15 + 1);
      cVar2 = *(char *)ppbVar15;
      ppbVar15 = ppbVar16;
    } while (cVar2 != '\0');
    uVar9 = ~uVar9;
    iVar6 = -1;
    pcVar12 = (char *)local_200;
    do {
      pcVar17 = pcVar12;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar17 = pcVar12 + 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar17;
    } while (cVar2 != '\0');
    pcVar12 = (char *)((int)ppbVar16 - uVar9);
    pcVar17 = pcVar17 + -1;
    for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar17 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  param_2 = (byte *)local_200;
LAB_0061c94b:
  puVar7 = (undefined4 *)FUN_0061cda0(param_1,param_2);
  if (puVar7 != (undefined4 *)0x0) {
    puVar7 = (undefined4 *)*puVar7;
    if ((*(byte *)(param_1 + 0x248) & 2) == 0) {
      for (; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
        pbVar8 = (byte *)puVar7[1];
        pbVar13 = param_2;
        do {
          bVar1 = *pbVar8;
          bVar18 = bVar1 < *pbVar13;
          if (bVar1 != *pbVar13) {
LAB_0061ca32:
            iVar6 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
            goto LAB_0061ca37;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar8[1];
          bVar18 = bVar1 < pbVar13[1];
          if (bVar1 != pbVar13[1]) goto LAB_0061ca32;
          pbVar8 = pbVar8 + 2;
          pbVar13 = pbVar13 + 2;
        } while (bVar1 != 0);
        iVar6 = 0;
LAB_0061ca37:
        if (iVar6 == 0) {
          uVar5 = puVar7[3];
          *(undefined4 *)(param_1 + 0x102a8) = puVar7[2];
          uVar9 = puVar7[4];
          *(undefined4 *)(param_1 + 0x102ac) = uVar5;
          bVar1 = *(byte *)(puVar7 + 7);
          *(uint *)(param_1 + 0x20c) = uVar9;
          if ((bVar1 & 9) == 0) {
            *(uint *)(param_1 + 0x20c) = uVar9 & 0xffff;
          }
          uVar5 = puVar7[6];
          *(undefined4 **)(param_1 + 0x254) = puVar7;
          *(undefined4 *)(param_1 + 0x210) = uVar5;
          return 1;
        }
      }
    }
    else {
      for (; puVar7 != (undefined4 *)0x0; puVar7 = (undefined4 *)*puVar7) {
        iVar6 = FUN_00646330(puVar7[1],param_2);
        if (iVar6 == 0) {
          uVar5 = puVar7[3];
          uVar9 = puVar7[4];
          *(undefined4 *)(param_1 + 0x102a8) = puVar7[2];
          bVar1 = *(byte *)(puVar7 + 7);
          *(undefined4 *)(param_1 + 0x102ac) = uVar5;
          *(uint *)(param_1 + 0x20c) = uVar9;
          if ((bVar1 & 9) == 0) {
            *(uint *)(param_1 + 0x20c) = uVar9 & 0xffff;
          }
          uVar5 = puVar7[6];
          *(undefined4 **)(param_1 + 0x254) = puVar7;
          *(undefined4 *)(param_1 + 0x210) = uVar5;
          return 1;
        }
      }
    }
  }
  *(undefined4 *)(param_1 + 0x102a8) = 0;
  *(undefined4 *)(param_1 + 0x102ac) = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0x7fff;
  *(undefined4 *)(param_1 + 0x210) = 0x7ffffffb;
  *(undefined4 *)(param_1 + 0x254) = 0;
  return 0;
}

