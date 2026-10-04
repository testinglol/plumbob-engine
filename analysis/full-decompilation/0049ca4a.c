
void FUN_0049ca4a(void)

{
  uint uVar1;
  undefined4 *puVar2;
  float fVar3;
  void *pvVar4;
  size_t sVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int extraout_ECX;
  undefined4 uVar9;
  int unaff_EBP;
  int iVar10;
  
  FUN_00634c24();
  uVar9 = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_004a4b90();
  iVar10 = *(int *)(extraout_ECX + 0x68);
  *(undefined4 *)(extraout_ECX + 0xd8) = 0xffffffff;
  if ((iVar10 != 0) && (*(int *)(DAT_006e54d8 + 0x10) != *(int *)(iVar10 + 8))) {
    if (iVar10 != 0) {
      FUN_00431242();
      FUN_006321f0(iVar10);
    }
    *(undefined4 *)(extraout_ECX + 0x68) = 0;
  }
  if (*(int *)(extraout_ECX + 0x68) == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(DAT_006e54d8 + 0x10);
    pvVar4 = operator_new(0x20);
    *(void **)(unaff_EBP + -0x18) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      uVar6 = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      sVar5 = _strlen(s_grass_random_seeds_006c6630);
      FUN_00401a3c(s_grass_random_seeds_006c6630,s_grass_random_seeds_006c6630 + sVar5);
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_004311b4(2,*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x14),
                   unaff_EBP + -0x2c);
      uVar6 = *(undefined4 *)(unaff_EBP + -0x18);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0x68) = uVar6;
    if ((*(byte *)(unaff_EBP + -0x10) & 1) != 0) {
      *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
      FUN_00401729();
    }
    uVar7 = FUN_0046f546();
    uVar6 = *(undefined4 *)(extraout_ECX + 0x88);
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar7;
    FUN_0046f54c(uVar6);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    if (0 < *(int *)(unaff_EBP + -0x14)) {
      do {
        iVar10 = 0;
        do {
          uVar8 = FUN_0046f556();
          *(short *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x68) + 0xc) +
                             *(int *)(unaff_EBP + -0x18) * 4) + iVar10 * 2) =
               (short)((ulonglong)uVar8 % 0xffff);
          iVar10 = iVar10 + 1;
        } while (iVar10 < *(int *)(unaff_EBP + -0x14));
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x14));
    }
    FUN_0046f54c(*(undefined4 *)(unaff_EBP + -0x1c));
  }
  iVar10 = *(int *)(extraout_ECX + 0x6c);
  if (iVar10 != 0) {
    FUN_00431242();
    FUN_006321f0(iVar10);
  }
  iVar10 = *(int *)(extraout_ECX + 0x74);
  if (iVar10 != 0) {
    FUN_00431242();
    FUN_006321f0(iVar10);
  }
  pvVar4 = operator_new(0x20);
  *(void **)(unaff_EBP + -0x1c) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if (pvVar4 != (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    sVar5 = _strlen(s_color_table_006c6624);
    FUN_00401a3c(s_color_table_006c6624,s_color_table_006c6624 + sVar5);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 2;
    uVar6 = *(undefined4 *)(extraout_ECX + 0x4c);
    uVar7 = *(undefined4 *)(extraout_ECX + 0x7c);
    uVar9 = *(undefined4 *)(unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_004311b4(0x10,uVar7,uVar6,unaff_EBP + -0x2c);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x6c) = uVar9;
  if ((*(byte *)(unaff_EBP + -0x10) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
    FUN_00401729();
  }
  iVar10 = *(int *)(extraout_ECX + 0x6c);
  uVar8 = *(uint *)(extraout_ECX + 0x58);
  *(uint *)(unaff_EBP + -0x1c) = uVar8;
  uVar1 = *(uint *)(extraout_ECX + 0x50);
  uVar9 = *(undefined4 *)(iVar10 + 0xc);
  *(uint *)(unaff_EBP + -0x18) = uVar1;
  *(undefined4 *)(extraout_ECX + 0x70) = uVar9;
  *(uint *)(unaff_EBP + -0x50) = (uint)*(byte *)(unaff_EBP + -0x1a);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(uint *)(unaff_EBP + -0x4c) = uVar8 >> 8 & 0xff;
  *(uint *)(unaff_EBP + -0x48) = uVar8 & 0xff;
  *(uint *)(unaff_EBP + -0x44) = (uint)*(byte *)(unaff_EBP + -0x16);
  *(uint *)(unaff_EBP + -0x40) = uVar1 >> 8 & 0xff;
  uVar8 = *(uint *)(extraout_ECX + 0x5c);
  *(uint *)(unaff_EBP + -0x1c) = uVar8;
  *(uint *)(unaff_EBP + -0x68) = (uint)*(byte *)(unaff_EBP + -0x1a);
  *(uint *)(unaff_EBP + -0x3c) = uVar1 & 0xff;
  uVar1 = *(uint *)(extraout_ECX + 0x54);
  *(uint *)(unaff_EBP + -0x60) = uVar8 & 0xff;
  *(uint *)(unaff_EBP + -0x18) = uVar1;
  *(uint *)(unaff_EBP + -0x5c) = (uint)*(byte *)(unaff_EBP + -0x16);
  *(uint *)(unaff_EBP + -100) = uVar8 >> 8 & 0xff;
  iVar10 = *(int *)(extraout_ECX + 0x7c);
  *(uint *)(unaff_EBP + -0x58) = uVar1 >> 8 & 0xff;
  *(uint *)(unaff_EBP + -0x54) = uVar1 & 0xff;
  if (0 < iVar10) {
    *(int *)(unaff_EBP + -0x1c) = iVar10 + -1;
    *(float *)(unaff_EBP + -0x1c) = (float)*(int *)(unaff_EBP + -0x1c);
    do {
      fVar3 = (float)*(int *)(unaff_EBP + -0x14) / *(float *)(unaff_EBP + -0x1c);
      *(float *)(unaff_EBP + -0x18) = fVar3;
      uVar9 = FUN_0049cdb0(fVar3);
      *(undefined4 *)(unaff_EBP + -0x20) = uVar9;
      uVar9 = FUN_0049cdb0(*(undefined4 *)(unaff_EBP + -0x18));
      FUN_0049e846(*(undefined4 *)(*(int *)(extraout_ECX + 0x70) + *(int *)(unaff_EBP + -0x14) * 4),
                   *(undefined4 *)(extraout_ECX + 0x4c),*(undefined4 *)(unaff_EBP + -0x20),uVar9,
                   extraout_ECX + 0x20,0);
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    } while (*(int *)(unaff_EBP + -0x14) < iVar10);
  }
  pvVar4 = operator_new(0x20);
  *(void **)(unaff_EBP + -0x18) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 8;
  if (pvVar4 == (void *)0x0) {
    uVar9 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    sVar5 = _strlen(s_color_table_006c6624);
    FUN_00401a3c(s_color_table_006c6624,s_color_table_006c6624 + sVar5);
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 4;
    uVar9 = *(undefined4 *)(extraout_ECX + 0x4c);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_004311b4(0x10,2,uVar9,unaff_EBP + -0x38);
    uVar9 = *(undefined4 *)(unaff_EBP + -0x18);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x74) = uVar9;
  if ((*(byte *)(unaff_EBP + -0x10) & 4) != 0) {
    FUN_00401729();
  }
  puVar2 = *(undefined4 **)(*(int *)(extraout_ECX + 0x74) + 0xc);
  *(undefined4 **)(extraout_ECX + 0x78) = puVar2;
  FUN_0049e846(*puVar2,*(undefined4 *)(extraout_ECX + 0x4c),*(undefined4 *)(extraout_ECX + 0xbc),
               *(undefined4 *)(extraout_ECX + 0xc0),extraout_ECX + 0x20,0);
  FUN_0049e846(*(undefined4 *)(*(int *)(extraout_ECX + 0x78) + 4),
               *(undefined4 *)(extraout_ECX + 0x4c),*(undefined4 *)(extraout_ECX + 0xc4),
               *(undefined4 *)(extraout_ECX + 200),extraout_ECX + 0x20,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

