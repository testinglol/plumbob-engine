
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056eb75(void)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  char cVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  char *pcVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined1 uVar16;
  int extraout_ECX;
  int unaff_EBP;
  uint uVar17;
  int iVar18;
  int iVar19;
  bool bVar20;
  float10 fVar21;
  float10 fVar22;
  
  FUN_00634c24();
  uVar17 = 0;
  bVar20 = DAT_006f627c != 0;
  *(int *)(unaff_EBP + -100) = extraout_ECX;
  if (bVar20) {
    iVar10 = *(int *)(unaff_EBP + 8);
    FUN_0056f4a1(iVar10 + 0x78);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + -0x40) - *(int *)(unaff_EBP + -0x44) >> 2 != 0) {
      do {
        FUN_005ced0e(*(undefined4 *)(*(int *)(unaff_EBP + -0x44) + uVar17 * 4));
        uVar17 = uVar17 + 1;
      } while (uVar17 < (uint)(*(int *)(unaff_EBP + -0x40) - *(int *)(unaff_EBP + -0x44) >> 2));
    }
    iVar18 = *(int *)(extraout_ECX + 0xc);
    fVar21 = (float10)FUN_00570d26();
    *(float *)(unaff_EBP + -0x74) = (float)fVar21;
    SetRect((LPRECT)(unaff_EBP + -0xd4),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
    if (*(int *)(extraout_ECX + 0x24) != 0) {
      FUN_005ceca4(*(int *)(extraout_ECX + 0x24));
    }
    *(undefined1 *)(iVar10 + 0x66) = 0;
    iVar18 = iVar18 + -1;
    *(undefined4 *)(unaff_EBP + -0x20) = 1;
    *(int *)(unaff_EBP + -0x84) = iVar18;
    iVar14 = extraout_ECX;
    if (1 < iVar18) {
      do {
        *(undefined4 *)(unaff_EBP + -0x24) = 1;
        if (1 < iVar18) {
          do {
            piVar9 = (int *)FUN_0047c7b7(unaff_EBP + -0xc0,*(undefined4 *)(unaff_EBP + -0x20));
            iVar10 = *(int *)(unaff_EBP + -0x24);
            pbVar1 = (byte *)(*piVar9 + iVar10 * 2);
            if ((*(byte *)(*piVar9 + iVar10 * 2) & 1) != 0) {
              uVar16 = (undefined1)(iVar10 / 2);
              *(undefined1 *)(unaff_EBP + -0x14) = uVar16;
              uVar7 = (undefined1)(*(int *)(unaff_EBP + -0x20) / 2);
              *(undefined1 *)(unaff_EBP + -0x13) = uVar7;
              *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + 0xc);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              if (*(int *)(unaff_EBP + 0x10) != 0) {
                *(undefined1 *)(unaff_EBP + -0x38) = uVar16;
                *(undefined1 *)(unaff_EBP + -0x37) = uVar7;
                *(undefined1 *)(unaff_EBP + -0x36) = *(undefined1 *)(unaff_EBP + 0xc);
                iVar10 = DAT_006e54d8;
                *(undefined1 *)(unaff_EBP + -4) = 2;
                FUN_00434ffd(*(undefined4 *)(iVar10 + 0x84));
                FUN_004b3e97(unaff_EBP + -0x60,unaff_EBP + -0xc4,unaff_EBP + -0x38);
                iVar18 = 0;
                iVar10 = *(int *)(*(int *)(DAT_006e486c + 4) + 0x58) / 2 + 1;
                if (*(int *)(unaff_EBP + 0x14) < 1) {
LAB_0056ecf6:
                  *(undefined1 *)(unaff_EBP + -4) = 0;
                  goto LAB_0056f17f;
                }
                piVar9 = *(int **)(unaff_EBP + 0x10);
                iVar19 = *(int *)(unaff_EBP + -0x60) - iVar10;
                *(int *)(unaff_EBP + -0x18) = iVar19;
                while ((piVar9[2] <= iVar19 && (*(int *)(unaff_EBP + -0x60) + iVar10 < *piVar9))) {
                  iVar18 = iVar18 + 1;
                  piVar9 = piVar9 + 4;
                  if (*(int *)(unaff_EBP + 0x14) <= iVar18) goto LAB_0056ecf6;
                  iVar19 = *(int *)(unaff_EBP + -0x18);
                }
                *(undefined1 *)(unaff_EBP + -4) = 1;
              }
              piVar9 = (int *)FUN_0056f815(pbVar1,unaff_EBP + -0x68);
              FUN_005c35b0();
              *(undefined1 *)(unaff_EBP + -4) = 3;
              if (*(int *)(unaff_EBP + -0x68) != 0) {
                fVar2 = _DAT_006714d0 * _DAT_00666a48;
                *(float *)(unaff_EBP + -0x18) = fVar2;
                *(undefined4 *)(unaff_EBP + -0xb4) = *(undefined4 *)(unaff_EBP + -0x18);
                *(float *)(unaff_EBP + -0x10) =
                     (float)*(int *)(unaff_EBP + -0x68) * DAT_00673438 * _DAT_00666578;
                fVar3 = _DAT_006714d0 * _DAT_006714e0;
                *(float *)(unaff_EBP + -0x1c) = fVar3;
                *(float *)(unaff_EBP + -0x78) = fVar3;
                *(float *)(unaff_EBP + -0xbc) = fVar2;
                *(undefined4 *)(unaff_EBP + -0xb8) = 0;
                uVar11 = FUN_00462f96(unaff_EBP + -0x208,unaff_EBP + -0xbc);
                *(undefined1 *)(unaff_EBP + -4) = 4;
                uVar12 = FUN_005c38c0(unaff_EBP + -0x1c4,1,unaff_EBP + -0x10);
                *(undefined4 *)(unaff_EBP + -0x18) = uVar12;
                *(undefined1 *)(unaff_EBP + -4) = 5;
                *(undefined4 *)(unaff_EBP + -0xa0) = *(undefined4 *)(unaff_EBP + -0x78);
                *(undefined4 *)(unaff_EBP + -0x98) = *(undefined4 *)(unaff_EBP + -0x1c);
                *(undefined4 *)(unaff_EBP + -0x9c) = 0;
                uVar12 = FUN_00462f96(unaff_EBP + -0x24c,unaff_EBP + -0xa0);
                *(undefined1 *)(unaff_EBP + -4) = 6;
                uVar12 = FUN_0049b9e6(unaff_EBP + -0x2d4,uVar12,*(undefined4 *)(unaff_EBP + -0x18));
                *(undefined1 *)(unaff_EBP + -4) = 7;
                iVar10 = FUN_0049b9e6(unaff_EBP + -0x180,uVar12,uVar11);
                *(undefined1 *)(unaff_EBP + -4) = 8;
                FUN_00462f2f(iVar10);
                *(undefined4 *)(unaff_EBP + -0xd8) = *(undefined4 *)(iVar10 + 0x40);
                *(undefined1 *)(unaff_EBP + -4) = 7;
                FUN_005c4890();
                *(undefined1 *)(unaff_EBP + -4) = 6;
                FUN_005c4890();
                *(undefined1 *)(unaff_EBP + -4) = 5;
                FUN_005c4890();
                *(undefined1 *)(unaff_EBP + -4) = 4;
                FUN_005c4890();
                *(undefined1 *)(unaff_EBP + -4) = 3;
                FUN_005c4890();
              }
              uVar17 = *(uint *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x14) + 0xc) +
                                         *(char *)(unaff_EBP + -0x14) * 4) +
                                *(char *)(unaff_EBP + -0x13) * 4);
              *(uint *)(unaff_EBP + -0x18) = uVar17;
              cVar8 = (char)uVar17;
              *(uint *)(unaff_EBP + -0x10) = uVar17 >> 8 & 0xff;
              if (((cVar8 == *(char *)(unaff_EBP + -0x16)) && (cVar8 == (char)(uVar17 >> 8))) &&
                 (cVar8 == *(char *)(unaff_EBP + -0x15))) {
LAB_0056ef9f:
                *(float *)(unaff_EBP + -0x1c) = (float)*(int *)(unaff_EBP + -0x10);
                fVar22 = (float10)FUN_00454f69(unaff_EBP + -0x1c);
                fVar21 = (float10)_DAT_006714d0;
                *(uint *)(unaff_EBP + -0x1c) = (uint)pbVar1[1];
                iVar10 = DAT_006e486c;
                *(undefined4 *)(unaff_EBP + -0x50) = 0;
                *(float *)(unaff_EBP + -0x4c) =
                     (float)((float10)*(int *)(unaff_EBP + -0x1c) *
                             (float10)*(float *)(unaff_EBP + -0x74) + fVar22 * fVar21);
                *(undefined4 *)(unaff_EBP + -0x48) = 0;
                piVar4 = *(int **)(iVar10 + 4);
                iVar10 = *piVar4;
                *(float *)(unaff_EBP + -0x10) = (float)*(int *)(unaff_EBP + 0xc);
                iVar18 = (**(code **)(iVar10 + 0x14))();
                iVar14 = (**(code **)(*piVar4 + 0x24))();
                iVar10 = DAT_006e54d8;
                iVar14 = iVar14 + iVar18 * -0xc;
                fVar2 = *(float *)(iVar14 + 0xc0);
                fVar3 = *(float *)(iVar14 + 0xbc);
                *(float *)(unaff_EBP + -0x5c) =
                     *(float *)(unaff_EBP + -0x10) * *(float *)(iVar14 + 0xb8);
                *(float *)(unaff_EBP + -0x58) = *(float *)(unaff_EBP + -0x10) * fVar3;
                *(float *)(unaff_EBP + -0x54) = *(float *)(unaff_EBP + -0x10) * fVar2;
                *(int *)(unaff_EBP + -0x1c) = -*(int *)(iVar10 + 0x84);
                *(float *)(unaff_EBP + -0x80) =
                     (float)*(int *)(unaff_EBP + -0x1c) * DAT_00673438 * _DAT_00666578;
                uVar11 = FUN_005c38c0(unaff_EBP + -0x290,1,unaff_EBP + -0x80);
                *(undefined1 *)(unaff_EBP + -4) = 0xd;
                puVar15 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x130,unaff_EBP + -0x5c,uVar11);
                *(undefined4 *)(unaff_EBP + -0x5c) = *puVar15;
                *(undefined4 *)(unaff_EBP + -0x58) = puVar15[1];
                *(undefined4 *)(unaff_EBP + -0x54) = puVar15[2];
                *(undefined1 *)(unaff_EBP + -4) = 3;
                FUN_005c4890();
                *(float *)(unaff_EBP + -0x50) =
                     *(float *)(unaff_EBP + -0x5c) + *(float *)(unaff_EBP + -0x50);
                *(float *)(unaff_EBP + -0x4c) =
                     *(float *)(unaff_EBP + -0x4c) + *(float *)(unaff_EBP + -0x58);
                *(float *)(unaff_EBP + -0x48) =
                     *(float *)(unaff_EBP + -0x48) + *(float *)(unaff_EBP + -0x54);
                *(undefined4 *)(unaff_EBP + -0x70) = 0;
                fVar2 = _DAT_00666578;
                *(float *)(unaff_EBP + -0x6c) = (float)*(int *)(unaff_EBP + -0x20) * _DAT_00666578;
                *(float *)(unaff_EBP + -0x7c) = (float)*(int *)(unaff_EBP + -0x24) * fVar2;
                uVar11 = FUN_004ca6b6(unaff_EBP + -0x13c,unaff_EBP + -0x7c,unaff_EBP + -0x6c,
                                      unaff_EBP + -0x70);
                uVar11 = FUN_0045ef64(unaff_EBP + -0x124,unaff_EBP + -0x50,uVar11);
                uVar11 = FUN_00462f96(unaff_EBP + -0x318,uVar11);
                *(undefined1 *)(unaff_EBP + -4) = 0xe;
                FUN_00462c01(uVar11);
                *(undefined1 *)(unaff_EBP + -4) = 3;
                FUN_005c4890();
                FUN_00463023(unaff_EBP + -0x118);
                FUN_005cf6fc(*(undefined4 *)(unaff_EBP + 8),0);
                *(int *)(unaff_EBP + -0x94) = piVar9[1];
                *(int *)(unaff_EBP + -0x90) = piVar9[2];
                *(int *)(unaff_EBP + -0x8c) = piVar9[3];
                *(int *)(unaff_EBP + -0x88) = piVar9[4];
                if ((*(int *)(unaff_EBP + -0x94) < *(int *)(unaff_EBP + -0x8c)) &&
                   (*(int *)(unaff_EBP + -0x90) < *(int *)(unaff_EBP + -0x88))) {
                  FUN_00422698();
                }
                (**(code **)(*piVar9 + 8))();
              }
              else if ((*pbVar1 & 2) != 0) {
                iVar10 = FUN_0056f209(0);
                uVar6 = DAT_006e4831;
                uVar5 = DAT_006e482e;
                uVar16 = DAT_006e482b;
                uVar7 = DAT_006e4828;
                if (iVar10 == 1) {
                  *(undefined1 *)(unaff_EBP + -0x2a) = 0;
                  *(undefined1 *)(unaff_EBP + -0x2c) = uVar16;
                  *(undefined1 *)(unaff_EBP + -0x2b) = DAT_006e482c;
                  iVar10 = unaff_EBP + -0x2c;
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  iVar18 = unaff_EBP + -0xb0;
LAB_0056ef74:
                  pcVar13 = (char *)FUN_0046185f(iVar18,iVar10);
                  cVar8 = pcVar13[1];
                  iVar10 = *(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x14) + 0xc) + *pcVar13 * 4);
                }
                else {
                  if (iVar10 == 2) {
                    *(undefined1 *)(unaff_EBP + -0x26) = 0;
                    *(undefined1 *)(unaff_EBP + -0x28) = uVar6;
                    *(undefined1 *)(unaff_EBP + -0x27) = DAT_006e4832;
                    iVar10 = unaff_EBP + -0x28;
                    *(undefined1 *)(unaff_EBP + -4) = 10;
                    iVar18 = unaff_EBP + -0xac;
                    goto LAB_0056ef74;
                  }
                  if (iVar10 == 4) {
                    *(undefined1 *)(unaff_EBP + -0x2e) = 0;
                    *(undefined1 *)(unaff_EBP + -0x30) = uVar5;
                    *(undefined1 *)(unaff_EBP + -0x2f) = DAT_006e482f;
                    iVar10 = unaff_EBP + -0x30;
                    *(undefined1 *)(unaff_EBP + -4) = 0xb;
                    iVar18 = unaff_EBP + -0xa8;
                    goto LAB_0056ef74;
                  }
                  if (iVar10 != 8) goto LAB_0056ef9f;
                  *(undefined1 *)(unaff_EBP + -0x32) = 0;
                  *(undefined1 *)(unaff_EBP + -0x34) = uVar7;
                  *(undefined1 *)(unaff_EBP + -0x33) = DAT_006e4829;
                  *(undefined1 *)(unaff_EBP + -4) = 0xc;
                  pcVar13 = (char *)FUN_0046185f(unaff_EBP + -0xa4,unaff_EBP + -0x34);
                  cVar8 = pcVar13[1];
                  iVar10 = *(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x14) + 0xc) + *pcVar13 * 4);
                }
                *(uint *)(unaff_EBP + -0x10) = (uint)*(byte *)(iVar10 + 1 + cVar8 * 4);
                *(undefined1 *)(unaff_EBP + -4) = 3;
                goto LAB_0056ef9f;
              }
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_005c4890();
              *(undefined1 *)(unaff_EBP + -4) = 0;
              iVar14 = *(int *)(unaff_EBP + -100);
            }
LAB_0056f17f:
            *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
            iVar18 = *(int *)(unaff_EBP + -0x84);
          } while (*(int *)(unaff_EBP + -0x24) < iVar18);
          iVar10 = *(int *)(unaff_EBP + 8);
        }
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
      } while (*(int *)(unaff_EBP + -0x20) < iVar18);
    }
    *(undefined1 *)(iVar10 + 0x66) = 1;
    FUN_005cf0fa(unaff_EBP + -0xd4);
    if (*(int *)(iVar14 + 0x24) != 0) {
      FUN_005ced0e(*(int *)(iVar14 + 0x24));
    }
    uVar17 = 0;
    if (*(int *)(unaff_EBP + -0x40) - *(int *)(unaff_EBP + -0x44) >> 2 != 0) {
      do {
        FUN_005ceca4(*(undefined4 *)(*(int *)(unaff_EBP + -0x44) + uVar17 * 4));
        uVar17 = uVar17 + 1;
      } while (uVar17 < (uint)(*(int *)(unaff_EBP + -0x40) - *(int *)(unaff_EBP + -0x44) >> 2));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0048c4c9();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

