
undefined4 FUN_0051449d(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  size_t sVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar13;
  
  FUN_00634c24();
  pvVar2 = operator_new(0xd4);
  *(void **)(unaff_EBP + -0x28) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005dbd68();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x62] = iVar3;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    (**(code **)(*extraout_ECX + 0x20))(iVar3);
    (**(code **)(*(int *)extraout_ECX[0x62] + 0x60))
              (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
               extraout_ECX[0x21] - extraout_ECX[0x1f],extraout_ECX[0x22] - extraout_ECX[0x20]);
    (**(code **)(*(int *)extraout_ECX[0x62] + 0x98))();
    FUN_0046fc87(unaff_EBP + -0x3c,0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar4 = FUN_0046fc7a();
    piVar5 = (int *)FUN_00500249(unaff_EBP + -0x4c,uVar4);
    iVar13 = *piVar5 - *(int *)(unaff_EBP + 0xc);
    iVar3 = piVar5[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x34) = iVar13;
    *(int *)(unaff_EBP + -0x30) = iVar3 - *(int *)(unaff_EBP + 0x10);
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x2c,0);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    uVar4 = FUN_0046fc7a();
    puVar6 = (undefined4 *)FUN_00500249(unaff_EBP + -0x4c,uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x3c) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x38) = puVar6[1];
    FUN_0042004f();
    if (*(char *)(DAT_006e486c + 100) == '\x11') {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 4;
      *(int *)(unaff_EBP + -0x34) = iVar13;
    }
    else if (*(char *)(DAT_006e486c + 100) == '\x13') {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -6;
      *(int *)(unaff_EBP + -0x34) = iVar13;
    }
    *(undefined4 **)(unaff_EBP + -0x10) = &DAT_0066c394;
    *(int **)(unaff_EBP + -0x18) = extraout_ECX + 0x3e;
    do {
      pvVar2 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x20) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (pvVar2 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int **)(unaff_EBP + -0x14) = piVar5;
      if (piVar5 != (int *)0x0) {
        piVar5[0x3e] = 2;
        piVar5[0x3d] = 0;
        (**(code **)(*piVar5 + 0x19c))(0,4,0);
        uVar4 = DAT_006f2a98;
        *(undefined4 *)(unaff_EBP + -0x1c) = DAT_006f2a98;
        FUN_005e4071(uVar4);
        FUN_0046fc87(unaff_EBP + -0x4c,0);
        *(undefined4 *)(unaff_EBP + -4) = 4;
        uVar4 = FUN_0046fc7a();
        FUN_005d4956(uVar4);
        iVar3 = *piVar5;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        (**(code **)(iVar3 + 0x9c))(unaff_EBP + -0x58);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0042004f();
        FUN_005e4ada(0);
        uVar4 = **(undefined4 **)(unaff_EBP + -0x1c);
        uVar7 = FUN_004096c2(piVar5[0x14] - piVar5[0x13]);
        *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
        piVar5 = *(int **)(unaff_EBP + -0x1c);
        uVar4 = (**(code **)(*(int *)(unaff_EBP + -0x20) + 0x68))(uVar7);
        *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
        iVar3 = *piVar5;
        *(undefined4 *)(unaff_EBP + -0x1c) = **(undefined4 **)(unaff_EBP + -0x14);
        uVar4 = (**(code **)(iVar3 + 0x58))();
        iVar3 = *(int *)(unaff_EBP + -0x14);
        (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0x60))
                  (0,0,*(undefined4 *)(unaff_EBP + -0x20),uVar4);
        puVar6 = operator_new(0xc);
        if (puVar6 == (undefined4 *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
        }
        else {
          *puVar6 = 0;
          puVar6[1] = 0;
          puVar6[2] = 0;
          *(undefined4 **)(unaff_EBP + -0x14) = puVar6;
        }
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          pcVar8 = (char *)FUN_0046fc7a();
          sVar9 = _strlen(pcVar8);
          pvVar2 = operator_new(sVar9 + 1);
          *(void **)(unaff_EBP + -0x1c) = pvVar2;
          if (pvVar2 != (void *)0x0) {
            uVar4 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x1c),uVar4);
          }
          FUN_005c11ce();
          pcVar8 = (char *)FUN_0046fc7a();
          sVar9 = _strlen(pcVar8);
          pvVar2 = operator_new(sVar9 + 1);
          *(void **)(unaff_EBP + -0x20) = pvVar2;
          if (pvVar2 != (void *)0x0) {
            uVar4 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x20),uVar4);
          }
          FUN_005c11ce();
          *(undefined4 *)(unaff_EBP + -0x28) = 0;
          if (**(int **)(unaff_EBP + -0x10) != -1) {
            FUN_005a5631(**(int **)(unaff_EBP + -0x10),unaff_EBP + -0x28,4);
          }
          puVar6 = *(undefined4 **)(unaff_EBP + -0x14);
          *puVar6 = *(undefined4 *)(unaff_EBP + -0x1c);
          puVar6[1] = *(undefined4 *)(unaff_EBP + -0x20);
          puVar6[2] = *(undefined4 *)(unaff_EBP + -0x28);
          *(undefined4 **)(iVar3 + 0xac) = puVar6;
        }
        (**(code **)(*(int *)extraout_ECX[0x62] + 0x20))(iVar3);
        **(int **)(unaff_EBP + -0x18) = iVar3;
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
    } while (*(int *)(unaff_EBP + -0x10) < 0x66c3a1);
    *(undefined4 *)(unaff_EBP + -0x60) = 1;
    iVar3 = *(int *)(unaff_EBP + -0x3c);
    *(undefined4 *)(unaff_EBP + -4) = 6;
    *(int *)(unaff_EBP + -0x70) = *(int *)(unaff_EBP + -0x34) + iVar3;
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x34);
    *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x38) * 4 + *(int *)(unaff_EBP + -0x30);
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x30);
    *(int *)(unaff_EBP + -0x78) = iVar3;
    *(int *)(unaff_EBP + -0x68) = iVar3;
    FUN_004ebf01(extraout_ECX + 0x3e,4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046fc87(unaff_EBP + -0x4c,0);
    *(undefined4 *)(unaff_EBP + -4) = 7;
    uVar4 = FUN_0046fc7a();
    piVar5 = (int *)FUN_00500249(unaff_EBP + -0x2c,uVar4);
    iVar13 = *piVar5 - *(int *)(unaff_EBP + 0xc);
    iVar3 = piVar5[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x34) = iVar13;
    *(int *)(unaff_EBP + -0x30) = iVar3 - *(int *)(unaff_EBP + 0x10);
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x4c,0);
    *(undefined4 *)(unaff_EBP + -4) = 8;
    uVar4 = FUN_0046fc7a();
    puVar6 = (undefined4 *)FUN_00500249(unaff_EBP + -0x2c,uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x3c) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x38) = puVar6[1];
    FUN_0042004f();
    if (*(char *)(DAT_006e486c + 100) == '\x13') {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + -3;
      *(int *)(unaff_EBP + -0x34) = iVar13;
    }
    *(undefined4 **)(unaff_EBP + -0x10) = &DAT_0066c3a4;
    *(int **)(unaff_EBP + -0x14) = extraout_ECX + 0x42;
    do {
      pvVar2 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x28) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 9;
      if (pvVar2 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int **)(unaff_EBP + -0x18) = piVar5;
      if (piVar5 != (int *)0x0) {
        piVar5[0x3e] = 2;
        piVar5[0x3d] = 0;
        (**(code **)(*piVar5 + 0x19c))(0,4,0);
        uVar4 = DAT_006f2a98;
        *(undefined4 *)(unaff_EBP + -0x28) = DAT_006f2a98;
        FUN_005e4071(uVar4);
        FUN_0046fc87(unaff_EBP + -0x4c,0);
        *(undefined4 *)(unaff_EBP + -4) = 10;
        uVar4 = FUN_0046fc7a();
        FUN_005d4956(uVar4);
        iVar3 = *piVar5;
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        (**(code **)(iVar3 + 0x9c))(unaff_EBP + -0x58);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0042004f();
        FUN_005e4ada(2);
        uVar4 = **(undefined4 **)(unaff_EBP + -0x28);
        uVar7 = FUN_004096c2(piVar5[0x14] - piVar5[0x13]);
        *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
        piVar5 = *(int **)(unaff_EBP + -0x28);
        uVar4 = (**(code **)(*(int *)(unaff_EBP + -0x20) + 0x68))(uVar7);
        *(undefined4 *)(unaff_EBP + -0x28) = uVar4;
        iVar3 = *piVar5;
        *(undefined4 *)(unaff_EBP + -0x20) = **(undefined4 **)(unaff_EBP + -0x18);
        uVar4 = (**(code **)(iVar3 + 0x58))();
        iVar3 = *(int *)(unaff_EBP + -0x18);
        (**(code **)(*(int *)(unaff_EBP + -0x20) + 0x60))
                  (0,0,*(undefined4 *)(unaff_EBP + -0x28),uVar4);
        puVar6 = operator_new(0xc);
        if (puVar6 == (undefined4 *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
        }
        else {
          *puVar6 = 0;
          puVar6[1] = 0;
          puVar6[2] = 0;
          *(undefined4 **)(unaff_EBP + -0x18) = puVar6;
        }
        if (*(int *)(unaff_EBP + -0x18) != 0) {
          pcVar8 = (char *)FUN_0046fc7a();
          sVar9 = _strlen(pcVar8);
          pvVar2 = operator_new(sVar9 + 1);
          *(void **)(unaff_EBP + -0x28) = pvVar2;
          if (pvVar2 != (void *)0x0) {
            uVar4 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x28),uVar4);
          }
          FUN_005c11ce();
          pcVar8 = (char *)FUN_0046fc7a();
          sVar9 = _strlen(pcVar8);
          pvVar2 = operator_new(sVar9 + 1);
          *(void **)(unaff_EBP + -0x20) = pvVar2;
          if (pvVar2 != (void *)0x0) {
            uVar4 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x20),uVar4);
          }
          FUN_005c11ce();
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          if (**(int **)(unaff_EBP + -0x10) != -1) {
            FUN_005a5631(**(int **)(unaff_EBP + -0x10),unaff_EBP + -0x1c,4);
          }
          puVar6 = *(undefined4 **)(unaff_EBP + -0x18);
          *puVar6 = *(undefined4 *)(unaff_EBP + -0x28);
          puVar6[1] = *(undefined4 *)(unaff_EBP + -0x20);
          puVar6[2] = *(undefined4 *)(unaff_EBP + -0x1c);
          *(undefined4 **)(iVar3 + 0xac) = puVar6;
        }
        (**(code **)(*(int *)extraout_ECX[0x62] + 0x20))(iVar3);
        **(int **)(unaff_EBP + -0x14) = iVar3;
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    } while (*(int *)(unaff_EBP + -0x10) < 0x66c3a9);
    iVar3 = 0;
    piVar5 = extraout_ECX + 0x42;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 2;
    do {
      iVar13 = *(int *)(*piVar5 + 0x84) - *(int *)(*piVar5 + 0x7c);
      piVar10 = (int *)(unaff_EBP + -0x1c);
      *(int *)(unaff_EBP + -0x1c) = iVar13;
      if (iVar13 <= iVar3) {
        piVar10 = (int *)(unaff_EBP + -0x28);
      }
      iVar3 = *piVar10;
      piVar5 = piVar5 + 1;
      piVar10 = (int *)(unaff_EBP + -0x20);
      *piVar10 = *piVar10 + -1;
      *(int *)(unaff_EBP + -0x28) = iVar3;
    } while (*piVar10 != 0);
    *(undefined4 *)(unaff_EBP + -0x28) = 2;
    *(int **)(unaff_EBP + -0x18) = extraout_ECX + 0x42;
    do {
      FUN_004ec186(iVar3);
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
      piVar5 = (int *)(unaff_EBP + -0x28);
      *piVar5 = *piVar5 + -1;
    } while (*piVar5 != 0);
    *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) - iVar3;
    *(undefined4 *)(unaff_EBP + -0x60) = 1;
    iVar3 = *(int *)(unaff_EBP + -0x3c);
    iVar13 = *(int *)(unaff_EBP + -0x38);
    *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x34);
    *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0x34) + iVar3;
    *(int *)(unaff_EBP + -0x78) = iVar3;
    *(int *)(unaff_EBP + -0x68) = iVar3;
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x30);
    *(int *)(unaff_EBP + -0x74) = iVar13;
    *(int *)(unaff_EBP + -100) = iVar13;
    *(undefined4 *)(unaff_EBP + -4) = 0xc;
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x54);
    *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x30) + iVar13 * 2;
    FUN_004ebf01(extraout_ECX + 0x42,2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046fc87(unaff_EBP + -0x4c,0);
    *(undefined4 *)(unaff_EBP + -4) = 0xd;
    uVar4 = FUN_0046fc7a();
    piVar5 = (int *)FUN_00500249(unaff_EBP + -0x24,uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar3 = *piVar5 - *(int *)(unaff_EBP + 0xc);
    *(int *)(unaff_EBP + -0x30) = piVar5[1] - *(int *)(unaff_EBP + 0x10);
    *(int *)(unaff_EBP + -0x28) = iVar3;
    *(int *)(unaff_EBP + -0x34) = iVar3;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x4c,0);
    *(undefined4 *)(unaff_EBP + -4) = 0xe;
    uVar4 = FUN_0046fc7a();
    piVar5 = (int *)FUN_00500249(unaff_EBP + -0x24,uVar4);
    iVar3 = *piVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x38) = piVar5[1];
    FUN_0042004f();
    if (*(char *)(DAT_006e486c + 100) == '\x11') {
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 4;
      *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x28);
    }
    *(undefined4 *)(unaff_EBP + -0x28) = 4;
    *(int **)(unaff_EBP + -0x18) = extraout_ECX + 0x44;
    do {
      pvVar2 = operator_new(0xe8);
      *(void **)(unaff_EBP + -0x20) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0xf;
      if (pvVar2 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
      else {
        uVar4 = FUN_005e4ba8();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (*(int *)(unaff_EBP + -0x10) != 0) {
        FUN_005e4f47(extraout_ECX[0x68]);
        FUN_005e4fa8(1);
        uVar4 = *(undefined4 *)(unaff_EBP + -0x10);
        **(undefined4 **)(unaff_EBP + -0x18) = uVar4;
        (**(code **)(*(int *)extraout_ECX[0x62] + 0x20))(uVar4);
      }
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
      piVar5 = (int *)(unaff_EBP + -0x28);
      *piVar5 = *piVar5 + -1;
    } while (*piVar5 != 0);
    *(undefined4 *)(unaff_EBP + -0x60) = 1;
    *(int *)(unaff_EBP + -0x70) = *(int *)(unaff_EBP + -0x34) + iVar3;
    *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x34);
    *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x38) * 4 + *(int *)(unaff_EBP + -0x30);
    *(undefined4 *)(unaff_EBP + -4) = 0x10;
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x30);
    *(int *)(unaff_EBP + -0x78) = iVar3;
    *(int *)(unaff_EBP + -0x68) = iVar3;
    FUN_004ebf01(extraout_ECX + 0x44,4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046fc87(unaff_EBP + -0x4c,0);
    *(undefined4 *)(unaff_EBP + -4) = 0x11;
    uVar4 = FUN_0046fc7a();
    FUN_00500249(unaff_EBP + -0x44,uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x4c,0);
    *(undefined4 *)(unaff_EBP + -4) = 0x12;
    uVar4 = FUN_0046fc7a();
    piVar5 = (int *)FUN_00500249(unaff_EBP + -0x34,uVar4);
    iVar3 = *piVar5;
    iVar13 = piVar5[1] - *(int *)(unaff_EBP + 0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x20) = iVar3 - *(int *)(unaff_EBP + 0xc);
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + 0xc,0);
    *(undefined4 *)(unaff_EBP + -4) = 0x13;
    uVar4 = FUN_0046fc7a();
    puVar6 = (undefined4 *)FUN_00500249(unaff_EBP + -0x4c,uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x3c) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x38) = puVar6[1];
    FUN_0042004f();
    *(undefined4 *)(unaff_EBP + -0x28) = 2;
    *(int **)(unaff_EBP + -0x14) = extraout_ECX + 0x48;
    *(int **)(unaff_EBP + -0x18) = extraout_ECX + 0x48;
    do {
      pvVar2 = operator_new(0xe8);
      *(void **)(unaff_EBP + 0x10) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0x14;
      if (pvVar2 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + 0x10) = 0;
      }
      else {
        uVar4 = FUN_0053777d(extraout_ECX[0x67]);
        *(undefined4 *)(unaff_EBP + 0x10) = uVar4;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (*(int **)(unaff_EBP + 0x10) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + 0x10) + 0xc))();
        (**(code **)(**(int **)(unaff_EBP + 0x10) + 0x60))
                  (0,0,*(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x40));
        (**(code **)(*(int *)extraout_ECX[0x62] + 0x20))(*(undefined4 *)(unaff_EBP + 0x10));
        **(undefined4 **)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0x10);
      }
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
      piVar5 = (int *)(unaff_EBP + -0x28);
      *piVar5 = *piVar5 + -1;
    } while (*piVar5 != 0);
    *(undefined4 *)(unaff_EBP + -0x60) = 1;
    iVar3 = *(int *)(unaff_EBP + -0x3c);
    iVar1 = *(int *)(unaff_EBP + -0x38);
    *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0x20) + iVar3;
    *(int *)(unaff_EBP + -0x78) = iVar3;
    *(int *)(unaff_EBP + -0x50) = iVar1 * 3 + iVar13;
    *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x54);
    *(int *)(unaff_EBP + -0x68) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0x15;
    *(int *)(unaff_EBP + -0x7c) = iVar13;
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x50);
    *(int *)(unaff_EBP + -0x74) = iVar1;
    *(int *)(unaff_EBP + -100) = iVar1;
    FUN_004ebf01(*(undefined4 *)(unaff_EBP + -0x14),2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    pvVar2 = operator_new(0xe4);
    *(void **)(unaff_EBP + 0x10) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0x16;
    if (pvVar2 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_00537a1c();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (piVar5 != (int *)0x0) {
      FUN_00537d48(DAT_006f2a94);
      (**(code **)(*(int *)extraout_ECX[0x62] + 0x20))(piVar5);
      FUN_0046fc87(unaff_EBP + 0xc,0);
      *(undefined4 *)(unaff_EBP + -4) = 0x17;
      uVar4 = FUN_0046fc7a();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x28) = uVar4;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x4c,0);
      *(undefined4 *)(unaff_EBP + -4) = 0x18;
      uVar4 = FUN_0046fc7a();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 0x10) = uVar4;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x4c,0);
      *(undefined4 *)(unaff_EBP + -4) = 0x19;
      uVar4 = FUN_0046fc7a();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0042004f();
      FUN_00537d55(*(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + 0x10),uVar4);
      piVar10 = *(int **)(unaff_EBP + -0x14);
      extraout_ECX[0x4a] = (int)piVar5;
      iVar3 = *(int *)(*piVar10 + 0x84);
      iVar13 = *(int *)(*piVar10 + 0x7c);
      iVar11 = (**(code **)(*(int *)piVar5[0x38] + 0x58))();
      iVar12 = (**(code **)(*(int *)piVar5[0x38] + 0x58))();
      iVar1 = *(int *)(**(int **)(unaff_EBP + -0x14) + 0x7c);
      iVar12 = *(int *)(**(int **)(unaff_EBP + -0x14) + 0x80) + (-7 - iVar12);
      (**(code **)(*piVar5 + 0x60))
                (iVar1 + -8,iVar12,iVar1 + (iVar3 - iVar13) + 5,iVar11 + -2 + iVar12);
    }
    uVar4 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

