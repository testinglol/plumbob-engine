
void FUN_0052bc54(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  undefined4 *puVar8;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    cVar1 = FUN_004cff80();
    if (cVar1 == '\0') {
      FUN_005a5631(0x1325,extraout_ECX + 0x35,4);
      FUN_005a5631(0x1338,extraout_ECX + 0x36,4);
    }
    else {
      FUN_005a5631(0x1324,extraout_ECX + 0x35,4);
      FUN_005a5631(0x1337,extraout_ECX + 0x36,4);
    }
    FUN_005a5631(0x12d6,extraout_ECX + 0x37,4);
    FUN_005a5631(0x12d7,extraout_ECX + 0x38,4);
    FUN_005a5631(0x116,extraout_ECX + 0x39,4);
    FUN_005a5631(0x117,extraout_ECX + 0x3a,4);
    FUN_005a5631(0x118,extraout_ECX + 0x3b,4);
    FUN_005a5631(0x132a,extraout_ECX + 0x7b,4);
    (**(code **)(*extraout_ECX + 0x60))(0,0,0x1ab,100);
    *(undefined4 *)(unaff_EBP + -0x50) = DAT_006f2a94;
    *(undefined4 *)(unaff_EBP + -0x4c) = DAT_006f2a90;
    cVar1 = FUN_004cff80();
    uVar2 = DAT_006f3bf4;
    if (cVar1 != '\0') {
      DAT_006f3c08 = DAT_006f3c00;
      DAT_006f3c0c = DAT_006f3c04;
      DAT_006f3bf8 = DAT_006f3bf0;
      puVar4 = &DAT_006f3ca0;
      puVar8 = &DAT_006f3cd8;
      for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar8 = puVar8 + 1;
      }
      DAT_006f3bfc = uVar2;
    }
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0xcc) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004fff98(1,s_fame_iff_006c0e84,unaff_EBP + -0xcc,0);
    FUN_00471655(unaff_EBP + -0x30);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar2 = FUN_0046fc7a();
    FUN_005d4bbf(uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    *(undefined4 *)(unaff_EBP + -0x14) = 0xb;
    do {
      FUN_0046fc87(unaff_EBP + -0x1c,0);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar2 = FUN_0046fc7a();
      FUN_005d4956(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_004054fa(unaff_EBP + -0x28);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      piVar5 = (int *)(unaff_EBP + -0x14);
      *piVar5 = *piVar5 + -1;
    } while (*piVar5 != 0);
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    uVar2 = FUN_0046fc7a();
    FUN_005d4bbf(uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    *(undefined4 *)(unaff_EBP + -0x14) = 0xb;
    do {
      FUN_0046fc87(unaff_EBP + -0x1c,0);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      uVar2 = FUN_0046fc7a();
      FUN_005d4956(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_004054fa(unaff_EBP + -0x48);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      uVar2 = FUN_0046fc7a();
      FUN_005d4956(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_004054fa(unaff_EBP + -0x3c);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      piVar5 = (int *)(unaff_EBP + -0x14);
      *piVar5 = *piVar5 + -1;
    } while (*piVar5 != 0);
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_0046fc7a();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_0046fc7a();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    uVar2 = FUN_0046fc7a();
    FUN_005d4956(uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    FUN_004054fa(unaff_EBP + -0x3c);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    uVar2 = FUN_0046fc7a();
    FUN_005d4956(uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 0xf;
    FUN_004054fa(unaff_EBP + -0x3c);
    *(undefined1 *)(unaff_EBP + -4) = 0xe;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    cVar1 = FUN_004fff98(0x88,&DAT_006c265c,unaff_EBP + -0xcc,0);
    if (cVar1 != '\0') {
      FUN_00471655(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      FUN_0046fc7a();
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_0042004f();
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      do {
        pvVar3 = operator_new(0x1ac);
        *(void **)(unaff_EBP + -0x20) = pvVar3;
        *(undefined1 *)(unaff_EBP + -4) = 0x12;
        if (pvVar3 == (void *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4 = (undefined4 *)FUN_0052c6db();
        }
        *(undefined1 *)(unaff_EBP + -4) = 0x10;
        *(undefined4 **)(unaff_EBP + -0x10) = puVar4;
        if (puVar4 != (undefined4 *)0x0) {
          if (*(int *)(unaff_EBP + -0x14) == 6) {
            iVar7 = extraout_ECX[0x4f];
            *(undefined4 *)(unaff_EBP + -0x40) = *puVar4;
            (**(code **)(*(int *)(unaff_EBP + -0x40) + 0x9c))(iVar7 + 0xc);
            *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x173) = 0;
            iVar7 = *(int *)(unaff_EBP + -0x10);
            *(undefined4 *)(unaff_EBP + -0x58) = 0x66;
            *(undefined4 *)(iVar7 + 0x160) = 1;
            *(undefined4 *)(iVar7 + 0x11c) = 0;
            *(undefined4 *)(iVar7 + 0x120) = 0;
            *(undefined4 *)(iVar7 + 0x124) = 0x66;
            *(undefined4 *)(iVar7 + 0x128) = 0x10;
            *(undefined4 *)(iVar7 + 0x164) = 0;
          }
          else {
            uVar2 = FUN_0046fc7a();
            FUN_005d4956(uVar2);
            *(undefined1 *)(unaff_EBP + -4) = 0x13;
            (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x9c))(unaff_EBP + -0x3c);
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_005b8770();
            iVar7 = *(int *)(unaff_EBP + -0x10);
            *(undefined4 *)(unaff_EBP + -0x58) = 0x3e;
            *(undefined4 *)(iVar7 + 0x160) = 1;
            *(undefined4 *)(iVar7 + 0x11c) = 0;
            *(undefined4 *)(iVar7 + 0x120) = 0;
            *(undefined4 *)(iVar7 + 0x124) = 0x3e;
            *(undefined4 *)(iVar7 + 0x128) = 0x10;
            *(undefined4 *)(iVar7 + 0x164) = 2;
          }
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x60))
                    (0,0,*(undefined4 *)(unaff_EBP + -0x58),0x10);
          cVar1 = FUN_004cff80();
          if (cVar1 == '\0') {
            puVar4 = (undefined4 *)(&DAT_006f3e60 + *(int *)(unaff_EBP + -0x14) * 8);
          }
          else {
            cVar1 = *(char *)(DAT_006e486c + 100);
            if (cVar1 == '\x0f') {
              puVar4 = (undefined4 *)(&DAT_006f3d10 + *(int *)(unaff_EBP + -0x14) * 8);
            }
            else if (cVar1 == '\x11') {
              puVar4 = (undefined4 *)(&DAT_006f3d48 + *(int *)(unaff_EBP + -0x14) * 8);
            }
            else if (cVar1 == '\x12') {
              puVar4 = (undefined4 *)(&DAT_006f3d80 + *(int *)(unaff_EBP + -0x14) * 8);
            }
            else if (cVar1 == '\x13') {
              puVar4 = (undefined4 *)(&DAT_006f3df0 + *(int *)(unaff_EBP + -0x14) * 8);
            }
            else if (cVar1 == '\x14') {
              puVar4 = (undefined4 *)(&DAT_006f3db8 + *(int *)(unaff_EBP + -0x14) * 8);
            }
            else {
              puVar4 = (undefined4 *)(&DAT_006f3e28 + *(int *)(unaff_EBP + -0x14) * 8);
            }
          }
          FUN_004cb21d(*puVar4,puVar4[1]);
          *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf8) = 1;
          *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf4) = 1;
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x19c))(0,4,0);
          FUN_005e4a3a(1);
          FUN_005e4071(*(undefined4 *)(unaff_EBP + -0x4c));
          (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x10));
          FUN_0052d5d9(unaff_EBP + -0x10);
        }
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        FUN_005c11ce();
      } while (*(int *)(unaff_EBP + -0x14) < 7);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
    }
    cVar1 = FUN_004fff98(0x89,&DAT_006c265c,unaff_EBP + -0xcc,0);
    if (cVar1 != '\0') {
      FUN_00471655(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      *(undefined4 *)(unaff_EBP + -0x14) = 6;
      do {
        FUN_0046fc87(unaff_EBP + -0x24,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x15;
        uVar2 = FUN_0046fc7a();
        FUN_005d4956(uVar2);
        *(undefined1 *)(unaff_EBP + -4) = 0x16;
        FUN_004054fa(unaff_EBP + -0x3c);
        *(undefined1 *)(unaff_EBP + -4) = 0x15;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0x14;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x44,0);
        *(undefined1 *)(unaff_EBP + -4) = 0x17;
        uVar2 = FUN_0046fc7a();
        FUN_005d4956(uVar2);
        *(undefined1 *)(unaff_EBP + -4) = 0x18;
        FUN_004054fa(unaff_EBP + -0x5c);
        *(undefined1 *)(unaff_EBP + -4) = 0x17;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0x14;
        FUN_0042004f();
        piVar5 = (int *)(unaff_EBP + -0x14);
        *piVar5 = *piVar5 + -1;
      } while (*piVar5 != 0);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
    }
    FUN_004054fa(extraout_ECX[0x52] + 0xc);
    FUN_004054fa(extraout_ECX[0x55] + 0xc);
    pvVar3 = operator_new(0x84);
    *(void **)(unaff_EBP + -0x40) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 0x19;
    if (pvVar3 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_00510166(*(undefined4 *)extraout_ECX[0x43],*(undefined4 *)extraout_ECX[0x46],0,0,0
                           ,0,0,0,0);
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x70] = iVar7;
    if (iVar7 != 0) {
      FUN_00503993(&DAT_006ccc60);
    }
    pvVar3 = operator_new(0x1ac);
    *(void **)(unaff_EBP + -0x20) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 0x1a;
    if (pvVar3 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_0052c6db();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(int *)(unaff_EBP + -0x10) = iVar7;
    if (iVar7 != 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      FUN_005e4a3a(1);
      *(undefined4 *)(unaff_EBP + -0x20) = DAT_006f3bfc;
      *(undefined4 *)(unaff_EBP + -0x40) = DAT_006f3bf8;
      FUN_005a5631(DAT_0066daac,unaff_EBP + -0x14,4);
      (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x14),4,1);
      *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x16b) = 1;
      FUN_005e4071(*(undefined4 *)(unaff_EBP + -0x50 + DAT_006ccc34 * 4));
      (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x60))
                (0,0,*(undefined4 *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x20));
      FUN_004cb21d(DAT_006f3c08,DAT_006f3c0c);
      *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf8) = 1;
      *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xf4) = 1;
      FUN_005e4a3a(1);
      *(int *)(unaff_EBP + -0x60) =
           (*(int *)(*(int *)(unaff_EBP + -0x14) + 0x1c) -
           *(int *)(*(int *)(unaff_EBP + -0x14) + 0x14)) /
           *(int *)(*(int *)(unaff_EBP + -0x10) + 0xf0) + 3;
      piVar5 = (int *)FUN_005e40a5();
      uVar2 = (**(code **)(*piVar5 + 0x58))();
      FUN_004ec1a7(uVar2);
      *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x144) = 0;
      *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x148) = 0;
      *(undefined1 *)(*(int *)(unaff_EBP + -0x10) + 0x173) = 0;
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
      piVar5 = (int *)FUN_005e40a5();
      iVar6 = (**(code **)(*piVar5 + 0x58))();
      iVar7 = *(int *)(unaff_EBP + -0x10);
      *(int *)(unaff_EBP + -0x20) = iVar7;
      *(undefined4 *)(iVar7 + 0x160) = 1;
      *(undefined4 *)(iVar7 + 0x11c) = *(undefined4 *)(unaff_EBP + -0x60);
      uVar2 = *(undefined4 *)(unaff_EBP + -0x40);
      *(int *)(iVar7 + 0x128) = iVar6 << 1;
      iVar6 = *(int *)(unaff_EBP + -0x20);
      *(undefined4 *)(iVar7 + 0x120) = 0;
      *(undefined4 *)(iVar7 + 0x124) = uVar2;
      *(undefined4 *)(iVar6 + 0x164) = 0;
      (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x10));
      FUN_0052d5d9(unaff_EBP + -0x10);
    }
    FUN_005d4bbf(&DAT_006ccc58);
    pvVar3 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x20) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 0x1b;
    if (pvVar3 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x7a] = iVar7;
    if (iVar7 != 0) {
      (**(code **)(*(int *)(iVar7 + 0xd4) + 0x18))(*(undefined4 *)(unaff_EBP + -0x4c));
      FUN_004cb21d(0xfa,3);
      (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x1c))
                (unaff_EBP + -0x14,unaff_EBP + -0x40,unaff_EBP + -0x20);
      uVar2 = FUN_005dd5e1(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x40),
                           *(undefined4 *)(unaff_EBP + -0x20));
      FUN_005e9fa4(uVar2);
      (**(code **)(*(int *)(extraout_ECX[0x7a] + 0xd4) + 0x14))(1);
      (**(code **)(*(int *)(extraout_ECX[0x7a] + 0xd4) + 0xc))(2,0);
      (*(code *)**(undefined4 **)(extraout_ECX[0x7a] + 0xd4))();
      (**(code **)(*(int *)extraout_ECX[0x7a] + 0x9c))(extraout_ECX + 0x77);
      (**(code **)(*(int *)extraout_ECX[0x7a] + 0x94))();
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x7a]);
      (**(code **)(*(int *)extraout_ECX[0x7a] + 0x98))();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  FUN_005dbf32();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

