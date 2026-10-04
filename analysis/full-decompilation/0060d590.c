
undefined4 * FUN_0060d590(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *local_8;
  
  puVar4 = (undefined4 *)*param_1;
  iVar7 = (int)(puVar4[6] * param_2 + (puVar4[6] * param_2 >> 0x1f & 7U)) >> 3;
  local_8 = (undefined4 *)0x0;
  if ((int)puVar4[4] <= param_2) {
    iVar1 = puVar4[5];
    if (iVar1 <= param_3) {
      puVar2 = (undefined4 *)FUN_005a9320(iVar7 * param_3);
      if (puVar2 != (undefined4 *)0x0) {
        uVar6 = puVar4[1];
        puVar3 = (undefined4 *)FUN_005a9320(uVar6);
        if (puVar3 == (undefined4 *)0x0) {
          FUN_005a9340(puVar2);
          return (undefined4 *)0x0;
        }
        local_8 = (undefined4 *)FUN_005a9320(0xc);
        if (local_8 == (undefined4 *)0x0) {
          FUN_005a9340(puVar3);
          FUN_005a9340(puVar2);
          return (undefined4 *)0x0;
        }
        local_8[1] = puVar2;
        local_8[2] = iVar7;
        *local_8 = puVar3;
        puVar8 = puVar3;
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar8 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar8 = puVar8 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        puVar3[4] = param_2;
        puVar3[5] = param_3;
        if (0 < iVar1) {
          uVar6 = param_1[2];
          puVar4 = (undefined4 *)param_1[1];
          param_2 = iVar1;
          do {
            puVar3 = puVar4;
            puVar8 = puVar2;
            for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar8 = *puVar3;
              puVar3 = puVar3 + 1;
              puVar8 = puVar8 + 1;
            }
            for (uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined1 *)puVar8 = *(undefined1 *)puVar3;
              puVar3 = (undefined4 *)((int)puVar3 + 1);
              puVar8 = (undefined4 *)((int)puVar8 + 1);
            }
            puVar4 = (undefined4 *)((int)puVar4 + uVar6);
            puVar2 = (undefined4 *)((int)puVar2 + iVar7);
            param_2 = param_2 + -1;
          } while (param_2 != 0);
        }
      }
      return local_8;
    }
  }
  return (undefined4 *)0x0;
}

