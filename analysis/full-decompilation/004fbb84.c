
void FUN_004fbb84(void)

{
  char *pcVar1;
  char cVar2;
  size_t sVar3;
  int unaff_EBP;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  
  FUN_00634c24();
  if (*(char *)(DAT_006fe8bc + 0x13c) != '\0') {
    FUN_005d48d9();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004f2baf(unaff_EBP + -0x20);
    FUN_005d48d9();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0046fb9b(unaff_EBP + -0x240,0x104);
    *(undefined ***)(unaff_EBP + -0x24c) = &PTR_LAB_00666cdc;
    FUN_0046fb9b(unaff_EBP + -0x350,0x104);
    *(undefined ***)(unaff_EBP + -0x35c) = &PTR_LAB_00666cdc;
    FUN_0046fb9b(unaff_EBP + -0x570,0x104);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined ***)(unaff_EBP + -0x57c) = &PTR_LAB_00666cdc;
    FUN_0046fb9b(unaff_EBP + -0x130,0x104);
    *(undefined ***)(unaff_EBP + -0x13c) = &PTR_LAB_00666cdc;
    FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x13c);
    FUN_0046f847(s_SoundData__006cc090,0xffffffff);
    FUN_0046b8c5(unaff_EBP + -0x24c);
    cVar2 = FUN_004fc0b7(unaff_EBP + -0x13c,s_SimsSound_hit_006cc080);
    if (cVar2 == '\0') {
      FUN_0046fb9b(unaff_EBP + -0x130,0x104);
      *(undefined ***)(unaff_EBP + -0x13c) = &PTR_LAB_00666cdc;
      FUN_0046f847(&DAT_006de560,0xffffffff);
      FUN_0046f8e4(unaff_EBP + -0x13c);
    }
    sVar3 = _strlen(*(char **)(unaff_EBP + -0x248));
    if ((sVar3 == 0) &&
       (cVar2 = FUN_004fc152(s_SIMS_SOUND_006cc074,unaff_EBP + -0x2c), cVar2 != '\0')) {
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x2c);
      FUN_0046fb9b(unaff_EBP + -0x130,0x104);
      *(undefined ***)(unaff_EBP + -0x13c) = &PTR_LAB_00666cdc;
      FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
      FUN_0046f8e4(unaff_EBP + -0x13c);
      FUN_0046f847(&DAT_006cc070,0xffffffff);
      FUN_0046b8c5(unaff_EBP + -0x24c);
      cVar2 = FUN_004fc0b7(unaff_EBP + -0x13c,s_SimsSound_hit_006cc080);
      if (cVar2 == '\0') {
        FUN_0046fb9b(unaff_EBP + -0x130,0x104);
        *(undefined ***)(unaff_EBP + -0x13c) = &PTR_LAB_00666cdc;
        FUN_0046f847(&DAT_006de560,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x13c);
      }
    }
    sVar3 = _strlen(*(char **)(unaff_EBP + -0x578));
    if (sVar3 == 0) {
      *(undefined1 *)(unaff_EBP + -0xd) = 0x43;
      do {
        wsprintfA(*(LPSTR *)(unaff_EBP + -0x578),s__c__Music__006cc064,
                  (int)*(char *)(unaff_EBP + -0xd));
        FUN_0046b8c5(unaff_EBP + -0x57c);
        cVar2 = FUN_004fc0b7(unaff_EBP + -0x46c,s_eag_us_avi_006cc058);
        if (cVar2 != '\0') break;
        FUN_0046fb9b(unaff_EBP + -0x130,0x104);
        *(undefined ***)(unaff_EBP + -0x13c) = &PTR_LAB_00666cdc;
        FUN_0046f847(&DAT_006de560,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x13c);
        *(char *)(unaff_EBP + -0xd) = *(char *)(unaff_EBP + -0xd) + '\x01';
      } while (*(char *)(unaff_EBP + -0xd) < 'Z');
    }
    sVar3 = _strlen(*(char **)(unaff_EBP + -0x358));
    if (sVar3 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x20);
      FUN_0046fb9b(unaff_EBP + -0x130,0x104);
      *(undefined ***)(unaff_EBP + -0x13c) = &PTR_LAB_00666cdc;
      FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
      FUN_0046f8e4(unaff_EBP + -0x13c);
      FUN_0046f847(s_Music__006cc050,0xffffffff);
      FUN_0046b8c5(unaff_EBP + -0x35c);
      cVar2 = FUN_004fc0b7(unaff_EBP + -0x46c,s_Modes_Build_build1_mp3_006cc038);
      if (cVar2 == '\0') {
        FUN_0046fb9b(unaff_EBP + -0x130,0x104);
        *(undefined ***)(unaff_EBP + -0x13c) = &PTR_LAB_00666cdc;
        FUN_0046f847(&DAT_006de560,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x13c);
      }
    }
    sVar3 = _strlen(*(char **)(unaff_EBP + -0x358));
    if ((sVar3 == 0) || (sVar3 = _strlen(*(char **)(unaff_EBP + -0x248)), sVar3 == 0)) {
      FUN_005d5f0b();
      FUN_005d4bbf(&DAT_006de560);
      puVar7 = &DAT_006de560;
    }
    else {
      FUN_0046f824(unaff_EBP + -0x130,0,0x104);
      pcVar1 = *(char **)(unaff_EBP + -0x578);
      *(undefined ***)(unaff_EBP + -0x13c) = &PTR_FUN_006664e8;
      sVar3 = _strlen(pcVar1);
      pcVar1[sVar3 - 1] = '\0';
      FUN_0046b8c5(unaff_EBP + -0x57c);
      FUN_00412122(unaff_EBP + -0x46c,unaff_EBP + -0x13c);
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x138));
      pcVar1 = *(char **)(unaff_EBP + -0x358);
      sVar3 = _strlen(pcVar1);
      pcVar1[sVar3 - 1] = '\0';
      FUN_0046b8c5(unaff_EBP + -0x35c);
      FUN_00412122(unaff_EBP + -0x46c,unaff_EBP + -0x13c);
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x138));
      uVar6 = 1;
      uVar5 = 1;
      uVar4 = *(undefined4 *)(unaff_EBP + -0x248);
      FUN_005b8e25(uVar4,1,1);
      FUN_005b92ee(uVar4,uVar5,uVar6);
      pcVar1 = *(char **)(unaff_EBP + -0x248);
      sVar3 = _strlen(pcVar1);
      pcVar1[sVar3 - 1] = '\0';
      FUN_0046b8c5(unaff_EBP + -0x24c);
      FUN_00412122(unaff_EBP + -0x46c,unaff_EBP + -0x13c);
      puVar7 = *(undefined1 **)(unaff_EBP + -0x138);
    }
    FUN_005d4bbf(puVar7);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

