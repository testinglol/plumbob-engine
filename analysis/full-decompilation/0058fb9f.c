
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058fb9f(void)

{
  char *pcVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  size_t sVar5;
  undefined4 *puVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar7;
  int iVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if ((DAT_006f6b58 == '\0') || (cVar4 = FUN_0045e67a(), cVar4 == '\0')) {
    if (extraout_ECX[0x4c] != extraout_ECX[0x4b]) {
      FUN_005d4bbf(&DAT_006de560);
    }
  }
  else {
    FUN_005b870f();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if ((DAT_006d0434 & 1) != 0) {
      sVar5 = _strlen(s_Person__006d18b4);
      FUN_00412d8a(s_Person__006d18b4,s_Person__006d18b4 + sVar5);
      pcVar1 = *(char **)(*(int *)(extraout_ECX[0x4e] + 0x11c) + 0x18);
      sVar5 = _strlen(pcVar1);
      FUN_00412d8a(pcVar1,pcVar1 + sVar5);
      sVar5 = _strlen(&DAT_006c08dc);
      FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
    }
    if ((DAT_006d0434 & 2) != 0) {
      sVar5 = _strlen(s_Background__006d18a4);
      FUN_00412d8a(s_Background__006d18a4,s_Background__006d18a4 + sVar5);
      if (extraout_ECX[5] == 0) {
        puVar6 = (undefined4 *)FUN_005b870f();
        *(undefined4 *)(unaff_EBP + -0x10) = 1;
        *(undefined1 *)(unaff_EBP + -4) = 1;
      }
      else {
        puVar6 = (undefined4 *)(*(int *)(extraout_ECX[5] + 4) + 4);
      }
      FUN_00412d8a(*puVar6,puVar6[1]);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if ((*(byte *)(unaff_EBP + -0x10) & 1) != 0) {
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
        FUN_005b8770();
      }
      sVar5 = _strlen(&DAT_006c08dc);
      FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
    }
    if ((DAT_006d0434 & 4) != 0) {
      sVar5 = _strlen(s_Current____006d1898);
      FUN_00412d8a(s_Current____006d1898,s_Current____006d1898 + sVar5);
      pcVar1 = (&PTR_s_Blank_006d07c8)[extraout_ECX[0x26]];
      sVar5 = _strlen(pcVar1);
      FUN_00412d8a(pcVar1,pcVar1 + sVar5);
      sVar5 = _strlen(&DAT_006d1894);
      FUN_00412d8a(&DAT_006d1894,&DAT_006d1894 + sVar5);
      if (extraout_ECX[3] == 0) {
        puVar6 = (undefined4 *)FUN_005b870f();
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 2;
        *(undefined1 *)(unaff_EBP + -4) = 2;
      }
      else {
        puVar6 = (undefined4 *)(*(int *)(extraout_ECX[3] + 4) + 4);
      }
      FUN_00412d8a(*puVar6,puVar6[1]);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if ((*(byte *)(unaff_EBP + -0x10) & 2) != 0) {
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
        FUN_005b8770();
      }
      sVar5 = _strlen(&DAT_006c08dc);
      FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
    }
    if ((DAT_006d0434 & 8) != 0) {
      sVar5 = _strlen(s_Carry__006d188c);
      FUN_00412d8a(s_Carry__006d188c,s_Carry__006d188c + sVar5);
      if (extraout_ECX[0x4f] == 0) {
        puVar6 = (undefined4 *)FUN_005b870f();
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 4;
        *(undefined1 *)(unaff_EBP + -4) = 3;
      }
      else {
        puVar6 = (undefined4 *)(*(int *)(extraout_ECX[0x4f] + 4) + 4);
      }
      FUN_00412d8a(*puVar6,puVar6[1]);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if ((*(byte *)(unaff_EBP + -0x10) & 4) != 0) {
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffb;
        FUN_005b8770();
      }
      sVar5 = _strlen(&DAT_006c08dc);
      FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
    }
    if ((DAT_006d0434 & 0x10) != 0) {
      sVar5 = _strlen(s_Last__006d1884);
      FUN_00412d8a(s_Last__006d1884,s_Last__006d1884 + sVar5);
      if (extraout_ECX[4] == 0) {
        puVar6 = (undefined4 *)FUN_005b870f();
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 8;
        *(undefined1 *)(unaff_EBP + -4) = 4;
      }
      else {
        puVar6 = (undefined4 *)(*(int *)(extraout_ECX[4] + 4) + 4);
      }
      FUN_00412d8a(*puVar6,puVar6[1]);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if ((*(byte *)(unaff_EBP + -0x10) & 8) != 0) {
        FUN_005b8770();
      }
      sVar5 = _strlen(&DAT_006c08dc);
      FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
    }
    if ((DAT_006d0434 & 0x20) != 0) {
      sVar5 = _strlen(s_State__006d187c);
      FUN_00412d8a(s_State__006d187c,s_State__006d187c + sVar5);
      pcVar1 = (&PTR_s_Animating_006d0874)[extraout_ECX[100]];
      sVar5 = _strlen(pcVar1);
      FUN_00412d8a(pcVar1,pcVar1 + sVar5);
      sVar5 = _strlen(&DAT_006c08dc);
      FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
    }
    if ((DAT_006d0434 & 0x40) != 0) {
      sVar5 = _strlen(s_FollowState__006d186c);
      FUN_00412d8a(s_FollowState__006d186c,s_FollowState__006d186c + sVar5);
      pcVar1 = (&PTR_s_0_Neutral_006d08bc)[extraout_ECX[0x62]];
      sVar5 = _strlen(pcVar1);
      FUN_00412d8a(pcVar1,pcVar1 + sVar5);
      sVar5 = _strlen(&DAT_006c08dc);
      FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
    }
    if ((DAT_006d0434 & 0x80) != 0) {
      FUN_00635858(unaff_EBP + -0x128,s__d____d_006d1864,extraout_ECX[0x60]);
      sVar5 = _strlen(s_CurDest__006d1858);
      FUN_00412d8a(s_CurDest__006d1858,s_CurDest__006d1858 + sVar5);
      sVar5 = _strlen((char *)(unaff_EBP + -0x128));
      FUN_00412d8a(unaff_EBP + -0x128,unaff_EBP + -0x128 + sVar5);
      uVar2 = extraout_ECX[0x60];
      if ((-1 < (int)uVar2) &&
         (piVar3 = (int *)extraout_ECX[0x61], uVar2 < (uint)(piVar3[1] - *piVar3 >> 3))) {
        FUN_00635858(unaff_EBP + -0x128,s__>__f__f_006d184c,
                     (double)((float)*(int *)(*piVar3 + 4 + uVar2 * 8) * _DAT_00667278),
                     (double)((float)*(int *)(*piVar3 + uVar2 * 8) * _DAT_00667278));
        sVar5 = _strlen((char *)(unaff_EBP + -0x128));
        FUN_00412d8a(unaff_EBP + -0x128,unaff_EBP + -0x128 + sVar5);
      }
      sVar5 = _strlen(&DAT_006c08dc);
      FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
    }
    if ((DAT_006d0435 & 1) != 0) {
      FUN_00635858(unaff_EBP + -0x128,s__f__f_006d1844,(double)(float)extraout_ECX[0x20],
                   (double)(float)extraout_ECX[0x21]);
      sVar5 = _strlen(s_GridPos__006d1838);
      FUN_00412d8a(s_GridPos__006d1838,s_GridPos__006d1838 + sVar5);
      sVar5 = _strlen((char *)(unaff_EBP + -0x128));
      FUN_00412d8a(unaff_EBP + -0x128,unaff_EBP + -0x128 + sVar5);
    }
    if ((DAT_006d0435 & 2) != 0) {
      FUN_00635858(unaff_EBP + -0x228,s_CurDir___1_2f_GoalDir___1_2f_006d1818,
                   (double)(float)extraout_ECX[0x22],(double)(float)extraout_ECX[0x73]);
      sVar5 = _strlen((char *)(unaff_EBP + -0x228));
      FUN_00412d8a(unaff_EBP + -0x228,unaff_EBP + -0x228 + sVar5);
      FUN_00635858(unaff_EBP + -0x228,s_WantTurn___1_2f_UsingTurn___1_2f_006d17f4,
                   (double)(float)extraout_ECX[0x7c],(double)(float)extraout_ECX[0x7d]);
      sVar5 = _strlen((char *)(unaff_EBP + -0x228));
      FUN_00412d8a(unaff_EBP + -0x228,unaff_EBP + -0x228 + sVar5);
      FUN_00635858(unaff_EBP + -0x228,s_StartDir___1_2f_FinalDir___1_2f_006d17d0,
                   (double)(float)extraout_ECX[0x76],(double)(float)extraout_ECX[0x79]);
      sVar5 = _strlen((char *)(unaff_EBP + -0x228));
      FUN_00412d8a(unaff_EBP + -0x228,unaff_EBP + -0x228 + sVar5);
      FUN_00635858();
      sVar5 = _strlen((char *)(unaff_EBP + -0x228));
      FUN_00412d8a(unaff_EBP + -0x228,unaff_EBP + -0x228 + sVar5);
      FUN_00635858();
      sVar5 = _strlen((char *)(unaff_EBP + -0x228));
      FUN_00412d8a(unaff_EBP + -0x228,unaff_EBP + -0x228 + sVar5);
      FUN_00635858();
      sVar5 = _strlen((char *)(unaff_EBP + -0x228));
      FUN_00412d8a(unaff_EBP + -0x228,unaff_EBP + -0x228 + sVar5);
    }
    if (((DAT_006d0435 & 4) != 0) && (extraout_ECX[0x68] != 0)) {
      FUN_00635858(unaff_EBP + -0x128);
      sVar5 = _strlen((char *)(unaff_EBP + -0x128));
      FUN_00412d8a(unaff_EBP + -0x128,unaff_EBP + -0x128 + sVar5);
    }
    if ((DAT_006d0435 & 8) != 0) {
      (**(code **)(*extraout_ECX + 0x30))();
      FUN_00635858(unaff_EBP + -0x128);
      sVar5 = _strlen((char *)(unaff_EBP + -0x128));
      FUN_00412d8a(unaff_EBP + -0x128,unaff_EBP + -0x128 + sVar5);
    }
    cVar4 = FUN_005d49dc();
    if (cVar4 == '\0') {
      FUN_005d499c();
      FUN_005b8680();
      iVar8 = 0;
      iVar7 = *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      if (0 < iVar7) {
        do {
          if (*(char *)(iVar8 + *(int *)(unaff_EBP + -0x1c)) == '\n') {
            FUN_004d3ff7();
            FUN_005d4bbf();
          }
          else {
            FUN_004015e4();
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar7);
      }
      if (*(int *)(unaff_EBP + -0x24) != *(int *)(unaff_EBP + -0x28)) {
        FUN_004d3ff7();
        FUN_005d4bbf();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

