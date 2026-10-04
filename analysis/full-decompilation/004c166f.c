
void FUN_004c166f(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  ushort *puVar8;
  uint local_c;
  undefined4 *local_8;
  
  puVar8 = (ushort *)(param_1 + 4);
  local_8 = param_2;
  puVar7 = param_1;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          uVar2 = *puVar8;
          uVar3 = (uint)uVar2;
          uVar4 = uVar3 & 0x1fff;
          uVar5 = uVar3 & 0xe000;
          puVar8 = puVar8 + 1;
          if ((uVar2 & 0xe000) != 0) break;
          puVar7 = local_8;
          local_8 = (undefined4 *)((int)local_8 + param_3);
        }
        if (uVar5 != 0x6000) break;
        if ((uVar2 & 0x1fff) != 0) {
          uVar1 = *(undefined1 *)((int)param_1 + 10);
          puVar6 = puVar7;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar6 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
            puVar6 = puVar6 + 1;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar6 = uVar1;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
          }
        }
        puVar7 = (undefined4 *)((int)puVar7 + uVar4);
      }
      if (uVar5 != 0x8000) break;
      local_8 = (undefined4 *)((int)local_8 + param_3 * uVar4);
      puVar7 = (undefined4 *)((int)local_8 - param_3);
    }
    if (uVar5 != 0xc000) break;
    if ((uVar2 & 0x1fff) != 0) {
      puVar6 = puVar7;
      local_c = uVar4;
      do {
        *(undefined1 *)puVar6 = *(undefined1 *)(((int)puVar8 - (int)puVar7) + (int)puVar6);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        local_c = local_c - 1;
      } while (local_c != 0);
    }
    puVar7 = (undefined4 *)((int)puVar7 + uVar4);
    puVar8 = (ushort *)((undefined1 *)((int)puVar8 + uVar4) + ((int)puVar8 + uVar4 & 1));
  }
  return;
}

