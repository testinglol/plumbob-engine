
undefined4 FUN_00514f95(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  char *pcVar12;
  size_t sVar13;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar14;
  
  FUN_00634c24();
  pvVar5 = operator_new(0xd4);
  *(void **)(unaff_EBP + -0x20) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_005dbd68();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[99] = iVar6;
  if (iVar6 == 0) {
    uVar7 = 0;
  }
  else {
    (**(code **)(*extraout_ECX + 0x20))(iVar6);
    (**(code **)(*(int *)extraout_ECX[99] + 0x60))
              (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
               extraout_ECX[0x21] - extraout_ECX[0x1f],extraout_ECX[0x22] - extraout_ECX[0x20]);
    (**(code **)(*(int *)extraout_ECX[99] + 0x98))();
    FUN_0046fc87(unaff_EBP + -0x30,0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar7 = FUN_0046fc7a();
    piVar8 = (int *)FUN_00500249(unaff_EBP + -0x38,uVar7);
    iVar14 = *piVar8 - *(int *)(unaff_EBP + 0xc);
    iVar6 = piVar8[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x28) = iVar14;
    *(int *)(unaff_EBP + -0x24) = iVar6 - *(int *)(unaff_EBP + 0x10);
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + 0xc,0);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    uVar7 = FUN_0046fc7a();
    puVar9 = (undefined4 *)FUN_00500249(unaff_EBP + -0x38,uVar7);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x30) = *puVar9;
    iVar6 = puVar9[1];
    *(int *)(unaff_EBP + -0x2c) = iVar6;
    FUN_0042004f();
    if (*(char *)(DAT_006e486c + 100) == '\x13') {
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + -4;
      *(int *)(unaff_EBP + -0x28) = iVar14;
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 **)(unaff_EBP + 0x10) = &DAT_0066c3c8;
    *(int **)(unaff_EBP + -0x14) = extraout_ECX + 0x4b;
    do {
      pvVar5 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x1c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (pvVar5 == (void *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)FUN_005e372a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (piVar8 != (int *)0x0) {
        piVar8[0x3e] = 2;
        piVar8[0x3d] = 0;
        (**(code **)(*piVar8 + 0x19c))(0,4,0);
        puVar9 = DAT_006f2a98;
        *(undefined4 **)(unaff_EBP + -0x18) = DAT_006f2a98;
        FUN_005e4071(puVar9);
        FUN_0046fc87(unaff_EBP + -0x38,0);
        *(undefined4 *)(unaff_EBP + -4) = 4;
        uVar7 = FUN_0046fc7a();
        FUN_005d4956(uVar7);
        iVar6 = *piVar8;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        (**(code **)(iVar6 + 0x9c))(unaff_EBP + -0x4c);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0042004f();
        uVar7 = *puVar9;
        uVar10 = FUN_004096c2(piVar8[0x14] - piVar8[0x13]);
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar7;
        puVar11 = *(undefined4 **)(unaff_EBP + -0x18);
        iVar6 = (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0x68))(uVar10);
        *(int *)(unaff_EBP + -0x1c) = iVar6;
        puVar9 = (undefined4 *)(unaff_EBP + -0x1c);
        if (iVar6 <= *(int *)(unaff_EBP + -0x10)) {
          puVar9 = (undefined4 *)(unaff_EBP + -0x10);
        }
        uVar7 = *puVar11;
        *(undefined4 *)(unaff_EBP + -0x10) = *puVar9;
        uVar10 = FUN_004096c2(piVar8[0x14] - piVar8[0x13]);
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar7;
        piVar1 = *(int **)(unaff_EBP + -0x18);
        uVar7 = (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0x68))(uVar10);
        iVar6 = *piVar8;
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar7;
        iVar14 = *piVar1;
        *(int *)(unaff_EBP + -0x18) = iVar6;
        uVar7 = (**(code **)(iVar14 + 0x58))();
        (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x60))
                  (0,0,*(undefined4 *)(unaff_EBP + -0x1c),uVar7);
        puVar11 = operator_new(0xc);
        puVar9 = (undefined4 *)0x0;
        if (puVar11 != (undefined4 *)0x0) {
          *puVar11 = 0;
          puVar11[1] = 0;
          puVar11[2] = 0;
          puVar9 = puVar11;
        }
        if (puVar9 != (undefined4 *)0x0) {
          pcVar12 = (char *)FUN_0046fc7a();
          sVar13 = _strlen(pcVar12);
          pvVar5 = operator_new(sVar13 + 1);
          *(void **)(unaff_EBP + -0x18) = pvVar5;
          if (pvVar5 != (void *)0x0) {
            uVar7 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x18),uVar7);
          }
          FUN_005c11ce();
          pcVar12 = (char *)FUN_0046fc7a();
          sVar13 = _strlen(pcVar12);
          pvVar5 = operator_new(sVar13 + 1);
          *(void **)(unaff_EBP + -0x1c) = pvVar5;
          if (pvVar5 != (void *)0x0) {
            uVar7 = FUN_0046fc7a();
            FUN_006358b0(*(undefined4 *)(unaff_EBP + -0x1c),uVar7);
          }
          FUN_005c11ce();
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          if (**(int **)(unaff_EBP + 0x10) != -1) {
            FUN_005a5631(**(int **)(unaff_EBP + 0x10),unaff_EBP + -0x20,4);
          }
          *puVar9 = *(undefined4 *)(unaff_EBP + -0x18);
          puVar9[1] = *(undefined4 *)(unaff_EBP + -0x1c);
          puVar9[2] = *(undefined4 *)(unaff_EBP + -0x20);
          piVar8[0x2b] = (int)puVar9;
        }
        (**(code **)(*(int *)extraout_ECX[99] + 0x20))(piVar8);
        iVar6 = *(int *)(unaff_EBP + -0x2c);
        **(undefined4 **)(unaff_EBP + -0x14) = piVar8;
      }
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 4;
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    } while (*(int *)(unaff_EBP + 0x10) < 0x66c3d1);
    *(undefined4 *)(unaff_EBP + -0x50) = 1;
    iVar14 = *(int *)(unaff_EBP + -0x30);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x28) + iVar14;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    *(int *)(unaff_EBP + -0x5c) = iVar6 * 3 + *(int *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x68) = iVar14;
    *(int *)(unaff_EBP + -100) = iVar6;
    *(int *)(unaff_EBP + -0x58) = iVar14;
    *(int *)(unaff_EBP + -0x54) = iVar6;
    FUN_004ebf01(extraout_ECX + 0x4b,3);
    iVar14 = DAT_006e486c;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (*(char *)(iVar14 + 100) == '\x13') {
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 4;
    }
    iVar14 = extraout_ECX[0x4b];
    iVar2 = *(int *)(extraout_ECX[0x69] + 0x18);
    iVar3 = *(int *)(extraout_ECX[0x69] + 0x20);
    iVar4 = *(int *)(iVar14 + 0x80);
    iVar14 = *(int *)(iVar14 + 0x88);
    *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + *(int *)(unaff_EBP + -0x10) + 0xf;
    *(int *)(unaff_EBP + -0x24) =
         *(int *)(unaff_EBP + -0x24) + (((iVar2 - iVar3) - iVar4) + iVar14) / 2;
    FUN_0046fc87(unaff_EBP + 0xc,0);
    *(undefined4 *)(unaff_EBP + -4) = 7;
    uVar7 = FUN_0046fc7a();
    FUN_00500249(unaff_EBP + -0x40,uVar7);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0042004f();
    *(undefined4 *)(unaff_EBP + 0x10) = 3;
    *(int **)(unaff_EBP + -0x20) = extraout_ECX + 0x4e;
    *(int **)(unaff_EBP + 8) = extraout_ECX + 0x4e;
    do {
      pvVar5 = operator_new(0x124);
      *(void **)(unaff_EBP + -0x1c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 8;
      if (pvVar5 == (void *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)FUN_005f5b18();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (piVar8 != (int *)0x0) {
        piVar8[2] = (int)piVar8;
        (**(code **)(*piVar8 + 0x1b4))(1);
        (**(code **)(*piVar8 + 0x1b8))(extraout_ECX[0x69],0);
        (**(code **)(*piVar8 + 0x60))
                  (0,0,*(undefined4 *)(unaff_EBP + -0x40),
                   *(int *)(extraout_ECX[0x69] + 0x20) - *(int *)(extraout_ECX[0x69] + 0x18));
        (**(code **)(*piVar8 + 0x1ac))(0);
        (**(code **)(*piVar8 + 0x1b0))(10);
        *(undefined1 *)((int)piVar8 + 0x11d) = 1;
        (**(code **)(*(int *)extraout_ECX[99] + 0x20))(piVar8);
        **(undefined4 **)(unaff_EBP + 8) = piVar8;
      }
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
      piVar8 = (int *)(unaff_EBP + 0x10);
      *piVar8 = *piVar8 + -1;
    } while (*piVar8 != 0);
    *(undefined4 *)(unaff_EBP + -0x50) = 1;
    iVar14 = *(int *)(unaff_EBP + -0x30);
    *(int *)(unaff_EBP + -0x60) = iVar14 + *(int *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -4) = 9;
    *(int *)(unaff_EBP + -0x70) = *(int *)(unaff_EBP + -0x28);
    *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x5c) = iVar6 * 3 + *(int *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x68) = iVar14;
    *(int *)(unaff_EBP + -100) = iVar6;
    *(int *)(unaff_EBP + -0x58) = iVar14;
    *(int *)(unaff_EBP + -0x54) = iVar6;
    FUN_004ebf01(*(undefined4 *)(unaff_EBP + -0x20),3);
    uVar7 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

