
void FUN_004360c1(void)

{
  byte bVar1;
  byte *pbVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  void *pvVar10;
  uint uVar11;
  int *piVar12;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int unaff_EBP;
  char *pcVar13;
  int *piStack_14c;
  int *piStack_148;
  uint uStack_144;
  undefined **ppuStack_140;
  
  FUN_00634c24();
  iVar8 = *extraout_ECX;
  if ((iVar8 == 0) || (iVar7 = FUN_00444bf6(), iVar8 != iVar7)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  *(undefined1 *)(extraout_ECX + 0x1b) = uVar3;
  if ((iVar8 == 0) || (iVar8 = FUN_0045741b(), iVar8 != -0x3cdb65e3)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  *(undefined1 *)((int)extraout_ECX + 0x6d) = uVar3;
  thunk_FUN_00457ea7();
  ppuStack_140 = (undefined **)0x43612a;
  FUN_005d499c();
  pbVar2 = *(byte **)(unaff_EBP + 0xc);
  extraout_ECX[0x14] = pbVar2[5] & 0x7f;
  *(byte *)((int)extraout_ECX + 0x6e) = pbVar2[5] >> 7;
  *(byte *)(extraout_ECX + 0x1a) = pbVar2[7] & 1;
  iVar8 = *(int *)(unaff_EBP + 8);
  *(byte *)((int)extraout_ECX + 0x69) = (byte)~pbVar2[7] >> 7;
  if (iVar8 == 0) {
    uVar9 = *(undefined4 *)extraout_ECX[1];
  }
  else {
    uVar9 = FUN_00401f6f();
  }
  *(undefined4 *)(unaff_EBP + 0xc) = uVar9;
  if (*(int *)(unaff_EBP + 8) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined2 *)(*(int *)(unaff_EBP + 8) + 4);
  }
  *(undefined2 *)((int)extraout_ECX + 0x6a) = uVar6;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x138) = &PTR_FUN_0066643c;
  ppuStack_140 = (undefined **)0x12d;
  uStack_144 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piStack_148 = (int *)0x4361ab;
  FUN_00470383();
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d48d9();
  uStack_144 = (uint)pbVar2[2];
  piStack_148 = extraout_ECX + 0xe;
  ppuStack_140 = (undefined **)0x0;
  piStack_14c = (int *)(unaff_EBP + -0x138);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00436a83();
  FUN_00436a83(unaff_EBP + -0x138,extraout_ECX + 2,pbVar2[6],extraout_ECX[2],1);
  iVar8 = extraout_ECX[0x14];
  if (iVar8 == 0) {
LAB_00436282:
    ppuStack_140 = (undefined **)0x1;
LAB_00436286:
    uStack_144 = 0x43628b;
    ppuStack_140 = (undefined **)FUN_00435ff3();
    uStack_144 = (uint)pbVar2[3];
    piStack_148 = extraout_ECX + 5;
    piStack_14c = (int *)(unaff_EBP + -0x138);
    FUN_00436a83();
  }
  else {
    if (iVar8 == 1) {
LAB_00436259:
      ppuStack_140 = (undefined **)0x4;
      uStack_144 = 0x436262;
      ppuStack_140 = (undefined **)FUN_00435ff3();
      uStack_144 = (uint)pbVar2[4];
      piStack_148 = extraout_ECX + 8;
      piStack_14c = (int *)(unaff_EBP + -0x138);
      FUN_00436a83();
      ppuStack_140 = (undefined **)0x3;
      goto LAB_00436286;
    }
    if (iVar8 == 2) {
      ppuStack_140 = (undefined **)0x2;
      uStack_144 = 0x436240;
      ppuStack_140 = (undefined **)FUN_00435ff3();
      uStack_144 = (uint)*pbVar2;
      piStack_148 = extraout_ECX + 0xb;
      piStack_14c = (int *)(unaff_EBP + -0x138);
      FUN_00436a83();
      goto LAB_00436259;
    }
    if ((2 < iVar8) && (iVar8 < 5)) goto LAB_00436282;
  }
  if (*extraout_ECX == 0) goto LAB_004369f5;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  ppuStack_140 = (undefined **)0x0;
  uStack_144 = *(undefined4 *)(unaff_EBP + 8);
  piStack_148 = extraout_ECX + 5;
  piStack_14c = (int *)0x4362c3;
  FUN_0044bf5a();
  ppuStack_140 = (undefined **)0x0;
  uStack_144 = *(undefined4 *)(unaff_EBP + 8);
  piStack_148 = extraout_ECX + 8;
  piStack_14c = (int *)0x4362d6;
  FUN_0044bf5a();
  ppuStack_140 = (undefined **)0x0;
  uStack_144 = *(undefined4 *)(unaff_EBP + 8);
  piStack_148 = extraout_ECX + 0xb;
  piStack_14c = (int *)0x4362e9;
  FUN_0044bf5a();
  ppuStack_140 = (undefined **)0x0;
  uStack_144 = *(undefined4 *)(unaff_EBP + 8);
  piStack_148 = extraout_ECX + 2;
  piStack_14c = (int *)0x4362fc;
  FUN_0044bf5a();
  ppuStack_140 = (undefined **)0x0;
  uStack_144 = *(uint *)(unaff_EBP + 8);
  piStack_148 = extraout_ECX + 0xe;
  piStack_14c = (int *)0x43630f;
  FUN_0044bf5a();
  *(undefined4 *)(unaff_EBP + -0x38) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  FUN_005b8680();
  bVar1 = pbVar2[7];
  *(undefined1 *)(unaff_EBP + -4) = 5;
  bVar4 = bVar1 >> 1 & 7;
  if ((bVar1 >> 1 & 7) == 0) {
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + -0x24);
    if ((*(int *)(unaff_EBP + -0x24) == 0) && (*extraout_ECX != 0)) {
      uVar11 = (uint)*(short *)((int)extraout_ECX + 0x6a);
      iVar8 = *(int *)(*extraout_ECX + 0xdc);
      if ((0 < (int)uVar11) &&
         ((uVar11 < (*(int *)(iVar8 + 0x1c) - *(int *)(iVar8 + 0x18) >> 2) + 1U &&
          (*(int *)(*(int *)(iVar8 + 0x18) + -4 + uVar11 * 4) != 0)))) {
        uVar9 = FUN_004573f9();
        goto LAB_004363ef;
      }
    }
  }
  else if (bVar4 == 2) {
    ppuStack_140 = (undefined **)0x4363ab;
    uVar9 = FUN_00425b48();
LAB_004363ef:
    *(undefined4 *)(unaff_EBP + 0xc) = uVar9;
  }
  else if (bVar4 == 3) {
    ppuStack_140 = (undefined **)0x436388;
    uVar9 = FUN_0043c0bd();
    *(undefined4 *)(unaff_EBP + 0xc) = uVar9;
    *(uint *)(unaff_EBP + -0x38) = pbVar2[1] + 5000;
  }
  else if (bVar4 == 4) {
    uStack_144 = (uint)pbVar2[1];
    ppuStack_140 = (undefined **)&DAT_006de560;
    piStack_148 = (int *)(unaff_EBP + -0x44);
    piStack_14c = (int *)(unaff_EBP + -0x138);
    FUN_00436a83();
    piStack_148 = (int *)(unaff_EBP + -0x44);
    ppuStack_140 = (undefined **)0x0;
    uStack_144 = *(uint *)(unaff_EBP + 8);
    piStack_14c = (int *)0x43636a;
    FUN_0044bf5a();
  }
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    if (*(int *)(unaff_EBP + -0x38) < 1) {
      iVar8 = *(int *)(unaff_EBP + 0xc);
      cVar5 = FUN_0045773e();
      if (cVar5 == '\0') {
        *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar8 + 0x84);
        cVar5 = FUN_005a5e72();
        if (cVar5 == '\0') {
          ppuStack_140 = (undefined **)0x4364cb;
          pvVar10 = operator_new(100);
          *(void **)(unaff_EBP + 0xc) = pvVar10;
          *(undefined1 *)(unaff_EBP + -4) = 7;
          if (pvVar10 != (void *)0x0) {
            FUN_005dfb13();
          }
          *(undefined1 *)(unaff_EBP + -4) = 5;
          ppuStack_140 = (undefined **)0x4364ee;
          FUN_005a5e48();
        }
        if (*(int *)(unaff_EBP + 8) != 0) {
          piVar12 = (int *)FUN_004096c2();
          iVar8 = *piVar12;
          ppuStack_140 = (undefined **)0x0;
          uStack_144 = 0;
          *(int ***)(unaff_EBP + -0x38) = &piStack_14c;
          *(int **)(unaff_EBP + 0xc) = piVar12;
          piStack_14c = extraout_ECX_00;
          piStack_148 = extraout_ECX_00;
          FUN_00436a50(4);
          (**(code **)(iVar8 + 0xc))(0x7d,0x7f);
          FUN_004096c2();
          FUN_005df69e();
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          *(undefined4 *)(unaff_EBP + -0x14) = 0x78;
          *(undefined4 *)(unaff_EBP + -0x10) = 0x78;
          iVar8 = FUN_004096c2();
          cVar5 = (**(code **)(**(int **)(iVar8 + 0x5c) + 0x20))(1);
          if (cVar5 != '\0') {
            iVar8 = FUN_004096c2();
            ppuStack_140 = (undefined **)(unaff_EBP + -0x1c);
            uStack_144 = 0xffff;
            piStack_148 = (int *)0x436570;
            (**(code **)(**(int **)(iVar8 + 0x5c) + 0x40))();
            piStack_148 = (int *)0x436577;
            iVar8 = FUN_004096c2();
            piStack_148 = (int *)0x1;
            piStack_14c = (int *)0x436583;
            (**(code **)(**(int **)(iVar8 + 0x5c) + 0x24))();
            piStack_14c = (int *)0x43658a;
            piVar12 = (int *)FUN_004096c2();
            piStack_14c = (int *)0x1;
            (**(code **)(*piVar12 + 0x20))();
            piVar12 = (int *)FUN_004096c2();
            (**(code **)(*piVar12 + 0x38))(DAT_006f2a54,0);
            piVar12 = (int *)FUN_004096c2();
            (**(code **)(*piVar12 + 0x24))(1);
          }
          ppuStack_140 = (undefined **)0x4365c3;
          ppuStack_140 = (undefined **)FUN_004096c2();
          uStack_144 = 0x4365cc;
          FUN_004cbd1c();
          *(undefined4 *)(unaff_EBP + -0x34) = 0;
          *(undefined4 *)(unaff_EBP + -0x30) = 0;
          *(undefined4 *)(unaff_EBP + -0x2c) = 0x78;
          *(undefined4 *)(unaff_EBP + -0x28) = 0x78;
        }
      }
      else {
        FUN_0045741b();
        ppuStack_140 = (undefined **)0x436459;
        iVar8 = FUN_004e988f();
        if (iVar8 != -1) {
          FUN_005c1719();
          *(undefined1 *)(unaff_EBP + -4) = 6;
          uStack_144 = 0x43647b;
          ppuStack_140 = (undefined **)iVar8;
          cVar5 = FUN_004e93e4();
          if (cVar5 != '\0') {
            ppuStack_140 = (undefined **)0x43648d;
            FUN_005a5e1c();
          }
          *(undefined4 *)(unaff_EBP + -0x34) = 0;
          *(undefined4 *)(unaff_EBP + -0x30) = 0;
          *(undefined4 *)(unaff_EBP + -0x2c) = 0x2d;
          *(undefined4 *)(unaff_EBP + -0x28) = 0x2d;
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_005a5e09();
        }
      }
    }
    else {
      ppuStack_140 = (undefined **)(unaff_EBP + 8);
      uStack_144 = *(uint *)(unaff_EBP + -0x38);
      piStack_148 = (int *)**(int **)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      piStack_14c = (int *)0x436423;
      cVar5 = FUN_005a55f6();
      if (cVar5 != '\0') {
        ppuStack_140 = (undefined **)0x436439;
        FUN_005a5e48();
      }
    }
  }
  cVar5 = FUN_005a5e72();
  if ((cVar5 == '\0') && (*(int *)(unaff_EBP + -0x40) != *(int *)(unaff_EBP + -0x44))) {
    uStack_144 = unaff_EBP + -100;
    ppuStack_140 = (undefined **)0x0;
    piStack_148 = (int *)0x436606;
    FUN_0046f824();
    uStack_144 = unaff_EBP + -0x90;
    ppuStack_140 = (undefined **)0x0;
    *(undefined ***)(unaff_EBP + -0x70) = &PTR_FUN_006666e4;
    piStack_148 = (int *)0x436623;
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x9c) = &PTR_FUN_006666e4;
    *(int *)(unaff_EBP + 8) = unaff_EBP + -0x70;
    pcVar13 = *(char **)(unaff_EBP + -0x44);
    cVar5 = *pcVar13;
    while (cVar5 != '\0') {
      if (*pcVar13 == ' ') {
        if (*(int *)(unaff_EBP + 8) == unaff_EBP + -0x70) {
          *(int *)(unaff_EBP + 8) = unaff_EBP + -0x9c;
        }
      }
      else {
        ppuStack_140 = (undefined **)0x43665a;
        FUN_0046fa24();
      }
      pcVar13 = pcVar13 + 1;
      cVar5 = *pcVar13;
    }
    uStack_144 = unaff_EBP + -0x10;
    ppuStack_140 = (undefined **)0x0;
    piStack_148 = (int *)0x43666e;
    FUN_0046f824();
    ppuStack_140 = (undefined **)&DAT_006c29a8;
    *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_0066663c;
    uStack_144 = 0x436685;
    FUN_0046f847();
    ppuStack_140 = (undefined **)0x436691;
    iVar8 = FUN_0046f973();
    if (iVar8 != 0) {
      uStack_144 = unaff_EBP + -0x10;
      ppuStack_140 = (undefined **)0x0;
      piStack_148 = (int *)0x4366a8;
      FUN_0046f824();
      ppuStack_140 = (undefined **)&DAT_006c29a4;
      *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_0066663c;
      uStack_144 = 0x4366ba;
      FUN_0046f847();
      ppuStack_140 = (undefined **)0x4366c6;
      iVar8 = FUN_0046f973();
      if (iVar8 != 0) {
        uStack_144 = unaff_EBP + -0x10;
        ppuStack_140 = (undefined **)0x0;
        piStack_148 = (int *)0x4366dd;
        FUN_0046f824();
        ppuStack_140 = (undefined **)&DAT_006c29a0;
        *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_0066663c;
        uStack_144 = 0x4366ef;
        FUN_0046f847();
        ppuStack_140 = (undefined **)0x4366fb;
        iVar8 = FUN_0046f973();
        if (iVar8 == 0) {
          ppuStack_140 = (undefined **)0x43670a;
          uVar11 = FUN_00635f62();
          if (uVar11 != 0) {
            iVar8 = *extraout_ECX;
            *(undefined4 *)(unaff_EBP + 8) = 0;
            ppuStack_140 = (undefined **)(unaff_EBP + 8);
            piStack_148 = (int *)**(int **)(iVar8 + 0x11c);
            piStack_14c = (int *)0x43672d;
            uStack_144 = uVar11;
            cVar5 = FUN_005a55f6();
            if (cVar5 != '\0') {
              ppuStack_140 = (undefined **)0x436743;
              FUN_005a5e48();
            }
          }
        }
        else {
          uStack_144 = unaff_EBP + -0x14;
          ppuStack_140 = (undefined **)0x0;
          piStack_148 = (int *)0x436757;
          FUN_0046f824();
          ppuStack_140 = (undefined **)&DAT_006c2998;
          *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666644;
          uStack_144 = 0x43676d;
          FUN_0046f847();
          ppuStack_140 = (undefined **)0x436779;
          iVar8 = FUN_0046f973();
          if (iVar8 == 0) {
            ppuStack_140 = (undefined **)0x436796;
            FUN_00635f62();
            ppuStack_140 = (undefined **)0x43679f;
            iVar8 = FUN_0043acf5();
            if ((iVar8 != 0) && (*(int *)(iVar8 + 0x84) != 0)) {
              ppuStack_140 = (undefined **)0x4367be;
              FUN_004ccc2f();
              *(undefined4 *)(unaff_EBP + -0x34) = 0;
              *(undefined4 *)(unaff_EBP + -0x30) = 0;
              *(undefined4 *)(unaff_EBP + -0x2c) = 0x2d;
              *(undefined4 *)(unaff_EBP + -0x28) = 0x2d;
            }
          }
          else {
            uStack_144 = unaff_EBP + -0x10;
            ppuStack_140 = (undefined **)0x0;
            piStack_148 = (int *)0x4367e1;
            FUN_0046f824();
            ppuStack_140 = &PTR_s_ndex_006c6568_0xa_006c2994;
            *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_0066663c;
            uStack_144 = 0x4367f3;
            FUN_0046f847();
            ppuStack_140 = (undefined **)0x4367ff;
            iVar8 = FUN_0046f973();
            if (iVar8 == 0) {
              uVar11 = FUN_004e99a9();
              if (uVar11 != 0xffffffff) {
                *(undefined4 *)(unaff_EBP + -0x18) = 0;
                *(undefined4 *)(unaff_EBP + -0x14) = 0;
                *(undefined4 *)(unaff_EBP + -0x10) = 0;
                ppuStack_140 = (undefined **)(unaff_EBP + -0x18);
                *(undefined1 *)(unaff_EBP + -4) = 8;
                piStack_148 = (int *)0x43682e;
                uStack_144 = uVar11;
                FUN_004e9f27();
                if ((*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18) & 0xfffffffcU) != 0)
                {
                  FUN_005c1719();
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  ppuStack_140 = (undefined **)**(int **)(unaff_EBP + -0x18);
                  uStack_144 = 0x436858;
                  cVar5 = FUN_004e95e0();
                  if (cVar5 != '\0') {
                    ppuStack_140 = (undefined **)0x43686a;
                    FUN_005a5e1c();
                  }
                  cVar5 = FUN_005a5e72();
                  if (cVar5 != '\0') {
                    iVar8 = FUN_004096c2();
                    iVar8 = *(int *)(iVar8 + 0x1c) / 5;
                    *(int *)(unaff_EBP + -0x2c) = iVar8;
                    iVar7 = FUN_004096c2();
                    uVar9 = *(undefined4 *)(iVar7 + 0x20);
                    iVar8 = iVar8 * 2;
                    *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + iVar8;
                    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + iVar8;
                    *(undefined4 *)(unaff_EBP + -0x28) = uVar9;
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 8;
                  FUN_005a5e09();
                }
                *(undefined1 *)(unaff_EBP + -4) = 5;
                FUN_0048c4c9();
              }
            }
            else {
              uStack_144 = unaff_EBP + -0x10;
              ppuStack_140 = (undefined **)0x0;
              piStack_148 = (int *)0x4368cf;
              FUN_0046f824();
              ppuStack_140 = &PTR_LAB_006c2990;
              *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_0066663c;
              uStack_144 = 0x4368e1;
              FUN_0046f847();
              ppuStack_140 = (undefined **)0x4368ed;
              iVar8 = FUN_0046f973();
              if (iVar8 == 0) {
                ppuStack_140 = (undefined **)0x436900;
                uVar9 = FUN_00635f62();
                *(undefined4 *)(unaff_EBP + 0xc) = uVar9;
                if ((DAT_006f3adc != 0) && (*(int *)(DAT_006f3adc + 0x110) != 0)) {
                  FUN_005c1719();
                  ppuStack_140 = (undefined **)(unaff_EBP + -0x34);
                  *(undefined1 *)(unaff_EBP + -4) = 10;
                  uStack_144 = *(uint *)(unaff_EBP + 0xc);
                  piStack_148 = (int *)0x43693d;
                  cVar5 = FUN_00530b47();
                  if (cVar5 != '\0') {
                    ppuStack_140 = (undefined **)0x43694d;
                    FUN_005a5e1c();
                  }
                  *(undefined1 *)(unaff_EBP + -4) = 5;
                  FUN_005a5e09();
                }
              }
            }
          }
        }
        goto LAB_004369d8;
      }
    }
    ppuStack_140 = (undefined **)0x436966;
    uVar11 = FUN_00635f62();
    if (uVar11 != 0) {
      ppuStack_140 = (undefined **)(unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + 8) = 0;
      piStack_148 = (int *)0x43697a;
      uStack_144 = uVar11;
      cVar5 = FUN_005a5631();
      if (cVar5 != '\0') {
        ppuStack_140 = (undefined **)0x43698c;
        FUN_005a5e48();
      }
      cVar5 = FUN_005a5e72();
      if (cVar5 != '\0') {
        iVar8 = FUN_004096c2();
        iVar8 = *(int *)(iVar8 + 0x1c);
        *(int *)(unaff_EBP + -0x2c) = iVar8;
        if (*(short *)(unaff_EBP + -0x68) == 2) {
          *(int *)(unaff_EBP + -0x2c) = iVar8 / 4;
        }
        iVar8 = FUN_004096c2();
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar8 + 0x20);
        piVar12 = (int *)FUN_004096c2();
        ppuStack_140 = (undefined **)0x4369d8;
        (**(code **)(*piVar12 + 0x68))();
      }
    }
  }
LAB_004369d8:
  piVar12 = (int *)FUN_004b469d();
  extraout_ECX[0x16] = *piVar12;
  extraout_ECX[0x17] = piVar12[1];
  extraout_ECX[0x18] = piVar12[2];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  extraout_ECX[0x19] = piVar12[3];
  FUN_005b8770();
LAB_004369f5:
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

