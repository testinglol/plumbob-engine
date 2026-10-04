
int __thiscall
FUN_005c5a00(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            undefined4 param_7,byte *param_8,undefined4 param_9)

{
  int *piVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 *puVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  bool bVar17;
  CRect local_28 [16];
  int local_18;
  int local_14;
  undefined2 local_4;
  
  uVar7 = param_2;
  piVar1 = (int *)(param_1 + 4);
  iVar4 = FUN_005c6f40(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),param_2);
  if (iVar4 == *(int *)(param_1 + 8)) {
    FUN_00468aa0(uVar7);
    param_2 = (*(int *)(param_1 + 8) - *piVar1) / 0xc + -1;
  }
  else {
    param_2 = (iVar4 - *piVar1) / 0xc;
  }
  uVar7 = param_4;
  iVar4 = FUN_005c6f40(*piVar1,*(undefined4 *)(param_1 + 8),param_4);
  if (iVar4 == *(int *)(param_1 + 8)) {
    FUN_00468aa0(uVar7);
    iVar4 = (*(int *)(param_1 + 8) - *piVar1) / 0xc + -1;
  }
  else {
    iVar4 = (iVar4 - *piVar1) / 0xc;
  }
  uVar7 = param_6;
  iVar5 = FUN_005c6f40(*piVar1,*(undefined4 *)(param_1 + 8),param_6);
  if (iVar5 == *(int *)(param_1 + 8)) {
    FUN_00468aa0(uVar7);
    iVar5 = (*(int *)(param_1 + 8) - *piVar1) / 0xc + -1;
  }
  else {
    iVar5 = (iVar5 - *piVar1) / 0xc;
  }
  uVar7 = param_3;
  piVar1 = (int *)(param_1 + 0x10);
  iVar6 = FUN_005c6fa0(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),param_3);
  if (iVar6 == *(int *)(param_1 + 0x14)) {
    FUN_005c6300(uVar7);
    param_4 = (*(int *)(param_1 + 0x14) - *piVar1 >> 3) + -1;
  }
  else {
    param_4 = iVar6 - *piVar1 >> 3;
  }
  uVar7 = param_5;
  iVar6 = FUN_005c6fa0(*piVar1,*(undefined4 *)(param_1 + 0x14),param_5);
  if (iVar6 == *(int *)(param_1 + 0x14)) {
    FUN_005c6300(uVar7);
    param_6 = (*(int *)(param_1 + 0x14) - *piVar1 >> 3) + -1;
  }
  else {
    param_6 = iVar6 - *piVar1 >> 3;
  }
  uVar7 = param_7;
  iVar6 = FUN_005c6fa0(*piVar1,*(undefined4 *)(param_1 + 0x14),param_7);
  if (iVar6 == *(int *)(param_1 + 0x14)) {
    FUN_005c6300(uVar7);
    param_3 = (*(int *)(param_1 + 0x14) - *piVar1 >> 3) + -1;
  }
  else {
    param_3 = iVar6 - *piVar1 >> 3;
  }
  pbVar15 = param_8;
  if (param_8 == (byte *)0x0) {
    iVar6 = *(int *)(param_1 + 0x40);
  }
  else {
    for (puVar13 = *(undefined4 **)(param_1 + 0x28); puVar13 != *(undefined4 **)(param_1 + 0x2c);
        puVar13 = puVar13 + 1) {
      pbVar16 = (byte *)*puVar13;
      pbVar14 = param_8;
      do {
        bVar2 = *pbVar16;
        bVar17 = bVar2 < *pbVar14;
        if (bVar2 != *pbVar14) {
LAB_005c5c03:
          iVar6 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
          goto LAB_005c5c08;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar16[1];
        bVar17 = bVar2 < pbVar14[1];
        if (bVar2 != pbVar14[1]) goto LAB_005c5c03;
        pbVar16 = pbVar16 + 2;
        pbVar14 = pbVar14 + 2;
      } while (bVar2 != 0);
      iVar6 = 0;
LAB_005c5c08:
      if (iVar6 == 0) {
        iVar6 = (int)puVar13 - *(int *)(param_1 + 0x28) >> 2;
        goto LAB_005c5c6e;
      }
    }
    uVar11 = 0xffffffff;
    pbVar16 = param_8;
    do {
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      bVar2 = *pbVar16;
      pbVar16 = pbVar16 + 1;
    } while (bVar2 != 0);
    param_8 = operator_new(~uVar11);
    uVar11 = 0xffffffff;
    do {
      pbVar16 = pbVar15;
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      pbVar16 = pbVar15 + 1;
      bVar2 = *pbVar15;
      pbVar15 = pbVar16;
    } while (bVar2 != 0);
    uVar11 = ~uVar11;
    pbVar15 = pbVar16 + -uVar11;
    pbVar16 = param_8;
    for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pbVar16 = *(undefined4 *)pbVar15;
      pbVar15 = pbVar15 + 4;
      pbVar16 = pbVar16 + 4;
    }
    for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
      *pbVar16 = *pbVar15;
      pbVar15 = pbVar15 + 1;
      pbVar16 = pbVar16 + 1;
    }
    FUN_0046ef6c(&param_8);
    iVar6 = (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28) >> 2) + -1;
  }
LAB_005c5c6e:
  uVar3 = *(undefined2 *)(param_1 + 0x44);
  local_18 = param_2;
  local_14 = param_4;
  param_8 = (byte *)0x0;
  param_2 = 0;
  param_4 = 0;
  uVar7 = FUN_00462bc9(&param_4,&param_2,&param_8);
  FUN_00462be8(uVar7);
  uVar7 = param_9;
  local_4 = uVar3;
  iVar8 = FUN_005c5930(&local_18,param_9);
  uVar10 = uVar7;
  uVar9 = FUN_005c5d60(iVar4,param_6,CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x44)));
  param_8 = (byte *)FUN_005c5930(uVar9,uVar10);
  uVar10 = FUN_005c5d60(iVar5,param_3,CONCAT22(extraout_var_00,*(undefined2 *)(param_1 + 0x44)));
  iVar4 = FUN_005c5930(uVar10,uVar7);
  CRect::CRect(local_28,iVar8,(int)param_8,iVar4,iVar6);
  FUN_005c64a0(local_28);
  *(undefined1 *)(param_1 + 0x60) = 1;
  return (*(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c) >> 4) + -1;
}

