
void FUN_0061caa0(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  char *pcVar12;
  char *pcVar13;
  byte *pbVar14;
  char local_208 [8];
  byte local_200 [512];
  
  if ((*(byte *)(param_1 + 0x248) & 1) == 0) {
    uVar8 = 0xffffffff;
    pbVar11 = param_2;
    do {
      pbVar14 = pbVar11;
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      pbVar14 = pbVar11 + 1;
      bVar5 = *pbVar11;
      pbVar11 = pbVar14;
    } while (bVar5 != 0);
    uVar8 = ~uVar8;
    pbVar11 = pbVar14 + -uVar8;
    pbVar14 = local_200;
    for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pbVar14 = *(undefined4 *)pbVar11;
      pbVar11 = pbVar11 + 4;
      pbVar14 = pbVar14 + 4;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pbVar14 = *pbVar11;
      pbVar11 = pbVar11 + 1;
      pbVar14 = pbVar14 + 1;
    }
  }
  else {
    bVar5 = *param_2;
    pbVar11 = local_200;
    if (bVar5 != 0) {
      do {
        bVar5 = FUN_00638af3(bVar5);
        *pbVar11 = bVar5;
        bVar5 = (param_2 + (1 - (int)local_200))[(int)pbVar11];
        pbVar11 = pbVar11 + 1;
      } while (bVar5 != 0);
    }
    *pbVar11 = 0;
  }
  bVar5 = *(byte *)(param_1 + 0x24c);
  if (bVar5 == 0) goto LAB_0061cbc5;
  bVar2 = *param_2;
  if ((bVar2 < 0x30) || (0x39 < bVar2)) {
    if (bVar2 != 0x5c) {
      if ((bVar2 != bVar5) && (bVar2 != 0x3f)) goto LAB_0061cbc5;
      goto LAB_0061cb45;
    }
LAB_0061cb51:
    uVar8 = 0xffffffff;
    pcVar12 = &DAT_006c10a0;
    do {
      pcVar13 = pcVar12;
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      pcVar13 = pcVar12 + 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar13;
    } while (cVar1 != '\0');
    uVar8 = ~uVar8;
    iVar9 = -1;
    pbVar11 = local_200;
    do {
      pbVar14 = pbVar11;
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      pbVar14 = pbVar11 + 1;
      bVar5 = *pbVar11;
      pbVar11 = pbVar14;
    } while (bVar5 != 0);
    pbVar11 = (byte *)(pcVar13 + -uVar8);
    pbVar14 = pbVar14 + -1;
    for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pbVar14 = *(undefined4 *)pbVar11;
      pbVar11 = pbVar11 + 4;
      pbVar14 = pbVar14 + 4;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pbVar14 = *pbVar11;
      pbVar11 = pbVar11 + 1;
      pbVar14 = pbVar14 + 1;
    }
  }
  else {
LAB_0061cb45:
    if ((bVar2 == 0x5c) || ((bVar2 == bVar5 || (bVar2 == 0x3f)))) goto LAB_0061cb51;
  }
  FUN_00635858(local_208,&DAT_006c8db0,*(undefined4 *)(param_1 + 0x250));
  uVar8 = 0xffffffff;
  pcVar12 = local_208;
  do {
    pcVar13 = pcVar12;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar13 = pcVar12 + 1;
    cVar1 = *pcVar12;
    pcVar12 = pcVar13;
  } while (cVar1 != '\0');
  uVar8 = ~uVar8;
  iVar9 = -1;
  pbVar11 = local_200;
  do {
    pbVar14 = pbVar11;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pbVar14 = pbVar11 + 1;
    bVar5 = *pbVar11;
    pbVar11 = pbVar14;
  } while (bVar5 != 0);
  pbVar11 = (byte *)(pcVar13 + -uVar8);
  pbVar14 = pbVar14 + -1;
  for (uVar10 = uVar8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pbVar14 = *(undefined4 *)pbVar11;
    pbVar11 = pbVar11 + 4;
    pbVar14 = pbVar14 + 4;
  }
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pbVar14 = *pbVar11;
    pbVar11 = pbVar11 + 1;
    pbVar14 = pbVar14 + 1;
  }
LAB_0061cbc5:
  iVar9 = *(int *)(param_1 + 0x25c) + 0x28;
  *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x25c);
  *(int *)(param_1 + 0x25c) = iVar9;
  if (0x10000 < iVar9 - *(int *)(param_1 + 600)) {
    iVar9 = FUN_005a9320(0x10000);
    *(int *)(param_1 + 0x254) = iVar9;
    if (iVar9 == 0) {
      FUN_00619f40(param_1,"Out of memory!\n");
    }
    puVar3 = *(undefined4 **)(param_1 + 0x254);
    **(undefined4 **)(param_1 + 600) = puVar3;
    *(undefined4 **)(param_1 + 600) = puVar3;
    *puVar3 = 0;
    *(undefined4 **)(param_1 + 0x254) = puVar3 + 10;
    *(undefined4 **)(param_1 + 0x25c) = puVar3 + 0x14;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x254);
  *puVar3 = 0;
  uVar6 = FUN_0061ccf0(param_1,local_200,0);
  puVar3[1] = uVar6;
  puVar3[2] = param_3;
  uVar6 = *(undefined4 *)(param_1 + 0x238);
  puVar3[3] = param_4;
  puVar3[4] = param_5;
  puVar3[5] = uVar6;
  puVar3[6] = param_6;
  puVar3[7] = param_7;
  iVar9 = *(int *)(param_1 + 0x264);
  puVar3[8] = 0;
  *(int *)(param_1 + 0x264) = iVar9 + 1;
  piVar7 = (int *)FUN_0061cda0(param_1,local_200);
  puVar3 = (undefined4 *)*piVar7;
  if (puVar3 != (undefined4 *)0x0) {
    for (puVar4 = (undefined4 *)*puVar3; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4
        ) {
      puVar3 = puVar4;
    }
    *puVar3 = *(undefined4 *)(param_1 + 0x254);
    return;
  }
  *piVar7 = *(int *)(param_1 + 0x254);
  return;
}

