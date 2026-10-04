
undefined4 FUN_00424850(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  void *pvVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  char *pcVar12;
  undefined1 *puVar13;
  int extraout_ECX;
  uint uVar14;
  int unaff_EBP;
  int *piVar15;
  undefined4 uVar16;
  
  FUN_00634c24();
  if (DAT_006e4a5c == '\0') {
    FUN_00424260();
    DAT_006e4a5c = '\x01';
  }
  piVar10 = *(int **)(extraout_ECX + 0x148);
  *(int *)(unaff_EBP + -0x40) = DAT_006e486c[10];
  if (piVar10 != *(int **)(extraout_ECX + 0x14c)) {
    do {
      iVar6 = *piVar10;
      if (iVar6 != 0) {
        FUN_00423852();
        FUN_006321f0(iVar6);
      }
      piVar10 = piVar10 + 1;
    } while (piVar10 != *(int **)(extraout_ECX + 0x14c));
  }
  FUN_0042ed71(*(undefined4 *)(extraout_ECX + 0x148),*(undefined4 *)(extraout_ECX + 0x14c));
  for (piVar10 = *(int **)(extraout_ECX + 0x154); piVar10 != *(int **)(extraout_ECX + 0x158);
      piVar10 = piVar10 + 1) {
    iVar6 = *piVar10;
    if (iVar6 != 0) {
      FUN_00410173();
      FUN_006321f0(iVar6);
    }
  }
  FUN_0042ed71(*(undefined4 *)(extraout_ECX + 0x154),*(undefined4 *)(extraout_ECX + 0x158));
  piVar10 = (int *)(extraout_ECX + 0x194);
  uVar14 = 0;
  if (*(int *)(extraout_ECX + 0x198) - *piVar10 >> 2 != 0) {
    do {
      iVar6 = *(int *)(*piVar10 + uVar14 * 4);
      *(int *)(unaff_EBP + -0x20) = iVar6;
      if (iVar6 != 0) {
        FUN_0041f37d();
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x20));
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < (uint)(*(int *)(extraout_ECX + 0x198) - *piVar10 >> 2));
  }
  FUN_0042ed71(*piVar10,*(undefined4 *)(extraout_ECX + 0x198));
  FUN_00406466(0,DAT_00666580);
  *(undefined1 *)(extraout_ECX + 0x184) = 0;
  *(undefined4 *)(extraout_ECX + 0x180) = *(undefined4 *)(extraout_ECX + 0x188);
  FUN_0042a53a();
  FUN_005d4956(&DAT_006c0d8c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4956(s_UserData_006c25ec);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  cVar2 = FUN_004fc152(s_SIMS_CURRENT_NEIGHBORHOOD_NUM_006c25cc,unaff_EBP + -0x60);
  if (cVar2 != '\0') {
    FUN_004fc152(s_SIMS_CURRENT_NEIGHBORHOOD_PATH_006c25ac,unaff_EBP + -0x6c);
  }
  uVar5 = FUN_004096c2();
  uVar3 = FUN_00635f62(uVar5);
  *(undefined1 *)(unaff_EBP + -0xd) = uVar3;
  FUN_0042fb39(unaff_EBP + -0x34,unaff_EBP + -0xd);
  iVar6 = *(int *)(unaff_EBP + -0x34);
  *(int *)(extraout_ECX + 0x180) = iVar6;
  if (iVar6 == *(int *)(extraout_ECX + 0x188)) {
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
    FUN_0042fb39(unaff_EBP + -0x34,unaff_EBP + -0xd);
    *(undefined4 *)(extraout_ECX + 0x180) = *(undefined4 *)(unaff_EBP + -0x34);
  }
  FUN_0042a3f4();
  FUN_0046f5cd();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  iVar6 = FUN_00465a37(extraout_ECX,1);
  *(int *)(unaff_EBP + -0x2c) = iVar6;
  if (iVar6 == 0) {
    FUN_00430291(extraout_ECX,0x4e474248);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    iVar6 = FUN_00464f5b(unaff_EBP + -0x54,unaff_EBP + -0x380,1,0);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00465055();
    *(int *)(unaff_EBP + -0x2c) = iVar6;
    FUN_0046f824(unaff_EBP + -0x594,0,0x104);
    *(undefined ***)(unaff_EBP + -0x5a0) = &PTR_FUN_006664e8;
    FUN_00412122(extraout_ECX,unaff_EBP + -0x5a0);
    FUN_0046f847(s_Characters__006c1d48,0xffffffff);
    FUN_0043c30d(unaff_EBP + -0x5a0);
    if (iVar6 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0x4e425253;
      *(int **)(unaff_EBP + -0x18) = (int *)(extraout_ECX + 0x148);
      uVar5 = FUN_00430654(unaff_EBP + -0x18,unaff_EBP + -0x380,0x4e425253,1,0);
      piVar15 = *(int **)(extraout_ECX + 0x148);
      piVar10 = *(int **)(extraout_ECX + 0x14c);
      *(undefined4 *)(unaff_EBP + -0x2c) = uVar5;
      if (piVar15 != piVar10) {
        do {
          iVar6 = *piVar15;
          if ((iVar6 != 0) && (*(int *)(iVar6 + 8) == 0)) {
            pcVar12 = *(char **)(iVar6 + 0x2c);
            *(char **)(unaff_EBP + -0x20) = pcVar12;
            sVar7 = _strlen(pcVar12);
            FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x20),sVar7 + *(int *)(unaff_EBP + -0x20));
            sVar7 = _strlen(&DAT_006c25a8);
            FUN_00412d8a(&DAT_006c25a8,&DAT_006c25a8 + sVar7);
            FUN_004259ec(*piVar15);
          }
          piVar15 = piVar15 + 1;
        } while (piVar15 != *(int **)(extraout_ECX + 0x14c));
      }
      FUN_0043e1bc(unaff_EBP + -0x380);
    }
    if (*(int *)(unaff_EBP + -0x2c) == -0x62) {
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    }
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(*DAT_006e486c + 0x14);
    sVar4 = (**(code **)(*(int *)(unaff_EBP + -0x380) + 0x34))(0x46414d49);
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(int *)(unaff_EBP + -0x14) = (int)sVar4;
    if (0 < sVar4) {
      do {
        *(undefined4 *)(unaff_EBP + -0x20) = 0xffffffff;
        iVar6 = (**(code **)(*(int *)(unaff_EBP + -0x380) + 0x40))
                          (0x46414d49,*(int *)(unaff_EBP + -0x30) + 1,0);
        if (iVar6 != 0) {
          (**(code **)(*(int *)(unaff_EBP + -0x380) + 0x50))(iVar6,unaff_EBP + -0x20);
          FUN_00465a06(iVar6);
        }
        if (*(short *)(unaff_EBP + -0x20) != -1) {
          pvVar8 = operator_new(0x15c);
          *(void **)(unaff_EBP + -0x4c) = pvVar8;
          *(undefined1 *)(unaff_EBP + -4) = 4;
          if (pvVar8 == (void *)0x0) {
            uVar5 = 0;
          }
          else {
            uVar5 = FUN_004100cf(*(undefined4 *)(unaff_EBP + -0x34),0xffffffff);
          }
          *(undefined1 *)(unaff_EBP + -4) = 2;
          *(undefined4 *)(unaff_EBP + -0x3c) = uVar5;
          FUN_00410398(unaff_EBP + -0x380,(int)*(short *)(unaff_EBP + -0x20));
          FUN_0042eb8e(unaff_EBP + -0x3c);
          do {
            uVar5 = FUN_004102e1();
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
            *(undefined4 *)(unaff_EBP + -0x4c) = uVar5;
            while( true ) {
              if (*(int *)(unaff_EBP + -0x4c) <= *(int *)(unaff_EBP + -0x1c)) goto LAB_00424ca0;
              puVar9 = (undefined4 *)FUN_004102ab(*(undefined4 *)(unaff_EBP + -0x1c));
              if ((puVar9 != (undefined4 *)0x0) && (iVar6 = FUN_00425769(*puVar9), iVar6 == 0))
              break;
              *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
            }
            FUN_00410917(*puVar9);
          } while( true );
        }
LAB_00424ca0:
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
      } while (*(int *)(unaff_EBP + -0x30) < *(int *)(unaff_EBP + -0x14));
    }
    for (piVar10 = *(int **)(extraout_ECX + 0x154); piVar10 != *(int **)(extraout_ECX + 0x158);
        piVar10 = piVar10 + 1) {
      if (*(int *)(*piVar10 + 0x10c) == 0) {
        iVar6 = *piVar10;
        goto LAB_00424cd5;
      }
    }
    iVar6 = 0;
LAB_00424cd5:
    if (iVar6 == 0) {
      pvVar8 = operator_new(0x15c);
      *(void **)(unaff_EBP + -0x14) = pvVar8;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      if (pvVar8 == (void *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_004100cf(*(undefined4 *)(unaff_EBP + -0x34),0);
      }
      *(undefined4 *)(unaff_EBP + -0x20) = uVar5;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_0046f824(unaff_EBP + -0x6a0,0,0x100);
      *(undefined ***)(unaff_EBP + -0x6ac) = &PTR_FUN_00666524;
      FUN_0046f847(s_Default_006c25a0,0xffffffff);
      FUN_004108c4(unaff_EBP + -0x6ac);
      FUN_0042eb8e(unaff_EBP + -0x20);
    }
    if (1 < (uint)(*(int *)(extraout_ECX + 0x158) - *(int *)(extraout_ECX + 0x154) >> 2)) {
      FUN_0042feee(*(int *)(extraout_ECX + 0x154),*(undefined4 *)(extraout_ECX + 0x158),
                   &LAB_00425253);
    }
  }
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  uVar5 = 0;
  while (iVar6 = FUN_0043ad1f(uVar5), iVar6 != 0) {
    iVar11 = *(int *)(iVar6 + 0x60);
    if (*(short *)(iVar11 + 0x12) == 2) {
      piVar10 = *(int **)(extraout_ECX + 0x148);
      iVar11 = 0;
      if (piVar10 == *(int **)(extraout_ECX + 0x14c)) goto LAB_00424ebc;
      do {
        iVar1 = *piVar10;
        if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == iVar6)) && (iVar11 == 0)) {
          iVar11 = iVar1;
        }
        piVar10 = piVar10 + 1;
      } while (piVar10 != *(int **)(extraout_ECX + 0x14c));
LAB_00424eb8:
      if (iVar11 == 0) goto LAB_00424ebc;
    }
    else {
      if (*(short *)(iVar11 + 0x12) == 0x200) {
        piVar10 = *(int **)(extraout_ECX + 0x148);
        iVar11 = 0;
        if (piVar10 != *(int **)(extraout_ECX + 0x14c)) {
          do {
            iVar1 = *piVar10;
            if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == iVar6)) && (iVar11 == 0)) {
              iVar11 = iVar1;
            }
            piVar10 = piVar10 + 1;
          } while (piVar10 != *(int **)(extraout_ECX + 0x14c));
          goto LAB_00424eb8;
        }
      }
      else if (*(short *)(iVar11 + 0x12) == 0x400) {
        piVar10 = *(int **)(extraout_ECX + 0x148);
        iVar11 = 0;
        if (piVar10 != *(int **)(extraout_ECX + 0x14c)) {
          do {
            iVar1 = *piVar10;
            if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == iVar6)) && (iVar11 == 0)) {
              iVar11 = iVar1;
            }
            piVar10 = piVar10 + 1;
          } while (piVar10 != *(int **)(extraout_ECX + 0x14c));
          goto LAB_00424eb8;
        }
      }
      else if (*(short *)(iVar11 + 0x12) == 0x800) {
        piVar10 = *(int **)(extraout_ECX + 0x148);
        iVar11 = 0;
        if (piVar10 != *(int **)(extraout_ECX + 0x14c)) {
          do {
            iVar1 = *piVar10;
            if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == iVar6)) && (iVar11 == 0)) {
              iVar11 = iVar1;
            }
            piVar10 = piVar10 + 1;
          } while (piVar10 != *(int **)(extraout_ECX + 0x14c));
          goto LAB_00424eb8;
        }
      }
      else {
        if (*(short *)(iVar11 + 0x12) != 0x1000) goto LAB_00424ec6;
        piVar10 = *(int **)(extraout_ECX + 0x148);
        iVar11 = 0;
        if (piVar10 != *(int **)(extraout_ECX + 0x14c)) {
          do {
            iVar1 = *piVar10;
            if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == iVar6)) && (iVar11 == 0)) {
              iVar11 = iVar1;
            }
            piVar10 = piVar10 + 1;
          } while (piVar10 != *(int **)(extraout_ECX + 0x14c));
          goto LAB_00424eb8;
        }
      }
LAB_00424ebc:
      FUN_004257ef(iVar6,0xffffffff);
    }
LAB_00424ec6:
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
    uVar5 = *(undefined4 *)(unaff_EBP + -0x20);
  }
  FUN_0042528e();
  *(undefined4 *)(extraout_ECX + 0x160) = 0;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x13c) = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_0046f824(unaff_EBP + -0x484,0,0x104);
  piVar10 = DAT_006e486c;
  *(undefined ***)(unaff_EBP + -0x490) = &PTR_FUN_006664e8;
  FUN_00412122(piVar10[9],unaff_EBP + -0x490);
  uVar16 = 0xffffffff;
  uVar5 = FUN_0041532c(0xb,0xffffffff);
  FUN_0046f847(uVar5,uVar16);
  FUN_0046f5cd();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  iVar6 = FUN_0046f71c(unaff_EBP + -0x490,1);
  if ((iVar6 != 0) || (iVar6 = FUN_004703f1(unaff_EBP + -0x8f0,1), iVar6 != 0)) {
    uVar5 = 0;
    goto LAB_004251fd;
  }
  FUN_00406746();
  FUN_0042ede2(*(undefined4 *)(extraout_ECX + 0x174),*(undefined4 *)(extraout_ECX + 0x178));
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  FUN_00471655(unaff_EBP + -0x48);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  uVar5 = FUN_0047166d(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  cVar2 = FUN_0046fc3a(uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_0042004f();
  if (cVar2 == '\0') {
LAB_00425122:
    if ((*(byte *)((int)DAT_006e486c + 0x66) & 0x80) != 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0x5a;
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      FUN_0042ebb5(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x5b;
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      FUN_0042ebb5(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x5c;
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      FUN_0042ebb5(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x5d;
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
      FUN_0042ebb5(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x5e;
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
      FUN_0042ebb5(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x5f;
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
      FUN_0042ebb5(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x60;
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
      FUN_0042ebb5(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x61;
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
      FUN_0042ebb5(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -0x18) = 0x62;
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
      FUN_0042ebb5(unaff_EBP + -0x18);
    }
  }
  else {
    do {
      sVar7 = 99;
      pcVar12 = (char *)FUN_0046fc7a();
      _strncpy((char *)(unaff_EBP + -0xd0),pcVar12,sVar7);
      puVar13 = (undefined1 *)FUN_00636450(unaff_EBP + -0xd0,0x2c);
      *(undefined1 **)(unaff_EBP + -0x1c) = puVar13;
      if (puVar13 != (undefined1 *)0x0) {
        *puVar13 = 0;
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        FUN_0064a3f6(*(undefined4 *)(unaff_EBP + -0x1c));
        iVar6 = FUN_006363c0(*(undefined4 *)(unaff_EBP + -0x1c),s_residential_006c2594);
        if (iVar6 == 0) {
          iVar6 = FUN_006363c0(*(undefined4 *)(unaff_EBP + -0x1c),s_community_006c2588);
          if (iVar6 == 0) {
            uVar5 = FUN_00635f62(unaff_EBP + -0xd0);
            *(undefined4 *)(unaff_EBP + -0x24) = uVar5;
            *(undefined4 *)(unaff_EBP + -0x20) = 1;
            iVar6 = unaff_EBP + -0x24;
          }
          else {
            uVar5 = FUN_00635f62(unaff_EBP + -0xd0);
            *(undefined4 *)(unaff_EBP + -0x38) = uVar5;
            *(undefined4 *)(unaff_EBP + -0x34) = 2;
            iVar6 = unaff_EBP + -0x38;
          }
        }
        else {
          uVar5 = FUN_00635f62(unaff_EBP + -0xd0);
          *(undefined4 *)(unaff_EBP + -0x50) = uVar5;
          *(undefined4 *)(unaff_EBP + -0x4c) = 1;
          iVar6 = unaff_EBP + -0x50;
        }
        FUN_0042ebb5(iVar6);
        iVar6 = FUN_00635f62(unaff_EBP + -0xd0);
        if ((0x59 < iVar6) && (iVar6 = FUN_00635f62(unaff_EBP + -0xd0), iVar6 < 0x5d)) {
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
        }
      }
      FUN_005c11ce();
      uVar5 = FUN_0047166d(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      uVar3 = FUN_0046fc3a(uVar5);
      *(undefined1 *)(unaff_EBP + -0x25) = uVar3;
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_0042004f();
    } while (*(char *)(unaff_EBP + -0x25) != '\0');
    if (*(char *)(unaff_EBP + -0xd) == '\0') goto LAB_00425122;
  }
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_0042004f();
  uVar5 = *(undefined4 *)(unaff_EBP + -0x2c);
LAB_004251fd:
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_0046b2e6();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046b2e6();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

