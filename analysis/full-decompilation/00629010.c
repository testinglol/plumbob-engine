
undefined4 FUN_00629010(uint *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  bool bVar9;
  
  uVar2 = *param_1;
  uVar3 = 0;
  bVar1 = *param_2;
  pbVar7 = param_2;
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
    pbVar5 = pbVar7 + 1;
    pbVar7 = pbVar7 + 1;
    bVar1 = *pbVar5;
  }
  puVar8 = *(undefined4 **)(param_1[2] + uVar3 * 0x14);
  if (puVar8 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  pbVar7 = (byte *)puVar8[3];
  pbVar5 = param_2;
  do {
    bVar1 = *pbVar5;
    bVar9 = bVar1 < *pbVar7;
    if (bVar1 != *pbVar7) {
LAB_006290b5:
      iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto joined_r0x006290bc;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar9 = bVar1 < pbVar7[1];
    if (bVar1 != pbVar7[1]) goto LAB_006290b5;
    pbVar5 = pbVar5 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar1 != 0);
  iVar6 = 0;
joined_r0x006290bc:
  do {
    if (iVar6 == 0) {
      return puVar8[4];
    }
    if (iVar6 < 0) {
      puVar8 = (undefined4 *)*puVar8;
    }
    else {
      puVar8 = (undefined4 *)puVar8[1];
    }
    if (puVar8 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    pbVar7 = (byte *)puVar8[3];
    pbVar5 = param_2;
    do {
      bVar1 = *pbVar5;
      bVar9 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_006290f8:
        iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto joined_r0x006290bc;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar9 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_006290f8;
      pbVar5 = pbVar5 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
  } while( true );
}

