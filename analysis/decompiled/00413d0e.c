
undefined4 FUN_00413d0e(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  short sVar3;
  undefined4 uVar4;
  int *piVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  void *pvVar9;
  size_t sVar10;
  char *pcVar11;
  int unaff_EBP;
  undefined4 *puVar12;
  undefined *puVar13;
  
  FUN_00634c24();
  uVar7 = FUN_005b8e25();
  *(undefined4 *)(unaff_EBP + -0x20) = uVar7;
  FUN_0046f824(unaff_EBP + -0x13c,0,0x104);
  *(undefined ***)(unaff_EBP + -0x148) = &PTR_FUN_006664e8;
  iVar8 = FUN_00635845(s___expansionpack_xpack_hot_006c16bc,&DAT_006c16d8);
  *(int *)(unaff_EBP + -0x1c) = iVar8;
  if (iVar8 != 0) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar6 = FUN_004fff98(1,s_Ranger_iff_006c16b0,unaff_EBP + -0x1c0,0);
    if (cVar6 != '\0') {
      *(byte *)((int)DAT_006e486c + 0x66) = *(byte *)((int)DAT_006e486c + 0x66) | 1;
    }
    FUN_0063558d(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  iVar8 = FUN_00635845(s___expansionshared_sound_housepar_006c1688,&DAT_006c16d8);
  *(int *)(unaff_EBP + -0x1c) = iVar8;
  if (iVar8 != 0) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    cVar6 = FUN_004fff98(1,s_Ranger2_iff_006c167c,unaff_EBP + -0x1c0,0);
    if (cVar6 != '\0') {
      *(byte *)((int)DAT_006e486c + 0x66) = *(byte *)((int)DAT_006e486c + 0x66) | 2;
    }
    FUN_0063558d(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  iVar8 = FUN_00635845(s___expansionshared_sound_HotDate__006c1658,&DAT_006c16d8);
  *(int *)(unaff_EBP + -0x1c) = iVar8;
  if (iVar8 != 0) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    cVar6 = FUN_004fff98(1,s_Ranger3_iff_006c164c,unaff_EBP + -0x1c0,0);
    if (cVar6 != '\0') {
      *(byte *)((int)DAT_006e486c + 0x66) = *(byte *)((int)DAT_006e486c + 0x66) | 4;
    }
    FUN_0063558d(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  iVar8 = FUN_00635845(s___expansionshared_sound_vacsnd_h_006c1628,&DAT_006c16d8);
  *(int *)(unaff_EBP + -0x1c) = iVar8;
  if (iVar8 != 0) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    cVar6 = FUN_004fff98(1,s_Ranger4_iff_006c161c,unaff_EBP + -0x1c0,0);
    if (cVar6 != '\0') {
      *(byte *)((int)DAT_006e486c + 0x66) = *(byte *)((int)DAT_006e486c + 0x66) | 8;
    }
    FUN_0063558d(*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  cVar6 = FUN_004fff98(1,s_RangerD_iff_006c1610,unaff_EBP + -0x1c0,0);
  if (cVar6 != '\0') {
    *(byte *)((int)DAT_006e486c + 0x66) = *(byte *)((int)DAT_006e486c + 0x66) | 0x10;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  iVar8 = FUN_00635845(s___expansionpack5_sound_sep5snds__006c15ec,&DAT_006c16d8);
  if (iVar8 != 0) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    cVar6 = FUN_004fff98(1,s_Ranger5_iff_006c15e0,unaff_EBP + -0x1c0,0);
    if (cVar6 != '\0') {
      *(byte *)((int)DAT_006e486c + 0x66) = *(byte *)((int)DAT_006e486c + 0x66) | 0x20;
    }
    FUN_0063558d(iVar8);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 6;
  cVar6 = FUN_004fff98(1,s_Ranger6_iff_006c15d4,unaff_EBP + -0x1c0,0);
  if (cVar6 != '\0') {
    *(byte *)((int)DAT_006e486c + 0x66) = *(byte *)((int)DAT_006e486c + 0x66) | 0x40;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  *(byte *)((int)DAT_006e486c + 0x66) = *(byte *)((int)DAT_006e486c + 0x66) | 0x80;
  uVar7 = (**(code **)(*(int *)DAT_006e486c[0x12] + 0x34))();
  *(undefined1 *)(DAT_006e486c + 0x1a) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar7;
  cVar6 = FUN_005d6516(s_Use_Split_Fars_006c15c4,0,1);
  if (cVar6 != '\0') {
    *(undefined1 *)(DAT_006e486c + 0x1a) = 1;
  }
  FUN_005d48d9();
  sVar3 = *(short *)((int)DAT_006e486c + 0x66);
  *(undefined4 *)(unaff_EBP + -4) = 7;
  FUN_005d5156(unaff_EBP + -0x154,&DAT_006c08e4,(int)sVar3);
  FUN_004fc0f2(s_SIMS_GAME_EDITION_006c15b0,unaff_EBP + -0x154);
  uVar7 = FUN_0041532c(4,unaff_EBP + -0x148);
  uVar7 = FUN_0041532c(0,uVar7);
  FUN_004ee9ce(uVar7);
  pvVar9 = operator_new(0xe20);
  *(void **)(unaff_EBP + -0x30) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_004b915a();
  }
  piVar5 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  piVar5[5] = iVar8;
  FUN_004b92d8(unaff_EBP + -0x148,1);
  *(int *)(DAT_006e486c[5] + 0x14) = *(int *)(DAT_006e486c[5] + 0x14) + 1;
  FUN_004b9471();
  FUN_004ff6fa(0x6c6f626a,s_Loading_Objects_006c15a0);
  FUN_0046f824(unaff_EBP + -0x2ec,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2f8) = &PTR_FUN_006664e8;
  FUN_004ee9ce(0,0,unaff_EBP + -0x2f8);
  pvVar9 = operator_new(0x1288);
  *(void **)(unaff_EBP + -0x30) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_0043a903();
  }
  piVar5 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  piVar5[10] = iVar8;
  FUN_0043af66(*(undefined4 *)(unaff_EBP + -0x2f4),1);
  FUN_0043e0a9();
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_0043beaa(unaff_EBP + -0x2c);
  uVar7 = FUN_0041532c(3,unaff_EBP + -0x148);
  uVar7 = FUN_0041532c(0,uVar7);
  FUN_004ee9ce(uVar7);
  pvVar9 = operator_new(0x244);
  *(void **)(unaff_EBP + -0x30) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_0046f5cd();
  }
  DAT_006e486c[3] = iVar8;
  piVar5 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  (**(code **)(*(int *)piVar5[3] + 0xc))(unaff_EBP + -0x148,0);
  pcVar11 = *(char **)(unaff_EBP + 0x1c);
  if ((pcVar11 == (char *)0x0) || (sVar10 = _strlen(pcVar11), sVar10 == 0)) {
    pcVar11 = (char *)FUN_0041532c(7);
  }
  uVar7 = FUN_0041532c(0xe,unaff_EBP + -0x148);
  FUN_004ee9ce(pcVar11,uVar7);
  pvVar9 = operator_new(0x1ac);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_00424464();
  }
  piVar5 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  piVar5[9] = iVar8;
  FUN_00424839(unaff_EBP + -0x148);
  FUN_004ff6fa(0x686f7573,s_Initializing_House_006c158c);
  pvVar9 = operator_new(0x70);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_00415b87(DAT_006e486c[9]);
  }
  piVar5 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  *piVar5 = iVar8;
  FUN_00415c5b();
  DAT_006e54d8 = *(undefined4 *)(*DAT_006e486c + 0x18);
  DAT_006e54dc = *(undefined4 *)(*DAT_006e486c + 0x1c);
  DAT_006e486c[7] = *(int *)(*DAT_006e486c + 0x20);
  DAT_006e4f10 = *(undefined4 *)(*DAT_006e486c + 0x14);
  pvVar9 = operator_new(0x24);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_0048461b(*DAT_006e486c);
  }
  piVar5 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  piVar5[6] = iVar8;
  FUN_004ff6fa(0x736e6473,s_Initializing_Sounds_006c1578);
  pvVar9 = operator_new(0x18);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_0057a161();
  }
  piVar5 = DAT_006e486c;
  uVar7 = *(undefined4 *)(unaff_EBP + 0x18);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar4 = *(undefined4 *)(unaff_EBP + 0x14);
  piVar5[4] = iVar8;
  FUN_0057a181(*(undefined4 *)(unaff_EBP + 8),uVar4,uVar7);
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 1) != 0) {
    FUN_0057a5e8(s_ExpansionPack__006c1568);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 2) != 0) {
    FUN_0057a5e8(s_ExpansionPack2_sound__006c1550);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 4) != 0) {
    FUN_0057a5e8(s_ExpansionPack3_sound__006c1538);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 8) != 0) {
    FUN_0057a5e8(s_ExpansionPack4_sound__006c1520);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x10) != 0) {
    FUN_0057a5e8(s_Deluxe_sound__006c1510);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x20) != 0) {
    FUN_0057a5e8(s_ExpansionPack5_sound__006c14f8);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x40) != 0) {
    FUN_0057a5e8(s_ExpansionPack6_sound__006c14e0);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x80) != 0) {
    FUN_0057a5e8(s_ExpansionPack7_sound__006c14c8);
  }
  if (3 < *(short *)((int)DAT_006e486c + 0x66)) {
    FUN_0057a5e8(s_ExpansionShared_sound__006c14b0);
  }
  iVar8 = *(int *)(unaff_EBP + -0x2c);
  if (iVar8 != *(int *)(unaff_EBP + -0x28)) {
    do {
      FUN_0057a5e8(*(undefined4 *)(iVar8 + 4));
      iVar8 = iVar8 + 0x110;
    } while (iVar8 != *(int *)(unaff_EBP + -0x28));
  }
  uVar7 = FUN_0041532c(1,unaff_EBP + -0x148);
  uVar7 = FUN_0041532c(0,uVar7);
  FUN_004ee9ce(uVar7);
  pvVar9 = operator_new(0x28);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  if (pvVar9 == (void *)0x0) {
    DAT_006f0bb8 = 0;
  }
  else {
    DAT_006f0bb8 = FUN_004c714f(unaff_EBP + -0x148);
  }
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_004ff6fa(0x68767772,s_Initializing_House_viewer_006c1494);
  pvVar9 = operator_new(0x520);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_004a6d2d();
  }
  piVar5 = DAT_006e486c;
  uVar7 = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  uVar4 = *(undefined4 *)(unaff_EBP + 0xc);
  piVar5[1] = iVar8;
  FUN_00464479(unaff_EBP + -0x1c8,0,0,uVar4,uVar7);
  FUN_004a72ce(unaff_EBP + -0x1c8,*DAT_006e486c);
  FUN_004ff6fa(0x666c7273,s_Loading_Floors_And_Walls_006c1478);
  pvVar9 = operator_new(0x134);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  if (pvVar9 == (void *)0x0) {
    DAT_006efc64 = 0;
  }
  else {
    DAT_006efc64 = FUN_004a002a();
  }
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_004a01ca();
  pvVar9 = operator_new(0x128);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0x13;
  if (pvVar9 == (void *)0x0) {
    DAT_006f0ba8 = 0;
  }
  else {
    DAT_006f0ba8 = FUN_004c4dcd();
  }
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_004c4f65();
  iVar8 = 0x28;
  do {
    pbVar2 = (byte *)(*(int *)(DAT_006e486c[5] + 8) + 3 + iVar8);
    *pbVar2 = *pbVar2 | 4;
    iVar8 = iVar8 + 4;
  } while (iVar8 < 0x3d8);
  pvVar9 = operator_new(0x24);
  *(void **)(unaff_EBP + 0x1c) = pvVar9;
  *(undefined1 *)(unaff_EBP + -4) = 0x14;
  if (pvVar9 == (void *)0x0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_004c3eea();
  }
  piVar5 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  piVar5[8] = iVar8;
  FUN_004ff6fa(0x76746279,s_Initializing_vitaboy_006c1460);
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  uVar7 = FUN_0041532c(0);
  *(undefined4 *)(unaff_EBP + 0x1c) = uVar7;
  if (3 < *(short *)((int)DAT_006e486c + 0x66)) {
    uVar7 = FUN_0041532c(0x44,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x45,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x46,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x52,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x80) != 0) {
    uVar7 = FUN_0041532c(0x5c,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x5d,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x40) != 0) {
    uVar7 = FUN_0041532c(0x3e,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x3f,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x20) != 0) {
    uVar7 = FUN_0041532c(0x38,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x39,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x10) != 0) {
    uVar7 = FUN_0041532c(0x32,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x33,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 8) != 0) {
    uVar7 = FUN_0041532c(0x2c,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x2d,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 4) != 0) {
    uVar7 = FUN_0041532c(0x26,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x27,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 2) != 0) {
    uVar7 = FUN_0041532c(0x20,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
    uVar7 = FUN_0041532c(0x21,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    *(char **)(unaff_EBP + 0x18) = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(*(char **)(unaff_EBP + -0x144));
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + 0x18),sVar10 + *(int *)(unaff_EBP + 0x18));
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  if ((*(byte *)((int)DAT_006e486c + 0x66) & 1) != 0) {
    uVar7 = FUN_0041532c(0x1d,unaff_EBP + -0x148);
    FUN_004ee9ce(&DAT_006de560,uVar7);
    cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
    if (cVar6 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
    }
    pcVar11 = *(char **)(unaff_EBP + -0x144);
    sVar10 = _strlen(pcVar11);
    FUN_00412d8a(pcVar11,pcVar11 + sVar10);
    sVar10 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  }
  uVar7 = FUN_0041532c(0x16,unaff_EBP + -0x148);
  FUN_004ee9ce(*(undefined4 *)(unaff_EBP + 0x1c),uVar7);
  cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
  if (cVar6 == '\0') {
    FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),1,1);
  }
  pcVar11 = *(char **)(unaff_EBP + -0x144);
  sVar10 = _strlen(pcVar11);
  FUN_00412d8a(pcVar11,pcVar11 + sVar10);
  sVar10 = _strlen(&DAT_006c145c);
  FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  uVar7 = FUN_0041532c(0x15,unaff_EBP + -0x148);
  FUN_004ee9ce(*(undefined4 *)(unaff_EBP + 0x1c),uVar7);
  cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
  if (cVar6 == '\0') {
    FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
  }
  pcVar11 = *(char **)(unaff_EBP + -0x144);
  sVar10 = _strlen(pcVar11);
  FUN_00412d8a(pcVar11,pcVar11 + sVar10);
  sVar10 = _strlen(&DAT_006c145c);
  FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
  uVar7 = FUN_0041532c(0x14,unaff_EBP + -0x148);
  FUN_004ee9ce(*(undefined4 *)(unaff_EBP + 0x1c),uVar7);
  cVar6 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x144));
  if (cVar6 == '\0') {
    FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x144),0,1);
  }
  pcVar11 = *(char **)(unaff_EBP + -0x144);
  sVar10 = _strlen(pcVar11);
  FUN_00412d8a(pcVar11,pcVar11 + sVar10);
  if (*(int *)(unaff_EBP + -0x2c) != *(int *)(unaff_EBP + -0x28)) {
    puVar12 = (undefined4 *)(*(int *)(unaff_EBP + -0x2c) + 4);
    do {
      sVar10 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar10);
      pcVar11 = (char *)*puVar12;
      sVar10 = _strlen(pcVar11);
      FUN_00412d8a(pcVar11,pcVar11 + sVar10);
      cVar6 = FUN_005b9b60(*puVar12);
      if (cVar6 == '\0') {
        FUN_005b92ee(*puVar12,1,1);
      }
      puVar1 = puVar12 + 0x43;
      puVar12 = puVar12 + 0x44;
    } while (puVar1 != *(undefined4 **)(unaff_EBP + -0x28));
  }
  uVar7 = FUN_005c2dfa(*(undefined4 *)(unaff_EBP + -0x18));
  *(undefined1 *)(unaff_EBP + -4) = 0x16;
  FUN_005caef6(uVar7);
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  FUN_005c2ee6();
  FUN_004ee9ce(*(undefined4 *)(unaff_EBP + 0x1c),0,unaff_EBP + -0x148);
  FUN_005bc36d();
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  FUN_005bc41e();
  FUN_00587c6c(DAT_006e486c[0xc],unaff_EBP + -0x148);
  FUN_005bc436();
  FUN_005bc44e(unaff_EBP + -0x34);
  puVar13 = &DAT_006c1458;
  *(undefined1 *)(unaff_EBP + -4) = 0x18;
  uVar7 = FUN_005bc676(&DAT_006c1458);
  FUN_005bc69b(s_Vita_load__006c144c);
  FUN_005bc69b(uVar7);
  FUN_005bc69b(puVar13);
  *(undefined1 *)(unaff_EBP + -4) = 0x17;
  FUN_0042004f();
  *(undefined1 *)(unaff_EBP + -4) = 0x15;
  FUN_005bc3da();
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005b8770();
  cVar6 = FUN_005d6516(s_all_sprites_006c1440,0,1);
  if (cVar6 != '\0') {
    *(undefined1 *)((int)DAT_006e486c + 0x59) = 1;
    FUN_004ff6fa(0x61616161,s_Loading_sprites_006c1430);
    FUN_0043cbde();
  }
  FUN_0040766a(0x8d,0);
  uVar7 = FUN_004643a9();
  FUN_0046f54c(uVar7);
  FUN_0040766a(0x83,0);
  FUN_004ff6fa(0x66676c62,s_Finished_globs_init_006c141c);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00415722();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

