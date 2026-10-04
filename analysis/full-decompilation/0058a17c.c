
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0058a17c(void)

{
  int *piVar1;
  short sVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  ushort uVar12;
  int extraout_ECX;
  int unaff_EBP;
  int iVar13;
  char *pcVar14;
  undefined4 uVar15;
  char *pcVar16;
  
  FUN_00634c24();
  FUN_00636080();
  FUN_0046f824(unaff_EBP + -0x25c,0,0x100);
  *(undefined ***)(unaff_EBP + -0x268) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x368,0,0x100);
  iVar5 = *(int *)(extraout_ECX + 0x138);
  *(undefined ***)(unaff_EBP + -0x374) = &PTR_FUN_00666524;
  if ((*(ushort *)(*(int *)(iVar5 + 0x118) + 0xcc) & 8) != 0) {
    iVar5 = (int)*(short *)(iVar5 + 0x59c);
    if (0 < iVar5) {
      *(undefined1 *)(extraout_ECX + 0xd9) = 1;
      *(undefined1 *)(extraout_ECX + 0x109) = 1;
      if ((*(int *)(extraout_ECX + 8) != 0) &&
         (iVar13 = *(int *)(*(int *)(extraout_ECX + 8) + 4), iVar13 != 0)) {
        *(undefined4 *)(iVar13 + 0x94) = 1;
      }
      if (*(int *)(extraout_ECX + 0x1b0) != iVar5) {
        *(int *)(extraout_ECX + 0x1b0) = iVar5;
        FUN_00455edc(iVar5 + 1,unaff_EBP + -0x268,unaff_EBP + -0x374,0);
        if (*(int *)(extraout_ECX + 8) != 0) {
          uVar6 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x370));
          *(undefined4 *)(unaff_EBP + -4) = 0;
          uVar7 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x264));
          uVar15 = *(undefined4 *)(*(int *)(extraout_ECX + 8) + 4);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0058372c(DAT_006f6b64,uVar15,uVar7,uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
      }
    }
    goto LAB_0058d78e;
  }
  if (iVar5 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = *(ushort *)(iVar5 + 0x60e);
  }
  if (((uVar12 & 6) != 0) && (*(short *)(iVar5 + 0x59c) != 0)) {
    *(undefined2 *)(iVar5 + 0x59c) = 0;
  }
  if ((((*(char *)(unaff_EBP + 8) == '\0') &&
       (iVar5 = *(int *)(extraout_ECX + 0x138),
       *(int *)(extraout_ECX + 0x1b0) == (int)*(short *)(iVar5 + 0x59c))) &&
      (*(int *)(extraout_ECX + 0x1b4) == (int)*(short *)(iVar5 + 0x5b6))) &&
     ((*(int *)(extraout_ECX + 0x1b8) == (int)*(short *)(iVar5 + 0x5b8) &&
      (*(int *)(extraout_ECX + 0x1bc) == (int)*(short *)(iVar5 + 0x5ba))))) goto LAB_0058d78e;
  FUN_0046f824(unaff_EBP + -0x2594,0,0x100);
  *(undefined ***)(unaff_EBP + -0x25a0) = &PTR_FUN_00666524;
  *(int *)(unaff_EBP + 8) = unaff_EBP + -0x2494;
  *(undefined4 *)(unaff_EBP + -0x144) = 2;
  do {
    FUN_0046f824(*(int *)(unaff_EBP + 8) + 0xc,0,0x100);
    puVar9 = *(undefined4 **)(unaff_EBP + 8);
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x10c;
    piVar1 = (int *)(unaff_EBP + -0x144);
    *piVar1 = *piVar1 + -1;
    iVar5 = *piVar1;
    *puVar9 = &PTR_FUN_00666524;
  } while (iVar5 != 0);
  *(undefined4 *)(unaff_EBP + -0x144) = 2;
  *(int *)(unaff_EBP + 8) = unaff_EBP + -0x7b4;
  do {
    FUN_0046f824(*(int *)(unaff_EBP + 8) + 0xc,0,0x100);
    puVar9 = *(undefined4 **)(unaff_EBP + 8);
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x10c;
    piVar1 = (int *)(unaff_EBP + -0x144);
    *piVar1 = *piVar1 + -1;
    iVar5 = *piVar1;
    *puVar9 = &PTR_FUN_00666524;
  } while (iVar5 != 0);
  FUN_0046f824(unaff_EBP + -0x590,0,0x100);
  *(undefined ***)(unaff_EBP + -0x59c) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x484,0,0x100);
  *(undefined ***)(unaff_EBP + -0x490) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x9cc,0,0x100);
  *(undefined2 *)(unaff_EBP + -0x9d0) = 0;
  *(undefined ***)(unaff_EBP + -0x9d8) = &PTR_FUN_00666524;
  **(undefined1 **)(unaff_EBP + -0x9d4) = 0;
  *(undefined1 *)(extraout_ECX + 0xd9) = 1;
  FUN_00455edc(3,unaff_EBP + -0x59c,unaff_EBP + -0x490,0);
  *(int *)(extraout_ECX + 0x1b8) = (int)*(short *)(*(int *)(extraout_ECX + 0x138) + 0x5b8);
  FUN_0046f824(unaff_EBP + -0x50,0,0x40);
  *(undefined ***)(unaff_EBP + -0x5c) = &PTR_FUN_0066651c;
  FUN_0046f824(unaff_EBP + -0x9c,0,0x40);
  *(undefined ***)(unaff_EBP + -0xa8) = &PTR_FUN_0066651c;
  FUN_00408b9d();
  iVar5 = *(int *)(extraout_ECX + 0x1b8);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (iVar5 == 0) {
LAB_0058a4e1:
    *(undefined4 *)(unaff_EBP + 8) = 0x12;
  }
  else if (iVar5 == 1) {
    *(undefined4 *)(unaff_EBP + 8) = 0x14;
  }
  else if (iVar5 == 2) {
    *(undefined4 *)(unaff_EBP + 8) = 0x16;
  }
  else if (iVar5 == 3) {
    *(undefined4 *)(unaff_EBP + 8) = 0x18;
  }
  else {
    if (iVar5 != 4) goto LAB_0058a4e1;
    *(undefined4 *)(unaff_EBP + 8) = 0x1a;
  }
  iVar5 = (int)*(short *)(*(int *)(extraout_ECX + 0x138) + 0x5ba);
  *(int *)(extraout_ECX + 0x1bc) = iVar5;
  if (iVar5 == 0) {
LAB_0058a5d1:
    uVar15 = 0x13;
    if (iVar5 != 3) goto LAB_0058a525;
LAB_0058a5dd:
    FUN_0046f824(unaff_EBP + -0x8c0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x8cc) = &PTR_FUN_00666524;
    FUN_0046f847(s_nohandr_006d173c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x8cc);
    FUN_0046f824(unaff_EBP + -0x8c0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x8cc) = &PTR_FUN_00666524;
    FUN_0046f847(s_nohand_006d1744,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x8cc);
  }
  else {
    if (iVar5 == 1) {
      uVar15 = 0x15;
    }
    else if (iVar5 == 2) {
      uVar15 = 0x17;
    }
    else {
      if (iVar5 == 3) goto LAB_0058a5dd;
      if (iVar5 != 4) goto LAB_0058a5d1;
      uVar15 = 0x1b;
    }
LAB_0058a525:
    FUN_00455edc(uVar15,unaff_EBP + -0x2388,unaff_EBP + -0x6a8,0);
  }
  if (*(int *)(extraout_ECX + 0x1b8) == 3) {
    FUN_0046f824(unaff_EBP + -0x8c0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x8cc) = &PTR_FUN_00666524;
    FUN_0046f847(s_nohandl_006d174c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x8cc);
    FUN_0046f824(unaff_EBP + -0x8c0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x8cc) = &PTR_FUN_00666524;
    FUN_0046f847(s_nohand_006d1744,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x8cc);
  }
  else {
    FUN_00455edc(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x2494,unaff_EBP + -0x7b4,0);
  }
  iVar5 = (int)*(short *)(*(int *)(extraout_ECX + 0x138) + 0x59c);
  *(int *)(extraout_ECX + 0x1b0) = iVar5;
  *(int *)(extraout_ECX + 0x1b4) = (int)*(short *)(*(int *)(extraout_ECX + 0x138) + 0x5b6);
  switch(iVar5) {
  default:
    goto code_r0x0058d47b;
  case 1:
    iVar5 = unaff_EBP + -0x374;
    iVar13 = unaff_EBP + -0x268;
    uVar15 = 0x10;
    goto code_r0x0058d48b;
  case 2:
    pcVar16 = &DAT_006de560;
    pcVar14 = (char *)FUN_004705f2(0x20,0xffffffff);
    iVar8 = _strcmp(pcVar14,pcVar16);
    iVar5 = unaff_EBP + -0x374;
    iVar13 = unaff_EBP + -0x268;
    if (iVar8 == 0) {
      uVar15 = 0x11;
    }
    else {
      uVar15 = 0x20;
    }
    goto code_r0x0058d48b;
  case 3:
    FUN_0045efcb(unaff_EBP + -0x268,unaff_EBP + -0x374,unaff_EBP + -0x25a0);
    goto code_r0x0058d496;
  case 4:
    uVar15 = FUN_004705f2(0xe,0xffffffff);
    iVar5 = FUN_00635f62(uVar15);
    if (iVar5 < 0x12) {
      iVar5 = unaff_EBP + -0x374;
      iVar13 = unaff_EBP + -0x268;
      uVar15 = 0x1c;
    }
    else {
      pcVar16 = &DAT_006de560;
      pcVar14 = (char *)FUN_004705f2(0x1f,0xffffffff);
      iVar5 = _strcmp(pcVar14,pcVar16);
      if (iVar5 == 0) {
        FUN_00455edc(0x1c,unaff_EBP + -0x268,unaff_EBP + -0x374,0);
        FUN_00455edc(0x1d,unaff_EBP + -0x2494,unaff_EBP + -0x7b4,0);
        iVar5 = unaff_EBP + -0x6a8;
        iVar13 = unaff_EBP + -0x2388;
        uVar15 = 0x1e;
      }
      else {
        iVar5 = unaff_EBP + -0x374;
        iVar13 = unaff_EBP + -0x268;
        uVar15 = 0x1f;
      }
    }
    goto code_r0x0058d48b;
  case 5:
    pcVar16 = &DAT_006de560;
    pcVar14 = (char *)FUN_004705f2(0x21,0xffffffff);
    iVar5 = _strcmp(pcVar14,pcVar16);
    if (iVar5 != 0) {
      iVar5 = unaff_EBP + -0x374;
      iVar13 = unaff_EBP + -0x268;
      uVar15 = 0x21;
      goto code_r0x0058d48b;
    }
    FUN_0045f1a0(unaff_EBP + -0x268,unaff_EBP + -0x374);
    goto code_r0x0058d496;
  case 6:
    uVar15 = 0;
    goto code_r0x0058a859;
  case 7:
    uVar15 = 1;
code_r0x0058a859:
    FUN_0045f2c6(uVar15,unaff_EBP + -0x268,unaff_EBP + -0x374,unaff_EBP + -0x59c,unaff_EBP + -0x490,
                 unaff_EBP + -0x7b4);
    iVar5 = unaff_EBP + -0x7b4;
    goto code_r0x0058d472;
  case 8:
    pcVar14 = (char *)0x6cba50;
    goto code_r0x0058a8e6;
  case 9:
    pcVar14 = (char *)0x6cba4c;
    goto code_r0x0058a8e6;
  case 10:
    pcVar14 = (char *)0x6cba44;
    goto code_r0x0058a8e6;
  case 0xb:
    pcVar14 = (char *)0x6cba3c;
    goto code_r0x0058a8e6;
  case 0xc:
    pcVar14 = (char *)0x6cba34;
    goto code_r0x0058a8e6;
  case 0xd:
    pcVar14 = (char *)0x6cba2c;
    goto code_r0x0058a8e6;
  case 0xe:
    pcVar14 = (char *)0x6cba24;
    goto code_r0x0058a8e6;
  case 0xf:
    pcVar14 = (char *)0x6cba18;
    goto code_r0x0058a8e6;
  case 0x10:
    pcVar14 = s_disco_006cba1c;
code_r0x0058a8e6:
    FUN_0046f847(pcVar14,0xffffffff);
    FUN_0045f5be(unaff_EBP + -0x268,unaff_EBP + -0x374,unaff_EBP + -0x9d8,
                 (int)*(short *)(*(int *)(extraout_ECX + 0x138) + 0x5b6));
    goto code_r0x0058d496;
  case 0x11:
    iVar5 = unaff_EBP + -0x374;
    iVar13 = unaff_EBP + -0x268;
    uVar15 = 0x22;
    goto code_r0x0058d48b;
  case 0x12:
    iVar5 = unaff_EBP + -0x374;
    iVar13 = unaff_EBP + -0x268;
    uVar15 = 0x23;
    goto code_r0x0058d48b;
  case 0x13:
    FUN_0046f824(unaff_EBP + -0x1db0,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1dbc) = &PTR_FUN_0066651c;
    FUN_0046f847(s_superstar_gaFit_movieactor1_006d1720,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1dbc);
    FUN_0046f824(unaff_EBP + -0x1e48,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1e54) = &PTR_FUN_0066651c;
    FUN_0046f847(s_superstar_gaFit_c_movieactor1_006d1700,0xffffffff);
    iVar5 = unaff_EBP + -0x1e54;
    break;
  case 0x14:
    FUN_0046f824(unaff_EBP + -0x1ee0,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1eec) = &PTR_FUN_0066651c;
    FUN_0046f847(s_superstar_gaFit_movieactor2_006d16e4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1eec);
    FUN_0046f824(unaff_EBP + -0x1f78,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1f84) = &PTR_FUN_0066651c;
    FUN_0046f847(s_superstar_gaFit_c_movieactor2_006d16c4,0xffffffff);
    iVar5 = unaff_EBP + -0x1f84;
    break;
  case 0x15:
    FUN_0046f824(unaff_EBP + -0x2010,0,0x40);
    *(undefined ***)(unaff_EBP + -0x201c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_superstar_gaFit_movieactor3_006d16a8,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x201c);
    FUN_0046f824(unaff_EBP + -0x20a8,0,0x40);
    *(undefined ***)(unaff_EBP + -0x20b4) = &PTR_FUN_0066651c;
    FUN_0046f847(s_superstar_gaFit_c_movieactor3_006d1688,0xffffffff);
    iVar5 = unaff_EBP + -0x20b4;
    break;
  case 0x16:
    FUN_0046f824(unaff_EBP + -0x2140,0,0x40);
    *(undefined ***)(unaff_EBP + -0x214c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_Doctor_006d1670,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x214c);
    FUN_0046f824(unaff_EBP + -0x21d8,0,0x40);
    *(undefined ***)(unaff_EBP + -0x21e4) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_c_Doctor_006d1654,0xffffffff);
    iVar5 = unaff_EBP + -0x21e4;
    break;
  case 0x17:
    FUN_0046f824(unaff_EBP + -0x1ccc,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1cd8) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_Relative_006d1638,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1cd8);
    FUN_0046f824(unaff_EBP + -0x2270,0,0x40);
    *(undefined ***)(unaff_EBP + -0x227c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_c_Relative_006d161c,0xffffffff);
    iVar5 = unaff_EBP + -0x227c;
    break;
  case 0x18:
    FUN_0046f824(unaff_EBP + -0xafc,0,0x40);
    *(undefined ***)(unaff_EBP + -0xb08) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Coffee_006d1608,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xb08);
    FUN_0046f824(unaff_EBP + -0x1728,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1734) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Coffee_006d15f0,0xffffffff);
    iVar5 = unaff_EBP + -0x1734;
    break;
  case 0x19:
    FUN_0046f824(unaff_EBP + -0xb94,0,0x40);
    *(undefined ***)(unaff_EBP + -0xba0) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Floral_006d15dc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xba0);
    FUN_0046f824(unaff_EBP + -0x1774,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1780) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Floral_006d15c4,0xffffffff);
    iVar5 = unaff_EBP + -0x1780;
    break;
  case 0x1a:
    FUN_0046f824(unaff_EBP + -0xc2c,0,0x40);
    *(undefined ***)(unaff_EBP + -0xc38) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Architectural_006d15a8,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xc38);
    FUN_0046f824(unaff_EBP + -0x1fc4,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1fd0) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Architectural_006d1588,0xffffffff);
    iVar5 = unaff_EBP + -0x1fd0;
    break;
  case 0x1b:
    FUN_0046f824(unaff_EBP + -0xcc4,0,0x40);
    *(undefined ***)(unaff_EBP + -0xcd0) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Formal1_006d1570,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xcd0);
    FUN_0046f824(unaff_EBP + -0x180c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1818) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Formal1_006d1558,0xffffffff);
    iVar5 = unaff_EBP + -0x1818;
    break;
  case 0x1c:
    FUN_0046f824(unaff_EBP + -0xd5c,0,0x40);
    *(undefined ***)(unaff_EBP + -0xd68) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Formal2_006d1540,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xd68);
    FUN_0046f824(unaff_EBP + -0x1d64,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1d70) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Formal2_006d1528,0xffffffff);
    iVar5 = unaff_EBP + -0x1d70;
    break;
  case 0x1d:
    FUN_0046f824(unaff_EBP + -0xdf4,0,0x40);
    *(undefined ***)(unaff_EBP + -0xe00) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Formal3_006d1510,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xe00);
    FUN_0046f824(unaff_EBP + -0x18a4,0,0x40);
    *(undefined ***)(unaff_EBP + -0x18b0) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Formal3_006d14f8,0xffffffff);
    iVar5 = unaff_EBP + -0x18b0;
    break;
  case 0x1e:
    FUN_0046f824(unaff_EBP + -0xe8c,0,0x40);
    *(undefined ***)(unaff_EBP + -0xe98) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Lingerie1_006d14e0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xe98);
    FUN_0046f824(unaff_EBP + -0x2224,0,0x40);
    *(undefined ***)(unaff_EBP + -0x2230) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Lingerie1_006d14c4,0xffffffff);
    iVar5 = unaff_EBP + -0x2230;
    break;
  case 0x1f:
    FUN_0046f824(unaff_EBP + -0xf24,0,0x40);
    *(undefined ***)(unaff_EBP + -0xf30) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Lingerie2_006d14ac,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xf30);
    FUN_0046f824(unaff_EBP + -0x193c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1948) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Lingerie2_006d1490,0xffffffff);
    iVar5 = unaff_EBP + -0x1948;
    break;
  case 0x20:
    FUN_0046f824(unaff_EBP + -0xfbc,0,0x40);
    *(undefined ***)(unaff_EBP + -0xfc8) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_Lingerie3_006d1478,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xfc8);
    FUN_0046f824(unaff_EBP + -0x1dfc,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1e08) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Runway_gAfit_c_Lingerie3_006d145c,0xffffffff);
    iVar5 = unaff_EBP + -0x1e08;
    break;
  case 0x21:
    FUN_0046f824(unaff_EBP + -0x1054,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1060) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_JumpSuit_006d1440,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1060);
    FUN_0046f824(unaff_EBP + -0x19d4,0,0x40);
    *(undefined ***)(unaff_EBP + -0x19e0) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_c_JumpSuit_006d1424,0xffffffff);
    iVar5 = unaff_EBP + -0x19e0;
    break;
  case 0x22:
    FUN_0046f824(unaff_EBP + -0x10ec,0,0x40);
    *(undefined ***)(unaff_EBP + -0x10f8) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_WetSuit_006d140c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x10f8);
    FUN_0046f824(unaff_EBP + -0x205c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x2068) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_c_WetSuit_006d13f0,0xffffffff);
    iVar5 = unaff_EBP + -0x2068;
    break;
  case 0x23:
    FUN_0046f824(unaff_EBP + -0x1184,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1190) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAFit_BackupDancerDanc_006d13cc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1190);
    FUN_0046f824(unaff_EBP + -0x1a6c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1a78) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAFit_c_BackupDancerDa_006d13a8,0xffffffff);
    iVar5 = unaff_EBP + -0x1a78;
    break;
  case 0x24:
    FUN_0046f824(unaff_EBP + -0x121c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1228) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_BackupDancerPop_006d1388,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1228);
    FUN_0046f824(unaff_EBP + -0x1e94,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1ea0) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_c_BackupDancerPo_006d1364,0xffffffff);
    iVar5 = unaff_EBP + -0x1ea0;
    break;
  case 0x25:
    FUN_0046f824(unaff_EBP + -0x12b4,0,0x40);
    *(undefined ***)(unaff_EBP + -0x12c0) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_BackupDancerRock_006d1340,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x12c0);
    FUN_0046f824(unaff_EBP + -0x1b04,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1b10) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Superstar_gAfit_c_BackupDancerRo_006d131c,0xffffffff);
    iVar5 = unaff_EBP + -0x1b10;
    break;
  case 0x26:
    FUN_0046f824(unaff_EBP + -0x134c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1358) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFat_BeeKeeper_006d1304,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1358);
    FUN_0046f824(unaff_EBP + -0x218c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x2198) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFat_BeeKeeper_006d1304,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x2198);
    FUN_0046f824(unaff_EBP + -0x8c0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x8cc) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_BeeKeeper_006d12f4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x8cc);
    FUN_0046f824(unaff_EBP + -0x26a0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x26ac) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_BeeKeeper_006d12f4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x26ac);
    FUN_00409377(*(undefined4 *)(*(int *)(extraout_ECX + 0x138) + 0x11c),0);
    FUN_0040e630(unaff_EBP + -0x5c);
    FUN_0040e6d6(unaff_EBP + -0xa8);
    goto code_r0x0058d41a;
  case 0x27:
    FUN_0046f824(unaff_EBP + -0x13e4,0,0x40);
    *(undefined ***)(unaff_EBP + -0x13f0) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_BlueGenie_006d12dc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x13f0);
    FUN_0046f824(unaff_EBP + -0x1b9c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1ba8) = &PTR_FUN_0066651c;
    FUN_0046f847(s_BMagic_gAFit_BlueGenie_006d12c4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1ba8);
    FUN_0046f824(unaff_EBP + -0x7848,0,0x100);
    *(undefined ***)(unaff_EBP + -0x7854) = &PTR_FUN_00666524;
    FUN_0046f847(s_H_gA_h_BlueGenie_006d12b0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x7854);
    FUN_0046f824(unaff_EBP + -0x7a60,0,0x100);
    *(undefined ***)(unaff_EBP + -0x7a6c) = &PTR_FUN_00666524;
    FUN_0046f847(s_H_gA_h_BlueGenie_006d12b0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x7a6c);
    FUN_0046f824(unaff_EBP + -0x518c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x5198) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagic_gA_BlueGenie_006d129c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x5198);
    FUN_0046f824(unaff_EBP + -0x29c4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x29d0) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagic_gAFit_BlueGenie_006d1284,0xffffffff);
    iVar5 = unaff_EBP + -0x29d0;
    goto code_r0x0058d3b7;
  case 0x28:
    FUN_0046f824(unaff_EBP + -0x147c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1488) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFit_Minotaur_006d1270,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1488);
    FUN_0046f824(unaff_EBP + -0x1f2c,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1f38) = &PTR_FUN_0066651c;
    FUN_0046f847(s_BMagicMAFit_Minotaur_006d1258,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1f38);
    FUN_0046f824(unaff_EBP + -0x667c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6688) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMAFit_Minotaur_006d1240,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6688);
    FUN_0046f824(unaff_EBP + -0x2bdc,0,0x100);
    *(undefined ***)(unaff_EBP + -0x2be8) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMAFit_Minotaur_006d1240,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x2be8);
    FUN_0046f824(unaff_EBP + -0x53a4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x53b0) = &PTR_FUN_00666524;
    FUN_0046f847(s_HMA_h_Minotaur_006d1230,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x53b0);
    FUN_0046f824(unaff_EBP + -0x2df4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x2e00) = &PTR_FUN_00666524;
    FUN_0046f847(s_HMA_h_Minotaur_006d1230,0xffffffff);
    iVar5 = unaff_EBP + -0x2e00;
    goto code_r0x0058d3b7;
  case 0x29:
    FUN_0046f824(unaff_EBP + -0x1514,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1520) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_Spookshow_006d1218,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1520);
    FUN_0046f824(unaff_EBP + -0x1c34,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1c40) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_c_Spookshow_006d1200,0xffffffff);
    iVar5 = unaff_EBP + -0x1c40;
    break;
  case 0x2a:
    FUN_0046f824(unaff_EBP + -0x15ac,0,0x40);
    *(undefined ***)(unaff_EBP + -0x15b8) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_SideShow_006d11e8,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x15b8);
    FUN_0046f824(unaff_EBP + -0x20f4,0,0x40);
    *(undefined ***)(unaff_EBP + -0x2100) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_c_SideShow_006d11d0,0xffffffff);
    iVar5 = unaff_EBP + -0x2100;
    break;
  case 0x2b:
    FUN_0046f824(unaff_EBP + -0x1430,0,0x40);
    *(undefined ***)(unaff_EBP + -0x143c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFAFit_Vampire_006d0f68,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x143c);
    FUN_0046f824(unaff_EBP + -0x14c8,0,0x40);
    *(undefined ***)(unaff_EBP + -0x14d4) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFAFit_Vampire_006d0f68,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x14d4);
    FUN_0046f824(unaff_EBP + -0x3978,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3984) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFAFit_Vampire_006d0f54,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x3984);
    FUN_0046f824(unaff_EBP + -0x3b90,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3b9c) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFAFit_Vampire_006d0f54,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x3b9c);
    FUN_0046f824(unaff_EBP + -0x3da8,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3db4) = &PTR_FUN_00666524;
    FUN_0046f847(s_HFA_h_Vampire_006d0f44,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x3db4);
    FUN_0046f824(unaff_EBP + -0x3fc0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3fcc) = &PTR_FUN_00666524;
    FUN_0046f847(s_HFA_h_Vampire_006d0f44,0xffffffff);
    iVar5 = unaff_EBP + -0x3fcc;
    goto code_r0x0058d3b7;
  case 0x2c:
    FUN_0046f824(unaff_EBP + -0x1560,0,0x40);
    *(undefined ***)(unaff_EBP + -0x156c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_Werewolf_006d0f2c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x156c);
    FUN_0046f824(unaff_EBP + -0x15f8,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1604) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_Werewolf_006d0f2c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1604);
    FUN_0046f824(unaff_EBP + -0x41d8,0,0x100);
    *(undefined ***)(unaff_EBP + -0x41e4) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagic_gAFit_Werewolf_006d0f14,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x41e4);
    FUN_0046f824(unaff_EBP + -0x43f0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x43fc) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagic_gAFit_Werewolf_006d0f14,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x43fc);
    FUN_0046f824(unaff_EBP + -0x4608,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4614) = &PTR_FUN_00666524;
    FUN_0046f847(s_HMA_h_Werewolf_006d0f04,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x4614);
    FUN_0046f824(unaff_EBP + -0x4820,0,0x100);
    *(undefined ***)(unaff_EBP + -0x482c) = &PTR_FUN_00666524;
    FUN_0046f847(s_HMA_h_Werewolf_006d0f04,0xffffffff);
    iVar5 = unaff_EBP + -0x482c;
    goto code_r0x0058d3b7;
  case 0x2d:
    FUN_0046f824(unaff_EBP + -0x1858,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1864) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFit_Headless_006d0eb0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1864);
    FUN_0046f824(unaff_EBP + -0x18f0,0,0x40);
    *(undefined ***)(unaff_EBP + -0x18fc) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFit_Headless_006d0eb0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x18fc);
    FUN_0046f824(unaff_EBP + -0x5298,0,0x100);
    *(undefined ***)(unaff_EBP + -0x52a4) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMA_Headless_006d0fac,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x52a4);
    FUN_0046f824(unaff_EBP + -0x54b0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x54bc) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMA_Headless_006d0fac,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x54bc);
    FUN_0046f824(unaff_EBP + -0x56c8,0,0x100);
    *(undefined ***)(unaff_EBP + -0x56d4) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Headless_006d0ea0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x56d4);
    FUN_0046f824(unaff_EBP + -0x58e0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x58ec) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Headless_006d0ea0,0xffffffff);
    iVar5 = unaff_EBP + -0x58ec;
    goto code_r0x0058d3b7;
  case 0x2e:
    FUN_0046f824(unaff_EBP + -0x1644,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1650) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFat_Troll_006d11bc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1650);
    FUN_0046f824(unaff_EBP + -0x16dc,0,0x40);
    *(undefined ***)(unaff_EBP + -0x16e8) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFat_Troll_006d11bc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x16e8);
    FUN_0046f824(unaff_EBP + -0x70f4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x7100) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMAFat_Troll_006d11a8,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x7100);
    FUN_0046f824(unaff_EBP + -0x300c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3018) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMAFat_Troll_006d11a8,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x3018);
    FUN_0046f824(unaff_EBP + -0x55bc,0,0x100);
    *(undefined ***)(unaff_EBP + -0x55c8) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Troll_006d119c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x55c8);
    FUN_0046f824(unaff_EBP + -0x3224,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3230) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Troll_006d119c,0xffffffff);
    iVar5 = unaff_EBP + -0x3230;
    goto code_r0x0058d3b7;
  case 0x2f:
    FUN_0046f824(unaff_EBP + -0x1690,0,0x40);
    *(undefined ***)(unaff_EBP + -0x169c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFat_Hunchback_006d0eec,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x169c);
    FUN_0046f824(unaff_EBP + -0x17c0,0,0x40);
    *(undefined ***)(unaff_EBP + -0x17cc) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFat_Hunchback_006d0eec,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x17cc);
    FUN_0046f824(unaff_EBP + -19000,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4a44) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMAFat_Hunchback_006d0ed4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x4a44);
    FUN_0046f824(unaff_EBP + -0x4c50,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4c5c) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMAFat_Hunchback_006d0ed4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x4c5c);
    FUN_0046f824(unaff_EBP + -0x4e68,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4e74) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Hunchback_006d0ec4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x4e74);
    FUN_0046f824(unaff_EBP + -0x5080,0,0x100);
    *(undefined ***)(unaff_EBP + -0x508c) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Hunchback_006d0ec4,0xffffffff);
    iVar5 = unaff_EBP + -0x508c;
    goto code_r0x0058d3b7;
  case 0x30:
    FUN_0046f824(unaff_EBP + -0xda8,0,0x40);
    *(undefined ***)(unaff_EBP + -0xdb4) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_Sorcerer_006d10a8,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xdb4);
    FUN_0046f824(unaff_EBP + -0xe40,0,0x40);
    *(undefined ***)(unaff_EBP + -0xe4c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_Magic_gAFit_Sorcerer_006d10a8,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xe4c);
    FUN_0046f824(unaff_EBP + -0x730c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x7318) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagic_gAFit_Sorcerer_006d1090,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x7318);
    FUN_0046f824(unaff_EBP + -0x40cc,0,0x100);
    *(undefined ***)(unaff_EBP + -0x40d8) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagic_gAFit_Sorcerer_006d1090,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x40d8);
    FUN_0046f824(unaff_EBP + -0x5e1c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x5e28) = &PTR_FUN_00666524;
    FUN_0046f847(s_HMA_h_Sorcerer_006d1080,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x5e28);
    FUN_0046f824(unaff_EBP + -0x42e4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x42f0) = &PTR_FUN_00666524;
    FUN_0046f847(s_HMA_h_Sorcerer_006d1080,0xffffffff);
    iVar5 = unaff_EBP + -0x42f0;
    goto code_r0x0058d3b7;
  case 0x31:
    FUN_0046f824(unaff_EBP + -0x1988,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1994) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFAFit_Witch_006d0e8c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1994);
    FUN_0046f824(unaff_EBP + -0x1a20,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1a2c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFAFit_Witch_006d0e8c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1a2c);
    FUN_0046f824(unaff_EBP + -0x5af8,0,0x100);
    *(undefined ***)(unaff_EBP + -0x5b04) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFAFit_Witch_006d0e78,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x5b04);
    FUN_0046f824(unaff_EBP + -0x5d10,0,0x100);
    *(undefined ***)(unaff_EBP + -0x5d1c) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFAFit_Witch_006d0e78,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x5d1c);
    FUN_0046f824(unaff_EBP + -0x5f28,0,0x100);
    *(undefined ***)(unaff_EBP + -0x5f34) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Hunchback_006d0ec4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x5f34);
    FUN_0046f824(unaff_EBP + -0x6140,0,0x100);
    *(undefined ***)(unaff_EBP + -0x614c) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Hunchback_006d0ec4,0xffffffff);
    iVar5 = unaff_EBP + -0x614c;
    goto code_r0x0058d3b7;
  case 0x32:
    FUN_0046f824(unaff_EBP + -0xa64,0,0x40);
    *(undefined ***)(unaff_EBP + -0xa70) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFAFat_Ogress_006d1188,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xa70);
    FUN_0046f824(unaff_EBP + -0xab0,0,0x40);
    *(undefined ***)(unaff_EBP + -0xabc) = &PTR_FUN_0066651c;
    FUN_0046f847(s_BMagicFAFat_Ogress_006d1174,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xabc);
    FUN_0046f824(unaff_EBP + -0x6894,0,0x100);
    *(undefined ***)(unaff_EBP + -0x68a0) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFAFat_Ogress_006d1160,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x68a0);
    FUN_0046f824(unaff_EBP + -0x343c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3448) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFAFat_Ogress_006d1160,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x3448);
    FUN_0046f824(unaff_EBP + -0x57d4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x57e0) = &PTR_FUN_00666524;
    FUN_0046f847(s_HFA_h_Ogress_006d1150,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x57e0);
    FUN_0046f824(unaff_EBP + -0x3654,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3660) = &PTR_FUN_00666524;
    FUN_0046f847(s_HFA_h_Ogress_006d1150,0xffffffff);
    iVar5 = unaff_EBP + -0x3660;
    goto code_r0x0058d3b7;
  case 0x33:
    FUN_0046f824(unaff_EBP + -0xb48,0,0x40);
    *(undefined ***)(unaff_EBP + -0xb54) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFASkn_Crone_006d113c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xb54);
    FUN_0046f824(unaff_EBP + -0xbe0,0,0x40);
    *(undefined ***)(unaff_EBP + -0xbec) = &PTR_FUN_0066651c;
    FUN_0046f847(s_BMagicFASkn_Crone_006d1128,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xbec);
    FUN_0046f824(unaff_EBP + -0x7954,0,0x100);
    *(undefined ***)(unaff_EBP + -0x7960) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFASkn_Crone_006d1114,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x7960);
    FUN_0046f824(unaff_EBP + -0x386c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3878) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFASkn_Crone_006d1114,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x3878);
    FUN_0046f824(unaff_EBP + -0x59ec,0,0x100);
    *(undefined ***)(unaff_EBP + -0x59f8) = &PTR_FUN_00666524;
    FUN_0046f847(s_HFA_h_Crone_006d1108,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x59f8);
    FUN_0046f824(unaff_EBP + -0x3a84,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3a90) = &PTR_FUN_00666524;
    FUN_0046f847(s_HFA_h_Crone_006d1108,0xffffffff);
    iVar5 = unaff_EBP + -0x3a90;
    goto code_r0x0058d3b7;
  case 0x34:
    FUN_0046f824(unaff_EBP + -0xc78,0,0x40);
    *(undefined ***)(unaff_EBP + -0xc84) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFASkn_Nymph_006d10f4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xc84);
    FUN_0046f824(unaff_EBP + -0xd10,0,0x40);
    *(undefined ***)(unaff_EBP + -0xd1c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_BMagicFASkn_Nymph_006d10e0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xd1c);
    FUN_0046f824(unaff_EBP + -0x6aac,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6ab8) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFASkn_Nymph_006d10cc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6ab8);
    FUN_0046f824(unaff_EBP + -0x3c9c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3ca8) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFASkn_Nymph_006d10cc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x3ca8);
    FUN_0046f824(unaff_EBP + -0x5c04,0,0x100);
    *(undefined ***)(unaff_EBP + -0x5c10) = &PTR_FUN_00666524;
    FUN_0046f847(0x6d10c0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x5c10);
    FUN_0046f824(unaff_EBP + -0x3eb4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x3ec0) = &PTR_FUN_00666524;
    FUN_0046f847(0x6d10c0,0xffffffff);
    iVar5 = unaff_EBP + -0x3ec0;
    goto code_r0x0058d3b7;
  case 0x35:
    FUN_0046f824(unaff_EBP + -0x1008,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1014) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMCChd_Goblin_006d102c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1014);
    FUN_0046f824(unaff_EBP + -0x10a0,0,0x40);
    *(undefined ***)(unaff_EBP + -0x10ac) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMCChd_Goblin_006d102c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x10ac);
    FUN_0046f824(unaff_EBP + -0x773c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x7748) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMCChd_Goblin_006d1018,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x7748);
    FUN_0046f824(unaff_EBP + -0x492c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4938) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMCChd_Goblin_006d1018,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x4938);
    FUN_0046f824(unaff_EBP + -0x624c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6258) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUC_h_Goblin_006d1008,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6258);
    FUN_0046f824(unaff_EBP + -0x4b44,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4b50) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUC_h_Goblin_006d1008,0xffffffff);
    iVar5 = unaff_EBP + -0x4b50;
    goto code_r0x0058d3b7;
  case 0x36:
    FUN_0046f824(unaff_EBP + -0xed8,0,0x40);
    *(undefined ***)(unaff_EBP + -0xee4) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFCChd_WizardGirl_006d1068,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xee4);
    FUN_0046f824(unaff_EBP + -0xf70,0,0x40);
    *(undefined ***)(unaff_EBP + -0xf7c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicFCChd_WizardGirl_006d1068,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xf7c);
    FUN_0046f824(unaff_EBP + -0x6cc4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6cd0) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFC_WizardGirl_006d1054,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6cd0);
    FUN_0046f824(unaff_EBP + -0x44fc,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4508) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicFC_WizardGirl_006d1054,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x4508);
    FUN_0046f824(unaff_EBP + -0x6034,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6040) = &PTR_FUN_00666524;
    FUN_0046f847(s_HFC_h_WizardGirl_006d1040,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6040);
    FUN_0046f824(unaff_EBP + -0x4714,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4720) = &PTR_FUN_00666524;
    FUN_0046f847(s_HFC_h_WizardGirl_006d1040,0xffffffff);
    iVar5 = unaff_EBP + -0x4720;
    goto code_r0x0058d3b7;
  case 0x37:
  case 0x38:
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
    FUN_0046f824(unaff_EBP + -0x1138,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1144) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFit_Mummy_006d0ff4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1144);
    FUN_0046f824(unaff_EBP + -0x11d0,0,0x40);
    *(undefined ***)(unaff_EBP + -0x11dc) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFit_MummyFull_006d0fdc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x11dc);
    FUN_0046f824(unaff_EBP + -0x6edc,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6ee8) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMA_Mummy_006d0fcc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6ee8);
    FUN_0046f824(unaff_EBP + -0x4d5c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4d68) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMA_Mummy_006d0fcc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x4d68);
    FUN_0046f824(unaff_EBP + -0x6464,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6470) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Mummy_006d0fc0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6470);
    FUN_0046f824(unaff_EBP + -0x4f74,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4f80) = &PTR_FUN_00666524;
    FUN_0046f847(s_HUA_h_Mummy_006d0fc0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x4f80);
    *(undefined2 *)(*(int *)(extraout_ECX + 0x138) + 0x5ba) = 0;
    *(undefined2 *)(*(int *)(extraout_ECX + 0x138) + 0x5b8) = 0;
    sVar2 = *(short *)(*(int *)(extraout_ECX + 0x138) + 0x5b6);
    if (sVar2 == 0) {
      FUN_0046f824(unaff_EBP + -0x1398,0,0x40);
      *(undefined ***)(unaff_EBP + -0x13a4) = &PTR_FUN_0066651c;
      FUN_0046f847(s_MagicMAFit_MummyFull_006d0fdc,0xffffffff);
      iVar5 = unaff_EBP + -0x13a4;
code_r0x0058c76e:
      FUN_0046f8e4(iVar5);
    }
    else {
      if (sVar2 == 1) {
        FUN_0046f824(unaff_EBP + -0x3548,0,0x100);
        *(undefined ***)(unaff_EBP + -0x3554) = &PTR_FUN_00666524;
        FUN_0046f847(s_CMagicMA_Headless_006d0fac,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x3554);
        FUN_0046f824(unaff_EBP + -0x3760,0,0x100);
        *(undefined ***)(unaff_EBP + -0x376c) = &PTR_FUN_00666524;
        FUN_0046f847(s_CMagicMA_Headless_006d0fac,0xffffffff);
        iVar5 = unaff_EBP + -0x376c;
        goto code_r0x0058c76e;
      }
      if (sVar2 == 2) {
        FUN_0046f824(unaff_EBP + -0x1300,0,0x40);
        *(undefined ***)(unaff_EBP + -0x130c) = &PTR_FUN_0066651c;
        FUN_0046f847(s_MagicMAFit_MummyTorso_006d0f7c,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x130c);
        FUN_0046f824(unaff_EBP + -0x3118,0,0x100);
        *(undefined ***)(unaff_EBP + -0x3124) = &PTR_FUN_00666524;
        FUN_0046f847(s_CMagicMA_Headless_006d0fac,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x3124);
        FUN_0046f824(unaff_EBP + -0x3330,0,0x100);
        *(undefined ***)(unaff_EBP + -0x333c) = &PTR_FUN_00666524;
        FUN_0046f847(s_CMagicMA_Headless_006d0fac,0xffffffff);
        iVar5 = unaff_EBP + -0x333c;
        goto code_r0x0058c76e;
      }
      if (sVar2 == 3) {
        FUN_0046f824(unaff_EBP + -0x7524,0,0x100);
        *(undefined ***)(unaff_EBP + -30000) = &PTR_FUN_00666524;
        FUN_0046f847(s_CMagicMA_Headless_006d0fac,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -30000);
        FUN_0046f824(unaff_EBP + -0x27ac,0,0x100);
        *(undefined ***)(unaff_EBP + -0x27b8) = &PTR_FUN_00666524;
        FUN_0046f847(s_CMagicMA_Headless_006d0fac,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x27b8);
        FUN_0046f824(unaff_EBP + -0x1268,0,0x40);
        *(undefined ***)(unaff_EBP + -0x1274) = &PTR_FUN_0066651c;
        FUN_0046f847(s_MagicMAFit_MummyLegs_006d0f94,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x1274);
        FUN_0046f824(unaff_EBP + -0x28b8,0,0x100);
        *(undefined ***)(unaff_EBP + -0x28c4) = &PTR_FUN_00666524;
        FUN_0046f847(s_nohandl_006d174c,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x28c4);
        FUN_0046f824(unaff_EBP + -0x2ad0,0,0x100);
        *(undefined ***)(unaff_EBP + -0x2adc) = &PTR_FUN_00666524;
        FUN_0046f847(s_nohand_006d1744,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x2adc);
        FUN_0046f824(unaff_EBP + -0x2ce8,0,0x100);
        *(undefined ***)(unaff_EBP + -0x2cf4) = &PTR_FUN_00666524;
        FUN_0046f847(s_nohandr_006d173c,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x2cf4);
        FUN_0046f824(unaff_EBP + -0x2f00,0,0x100);
        *(undefined ***)(unaff_EBP + -0x2f0c) = &PTR_FUN_00666524;
        FUN_0046f847(s_nohand_006d1744,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x2f0c);
        FUN_0058a074(0,unaff_EBP + -0x2494,unaff_EBP + -0x7b4);
        FUN_0058a074(1,unaff_EBP + -0x2388,unaff_EBP + -0x6a8);
        *(undefined1 *)(unaff_EBP + 0xb) = 1;
      }
    }
    FUN_00409377(*(undefined4 *)(*(int *)(extraout_ECX + 0x138) + 0x11c),0);
    FUN_0040e630(unaff_EBP + -0x5c);
    FUN_0040e6d6(unaff_EBP + -0xa8);
    FUN_0040ea14(unaff_EBP + -0x59c);
    FUN_0040e8f3(unaff_EBP + -0x490);
    if (*(char *)(unaff_EBP + 0xb) == '\0') {
      FUN_0040e7f7(*(undefined4 *)(extraout_ECX + 0x1b8),unaff_EBP + -0x7b4);
      FUN_0040e7f7(*(undefined4 *)(extraout_ECX + 0x1bc),unaff_EBP + -0x6a8);
    }
    goto code_r0x0058d44b;
  case 0x39:
    FUN_0046f824(unaff_EBP + -0x6358,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6364) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMAFat_Donkey_006d0e64,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6364);
    FUN_0046f824(unaff_EBP + -0x6570,0,0x100);
    *(undefined ***)(unaff_EBP + -0x657c) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMAFat_Donkey_006d0e64,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x657c);
    FUN_00409377(*(undefined4 *)(*(int *)(extraout_ECX + 0x138) + 0x11c),0);
    FUN_0040ea14(unaff_EBP + -0x59c);
    FUN_0040e8f3(unaff_EBP + -0x490);
    FUN_004094f4(0);
code_r0x0058d47b:
    iVar5 = unaff_EBP + -0x374;
    iVar13 = unaff_EBP + -0x268;
    uVar15 = 2;
code_r0x0058d48b:
    FUN_00455edc(uVar15,iVar13,iVar5,0);
    goto code_r0x0058d496;
  case 0x3a:
    FUN_0046f824(unaff_EBP + -0x1ab8,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1ac4) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMASkn_Vampire_006d0e50,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1ac4);
    FUN_0046f824(unaff_EBP + -0x1b50,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1b5c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMASkn_Vampire_006d0e50,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1b5c);
    FUN_0046f824(unaff_EBP + -0x6788,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6794) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMASkn_Vampire_006d0e3c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6794);
    FUN_0046f824(unaff_EBP + -0x69a0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x69ac) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMASkn_Vampire_006d0e3c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x69ac);
    FUN_0046f824(unaff_EBP + -0x6bb8,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6bc4) = &PTR_FUN_00666524;
    FUN_0046f847(s_HMA_h_Vampire_006d0e2c,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6bc4);
    FUN_0046f824(unaff_EBP + -0x6dd0,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6ddc) = &PTR_FUN_00666524;
    FUN_0046f847(s_HMA_h_Vampire_006d0e2c,0xffffffff);
    iVar5 = unaff_EBP + -0x6ddc;
    goto code_r0x0058d3b7;
  case 0x3b:
    FUN_0046f824(unaff_EBP + -0x1be8,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1bf4) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFit_PrinceCharming_006d0e10,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1bf4);
    FUN_0046f824(unaff_EBP + -0x1c80,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1c8c) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMAFitlgt_PrinceCharming_006d0df0,0xffffffff);
    iVar5 = unaff_EBP + -0x1c8c;
    break;
  case 0x3c:
    FUN_0046f824(unaff_EBP + -0x1d18,0,0x40);
    *(undefined ***)(unaff_EBP + -0x1d24) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMCChd_Skeleton_006d0ddc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x1d24);
    FUN_0046f824(unaff_EBP + -0xa18,0,0x40);
    *(undefined ***)(unaff_EBP + -0xa24) = &PTR_FUN_0066651c;
    FUN_0046f847(s_MagicMCChd_Skeleton_006d0ddc,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0xa24);
    FUN_0046f824(unaff_EBP + -0x6fe8,0,0x100);
    *(undefined ***)(unaff_EBP + -0x6ff4) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMCChd_Skeleton_006d0dc4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x6ff4);
    FUN_0046f824(unaff_EBP + -0x7200,0,0x100);
    *(undefined ***)(unaff_EBP + -0x720c) = &PTR_FUN_00666524;
    FUN_0046f847(s_CMagicMCChd_Skeleton_006d0dc4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x720c);
    FUN_0046f824(unaff_EBP + -0x7418,0,0x100);
    *(undefined ***)(unaff_EBP + -0x7424) = &PTR_FUN_00666524;
    FUN_0046f847(s_GUA_h_SkeletonChild_006d0db0,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x7424);
    FUN_0046f824(unaff_EBP + -0x7630,0,0x100);
    *(undefined ***)(unaff_EBP + -0x763c) = &PTR_FUN_00666524;
    FUN_0046f847(s_GUA_h_SkeletonChild_006d0db0,0xffffffff);
    iVar5 = unaff_EBP + -0x763c;
code_r0x0058d3b7:
    FUN_0046f8e4(iVar5);
    FUN_00409377(*(undefined4 *)(*(int *)(extraout_ECX + 0x138) + 0x11c),0);
    FUN_0040e630(unaff_EBP + -0x5c);
    FUN_0040e6d6(unaff_EBP + -0xa8);
    FUN_0040ea14(unaff_EBP + -0x59c);
    FUN_0040e8f3(unaff_EBP + -0x490);
code_r0x0058d41a:
    FUN_0040e7f7(*(undefined4 *)(extraout_ECX + 0x1b8),unaff_EBP + -0x7b4);
    FUN_0040e7f7(*(undefined4 *)(extraout_ECX + 0x1bc),unaff_EBP + -0x6a8);
    goto code_r0x0058d44b;
  }
  FUN_0046f8e4(iVar5);
  FUN_00409377(*(undefined4 *)(*(int *)(extraout_ECX + 0x138) + 0x11c),0);
  FUN_0040e630(unaff_EBP + -0x5c);
  FUN_0040e6d6(unaff_EBP + -0xa8);
code_r0x0058d44b:
  FUN_004094f4(0);
  FUN_0046f8e4(unaff_EBP + -0x5c);
  iVar5 = unaff_EBP + -0xa8;
code_r0x0058d472:
  FUN_0046f8e4(iVar5);
code_r0x0058d496:
  if ((*(short *)(unaff_EBP + -0x260) == 0) && (*(int *)(extraout_ECX + 0x1b0) != 0)) {
    FUN_00455edc(2,unaff_EBP + -0x268,unaff_EBP + -0x374,0);
  }
  if (**(int **)(extraout_ECX + 600) == 0) {
    *(undefined1 *)(unaff_EBP + 0xb) = 1;
    uVar15 = FUN_0045741b();
    FUN_004eb208(uVar15);
  }
  else {
    cVar3 = FUN_0058a133(*(int **)(extraout_ECX + 600),unaff_EBP + -0x59c,unaff_EBP + -0x490);
    *(char *)(unaff_EBP + 0xb) = cVar3;
    if (cVar3 != '\0') {
      uVar15 = FUN_0045741b();
      FUN_004eb227(uVar15);
    }
  }
  if (*(int *)**(undefined4 **)(extraout_ECX + 0x25c) == 0) {
    *(undefined1 *)(unaff_EBP + -0xe) = 1;
  }
  else {
    iVar5 = unaff_EBP + -0x374;
    iVar13 = unaff_EBP + -0x268;
    puVar9 = (undefined4 *)FUN_005938bb(0);
    uVar4 = FUN_0058a133(*puVar9,iVar13,iVar5);
    *(undefined1 *)(unaff_EBP + -0xe) = uVar4;
  }
  puVar9 = (undefined4 *)FUN_005938bb(1);
  if (*(int *)*puVar9 == 0) {
    iVar5 = FUN_0040323c();
    *(bool *)(unaff_EBP + -0xd) = iVar5 != 0;
  }
  else {
    uVar15 = FUN_0040f49d();
    iVar5 = unaff_EBP + -0x25a0;
    puVar9 = (undefined4 *)FUN_005938bb(1);
    uVar4 = FUN_0058a133(*puVar9,iVar5,uVar15);
    *(undefined1 *)(unaff_EBP + -0xd) = uVar4;
  }
  if (*(int *)(extraout_ECX + 8) != 0) {
    uVar15 = FUN_005ece7a();
    if (*(char *)(unaff_EBP + 0xb) != '\0') {
      uVar6 = FUN_005ece7a();
      uVar6 = FUN_005b870f(uVar6);
      *(undefined4 *)(unaff_EBP + 8) = uVar6;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar6 = FUN_005ece7a();
      uVar6 = FUN_005b870f(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0058372c(DAT_006f6b64,uVar15,uVar6,*(undefined4 *)(unaff_EBP + 8));
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
    }
    if (*(char *)(unaff_EBP + -0xe) != '\0') {
      uVar6 = FUN_005ece7a();
      uVar6 = FUN_005b870f(uVar6);
      *(undefined4 *)(unaff_EBP + 8) = uVar6;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      uVar6 = FUN_005ece7a();
      uVar10 = FUN_005b870f(uVar6);
      uVar6 = *(undefined4 *)(unaff_EBP + 8);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      uVar7 = DAT_006f6b64;
      uVar11 = uVar15;
      FUN_005938bb(0);
      FUN_0058372c(uVar7,uVar11,uVar10,uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
    }
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      uVar6 = FUN_005b870f(&DAT_006de560);
      *(undefined4 *)(unaff_EBP + 8) = uVar6;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      uVar6 = FUN_005ece7a();
      uVar11 = FUN_005b870f(uVar6);
      uVar6 = *(undefined4 *)(unaff_EBP + 8);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      uVar7 = DAT_006f6b64;
      FUN_005938bb(1);
      FUN_0058372c(uVar7,uVar15,uVar11,uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
    }
  }
  iVar5 = FUN_0040323c();
  if ((iVar5 != 0) && (iVar5 = FUN_0040323c(), iVar5 != 0)) {
    FUN_0058a074(0,unaff_EBP + -0x2494,unaff_EBP + -0x7b4);
    FUN_0058a074(1,unaff_EBP + -0x2388,unaff_EBP + -0x6a8);
  }
  FUN_005a1917(*(undefined1 *)(extraout_ECX + 0xf4),*(undefined1 *)(extraout_ECX + 0xf5),
               *(undefined1 *)(extraout_ECX + 0xf6));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00408c4f();
LAB_0058d78e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

