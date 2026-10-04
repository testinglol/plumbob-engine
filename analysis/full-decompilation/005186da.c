
undefined1 FUN_005186da(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  void *pvVar7;
  int *piVar8;
  undefined4 *puVar9;
  size_t sVar10;
  int *extraout_ECX;
  int iVar11;
  int *piVar12;
  int iVar13;
  int unaff_EBP;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 != '\0') {
    uVar2 = FUN_005dbf32();
    goto LAB_0051a620;
  }
  (**(code **)(*extraout_ECX + 0x90))(0x10,0);
  cVar1 = FUN_005dbf32();
  if (cVar1 != '\0') {
    FUN_005a5631(0x132f,extraout_ECX + 0xbb,4);
    piVar4 = extraout_ECX + 0x36;
    *piVar4 = 0;
    FUN_005a5631(800,piVar4,4);
    *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)*piVar4;
    uVar3 = FUN_005dfe3b(0xff,0,0xff);
    (**(code **)(*(int *)(unaff_EBP + -0x68) + 0x68))(uVar3);
    FUN_005e357a();
    piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    uVar5 = (**(code **)(*piVar4 + 0x38))(0,0x28,0x8c);
    piVar4 = DAT_006fe8bc;
    *(uint *)(unaff_EBP + -0x1c) = uVar5 & 0xffff;
    piVar4 = (int *)(**(code **)(*piVar4 + 0x1c))();
    uVar5 = (**(code **)(*piVar4 + 0x38))(0xff,0xff,0xff);
    piVar4 = DAT_006fe8bc;
    *(uint *)(unaff_EBP + -0x80) = uVar5 & 0xffff;
    piVar4 = (int *)(**(code **)(*piVar4 + 0x1c))();
    uVar5 = (**(code **)(*piVar4 + 0x38))(0xa5,0xc3,0xd6);
    piVar4 = DAT_006fe8bc;
    *(uint *)(unaff_EBP + -0x38) = uVar5 & 0xffff;
    piVar4 = (int *)(**(code **)(*piVar4 + 0x1c))();
    uVar5 = (**(code **)(*piVar4 + 0x38))(0,0xff,0xff);
    *(uint *)(unaff_EBP + -0x68) = uVar5 & 0xffff;
    piVar4 = (int *)FUN_005e7743();
    uVar6 = (**(code **)(*piVar4 + 8))(1);
    *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
    pvVar7 = operator_new(0x19c);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar7 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_005ea0f3();
    }
    uVar6 = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x37] = (int)piVar4;
    (**(code **)(*piVar4 + 0x230))(uVar6);
    uVar6 = *(undefined4 *)(unaff_EBP + -0x80);
    *(undefined4 *)(extraout_ECX[0x37] + 100) = *(undefined4 *)(unaff_EBP + -0x1c);
    (**(code **)(*(int *)extraout_ECX[0x37] + 0x23c))(uVar6);
    (**(code **)(*(int *)extraout_ECX[0x37] + 0x238))(*(undefined4 *)(unaff_EBP + -0x38));
    (**(code **)(*(int *)extraout_ECX[0x37] + 0x240))(*(undefined4 *)(unaff_EBP + -0x68));
    (**(code **)(*(int *)extraout_ECX[0x37] + 0x1e0))(0x96);
    *(int **)(extraout_ECX[0x37] + 0x48) = extraout_ECX;
    (**(code **)(*(int *)extraout_ECX[0x37] + 0x1d4))(0x23);
    iVar11 = extraout_ECX[0x37];
    *(undefined4 *)(iVar11 + 0x184) = 0x3c;
    *(undefined4 *)(iVar11 + 0x188) = 0x1e;
    *(int **)(extraout_ECX[0x37] + 0x48) = extraout_ECX;
    (**(code **)(*(int *)extraout_ECX[0x37] + 0x24c))(0);
    (**(code **)(*(int *)extraout_ECX[0x37] + 0x228))(extraout_ECX[0x36],0);
    pvVar7 = operator_new(0x19c);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar7 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_005ea0f3();
    }
    uVar6 = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x38] = (int)piVar4;
    (**(code **)(*piVar4 + 0x230))(uVar6);
    uVar6 = *(undefined4 *)(unaff_EBP + -0x80);
    *(undefined4 *)(extraout_ECX[0x38] + 100) = *(undefined4 *)(unaff_EBP + -0x1c);
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x23c))(uVar6);
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x238))(*(undefined4 *)(unaff_EBP + -0x38));
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x240))(*(undefined4 *)(unaff_EBP + -0x68));
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x1e0))(0x96);
    *(int **)(extraout_ECX[0x38] + 0x48) = extraout_ECX;
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x1d4))(0x23);
    iVar11 = extraout_ECX[0x38];
    *(undefined4 *)(iVar11 + 0x184) = 0x3c;
    *(undefined4 *)(iVar11 + 0x188) = 0x1e;
    *(int **)(extraout_ECX[0x38] + 0x48) = extraout_ECX;
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x24c))(0);
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x228))(extraout_ECX[0x36],0);
    FUN_0051c61b(0xffffffff);
    *(undefined4 *)(unaff_EBP + -0x68) = 0;
    FUN_0054821c(8,unaff_EBP + -0x21);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    uVar6 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x18),8,unaff_EBP + -0x68,
                         *(undefined4 *)(unaff_EBP + -0x10));
    *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
    piVar4 = extraout_ECX + 0x3c;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_005202fc(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0048c4c9();
    iVar11 = 0;
    do {
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      if (pvVar7 == (void *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_005e372a();
      }
      iVar13 = *piVar4;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(iVar11 + iVar13) = uVar6;
      if (*(int *)(iVar11 + *piVar4) != 0) {
        *(undefined4 *)(*(int *)(iVar11 + *piVar4) + 0xf4) = 1;
        *(undefined4 *)(*(int *)(iVar11 + *piVar4) + 0xf8) = 1;
        (**(code **)(**(int **)(iVar11 + *piVar4) + 0x94))();
        *(undefined4 *)(*(int *)(iVar11 + *piVar4) + 0xa4) = 0;
        (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(iVar11 + *piVar4));
        iVar14 = DAT_006d74f0;
        iVar13 = *(int *)(iVar11 + *piVar4);
        if (DAT_006d74f0 == 0) {
          *(undefined4 *)(iVar13 + 0x154) = 0;
        }
        else {
          *(undefined4 *)(iVar13 + 0x154) = 2;
          *(int *)(iVar13 + 0x158) = iVar14;
        }
        *(undefined1 *)(iVar13 + 0x16c) = 0;
      }
      iVar11 = iVar11 + 4;
    } while (iVar11 < 0x20);
    pvVar7 = operator_new(0x84);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    iVar11 = 0;
    *(undefined4 *)(unaff_EBP + -4) = 5;
    if (pvVar7 != (void *)0x0) {
      iVar11 = FUN_00510166(0,0,0,0,0,0,0,0,0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0xbe] = iVar11;
    *(undefined4 **)(unaff_EBP + -0x20) = &DAT_006f39d8;
    *(undefined4 **)(unaff_EBP + -0x1c) = &DAT_0066c5c4;
    piVar12 = extraout_ECX + 0x57;
    do {
      FUN_005a5631(**(undefined4 **)(unaff_EBP + -0x1c),unaff_EBP + -0x7c,4);
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 6;
      if (pvVar7 == (void *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *piVar12 = (int)piVar8;
      if (piVar8 == (int *)0x0) {
        if (*(undefined4 **)(unaff_EBP + -0x7c) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(unaff_EBP + -0x7c))(1);
        }
      }
      else {
        (**(code **)(*piVar8 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x7c),4,1);
        *(undefined1 *)(*piVar12 + 0x16b) = 1;
        FUN_004cb21d(**(undefined4 **)(unaff_EBP + -0x20),(*(undefined4 **)(unaff_EBP + -0x20))[1]);
        *(undefined4 *)(*piVar12 + 0xf8) = 1;
        *(undefined4 *)(*piVar12 + 0xf4) = 1;
        (**(code **)(*extraout_ECX + 0x20))(*piVar12);
      }
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 8;
      piVar12 = piVar12 + 1;
    } while (*(int *)(unaff_EBP + -0x1c) < 0x66c5e0);
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xf0) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 7;
    cVar1 = FUN_004fff98(0x86,&DAT_006c265c,unaff_EBP + -0xf0,0);
    if (cVar1 == '\0') {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_00519896:
      FUN_00470467();
    }
    else {
      FUN_00471655(unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      piVar12 = extraout_ECX + 0x57;
      *(undefined4 *)(unaff_EBP + -0x68) = 7;
      do {
        if (*piVar12 != 0) {
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_005dd9c8(unaff_EBP + -0x40);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b8770();
        }
        piVar12 = piVar12 + 1;
        FUN_005c11ce();
        piVar8 = (int *)(unaff_EBP + -0x68);
        *piVar8 = *piVar8 + -1;
      } while (*piVar8 != 0);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_0042004f();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00470467();
      FUN_005a5631(0x119a,extraout_ECX + 0x5f,4);
      FUN_005a5631(0x119e,extraout_ECX + 0x5e,4);
      *(undefined4 *)(unaff_EBP + -0x44) = 0;
      uVar6 = DAT_006f3a14;
      *(undefined4 *)(unaff_EBP + -100) = DAT_006f3a10;
      *(undefined4 *)(unaff_EBP + -0x54) = DAT_006f3a18;
      *(undefined4 *)(unaff_EBP + -0x50) = DAT_006f3a1c;
      *(undefined4 *)(unaff_EBP + -0x60) = uVar6;
      iVar11 = *piVar4;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0x2d;
      *(undefined4 *)(unaff_EBP + -0x58) = 0x2d;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0x2d;
      *(undefined4 *)(unaff_EBP + -0x48) = 0x2d;
      iVar13 = extraout_ECX[0x3d];
      *(undefined4 *)(unaff_EBP + -4) = 10;
      FUN_004ebf01(iVar11,iVar13 - iVar11 >> 2);
      pvVar7 = operator_new(0xd4);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      if (pvVar7 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_005dbd68();
      }
      extraout_ECX[0x40] = (int)piVar4;
      iVar11 = *piVar4;
      *(undefined1 *)(unaff_EBP + -4) = 10;
      cVar1 = (**(code **)(iVar11 + 0xc))();
      if (cVar1 != '\0') {
        cVar1 = FUN_004cff80();
        if (cVar1 == '\0') {
          (**(code **)(*(int *)extraout_ECX[0x40] + 0x60))
                    (DAT_006f3ab8,DAT_006f3abc,DAT_006f3ac0,DAT_006f3ac4);
          uVar6 = DAT_006f3a80;
          uVar18 = DAT_006f3a84;
        }
        else {
          (**(code **)(*(int *)extraout_ECX[0x40] + 0x60))
                    (DAT_006f3aa8,DAT_006f3aac,DAT_006f3ab0,DAT_006f3ab4);
          uVar6 = DAT_006f3a78;
          uVar18 = DAT_006f3a7c;
        }
        FUN_004cb21d(uVar6,uVar18);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x40]);
        pvVar7 = operator_new(0xd4);
        *(void **)(unaff_EBP + -0x10) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        if (pvVar7 == (void *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)FUN_005dbd68();
        }
        extraout_ECX[0x41] = (int)piVar4;
        iVar11 = *piVar4;
        *(undefined1 *)(unaff_EBP + -4) = 10;
        cVar1 = (**(code **)(iVar11 + 0xc))();
        if (cVar1 != '\0') {
          cVar1 = FUN_004cff80();
          if (cVar1 == '\0') {
            (**(code **)(*(int *)extraout_ECX[0x41] + 0x60))
                      (DAT_006f3ab8,DAT_006f3abc,DAT_006f3ac0,DAT_006f3ac4);
            uVar6 = DAT_006f3a80;
            uVar18 = DAT_006f3a84;
          }
          else {
            (**(code **)(*(int *)extraout_ECX[0x41] + 0x60))
                      (DAT_006f3aa8,DAT_006f3aac,DAT_006f3ab0,DAT_006f3ab4);
            uVar6 = DAT_006f3a78;
            uVar18 = DAT_006f3a7c;
          }
          FUN_004cb21d(uVar6,uVar18);
          (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x41]);
          pvVar7 = operator_new(0xd4);
          *(void **)(unaff_EBP + -0x10) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          if (pvVar7 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_005dbd68();
          }
          *(undefined1 *)(unaff_EBP + -4) = 10;
          extraout_ECX[0x42] = (int)piVar4;
          if (piVar4 != (int *)0x0) {
            cVar1 = (**(code **)(*piVar4 + 0xc))();
            if (cVar1 == '\0') goto LAB_0051989b;
            cVar1 = FUN_004cff80();
            if (cVar1 == '\0') {
              (**(code **)(*(int *)extraout_ECX[0x42] + 0x60))
                        (DAT_006f3ab8,DAT_006f3abc,DAT_006f3ac0,DAT_006f3ac4);
              uVar6 = DAT_006f3a80;
              uVar18 = DAT_006f3a84;
            }
            else {
              (**(code **)(*(int *)extraout_ECX[0x42] + 0x60))
                        (DAT_006f3aa8,DAT_006f3aac,DAT_006f3ab0,DAT_006f3ab4);
              uVar6 = DAT_006f3a78;
              uVar18 = DAT_006f3a7c;
            }
            FUN_004cb21d(uVar6,uVar18);
            (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x42]);
          }
          cVar1 = FUN_004cff80();
          iVar13 = DAT_006f3ac0;
          iVar11 = DAT_006f3ab0;
          if (cVar1 == '\0') {
            *(undefined4 *)(unaff_EBP + -0x34) = DAT_006f3ab8;
            *(undefined4 *)(unaff_EBP + -0x30) = DAT_006f3abc;
            uVar6 = DAT_006f3ac4;
          }
          else {
            *(undefined4 *)(unaff_EBP + -0x34) = DAT_006f3aa8;
            *(undefined4 *)(unaff_EBP + -0x30) = DAT_006f3aac;
            uVar6 = DAT_006f3ab4;
            iVar13 = iVar11;
          }
          *(undefined4 *)(unaff_EBP + -0x28) = uVar6;
          piVar4 = (int *)FUN_005caed9();
          if (*piVar4 == 0x400) {
            iVar13 = iVar13 + 0xe0;
          }
          pvVar7 = operator_new(0x210);
          *(void **)(unaff_EBP + -0x10) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          if (pvVar7 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_0052efca(extraout_ECX);
          }
          *(undefined1 *)(unaff_EBP + -4) = 10;
          extraout_ECX[0x44] = (int)piVar4;
          if (piVar4 != (int *)0x0) {
            cVar1 = (**(code **)(*piVar4 + 0xc))();
            if (cVar1 == '\0') goto LAB_0051989b;
            (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x44]);
            (**(code **)(*(int *)extraout_ECX[0x44] + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),iVar13,
                       *(undefined4 *)(unaff_EBP + -0x28));
            cVar1 = FUN_004cff80();
            uVar6 = DAT_006f3a80;
            uVar18 = DAT_006f3a84;
            if (cVar1 != '\0') {
              uVar6 = DAT_006f3a78;
              uVar18 = DAT_006f3a7c;
            }
            FUN_004cb21d(uVar6,uVar18);
          }
          pvVar7 = operator_new(500);
          *(void **)(unaff_EBP + -0x10) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 0xf;
          if (pvVar7 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_0052b99a(extraout_ECX);
          }
          *(undefined1 *)(unaff_EBP + -4) = 10;
          extraout_ECX[0x47] = (int)piVar4;
          if (piVar4 != (int *)0x0) {
            cVar1 = (**(code **)(*piVar4 + 0xc))();
            if (cVar1 == '\0') goto LAB_0051989b;
            (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x47]);
            (**(code **)(*(int *)extraout_ECX[0x47] + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),iVar13,
                       *(undefined4 *)(unaff_EBP + -0x28));
            cVar1 = FUN_004cff80();
            uVar6 = DAT_006f3a80;
            uVar18 = DAT_006f3a84;
            if (cVar1 != '\0') {
              uVar6 = DAT_006f3a78;
              uVar18 = DAT_006f3a7c;
            }
            FUN_004cb21d(uVar6,uVar18);
          }
          pvVar7 = operator_new(0x118);
          *(void **)(unaff_EBP + -0x10) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          if (pvVar7 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_0053153f(extraout_ECX);
          }
          *(undefined1 *)(unaff_EBP + -4) = 10;
          extraout_ECX[0x45] = (int)piVar4;
          if (piVar4 != (int *)0x0) {
            cVar1 = (**(code **)(*piVar4 + 0xc))();
            if (cVar1 == '\0') goto LAB_0051989b;
            (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x45]);
            (**(code **)(*(int *)extraout_ECX[0x45] + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),iVar13,
                       *(undefined4 *)(unaff_EBP + -0x28));
            cVar1 = FUN_004cff80();
            uVar6 = DAT_006f3a80;
            uVar18 = DAT_006f3a84;
            if (cVar1 != '\0') {
              uVar6 = DAT_006f3a78;
              uVar18 = DAT_006f3a7c;
            }
            FUN_004cb21d(uVar6,uVar18);
          }
          pvVar7 = operator_new(0x118);
          *(void **)(unaff_EBP + -0x10) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          if (pvVar7 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_00531f81(extraout_ECX);
          }
          *(undefined1 *)(unaff_EBP + -4) = 10;
          extraout_ECX[0x46] = (int)piVar4;
          if (piVar4 != (int *)0x0) {
            cVar1 = (**(code **)(*piVar4 + 0xc))();
            if (cVar1 == '\0') goto LAB_0051989b;
            (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x46]);
            (**(code **)(*(int *)extraout_ECX[0x46] + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),iVar13,
                       *(undefined4 *)(unaff_EBP + -0x28));
            cVar1 = FUN_004cff80();
            uVar6 = DAT_006f3a80;
            uVar18 = DAT_006f3a84;
            if (cVar1 != '\0') {
              uVar6 = DAT_006f3a78;
              uVar18 = DAT_006f3a7c;
            }
            FUN_004cb21d(uVar6,uVar18);
          }
          pvVar7 = operator_new(0x108);
          *(void **)(unaff_EBP + -0x10) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 0x12;
          if (pvVar7 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_00532a9b(extraout_ECX,extraout_ECX[0x44]);
          }
          *(undefined1 *)(unaff_EBP + -4) = 10;
          extraout_ECX[0x49] = (int)piVar4;
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),iVar13,
                       *(undefined4 *)(unaff_EBP + -0x28));
            cVar1 = (**(code **)(*(int *)extraout_ECX[0x49] + 0xc))();
            if (cVar1 == '\0') goto LAB_0051989b;
            (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x49]);
            cVar1 = FUN_004cff80();
            uVar6 = DAT_006f3a80;
            uVar18 = DAT_006f3a84;
            if (cVar1 != '\0') {
              uVar6 = DAT_006f3a78;
              uVar18 = DAT_006f3a7c;
            }
            FUN_004cb21d(uVar6,uVar18);
          }
          piVar4 = (int *)FUN_005caed9();
          if (*piVar4 == 0x400) {
            extraout_ECX[0x101] = 3;
            extraout_ECX[0x62] = 10;
            extraout_ECX[0x114] = 10;
          }
          else {
            extraout_ECX[0x62] = 5;
            extraout_ECX[0x101] = 2;
            extraout_ECX[0x114] = 6;
          }
          pvVar7 = operator_new(0xd4);
          *(void **)(unaff_EBP + -0x10) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 0x13;
          if (pvVar7 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_005dbd68();
          }
          *(undefined1 *)(unaff_EBP + -4) = 10;
          extraout_ECX[0x43] = (int)piVar4;
          if (piVar4 != (int *)0x0) {
            cVar1 = (**(code **)(*piVar4 + 0xc))();
            if (cVar1 == '\0') goto LAB_0051989b;
            (**(code **)(*(int *)extraout_ECX[0x43] + 0x60))
                      (*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),iVar13,
                       *(undefined4 *)(unaff_EBP + -0x28));
            cVar1 = FUN_004cff80();
            uVar6 = DAT_006f3a80;
            uVar18 = DAT_006f3a84;
            if (cVar1 != '\0') {
              uVar6 = DAT_006f3a78;
              uVar18 = DAT_006f3a7c;
            }
            FUN_004cb21d(uVar6,uVar18);
            (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x43]);
          }
          cVar1 = FUN_0051f4ef();
          if ((cVar1 != '\0') && (cVar1 = FUN_0051fc72(), cVar1 != '\0')) {
            FUN_0051aaec();
            pvVar7 = operator_new(0x154);
            *(void **)(unaff_EBP + -0x10) = pvVar7;
            *(undefined1 *)(unaff_EBP + -4) = 0x14;
            if (pvVar7 == (void *)0x0) {
              piVar4 = (int *)0x0;
            }
            else {
              piVar4 = (int *)FUN_0052dc62(extraout_ECX);
            }
            *(undefined1 *)(unaff_EBP + -4) = 10;
            extraout_ECX[0x48] = (int)piVar4;
            if (piVar4 != (int *)0x0) {
              cVar1 = (**(code **)(*piVar4 + 0xc))();
              if (cVar1 == '\0') goto LAB_0051989b;
              (**(code **)(*(int *)extraout_ECX[0x48] + 0x60))
                        (*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),
                         iVar13,*(undefined4 *)(unaff_EBP + -0x28));
              (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x48]);
              cVar1 = FUN_004cff80();
              uVar6 = DAT_006f3a80;
              uVar18 = DAT_006f3a84;
              if (cVar1 != '\0') {
                uVar6 = DAT_006f3a78;
                uVar18 = DAT_006f3a7c;
              }
              FUN_004cb21d(uVar6,uVar18);
            }
            FUN_005a5631(100,unaff_EBP + -0x78,4);
            pvVar7 = operator_new(0x194);
            *(void **)(unaff_EBP + -0x10) = pvVar7;
            *(undefined1 *)(unaff_EBP + -4) = 0x15;
            if (pvVar7 == (void *)0x0) {
              iVar11 = 0;
            }
            else {
              iVar11 = FUN_005e372a();
            }
            piVar4 = *(int **)(unaff_EBP + -0x78);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            extraout_ECX[0x65] = iVar11;
            if (piVar4 != (int *)0x0) {
              (**(code **)(*piVar4 + 0x68))(DAT_006f2a64);
            }
            (**(code **)(*(int *)extraout_ECX[0x65] + 0x19c))
                      (*(undefined4 *)(unaff_EBP + -0x78),4,1);
            *(undefined1 *)(extraout_ECX[0x65] + 0x16b) = 1;
            *(undefined4 *)(extraout_ECX[0x65] + 0xf4) = 1;
            (**(code **)(*(int *)extraout_ECX[0x65] + 0x98))();
            (**(code **)(*(int *)extraout_ECX[0x43] + 0x20))(extraout_ECX[0x65]);
            FUN_005a5631(0x65,unaff_EBP + -0x78,4);
            if (*(int **)(unaff_EBP + -0x78) != (int *)0x0) {
              (**(code **)(**(int **)(unaff_EBP + -0x78) + 0x68))(DAT_006f2a64);
            }
            pvVar7 = operator_new(0x194);
            *(void **)(unaff_EBP + -0x10) = pvVar7;
            *(undefined1 *)(unaff_EBP + -4) = 0x16;
            if (pvVar7 == (void *)0x0) {
              piVar4 = (int *)0x0;
            }
            else {
              piVar4 = (int *)FUN_005e372a();
            }
            uVar6 = *(undefined4 *)(unaff_EBP + -0x78);
            extraout_ECX[0x66] = (int)piVar4;
            iVar11 = *piVar4;
            *(undefined1 *)(unaff_EBP + -4) = 10;
            (**(code **)(iVar11 + 0x19c))(uVar6,4,1);
            *(undefined1 *)(extraout_ECX[0x66] + 0x16b) = 1;
            *(undefined4 *)(extraout_ECX[0x66] + 0xf4) = 1;
            (**(code **)(*(int *)extraout_ECX[0x66] + 0x98))();
            (**(code **)(*(int *)extraout_ECX[0x43] + 0x20))(extraout_ECX[0x66]);
            FUN_0051a62f();
            FUN_0046fca5();
            *(undefined ***)(unaff_EBP + -0x1c8) = &PTR_FUN_0066643c;
            *(undefined1 *)(unaff_EBP + -4) = 0x17;
            uVar6 = FUN_0041532c(9,unaff_EBP + -0x1c8,0);
            cVar1 = FUN_004fff98(0x9a,uVar6);
            if (cVar1 != '\0') {
              FUN_00471655(unaff_EBP + -0x14);
              *(undefined1 *)(unaff_EBP + -4) = 0x18;
              FUN_0046fc87(unaff_EBP + -0x6c,0);
              *(undefined1 *)(unaff_EBP + -4) = 0x19;
              uVar6 = FUN_0046fc7a();
              FUN_005d4956(uVar6);
              *(undefined1 *)(unaff_EBP + -4) = 0x1a;
              FUN_005dd9c8(unaff_EBP + -0x40);
              *(undefined1 *)(unaff_EBP + -4) = 0x19;
              FUN_005b8770();
              *(undefined1 *)(unaff_EBP + -4) = 0x18;
              FUN_0042004f();
              FUN_0046fc87(unaff_EBP + -0x6c,0);
              *(undefined1 *)(unaff_EBP + -4) = 0x1b;
              uVar6 = FUN_0046fc7a();
              FUN_005d4956(uVar6);
              *(undefined1 *)(unaff_EBP + -4) = 0x1c;
              FUN_005dd9c8(unaff_EBP + -0x40);
              *(undefined1 *)(unaff_EBP + -4) = 0x1b;
              FUN_005b8770();
              *(undefined1 *)(unaff_EBP + -4) = 0x18;
              FUN_0042004f();
              *(undefined1 *)(unaff_EBP + -4) = 0x17;
              FUN_0042004f();
            }
            FUN_0046fca5();
            *(undefined ***)(unaff_EBP + -0xf0) = &PTR_FUN_0066643c;
            *(undefined1 *)(unaff_EBP + -4) = 0x1d;
            cVar1 = FUN_004fff98(0x82,&DAT_006c265c,unaff_EBP + -0xf0,0);
            if (cVar1 == '\0') {
              *(undefined1 *)(unaff_EBP + -4) = 0x17;
            }
            else {
              FUN_00471655(unaff_EBP + -0x3c);
              *(undefined1 *)(unaff_EBP + -4) = 0x1e;
              FUN_0046fc87(unaff_EBP + -0x14,0);
              *(undefined1 *)(unaff_EBP + -4) = 0x1f;
              uVar6 = FUN_0046fc7a();
              FUN_005d4bbf(uVar6);
              *(undefined1 *)(unaff_EBP + -4) = 0x1e;
              FUN_0042004f();
              *(undefined4 *)(unaff_EBP + -0x68) = 0;
              FUN_0054821c(8,unaff_EBP + -0x21);
              *(undefined1 *)(unaff_EBP + -4) = 0x20;
              uVar6 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x18),8,unaff_EBP + -0x68,
                                   *(undefined4 *)(unaff_EBP + -0x10));
              *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
              piVar4 = extraout_ECX + 0x4a;
              *(undefined1 *)(unaff_EBP + -4) = 0x21;
              FUN_005203c6(unaff_EBP + -0x18);
              *(undefined1 *)(unaff_EBP + -4) = 0x1e;
              FUN_0048c4c9();
              iVar11 = 0;
              *(undefined4 *)(unaff_EBP + -0x1c) = 0;
              while( true ) {
                pvVar7 = operator_new(0x22c);
                *(void **)(unaff_EBP + -0x10) = pvVar7;
                *(undefined1 *)(unaff_EBP + -4) = 0x22;
                if (pvVar7 == (void *)0x0) {
                  uVar6 = 0;
                }
                else {
                  uVar6 = FUN_005130b2(unaff_EBP + -0x3c,(&DAT_0066c5e0)[iVar11],
                                       (&DAT_006f3980)[iVar11 * 2],(&DAT_006f3984)[iVar11 * 2],
                                       (&DAT_006f3940)[iVar11 * 2],(&DAT_006f3944)[iVar11 * 2]);
                }
                iVar11 = *(int *)(unaff_EBP + -0x1c);
                iVar13 = *piVar4;
                *(undefined1 *)(unaff_EBP + -4) = 0x1e;
                iVar14 = iVar11 * 4;
                *(undefined4 *)(iVar14 + iVar13) = uVar6;
                if (iVar11 == 5) {
                  *(undefined4 *)(unaff_EBP + -0x20) = 0;
                  FUN_005a5631(0xea6,unaff_EBP + -0x20,4);
                  if (*(int *)(unaff_EBP + -0x20) != 0) {
                    FUN_005e357a();
                    FUN_00510489(0,*(undefined4 *)(unaff_EBP + -0x20));
                    FUN_005e3581();
                  }
                }
                if ((*(int *)(iVar14 + *piVar4) != 0) &&
                   (cVar1 = (**(code **)(**(int **)(iVar14 + *piVar4) + 0xc))(), cVar1 != '\0')) {
                  (**(code **)(*(int *)extraout_ECX[0x40] + 0x20))
                            (*(undefined4 *)(iVar14 + *piVar4));
                }
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
                if (7 < *(int *)(unaff_EBP + -0x1c)) break;
                iVar11 = *(int *)(unaff_EBP + -0x1c);
              }
              *(undefined1 *)(unaff_EBP + -4) = 0x1d;
              FUN_0042004f();
              *(undefined1 *)(unaff_EBP + -4) = 0x17;
              FUN_00470467();
              FUN_0046fca5();
              *(undefined ***)(unaff_EBP + -0xf0) = &PTR_FUN_0066643c;
              *(undefined1 *)(unaff_EBP + -4) = 0x23;
              cVar1 = FUN_004fff98(0xb4,&DAT_006c265c,unaff_EBP + -0xf0,0);
              if (cVar1 != '\0') {
                FUN_00471655(unaff_EBP + -0x3c);
                iVar11 = 0;
                *(undefined1 *)(unaff_EBP + -4) = 0x24;
                FUN_0046fc87(unaff_EBP + -0x14,0);
                *(undefined1 *)(unaff_EBP + -4) = 0x25;
                uVar6 = FUN_0046fc7a();
                FUN_005d4bbf(uVar6);
                *(undefined1 *)(unaff_EBP + -4) = 0x24;
                FUN_0042004f();
                *(undefined4 *)(unaff_EBP + -0x68) = 0;
                FUN_0054821c(8,unaff_EBP + -0x21);
                *(undefined1 *)(unaff_EBP + -4) = 0x26;
                uVar6 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x18),8,unaff_EBP + -0x68,
                                     *(undefined4 *)(unaff_EBP + -0x10));
                *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
                piVar4 = extraout_ECX + 0x4d;
                *(undefined1 *)(unaff_EBP + -4) = 0x27;
                FUN_005203c6(unaff_EBP + -0x18);
                *(undefined1 *)(unaff_EBP + -4) = 0x24;
                FUN_0048c4c9();
                do {
                  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) {
                    pvVar7 = operator_new(0x22c);
                    *(void **)(unaff_EBP + -0x10) = pvVar7;
                    *(undefined1 *)(unaff_EBP + -4) = 0x29;
                    if (pvVar7 != (void *)0x0) {
                      uVar6 = 0;
                      uVar18 = 0;
                      uVar17 = (&DAT_006f3904)[iVar11 * 2];
                      uVar16 = (&DAT_006f3900)[iVar11 * 2];
                      uVar15 = (&DAT_0066c5e0)[iVar11];
                      goto LAB_005199b1;
                    }
LAB_005199b8:
                    uVar6 = 0;
                  }
                  else {
                    pvVar7 = operator_new(0x22c);
                    *(void **)(unaff_EBP + -0x10) = pvVar7;
                    *(undefined1 *)(unaff_EBP + -4) = 0x28;
                    if (pvVar7 == (void *)0x0) goto LAB_005199b8;
                    uVar6 = (&DAT_006f38c4)[iVar11 * 2];
                    uVar18 = (&DAT_006f38c0)[iVar11 * 2];
                    uVar17 = (&DAT_006f3904)[iVar11 * 2];
                    uVar16 = (&DAT_006f3900)[iVar11 * 2];
                    uVar15 = (&DAT_0066c5e0)[iVar11];
LAB_005199b1:
                    uVar6 = FUN_005130b2(unaff_EBP + -0x3c,uVar15,uVar16,uVar17,uVar18,uVar6);
                  }
                  iVar13 = *piVar4;
                  *(undefined1 *)(unaff_EBP + -4) = 0x24;
                  *(undefined4 *)(iVar13 + iVar11 * 4) = uVar6;
                  if (iVar11 == 5) {
                    *(undefined4 *)(unaff_EBP + -0x20) = 0;
                    FUN_005a5631(0xea6,unaff_EBP + -0x20,4);
                    if (*(int *)(unaff_EBP + -0x20) != 0) {
                      FUN_005e357a();
                      FUN_00510489(0,*(undefined4 *)(unaff_EBP + -0x20));
                      FUN_005e3581();
                    }
                  }
                  if ((*(int *)(*piVar4 + iVar11 * 4) != 0) &&
                     (cVar1 = (**(code **)(**(int **)(*piVar4 + iVar11 * 4) + 0xc))(), cVar1 != '\0'
                     )) {
                    (**(code **)(*(int *)extraout_ECX[0x41] + 0x20))
                              (*(undefined4 *)(*piVar4 + iVar11 * 4));
                  }
                  iVar11 = iVar11 + 1;
                } while (iVar11 < 8);
                *(undefined1 *)(unaff_EBP + -4) = 0x23;
                FUN_0042004f();
                *(undefined1 *)(unaff_EBP + -4) = 0x17;
                FUN_00470467();
                cVar1 = FUN_004cff80();
                if (cVar1 == '\0') {
                  *(undefined4 *)(unaff_EBP + -100) = 0;
                  *(undefined4 *)(unaff_EBP + -0x60) = 0x15;
                  *(undefined4 *)(unaff_EBP + -0x54) = 200;
                  *(undefined4 *)(unaff_EBP + -0x50) = 0x69;
                }
                else if (*(char *)(DAT_006e486c + 100) == '\x13') {
                  *(undefined4 *)(unaff_EBP + -100) = 0;
                  *(undefined4 *)(unaff_EBP + -0x60) = 0x1c;
                  *(undefined4 *)(unaff_EBP + -0x54) = 200;
                  *(undefined4 *)(unaff_EBP + -0x50) = 0x91;
                }
                else {
                  *(undefined4 *)(unaff_EBP + -100) = 0;
                  *(undefined4 *)(unaff_EBP + -0x60) = 0x28;
                  *(undefined4 *)(unaff_EBP + -0x54) = 200;
                  *(undefined4 *)(unaff_EBP + -0x50) = 0x9b;
                }
                piVar12 = (int *)extraout_ECX[0x4a];
                iVar11 = *(int *)(*piVar12 + 0x88);
                iVar13 = *(int *)(*piVar12 + 0x80);
                *(int *)(unaff_EBP + -0x5c) = *(int *)(*piVar12 + 0x84) - *(int *)(*piVar12 + 0x7c);
                *(int *)(unaff_EBP + -0x58) = (iVar11 - iVar13) + -1;
                iVar11 = *(int *)(*piVar12 + 0x88);
                iVar13 = *(int *)(*piVar12 + 0x80);
                *(int *)(unaff_EBP + -0x4c) = *(int *)(*piVar12 + 0x84) - *(int *)(*piVar12 + 0x7c);
                *(int *)(unaff_EBP + -0x48) = (iVar11 - iVar13) + -1;
                FUN_004ebf01(piVar12,extraout_ECX[0x4b] - extraout_ECX[0x4a] >> 2);
                cVar1 = FUN_004cff80();
                if (cVar1 != '\0') {
                  *(undefined1 *)(*(int *)extraout_ECX[0x4a] + 0x228) = 1;
                  *(undefined1 *)(*(int *)(extraout_ECX[0x4a] + 4) + 0x228) = 1;
                }
                cVar1 = FUN_004cff80();
                if (cVar1 == '\0') {
                  *(undefined4 *)(unaff_EBP + -100) = 0;
                  *(undefined4 *)(unaff_EBP + -0x60) = 0x15;
                  *(undefined4 *)(unaff_EBP + -0x54) = 200;
                  *(undefined4 *)(unaff_EBP + -0x50) = 0x69;
                }
                else if (*(char *)(DAT_006e486c + 100) == '\x13') {
                  *(undefined4 *)(unaff_EBP + -100) = 0;
                  *(undefined4 *)(unaff_EBP + -0x60) = 0x1c;
                  *(undefined4 *)(unaff_EBP + -0x54) = 200;
                  *(undefined4 *)(unaff_EBP + -0x50) = 0x91;
                }
                else {
                  *(undefined4 *)(unaff_EBP + -100) = 0;
                  *(undefined4 *)(unaff_EBP + -0x60) = 0x28;
                  *(undefined4 *)(unaff_EBP + -0x54) = 200;
                  *(undefined4 *)(unaff_EBP + -0x50) = 0x9b;
                }
                piVar12 = (int *)*piVar4;
                iVar11 = *(int *)(*piVar12 + 0x88);
                iVar13 = *(int *)(*piVar12 + 0x80);
                *(int *)(unaff_EBP + -0x5c) = *(int *)(*piVar12 + 0x84) - *(int *)(*piVar12 + 0x7c);
                *(int *)(unaff_EBP + -0x58) = (iVar11 - iVar13) + -1;
                iVar11 = *(int *)(*piVar12 + 0x84);
                iVar13 = *(int *)(*piVar12 + 0x7c);
                *(int *)(unaff_EBP + -0x48) =
                     (*(int *)(*piVar12 + 0x88) - *(int *)(*piVar12 + 0x80)) + -1;
                iVar14 = extraout_ECX[0x4e];
                *(int *)(unaff_EBP + -0x4c) = iVar11 - iVar13;
                FUN_004ebf01(piVar12,iVar14 - (int)piVar12 >> 2);
                cVar1 = FUN_004cff80();
                if (cVar1 != '\0') {
                  *(undefined1 *)(*(int *)*piVar4 + 0x228) = 1;
                  *(undefined1 *)(*(int *)(*piVar4 + 4) + 0x228) = 1;
                }
                *(undefined4 *)(unaff_EBP + -0x68) = 0;
                FUN_0054821c(5,unaff_EBP + -0x21);
                *(undefined1 *)(unaff_EBP + -4) = 0x2a;
                uVar6 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x18),5,unaff_EBP + -0x68,
                                     *(undefined4 *)(unaff_EBP + -0x10));
                *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
                piVar4 = extraout_ECX + 0x50;
                *(undefined1 *)(unaff_EBP + -4) = 0x2b;
                FUN_00520490(unaff_EBP + -0x18);
                *(undefined1 *)(unaff_EBP + -4) = 0x17;
                FUN_0048c4c9();
                FUN_0051dfa3(*piVar4,extraout_ECX[0x51] - *piVar4 >> 2,unaff_EBP + -0x1d8);
                if ((extraout_ECX[0x42] != 0) &&
                   (iVar11 = extraout_ECX[0x51], *(undefined4 *)(unaff_EBP + -0x1c) = 0,
                   iVar11 - *piVar4 >> 2 != 0)) {
                  do {
                    iVar11 = *(int *)(unaff_EBP + -0x1c) * 4;
                    if (*(int *)(iVar11 + *piVar4) != 0) {
                      (**(code **)(*(int *)extraout_ECX[0x42] + 0x20))
                                (*(undefined4 *)(iVar11 + *piVar4));
                    }
                    iVar11 = extraout_ECX[0x51];
                    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
                  } while (*(uint *)(unaff_EBP + -0x1c) < (uint)(iVar11 - *piVar4 >> 2));
                }
                cVar1 = FUN_004cff80();
                if (cVar1 == '\0') {
                  iVar11 = extraout_ECX[0x51];
                  piVar12 = (int *)*piVar4;
                  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
                  *(undefined4 *)(unaff_EBP + -0x58) = 0x12;
                  iVar13 = *(int *)(*piVar12 + 0x84);
                  iVar14 = *(int *)(*piVar12 + 0x7c);
                  *(undefined4 *)(unaff_EBP + -0x34) = 0;
                  *(undefined4 *)(unaff_EBP + -0x30) = 0;
                  *(int *)(unaff_EBP + -0x28) = (iVar11 - (int)piVar12 >> 2) * 0x13;
                  *(int *)(unaff_EBP + -0x2c) = iVar13 - iVar14;
                  iVar11 = *(int *)(*piVar12 + 0x84);
                  iVar13 = *(int *)(*piVar12 + 0x7c);
                  *(undefined4 *)(unaff_EBP + -0x10) = 8;
                  *(int *)(unaff_EBP + -0x14) = 0xca - (iVar11 - iVar13);
                }
                else {
                  iVar11 = extraout_ECX[0x51];
                  piVar12 = (int *)*piVar4;
                  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
                  *(undefined4 *)(unaff_EBP + -0x58) = 0x19;
                  iVar13 = *(int *)(*piVar12 + 0x84);
                  iVar14 = *(int *)(*piVar12 + 0x7c);
                  *(undefined4 *)(unaff_EBP + -0x34) = 0;
                  *(undefined4 *)(unaff_EBP + -0x30) = 0;
                  *(int *)(unaff_EBP + -0x28) = (iVar11 - (int)piVar12 >> 2) * 0x19;
                  *(int *)(unaff_EBP + -0x2c) = iVar13 - iVar14;
                  iVar11 = *(int *)(*piVar12 + 0x84);
                  iVar13 = *(int *)(*piVar12 + 0x7c);
                  *(undefined4 *)(unaff_EBP + -0x10) = 0xf;
                  *(int *)(unaff_EBP + -0x14) = 0xca - (iVar11 - iVar13);
                }
                puVar9 = (undefined4 *)FUN_004e84f4(unaff_EBP + -0x74,unaff_EBP + -0x34);
                uVar6 = puVar9[1];
                piVar12 = (int *)*piVar4;
                *(undefined4 *)(unaff_EBP + -100) = *puVar9;
                *(undefined4 *)(unaff_EBP + -0x60) = uVar6;
                *(undefined4 *)(unaff_EBP + -0x54) = puVar9[2];
                *(undefined4 *)(unaff_EBP + -0x50) = puVar9[3];
                iVar11 = *(int *)(*piVar12 + 0x84);
                iVar13 = *(int *)(*piVar12 + 0x7c);
                *(int *)(unaff_EBP + -0x48) = *(int *)(*piVar12 + 0x88) - *(int *)(*piVar12 + 0x80);
                *(int *)(unaff_EBP + -0x4c) = iVar11 - iVar13;
                FUN_004ebf01(piVar12,extraout_ECX[0x51] - (int)piVar12 >> 2);
                if (*(char *)(DAT_006e486c + 100) == '\x13') {
                  piVar4 = *(int **)(*piVar4 + -4 + (extraout_ECX[0x51] - *piVar4 >> 2) * 4);
                  iVar11 = piVar4[0x1f];
                  iVar13 = piVar4[0x21];
                  iVar14 = piVar4[0x20];
                  *(int *)(unaff_EBP + -0x28) = piVar4[0x22];
                  (**(code **)(*piVar4 + 0x60))
                            (iVar11 + 0x19,iVar14,iVar13,*(undefined4 *)(unaff_EBP + -0x28));
                  uVar6 = FUN_00521530(unaff_EBP + -0x34);
                  FUN_00521577(uVar6);
                  FUN_004cb21d(piVar4[0x1f] + 3,piVar4[0x20]);
                }
                pvVar7 = operator_new(0x194);
                *(void **)(unaff_EBP + -0x10) = pvVar7;
                *(undefined1 *)(unaff_EBP + -4) = 0x2c;
                if (pvVar7 == (void *)0x0) {
                  iVar11 = 0;
                }
                else {
                  iVar11 = FUN_005e372a();
                }
                *(undefined1 *)(unaff_EBP + -4) = 0x17;
                extraout_ECX[0x71] = iVar11;
                if (iVar11 != 0) {
                  FUN_005e4071(DAT_006f2aa4);
                  FUN_005d4956(&DAT_006de560);
                  piVar4 = (int *)extraout_ECX[0x71];
                  *(undefined1 *)(unaff_EBP + -4) = 0x2d;
                  (**(code **)(*piVar4 + 0x9c))(unaff_EBP + -0x18);
                  *(undefined1 *)(unaff_EBP + -4) = 0x17;
                  FUN_005b8770();
                  (**(code **)(*(int *)extraout_ECX[0x71] + 0x19c))(0,4,1);
                  (**(code **)(*(int *)extraout_ECX[0x42] + 0x20))(extraout_ECX[0x71]);
                }
                pvVar7 = operator_new(0x84);
                *(void **)(unaff_EBP + -0x10) = pvVar7;
                *(undefined1 *)(unaff_EBP + -4) = 0x2e;
                if (pvVar7 == (void *)0x0) {
                  iVar11 = 0;
                }
                else {
                  iVar11 = FUN_00510166(0,0,0,0,0,0,0,0,0);
                }
                *(undefined1 *)(unaff_EBP + -4) = 0x17;
                extraout_ECX[0x72] = iVar11;
                FUN_0046fca5();
                *(undefined ***)(unaff_EBP + -0x15c) = &PTR_FUN_0066643c;
                *(undefined1 *)(unaff_EBP + -4) = 0x2f;
                uVar6 = FUN_0041532c(9,unaff_EBP + -0x15c,0);
                cVar1 = FUN_004fff98(0xa5,uVar6);
                if (cVar1 != '\0') {
                  FUN_00471655(unaff_EBP + -0x14);
                  *(undefined1 *)(unaff_EBP + -4) = 0x30;
                  *(undefined4 *)(unaff_EBP + -0x68) = 0xc;
                  do {
                    FUN_0046fc87(unaff_EBP + -0x3c,0);
                    *(undefined1 *)(unaff_EBP + -4) = 0x31;
                    uVar6 = FUN_0046fc7a();
                    FUN_005d4bbf(uVar6);
                    *(undefined1 *)(unaff_EBP + -4) = 0x30;
                    FUN_0042004f();
                    FUN_0046fc87(unaff_EBP + -0x84,0);
                    *(undefined1 *)(unaff_EBP + -4) = 0x32;
                    uVar6 = FUN_0046fc7a();
                    FUN_005d4bbf(uVar6);
                    *(undefined1 *)(unaff_EBP + -4) = 0x30;
                    FUN_0042004f();
                    piVar4 = (int *)(unaff_EBP + -0x68);
                    *piVar4 = *piVar4 + -1;
                  } while (*piVar4 != 0);
                  *(undefined1 *)(unaff_EBP + -4) = 0x2f;
                  FUN_0042004f();
                }
                *(undefined4 *)(unaff_EBP + -0x1c) = 1;
                do {
                  sVar10 = _strlen(&DAT_006c08dc);
                  FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
                  puVar9 = (undefined4 *)
                           FUN_00484477(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + -0x1c));
                  uVar6 = puVar9[1];
                  uVar18 = *puVar9;
                  *(undefined1 *)(unaff_EBP + -4) = 0x33;
                  FUN_00412d8a(uVar18,uVar6);
                  *(undefined1 *)(unaff_EBP + -4) = 0x2f;
                  FUN_005b8770();
                  sVar10 = _strlen(&DAT_006c08dc);
                  FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar10);
                  puVar9 = (undefined4 *)
                           FUN_00484549(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + -0x1c));
                  uVar6 = puVar9[1];
                  uVar18 = *puVar9;
                  *(undefined1 *)(unaff_EBP + -4) = 0x34;
                  FUN_00412d8a(uVar18,uVar6);
                  *(undefined1 *)(unaff_EBP + -4) = 0x2f;
                  FUN_005b8770();
                  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
                } while (*(int *)(unaff_EBP + -0x1c) < 0xd);
                *(undefined1 *)(unaff_EBP + -4) = 0x17;
                FUN_00470467();
                FUN_0051d7c8();
                FUN_0051e1a1();
                FUN_0051e3b5();
                pvVar7 = operator_new(0x118);
                *(void **)(unaff_EBP + -0x10) = pvVar7;
                *(undefined1 *)(unaff_EBP + -4) = 0x35;
                if (pvVar7 == (void *)0x0) {
                  piVar4 = (int *)0x0;
                }
                else {
                  piVar4 = (int *)FUN_0050f7c5(extraout_ECX[0x39]);
                }
                *(undefined1 *)(unaff_EBP + -4) = 0x17;
                extraout_ECX[0x56] = (int)piVar4;
                if (piVar4 == (int *)0x0) {
                  uVar2 = 0;
                }
                else {
                  (**(code **)(*piVar4 + 0x98))();
                  FUN_005a5631(0x11f9,extraout_ECX + 0xc6,4);
                  piVar4 = (int *)extraout_ECX[0xc6];
                  if (piVar4 != (int *)0x0) {
                    (**(code **)(*piVar4 + 0x68))(DAT_006f2a64);
                  }
                  (**(code **)(**(int **)(DAT_006f2a08 + 0x84) + 0x20))(extraout_ECX[0x56]);
                  FUN_0051d3e7(1);
                  FUN_004e609e();
                  uVar6 = FUN_004e63de();
                  FUN_0051ef83(uVar6);
                  pvVar7 = operator_new(0x110);
                  *(void **)(unaff_EBP + -0x10) = pvVar7;
                  *(undefined1 *)(unaff_EBP + -4) = 0x36;
                  if (pvVar7 == (void *)0x0) {
                    piVar4 = (int *)0x0;
                  }
                  else {
                    piVar4 = (int *)FUN_005e9913();
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0x17;
                  if (piVar4 != (int *)0x0) {
                    piVar12 = piVar4 + 0x35;
                    (**(code **)(piVar4[0x35] + 0x18))(DAT_006f2aa0);
                    cVar1 = FUN_004cff80();
                    uVar6 = DAT_006f3aa0;
                    uVar18 = DAT_006f3aa4;
                    if (cVar1 != '\0') {
                      uVar6 = DAT_006f3a98;
                      uVar18 = DAT_006f3a9c;
                    }
                    FUN_004cb21d(uVar6,uVar18);
                    (**(code **)(*piVar12 + 0x14))(0);
                    (**(code **)(*piVar4 + 0x9c))(extraout_ECX + 200);
                    (**(code **)(*(int *)extraout_ECX[0x40] + 0x20))(piVar4);
                    (**(code **)(*piVar12 + 0xc))(2,0);
                    (**(code **)*piVar12)();
                  }
                  pvVar7 = operator_new(0x110);
                  *(void **)(unaff_EBP + -0x10) = pvVar7;
                  *(undefined1 *)(unaff_EBP + -4) = 0x37;
                  if (pvVar7 == (void *)0x0) {
                    piVar4 = (int *)0x0;
                  }
                  else {
                    piVar4 = (int *)FUN_005e9913();
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0x17;
                  if (piVar4 != (int *)0x0) {
                    piVar12 = piVar4 + 0x35;
                    (**(code **)(piVar4[0x35] + 0x18))(DAT_006f2aa0);
                    cVar1 = FUN_004cff80();
                    uVar6 = DAT_006f3aa0;
                    uVar18 = DAT_006f3aa4;
                    if (cVar1 != '\0') {
                      uVar6 = DAT_006f3a98;
                      uVar18 = DAT_006f3a9c;
                    }
                    FUN_004cb21d(uVar6,uVar18);
                    (**(code **)(*piVar12 + 0x14))(0);
                    (**(code **)(*piVar4 + 0x9c))(extraout_ECX + 200);
                    (**(code **)(*(int *)extraout_ECX[0x41] + 0x20))(piVar4);
                    (**(code **)(*piVar12 + 0xc))(2,0);
                    (**(code **)*piVar12)();
                  }
                  pvVar7 = operator_new(0x110);
                  *(void **)(unaff_EBP + -0x10) = pvVar7;
                  *(undefined1 *)(unaff_EBP + -4) = 0x38;
                  if (pvVar7 == (void *)0x0) {
                    piVar4 = (int *)0x0;
                  }
                  else {
                    piVar4 = (int *)FUN_005e9913();
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0x17;
                  if (piVar4 != (int *)0x0) {
                    if (*(char *)(DAT_006e486c + 100) == '\x04') {
                      iVar11 = piVar4[0x35];
                      uVar6 = DAT_006f2a98;
                    }
                    else {
                      iVar11 = piVar4[0x35];
                      uVar6 = DAT_006f2aa0;
                      if (*(char *)(DAT_006e486c + 100) == '\a') {
                        uVar6 = DAT_006f2a9c;
                      }
                    }
                    piVar12 = piVar4 + 0x35;
                    (**(code **)(iVar11 + 0x18))(uVar6);
                    cVar1 = FUN_004cff80();
                    uVar6 = DAT_006f3aa0;
                    uVar18 = DAT_006f3aa4;
                    if (cVar1 != '\0') {
                      uVar6 = DAT_006f3a98;
                      uVar18 = DAT_006f3a9c;
                    }
                    FUN_004cb21d(uVar6,uVar18);
                    (**(code **)(*piVar12 + 0x14))(0);
                    (**(code **)(*piVar4 + 0x9c))(&DAT_006f3ad0);
                    (**(code **)(*(int *)extraout_ECX[0x42] + 0x20))(piVar4);
                    (**(code **)(*piVar12 + 0xc))(2,0);
                    (**(code **)*piVar12)();
                    (**(code **)(*(int *)extraout_ECX[0x42] + 0x50))(piVar4);
                  }
                  pvVar7 = operator_new(0x110);
                  *(void **)(unaff_EBP + -0x10) = pvVar7;
                  *(undefined1 *)(unaff_EBP + -4) = 0x39;
                  if (pvVar7 == (void *)0x0) {
                    piVar4 = (int *)0x0;
                  }
                  else {
                    piVar4 = (int *)FUN_005e9913();
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0x17;
                  if (piVar4 != (int *)0x0) {
                    piVar12 = piVar4 + 0x35;
                    (**(code **)(piVar4[0x35] + 0x18))(DAT_006f2a8c);
                    cVar1 = FUN_004cff80();
                    uVar6 = DAT_006f3aa0;
                    uVar18 = DAT_006f3aa4;
                    if (cVar1 != '\0') {
                      uVar6 = DAT_006f3a98;
                      uVar18 = DAT_006f3a9c;
                    }
                    FUN_004cb21d(uVar6,uVar18);
                    (**(code **)(*piVar12 + 0x14))(0);
                    (**(code **)(*piVar4 + 0x9c))(extraout_ECX + 0xcb);
                    (**(code **)(*(int *)extraout_ECX[0x43] + 0x20))(piVar4);
                    (**(code **)(*piVar12 + 0xc))(2,0);
                    (**(code **)*piVar12)();
                  }
                  FUN_0046fca5();
                  *(undefined ***)(unaff_EBP + -0x15c) = &PTR_FUN_0066643c;
                  *(undefined1 *)(unaff_EBP + -4) = 0x3a;
                  uVar6 = FUN_0041532c(9,unaff_EBP + -0x15c,0);
                  cVar1 = FUN_004fff98(0x9a,uVar6);
                  if (cVar1 != '\0') {
                    pvVar7 = operator_new(0xd4);
                    *(void **)(unaff_EBP + -0x10) = pvVar7;
                    *(undefined1 *)(unaff_EBP + -4) = 0x3b;
                    if (pvVar7 == (void *)0x0) {
                      piVar4 = (int *)0x0;
                    }
                    else {
                      piVar4 = (int *)FUN_005dbd68();
                    }
                    *(undefined1 *)(unaff_EBP + -4) = 0x3a;
                    if ((piVar4 == (int *)0x0) ||
                       (cVar1 = (**(code **)(*piVar4 + 0xc))(), cVar1 == '\0')) {
                      FUN_005da4c7(piVar4);
                    }
                    else {
                      (**(code **)(*extraout_ECX + 0x20))(piVar4);
                      (**(code **)(*piVar4 + 0x60))
                                (DAT_006f3a60,DAT_006f3a64,DAT_006f3a68,DAT_006f3a6c);
                      FUN_004cb21d(DAT_006f3a60 + DAT_006f3a70,DAT_006f3a64 + DAT_006f3a74);
                      uVar6 = FUN_004705f2(0x10,0xffffffff);
                      FUN_005d4956(uVar6);
                      *(undefined1 *)(unaff_EBP + -4) = 0x3c;
                      FUN_005dd9c8(unaff_EBP + -0x18);
                      *(undefined1 *)(unaff_EBP + -4) = 0x3a;
                      FUN_005b8770();
                    }
                    pvVar7 = operator_new(0xd4);
                    *(void **)(unaff_EBP + -0x10) = pvVar7;
                    *(undefined1 *)(unaff_EBP + -4) = 0x3d;
                    if (pvVar7 == (void *)0x0) {
                      piVar4 = (int *)0x0;
                    }
                    else {
                      piVar4 = (int *)FUN_005dbd68();
                    }
                    *(undefined1 *)(unaff_EBP + -4) = 0x3a;
                    if ((piVar4 == (int *)0x0) ||
                       (cVar1 = (**(code **)(*piVar4 + 0xc))(), cVar1 == '\0')) {
                      FUN_005da4c7(piVar4);
                    }
                    else {
                      (**(code **)(*extraout_ECX + 0x20))(piVar4);
                      (**(code **)(*piVar4 + 0x60))
                                (DAT_006f3a50,DAT_006f3a54,DAT_006f3a58,DAT_006f3a5c);
                      FUN_004cb21d(DAT_006f3a70 + DAT_006f3a50,DAT_006f3a54 + DAT_006f3a74);
                      uVar6 = FUN_004705f2(0x10,0xffffffff);
                      FUN_005d4956(uVar6);
                      *(undefined1 *)(unaff_EBP + -4) = 0x3e;
                      FUN_005dd9c8(unaff_EBP + -0x30);
                      *(undefined1 *)(unaff_EBP + -4) = 0x3a;
                      FUN_005b8770();
                    }
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 0x17;
                  FUN_00470467();
                  FUN_005ddfdc(1);
                  uVar2 = 1;
                }
                *(undefined1 *)(unaff_EBP + -4) = 10;
                FUN_00470467();
                goto LAB_0051a620;
              }
              *(undefined1 *)(unaff_EBP + -4) = 0x17;
            }
            FUN_00470467();
            *(undefined1 *)(unaff_EBP + -4) = 10;
            goto LAB_00519896;
          }
        }
      }
    }
  }
LAB_0051989b:
  uVar2 = 0;
LAB_0051a620:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

