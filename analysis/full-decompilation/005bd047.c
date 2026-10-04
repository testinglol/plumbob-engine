
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bd047(void)

{
  double dVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  bool bVar5;
  short sVar6;
  int iVar7;
  size_t sVar8;
  int iVar9;
  size_t sVar10;
  char cVar11;
  char *pcVar12;
  char *pcVar13;
  int unaff_EBP;
  double *pdVar14;
  undefined8 uVar15;
  
  FUN_00634c24();
  uVar4 = DAT_00666580;
  *(int *)(unaff_EBP + -0x1c) = unaff_EBP + 0x10;
  FUN_00406466(0,uVar4);
  iVar7 = 0;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  pcVar13 = *(char **)(unaff_EBP + 0xc);
  *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar11 = *pcVar13;
  if (cVar11 != '\0') {
    do {
      if (cVar11 == '%') {
        *(undefined1 *)(unaff_EBP + -0x14) = 0;
        FUN_005bd7b3(0x40,unaff_EBP + -0x14);
        *(undefined1 *)(unaff_EBP + -0x10) = 0;
        *(undefined1 *)(unaff_EBP + -0x13) = 0;
        *(undefined1 *)(unaff_EBP + -0x12) = 0;
        *(undefined1 *)(unaff_EBP + -0xf) = 0;
        *(undefined1 *)(unaff_EBP + -0x11) = 0;
        pcVar13 = *(char **)(unaff_EBP + 0xc);
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                while( true ) {
                  cVar11 = *pcVar13;
                  pcVar12 = pcVar13 + 1;
                  if (cVar11 != '-') break;
                  *(undefined1 *)(unaff_EBP + -0x10) = 1;
                  pcVar13 = pcVar12;
                }
                if (cVar11 != '+') break;
                *(undefined1 *)(unaff_EBP + -0x13) = 1;
                pcVar13 = pcVar12;
              }
              if (cVar11 != ' ') break;
              *(undefined1 *)(unaff_EBP + -0x12) = 1;
              pcVar13 = pcVar12;
            }
            if (cVar11 != '0') break;
            *(undefined1 *)(unaff_EBP + -0xf) = 1;
            pcVar13 = pcVar12;
          }
          if (cVar11 != '#') break;
          *(undefined1 *)(unaff_EBP + -0x11) = 1;
          pcVar13 = pcVar12;
        }
        *(char **)(unaff_EBP + 0xc) = pcVar12;
        if (cVar11 == '%') {
          FUN_004015e4();
        }
        else {
          if (*(char *)(unaff_EBP + -0x10) != '\0') {
            *(undefined1 *)(unaff_EBP + -0xf) = 0;
          }
          if (*(char *)(unaff_EBP + -0x13) != '\0') {
            *(undefined1 *)(unaff_EBP + -0x12) = 0;
          }
          *(undefined4 *)(unaff_EBP + -0x34) = 0xffffffff;
          if (cVar11 == '*') {
            puVar3 = *(undefined4 **)(unaff_EBP + -0x1c);
            cVar11 = *pcVar12;
            pdVar14 = (double *)(puVar3 + 1);
            pcVar12 = pcVar13 + 2;
            *(double **)(unaff_EBP + -0x1c) = pdVar14;
            uVar4 = *puVar3;
            *(char **)(unaff_EBP + 0xc) = pcVar12;
            *(undefined4 *)(unaff_EBP + -0x34) = uVar4;
          }
          else {
            if (('/' < cVar11) && (cVar11 < ':')) {
              iVar7 = 0;
              do {
                iVar9 = (int)cVar11;
                cVar11 = *pcVar12;
                pcVar12 = pcVar12 + 1;
                iVar7 = iVar9 + -0x30 + iVar7 * 10;
                *(char **)(unaff_EBP + 0xc) = pcVar12;
                *(int *)(unaff_EBP + -0x34) = iVar7;
                if (cVar11 < '0') break;
              } while (cVar11 < ':');
            }
            pdVar14 = *(double **)(unaff_EBP + -0x1c);
          }
          *(undefined4 *)(unaff_EBP + -0x28) = 0xffffffff;
          pcVar13 = pcVar12;
          if (cVar11 == '.') {
            cVar11 = *pcVar12;
            pcVar13 = pcVar12 + 1;
            *(char **)(unaff_EBP + 0xc) = pcVar13;
            if (cVar11 == '*') {
              cVar11 = *pcVar13;
              uVar4 = *(undefined4 *)pdVar14;
              pdVar14 = (double *)((int)pdVar14 + 4);
              pcVar13 = pcVar12 + 2;
              *(double **)(unaff_EBP + -0x1c) = pdVar14;
              *(undefined4 *)(unaff_EBP + -0x28) = uVar4;
              *(char **)(unaff_EBP + 0xc) = pcVar13;
            }
            else if (('/' < cVar11) && (cVar11 < ':')) {
              iVar7 = 0;
              do {
                iVar9 = (int)cVar11;
                cVar11 = *pcVar13;
                pcVar13 = pcVar13 + 1;
                iVar7 = iVar9 + -0x30 + iVar7 * 10;
                *(char **)(unaff_EBP + 0xc) = pcVar13;
                *(int *)(unaff_EBP + -0x28) = iVar7;
                if (cVar11 < '0') break;
              } while (cVar11 < ':');
            }
          }
          *(undefined4 *)(unaff_EBP + -0x2c) = 1;
          if (cVar11 == 'I') {
            if ((*pcVar13 == '6') && (pcVar13[1] == '4')) {
              pcVar13 = pcVar13 + 2;
LAB_005bd208:
              cVar11 = *pcVar13;
              pcVar13 = pcVar13 + 1;
              *(char **)(unaff_EBP + 0xc) = pcVar13;
              *(undefined4 *)(unaff_EBP + -0x2c) = 3;
            }
          }
          else if (cVar11 == 'h') {
            cVar11 = *pcVar13;
            pcVar13 = pcVar13 + 1;
            *(undefined4 *)(unaff_EBP + -0x2c) = 0;
            *(char **)(unaff_EBP + 0xc) = pcVar13;
          }
          else if (cVar11 == 'l') {
            cVar11 = *pcVar13;
            pcVar13 = pcVar13 + 1;
            *(char **)(unaff_EBP + 0xc) = pcVar13;
            *(undefined4 *)(unaff_EBP + -0x2c) = 2;
            if (cVar11 == 'l') goto LAB_005bd208;
          }
          iVar7 = *(int *)(unaff_EBP + -0x48);
          *(undefined1 *)(unaff_EBP + -0x14) = 0;
          *(undefined1 *)(unaff_EBP + -0xd) = 0;
          *(undefined1 *)(unaff_EBP + -0xe) = 0;
          *(int *)(unaff_EBP + -0x20) = iVar7;
          if (cVar11 < 'h') {
            if (cVar11 < 'e') {
              if (cVar11 != 'C') {
                if ((cVar11 == 'E') || (cVar11 == 'G')) goto LAB_005bd283;
                if (cVar11 != 'S') {
                  if (cVar11 == 'X') goto LAB_005bd3f7;
                  if (cVar11 == 'c') {
                    uVar2 = *(undefined1 *)pdVar14;
                    iVar7 = iVar7 + 1;
                    *(int *)(unaff_EBP + -0x1c) = (int)pdVar14 + 4;
                    **(undefined1 **)(unaff_EBP + -0x48) = uVar2;
                    goto LAB_005bd4f6;
                  }
                  if (cVar11 == 'd') goto LAB_005bd3f3;
                }
              }
LAB_005bd364:
              *(char **)(unaff_EBP + 0xc) = pcVar13 + -1;
            }
            else {
LAB_005bd283:
              *(undefined1 *)(unaff_EBP + -0x68) = 0x25;
              pcVar13 = (char *)(unaff_EBP + -0x67);
              if (*(char *)(unaff_EBP + -0x11) != '\0') {
                *(undefined1 *)(unaff_EBP + -0x67) = 0x23;
                pcVar13 = (char *)(unaff_EBP + -0x66);
              }
              if (-1 < *(int *)(unaff_EBP + -0x28)) {
                uVar4 = *(undefined4 *)(unaff_EBP + -0x28);
                *pcVar13 = '.';
                iVar7 = FUN_00635858(pcVar13 + 1,&DAT_006c08e4,uVar4);
                pcVar13 = pcVar13 + 1 + iVar7;
              }
              dVar1 = *pdVar14;
              *pcVar13 = cVar11;
              pcVar13[1] = '\0';
              *(double **)(unaff_EBP + -0x1c) = pdVar14 + 1;
              bVar5 = dVar1 < _DAT_006669e8;
              *(double *)(unaff_EBP + -0x3c) = dVar1;
              *(undefined1 *)(unaff_EBP + -0xd) = 1;
              if (bVar5) {
                dVar1 = -dVar1;
                *(double *)(unaff_EBP + -0x3c) = dVar1;
                *(undefined1 *)(unaff_EBP + -0xe) = 1;
              }
              while (iVar7 = FUN_00638c2e(*(undefined4 *)(unaff_EBP + -0x48),
                                          *(int *)(unaff_EBP + -0x44) - *(int *)(unaff_EBP + -0x48),
                                          unaff_EBP + -0x68,dVar1), iVar7 < 0) {
                *(undefined1 *)(unaff_EBP + -0x15) = 0;
                FUN_005bd7b3((*(int *)(unaff_EBP + -0x48) * 0x7fffffff + *(int *)(unaff_EBP + -0x40)
                             ) * 2,unaff_EBP + -0x15);
                dVar1 = *(double *)(unaff_EBP + -0x3c);
              }
              *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x48);
              iVar7 = iVar7 + *(int *)(unaff_EBP + -0x48);
            }
          }
          else {
            if (cVar11 == 'i') {
LAB_005bd3f3:
              *(undefined1 *)(unaff_EBP + -0xd) = 1;
LAB_005bd3f7:
              iVar9 = *(int *)(unaff_EBP + -0x2c);
              *(undefined1 *)(unaff_EBP + -0x14) = 1;
              *(undefined1 *)(unaff_EBP + -0x68) = 0x25;
              if (iVar9 == 0) {
                sVar6 = *(short *)pdVar14;
                *(int *)(unaff_EBP + -0x1c) = (int)pdVar14 + 4;
                if ((sVar6 < 0) && (*(char *)(unaff_EBP + -0xd) != '\0')) {
                  *(undefined1 *)(unaff_EBP + -0xe) = 1;
                  cVar11 = 'u';
                  sVar6 = -sVar6;
                }
                *(undefined1 *)(unaff_EBP + -0x65) = 0;
                *(undefined1 *)(unaff_EBP + -0x67) = 0x68;
                *(char *)(unaff_EBP + -0x66) = cVar11;
                iVar7 = (int)sVar6;
LAB_005bd4e1:
                uVar15 = CONCAT44(iVar7,unaff_EBP + -0x68);
                goto LAB_005bd4e6;
              }
              if (iVar9 == 1) {
                iVar7 = *(int *)pdVar14;
                *(int *)(unaff_EBP + -0x1c) = (int)pdVar14 + 4;
                if ((iVar7 < 0) && (*(char *)(unaff_EBP + -0xd) != '\0')) {
                  *(undefined1 *)(unaff_EBP + -0xe) = 1;
                  cVar11 = 'u';
                  iVar7 = -iVar7;
                }
                *(undefined1 *)(unaff_EBP + -0x66) = 0;
                *(char *)(unaff_EBP + -0x67) = cVar11;
                goto LAB_005bd4e1;
              }
              if (iVar9 == 2) {
                iVar7 = *(int *)pdVar14;
                *(int *)(unaff_EBP + -0x1c) = (int)pdVar14 + 4;
                if ((iVar7 < 0) && (*(char *)(unaff_EBP + -0xd) != '\0')) {
                  *(undefined1 *)(unaff_EBP + -0xe) = 1;
                  cVar11 = 'u';
                  iVar7 = -iVar7;
                }
                *(undefined1 *)(unaff_EBP + -0x65) = 0;
                *(undefined1 *)(unaff_EBP + -0x67) = 0x6c;
                *(char *)(unaff_EBP + -0x66) = cVar11;
                goto LAB_005bd4e1;
              }
              if (iVar9 != 3) goto LAB_005bd4f6;
              iVar7 = *(int *)((int)pdVar14 + 4);
              iVar9 = *(int *)pdVar14;
              *(double **)(unaff_EBP + -0x1c) = pdVar14 + 1;
              if (((iVar7 < 1) && (iVar7 < 0)) && (*(char *)(unaff_EBP + -0xd) != '\0')) {
                iVar9 = -iVar9;
                *(undefined1 *)(unaff_EBP + -0xe) = 1;
                cVar11 = 'u';
              }
              *(undefined1 *)(unaff_EBP + -99) = 0;
              *(undefined1 *)(unaff_EBP + -0x67) = 0x49;
              *(undefined1 *)(unaff_EBP + -0x66) = 0x36;
              *(undefined1 *)(unaff_EBP + -0x65) = 0x34;
              *(char *)(unaff_EBP + -100) = cVar11;
              iVar7 = FUN_00635858(*(undefined4 *)(unaff_EBP + -0x48),unaff_EBP + -0x68,iVar9);
            }
            else {
              if (cVar11 == 'n') {
                *(int *)(unaff_EBP + -0x1c) = (int)pdVar14 + 4;
                **(int **)pdVar14 =
                     *(int *)(*(int *)(unaff_EBP + 8) + 8) - *(int *)(*(int *)(unaff_EBP + 8) + 4);
                goto LAB_005bd67a;
              }
              if (cVar11 == 'o') goto LAB_005bd3f7;
              if (cVar11 != 'p') {
                if (cVar11 != 's') {
                  if ((cVar11 != 'u') && (cVar11 != 'x')) goto LAB_005bd364;
                  goto LAB_005bd3f7;
                }
                pcVar13 = *(char **)pdVar14;
                *(int *)(unaff_EBP + -0x1c) = (int)pdVar14 + 4;
                *(char **)(unaff_EBP + -0x20) = pcVar13;
                sVar8 = _strlen(pcVar13);
                sVar10 = sVar8;
                if (-1 < *(int *)(unaff_EBP + -0x28)) {
                  sVar10 = 0;
                  *(undefined4 *)(unaff_EBP + -0x30) = 0;
                  if (0 < (int)sVar8) {
                    do {
                      if ((*(int *)(unaff_EBP + -0x28) <= *(int *)(unaff_EBP + -0x30)) ||
                         (iVar7 = FUN_005c06f6(*(int *)(unaff_EBP + -0x20) + sVar10,sVar8 - sVar10),
                         iVar7 == 0)) break;
                      sVar10 = sVar10 + iVar7;
                      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
                    } while ((int)sVar10 < (int)sVar8);
                  }
                }
                iVar7 = sVar10 + *(int *)(unaff_EBP + -0x20);
                goto LAB_005bd4f6;
              }
              uVar4 = *(undefined4 *)pdVar14;
              *(int *)(unaff_EBP + -0x1c) = (int)pdVar14 + 4;
              uVar15 = CONCAT44(uVar4,&DAT_006d25ac);
LAB_005bd4e6:
              iVar7 = FUN_00635858(*(undefined4 *)(unaff_EBP + -0x48),uVar15);
            }
            iVar7 = iVar7 + *(int *)(unaff_EBP + -0x20);
          }
LAB_005bd4f6:
          iVar9 = FUN_005c0787(*(undefined4 *)(unaff_EBP + -0x20),
                               iVar7 - *(int *)(unaff_EBP + -0x20));
          *(undefined1 *)(unaff_EBP + -0x24) = 0;
          *(undefined4 *)(unaff_EBP + -0x38) = 0;
          *(undefined4 *)(unaff_EBP + -0x30) = 0;
          *(undefined4 *)(unaff_EBP + -0x2c) = 0;
          if (*(char *)(unaff_EBP + -0x14) != '\0') {
            if (iVar9 < *(int *)(unaff_EBP + -0x28)) {
              *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x28) - iVar9;
            }
            if (*(char *)(unaff_EBP + -0x11) != '\0') {
              if (cVar11 == 'X') {
                *(undefined **)(unaff_EBP + -0x2c) = &DAT_006d25a4;
LAB_005bd559:
                iVar9 = iVar9 + 2;
              }
              else if (cVar11 == 'o') {
                *(undefined **)(unaff_EBP + -0x2c) = &DAT_006c839c;
                iVar9 = iVar9 + 1;
              }
              else if (cVar11 == 'x') {
                *(undefined **)(unaff_EBP + -0x2c) = &DAT_006d25a8;
                goto LAB_005bd559;
              }
            }
          }
          if (*(char *)(unaff_EBP + -0xd) != '\0') {
            if (*(char *)(unaff_EBP + -0xe) == '\0') {
              if (*(char *)(unaff_EBP + -0x12) != '\0') {
                *(undefined1 *)(unaff_EBP + -0x24) = 0x20;
              }
              if (*(char *)(unaff_EBP + -0x13) != '\0') {
                *(undefined1 *)(unaff_EBP + -0x24) = 0x2b;
              }
              if (*(char *)(unaff_EBP + -0x24) == '\0') goto LAB_005bd5a2;
            }
            else {
              *(undefined1 *)(unaff_EBP + -0x24) = 0x2d;
            }
            iVar9 = iVar9 + 1;
            if ((*(char *)(unaff_EBP + -0x24) != '\0') && (*(char *)(unaff_EBP + -0xf) != '\0')) {
              FUN_004015e4();
            }
          }
LAB_005bd5a2:
          if (((0 < *(int *)(unaff_EBP + -0x34)) &&
              (iVar9 = *(int *)(unaff_EBP + -0x34) - iVar9, *(int *)(unaff_EBP + -0x30) = iVar9,
              0 < iVar9)) && (*(char *)(unaff_EBP + -0x10) == '\0')) {
            FUN_00548250(*(undefined4 *)(unaff_EBP + -0x30),
                         ((*(char *)(unaff_EBP + -0xf) == '\0') - 1U & 0x10) + 0x20);
          }
          if ((*(char *)(unaff_EBP + -0x24) != '\0') && (*(char *)(unaff_EBP + -0xf) == '\0')) {
            FUN_004015e4();
          }
          if (*(int *)(unaff_EBP + -0x2c) != 0) {
            sVar10 = _strlen(*(char **)(unaff_EBP + -0x2c));
            FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x2c),sVar10 + *(int *)(unaff_EBP + -0x2c));
          }
          if (0 < *(int *)(unaff_EBP + -0x38)) {
            FUN_00548250(*(undefined4 *)(unaff_EBP + -0x38),0x30);
          }
          FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x20),iVar7);
          if ((0 < *(int *)(unaff_EBP + -0x30)) && (*(char *)(unaff_EBP + -0x10) != '\0')) {
            FUN_00548250(*(undefined4 *)(unaff_EBP + -0x30),0x20);
          }
        }
      }
      else {
        pcVar12 = *(char **)(unaff_EBP + 0xc);
        pcVar13 = pcVar12 + -1;
        while ((*pcVar12 != '\0' && (*pcVar12 != '%'))) {
          pcVar12 = pcVar12 + 1;
          *(char **)(unaff_EBP + 0xc) = pcVar12;
        }
        FUN_00412d8a(pcVar13,pcVar12);
      }
LAB_005bd67a:
      pcVar13 = *(char **)(unaff_EBP + 0xc);
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
      cVar11 = *pcVar13;
    } while (cVar11 != '\0');
    iVar7 = *(int *)(unaff_EBP + -0x40);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar7 = iVar7 - *(int *)(unaff_EBP + -0x48);
  if (iVar7 != 0) {
    FUN_0040189d(*(undefined4 *)(unaff_EBP + -0x48),iVar7);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

