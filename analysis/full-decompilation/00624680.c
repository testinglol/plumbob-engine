
void FUN_00624680(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = (undefined4 *)**(undefined4 **)(param_1 + 0xc);
  uVar3 = puVar4[1];
  puVar1 = (undefined4 *)FUN_005a9320(uVar3);
  if (puVar1 != (undefined4 *)0x0) {
    puVar5 = puVar1;
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    puVar1[3] = param_2;
  }
  return;
}

