
undefined1 FUN_00431808(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar1 = param_1;
  piVar2 = (int *)FUN_00420048(param_1);
  param_1._0_1_ = 0;
  iVar3 = *piVar2;
  if (iVar3 == 0x89) {
    iVar3 = FUN_00420096(uVar1);
    if ((iVar3 != 0xd8) && (iVar3 == 0xa0)) {
      iVar3 = 0x88;
      goto LAB_00431843;
    }
  }
  else {
LAB_00431843:
    if ((iVar3 != 0x88) && (iVar3 != 0x89)) goto LAB_00431898;
  }
  *piVar2 = 0x8a;
  FUN_0042004f(uVar1);
  iVar4 = FUN_00420096(uVar1);
  FUN_004200aa(uVar1,0xd8);
  iVar3 = FUN_00420048(uVar1);
  iVar4 = iVar4 / 2;
  if (iVar4 < 0x6c) {
    puVar6 = (undefined4 *)(iVar3 + iVar4 * 2);
    for (uVar5 = 0x6cU - iVar4 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (uVar5 = (uint)((0x6cU - iVar4 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined2 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 2);
    }
  }
  param_1._0_1_ = 1;
LAB_00431898:
  FUN_0042004f(uVar1);
  iVar3 = FUN_00420096(uVar1);
  if (iVar3 < 0xd8) {
    FUN_004200aa(uVar1,0xd8);
    iVar4 = FUN_00420048(uVar1);
    puVar6 = (undefined4 *)(iVar4 + iVar3);
    for (uVar5 = 0xd8U - iVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (uVar5 = 0xd8U - iVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
  }
  else if (0xd8 < iVar3) {
    FUN_004200aa(uVar1,0xd8);
  }
  return (undefined1)param_1;
}

