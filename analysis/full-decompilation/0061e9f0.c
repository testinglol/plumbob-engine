
undefined4 * FUN_0061e9f0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *local_2c;
  int local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  puVar5 = *(undefined4 **)(param_1 + 0x14);
  local_2c = (int *)0x0;
  local_10 = 0;
  local_c = 0;
  local_18 = 0;
  local_14 = 0;
  local_20 = 0;
  local_1c = 0;
  if (puVar5 != (undefined4 *)0x0) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (0 < iVar1) {
      local_10 = *puVar5;
      local_c = puVar5[1];
    }
    if (1 < iVar1) {
      local_18 = puVar5[2];
      local_14 = puVar5[3];
    }
    if (2 < iVar1) {
      local_20 = puVar5[4];
      local_1c = puVar5[5];
    }
    if (3 < iVar1) {
      local_2c = (int *)puVar5[6];
    }
  }
  puVar5 = (undefined4 *)**(undefined4 **)(param_1 + 0xc);
  uVar4 = puVar5[1];
  puVar2 = (undefined4 *)FUN_005a9320(uVar4);
  if (puVar2 != (undefined4 *)0x0) {
    puVar6 = puVar2;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    if (local_2c != (int *)0x0) {
      puVar5 = puVar2 + 10;
      local_28 = 0x100;
      do {
        if (*local_2c != 0) {
          FUN_0061eb50(puVar5,1,local_10,local_c,local_18,local_14,local_20,local_1c);
        }
        local_2c = local_2c + 1;
        puVar5 = puVar5 + 1;
        local_28 = local_28 + -1;
      } while (local_28 != 0);
      return puVar2;
    }
    FUN_0061eb50(puVar2 + 10,0x100,local_10,local_c,local_18,local_14,local_20,local_1c);
  }
  return puVar2;
}

