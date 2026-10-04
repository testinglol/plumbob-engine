
undefined4 FUN_005aa1c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  
  if (param_1 != 0) {
    iVar1 = (&DAT_00703ea0)[*(byte *)(param_1 + -0xe) & 0xf];
    if (*(int *)(iVar1 + 0x38) != 0) {
      FUN_005b6820(*(int *)(iVar1 + 0x38));
    }
    puVar5 = *(undefined2 **)(param_1 + -4);
    puVar6 = *(undefined2 **)(param_1 + -8);
    puVar7 = (undefined4 *)(param_1 + -4);
    puVar4 = puVar5;
    puVar8 = (undefined2 *)(param_1 + -0x10);
    if ((puVar5[1] & 0x4000) != 0) {
      iVar2 = *(int *)(puVar5 + 10);
      iVar3 = *(int *)(puVar5 + 8);
      *(int *)(iVar2 + 0x10) = iVar3;
      *(int *)(iVar3 + 0x14) = iVar2;
      puVar5[1] = puVar5[1] & 0xbfff;
      puVar7 = (undefined4 *)(puVar5 + 6);
      *puVar5 = 0x424f;
      puVar4 = (undefined2 *)*puVar7;
      *(undefined2 **)(puVar5 + 4) = puVar6;
      *(undefined2 **)(puVar4 + 4) = puVar5;
      *(undefined2 **)(puVar6 + 6) = puVar5;
      puVar8 = puVar5;
    }
    if ((puVar6[1] & 0x4000) != 0) {
      iVar2 = *(int *)(puVar6 + 10);
      iVar3 = *(int *)(puVar6 + 8);
      *(int *)(iVar2 + 0x10) = iVar3;
      *(int *)(iVar3 + 0x14) = iVar2;
      puVar6[1] = puVar6[1] & 0xbfff;
      *puVar6 = 0x424f;
      iVar2 = *(int *)(puVar6 + 4);
      *puVar7 = puVar4;
      *(int *)(puVar8 + 4) = iVar2;
      *(undefined2 **)(iVar2 + 0xc) = puVar8;
    }
    puVar5 = (undefined2 *)(iVar1 + 0x10);
    puVar6 = puVar5;
    if ((undefined2 *)
        (((uint)(*(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20)) >> 1) + *(int *)(iVar1 + 0x20)) <
        puVar8) {
      do {
        puVar6 = *(undefined2 **)(puVar6 + 10);
      } while (puVar8 < puVar6);
      puVar5 = *(undefined2 **)(puVar6 + 8);
    }
    else {
      do {
        puVar5 = *(undefined2 **)(puVar5 + 8);
      } while (puVar5 < puVar8);
      puVar6 = *(undefined2 **)(puVar5 + 10);
    }
    *(undefined2 **)(puVar8 + 8) = puVar5;
    *(undefined2 **)(puVar8 + 10) = puVar6;
    *(int *)(puVar8 + 2) = *(int *)(puVar8 + 4) - (int)puVar8;
    *(undefined2 **)(puVar6 + 8) = puVar8;
    *(undefined2 **)(puVar5 + 10) = puVar8;
    *(byte *)((int)puVar8 + 3) = *(byte *)((int)puVar8 + 3) | 0x40;
    *puVar8 = 0x4246;
    if (*(int *)(iVar1 + 0x38) != 0) {
      FUN_005b6830(*(int *)(iVar1 + 0x38));
    }
  }
  return 1;
}

