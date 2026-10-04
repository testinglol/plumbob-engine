
void FUN_0061ab10(uint *param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  int iVar9;
  bool bVar10;
  
  uVar2 = *param_1;
  uVar3 = 0;
  bVar1 = *param_2;
  pbVar8 = param_2;
  while (bVar1 != 0) {
    uVar4 = 0;
    if (uVar3 != 0) {
      uVar3 = uVar3 << 1;
      if ((uVar3 & uVar2) != 0) {
        uVar3 = uVar3 ^ uVar2 + 1;
      }
      uVar3 = uVar3 << 1;
      if ((uVar3 & uVar2) != 0) {
        uVar3 = uVar3 ^ uVar2 + 1;
      }
      uVar3 = uVar3 << 1;
      if ((uVar3 & uVar2) != 0) {
        uVar3 = uVar3 ^ uVar2 + 1;
      }
      uVar3 = uVar3 << 1;
      if ((uVar3 & uVar2) != 0) {
        uVar3 = uVar3 ^ uVar2 + 1;
      }
      uVar4 = uVar3 << 1;
      if ((uVar4 & uVar2) != 0) {
        uVar4 = uVar4 ^ uVar2 + 1;
      }
    }
    uVar3 = uVar4 ^ bVar1 - 0x61 & 0xff;
    pbVar5 = pbVar8 + 1;
    pbVar8 = pbVar8 + 1;
    bVar1 = *pbVar5;
  }
  puVar6 = *(undefined4 **)(param_1[2] + uVar3 * 0x14);
  puVar7 = (undefined4 *)(param_1[2] + uVar3 * 0x14);
  iVar9 = -1;
  if (puVar6 != (undefined4 *)0x0) {
    pbVar8 = (byte *)puVar6[3];
    pbVar5 = param_2;
    do {
      bVar1 = *pbVar5;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_0061abb8:
        iVar9 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_0061abbd;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_0061abb8;
      pbVar5 = pbVar5 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar9 = 0;
LAB_0061abbd:
    puVar7 = puVar6;
    if (iVar9 == 0) {
      return;
    }
    while( true ) {
      if (iVar9 < 0) {
        puVar6 = (undefined4 *)*puVar7;
      }
      else {
        puVar6 = (undefined4 *)puVar7[1];
      }
      if (puVar6 == (undefined4 *)0x0) break;
      pbVar8 = (byte *)puVar6[3];
      pbVar5 = param_2;
      do {
        bVar1 = *pbVar5;
        bVar10 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_0061ac00:
          iVar9 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0061ac05;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar10 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_0061ac00;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar9 = 0;
LAB_0061ac05:
      puVar7 = puVar6;
      if (iVar9 == 0) {
        return;
      }
    }
  }
  puVar6 = (undefined4 *)FUN_0061ac60(param_1 + 4);
  if (puVar6 != (undefined4 *)0x0) {
    param_1[1] = param_1[1] + 1;
    if (iVar9 < 0) {
      *puVar7 = puVar6;
    }
    else {
      puVar7[1] = puVar6;
    }
    uVar2 = param_1[3];
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = uVar2;
    param_1[3] = (uint)puVar6;
    puVar6[3] = param_2;
    puVar6[4] = param_3;
  }
  return;
}

