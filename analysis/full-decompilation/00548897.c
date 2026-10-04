
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00548897(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int *extraout_ECX;
  uint uVar11;
  int iVar12;
  int *piVar13;
  int unaff_EBP;
  int *piVar14;
  
  FUN_00634c24();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 == '\0') {
    extraout_ECX[0x41] = 3;
    extraout_ECX[0x19] = DAT_006f2a68;
    FUN_005a5631(0x14b5,extraout_ECX + 0x6c,4);
    piVar14 = (int *)extraout_ECX[0x6c];
    uVar5 = 0;
    if (piVar14 != (int *)0x0) {
      (**(code **)(*piVar14 + 0x68))(DAT_006f2a64);
    }
    FUN_005a5631(0x139e,extraout_ECX + 0x42,4);
    iVar8 = extraout_ECX[0x42];
    if (iVar8 == 0) {
      extraout_ECX[0x43] = 0;
      extraout_ECX[0x44] = 0;
    }
    else {
      uVar11 = *(uint *)(iVar8 + 0x1c);
      iVar12 = extraout_ECX[0x21];
      iVar2 = extraout_ECX[0x22];
      iVar3 = extraout_ECX[0x1f];
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar8 + 0x20);
      if (uVar11 < (uint)(iVar12 - iVar3)) {
        uVar11 = (iVar12 - iVar3) - uVar11 >> 1;
      }
      else {
        uVar11 = 0;
      }
      uVar1 = *(uint *)(unaff_EBP + -0x18);
      extraout_ECX[0x43] = uVar11;
      if (uVar1 < (uint)(iVar2 - extraout_ECX[0x20])) {
        uVar11 = (uint)((iVar2 - extraout_ECX[0x20]) - *(int *)(unaff_EBP + -0x18)) >> 1;
      }
      else {
        uVar11 = 0;
      }
      extraout_ECX[0x44] = uVar11;
    }
    piVar14 = extraout_ECX + 0x43;
    FUN_005e8d11();
    (**(code **)(*extraout_ECX + 0x90))(0x2000,1);
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xdc) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar6 = FUN_0041532c(9,unaff_EBP + -0xdc,0);
    cVar4 = FUN_004fff98(0x81,uVar6);
    if (cVar4 != '\0') {
      pvVar7 = operator_new(0x1b8);
      *(void **)(unaff_EBP + -0x18) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar7 == (void *)0x0) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_005f179a();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      extraout_ECX[0x45] = iVar8;
      if (iVar8 != 0) {
        FUN_005f42c3(DAT_006f2a9c);
        FUN_005f4336(DAT_006f2a48);
        iVar12 = *piVar14 + DAT_006f5040;
        iVar8 = extraout_ECX[0x44] + _DAT_006f5044;
        *(int *)(unaff_EBP + -0x3c) = DAT_006f5030 + iVar12;
        *(int *)(unaff_EBP + -0x34) = iVar12 + DAT_006f5038;
        *(int *)(unaff_EBP + -0x38) = DAT_006f5034 + iVar8;
        (**(code **)(*(int *)extraout_ECX[0x45] + 0x60))
                  (*(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x38),
                   *(undefined4 *)(unaff_EBP + -0x34),iVar8 + DAT_006f503c);
        *(int *)(extraout_ECX[0x45] + 8) = extraout_ECX[0x45];
        FUN_005f42b6(1);
        FUN_005d4bbf(s_UI_NHood_error_006cd69c);
        FUN_005d4bbf(s_UI_NHood_error_006cd69c);
        FUN_005f489f(1);
        FUN_005f4256((-(*(int *)(DAT_006e486c + 0x34) != 1) & 0x20U) + 5,DAT_006f2a48,DAT_006f2a48);
        FUN_005f435f(0x18);
        FUN_005f4294(1);
        (**(code **)(*(int *)extraout_ECX[0x45] + 0x90))(0x2000,0);
        FUN_005f42a1(0);
        FUN_005f4992(1);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x45]);
      }
      pvVar7 = operator_new(0x110);
      *(void **)(unaff_EBP + -0x18) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (pvVar7 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
      else {
        uVar6 = FUN_005e9913();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      if (*(int *)(unaff_EBP + -0x10) != 0) {
        (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0xd4) + 0x18))(DAT_006f2aa4);
        (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0xd4) + 0xc))(2,0);
        uVar6 = **(undefined4 **)(unaff_EBP + -0x10);
        uVar9 = FUN_004705f2(0xd,0xffffffff);
        *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
        iVar8 = *(int *)(unaff_EBP + -0x10);
        (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x1a0))(uVar9);
        (*(code *)**(undefined4 **)(iVar8 + 0xd4))();
        FUN_004cb21d((*(int *)(*(int *)(unaff_EBP + -0x10) + 0x7c) -
                     *(int *)(*(int *)(unaff_EBP + -0x10) + 0x84)) + *piVar14 + -0x14 + DAT_006f5040
                     ,extraout_ECX[0x44] + _DAT_006f5044);
        (**(code **)(*(int *)(iVar8 + 0xd4) + 0x14))(0);
        (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x10));
      }
      *(undefined4 *)(unaff_EBP + -0x18) = 8;
      *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0x49;
      do {
        pvVar7 = operator_new(0x19c);
        *(void **)(unaff_EBP + -0x14) = pvVar7;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (pvVar7 == (void *)0x0) {
          piVar13 = (int *)0x0;
        }
        else {
          *(int *)(unaff_EBP + -0x1c) = extraout_ECX[0x6a];
          FUN_005e372a();
          piVar13 = *(int **)(unaff_EBP + -0x14);
          piVar13[0x65] = *(int *)(unaff_EBP + -0x1c);
          *piVar13 = (int)&PTR_FUN_0066fea8;
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        **(undefined4 **)(unaff_EBP + -0x10) = piVar13;
        if (piVar13 != (int *)0x0) {
          (**(code **)(*piVar13 + 0x60))(0,0,0x55,0x69);
          FUN_005e4a66(1);
          (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + -0x10) + 0x90))(0x2000,1);
          (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + -0x10) + 0x90))(0x400,1);
          (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + -0x10) + 0x90))(0x1000,1);
          (**(code **)(*extraout_ECX + 0x20))(**(undefined4 **)(unaff_EBP + -0x10));
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
        piVar13 = (int *)(unaff_EBP + -0x18);
        *piVar13 = *piVar13 + -1;
      } while (*piVar13 != 0);
      *(undefined4 *)(unaff_EBP + -0x60) = 0;
      *(undefined4 *)(unaff_EBP + -0x5c) = 0;
      *(undefined4 *)(unaff_EBP + -0x58) = 0;
      *(undefined4 *)(unaff_EBP + -0x54) = 0;
      *(undefined4 *)(unaff_EBP + -0x50) = 0;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x48) = 0;
      *(undefined4 *)(unaff_EBP + -0x44) = 0;
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
      iVar8 = unaff_EBP + -0x3c;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      piVar13 = piVar14;
      FUN_004df599(unaff_EBP + -0x70,&DAT_006f5028);
      puVar10 = (undefined4 *)FUN_004df599(iVar8,piVar13);
      uVar6 = puVar10[1];
      *(undefined4 *)(unaff_EBP + -0x60) = *puVar10;
      *(undefined4 *)(unaff_EBP + -0x5c) = uVar6;
      *(undefined4 *)(unaff_EBP + -0x50) = puVar10[2];
      *(undefined4 *)(unaff_EBP + -0x4c) = puVar10[3];
      *(undefined4 *)(unaff_EBP + -0x58) = 0x78;
      *(undefined4 *)(unaff_EBP + -0x54) = 0x8c;
      FUN_004ebf01(extraout_ECX + 0x49,8);
      FUN_00471655(unaff_EBP + -0x2c);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      *(undefined4 **)(unaff_EBP + -0x18) = &DAT_006f5048;
      *(undefined4 **)(unaff_EBP + -0x1c) = &DAT_0066fcc0;
      *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0x52;
      do {
        if (*(int *)(unaff_EBP + -0x1c) < 0x66fccc) {
          pvVar7 = operator_new(0x194);
          *(void **)(unaff_EBP + -0x14) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 6;
          if (pvVar7 == (void *)0x0) {
            iVar8 = 0;
          }
          else {
            iVar8 = FUN_005e372a();
          }
          *(undefined1 *)(unaff_EBP + -4) = 5;
          **(int **)(unaff_EBP + -0x10) = iVar8;
          if (iVar8 != 0) {
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            FUN_005a5631(**(undefined4 **)(unaff_EBP + -0x1c),unaff_EBP + -0x14,4);
            if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
              (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
              (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + -0x10) + 0x19c))
                        (*(undefined4 *)(unaff_EBP + -0x14),4,1);
              *(undefined1 *)(**(int **)(unaff_EBP + -0x10) + 0x16b) = 1;
            }
            FUN_004cb21d(*piVar14 + **(int **)(unaff_EBP + -0x18),
                         (*(int **)(unaff_EBP + -0x18))[1] + extraout_ECX[0x44]);
            (**(code **)(*extraout_ECX + 0x20))(**(undefined4 **)(unaff_EBP + -0x10));
            uVar6 = FUN_0046fc7a();
            FUN_005d4956(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            FUN_005dd9c8(unaff_EBP + -0x6c);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            FUN_005b8770();
            (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + -0x10) + 0x90))(0x2000,1);
          }
        }
        else {
          pvVar7 = operator_new(0x1ac);
          *(void **)(unaff_EBP + -0x14) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 8;
          if (pvVar7 == (void *)0x0) {
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
          }
          else {
            uVar6 = FUN_005f7201(extraout_ECX[0x6c]);
            *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
          }
          *(undefined1 *)(unaff_EBP + -4) = 5;
          if (*(int *)(unaff_EBP + -0x14) != 0) {
            FUN_004cb1a2(200,*(undefined4 *)(extraout_ECX[0x6c] + 0x20));
            iVar8 = **(int **)(unaff_EBP + -0x18);
            iVar12 = *piVar14;
            *(int *)(unaff_EBP + -0x20) =
                 *(int *)(extraout_ECX[0x6c] + 0x20) / 2 +
                 (*(int **)(unaff_EBP + -0x18))[1] + extraout_ECX[0x44];
            *(int *)(unaff_EBP + -0x24) = iVar8 + iVar12;
            FUN_005f78d8(unaff_EBP + -0x24);
            (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x90))(0x2000,1);
            uVar6 = FUN_0046fc7a();
            FUN_005d4956(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x9c))(unaff_EBP + -0x38);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            FUN_005b8770();
            (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
            **(undefined4 **)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x14);
          }
        }
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 8;
        FUN_005c11ce();
      } while (*(int *)(unaff_EBP + -0x1c) < 0x66fcd4);
      FUN_005e4b90(1);
      FUN_005e4b90(1);
      FUN_005e4b90(1);
      FUN_005e4b90(1);
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      uVar6 = FUN_0046fc7a();
      FUN_005d4bbf(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      uVar6 = FUN_0046fc7a();
      FUN_005d4bbf(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      uVar6 = FUN_0046fc7a();
      FUN_005d4bbf(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      uVar6 = FUN_0046fc7a();
      FUN_005d4bbf(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0042004f();
      pvVar7 = operator_new(0x110);
      *(void **)(unaff_EBP + -0x18) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      if (pvVar7 == (void *)0x0) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_005e9913();
      }
      *(undefined1 *)(unaff_EBP + -4) = 5;
      extraout_ECX[0x6d] = iVar8;
      if (iVar8 != 0) {
        (**(code **)(*(int *)(iVar8 + 0xd4) + 0x18))(DAT_006f2ab4);
        iVar8 = extraout_ECX[0x1f];
        *(int *)(unaff_EBP + -0x34) = extraout_ECX[0x21];
        *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) - iVar8;
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
        iVar8 = (**(code **)(**(int **)(extraout_ECX[0x6d] + 0xd8) + 0x58))();
        (**(code **)(*(int *)extraout_ECX[0x6d] + 0x60))
                  (*(undefined4 *)(unaff_EBP + -0x3c),extraout_ECX[0x44] + 6,
                   *(undefined4 *)(unaff_EBP + -0x34),iVar8 + 6 + extraout_ECX[0x44]);
        iVar8 = *(int *)extraout_ECX[0x6d];
        uVar6 = FUN_004705f2(10,0xffffffff);
        (**(code **)(iVar8 + 0x1a0))(uVar6);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x6d]);
        (**(code **)(*(int *)(extraout_ECX[0x6d] + 0xd4) + 0x1c))(2);
        (**(code **)(*(int *)(extraout_ECX[0x6d] + 0xd4) + 0x14))(0);
      }
      uVar6 = FUN_004705f2(0xf,0xffffffff);
      FUN_005d4bbf(uVar6);
      uVar6 = FUN_004705f2(0xe,0xffffffff);
      FUN_005d4bbf(uVar6);
      FUN_00549a98();
      FUN_00436e16();
      iVar8 = DAT_006fe8f4;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      extraout_ECX[0x6b] = *(int *)(iVar8 + 0x1fc);
      *(int **)(DAT_006fe8f4 + 0x1fc) = extraout_ECX;
      FUN_0042004f();
      uVar5 = 1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  else {
    uVar5 = FUN_005e8d11();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

