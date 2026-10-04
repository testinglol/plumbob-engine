
void __thiscall FUN_005c5db0(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  bool bVar9;
  
  pbVar7 = param_2;
  iVar2 = 0;
  if (param_2 != (byte *)0x0) {
    for (puVar8 = *(undefined4 **)(param_1 + 0x28); puVar8 != *(undefined4 **)(param_1 + 0x2c);
        puVar8 = puVar8 + 1) {
      pbVar3 = (byte *)*puVar8;
      pbVar6 = param_2;
      do {
        bVar1 = *pbVar3;
        bVar9 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_005c5e02:
          iVar2 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_005c5e07;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar9 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_005c5e02;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_005c5e07:
      if (iVar2 == 0) {
        *(int *)(param_1 + 0x40) = (int)puVar8 - (int)*(undefined4 **)(param_1 + 0x28) >> 2;
        return;
      }
    }
    uVar4 = 0xffffffff;
    pbVar3 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (bVar1 != 0);
    param_2 = operator_new(~uVar4);
    uVar4 = 0xffffffff;
    do {
      pbVar3 = pbVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pbVar3 = pbVar7 + 1;
      bVar1 = *pbVar7;
      pbVar7 = pbVar3;
    } while (bVar1 != 0);
    uVar4 = ~uVar4;
    pbVar7 = pbVar3 + -uVar4;
    pbVar3 = param_2;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pbVar3 = *(undefined4 *)pbVar7;
      pbVar7 = pbVar7 + 4;
      pbVar3 = pbVar3 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pbVar3 = *pbVar7;
      pbVar7 = pbVar7 + 1;
      pbVar3 = pbVar3 + 1;
    }
    puVar8 = *(undefined4 **)(param_1 + 0x2c);
    if (puVar8 == *(undefined4 **)(param_1 + 0x30)) {
      FUN_0046f199(puVar8,&param_2);
    }
    else {
      if (puVar8 != (undefined4 *)0x0) {
        *puVar8 = param_2;
      }
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 4;
    }
    iVar2 = (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28) >> 2) + -1;
  }
  *(int *)(param_1 + 0x40) = iVar2;
  return;
}

