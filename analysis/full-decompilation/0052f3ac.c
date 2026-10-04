
void FUN_0052f3ac(void)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar9;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    cVar1 = FUN_004cff80();
    if (cVar1 == '\0') {
      FUN_005a5631(0x1325,extraout_ECX + 0x35,4);
      uVar9 = 0x1338;
    }
    else {
      FUN_005a5631(0x1324,extraout_ECX + 0x35,4);
      uVar9 = 0x1337;
    }
    FUN_005a5631(uVar9,extraout_ECX + 0x36,4);
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    FUN_005a5631(0x1329,unaff_EBP + -0x30,4);
    FUN_005a5e48(*(undefined4 *)(unaff_EBP + -0x30));
    FUN_005a5631(0x1326,unaff_EBP + -0x30,4);
    FUN_005a5e48(*(undefined4 *)(unaff_EBP + -0x30));
    cVar1 = FUN_005a5e72();
    if (cVar1 != '\0') {
      piVar2 = (int *)FUN_004096c2();
      (**(code **)(*piVar2 + 0x68))(DAT_006f2a64);
    }
    (**(code **)(*extraout_ECX + 0x60))(0,0,0x1ab,100);
    *(undefined4 *)(unaff_EBP + -100) = DAT_006f2a94;
    *(undefined4 *)(unaff_EBP + -0x60) = DAT_006f2a90;
    cVar1 = FUN_004cff80();
    iVar5 = DAT_006e486c;
    if (cVar1 != '\0') {
      uVar3 = 0;
      do {
        cVar1 = *(char *)(iVar5 + 100);
        if (cVar1 == '\x14') {
          *(undefined4 *)((int)&DAT_006f43d0 + uVar3) = *(undefined4 *)((int)&DAT_006f4340 + uVar3);
          uVar9 = *(undefined4 *)((int)&DAT_006f4344 + uVar3);
        }
        else if (cVar1 == '\x13') {
          *(undefined4 *)((int)&DAT_006f43d0 + uVar3) = *(undefined4 *)(&DAT_006f4370 + uVar3);
          uVar9 = *(undefined4 *)(&DAT_006f4374 + uVar3);
        }
        else if (cVar1 == '\x12') {
          *(undefined4 *)((int)&DAT_006f43d0 + uVar3) = *(undefined4 *)(&DAT_006f4310 + uVar3);
          uVar9 = *(undefined4 *)(&DAT_006f4314 + uVar3);
        }
        else if (cVar1 == '\x0f') {
          *(undefined4 *)((int)&DAT_006f43d0 + uVar3) = *(undefined4 *)(&DAT_006f42e0 + uVar3);
          uVar9 = *(undefined4 *)(&DAT_006f42e4 + uVar3);
        }
        else {
          *(undefined4 *)((int)&DAT_006f43d0 + uVar3) = *(undefined4 *)(&DAT_006f43a0 + uVar3);
          uVar9 = *(undefined4 *)(&DAT_006f43a4 + uVar3);
        }
        *(undefined4 *)((int)&DAT_006f43d4 + uVar3) = uVar9;
        *(undefined4 *)((int)&DAT_006f42b0 + uVar3) = *(undefined4 *)((int)&DAT_006f4280 + uVar3);
        *(undefined4 *)((int)&DAT_006f42b4 + uVar3) = *(undefined4 *)((int)&DAT_006f4284 + uVar3);
        uVar3 = uVar3 + 8;
      } while (uVar3 < 0x30);
      uVar3 = 0;
      do {
        if (*(char *)(iVar5 + 100) == '\x13') {
          *(undefined4 *)((int)&DAT_006f4220 + uVar3) = *(undefined4 *)((int)&DAT_006f41e0 + uVar3);
          uVar9 = *(undefined4 *)((int)&DAT_006f41e4 + uVar3);
        }
        else {
          *(undefined4 *)((int)&DAT_006f4220 + uVar3) = *(undefined4 *)(&DAT_006f4200 + uVar3);
          uVar9 = *(undefined4 *)(&DAT_006f4204 + uVar3);
        }
        *(undefined4 *)((int)&DAT_006f4224 + uVar3) = uVar9;
        *(undefined4 *)((int)&DAT_006f41c0 + uVar3) = *(undefined4 *)((int)&DAT_006f41a0 + uVar3);
        *(undefined4 *)((int)&DAT_006f41c4 + uVar3) = *(undefined4 *)((int)&DAT_006f41a4 + uVar3);
        uVar3 = uVar3 + 8;
      } while (uVar3 < 0x20);
    }
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xd0) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_004fff98(0x88,&DAT_006c265c,unaff_EBP + -0xd0,0);
    if (cVar1 != '\0') {
      FUN_00471655(unaff_EBP + -0x38);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046fc87(unaff_EBP + -0x18,0);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar9 = FUN_0046fc7a();
      FUN_005d4bbf(uVar9);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      *(undefined4 **)(unaff_EBP + -0x28) = &DAT_006f43d0;
      do {
        pvVar4 = operator_new(0x1ac);
        *(void **)(unaff_EBP + -0x14) = pvVar4;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (pvVar4 == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_0052c6db();
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(int *)(unaff_EBP + -0x10) = iVar5;
        if (iVar5 != 0) {
          uVar9 = FUN_0046fc7a();
          FUN_005d4956(uVar9);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x9c))(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x60))(0,0,0x3e,0x10);
          FUN_004cb21d(**(undefined4 **)(unaff_EBP + -0x28),(*(undefined4 **)(unaff_EBP + -0x28))[1]
                      );
          *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf8) = 1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf4) = 1;
          iVar5 = *(int *)(unaff_EBP + -0x10);
          *(undefined4 *)(iVar5 + 0x160) = 1;
          *(undefined4 *)(iVar5 + 0x11c) = 0;
          *(undefined4 *)(iVar5 + 0x120) = 0;
          *(undefined4 *)(iVar5 + 0x124) = 0x3e;
          *(undefined4 *)(iVar5 + 0x128) = 0x10;
          *(undefined4 *)(iVar5 + 0x164) = 2;
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x19c))(0,4,0);
          FUN_005e4a3a(1);
          FUN_005e4071(*(undefined4 *)(unaff_EBP + -0x60));
          (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x10));
          FUN_0052d5d9(unaff_EBP + -0x10);
        }
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 8;
        FUN_005c11ce();
      } while (*(int *)(unaff_EBP + -0x28) < 0x6f4400);
      FUN_0046fc87(unaff_EBP + -0x18,0);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      uVar9 = FUN_0046fc7a();
      FUN_005d4bbf(uVar9);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x18,0);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      uVar9 = FUN_0046fc7a();
      FUN_005d4bbf(uVar9);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x18,0);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      uVar9 = FUN_0046fc7a();
      FUN_005d4bbf(uVar9);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x18,0);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      uVar9 = FUN_0046fc7a();
      FUN_005d4bbf(uVar9);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      cVar1 = FUN_004fff98(0x89,&DAT_006c265c,unaff_EBP + -0xd0,0);
      if (cVar1 != '\0') {
        FUN_00471655(unaff_EBP + -0x18);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        *(undefined4 *)(unaff_EBP + -0x1c) = 6;
        do {
          FUN_0046fc87(unaff_EBP + -0x40,0);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          uVar9 = FUN_0046fc7a();
          FUN_005d4956(uVar9);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          FUN_004054fa(unaff_EBP + -0x5c);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_0042004f();
          FUN_0046fc87(unaff_EBP + -0x2c,0);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          uVar9 = FUN_0046fc7a();
          FUN_005d4956(uVar9);
          *(undefined1 *)(unaff_EBP + -4) = 0xd;
          FUN_004054fa(unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_0042004f();
          piVar2 = (int *)(unaff_EBP + -0x1c);
          *piVar2 = *piVar2 + -1;
        } while (*piVar2 != 0);
        *(undefined4 *)(unaff_EBP + -0x1c) = 4;
        do {
          FUN_0046fc87(unaff_EBP + -0x40,0);
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          uVar9 = FUN_0046fc7a();
          FUN_005d4956(uVar9);
          *(undefined1 *)(unaff_EBP + -4) = 0xf;
          FUN_004054fa(unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_0042004f();
          FUN_0046fc87(unaff_EBP + -0x2c,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          uVar9 = FUN_0046fc7a();
          FUN_005d4956(uVar9);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_004054fa(unaff_EBP + -0x5c);
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_0042004f();
          piVar2 = (int *)(unaff_EBP + -0x1c);
          *piVar2 = *piVar2 + -1;
        } while (*piVar2 != 0);
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x12;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x13;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x14;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x15;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x16;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x17;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x18;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x19;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x1a;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x1b;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x1c;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x20,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x1d;
        uVar9 = FUN_0046fc7a();
        FUN_005d4bbf(uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_0042004f();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
      }
      pvVar4 = operator_new(0x84);
      *(void **)(unaff_EBP + -0x14) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 0x1e;
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00510166(*(undefined4 *)extraout_ECX[0x41],*(undefined4 *)extraout_ECX[0x44],0,0
                             ,0,0,0,0,0);
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      extraout_ECX[0x4d] = iVar5;
      if (iVar5 != 0) {
        FUN_00503993(&PTR_LAB_006c2990);
      }
      iVar5 = 0;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      do {
        if (iVar5 == 2) {
          pvVar4 = operator_new(0x1ac);
          *(void **)(unaff_EBP + -0x14) = pvVar4;
          *(undefined1 *)(unaff_EBP + -4) = 0x20;
          if (pvVar4 == (void *)0x0) goto LAB_0052fc9c;
          FUN_0052c6db();
          puVar6 = *(undefined4 **)(unaff_EBP + -0x14);
          *puVar6 = &PTR_FUN_0066e1a8;
        }
        else {
          pvVar4 = operator_new(0x1ac);
          *(void **)(unaff_EBP + -0x14) = pvVar4;
          *(undefined1 *)(unaff_EBP + -4) = 0x1f;
          if (pvVar4 == (void *)0x0) {
LAB_0052fc9c:
            puVar6 = (undefined4 *)0x0;
          }
          else {
            puVar6 = (undefined4 *)FUN_0052c6db();
          }
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(undefined4 **)(unaff_EBP + -0x10) = puVar6;
        if (puVar6 != (undefined4 *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x28) = 0;
          FUN_005e4a3a(1);
          *(undefined4 *)(unaff_EBP + -0x14) = (&DAT_006f41c4)[iVar5 * 2];
          *(undefined4 *)(unaff_EBP + -0x3c) = (&DAT_006f41c0)[iVar5 * 2];
          *(undefined4 *)(unaff_EBP + -0x50) = 0;
          *(undefined4 *)(unaff_EBP + -0x4c) = 0;
          if (iVar5 == 0) {
            iVar5 = **(int **)(unaff_EBP + -0x10);
            uVar9 = FUN_004096c2(4,0x16);
            (**(code **)(iVar5 + 0x19c))(uVar9);
            iVar5 = *(int *)(unaff_EBP + -0x1c);
          }
          else {
            FUN_005a5631((&DAT_0066dfdc)[iVar5],unaff_EBP + -0x28,4);
            (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x19c))
                      (*(undefined4 *)(unaff_EBP + -0x28),4,1);
            *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x16b) = 1;
          }
          FUN_005e4071(*(undefined4 *)(unaff_EBP + -100 + (&DAT_006cccbc)[iVar5] * 4));
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x60))
                    (0,0,*(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x14));
          FUN_004cb21d((&DAT_006f4220)[iVar5 * 2],(&DAT_006f4224)[iVar5 * 2]);
          *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf8) = 1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf4) = 1;
          FUN_005e4a3a(1);
          if (iVar5 == 0) {
            *(int *)(unaff_EBP + -0x4c) =
                 *(int *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0xd8) + 0x20) / 0x16;
            piVar2 = (int *)FUN_005e40a5();
            iVar7 = (**(code **)(*piVar2 + 0x58))();
            FUN_004ec1a7(*(int *)(unaff_EBP + -0x4c) + iVar7 * 2);
LAB_0052ff24:
            iVar7 = *(int *)(unaff_EBP + -0x10);
            *(undefined4 *)(iVar7 + 0x160) = 1;
            if (*(int *)(iVar7 + 0x160) != 0) {
              *(undefined4 *)(iVar7 + 0x11c) = *(undefined4 *)(unaff_EBP + -0x50);
              *(undefined4 *)(iVar7 + 0x120) = *(undefined4 *)(unaff_EBP + -0x4c);
              *(undefined4 *)(iVar7 + 0x124) = *(undefined4 *)(unaff_EBP + -0x3c);
              *(undefined4 *)(iVar7 + 0x128) = *(undefined4 *)(unaff_EBP + -0x14);
              *(undefined4 *)(iVar7 + 0x164) = 0;
            }
          }
          else {
            if (iVar5 == 3) {
              piVar2 = (int *)FUN_005e40a5();
              uVar9 = (**(code **)(*piVar2 + 0x58))();
              FUN_004ec1a7(uVar9);
              *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x173) = 0;
              if ((extraout_ECX[0x3b] - extraout_ECX[0x3a] & 0xfffffffcU) != 0) {
                iVar7 = *(int *)(extraout_ECX[0x3b] + -4);
                FUN_004cb21d(*(undefined4 *)(iVar7 + 0x7c),
                             *(int *)(iVar7 + 0x80) +
                             (*(int *)(iVar7 + 0x88) - *(int *)(iVar7 + 0x80)));
              }
              (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x68))(DAT_006f2a64);
              goto LAB_0052ff24;
            }
            *(int *)(unaff_EBP + -0x50) =
                 (*(int *)(*(int *)(unaff_EBP + -0x28) + 0x1c) -
                 *(int *)(*(int *)(unaff_EBP + -0x28) + 0x14)) /
                 *(int *)(*(int *)(unaff_EBP + -0x10) + 0xf0) + 3;
            piVar2 = (int *)FUN_005e40a5();
            uVar9 = (**(code **)(*piVar2 + 0x58))();
            FUN_004ec1a7(uVar9);
            if (iVar5 == 2) {
              if (*(char *)(DAT_006e486c + 100) == '\x13') {
                *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x144) = 0;
                *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x148) = 8;
              }
              else {
                *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x144) = 0;
                *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x148) = 0;
              }
              *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x173) = 0;
            }
            else {
              iVar7 = *(int *)(unaff_EBP + -0x10);
              iVar8 = *(int *)(*(int *)(unaff_EBP + -0x28) + 0x20);
              if (*(char *)(DAT_006e486c + 100) == '\x13') {
                iVar7 = ((*(int *)(iVar7 + 0x88) - *(int *)(iVar7 + 0x80)) - iVar8) / 2 + 3;
              }
              else {
                iVar7 = ((*(int *)(iVar7 + 0x88) - *(int *)(iVar7 + 0x80)) - iVar8) / 2;
              }
              *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x144) = 0;
              *(int *)(*(int *)(unaff_EBP + -0x10) + 0x148) = iVar7;
            }
            if ((extraout_ECX[0x3b] - extraout_ECX[0x3a] & 0xfffffffcU) != 0) {
              iVar7 = *(int *)(extraout_ECX[0x3b] + -4);
              FUN_004cb21d(*(undefined4 *)(iVar7 + 0x7c),
                           *(int *)(iVar7 + 0x80) +
                           (*(int *)(iVar7 + 0x88) - *(int *)(iVar7 + 0x80)));
            }
            if (iVar5 != 2) goto LAB_0052ff24;
            piVar2 = (int *)FUN_005e40a5();
            iVar8 = (**(code **)(*piVar2 + 0x58))();
            iVar7 = *(int *)(unaff_EBP + -0x10);
            *(undefined4 *)(iVar7 + 0x160) = 1;
            if (*(int *)(iVar7 + 0x160) != 0) {
              *(undefined4 *)(iVar7 + 0x11c) = *(undefined4 *)(unaff_EBP + -0x50);
              uVar9 = *(undefined4 *)(unaff_EBP + -0x3c);
              *(undefined4 *)(iVar7 + 0x120) = 0;
              *(undefined4 *)(iVar7 + 0x124) = uVar9;
              iVar5 = *(int *)(unaff_EBP + -0x1c);
              *(int *)(iVar7 + 0x128) = iVar8 << 1;
              *(undefined4 *)(iVar7 + 0x164) = 0;
            }
          }
          (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x10));
          FUN_0052d5d9(unaff_EBP + -0x10);
        }
        iVar5 = iVar5 + 1;
        *(int *)(unaff_EBP + -0x1c) = iVar5;
      } while (iVar5 < 4);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  if (*(char *)(DAT_006e486c + 100) == '\x13') {
    FUN_004cb21d(*(int *)(*(int *)(extraout_ECX[0x3a] + 0xc) + 0x7c) + -3,
                 *(int *)(*(int *)(extraout_ECX[0x3a] + 0xc) + 0x80) + 3);
  }
  FUN_005dbf32();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

