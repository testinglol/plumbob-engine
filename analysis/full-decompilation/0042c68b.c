
undefined4 FUN_0042c68b(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined1 auStack_120 [8];
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined *puStack_110;
  int iStack_10c;
  char *pcStack_108;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  if ((0xb < *(int *)(unaff_EBP + 8)) || (*(int *)(unaff_EBP + 8) < 0)) {
    uVar4 = 0;
    goto LAB_0042c8f3;
  }
  *(undefined4 *)(unaff_EBP + -0x68) = 10;
  *(undefined4 *)(unaff_EBP + -100) = 9;
  *(undefined4 *)(unaff_EBP + -0x60) = 9;
  *(undefined4 *)(unaff_EBP + -0x5c) = 8;
  pcStack_108 = (char *)0x3e8;
  *(undefined4 *)(unaff_EBP + -0x58) = 8;
  *(undefined4 *)(unaff_EBP + -0x54) = 7;
  *(undefined4 *)(unaff_EBP + -0x50) = 7;
  *(undefined4 *)(unaff_EBP + -0x4c) = 6;
  *(undefined4 *)(unaff_EBP + -0x48) = 5;
  *(undefined4 *)(unaff_EBP + -0x44) = 4;
  *(undefined4 *)(unaff_EBP + -0x40) = 3;
  *(undefined4 *)(unaff_EBP + -0x3c) = 2;
  iStack_10c = 0x42c70a;
  uVar2 = FUN_005bc722();
  *(uint *)(unaff_EBP + -0x14) = uVar2;
  iVar3 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + 8) = 0;
  *(uint *)(unaff_EBP + -0x28) = (uint)(iVar3 < 7);
  *(uint *)(unaff_EBP + -0x10) = uVar2 % 3;
  if (iVar3 < 10) {
    uVar2 = *(uint *)(unaff_EBP + -0x68 + iVar3 * 4);
  }
  else {
    uVar2 = *(uint *)(unaff_EBP + -0x14) % 7 + 4;
  }
  pcStack_108 = (char *)0x42c744;
  iVar3 = FUN_0040542d();
  if (iVar3 != 0) {
    if (uVar2 < 10) {
      iStack_10c = 0x42c757;
      pcStack_108 = (char *)uVar2;
      uVar4 = FUN_00405252();
      *(undefined4 *)(unaff_EBP + 8) = uVar4;
    }
    else {
      *(undefined4 *)(unaff_EBP + 8) = 1000;
    }
    if (1000 < *(uint *)(unaff_EBP + 8)) {
      *(undefined4 *)(unaff_EBP + 8) = 1000;
    }
  }
  pcStack_108 = &DAT_006de560;
  iStack_10c = 0x42c774;
  FUN_0040bfed();
  pcStack_108 = (char *)0x42c77c;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pcStack_108 = (char *)0x42c78a;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x104) = &PTR_FUN_0066643c;
  iVar3 = *(int *)(unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar3 == 0) {
    pcStack_108 = &DAT_006c1010;
    iStack_10c = 0x42c7e2;
    FUN_0040bfed();
    pcStack_108 = (char *)(unaff_EBP + -0x78);
LAB_0042c7e5:
    iStack_10c = 0x42c7ee;
    FUN_0046f8e4();
  }
  else {
    if (iVar3 == 1) {
      pcStack_108 = &DAT_006c100c;
      iStack_10c = 0x42c7cd;
      FUN_0040bfed();
      pcStack_108 = (char *)(unaff_EBP + -0x88);
      goto LAB_0042c7e5;
    }
    if (iVar3 == 2) {
      pcStack_108 = &DAT_006c1008;
      iStack_10c = 0x42c7b5;
      FUN_0040bfed();
      pcStack_108 = (char *)(unaff_EBP + -0x98);
      goto LAB_0042c7e5;
    }
  }
  if (*(int *)(unaff_EBP + -0x28) == 0) {
    pcStack_108 = s_Nomad_006c28bc;
    iStack_10c = 0x42c82d;
    FUN_005d4bbf();
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    uStack_114 = 0xa5;
LAB_0042c842:
    iStack_10c = unaff_EBP + -0x104;
    pcStack_108 = (char *)0x0;
    puStack_110 = &DAT_006c265c;
    uStack_118 = 0x42c847;
    FUN_004fff98();
  }
  else if (*(int *)(unaff_EBP + -0x28) == 1) {
    pcStack_108 = &DAT_006c28c4;
    iStack_10c = 0x42c805;
    FUN_005d4bbf();
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    uStack_114 = 0xa6;
    goto LAB_0042c842;
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  do {
    pcStack_108 = (char *)0x3e8;
    iStack_10c = 0x42c858;
    uVar5 = FUN_005bc722();
    pcStack_108 = (char *)0xffffffff;
    iStack_10c = 0x42c867;
    uVar6 = FUN_0046fbe5();
    pcStack_108 = (char *)0xffffffff;
    iStack_10c = uVar5 % uVar6 + 1;
    puStack_110 = (undefined *)0x42c87e;
    pcStack_108 = (char *)FUN_004705f2();
    iStack_10c = 0x42c887;
    FUN_005d4bbf();
    iStack_10c = unaff_EBP + -0x24;
    pcStack_108 = (char *)0x1388;
    puStack_110 = (undefined *)0x42c898;
    cVar1 = FUN_0042da84();
    if (cVar1 == '\x01') break;
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 0xc);
  pcStack_108 = (char *)0x1;
  iStack_10c = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + 8) = auStack_120;
  puStack_110 = (undefined *)uVar2;
  FUN_0042c904(unaff_EBP + -0x38);
  uVar4 = FUN_0042ccd8(*(undefined4 *)(unaff_EBP + 0xc),0,*(undefined4 *)(unaff_EBP + -0x14),
                       unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  pcStack_108 = (char *)0x42c8e1;
  FUN_00470467();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  pcStack_108 = (char *)0x42c8ed;
  FUN_005b8770();
LAB_0042c8f3:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

