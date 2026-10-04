
undefined4 FUN_005154a3(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  void *pvVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  char *pcVar12;
  size_t sVar13;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar14;
  
  FUN_00634c24();
  uVar8 = DAT_006f2a98;
  *(undefined1 *)(unaff_EBP + -0x25) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = uVar8;
  uVar8 = DAT_006f2a90;
  cVar5 = *(char *)(DAT_006e486c + 100);
  uVar10 = DAT_006f2a94;
  if (cVar5 != '\x03') {
    if (cVar5 != '\x04') {
      if ((cVar5 == '\x05') || (cVar5 == '\t')) goto LAB_005154f8;
      if ((cVar5 != '\x0e') && (cVar5 != '\x10')) goto LAB_005154fb;
    }
    *(undefined1 *)(unaff_EBP + -0x25) = 1;
    uVar10 = uVar8;
  }
LAB_005154f8:
  *(undefined4 *)(unaff_EBP + -0x30) = uVar10;
LAB_005154fb:
  pvVar6 = operator_new(0xd4);
  *(void **)(unaff_EBP + -0x10) = pvVar6;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar6 == (void *)0x0) {
    iVar7 = 0;
  }
  else {
    iVar7 = FUN_005dbd68();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[100] = iVar7;
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    (**(code **)(*extraout_ECX + 0x20))(iVar7);
    (**(code **)(*(int *)extraout_ECX[100] + 0x60))
              (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
               extraout_ECX[0x21] - extraout_ECX[0x1f],extraout_ECX[0x22] - extraout_ECX[0x20]);
    (**(code **)(*(int *)extraout_ECX[100] + 0x98))();
    FUN_0046fc87(unaff_EBP + -0x40,0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar8 = FUN_0046fc7a();
    piVar9 = (int *)FUN_00500249(unaff_EBP + -0x38,uVar8);
    iVar14 = *piVar9 - *(int *)(unaff_EBP + 0xc);
    iVar7 = piVar9[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x1c) = iVar14;
    *(int *)(unaff_EBP + -0x18) = iVar7 - *(int *)(unaff_EBP + 0x10);
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + 0xc,0);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    uVar8 = FUN_0046fc7a();
    piVar9 = (int *)FUN_00500249(unaff_EBP + -0x38,uVar8);
    iVar7 = *piVar9;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x40) = iVar7;
    *(int *)(unaff_EBP + -0x3c) = piVar9[1];
    FUN_0042004f();
    if (*(char *)(unaff_EBP + -0x25) != '\0') {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 5;
      *(int *)(unaff_EBP + -0x1c) = iVar14;
    }
    if (*(char *)(DAT_006e486c + 100) == '\x13') {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -4;
    }
    *(undefined4 *)(unaff_EBP + 0x10) = 0;
    *(undefined4 **)(unaff_EBP + -0x20) = &DAT_0066c3e0;
    *(int **)(unaff_EBP + -0x24) = extraout_ECX + 0x51;
    do {
      pvVar6 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x14) = pvVar6;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (pvVar6 == (void *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (piVar9 != (int *)0x0) {
        piVar9[0x3e] = 2;
        piVar9[0x3d] = 0;
        (**(code **)(*piVar9 + 0x19c))(0,4,0);
        puVar11 = *(undefined4 **)(unaff_EBP + -0x30);
        FUN_005e4071(puVar11);
        FUN_0046fc87(unaff_EBP + -0x38,0);
        *(undefined4 *)(unaff_EBP + -4) = 4;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        iVar7 = *piVar9;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        (**(code **)(iVar7 + 0x9c))(unaff_EBP + -0x70);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0042004f();
        uVar8 = *puVar11;
        uVar10 = FUN_004096c2(piVar9[0x14] - piVar9[0x13]);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar8;
        puVar1 = *(undefined4 **)(unaff_EBP + -0x30);
        iVar7 = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x68))(uVar10);
        *(int *)(unaff_EBP + -0x14) = iVar7;
        puVar11 = (undefined4 *)(unaff_EBP + -0x14);
        if (iVar7 <= *(int *)(unaff_EBP + 0x10)) {
          puVar11 = (undefined4 *)(unaff_EBP + 0x10);
        }
        uVar8 = *puVar1;
        *(undefined4 *)(unaff_EBP + 0x10) = *puVar11;
        uVar10 = FUN_004096c2(piVar9[0x14] - piVar9[0x13]);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar8;
        piVar2 = *(int **)(unaff_EBP + -0x30);
        uVar8 = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x68))(uVar10);
        iVar7 = *piVar9;
        *(undefined4 *)(unaff_EBP + -0x14) = uVar8;
        iVar14 = *piVar2;
        *(int *)(unaff_EBP + -0x2c) = iVar7;
        uVar8 = (**(code **)(iVar14 + 0x58))();
        (**(code **)(*(int *)(unaff_EBP + -0x2c) + 0x60))
                  (0,0,*(undefined4 *)(unaff_EBP + -0x14),uVar8);
        puVar11 = operator_new(0xc);
        if (puVar11 == (undefined4 *)0x0) {
          puVar11 = (undefined4 *)0x0;
        }
        else {
          *puVar11 = 0;
          puVar11[1] = 0;
          puVar11[2] = 0;
        }
        if (puVar11 != (undefined4 *)0x0) {
          pcVar12 = (char *)FUN_0046fc7a();
          sVar13 = _strlen(pcVar12);
          pvVar6 = operator_new(sVar13 + 1);
          *(void **)(unaff_EBP + -0x2c) = pvVar6;
          if (pvVar6 != (void *)0x0) {
            uVar8 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x2c),uVar8);
          }
          FUN_005c11ce();
          pcVar12 = (char *)FUN_0046fc7a();
          sVar13 = _strlen(pcVar12);
          pvVar6 = operator_new(sVar13 + 1);
          *(void **)(unaff_EBP + -0x14) = pvVar6;
          if (pvVar6 != (void *)0x0) {
            uVar8 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x14),uVar8);
          }
          FUN_005c11ce();
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          if (**(int **)(unaff_EBP + -0x20) != -1) {
            FUN_005a5631(**(int **)(unaff_EBP + -0x20),unaff_EBP + -0x10,4);
          }
          *puVar11 = *(undefined4 *)(unaff_EBP + -0x2c);
          puVar11[1] = *(undefined4 *)(unaff_EBP + -0x14);
          puVar11[2] = *(undefined4 *)(unaff_EBP + -0x10);
          piVar9[0x2b] = (int)puVar11;
        }
        (**(code **)(*(int *)extraout_ECX[100] + 0x20))(piVar9);
        iVar7 = *(int *)(unaff_EBP + -0x40);
        **(undefined4 **)(unaff_EBP + -0x24) = piVar9;
      }
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 4;
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 4;
    } while (*(int *)(unaff_EBP + -0x20) < 0x66c3ed);
    *(undefined4 *)(unaff_EBP + -0x44) = 1;
    iVar14 = *(int *)(unaff_EBP + -0x3c);
    *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x54) = iVar7 + *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x18) + iVar14 * 4;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x5c) = iVar7;
    *(int *)(unaff_EBP + -0x58) = iVar14;
    *(int *)(unaff_EBP + -0x4c) = iVar7;
    *(int *)(unaff_EBP + -0x48) = iVar14;
    FUN_004ebf01(extraout_ECX + 0x51,4);
    iVar3 = DAT_006e486c;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(char *)(iVar3 + 100) == '\x13') {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
    }
    iVar3 = extraout_ECX[0x68];
    iVar4 = extraout_ECX[0x51];
    uVar8 = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(unaff_EBP + -0x20) = 0x1d;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar8;
    *(int *)(unaff_EBP + -0x14) =
         (((*(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x20)) - *(int *)(iVar4 + 0x80)) +
         *(int *)(iVar4 + 0x88)) / 2;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x10) / -4;
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + -0x14);
    do {
      pvVar6 = operator_new(0xe8);
      *(void **)(unaff_EBP + -0x10) = pvVar6;
      *(undefined4 *)(unaff_EBP + -4) = 7;
      if (pvVar6 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
      }
      else {
        uVar8 = FUN_005e4ba8();
        *(undefined4 *)(unaff_EBP + -0x24) = uVar8;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (*(int *)(unaff_EBP + -0x24) != 0) {
        FUN_005e4f47(extraout_ECX[0x68]);
        FUN_005e4fa8(1);
        iVar3 = *(int *)(unaff_EBP + -0x24);
        extraout_ECX[*(int *)(unaff_EBP + -0x20) + 0x38] = iVar3;
        (**(code **)(*(int *)extraout_ECX[100] + 0x20))(iVar3);
        if ((*(int *)(unaff_EBP + -0x20) == 0x1e) && (cVar5 = FUN_004074f7(), cVar5 == '\x01')) {
          (**(code **)(*(int *)extraout_ECX[0x56] + 0x90))(2,0);
        }
      }
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
    } while (*(int *)(unaff_EBP + -0x20) < 0x21);
    *(undefined4 *)(unaff_EBP + -0x44) = 1;
    *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x54) = iVar7 + *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x18) + iVar14 * 4;
    *(undefined4 *)(unaff_EBP + -4) = 8;
    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x5c) = iVar7;
    *(int *)(unaff_EBP + -0x58) = iVar14;
    *(int *)(unaff_EBP + -0x4c) = iVar7;
    *(int *)(unaff_EBP + -0x48) = iVar14;
    FUN_004ebf01(extraout_ECX + 0x55,4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    pvVar6 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x10) = pvVar6;
    *(undefined4 *)(unaff_EBP + -4) = 9;
    if (pvVar6 == (void *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)FUN_005e372a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (piVar9 != (int *)0x0) {
      FUN_0046fc87(unaff_EBP + -0x38,0);
      *(undefined4 *)(unaff_EBP + -4) = 10;
      FUN_0046fc7a();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0042004f();
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      FUN_005a5631(0x1360,unaff_EBP + -0x20,4);
      if (*(int **)(unaff_EBP + -0x20) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))(DAT_006f2a64);
      }
      (**(code **)(*piVar9 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x20),4,1);
      FUN_0046fc87(unaff_EBP + -0x38,0);
      *(undefined4 *)(unaff_EBP + -4) = 0xb;
      uVar8 = FUN_0046fc7a();
      FUN_005d4956(uVar8);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005dd9c8(unaff_EBP + -0x70);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0042004f();
      piVar9[0x3e] = 0;
      *(undefined1 *)((int)piVar9 + 0x16b) = 1;
      (**(code **)(*(int *)extraout_ECX[100] + 0x20))(piVar9);
      FUN_004cb21d(((*(int *)(extraout_ECX[100] + 0x84) - piVar9[0x21]) -
                   *(int *)(extraout_ECX[100] + 0x7c)) + -3 + piVar9[0x1f],7);
      extraout_ECX[0x59] = (int)piVar9;
      puVar11 = operator_new(0xc);
      if (puVar11 == (undefined4 *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
      }
      else {
        *(undefined4 **)(unaff_EBP + -0x24) = puVar11;
        *puVar11 = 0;
        puVar11[1] = 0;
        puVar11[2] = 0;
      }
      if (*(int *)(unaff_EBP + -0x24) != 0) {
        pcVar12 = (char *)FUN_0046fc7a();
        sVar13 = _strlen(pcVar12);
        pvVar6 = operator_new(sVar13 + 1);
        *(void **)(unaff_EBP + -0x10) = pvVar6;
        if (pvVar6 != (void *)0x0) {
          uVar8 = FUN_0046fc7a();
          FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x10),uVar8);
        }
        FUN_005c11ce();
        pcVar12 = (char *)FUN_0046fc7a();
        sVar13 = _strlen(pcVar12);
        pvVar6 = operator_new(sVar13 + 1);
        *(void **)(unaff_EBP + -0x14) = pvVar6;
        if (pvVar6 != (void *)0x0) {
          uVar8 = FUN_0046fc7a();
          FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x14),uVar8);
        }
        FUN_005c11ce();
        iVar14 = DAT_0066c400;
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        if (iVar14 != -1) {
          FUN_005a5631(iVar14,unaff_EBP + -0x2c,4);
        }
        puVar11 = *(undefined4 **)(unaff_EBP + -0x24);
        *puVar11 = *(undefined4 *)(unaff_EBP + -0x10);
        puVar11[1] = *(undefined4 *)(unaff_EBP + -0x14);
        puVar11[2] = *(undefined4 *)(unaff_EBP + -0x2c);
        piVar9[0x2b] = (int)puVar11;
      }
    }
    if (*(char *)(unaff_EBP + -0x25) == '\0') {
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + 0x10) + 0x46;
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
    }
    else {
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + 0x10) + 0x46;
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 2;
    }
    if (*(char *)(DAT_006e486c + 100) == '\x13') {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -8;
    }
    *(undefined4 **)(unaff_EBP + -0x20) = &DAT_0066c404;
    *(int **)(unaff_EBP + -0x24) = extraout_ECX + 0x5a;
    do {
      pvVar6 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar6;
      *(undefined4 *)(unaff_EBP + -4) = 0xd;
      if (pvVar6 == (void *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (piVar9 != (int *)0x0) {
        piVar9[0x3e] = 2;
        piVar9[0x3d] = 0;
        (**(code **)(*piVar9 + 0x19c))(0,4,0);
        puVar11 = *(undefined4 **)(unaff_EBP + -0x30);
        FUN_005e4071(puVar11);
        FUN_0046fc87(unaff_EBP + -0x38,0);
        *(undefined4 *)(unaff_EBP + -4) = 0xe;
        uVar8 = FUN_0046fc7a();
        FUN_005d4956(uVar8);
        iVar7 = *piVar9;
        *(undefined1 *)(unaff_EBP + -4) = 0xf;
        (**(code **)(iVar7 + 0x9c))(unaff_EBP + -0x70);
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0042004f();
        uVar8 = *puVar11;
        uVar10 = FUN_004096c2(piVar9[0x14] - piVar9[0x13]);
        *(undefined4 *)(unaff_EBP + -0x10) = uVar8;
        puVar1 = *(undefined4 **)(unaff_EBP + -0x30);
        iVar7 = (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x68))(uVar10);
        *(int *)(unaff_EBP + -0x10) = iVar7;
        puVar11 = (undefined4 *)(unaff_EBP + -0x10);
        if (iVar7 <= *(int *)(unaff_EBP + 0x10)) {
          puVar11 = (undefined4 *)(unaff_EBP + 0x10);
        }
        uVar8 = *puVar1;
        *(undefined4 *)(unaff_EBP + 0x10) = *puVar11;
        uVar10 = FUN_004096c2(piVar9[0x14] - piVar9[0x13]);
        *(undefined4 *)(unaff_EBP + -0x10) = uVar8;
        piVar2 = *(int **)(unaff_EBP + -0x30);
        uVar8 = (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x68))(uVar10);
        iVar7 = *piVar9;
        *(undefined4 *)(unaff_EBP + -0x10) = uVar8;
        iVar14 = *piVar2;
        *(int *)(unaff_EBP + -0x14) = iVar7;
        uVar8 = (**(code **)(iVar14 + 0x58))();
        (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x60))
                  (0,0,*(undefined4 *)(unaff_EBP + -0x10),uVar8);
        puVar11 = operator_new(0xc);
        if (puVar11 == (undefined4 *)0x0) {
          puVar11 = (undefined4 *)0x0;
        }
        else {
          *puVar11 = 0;
          puVar11[1] = 0;
          puVar11[2] = 0;
        }
        if (puVar11 != (undefined4 *)0x0) {
          pcVar12 = (char *)FUN_0046fc7a();
          sVar13 = _strlen(pcVar12);
          pvVar6 = operator_new(sVar13 + 1);
          *(void **)(unaff_EBP + -0x10) = pvVar6;
          if (pvVar6 != (void *)0x0) {
            uVar8 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x10),uVar8);
          }
          FUN_005c11ce();
          pcVar12 = (char *)FUN_0046fc7a();
          sVar13 = _strlen(pcVar12);
          pvVar6 = operator_new(sVar13 + 1);
          *(void **)(unaff_EBP + -0x14) = pvVar6;
          if (pvVar6 != (void *)0x0) {
            uVar8 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x14),uVar8);
          }
          FUN_005c11ce();
          *(undefined4 *)(unaff_EBP + -0x2c) = 0;
          if (**(int **)(unaff_EBP + -0x20) != -1) {
            FUN_005a5631(**(int **)(unaff_EBP + -0x20),unaff_EBP + -0x2c,4);
          }
          *puVar11 = *(undefined4 *)(unaff_EBP + -0x10);
          puVar11[1] = *(undefined4 *)(unaff_EBP + -0x14);
          puVar11[2] = *(undefined4 *)(unaff_EBP + -0x2c);
          piVar9[0x2b] = (int)puVar11;
        }
        (**(code **)(*(int *)extraout_ECX[100] + 0x20))(piVar9);
        iVar7 = *(int *)(unaff_EBP + -0x40);
        **(undefined4 **)(unaff_EBP + -0x24) = piVar9;
      }
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 4;
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 4;
    } while (*(int *)(unaff_EBP + -0x20) < 0x66c411);
    *(undefined4 *)(unaff_EBP + -0x44) = 1;
    iVar14 = *(int *)(unaff_EBP + -0x3c);
    *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x54) = iVar7 + *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x18) + iVar14 * 4;
    *(undefined4 *)(unaff_EBP + -4) = 0x10;
    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x5c) = iVar7;
    *(int *)(unaff_EBP + -0x58) = iVar14;
    *(int *)(unaff_EBP + -0x4c) = iVar7;
    *(int *)(unaff_EBP + -0x48) = iVar14;
    FUN_004ebf01(extraout_ECX + 0x5a,4);
    iVar3 = DAT_006e486c;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(char *)(iVar3 + 100) == '\x13') {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
    }
    iVar3 = extraout_ECX[0x68];
    iVar4 = extraout_ECX[0x5a];
    uVar8 = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(unaff_EBP + -0x10) = 4;
    *(undefined4 *)(unaff_EBP + 8) = uVar8;
    *(int *)(unaff_EBP + 0x10) =
         (((*(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x20)) - *(int *)(iVar4 + 0x80)) +
         *(int *)(iVar4 + 0x88)) / 2;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + 8) / -4;
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + 0x10);
    *(int **)(unaff_EBP + -0x14) = extraout_ECX + 0x5e;
    *(int **)(unaff_EBP + 0x10) = extraout_ECX + 0x5e;
    do {
      pvVar6 = operator_new(0xe8);
      *(void **)(unaff_EBP + 8) = pvVar6;
      *(undefined4 *)(unaff_EBP + -4) = 0x11;
      if (pvVar6 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + 8) = 0;
      }
      else {
        uVar8 = FUN_005e4ba8();
        *(undefined4 *)(unaff_EBP + 8) = uVar8;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (*(int *)(unaff_EBP + 8) != 0) {
        FUN_005e4f47(extraout_ECX[0x68]);
        FUN_005e4fa8(1);
        uVar8 = *(undefined4 *)(unaff_EBP + 8);
        **(undefined4 **)(unaff_EBP + 0x10) = uVar8;
        (**(code **)(*(int *)extraout_ECX[100] + 0x20))(uVar8);
      }
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 4;
      piVar9 = (int *)(unaff_EBP + -0x10);
      *piVar9 = *piVar9 + -1;
    } while (*piVar9 != 0);
    *(undefined4 *)(unaff_EBP + -0x74) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0x12;
    *(int *)(unaff_EBP + -0x80) = iVar14 * 4 + *(int *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x94) = *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x90) = *(int *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x84) = iVar7 + *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x8c) = iVar7;
    *(int *)(unaff_EBP + -0x88) = iVar14;
    *(int *)(unaff_EBP + -0x7c) = iVar7;
    *(int *)(unaff_EBP + -0x78) = iVar14;
    FUN_004ebf01(*(undefined4 *)(unaff_EBP + -0x14),4);
    uVar8 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}

