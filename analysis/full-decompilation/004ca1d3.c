
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004ca1d3(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  short *psVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  undefined4 *puVar11;
  
  if (*(int *)(param_1 + (0xe - param_3) * 4) == 0) {
    uVar3 = 0x10 << ((byte)param_3 & 0x1f);
    puVar4 = operator_new(uVar3 * 4 + 4);
    *(undefined4 **)(param_1 + (0xe - param_3) * 4) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      return 0x9b0b0001;
    }
    iVar8 = 8 << ((byte)param_3 & 0x1f);
    FUN_00636264();
    uVar5 = __ftol();
    *(undefined4 *)(param_1 + (0x12 - param_3) * 4) = uVar5;
    if (-1 < iVar8) {
      puVar10 = (undefined2 *)((int)puVar4 + iVar8 * 2);
      iVar8 = iVar8 + 1;
      param_2 = puVar10;
      do {
        uVar2 = __ftol();
        *param_2 = uVar2;
        *puVar10 = uVar2;
        puVar10 = puVar10 + 1;
        iVar8 = iVar8 + -1;
        param_2 = param_2 + -1;
      } while (iVar8 != 0);
    }
    puVar9 = puVar4;
    puVar11 = (undefined4 *)(uVar3 * 2 + (int)puVar4);
    for (uVar6 = (uVar3 & 0x7fffffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
    puVar1 = puVar4 + uVar3;
    for (uVar3 = uVar3 * 2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    *(undefined2 *)puVar1 = *(undefined2 *)((int)puVar1 + -2);
    *(undefined2 *)((int)puVar1 + 2) = *(undefined2 *)((int)puVar1 + -2);
    if (param_3 == 2) {
      *(short *)((int)puVar4 + 0x7e) = *(short *)((int)puVar4 + 0x7e) + 1;
      psVar7 = (short *)((int)puVar4 + 0xfe);
    }
    else {
      if (param_3 != 3) goto LAB_004ca314;
      *(short *)(puVar4 + 0x3f) = *(short *)(puVar4 + 0x3f) + 1;
      *(short *)((int)puVar4 + 0xfe) = *(short *)((int)puVar4 + 0xfe) + 1;
      *(short *)(puVar4 + 0x7f) = *(short *)(puVar4 + 0x7f) + 1;
      psVar7 = (short *)((int)puVar4 + 0x1fe);
    }
    *psVar7 = *psVar7 + 1;
  }
LAB_004ca314:
  if (*(int *)(param_1 + 0x38) == 0) {
    puVar4 = operator_new(0x200);
    *(undefined4 **)(param_1 + 0x38) = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
  }
  return 0;
}

