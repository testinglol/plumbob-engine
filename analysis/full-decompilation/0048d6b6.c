
int FUN_0048d6b6(void)

{
  bool bVar1;
  char cVar2;
  SHORT SVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  char *pcVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int extraout_ECX;
  uint uVar12;
  int iVar13;
  int unaff_EBP;
  size_t sVar14;
  float10 fVar15;
  
  FUN_00634c24();
  uVar4 = FUN_0051cebb();
  *(undefined4 *)(extraout_ECX + 0xdc) = uVar4;
  uVar4 = FUN_0051cecc();
  iVar13 = *(int *)(extraout_ECX + 0x30);
  *(undefined4 *)(extraout_ECX + 0xe0) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(extraout_ECX + 0xec) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(extraout_ECX + 0xf0) = *(undefined4 *)(unaff_EBP + 0x14);
  if (iVar13 != *(int *)(extraout_ECX + 0x34)) {
    do {
      if (*(int *)(iVar13 + 8) != 0) {
        *(int *)(unaff_EBP + -0x2c) = (int)*(short *)(iVar13 + 0x14);
        puVar5 = (undefined4 *)FUN_0041f169();
        uVar4 = *puVar5;
        *(undefined4 *)(unaff_EBP + -0x34) = uVar4;
        iVar6 = FUN_00636450(uVar4,0x2f);
        *(int *)(unaff_EBP + -0x20) = iVar6;
        if (iVar6 == 0) {
          uVar4 = *(undefined4 *)(unaff_EBP + -0x34);
          *(int *)(iVar13 + 0x34) =
               (*(int *)(extraout_ECX + 0x50) - *(int *)(extraout_ECX + 0x4c)) / 0x28;
          *(undefined4 *)(iVar13 + 0x38) = 0xffffffff;
          FUN_005b870f(uVar4);
          *(undefined1 *)(unaff_EBP + -0x4c) = 0;
          *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(unaff_EBP + -0x10);
          *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x10);
          *(int *)(unaff_EBP + -0x3c) = iVar13;
          *(undefined4 *)(unaff_EBP + -0x48) = 0;
          *(undefined4 *)(unaff_EBP + -0x44) = 0;
          *(undefined4 *)(unaff_EBP + -0x40) = 0;
          *(undefined4 *)(unaff_EBP + -4) = 4;
          FUN_0048e3ce(unaff_EBP + -0x60);
          *(undefined4 *)(unaff_EBP + -4) = 5;
          FUN_0048e388();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        else {
          sVar14 = iVar6 - *(int *)(unaff_EBP + -0x34);
          *(size_t *)(unaff_EBP + -0x24) = sVar14;
          pcVar7 = operator_new(sVar14 + 4);
          *(char **)(unaff_EBP + -0x1c) = pcVar7;
          _strncpy(pcVar7,*(char **)(unaff_EBP + -0x34),sVar14);
          *(undefined4 *)(unaff_EBP + -0x30) = 0;
          *(undefined1 *)(*(int *)(unaff_EBP + -0x1c) + sVar14) = 0;
          piVar11 = (int *)(extraout_ECX + 0x4c);
          if ((*(int *)(extraout_ECX + 0x50) - *(int *)(extraout_ECX + 0x4c)) / 0x28 != 0) {
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
            do {
              if ((*(char *)(*(int *)(unaff_EBP + -0x18) + 0x14 + *piVar11) != '\0') &&
                 (iVar6 = _strcmp(*(char **)(*(int *)(unaff_EBP + -0x18) + *piVar11),
                                  *(char **)(unaff_EBP + -0x1c)), iVar6 == 0)) {
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x30);
                if (*(int *)(unaff_EBP + -0x30) != -1) goto LAB_0048d844;
                break;
              }
              iVar6 = *(int *)(extraout_ECX + 0x50);
              iVar9 = *piVar11;
              *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
              *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 0x28;
            } while (*(uint *)(unaff_EBP + -0x30) < (uint)((iVar6 - iVar9) / 0x28));
          }
          pcVar7 = operator_new(*(int *)(unaff_EBP + -0x24) + 4);
          *(char **)(unaff_EBP + -0x18) = pcVar7;
          _strncpy(pcVar7,*(char **)(unaff_EBP + -0x34),*(size_t *)(unaff_EBP + -0x24));
          *(undefined1 *)(*(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + -0x24)) = 0;
          iVar6 = (*(int *)(extraout_ECX + 0x50) - *piVar11) / 0x28;
          *(int *)(unaff_EBP + -0x1c) = iVar6;
          uVar4 = FUN_0048ddc5(*(undefined4 *)(unaff_EBP + -0x18),iVar6,
                               *(undefined4 *)(unaff_EBP + -0x10));
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_0048e3ce(uVar4);
          *(undefined4 *)(unaff_EBP + -4) = 1;
          FUN_0048e388();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x18));
LAB_0048d844:
          pcVar7 = (char *)(*(int *)(unaff_EBP + -0x20) + 1);
          *(char **)(unaff_EBP + -0x20) = pcVar7;
          sVar14 = _strlen(pcVar7);
          *(size_t *)(unaff_EBP + -0x18) = sVar14;
          pvVar8 = operator_new(sVar14 + 1);
          *(void **)(unaff_EBP + -0x24) = pvVar8;
          FUN_006358b0(pvVar8,*(undefined4 *)(unaff_EBP + -0x20));
          *(undefined1 *)(*(int *)(unaff_EBP + -0x24) + *(int *)(unaff_EBP + -0x18)) = 0;
          iVar6 = *(int *)(unaff_EBP + -0x1c);
          *(int *)(iVar13 + 0x34) = iVar6;
          iVar9 = *piVar11;
          iVar6 = iVar6 * 0x28;
          *(int *)(unaff_EBP + -0x20) = iVar6;
          piVar11 = (int *)(iVar6 + 0x18 + iVar9);
          uVar4 = *(undefined4 *)(unaff_EBP + -0x24);
          *(int *)(iVar13 + 0x38) = (piVar11[1] - *piVar11) / 0x28;
          FUN_005b870f(uVar4);
          *(undefined1 *)(unaff_EBP + -0x74) = 0;
          *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x2c);
          *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x10);
          *(undefined4 *)(unaff_EBP + -0x70) = 0;
          *(undefined4 *)(unaff_EBP + -0x6c) = 0;
          *(undefined4 *)(unaff_EBP + -0x68) = 0;
          *(int *)(unaff_EBP + -100) = iVar13;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          FUN_0048e3ce(unaff_EBP + -0x88);
          *(undefined4 *)(unaff_EBP + -4) = 3;
          FUN_0048e388();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x24));
        }
      }
      iVar13 = iVar13 + 0x44;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (iVar13 != *(int *)(extraout_ECX + 0x34));
  }
  *(undefined4 *)(extraout_ECX + 0x5c) = 0;
  *(undefined4 *)(extraout_ECX + 0x60) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 100) = 0;
  if ((*(int **)(DAT_006f2a08 + 0x84) == (int *)0x0) ||
     (cVar2 = (**(code **)(**(int **)(DAT_006f2a08 + 0x84) + 0x8c))(1), cVar2 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  *(undefined1 *)(extraout_ECX + 0xd8) = 0;
  *(undefined1 *)(extraout_ECX + 0xd9) = 0;
  *(undefined1 *)(extraout_ECX + 0xda) = 0;
  if (bVar1) {
    FUN_005ddfdc(1);
    *(undefined1 *)(extraout_ECX + 0xd9) = 1;
    FUN_005ddfdc(1);
    *(undefined1 *)(extraout_ECX + 0xda) = 1;
  }
  DAT_006e579c = 0;
  iVar6 = *(int *)(extraout_ECX + 0x4c);
  iVar13 = *(int *)(extraout_ECX + 0x50);
  *(undefined1 *)(unaff_EBP + -0x11) = 1;
  if ((iVar6 != iVar13) && (*(int *)(iVar6 + 0x24) != 0)) {
    DAT_006e579c = *(undefined4 *)(*(int *)(iVar6 + 0x24) + 8);
  }
LAB_0048da1a:
  do {
    if (*(int *)(extraout_ECX + 0x5c) == 0) {
      piVar11 = *(int **)(extraout_ECX + 0xdc);
    }
    else {
      piVar11 = *(int **)(extraout_ECX + 0xe0);
    }
    *(int **)(extraout_ECX + 0xe4) = piVar11;
    if (*(int *)(extraout_ECX + 0x5c) == 0) {
      iVar13 = extraout_ECX + 0x4c;
    }
    else {
      iVar13 = *(int *)(extraout_ECX + 0x4c) + 0x18 + *(int *)(extraout_ECX + 0x60) * 0x28;
    }
    if (iVar13 != *(int *)(extraout_ECX + 0x58)) {
      *(undefined4 *)(extraout_ECX + 100) = 0;
    }
    *(int *)(extraout_ECX + 0x58) = iVar13;
    (**(code **)(*piVar11 + 0x1a4))();
    piVar11 = *(int **)(extraout_ECX + 0x58);
    uVar12 = *(uint *)(extraout_ECX + 100);
    iVar13 = piVar11[1];
    iVar6 = *piVar11;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if (uVar12 < (uint)((iVar13 - iVar6) / 0x28)) {
      do {
        if (0xb < *(int *)(unaff_EBP + -0x10)) break;
        uVar4 = FUN_005d4956(*(undefined4 *)
                              (*piVar11 + (uVar12 + *(int *)(unaff_EBP + -0x10)) * 0x28));
        piVar11 = *(int **)(extraout_ECX + 0xe4);
        *(undefined4 *)(unaff_EBP + -4) = 6;
        (**(code **)(*piVar11 + 0x1a8))(uVar4,0);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        piVar11 = *(int **)(extraout_ECX + 0x58);
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        uVar12 = *(uint *)(extraout_ECX + 100);
      } while (*(int *)(unaff_EBP + -0x10) + uVar12 < (uint)((piVar11[1] - *piVar11) / 0x28));
    }
    SVar3 = GetKeyState(1);
    iVar13 = *(int *)(extraout_ECX + 0x5c);
    *(uint *)(unaff_EBP + -0x1c) = (uint)(-1 < SVar3);
    *(uint *)(unaff_EBP + -0x20) = (iVar13 != 0) - 1;
    if (iVar13 == 0) {
      *(undefined1 *)(extraout_ECX + 0xd8) = 1;
    }
    else {
      piVar11 = *(int **)(extraout_ECX + 0xdc);
      *(int **)(unaff_EBP + -0x2c) = piVar11;
      iVar6 = (**(code **)(*piVar11 + 0x210))();
      iVar9 = (**(code **)(*piVar11 + 0x1f8))();
      piVar11 = *(int **)(extraout_ECX + 0xdc);
      iVar13 = *piVar11;
      *(int *)(unaff_EBP + -0x2c) = (iVar6 + iVar9) - *(int *)(unaff_EBP + 0x10);
      iVar9 = (**(code **)(iVar13 + 0x214))();
      iVar13 = *(int *)(unaff_EBP + 0x14);
      iVar10 = (**(code **)(*piVar11 + 0x1fc))();
      iVar6 = *(int *)(unaff_EBP + -0x2c);
      iVar10 = (iVar9 - iVar13) + iVar10;
      if ((iVar6 != 0) || (iVar10 != 0)) {
        GetCursorPos((LPPOINT)(unaff_EBP + -0x28));
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar10;
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + iVar6;
        SetCursorPos(*(int *)(unaff_EBP + -0x28),*(int *)(unaff_EBP + -0x24));
        *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + iVar6;
        *(int *)(unaff_EBP + 0x14) = *(int *)(unaff_EBP + 0x14) + iVar10;
      }
    }
    uVar4 = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined1 *)(extraout_ECX + 0x2c) = 1;
    (**(code **)(**(int **)(extraout_ECX + 0xe4) + 0x254))
              (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
               *(undefined4 *)(unaff_EBP + -0x1c),uVar4);
    if (*(char *)(unaff_EBP + -0x11) != '\0') {
      *(undefined1 *)(unaff_EBP + -0x11) = 0;
      uVar4 = (**(code **)(**(int **)(unaff_EBP + 0xc) + 0x8c))();
      FUN_00587cb4(*(undefined4 *)(extraout_ECX + 0xdc),uVar4);
    }
    iVar13 = (**(code **)(**(int **)(extraout_ECX + 0xe4) + 600))();
    (**(code **)(**(int **)(extraout_ECX + 0xe4) + 0x25c))();
    if (*(char *)(extraout_ECX + 0xd8) != '\0') {
      (**(code **)(*DAT_006fe8bc + 0x18))();
      piVar11 = (int *)FUN_004b46a0();
      (**(code **)(*piVar11 + 0x20))(*(undefined4 *)(extraout_ECX + 0xdc));
    }
    *(undefined1 *)(extraout_ECX + 0x2c) = 0;
    if (iVar13 != -3) {
      if (iVar13 == -2) {
        if (0 < *(int *)(extraout_ECX + 0x5c)) {
          *(undefined4 *)(extraout_ECX + 0x5c) = 0;
          FUN_00587ce0();
        }
        FUN_0048de2c(0xfffffffe);
        iVar13 = -2;
        goto LAB_0048ddb4;
      }
      if (iVar13 == -1) {
        if (*(int *)(extraout_ECX + 0x5c) < 1) {
LAB_0048dd74:
          FUN_0048de2c(0);
          iVar13 = 0;
LAB_0048ddb4:
          ExceptionList = *(void **)(unaff_EBP + -0xc);
          return iVar13;
        }
        piVar11 = *(int **)(extraout_ECX + 0xe0);
        *(int **)(unaff_EBP + 0x10) = piVar11;
        fVar15 = (float10)(**(code **)(*piVar11 + 0x1c8))();
        iVar13 = *piVar11;
        *(float *)(unaff_EBP + 0x14) = (float)fVar15;
        uVar4 = (**(code **)(iVar13 + 0x1d0))();
        *(undefined4 *)(unaff_EBP + 0x10) = uVar4;
        if ((float)*(int *)(unaff_EBP + 0x10) < *(float *)(unaff_EBP + 0x14)) goto LAB_0048dd74;
        *(undefined4 *)(extraout_ECX + 0x5c) = 0;
        *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(extraout_ECX + 0xec);
        *(undefined4 *)(unaff_EBP + 0x14) = *(undefined4 *)(extraout_ECX + 0xf0);
        FUN_00587ce0();
      }
      else {
        uVar12 = iVar13 + *(int *)(extraout_ECX + 100);
        if (((int)uVar12 < 0) ||
           (piVar11 = *(int **)(extraout_ECX + 0x58),
           (uint)((piVar11[1] - *piVar11) / 0x28) <= uVar12)) {
          FUN_0048de2c(0xffffffff);
          iVar13 = -1;
          goto LAB_0048ddb4;
        }
        if (*(char *)(*piVar11 + 0x14 + uVar12 * 0x28) == '\0') {
          if (0 < *(int *)(extraout_ECX + 0x5c)) {
            *(undefined4 *)(extraout_ECX + 0x5c) = 0;
            FUN_00587ce0();
          }
          iVar13 = *(int *)(**(int **)(extraout_ECX + 0x58) + 0x10 + uVar12 * 0x28) + 1;
          FUN_0048de2c(iVar13);
          goto LAB_0048ddb4;
        }
        *(uint *)(extraout_ECX + 0x60) = uVar12;
        *(undefined4 *)(extraout_ECX + 0x5c) = 1;
        GetCursorPos((LPPOINT)(unaff_EBP + -0x38));
        ScreenToClient(DAT_006fe8cc,(LPPOINT)(unaff_EBP + -0x38));
        uVar4 = *(undefined4 *)(extraout_ECX + 0xe0);
        *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(unaff_EBP + -0x38);
        *(undefined4 *)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -0x34);
        FUN_00587cd1(uVar4);
        iVar6 = 0;
        iVar13 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x1bc))();
        if (0 < iVar13) {
          do {
            (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x1c4))(iVar6,0);
            iVar6 = iVar6 + 1;
            iVar13 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x1bc))();
          } while (iVar6 < iVar13);
        }
        (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x168))();
      }
      goto LAB_0048da1a;
    }
    uVar12 = *(int *)(extraout_ECX + 100) + 0xc;
    *(uint *)(extraout_ECX + 100) =
         ~-(uint)((uint)(((*(int **)(extraout_ECX + 0x58))[1] - **(int **)(extraout_ECX + 0x58)) /
                        0x28) < uVar12) & uVar12;
  } while( true );
}

