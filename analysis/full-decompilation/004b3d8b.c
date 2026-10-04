
undefined1 FUN_004b3d8b(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_004b04af(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x18));
  if (*(int *)(unaff_EBP + 0x18) != 0) {
    FUN_006321f0(*(undefined4 *)(unaff_EBP + 0x18));
  }
  if (*(int *)(unaff_EBP + -0x3c) != 0) {
    FUN_004b0db9(*(undefined4 *)(unaff_EBP + -0x30));
  }
  DAT_006d6184 = *(undefined4 *)(unaff_EBP + -0x40);
  FUN_005cf06d(*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28));
  FUN_004b3938(unaff_EBP + -0xb8);
  FUN_00586fdc(*(undefined4 *)(unaff_EBP + -0x24));
  FUN_00584818(*(undefined4 *)(unaff_EBP + -0x34));
  DAT_006e54ac = *(undefined4 *)(unaff_EBP + -0x38);
  *(undefined1 *)(unaff_EBX + 0x51) = *(undefined1 *)(unaff_EBP + -0x12);
  FUN_0049ea67(unaff_EBP + -0x90);
  if ((undefined4 *)(unaff_EBX + 0x208) != (undefined4 *)(unaff_EBP + -0x2b8)) {
    puVar2 = (undefined4 *)(unaff_EBP + -0x2b8);
    puVar3 = (undefined4 *)(unaff_EBX + 0x208);
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  *(undefined1 *)(unaff_EBX + 0x4e) = 1;
  FUN_004abb9e(CONCAT31((int3)((uint)(unaff_EBP + -0x2b8) >> 8),*(undefined1 *)(unaff_EBX + 0x1f8)))
  ;
  (**(code **)(**(int **)(DAT_006e486c + 0x48) + 0x18))();
  FUN_005db0b7();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00635f6d(unaff_EBP + -0x2b8,8,0x40,FUN_00416e17);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0049ea8c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0x11);
}

