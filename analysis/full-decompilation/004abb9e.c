
void FUN_004abb9e(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  undefined1 uVar8;
  int iVar9;
  uint *puVar10;
  undefined4 *puVar11;
  int *piVar12;
  HWND hWnd;
  undefined4 uVar13;
  undefined1 *puVar14;
  int *extraout_ECX;
  uint *puVar15;
  int unaff_EBP;
  int *piVar16;
  int iVar17;
  bool bVar18;
  undefined8 uVar19;
  LPPOINT lpPoint;
  
  FUN_00634c24();
  if (*(char *)((int)extraout_ECX + 0x49) != '\0') {
    iVar9 = FUN_00401f6f();
    *(bool *)(unaff_EBP + -0x15) = iVar9 == 2;
    FUN_00635e55(unaff_EBP + -0x250,8,0x40,FUN_004678f9,FUN_00416e17);
    piVar12 = extraout_ECX + 0x82;
    piVar16 = (int *)(unaff_EBP + -0x250);
    for (iVar9 = 0x80; piVar4 = DAT_006e486c, iVar9 != 0; iVar9 = iVar9 + -1) {
      *piVar16 = *piVar12;
      piVar12 = piVar12 + 1;
      piVar16 = piVar16 + 1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined1 *)(unaff_EBP + -0x16) = 0;
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(*piVar4 + 0x24);
    if (*(char *)(unaff_EBP + 8) != '\0') {
      piVar12 = extraout_ECX + 0x82;
      for (iVar9 = 0x80; iVar9 != 0; iVar9 = iVar9 + -1) {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
      }
      iVar17 = 0;
      iVar9 = FUN_004ed827();
      if (0 < iVar9) {
        do {
          iVar9 = FUN_0049eaee(iVar17);
          puVar15 = (uint *)(extraout_ECX + 0x82);
          puVar10 = (uint *)(iVar9 + 0x80);
          *(undefined4 *)(unaff_EBP + -0x24) = 0x40;
          do {
            uVar2 = puVar10[1];
            *puVar15 = *puVar15 | *puVar10;
            puVar15[1] = puVar15[1] | uVar2;
            puVar15 = puVar15 + 2;
            puVar10 = puVar10 + 2;
            piVar12 = (int *)(unaff_EBP + -0x24);
            *piVar12 = *piVar12 + -1;
          } while (*piVar12 != 0);
          FUN_0049eaee(iVar17);
          cVar5 = FUN_00468851();
          if (cVar5 != '\0') {
            *(undefined1 *)(unaff_EBP + -0x16) = 1;
          }
          iVar17 = iVar17 + 1;
          iVar9 = FUN_004ed827();
        } while (iVar17 < iVar9);
      }
    }
    if (*(char *)(unaff_EBP + -0x15) != '\0') {
      if (DAT_006f6b5c == 0) {
        iVar9 = FUN_00445724();
      }
      else {
        iVar9 = FUN_006359f2(DAT_006f6b5c,0,&cXObject::RTTI_Type_Descriptor,
                             &cXPerson::RTTI_Type_Descriptor,0);
      }
      *(int *)(unaff_EBP + -0x1c) = iVar9;
      if (((iVar9 != 0) && (*(int *)(iVar9 + 0x110) == extraout_ECX[6])) &&
         (*(ushort *)(iVar9 + 0xafc) < 0xfffb)) {
        iVar9 = FUN_004670a4(*(ushort *)(iVar9 + 0xafc));
        puVar15 = (uint *)(extraout_ECX + 0x82);
        puVar10 = (uint *)(iVar9 + 0x80);
        *(undefined4 *)(unaff_EBP + -0x24) = 0x40;
        do {
          uVar2 = puVar10[1];
          *puVar15 = *puVar15 | *puVar10;
          puVar15[1] = puVar15[1] | uVar2;
          puVar15 = puVar15 + 2;
          puVar10 = puVar10 + 2;
          piVar12 = (int *)(unaff_EBP + -0x24);
          *piVar12 = *piVar12 + -1;
        } while (*piVar12 != 0);
        cVar5 = FUN_00468851();
        if (cVar5 != '\0') {
          iVar9 = *(int *)(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -0x16) = 1;
          cVar5 = *(char *)(iVar9 + 0xfc);
          cVar1 = *(char *)(iVar9 + 0xfd);
          uVar8 = *(undefined1 *)(iVar9 + 0xfe);
          *(char *)(unaff_EBP + -0x1c) = cVar5;
          *(char *)(unaff_EBP + -0x1b) = cVar1;
          *(undefined1 *)(unaff_EBP + -0x1a) = uVar8;
          if ((('\0' < cVar5) && (iVar9 = *(int *)(DAT_006e54dc + 0x10) + -1, cVar5 < iVar9)) &&
             (('\0' < cVar1 && (cVar1 < iVar9)))) {
            FUN_00434ffd(*(undefined4 *)(DAT_006e54d8 + 0x84));
            cVar1 = *(char *)(unaff_EBP + -0x1c);
            *(undefined1 *)(unaff_EBP + -0xf) = 0;
            iVar17 = DAT_006e54d8;
            *(char *)(unaff_EBP + -0x14) = cVar1;
            *(char *)(unaff_EBP + -0x13) = *(char *)(unaff_EBP + -0x1b);
            *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0x1a);
            iVar9 = 4;
            cVar5 = cVar1 + '\x04';
            do {
              *(char *)(unaff_EBP + -0x11) = cVar5;
              cVar6 = cVar5 + (*(char *)(unaff_EBP + -0x1b) - cVar1);
              *(char *)(unaff_EBP + -0x15) = cVar6;
              *(char *)(unaff_EBP + -0x10) = cVar6;
              if (((*(int *)(iVar17 + 0x70) <= (int)cVar5) &&
                  ((int)cVar5 <= *(int *)(iVar17 + 0x74))) &&
                 ((*(int *)(iVar17 + 0x78) <= (int)*(char *)(unaff_EBP + -0x15) &&
                  ((int)*(char *)(unaff_EBP + -0x15) <= *(int *)(iVar17 + 0x7c))))) break;
              iVar9 = iVar9 + -1;
              cVar5 = cVar5 + -1;
            } while (-1 < iVar9);
            *(undefined4 *)(unaff_EBP + -0x30) = 0;
            *(undefined1 *)(unaff_EBP + -0x2a) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_004619d2(unaff_EBP + -0x48);
            *(undefined1 *)(unaff_EBP + -4) = 4;
            puVar11 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x28);
            *(undefined4 *)(unaff_EBP + -0x30) = *puVar11;
            FUN_00461b74(puVar11 + 1);
            while( true ) {
              iVar9 = FUN_004619d2(unaff_EBP + -0x40);
              *(undefined1 *)(unaff_EBP + -4) = 5;
              cVar5 = FUN_0046198c(iVar9 + 4);
              *(undefined1 *)(unaff_EBP + -4) = 4;
              cVar5 = '\x01' - (cVar5 != '\0');
              *(char *)(unaff_EBP + -0x15) = cVar5;
              if (cVar5 == '\0') break;
              FUN_00461941(unaff_EBP + -0x24);
              if ((((*(int *)(DAT_006e54d8 + 0x70) <= (int)*(char *)(unaff_EBP + -0x24)) &&
                   ((int)*(char *)(unaff_EBP + -0x24) <= *(int *)(DAT_006e54d8 + 0x74))) &&
                  (iVar9 = (int)*(char *)(unaff_EBP + -0x23), *(int *)(DAT_006e54d8 + 0x78) <= iVar9
                  )) && (iVar9 <= *(int *)(DAT_006e54d8 + 0x7c))) {
                puVar15 = (uint *)(extraout_ECX + iVar9 * 2 + 0x82);
                uVar19 = __allshl();
                *puVar15 = *puVar15 | (uint)uVar19;
                puVar15[1] = puVar15[1] | (uint)((ulonglong)uVar19 >> 0x20);
              }
              FUN_00461961();
            }
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
        }
      }
    }
    piVar12 = (int *)FUN_004d44c4();
    iVar9 = DAT_006e54d8;
    if ((piVar12 != (int *)0x0) &&
       (cVar5 = (**(code **)(*piVar12 + 0x54))(), iVar9 = DAT_006e54d8, cVar5 == '\0')) {
      GetCursorPos((LPPOINT)(unaff_EBP + -0x30));
      lpPoint = (LPPOINT)(unaff_EBP + -0x30);
      hWnd = (HWND)FUN_005caf13();
      ScreenToClient(hWnd,lpPoint);
      iVar9 = DAT_006e54d8;
      if (((-1 < *(int *)(unaff_EBP + -0x30)) &&
          ((piVar12 = (int *)FUN_005caed9(), iVar9 = DAT_006e54d8,
           *(int *)(unaff_EBP + -0x30) < *piVar12 && (-1 < *(int *)(unaff_EBP + -0x2c))))) &&
         (iVar17 = FUN_005caed9(), iVar9 = DAT_006e54d8,
         *(int *)(unaff_EBP + -0x2c) < *(int *)(iVar17 + 4))) {
        bVar7 = (**(code **)(*extraout_ECX + 0x14))();
        *(undefined2 *)(unaff_EBP + -0x22) = *(undefined2 *)(unaff_EBP + -0x30);
        piVar12 = DAT_006e54ac;
        bVar18 = DAT_006e54ac != (int *)0x0;
        iVar9 = *(int *)(unaff_EBP + -0x2c) + (8 << (bVar7 & 0x1f)) * 4;
        *(int *)(unaff_EBP + -0x2c) = iVar9;
        *(short *)(unaff_EBP + -0x24) = (short)iVar9;
        if (bVar18) {
          (**(code **)(*piVar12 + 0x44))(unaff_EBP + -0x24);
        }
        (**(code **)(*extraout_ECX + 4))(unaff_EBP + -0x48,*(undefined4 *)(unaff_EBP + -0x24),1);
        *(undefined1 *)(unaff_EBP + -0x12) = 0;
        *(undefined1 *)(unaff_EBP + -0xf) = 0;
        iVar9 = *extraout_ECX;
        *(undefined1 *)(unaff_EBP + -4) = 6;
        uVar8 = (**(code **)(iVar9 + 0x38))();
        *(char *)(unaff_EBP + -0x11) = (char)(*(int *)(unaff_EBP + -0x44) >> 4);
        *(char *)(unaff_EBP + -0x10) = (char)(*(int *)(unaff_EBP + -0x48) >> 4);
        *(undefined1 *)(unaff_EBP + -0xf) = uVar8;
        FUN_00461b74(&DAT_006e4828);
        *(undefined1 *)(unaff_EBP + -0x32) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 7;
        uVar13 = FUN_00494e66(unaff_EBP + -0x3c,4,unaff_EBP + -0x34);
        puVar14 = (undefined1 *)FUN_0046185f(unaff_EBP + -0x1c,uVar13);
        uVar8 = *puVar14;
        *(undefined1 *)(unaff_EBP + -4) = 6;
        *(undefined1 *)(unaff_EBP + -0x14) = uVar8;
        *(undefined1 *)(unaff_EBP + -0x13) = puVar14[1];
        *(undefined1 *)(unaff_EBP + -0x12) = puVar14[2];
        while( true ) {
          cVar5 = *(char *)(unaff_EBP + -0x11);
          if (((((*(int *)(DAT_006e54d8 + 0x70) <= (int)cVar5) &&
                ((int)cVar5 <= *(int *)(DAT_006e54d8 + 0x74))) &&
               (*(int *)(DAT_006e54d8 + 0x78) <= (int)*(char *)(unaff_EBP + -0x10))) &&
              ((int)*(char *)(unaff_EBP + -0x10) <= *(int *)(DAT_006e54d8 + 0x7c))) ||
             (((cVar5 == *(char *)(unaff_EBP + -0x14) &&
               (*(char *)(unaff_EBP + -0x10) == *(char *)(unaff_EBP + -0x13))) &&
              (*(char *)(unaff_EBP + -0xf) == *(char *)(unaff_EBP + -0x12))))) break;
          FUN_00461b74(&DAT_006e4828);
          *(undefined1 *)(unaff_EBP + -0x32) = 0;
          *(char *)(unaff_EBP + -0x11) = *(char *)(unaff_EBP + -0x11) + *(char *)(unaff_EBP + -0x34)
          ;
          *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + *(char *)(unaff_EBP + -0x33)
          ;
        }
        cVar5 = *(char *)(unaff_EBP + -0x14);
        iVar9 = DAT_006e54d8;
        while (((((int)cVar5 < *(int *)(iVar9 + 0x70) || (*(int *)(iVar9 + 0x74) < (int)cVar5)) ||
                (((int)*(char *)(unaff_EBP + -0x13) < *(int *)(iVar9 + 0x78) ||
                 (*(int *)(iVar9 + 0x7c) < (int)*(char *)(unaff_EBP + -0x13))))) &&
               (((*(char *)(unaff_EBP + -0x11) != cVar5 ||
                 (*(char *)(unaff_EBP + -0x10) != *(char *)(unaff_EBP + -0x13))) ||
                (*(char *)(unaff_EBP + -0xf) != *(char *)(unaff_EBP + -0x12)))))) {
          FUN_00461b74(&DAT_006e482b);
          cVar5 = *(char *)(unaff_EBP + -0x14) + *(char *)(unaff_EBP + -0x34);
          *(undefined1 *)(unaff_EBP + -0x32) = 0;
          *(char *)(unaff_EBP + -0x13) = *(char *)(unaff_EBP + -0x13) + *(char *)(unaff_EBP + -0x33)
          ;
          iVar9 = DAT_006e54d8;
          *(char *)(unaff_EBP + -0x14) = cVar5;
        }
        if (((*(char *)(unaff_EBP + -0x16) != '\0') &&
            (*(int *)(iVar9 + 0x70) <= (int)*(char *)(unaff_EBP + -0x14))) &&
           (((int)*(char *)(unaff_EBP + -0x14) <= *(int *)(iVar9 + 0x74) &&
            ((*(int *)(iVar9 + 0x78) <= (int)*(char *)(unaff_EBP + -0x13) &&
             ((int)*(char *)(unaff_EBP + -0x13) <= *(int *)(iVar9 + 0x7c))))))) {
          *(undefined4 *)(unaff_EBP + -0x40) = 0;
          *(undefined1 *)(unaff_EBP + -0x3a) = 0;
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_004619d2(unaff_EBP + -0x38);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          puVar11 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x20);
          *(undefined4 *)(unaff_EBP + -0x40) = *puVar11;
          FUN_00461b74(puVar11 + 1);
          while( true ) {
            iVar9 = FUN_004619d2(unaff_EBP + -0x50);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            cVar5 = FUN_0046198c(iVar9 + 4);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            cVar5 = '\x01' - (cVar5 != '\0');
            *(char *)(unaff_EBP + -0x15) = cVar5;
            iVar9 = DAT_006e54d8;
            if (cVar5 == '\0') break;
            FUN_00461941(unaff_EBP + -0x1c);
            if ((((*(int *)(DAT_006e54d8 + 0x70) <= (int)*(char *)(unaff_EBP + -0x1c)) &&
                 ((int)*(char *)(unaff_EBP + -0x1c) <= *(int *)(DAT_006e54d8 + 0x74))) &&
                (iVar9 = (int)*(char *)(unaff_EBP + -0x1b), *(int *)(DAT_006e54d8 + 0x78) <= iVar9))
               && (iVar9 <= *(int *)(DAT_006e54d8 + 0x7c))) {
              puVar15 = (uint *)(extraout_ECX + iVar9 * 2 + 0x82);
              uVar19 = __allshl();
              *puVar15 = *puVar15 | (uint)uVar19;
              puVar15[1] = puVar15[1] | (uint)((ulonglong)uVar19 >> 0x20);
            }
            FUN_00461961();
          }
          *(undefined1 *)(unaff_EBP + -4) = 6;
        }
        if (((DAT_006e54ac != (int *)0x0) &&
            (*(int *)(iVar9 + 0x70) <= (int)*(char *)(unaff_EBP + -0x14))) &&
           (((int)*(char *)(unaff_EBP + -0x14) <= *(int *)(iVar9 + 0x74) &&
            ((*(int *)(iVar9 + 0x78) <= (int)*(char *)(unaff_EBP + -0x13) &&
             ((int)*(char *)(unaff_EBP + -0x13) <= *(int *)(iVar9 + 0x7c))))))) {
          (**(code **)(*DAT_006e54ac + 0x40))(unaff_EBP + -0x14,extraout_ECX + 0x82);
          iVar9 = DAT_006e54d8;
        }
      }
    }
    puVar15 = (uint *)(unaff_EBP + -0x250);
    iVar17 = 0x40;
    puVar10 = (uint *)(extraout_ECX + 0x82);
    do {
      *puVar15 = *puVar15 ^ *puVar10;
      puVar15[1] = puVar15[1] ^ puVar10[1];
      puVar15 = puVar15 + 2;
      iVar17 = iVar17 + -1;
      puVar10 = puVar10 + 2;
    } while (iVar17 != 0);
    cVar5 = *(char *)((int)extraout_ECX + 0x4e);
    iVar17 = *(int *)(DAT_006e54dc + 0x10);
    *(int *)(unaff_EBP + -0x3c) = iVar17;
    if (cVar5 == '\0') {
      uVar13 = *(undefined4 *)(iVar9 + 0x78);
      uVar3 = *(undefined4 *)(iVar9 + 0x70);
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
      if (0 < iVar17) {
        puVar15 = (uint *)(unaff_EBP + -0x250 + (char)uVar13 * 8);
        do {
          *(undefined4 *)(unaff_EBP + -0x24) = 0;
          do {
            uVar19 = __allshl();
            if (((uint)uVar19 & *puVar15) != 0 ||
                ((uint)((ulonglong)uVar19 >> 0x20) & puVar15[1]) != 0) {
              *(undefined1 *)((int)extraout_ECX + 0x4e) = 1;
              break;
            }
            *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
          } while (*(int *)(unaff_EBP + -0x24) < *(int *)(unaff_EBP + -0x3c));
          if (*(char *)((int)extraout_ECX + 0x4e) != '\0') break;
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
          puVar15 = puVar15 + 2;
        } while (*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x3c));
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined1 *)(extraout_ECX + 0x7e) = *(undefined1 *)(unaff_EBP + 8);
    FUN_00635f6d(unaff_EBP + -0x250,8,0x40,FUN_00416e17);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

