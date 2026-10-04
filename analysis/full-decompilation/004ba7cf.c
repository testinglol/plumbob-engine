
undefined4 __thiscall FUN_004ba7cf(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  byte *pbVar5;
  bool bVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  
  *param_3 = param_2;
  if (*(char *)(param_1 + 0x14) == '\0') {
    uVar7 = 0;
    bVar6 = false;
    puVar10 = param_2;
LAB_004ba7f1:
    while( true ) {
      while( true ) {
        cVar2 = **(char **)(param_1 + 8);
        bVar3 = (*(char **)(param_1 + 8))[1];
        uVar9 = (uint)bVar3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 2;
        pbVar5 = *(byte **)(param_1 + 8);
        if (cVar2 != '\x01') break;
        puVar10 = (undefined4 *)((int)puVar10 + uVar9 * 2);
        param_2 = puVar10;
      }
      if (cVar2 != '\x02') break;
      uVar4 = *(undefined2 *)(*(int *)(param_1 + 0x10) + (uint)*pbVar5 * 2);
      *(byte **)(param_1 + 8) = pbVar5 + 2;
      if (uVar9 != 0) {
        for (uVar8 = (uint)(bVar3 >> 1); uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar10 = CONCAT22(uVar4,uVar4);
          puVar10 = puVar10 + 1;
        }
        for (uVar8 = (uint)((bVar3 & 1) != 0); uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined2 *)puVar10 = uVar4;
          puVar10 = (undefined4 *)((int)puVar10 + 2);
        }
        puVar10 = (undefined4 *)((int)param_2 + uVar9 * 2);
        param_2 = puVar10;
      }
LAB_004ba874:
      uVar7 = 1;
    }
    if (cVar2 == '\x03') {
      uVar8 = 0;
      param_2 = puVar10;
      if (uVar9 != 0) {
        do {
          pbVar5 = (byte *)(*(int *)(param_1 + 8) + uVar8);
          uVar8 = uVar8 + 1;
          *(undefined2 *)param_2 = *(undefined2 *)(*(int *)(param_1 + 0x10) + (uint)*pbVar5 * 2);
          param_2 = (undefined4 *)((int)param_2 + 2);
        } while (uVar8 < uVar9);
      }
      puVar10 = (undefined4 *)((int)puVar10 + uVar9 * 2);
      *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + 1 + uVar9 & 0xfffffffe;
      param_2 = puVar10;
      goto LAB_004ba874;
    }
    if (cVar2 == '\x04') {
      if (bVar6) goto LAB_004ba8f1;
      if (((uVar9 == 2) && (*pbVar5 == 5)) && (pbVar5[1] == 0xff)) {
        *(byte **)(param_1 + 8) = pbVar5 + 4;
      }
      bVar6 = true;
      goto LAB_004ba7f1;
    }
    if (cVar2 == '\x05') {
      *(undefined1 *)(param_1 + 0x14) = 1;
      return uVar7;
    }
    if (cVar2 != '\t') {
      return uVar7;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      if (bVar6) {
        *(uint *)(param_1 + 0xc) = uVar9;
        *(byte **)(param_1 + 8) = pbVar5 + -2;
        return uVar7;
      }
      *(uint *)(param_1 + 0xc) = uVar9;
    }
    piVar1 = (int *)(param_1 + 0xc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      return uVar7;
    }
LAB_004ba8f1:
    *(byte **)(param_1 + 8) = pbVar5 + -2;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}

