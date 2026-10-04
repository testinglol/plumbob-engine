
undefined4 * FUN_00619870(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar2 = (undefined4 *)FUN_005a9320(0x102c8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar5 = puVar2;
    for (iVar4 = 0x40b2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    FUN_00619e00(puVar2);
    puVar2[0x98] = 0;
    puVar2[0x409d] = 0;
    puVar2[0x409e] = 0;
    puVar2[0x409f] = 0;
    puVar2[0x40a1] = 0;
    puVar2[0x40a4] = 0;
    puVar2[0x40a5] = 0;
    puVar2[0x40a6] = 0x3c;
    puVar2[0x40a7] = 0;
    puVar2[0x40a8] = 0xffffffff;
    iVar4 = FUN_005a9320(0x2000);
    puVar2[0x98] = iVar4;
    if (iVar4 == 0) {
      FUN_00619f40(puVar2,"Out of memory!\n");
    }
    puVar5 = (undefined4 *)puVar2[0x98];
    for (iVar4 = 0x800; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    iVar4 = FUN_005a9320(0x10000);
    puVar2[0x409d] = iVar4;
    if (iVar4 == 0) {
      FUN_00619f40(puVar2,"Out of memory!\n");
    }
    puVar5 = (undefined4 *)puVar2[0x409d];
    puVar2[0x96] = puVar5;
    *puVar5 = 0;
    puVar2[0x97] = puVar5 + 10;
    iVar4 = FUN_005a9320(0x10000);
    puVar2[0x409e] = iVar4;
    if (iVar4 == 0) {
      FUN_00619f40(puVar2,"Out of memory!\n");
    }
    puVar5 = (undefined4 *)puVar2[0x409e];
    puVar2[0x9b] = puVar5;
    *puVar5 = 0;
    puVar2[0x9a] = puVar5 + 1;
    iVar4 = FUN_005a9320(0x400);
    puVar2[0x40a1] = iVar4;
    if (iVar4 == 0) {
      FUN_00619f40(puVar2,"Out of memory!\n");
    }
    iVar1 = puVar2[0x40a1];
    iVar4 = iVar1 + 0x3fc;
    puVar2[0x85] = iVar1;
    puVar2[0x88] = iVar4;
    puVar2[0x99] = 0;
    puVar2[0x40a3] = 1;
    puVar2[0x40a2] = iVar4;
    puVar2[0x89] = iVar1;
    puVar2[0x8a] = iVar4;
    puVar2[0x8e] = 1;
    uVar3 = FUN_005a9320(0x2400);
    puVar2[0x40ae] = uVar3;
    uVar3 = FUN_00619ba0(0x10000);
    puVar2[0x40af] = uVar3;
    uVar3 = FUN_005a9320(0x1800);
    puVar2[0x40b1] = uVar3;
    puVar2[0x40b0] = 0;
    FUN_0061d030(puVar2,&DAT_006c389c,&LAB_00619ca0,1);
    FUN_0061d030(puVar2,&PTR_DAT_00677c50,&LAB_00619cd0,1);
    FUN_0061d030(puVar2,"hypot",&LAB_00619db0,1);
    FUN_0061d030(puVar2,&DAT_00677c44,FUN_00636e69,2);
    FUN_0061d030(puVar2,&DAT_006ccae8,&LAB_00619d90,2);
    FUN_0061d030(puVar2,"round",&LAB_00619d40,2);
    FUN_0061d030(puVar2,"floor",FUN_006369f9,2);
    FUN_0061d030(puVar2,&DAT_00677c2c,FUN_00636ac8,2);
    FUN_0061d030(puVar2,&PTR_DAT_00677c28,FUN_00636d14,2);
    FUN_0061d030(puVar2,&DAT_00677c24,FUN_00637084,2);
    FUN_0061d030(puVar2,&PTR_DAT_00677c20,FUN_00639144,2);
    FUN_0061d030(puVar2,&DAT_00677c18,FUN_00639204,2);
    FUN_0061d030(puVar2,&DAT_00677c10,FUN_00636c44,2);
    FUN_0061d030(puVar2,&DAT_00677c08,FUN_00636dc4,2);
    FUN_0061d030(puVar2,&PTR_DAT_00677c04,&LAB_00637fd0,2);
    FUN_0061d030(puVar2,&PTR_PTR_00677c00,&DAT_00637f14,2);
    FUN_0061d030(puVar2,"log10",&DAT_0063ccf4,2);
    FUN_0061d030(puVar2,&DAT_00677bf0,&LAB_00619de0,2);
    FUN_0061d030(puVar2,&DAT_00677be8,FUN_00636264,2);
    FUN_0061d030(puVar2,&DAT_00677be0,&LAB_00619d00,2);
    return puVar2;
  }
  return (undefined4 *)0x0;
}

