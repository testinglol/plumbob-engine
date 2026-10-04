
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00545b04(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int *extraout_ECX;
  uint uVar13;
  int unaff_EBP;
  int *piVar14;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0xa0) = 0x112;
  *(undefined4 *)(unaff_EBP + -0x98) = 0x112;
  *(undefined4 *)(unaff_EBP + -0x90) = 0xca;
  *(undefined4 *)(unaff_EBP + -0x88) = 0xca;
  *(undefined4 *)(unaff_EBP + -0x80) = 0xca;
  *(undefined4 *)(unaff_EBP + -0x78) = 0x123;
  *(undefined4 *)(unaff_EBP + -0x70) = 0x123;
  *(undefined4 *)(unaff_EBP + -0x68) = 0xa0;
  *(undefined4 *)(unaff_EBP + -0x60) = 0xa0;
  *(undefined4 *)(unaff_EBP + -0xa4) = 499;
  *(undefined4 *)(unaff_EBP + -0x58) = 0x211;
  *(undefined4 *)(unaff_EBP + -0x50) = 0x211;
  iVar8 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x94) = 499;
  *(undefined4 *)(unaff_EBP + -0xb4) = 0x1f1;
  *(undefined4 *)(unaff_EBP + -0xb0) = 0x65;
  *(undefined4 *)(unaff_EBP + -0xac) = 0x196;
  *(undefined4 *)(unaff_EBP + -0xa8) = 0x6f;
  *(undefined4 *)(unaff_EBP + -0x9c) = 400;
  *(undefined4 *)(unaff_EBP + -0x8c) = 0x1c4;
  *(undefined4 *)(unaff_EBP + -0x84) = 0x18c;
  *(undefined4 *)(unaff_EBP + -0x7c) = 0x244;
  *(undefined4 *)(unaff_EBP + -0x74) = 0x2d9;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0x255;
  *(undefined4 *)(unaff_EBP + -100) = 0x2ca;
  *(undefined4 *)(unaff_EBP + -0x5c) = 200;
  *(undefined4 *)(unaff_EBP + -0x54) = 600;
  cVar4 = (**(code **)(iVar8 + 200))();
  if (cVar4 != '\0') {
    uVar5 = FUN_005e8d11();
    goto LAB_00546cf1;
  }
  extraout_ECX[0x41] = 3;
  extraout_ECX[0x19] = DAT_006f2a68;
  FUN_005a5631(0x13b2,extraout_ECX + 0x42,4);
  iVar8 = extraout_ECX[0x42];
  if (iVar8 == 0) {
    extraout_ECX[0x43] = 0;
    extraout_ECX[0x44] = 0;
  }
  else {
    uVar13 = *(uint *)(iVar8 + 0x1c);
    iVar9 = extraout_ECX[0x21];
    iVar2 = extraout_ECX[0x22];
    iVar10 = extraout_ECX[0x1f];
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar8 + 0x20);
    if (uVar13 < (uint)(iVar9 - iVar10)) {
      uVar13 = (iVar9 - iVar10) - uVar13 >> 1;
    }
    else {
      uVar13 = 0;
    }
    uVar1 = *(uint *)(unaff_EBP + -0x10);
    extraout_ECX[0x43] = uVar13;
    if (uVar1 < (uint)(iVar2 - extraout_ECX[0x20])) {
      uVar13 = (uint)((iVar2 - extraout_ECX[0x20]) - *(int *)(unaff_EBP + -0x10)) >> 1;
    }
    else {
      uVar13 = 0;
    }
    extraout_ECX[0x44] = uVar13;
  }
  piVar14 = extraout_ECX + 0x43;
  FUN_005e8d11();
  (**(code **)(*extraout_ECX + 0x90))(0x2000,1);
  FUN_005a5631(0x14b5,extraout_ECX + 0x6a,4);
  if ((int *)extraout_ECX[0x6a] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0x6a] + 0x68))(DAT_006f2a64);
  }
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x13c) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar6 = FUN_0041532c(9,unaff_EBP + -0x13c,0);
  cVar4 = FUN_004fff98(0x82,uVar6);
  if (cVar4 == '\0') {
    *(undefined1 *)(unaff_EBP + -0x19) = 0;
  }
  else {
    FUN_00471655(unaff_EBP + -0x44);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(int *)(unaff_EBP + -0x10) = unaff_EBP + -0xb4;
    *(undefined4 **)(unaff_EBP + -0x30) = &DAT_0066fabc;
    *(int **)(unaff_EBP + -0x18) = extraout_ECX + 0x4b;
    do {
      if (*(int *)(unaff_EBP + -0x30) < 0x66fae8) {
        pvVar7 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x14) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        if (pvVar7 == (void *)0x0) {
          iVar8 = 0;
        }
        else {
          iVar8 = FUN_005e372a();
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        **(int **)(unaff_EBP + -0x18) = iVar8;
        if (iVar8 != 0) {
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          FUN_005a5631(**(undefined4 **)(unaff_EBP + -0x30),unaff_EBP + -0x14,4);
          if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
            (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + -0x18) + 0x19c))
                      (*(undefined4 *)(unaff_EBP + -0x14),4,1);
            *(undefined1 *)(**(int **)(unaff_EBP + -0x18) + 0x16b) = 1;
          }
        }
        if (**(int **)(unaff_EBP + -0x18) != 0) {
          (**(code **)(*extraout_ECX + 0x20))(**(int **)(unaff_EBP + -0x18));
          FUN_004cb21d(**(int **)(unaff_EBP + -0x10) + *piVar14,
                       extraout_ECX[0x44] + (*(int **)(unaff_EBP + -0x10))[1]);
          (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + -0x18) + 0x90))(0x2000,1);
          FUN_0046fc87(unaff_EBP + -0xd0,0);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005dd9c8(unaff_EBP + -200);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0042004f();
        }
      }
      else {
        pvVar7 = operator_new(0x1ac);
        *(void **)(unaff_EBP + -0x14) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        if (pvVar7 == (void *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
        }
        else {
          uVar6 = FUN_005f7201(extraout_ECX[0x6a]);
          *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (*(int *)(unaff_EBP + -0x14) != 0) {
          (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
          FUN_004cb1a2(200,*(undefined4 *)(extraout_ECX[0x6a] + 0x20));
          iVar8 = extraout_ECX[0x44];
          iVar9 = (*(int **)(unaff_EBP + -0x10))[1];
          *(int *)(unaff_EBP + -0xb8) = *(int *)(extraout_ECX[0x6a] + 0x20) / 2;
          *(int *)(unaff_EBP + -0x4c) = *piVar14 + **(int **)(unaff_EBP + -0x10);
          *(int *)(unaff_EBP + -0x48) = iVar8 + iVar9 + *(int *)(unaff_EBP + -0xb8);
          FUN_005f78d8(unaff_EBP + -0x4c);
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x90))(0x2000,1);
          FUN_0046fc87(unaff_EBP + -0x38,0);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          uVar6 = FUN_0046fc7a();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x9c))(unaff_EBP + -0x28);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0042004f();
          **(undefined4 **)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x14);
        }
      }
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 4;
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 8;
    } while (*(int *)(unaff_EBP + -0x30) < 0x66faf0);
    pvVar7 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x6b] = iVar8;
    if (iVar8 != 0) {
      (**(code **)(*(int *)(iVar8 + 0xd4) + 0x18))(DAT_006f2ab4);
      iVar8 = extraout_ECX[0x1f];
      *(int *)(unaff_EBP + -0x24) = extraout_ECX[0x21];
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) - iVar8;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      iVar8 = (**(code **)(**(int **)(extraout_ECX[0x6b] + 0xd8) + 0x58))();
      (**(code **)(*(int *)extraout_ECX[0x6b] + 0x60))
                (*(undefined4 *)(unaff_EBP + -0x2c),extraout_ECX[0x44] + 6,
                 *(undefined4 *)(unaff_EBP + -0x24),iVar8 + 6 + extraout_ECX[0x44]);
      iVar8 = *(int *)extraout_ECX[0x6b];
      uVar6 = FUN_004705f2(0x10,0xffffffff);
      (**(code **)(iVar8 + 0x1a0))(uVar6);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x6b]);
      (**(code **)(*(int *)(extraout_ECX[0x6b] + 0xd4) + 0x1c))(2);
      (**(code **)(*(int *)(extraout_ECX[0x6b] + 0xd4) + 0x14))(0);
    }
    if (DAT_006f5008 != '\0') {
      pvVar7 = operator_new(0x110);
      *(void **)(unaff_EBP + -0x10) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 9;
      if (pvVar7 == (void *)0x0) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_005e9913();
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      extraout_ECX[0x78] = iVar8;
      if (iVar8 != 0) {
        (**(code **)(*(int *)(iVar8 + 0xd4) + 0x18))(DAT_006f2a94);
        (**(code **)(*(int *)(extraout_ECX[0x78] + 0xd4) + 0xc))(2,1);
        (*(code *)**(undefined4 **)(extraout_ECX[0x78] + 0xd4))();
        FUN_004cb21d(DAT_006f5000,DAT_006f5004 + -200);
        (**(code **)(*(int *)extraout_ECX[0x78] + 0x1a0))(s_body_strings_cheat_006cd6d4);
        iVar8 = *(int *)extraout_ECX[0x78];
        iVar9 = (**(code **)(*DAT_006f2a94 + 0x58))();
        (**(code **)(iVar8 + 0x60))(DAT_006f5000 + -0x32,10,DAT_006f5000 + 400,iVar9 << 2);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x78]);
        (**(code **)(*(int *)(extraout_ECX[0x78] + 0xd4) + 0x14))(0);
      }
    }
    uVar6 = FUN_004705f2(0x19,0xffffffff);
    FUN_005d4bbf(uVar6);
    uVar6 = FUN_004705f2(0x1a,0xffffffff);
    FUN_005d4bbf(uVar6);
    pvVar7 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x6c] = iVar8;
    if (iVar8 != 0) {
      (**(code **)(*(int *)(iVar8 + 0xd4) + 0x18))(DAT_006f2a9c);
      *(int *)(unaff_EBP + -0x2c) = DAT_006f4fc0;
      *(int *)(unaff_EBP + -0x28) = DAT_006f4fc4;
      iVar8 = (**(code **)(**(int **)(extraout_ECX[0x6c] + 0xd8) + 0x58))();
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + iVar8 * -2;
      iVar8 = (**(code **)(**(int **)(extraout_ECX[0x6c] + 0xd8) + 0x58))();
      piVar3 = *(int **)(extraout_ECX[0x6c] + 0xd8);
      *(int *)(unaff_EBP + -0x20) = iVar8 + *(int *)(unaff_EBP + -0x28);
      *(int **)(unaff_EBP + -0x10) = piVar3;
      iVar10 = (**(code **)(*piVar3 + 0x68))
                         (extraout_ECX[0x6d],extraout_ECX[0x6e] - extraout_ECX[0x6d]);
      iVar8 = *(int *)(unaff_EBP + -0x2c);
      iVar9 = *piVar14;
      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar9;
      iVar2 = extraout_ECX[0x44];
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + iVar2;
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + iVar2;
      (**(code **)(*(int *)extraout_ECX[0x6c] + 0x60))
                (*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28),
                 iVar10 + iVar8 + iVar9,*(undefined4 *)(unaff_EBP + -0x20));
      (**(code **)(*(int *)extraout_ECX[0x6c] + 0x9c))(extraout_ECX + 0x6d);
      (**(code **)(*(int *)(extraout_ECX[0x6c] + 0xd4) + 0x14))(0);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x6c]);
    }
    pvVar7 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    if (pvVar7 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar6 = FUN_005e9913();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x18) + 0xd4) + 0x18))(DAT_006f2aa4);
      (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x18) + 0xd4) + 0xc))(2,0);
      uVar6 = **(undefined4 **)(unaff_EBP + -0x18);
      uVar11 = FUN_004705f2(0x1b,0xffffffff);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      iVar8 = *(int *)(unaff_EBP + -0x18);
      (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x1a0))(uVar11);
      (*(code *)**(undefined4 **)(iVar8 + 0xd4))();
      FUN_004cb21d((*piVar14 - *(int *)(*(int *)(unaff_EBP + -0x18) + 0x84)) +
                   *(int *)(*(int *)(unaff_EBP + -0x18) + 0x7c) + -0x14 + DAT_006f4fd8,
                   extraout_ECX[0x44] + _DAT_006f4fdc);
      (**(code **)(*(int *)(iVar8 + 0xd4) + 0x14))(0);
      (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x18));
    }
    pvVar7 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    if (pvVar7 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
    }
    else {
      uVar6 = FUN_005e9913();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x14) + 0xd4) + 0x18))(DAT_006f2aa4);
      (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x14) + 0xd4) + 0xc))(2,0);
      uVar6 = **(undefined4 **)(unaff_EBP + -0x14);
      uVar11 = FUN_004705f2(0x11,0xffffffff);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      iVar8 = *(int *)(unaff_EBP + -0x14);
      (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x1a0))(uVar11);
      (*(code *)**(undefined4 **)(iVar8 + 0xd4))();
      FUN_004cb21d((*piVar14 -
                   (*(int *)(*(int *)(unaff_EBP + -0x18) + 0x84) -
                   *(int *)(*(int *)(unaff_EBP + -0x18) + 0x7c)) / 2) + _DAT_006f4fa0,
                   (*(int *)(*(int *)(unaff_EBP + -0x14) + 0x80) -
                   *(int *)(*(int *)(unaff_EBP + -0x14) + 0x88)) + extraout_ECX[0x44] +
                   _DAT_006f4fa4);
      (**(code **)(*(int *)(iVar8 + 0xd4) + 0x14))(0);
      (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
    }
    FUN_0046fc87(unaff_EBP + -0x38,0);
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    uVar6 = FUN_0046fc7a();
    FUN_005d4bbf(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x38,0);
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    uVar6 = FUN_0046fc7a();
    FUN_005d4bbf(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    *(undefined4 *)(extraout_ECX[0x4c] + 0xf8) = 1;
    FUN_005e46f0(0);
    piVar3 = (int *)extraout_ECX[0x4c];
    if ((char)piVar3[0x5a] != '\x01') {
      *(undefined1 *)(piVar3 + 0x5a) = 1;
      (**(code **)(*piVar3 + 0x168))();
    }
    *(undefined4 *)(extraout_ECX[0x4b] + 0xf8) = 1;
    FUN_005e46f0(1);
    piVar3 = (int *)extraout_ECX[0x4b];
    if ((char)piVar3[0x5a] != '\x01') {
      *(undefined1 *)(piVar3 + 0x5a) = 1;
      (**(code **)(*piVar3 + 0x168))();
    }
    *(undefined4 *)(extraout_ECX[0x52] + 0xf8) = 0;
    *(undefined4 *)(extraout_ECX[0x53] + 0xf8) = 0;
    *(undefined4 *)(extraout_ECX[0x56] + 0xf8) = 0;
    piVar3 = (int *)extraout_ECX[0x56];
    if ((char)piVar3[0x5a] != '\0') {
      *(undefined1 *)(piVar3 + 0x5a) = 0;
      (**(code **)(*piVar3 + 0x168))();
    }
    FUN_005e4b90(1);
    *(undefined4 *)(extraout_ECX[0x57] + 0xf8) = 0;
    FUN_005e4b90(1);
    FUN_005e4817(0,s_UI_CAC_CycleParts_006cd6c0,0,0);
    FUN_005e4817(0,s_UI_CAC_CycleParts_006cd6c0,0,0);
    FUN_005e4817(0,s_UI_CAC_Cyclehead_006cd6ac,0,0);
    FUN_005e4817(0,s_UI_CAC_Cyclehead_006cd6ac,0,0);
    FUN_004a8012(0,0,1);
    FUN_004a7da6(1,0,1);
    pvVar7 = operator_new(0x208);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_0056cd4f(_DAT_00667678);
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x61] = iVar8;
    if (iVar8 != 0) {
      FUN_004cb21d(*piVar14 + DAT_006f5000,extraout_ECX[0x44] + DAT_006f5004);
      FUN_004cb1a2(100,0xdc);
      *(undefined4 *)(extraout_ECX[0x61] + 0x150) = 0;
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x61]);
      (**(code **)(*(int *)extraout_ECX[0x61] + 0x90))(0x2000,1);
    }
    FUN_00547de6(unaff_EBP + -0x13c);
    pvVar7 = operator_new(0x1b8);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005f179a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x45] = iVar8;
    uVar6 = DAT_006f2a9c;
    if (iVar8 != 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(DAT_006e486c + 0x34);
      FUN_005f42c3(uVar6);
      FUN_005f4336(DAT_006f2a48);
      FUN_005f4256(4,DAT_006f2a48,DAT_006f2a48);
      iVar9 = *piVar14 + DAT_006f4fd8;
      iVar8 = extraout_ECX[0x44] + _DAT_006f4fdc;
      *(int *)(unaff_EBP + -0x2c) = DAT_006f4fe0 + iVar9;
      *(int *)(unaff_EBP + -0x24) = iVar9 + DAT_006f4fe8;
      *(int *)(unaff_EBP + -0x28) = DAT_006f4fe4 + iVar8;
      (**(code **)(*(int *)extraout_ECX[0x45] + 0x60))
                (*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28),
                 *(undefined4 *)(unaff_EBP + -0x24),iVar8 + DAT_006f4fec);
      *(int *)(extraout_ECX[0x45] + 8) = extraout_ECX[0x45];
      FUN_005f42b6(1);
      if (*(char *)(DAT_006e486c + 100) == '\x0f') {
        uVar6 = 0x10;
      }
      else {
        uVar6 = 0x19;
      }
      FUN_005f435f(uVar6);
      FUN_005f4294(1);
      (**(code **)(*(int *)extraout_ECX[0x45] + 0x90))(0x2000,0);
      FUN_005f42a1(0);
      FUN_005d4bbf(s_UI_NHood_error_006cd69c);
      FUN_005f489f(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x45]);
      FUN_00436e16();
    }
    pvVar7 = operator_new(0x1b8);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 0x11;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005f179a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x46] = iVar8;
    uVar6 = DAT_006f2a9c;
    if (iVar8 != 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(DAT_006e486c + 0x34);
      FUN_005f42c3(uVar6);
      FUN_005f4336(DAT_006f2a48);
      FUN_005f4256(4,DAT_006f2a48,DAT_006f2a48);
      FUN_005f42b6(0xffffffff);
      iVar9 = *piVar14 + DAT_006f4fc0;
      iVar8 = extraout_ECX[0x44] + DAT_006f4fc4;
      *(int *)(unaff_EBP + -0x2c) = DAT_006f4fc8 + iVar9;
      *(int *)(unaff_EBP + -0x24) = iVar9 + DAT_006f4fd0;
      *(int *)(unaff_EBP + -0x28) = DAT_006f4fcc + iVar8;
      (**(code **)(*(int *)extraout_ECX[0x46] + 0x60))
                (*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28),
                 *(undefined4 *)(unaff_EBP + -0x24),iVar8 + DAT_006f4fd4);
      *(int *)(extraout_ECX[0x46] + 8) = extraout_ECX[0x46];
      FUN_005f4294(0);
      (**(code **)(*(int *)extraout_ECX[0x46] + 0x90))(0x2000,0);
      FUN_005f42a1(0);
      FUN_005f435f(0x800);
      FUN_005d4bbf(s_UI_NHood_error_006cd69c);
      FUN_005f489f(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x46]);
    }
    pvVar7 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 0x12;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005e372a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x77] = iVar8;
    if (iVar8 != 0) {
      FUN_005e4071(DAT_006f2aa4);
      (**(code **)(*(int *)extraout_ECX[0x77] + 0x19c))(0,4,1);
      puVar12 = (undefined4 *)FUN_004df599(unaff_EBP + -0x2c,piVar14);
      (**(code **)(*(int *)extraout_ECX[0x77] + 0x60))(*puVar12,puVar12[1],puVar12[2],puVar12[3]);
      iVar8 = extraout_ECX[0x77];
      *(undefined4 *)(iVar8 + 0x160) = 1;
      *(int *)(iVar8 + 0x128) = *(int *)(iVar8 + 0x88) - *(int *)(iVar8 + 0x80);
      *(undefined4 *)(iVar8 + 0x11c) = 0;
      *(undefined4 *)(iVar8 + 0x120) = 0;
      *(int *)(iVar8 + 0x124) = *(int *)(iVar8 + 0x84) - *(int *)(iVar8 + 0x7c);
      *(undefined4 *)(iVar8 + 0x164) = 1;
      uVar6 = FUN_004705f2(0x1c,0xffffffff);
      FUN_005d4956(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      FUN_005dd9c8(unaff_EBP + -0x28);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      (**(code **)(*(int *)extraout_ECX[0x77] + 0x90))(0x400,0);
      (**(code **)(*(int *)extraout_ECX[0x77] + 0x90))(0x2000,1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x77]);
    }
    if (extraout_ECX[0x47] == -1) {
      iVar8 = FUN_004e1df3();
      extraout_ECX[0x47] = iVar8;
      if (iVar8 != -1) goto LAB_00546b2e;
      FUN_004f6994(s_MakeNewPerson_failed__006cd67c,s_Sorry_006cd694,0,0);
LAB_00546ac1:
      *(undefined1 *)(unaff_EBP + -0x19) = 0;
    }
    else {
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      uVar6 = FUN_005d49d6();
      uVar11 = FUN_004096c2(uVar6);
      uVar6 = FUN_005b86cf(uVar11,uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      FUN_004e9c34(extraout_ECX[0x47],uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      FUN_005b8770();
      if (extraout_ECX[0x45] != 0) {
        FUN_005f436c(*(undefined4 *)(unaff_EBP + -0x3c),0,1);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
LAB_00546b2e:
      FUN_005a5631(0x1453,extraout_ECX + 0x62,4);
      if (extraout_ECX[0x47] == -1) goto LAB_00546ac1;
      if ((char)extraout_ECX[0x48] == '\0') {
        uVar13 = 0;
        if (extraout_ECX[0x59] - extraout_ECX[0x58] >> 2 != 0) {
          do {
            iVar8 = FUN_004ea79e(extraout_ECX[0x47]);
            *(int *)(unaff_EBP + -0x10) = (int)*(short *)(iVar8 + (&DAT_0066c600)[uVar13] * 2) / 100
            ;
            FUN_005630c6(*(undefined4 *)(unaff_EBP + -0x10));
            extraout_ECX[0x49] = extraout_ECX[0x49] - *(int *)(unaff_EBP + -0x10);
            uVar13 = uVar13 + 1;
          } while (uVar13 < (uint)(extraout_ECX[0x59] - extraout_ECX[0x58] >> 2));
        }
      }
      FUN_004ea53c(extraout_ECX[0x47],*(char *)((int)extraout_ECX + 0x121) == '\0');
      if ((char)extraout_ECX[0x48] == '\0') {
        iVar8 = FUN_004ead84(extraout_ECX[0x47]);
        extraout_ECX[0x5c] = iVar8;
        iVar8 = FUN_004eacd3(extraout_ECX[0x47]);
        extraout_ECX[0x5d] = iVar8;
      }
      else {
        extraout_ECX[0x5c] = 0;
        extraout_ECX[0x5d] = 0;
      }
      *(undefined1 *)(extraout_ECX + 0x4a) = 0;
      FUN_004eada1(extraout_ECX[0x47],extraout_ECX[0x5c]);
      FUN_004eacf0(extraout_ECX[0x47],extraout_ECX[0x5d]);
      FUN_0056d052(extraout_ECX[0x47]);
      FUN_00547754();
      if ((char)extraout_ECX[0x48] == '\0') {
        puVar12 = (undefined4 *)FUN_004e9bbd(extraout_ECX[0x47]);
        FUN_005f436c(*puVar12,0,1);
      }
      else {
        uVar13 = 0;
        if (extraout_ECX[0x59] - extraout_ECX[0x58] >> 2 != 0) {
          do {
            FUN_005630c6(0);
            uVar13 = uVar13 + 1;
          } while (uVar13 < (uint)(extraout_ECX[0x59] - extraout_ECX[0x58] >> 2));
        }
      }
      FUN_00547754();
      iVar8 = DAT_006fe8f4;
      *(undefined1 *)(unaff_EBP + -0x19) = 1;
      extraout_ECX[0x69] = *(int *)(iVar8 + 0x1fc);
      *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  uVar5 = *(undefined1 *)(unaff_EBP + -0x19);
LAB_00546cf1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

