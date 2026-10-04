
void FUN_004fc804(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBP;
  undefined *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  uVar4 = 0;
  FUN_0046f824(unaff_EBP + -0x268,0,0x104);
  *(undefined ***)(unaff_EBP + -0x274) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x610,0,0x104);
  *(undefined ***)(unaff_EBP + -0x61c) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x500,0,0x104);
  *(undefined ***)(unaff_EBP + -0x50c) = &PTR_FUN_006664e8;
  uVar2 = FUN_00428886();
  *(undefined4 *)(unaff_EBP + -0x5c) = uVar2;
  FUN_0046f824(unaff_EBP + -0xa50,0,0x104);
  *(undefined ***)(unaff_EBP + -0xa5c) = &PTR_FUN_006664e8;
  FUN_00425691(*(undefined4 *)(unaff_EBP + -0x5c),unaff_EBP + -0xa5c);
  uVar2 = FUN_0041532c(0x57,0,unaff_EBP + -0x274);
  FUN_004eea6b(uVar2);
  FUN_0046f847(&DAT_006c0fb8,0xffffffff);
  FUN_0046fa6f(*(undefined4 *)(unaff_EBP + -0x5c),2);
  FUN_0046f8cb(*(undefined4 *)(unaff_EBP + -0x270));
  FUN_0046f8cb(*(undefined4 *)(unaff_EBP + -0x270));
  cVar1 = FUN_004074bc();
  if (cVar1 == '\x01') {
    puVar5 = &DAT_006cc220;
LAB_004fc9ac:
    FUN_0046f847(puVar5,0xffffffff);
  }
  else {
    cVar1 = FUN_004ce974();
    if (cVar1 != '\0') {
      puVar5 = &DAT_006cc218;
      goto LAB_004fc9ac;
    }
    cVar1 = FUN_004074f7();
    if (cVar1 != '\0') {
      puVar5 = &DAT_006cc210;
      goto LAB_004fc9ac;
    }
    cVar1 = FUN_0040750e();
    if (cVar1 != '\0') {
      puVar5 = &DAT_006cc208;
      goto LAB_004fc9ac;
    }
    cVar1 = FUN_0042886f();
    if (cVar1 != '\0') {
      puVar5 = &DAT_006cc200;
      goto LAB_004fc9ac;
    }
    cVar1 = FUN_00407525();
    if (cVar1 != '\0') {
      puVar5 = &DAT_006cc1f8;
      goto LAB_004fc9ac;
    }
  }
  FUN_0046f847(&DAT_006cc1f0,0xffffffff);
  FUN_00418fea();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041c785(unaff_EBP + -0x274);
  FUN_0041c785(unaff_EBP + -0x50c);
  uVar2 = *(undefined4 *)(unaff_EBP + -0x270);
  uVar7 = *(undefined4 *)(unaff_EBP + -0xa58);
  FUN_005b8e25(uVar7,uVar2);
  FUN_005b9976(uVar7,uVar2);
  FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x508));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b86bd(unaff_EBP + -0x74);
  *(undefined ***)(unaff_EBP + -0x40) = &PTR_FUN_006698c8;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00416780();
  FUN_00416618(unaff_EBP + -0xf8);
  FUN_0046f824(unaff_EBP + -0x3f0,0,0x104);
  *(undefined ***)(unaff_EBP + -0x3fc) = &PTR_FUN_006664e8;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00425531(unaff_EBP + -0x3fc);
  cVar1 = FUN_004074f7();
  if (cVar1 == '\x01') {
    pcVar6 = s_Houses_DTDesc_iff_006c26bc;
LAB_004fcb45:
    FUN_0046f847(pcVar6,0xffffffff);
  }
  else {
    cVar1 = FUN_0040750e();
    if (cVar1 == '\x01') {
      pcVar6 = s_Houses_STDesc_iff_006c2678;
      goto LAB_004fcb45;
    }
    cVar1 = FUN_0042886f();
    if (cVar1 == '\x01') {
      pcVar6 = s_Houses_MTDesc_iff_006c2664;
      goto LAB_004fcb45;
    }
    cVar1 = FUN_00407525();
    if (cVar1 == '\x01') {
      pcVar6 = s_Houses_VIDesc_iff_006c26a8;
      goto LAB_004fcb45;
    }
    cVar1 = FUN_004ce974();
    if (cVar1 == '\x01') {
LAB_004fcb3e:
      pcVar6 = s_Houses_NeighborhoodDesc_iff_006c268c;
      goto LAB_004fcb45;
    }
    cVar1 = FUN_004074bc();
    if (cVar1 == '\x01') goto LAB_004fcb3e;
  }
  FUN_0046f5cd();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  iVar3 = FUN_0046f71c(unaff_EBP + -0x3fc,0);
  FUN_004706f0();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (iVar3 == 0) {
    iVar3 = FUN_00470d31(unaff_EBP + -0xca0,*(int *)(unaff_EBP + -0x5c) + 2000,1);
    if (iVar3 == 0) {
      iVar3 = FUN_00471509(1,0xffffffff);
      if (iVar3 != 0) {
        FUN_005d4bbf(iVar3);
      }
      iVar3 = FUN_00471509(2,0xffffffff);
      if (iVar3 != 0) {
        FUN_005d4bbf(iVar3);
        if (*(int *)(unaff_EBP + -0x54) != *(int *)(unaff_EBP + -0x58)) {
          do {
            pcVar6 = (char *)(*(int *)(unaff_EBP + -0x58) + uVar4);
            if (*pcVar6 == '\n') {
              *pcVar6 = ' ';
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < (uint)(*(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -0x58)));
        }
      }
    }
    FUN_0046b7ee();
  }
  cVar1 = FUN_004074f7();
  if (cVar1 == '\x01') {
    FUN_005d4956(s_Description_006cc1cc);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005d4956(s_DowntownLot_006cc1e4);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005f0b22(unaff_EBP + -0x18,unaff_EBP + -0x24,unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
LAB_004fce99:
    FUN_005b8770();
  }
  else {
    cVar1 = FUN_0040750e();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Description_006cc1cc);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_005d4956(s_StudiotownLot_006cc1bc);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x58);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fce99;
    }
    cVar1 = FUN_0042886f();
    if (cVar1 == '\x01') {
      cVar1 = FUN_004074bc();
      if (cVar1 == '\x01') {
        FUN_005d4956(s_Description_006cc1cc);
        *(undefined1 *)(unaff_EBP + -4) = 0xd;
        FUN_005d4956(s_MagicResidentialLot_006cc1a8);
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x58);
        *(undefined1 *)(unaff_EBP + -4) = 0xd;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 8;
      }
      else {
        FUN_005d4956(s_Description_006cc1cc);
        *(undefined1 *)(unaff_EBP + -4) = 0xf;
        FUN_005d4956(s_MagicCommunityLot_006cc194);
        *(undefined1 *)(unaff_EBP + -4) = 0x10;
        FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x58);
        *(undefined1 *)(unaff_EBP + -4) = 0xf;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 8;
      }
      goto LAB_004fce99;
    }
    cVar1 = FUN_00407525();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Description_006cc1cc);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_005d4956(s_IslandLot_006cc1d8);
      *(undefined1 *)(unaff_EBP + -4) = 0x12;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x58);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fce99;
    }
    cVar1 = FUN_004074bc();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Description_006cc1cc);
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      FUN_005d4956(s_ResidentialLot_006cc184);
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x58);
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fce99;
    }
    cVar1 = FUN_004ce974();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Description_006cc1cc);
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      FUN_005d4956(s_CommunityLot_006cc174);
      *(undefined1 *)(unaff_EBP + -4) = 0x16;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x58);
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fce99;
    }
  }
  uVar2 = FUN_004ed868();
  FUN_005d5156(unaff_EBP + -0x4c,&DAT_006c08e4,uVar2);
  cVar1 = FUN_004074f7();
  if (cVar1 == '\x01') {
    FUN_005d4956(s_Floors_006cc16c);
    *(undefined1 *)(unaff_EBP + -4) = 0x17;
    FUN_005d4956(s_DowntownLot_006cc1e4);
    *(undefined1 *)(unaff_EBP + -4) = 0x18;
    FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
    *(undefined1 *)(unaff_EBP + -4) = 0x17;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
LAB_004fd13c:
    FUN_005b8770();
  }
  else {
    cVar1 = FUN_0040750e();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Floors_006cc16c);
      *(undefined1 *)(unaff_EBP + -4) = 0x19;
      FUN_005d4956(s_StudiotownLot_006cc1bc);
      *(undefined1 *)(unaff_EBP + -4) = 0x1a;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
      *(undefined1 *)(unaff_EBP + -4) = 0x19;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fd13c;
    }
    cVar1 = FUN_0042886f();
    if (cVar1 == '\x01') {
      cVar1 = FUN_004074bc();
      if (cVar1 == '\x01') {
        FUN_005d4956(s_Floors_006cc16c);
        *(undefined1 *)(unaff_EBP + -4) = 0x1b;
        FUN_005d4956(s_MagicResidentialLot_006cc1a8);
        *(undefined1 *)(unaff_EBP + -4) = 0x1c;
        FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
        *(undefined1 *)(unaff_EBP + -4) = 0x1b;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 8;
      }
      else {
        FUN_005d4956(s_Floors_006cc16c);
        *(undefined1 *)(unaff_EBP + -4) = 0x1d;
        FUN_005d4956(s_MagicCommunityLot_006cc194);
        *(undefined1 *)(unaff_EBP + -4) = 0x1e;
        FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
        *(undefined1 *)(unaff_EBP + -4) = 0x1d;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 8;
      }
      goto LAB_004fd13c;
    }
    cVar1 = FUN_00407525();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Floors_006cc16c);
      *(undefined1 *)(unaff_EBP + -4) = 0x1f;
      FUN_005d4956(s_IslandLot_006cc1d8);
      *(undefined1 *)(unaff_EBP + -4) = 0x20;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
      *(undefined1 *)(unaff_EBP + -4) = 0x1f;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fd13c;
    }
    cVar1 = FUN_004074bc();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Floors_006cc16c);
      *(undefined1 *)(unaff_EBP + -4) = 0x21;
      FUN_005d4956(s_ResidentialLot_006cc184);
      *(undefined1 *)(unaff_EBP + -4) = 0x22;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
      *(undefined1 *)(unaff_EBP + -4) = 0x21;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fd13c;
    }
    cVar1 = FUN_004ce974();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Floors_006cc16c);
      *(undefined1 *)(unaff_EBP + -4) = 0x23;
      FUN_005d4956(s_CommunityLot_006cc174);
      *(undefined1 *)(unaff_EBP + -4) = 0x24;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
      *(undefined1 *)(unaff_EBP + -4) = 0x23;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fd13c;
    }
  }
  cVar1 = FUN_004074f7();
  if (cVar1 == '\x01') {
    FUN_005d4956(&DAT_006cc164);
    *(undefined1 *)(unaff_EBP + -4) = 0x25;
    FUN_005d4956(s_DowntownLot_006cc1e4);
    *(undefined1 *)(unaff_EBP + -4) = 0x26;
    FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x68);
    *(undefined1 *)(unaff_EBP + -4) = 0x25;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
LAB_004fd3c1:
    FUN_005b8770();
  }
  else {
    cVar1 = FUN_0040750e();
    if (cVar1 == '\x01') {
      FUN_005d4956(&DAT_006cc164);
      *(undefined1 *)(unaff_EBP + -4) = 0x27;
      FUN_005d4956(s_StudiotownLot_006cc1bc);
      *(undefined1 *)(unaff_EBP + -4) = 0x28;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x68);
      *(undefined1 *)(unaff_EBP + -4) = 0x27;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fd3c1;
    }
    cVar1 = FUN_0042886f();
    if (cVar1 == '\x01') {
      cVar1 = FUN_004074bc();
      if (cVar1 == '\x01') {
        FUN_005d4956(&DAT_006cc164);
        *(undefined1 *)(unaff_EBP + -4) = 0x29;
        FUN_005d4956(s_MagicResidentialLot_006cc1a8);
        *(undefined1 *)(unaff_EBP + -4) = 0x2a;
        FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x68);
        *(undefined1 *)(unaff_EBP + -4) = 0x29;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 8;
      }
      else {
        FUN_005d4956(&DAT_006cc164);
        *(undefined1 *)(unaff_EBP + -4) = 0x2b;
        FUN_005d4956(s_MagicCommunityLot_006cc194);
        *(undefined1 *)(unaff_EBP + -4) = 0x2c;
        FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x68);
        *(undefined1 *)(unaff_EBP + -4) = 0x2b;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 8;
      }
      goto LAB_004fd3c1;
    }
    cVar1 = FUN_00407525();
    if (cVar1 == '\x01') {
      FUN_005d4956(&DAT_006cc164);
      *(undefined1 *)(unaff_EBP + -4) = 0x2d;
      FUN_005d4956(s_IslandLot_006cc1d8);
      *(undefined1 *)(unaff_EBP + -4) = 0x2e;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x68);
      *(undefined1 *)(unaff_EBP + -4) = 0x2d;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fd3c1;
    }
    cVar1 = FUN_004074bc();
    if (cVar1 == '\x01') {
      FUN_005d4956(&DAT_006cc164);
      *(undefined1 *)(unaff_EBP + -4) = 0x2f;
      FUN_005d4956(s_ResidentialLot_006cc184);
      *(undefined1 *)(unaff_EBP + -4) = 0x30;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x68);
      *(undefined1 *)(unaff_EBP + -4) = 0x2f;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fd3c1;
    }
    cVar1 = FUN_004ce974();
    if (cVar1 == '\x01') {
      FUN_005d4956(&DAT_006cc164);
      *(undefined1 *)(unaff_EBP + -4) = 0x31;
      FUN_005d4956(s_CommunityLot_006cc174);
      *(undefined1 *)(unaff_EBP + -4) = 0x32;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x68);
      *(undefined1 *)(unaff_EBP + -4) = 0x31;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      goto LAB_004fd3c1;
    }
  }
  FUN_005d5156(unaff_EBP + -0x4c,&DAT_006c08e4,*(undefined4 *)(unaff_EBP + -0x5c));
  cVar1 = FUN_004074f7();
  if (cVar1 == '\x01') {
    FUN_005d4956(s_Number_006cc15c);
    *(undefined1 *)(unaff_EBP + -4) = 0x33;
    FUN_005d4956(s_DowntownLot_006cc1e4);
    *(undefined1 *)(unaff_EBP + -4) = 0x34;
    FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
    *(undefined1 *)(unaff_EBP + -4) = 0x33;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    cVar1 = FUN_0040750e();
    if (cVar1 == '\x01') {
      FUN_005d4956(s_Number_006cc15c);
      *(undefined1 *)(unaff_EBP + -4) = 0x35;
      FUN_005d4956(s_StudiotownLot_006cc1bc);
      *(undefined1 *)(unaff_EBP + -4) = 0x36;
      FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
      *(undefined1 *)(unaff_EBP + -4) = 0x35;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 8;
    }
    else {
      cVar1 = FUN_0042886f();
      if (cVar1 == '\x01') {
        cVar1 = FUN_004074bc();
        if (cVar1 == '\x01') {
          FUN_005d4956(s_Number_006cc15c);
          *(undefined1 *)(unaff_EBP + -4) = 0x37;
          FUN_005d4956(s_MagicResidentialLot_006cc1a8);
          *(undefined1 *)(unaff_EBP + -4) = 0x38;
          FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 0x37;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 8;
        }
        else {
          FUN_005d4956(s_Number_006cc15c);
          *(undefined1 *)(unaff_EBP + -4) = 0x39;
          FUN_005d4956(s_MagicCommunityLot_006cc194);
          *(undefined1 *)(unaff_EBP + -4) = 0x3a;
          FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 0x39;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 8;
        }
      }
      else {
        cVar1 = FUN_00407525();
        if (cVar1 == '\x01') {
          FUN_005d4956(s_Number_006cc15c);
          *(undefined1 *)(unaff_EBP + -4) = 0x3b;
          FUN_005d4956(s_IslandLot_006cc1d8);
          *(undefined1 *)(unaff_EBP + -4) = 0x3c;
          FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 0x3b;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 8;
        }
        else {
          cVar1 = FUN_004074bc();
          if (cVar1 == '\x01') {
            FUN_005d4956(s_Number_006cc15c);
            *(undefined1 *)(unaff_EBP + -4) = 0x3d;
            FUN_005d4956(s_ResidentialLot_006cc184);
            *(undefined1 *)(unaff_EBP + -4) = 0x3e;
            FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
            *(undefined1 *)(unaff_EBP + -4) = 0x3d;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 8;
          }
          else {
            cVar1 = FUN_004ce974();
            if (cVar1 != '\x01') goto LAB_004fd65b;
            FUN_005d4956(s_Number_006cc15c);
            *(undefined1 *)(unaff_EBP + -4) = 0x3f;
            FUN_005d4956(s_CommunityLot_006cc174);
            *(undefined1 *)(unaff_EBP + -4) = 0x40;
            FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x4c);
            *(undefined1 *)(unaff_EBP + -4) = 0x3f;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 8;
          }
        }
      }
    }
  }
  FUN_005b8770();
LAB_004fd65b:
  if ((*(ushort *)(*(int *)(DAT_006e486c + 0x1c) + 0x5a) & 1) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x44;
    FUN_005d4956(s_Lodging_006cc144);
    *(undefined1 *)(unaff_EBP + -4) = 0x45;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x46;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x45;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x44;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x41;
    FUN_005d4956(s_Lodging_006cc144);
    *(undefined1 *)(unaff_EBP + -4) = 0x42;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x43;
    FUN_005f0b22(unaff_EBP + -0x24,unaff_EBP + -0x18,unaff_EBP + -0x30);
    *(undefined1 *)(unaff_EBP + -4) = 0x42;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x41;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5a) & 2) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x4a;
    FUN_005d4956(&DAT_006cc134);
    *(undefined1 *)(unaff_EBP + -4) = 0x4b;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x4c;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x4b;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x4a;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x47;
    FUN_005d4956(&DAT_006cc134);
    *(undefined1 *)(unaff_EBP + -4) = 0x48;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x49;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x48;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x47;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5a) & 4) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x50;
    FUN_005d4956(s_Gardening_006cc128);
    *(undefined1 *)(unaff_EBP + -4) = 0x51;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x52;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x51;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x50;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x4d;
    FUN_005d4956(s_Gardening_006cc128);
    *(undefined1 *)(unaff_EBP + -4) = 0x4e;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x4f;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x4e;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x4d;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5a) & 8) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x56;
    FUN_005d4956(s_Shopping_006cc11c);
    *(undefined1 *)(unaff_EBP + -4) = 0x57;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x58;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x57;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x56;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x53;
    FUN_005d4956(s_Shopping_006cc11c);
    *(undefined1 *)(unaff_EBP + -4) = 0x54;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x55;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x54;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x53;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5a) & 0x10) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x5c;
    FUN_005d4956(s_PetStore_006cc110);
    *(undefined1 *)(unaff_EBP + -4) = 0x5d;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x5e;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x5d;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x5c;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x59;
    FUN_005d4956(s_PetStore_006cc110);
    *(undefined1 *)(unaff_EBP + -4) = 0x5a;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x5b;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x5a;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x59;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5a) & 0x20) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x62;
    FUN_005d4956(s_SmallAnimal_006cc104);
    *(undefined1 *)(unaff_EBP + -4) = 99;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 100;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 99;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x62;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x5f;
    FUN_005d4956(s_SmallAnimal_006cc104);
    *(undefined1 *)(unaff_EBP + -4) = 0x60;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x61;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x60;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x5f;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(ushort *)(*(int *)(DAT_006e486c + 0x1c) + 0x5a) & 0x40) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x68;
    FUN_005d4956(&DAT_006cc0fc);
    *(undefined1 *)(unaff_EBP + -4) = 0x69;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x6a;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x69;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x68;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x65;
    FUN_005d4956(&DAT_006cc0fc);
    *(undefined1 *)(unaff_EBP + -4) = 0x66;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x67;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x66;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x65;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5a) & 0x80) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x6e;
    FUN_005d4956(&DAT_006cc0f8);
    *(undefined1 *)(unaff_EBP + -4) = 0x6f;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x70;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x6f;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x6e;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x6b;
    FUN_005d4956(&DAT_006cc0f8);
    *(undefined1 *)(unaff_EBP + -4) = 0x6c;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x6d;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x6c;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x6b;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5b) & 1) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x74;
    FUN_005d4956(s_Movie_006cc0f0);
    *(undefined1 *)(unaff_EBP + -4) = 0x75;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x76;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x75;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x74;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x71;
    FUN_005d4956(s_Movie_006cc0f0);
    *(undefined1 *)(unaff_EBP + -4) = 0x72;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x73;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x72;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x71;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5b) & 2) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x7a;
    FUN_005d4956(s_Model_006cc0e8);
    *(undefined1 *)(unaff_EBP + -4) = 0x7b;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x7c;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x7b;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x7a;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x77;
    FUN_005d4956(s_Model_006cc0e8);
    *(undefined1 *)(unaff_EBP + -4) = 0x78;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x79;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x78;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x77;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5b) & 4) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x80;
    FUN_005d4956(s_Music_006cacf4);
    *(undefined1 *)(unaff_EBP + -4) = 0x81;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x82;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x81;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x80;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x7d;
    FUN_005d4956(s_Music_006cacf4);
    *(undefined1 *)(unaff_EBP + -4) = 0x7e;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x7f;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x7e;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x7d;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5b) & 8) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x86;
    FUN_005d4956(s_MagiCo_006cc0e0);
    *(undefined1 *)(unaff_EBP + -4) = 0x87;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x88;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x87;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x86;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x83;
    FUN_005d4956(s_MagiCo_006cc0e0);
    *(undefined1 *)(unaff_EBP + -4) = 0x84;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x85;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x84;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x83;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  if ((*(byte *)(*(int *)(DAT_006e486c + 0x1c) + 0x5b) & 0x10) == 0) {
    FUN_005d4956(s_False_006cc154);
    *(undefined1 *)(unaff_EBP + -4) = 0x8c;
    FUN_005d4956(s_Rides_006cc0d8);
    *(undefined1 *)(unaff_EBP + -4) = 0x8d;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x8e;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x8d;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x8c;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  else {
    FUN_005d4956(&DAT_006cc14c);
    *(undefined1 *)(unaff_EBP + -4) = 0x89;
    FUN_005d4956(s_Rides_006cc0d8);
    *(undefined1 *)(unaff_EBP + -4) = 0x8a;
    FUN_005d4956(s_Filters_006cc13c);
    *(undefined1 *)(unaff_EBP + -4) = 0x8b;
    FUN_005f0b22(unaff_EBP + -0x30,unaff_EBP + -0x24,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 0x8a;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x89;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_005b8770();
  FUN_00418fea();
  *(undefined1 *)(unaff_EBP + -4) = 0x8f;
  iVar3 = FUN_004190d3(unaff_EBP + -0x274,1);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x164) = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 0x90;
  if (iVar3 == 0) {
    FUN_00470383(unaff_EBP + -0xa0,2000,1);
    uVar7 = 0xffffffff;
    uVar2 = FUN_004096c2(0xffffffff);
    FUN_004704a5(1,uVar2,uVar7);
    uVar7 = 0xffffffff;
    uVar2 = FUN_004096c2(0xffffffff);
    FUN_004704a5(2,uVar2,uVar7);
    uVar7 = 0xffffffff;
    uVar2 = FUN_004096c2(0xffffffff);
    FUN_004704a5(3,uVar2,uVar7);
    FUN_0046fd72();
    FUN_004195ba();
  }
  FUN_0046f824(unaff_EBP + -0x940,0,0x104);
  *(undefined ***)(unaff_EBP + -0x94c) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x720,0,0x104);
  *(undefined ***)(unaff_EBP + -0x72c) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x830,0,0x104);
  *(undefined ***)(unaff_EBP + -0x83c) = &PTR_FUN_006664e8;
  FUN_0046f8e4(unaff_EBP + -0x61c);
  FUN_0046f8e4(unaff_EBP + -0x61c);
  FUN_0046f8e4(unaff_EBP + -0x61c);
  FUN_0046f847(s__thumb_jpg_006cc0cc,0xffffffff);
  FUN_0046f847(s__floor1_jpg_006cc0c0,0xffffffff);
  FUN_0046f847(s__floor2_jpg_006cc0b4,0xffffffff);
  FUN_004b2bc4(*(undefined4 *)(unaff_EBP + -0x948),0,0,0x66,0x66,0x66);
  FUN_004b2bc4(*(undefined4 *)(unaff_EBP + -0x728),1,1,0x66,0x66,0x66);
  iVar3 = FUN_004ed868();
  if (1 < iVar3) {
    FUN_004b2bc4(*(undefined4 *)(unaff_EBP + -0x838),2,1,0x66,0x66,0x66);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0x8f;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_0041905d();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_004712d0();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_0046b2e6();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined ***)(unaff_EBP + -0x40) = &PTR_FUN_006698c8;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0041905d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

