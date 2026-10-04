
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00530bbd(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  size_t sVar7;
  char *_Str;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar3 = FUN_004e99a9();
  *(int *)(unaff_EBP + -0x14) = iVar3;
  if ((iVar3 != -1) && (*(int *)(extraout_ECX + 0x134) != 0)) {
    FUN_005103e6(0,0);
    FUN_005103e6(1,0);
    iVar4 = *(int *)(unaff_EBP + 8);
    if (iVar4 == 2) {
      FUN_00510747(*(undefined4 *)(*(int *)(extraout_ECX + 0x11c) + 0x18));
      FUN_00510489(0,0);
      FUN_00503993(&DAT_006ccd34);
      iVar4 = FUN_004ea85e(iVar3);
      if (iVar4 == 0) {
        uVar5 = *(undefined4 *)(extraout_ECX + 0x1b0);
      }
      else {
        uVar5 = FUN_004ea908(iVar3);
        *(undefined4 *)(unaff_EBP + 8) = uVar5;
        iVar3 = FUN_004ea79e(iVar3);
        *(int *)(unaff_EBP + -0x14) = (int)*(short *)(iVar3 + 0x7e);
        fVar1 = (float)*(int *)(unaff_EBP + -0x14);
        if (_DAT_0066dfcc <= fVar1) {
          if (_DAT_0066dfd0 <= fVar1) {
            if (_DAT_0066dfd4 <= fVar1) {
              if (_DAT_0066dfd8 <= fVar1) {
                if (*(int *)(unaff_EBP + 8) == 0) {
                  uVar5 = *(undefined4 *)(extraout_ECX + 0x1f8);
                }
                else {
                  uVar5 = *(undefined4 *)(extraout_ECX + 0x1a4);
                }
              }
              else if (*(int *)(unaff_EBP + 8) == 0) {
                uVar5 = *(undefined4 *)(extraout_ECX + 0x1ec);
              }
              else {
                uVar5 = *(undefined4 *)(extraout_ECX + 0x198);
              }
            }
            else if (*(int *)(unaff_EBP + 8) == 0) {
              uVar5 = *(undefined4 *)(extraout_ECX + 0x1e0);
            }
            else {
              uVar5 = *(undefined4 *)(extraout_ECX + 0x18c);
            }
          }
          else if (*(int *)(unaff_EBP + 8) == 0) {
            uVar5 = *(undefined4 *)(extraout_ECX + 0x1d4);
          }
          else {
            uVar5 = *(undefined4 *)(extraout_ECX + 0x180);
          }
        }
        else if (*(int *)(unaff_EBP + 8) == 0) {
          uVar5 = *(undefined4 *)(extraout_ECX + 0x1c8);
        }
        else {
          uVar5 = *(undefined4 *)(*(int *)(extraout_ECX + 0x128) + 0x18);
        }
      }
      FUN_00510775(uVar5);
    }
    else if (iVar4 == 0) {
      if ((DAT_006f4194 & 1) == 0) {
        DAT_006f4194 = DAT_006f4194 | 1;
        FUN_005d4956(s__Start_006ccd2c);
        FUN_00635543(&LAB_00531112);
      }
      if ((DAT_006f4194 & 2) == 0) {
        DAT_006f4194 = DAT_006f4194 | 2;
        FUN_005d4956(&DAT_006ccd24);
        FUN_00635543(&LAB_00531108);
      }
      if ((DAT_006f4194 & 4) == 0) {
        DAT_006f4194 = DAT_006f4194 | 4;
        FUN_005d4956(s__CarTime_006ccd18);
        FUN_00635543(&LAB_005310fe);
      }
      iVar4 = FUN_004ea85e(iVar3);
      *(int *)(unaff_EBP + 8) = iVar4;
      if (iVar4 == 0) {
        FUN_00510747(**(undefined4 **)(extraout_ECX + 0x11c));
        FUN_00510775(**(undefined4 **)(extraout_ECX + 0x128));
        FUN_00503993(&PTR_LAB_006c2990);
        FUN_005c1719();
        *(undefined4 *)(unaff_EBP + -4) = 4;
        cVar2 = FUN_00530b47(0,unaff_EBP + -0x60,unaff_EBP + -0x14);
        if (cVar2 != '\0') {
          iVar3 = unaff_EBP + -0x60;
          uVar5 = FUN_004096c2(iVar3);
          FUN_0051052c(0,uVar5,iVar3);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005a5e09();
      }
      else {
        iVar3 = FUN_004eabb1(iVar3);
        piVar6 = DAT_006fe8bc;
        *(char *)(unaff_EBP + -0x1c) = '\x01' - (iVar3 != 1);
        piVar6 = (int *)(**(code **)(*piVar6 + 4))();
        FUN_005d48d9();
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_005d48d9();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005d48d9();
        iVar3 = *piVar6;
        uVar5 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x48);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        (**(code **)(iVar3 + 0x80))(unaff_EBP + -0x40,uVar5,0,0,0);
        (**(code **)(*piVar6 + 0x80))
                  (unaff_EBP + -0x34,*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x4c),0,0,0);
        iVar3 = *(int *)(*(int *)(unaff_EBP + 8) + 0x48);
        *(int *)(unaff_EBP + -0x18) = *piVar6;
        (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x80))
                  (unaff_EBP + -0x28,(iVar3 + 0x17) % 0x18,0,0,0);
        FUN_005d499c(extraout_ECX + 0x15c);
        iVar3 = FUN_004558e0(DAT_006f4188,0,DAT_006f418c - DAT_006f4188);
        if (iVar3 != -1) {
          FUN_00455790(iVar3,DAT_006f418c - DAT_006f4188,unaff_EBP + -0x40);
        }
        iVar3 = FUN_004558e0(DAT_006f4178,0,DAT_006f417c - DAT_006f4178);
        if (iVar3 != -1) {
          FUN_00455790(iVar3,DAT_006f417c - DAT_006f4178,unaff_EBP + -0x34);
        }
        iVar3 = FUN_004558e0(DAT_006f4168,0,DAT_006f416c - DAT_006f4168);
        if (iVar3 != -1) {
          FUN_00455790(iVar3,DAT_006f416c - DAT_006f4168,unaff_EBP + -0x28);
        }
        sVar7 = _strlen(&DAT_006c08dc);
        FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar7);
        _Str = (char *)FUN_004096c2();
        sVar7 = _strlen(_Str);
        FUN_00412d8a(_Str,_Str + sVar7);
        uVar5 = FUN_004033ea(*(undefined4 *)(unaff_EBP + -0x1c));
        FUN_00510747(uVar5);
        FUN_00510775(*(undefined4 *)(extraout_ECX + 0xf8));
        FUN_00503993(&PTR_LAB_006c2990);
        iVar3 = FUN_004ea83d(*(undefined4 *)(unaff_EBP + -0x14));
        FUN_005c1719();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (iVar3 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = FUN_004096c2();
        }
        cVar2 = FUN_00530b47(uVar5,unaff_EBP + -0x50,unaff_EBP + -0x10);
        if (cVar2 != '\0') {
          iVar3 = unaff_EBP + -0x50;
          uVar5 = FUN_004096c2(iVar3);
          FUN_0051052c(0,uVar5,iVar3);
        }
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_005a5e09();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
      }
    }
    else {
      FUN_00510747(*(undefined4 *)(*(int *)(extraout_ECX + 0x11c) + iVar4 * 0xc));
      if (*(int *)(unaff_EBP + 8) == 1) {
        iVar3 = FUN_004ea85e(*(undefined4 *)(unaff_EBP + -0x14));
        if (iVar3 == 0) {
          uVar5 = *(undefined4 *)(extraout_ECX + 0x1bc);
        }
        else {
          uVar5 = *(undefined4 *)(*(int *)(extraout_ECX + 0x128) + 0xc);
        }
      }
      else {
        uVar5 = *(undefined4 *)(*(int *)(extraout_ECX + 0x128) + iVar4 * 0xc);
      }
      FUN_00510775(uVar5);
      FUN_00503993(s_summary_006ccd10);
      FUN_00510489(0,0);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

