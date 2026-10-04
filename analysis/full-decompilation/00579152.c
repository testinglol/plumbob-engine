
undefined1 FUN_00579152(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  CParkingWnd *pCVar7;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  uVar8 = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar6 = *(undefined4 *)(unaff_EBP + 8);
  FUN_005b8e25(uVar6,0);
  iVar4 = FUN_005b936f(uVar6,uVar8);
  *(int *)(unaff_EBP + -0x18) = iVar4;
  if (iVar4 != 0) {
    iVar1 = *(int *)(iVar4 + 0x10);
    if (iVar1 == 0) {
      FUN_005b8e25(iVar4);
      FUN_005b95c0(iVar4);
    }
    else {
      pvVar5 = operator_new(iVar1 + 1);
      if (pvVar5 != (void *)0x0) {
        FUN_005b8e6a(pvVar5,iVar1);
        uVar6 = *(undefined4 *)(unaff_EBP + -0x18);
        FUN_005b8e25(uVar6);
        FUN_005b95c0(uVar6);
        *(undefined1 *)(iVar1 + (int)pvVar5) = 0;
        FUN_005d49b7(pvVar5);
        FUN_006321f0(pvVar5);
        cVar2 = FUN_005d4cfd(s_version_006cf2f4,7);
        if (cVar2 != '\0') {
          uVar6 = FUN_005d4a0d(unaff_EBP + -0x34,s_version_006cf2f4);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005d499c(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005b8770();
          uVar6 = FUN_005d4a0d(unaff_EBP + -0x34,&DAT_006c08dc);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005d499c(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005b8770();
          uVar6 = FUN_004096c2();
          iVar4 = FUN_005d81cf(uVar6);
          if (iVar4 == 7) {
            uVar6 = FUN_005d4a0d(unaff_EBP + -0x34,&DAT_006c08dc);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            FUN_005d499c(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_005b8770();
            uVar6 = FUN_005d4a0d(unaff_EBP + -0x34,&DAT_006c08dc);
            *(undefined1 *)(unaff_EBP + -4) = 6;
            FUN_005d499c(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_005b8770();
            (*(code *)PTR_FUN_006d6ff8)
                      (*(undefined4 *)(unaff_EBP + -0x28),
                       s__ld__ld__ld__ld__ld__ld__ld__ld___006cf2b8,extraout_ECX + 4,
                       extraout_ECX + 8,extraout_ECX + 0xc,extraout_ECX + 0x10,
                       (int *)(extraout_ECX + 0x24),extraout_ECX + 0x28,extraout_ECX + 0x2c,
                       extraout_ECX + 0x30,extraout_ECX + 0x20,extraout_ECX + 0x1c,
                       extraout_ECX + 0x34,extraout_ECX + 0x38,extraout_ECX + 0x14,
                       extraout_ECX + 0x18);
            uVar6 = FUN_005d4a0d(unaff_EBP + -0x34,&DAT_006c08dc);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            FUN_005d499c(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_005b8770();
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
            if (0 < *(int *)(extraout_ECX + 0x24)) {
              *(undefined4 *)(unaff_EBP + -0x1c) = 0x11;
              do {
                *(undefined4 *)(unaff_EBP + -0x14) = 0;
                if (0 < *(int *)(extraout_ECX + 0x28)) {
                  do {
                    pvVar5 = operator_new(0x54);
                    *(void **)(unaff_EBP + -0x90) = pvVar5;
                    *(undefined1 *)(unaff_EBP + -4) = 8;
                    if (pvVar5 == (void *)0x0) {
                      pCVar7 = (CParkingWnd *)0x0;
                    }
                    else {
                      pCVar7 = (CParkingWnd *)FUN_00578fe9();
                    }
                    *(undefined1 *)(unaff_EBP + -4) = 2;
                    uVar6 = FUN_005d4a0d(unaff_EBP + -0x34,&DAT_006c08dc);
                    *(undefined1 *)(unaff_EBP + -4) = 9;
                    FUN_005d499c(uVar6);
                    *(undefined1 *)(unaff_EBP + -4) = 2;
                    FUN_005b8770();
                    _memset((void *)(unaff_EBP + -0x1bc),0,0x104);
                    (*(code *)PTR_FUN_006d6ff8)
                              (*(undefined4 *)(unaff_EBP + -0x28),
                               s__ld__ld__ld__ld__ld__ld__ld__ld___006cf26c,pCVar7 + 0x10,
                               unaff_EBP + -0x54,pCVar7 + 0x14,pCVar7 + 0x18,unaff_EBP + -0x94,
                               pCVar7 + 0x20,pCVar7 + 0x24,pCVar7 + 0x28,unaff_EBP + -0x50,
                               pCVar7 + 0x34,unaff_EBP + -0x48,pCVar7 + 0x38,pCVar7 + 0x2c,
                               pCVar7 + 0x40,pCVar7 + 0x44,unaff_EBP + -0x44,pCVar7 + 0x48,
                               unaff_EBP + -0x4c,unaff_EBP + -0x1bc);
                    if (*(int *)(unaff_EBP + -0x94) == 0) {
                      pCVar7[0x1d] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x1d] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x54) == 0) {
                      pCVar7[0x1c] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x1c] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x50) == 0) {
                      pCVar7[0x30] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x30] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x48) == 0) {
                      pCVar7[0x3c] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x3c] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x44) == 0) {
                      pCVar7[0xc] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0xc] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x4c) == 0) {
                      pCVar7[0x4c] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x4c] = (CParkingWnd)0x1;
                    }
                    *(undefined1 *)(unaff_EBP + -0xd) = 1;
                    FUN_005d48d9();
                    *(undefined1 *)(unaff_EBP + -4) = 10;
                    FUN_005d4a0d(unaff_EBP + -0x6c,&DAT_006c3cd0);
                    *(undefined1 *)(unaff_EBP + -4) = 0xb;
                    do {
                      if (*(int *)(unaff_EBP + -0x68) == *(int *)(unaff_EBP + -0x6c)) {
                        *(undefined1 *)(unaff_EBP + -0xd) = 0;
                      }
                      else {
                        uVar6 = FUN_005d4a0d(unaff_EBP + -0xac,&DAT_006c3cd4);
                        *(undefined1 *)(unaff_EBP + -4) = 0xc;
                        FUN_005d499c(uVar6);
                        *(undefined1 *)(unaff_EBP + -4) = 0xb;
                        FUN_005b8770();
                        (*(code *)PTR_FUN_006d6ff8)
                                  (*(undefined4 *)(unaff_EBP + -0x8c),s__ld__ld_006cf264,
                                   unaff_EBP + -0x80,unaff_EBP + -0x7c);
                        FUN_0057a0ce(unaff_EBP + -0x80);
                        uVar6 = FUN_005d4a0d(unaff_EBP + -0xa0,&DAT_006c3cd0);
                        *(undefined1 *)(unaff_EBP + -4) = 0xd;
                        FUN_005d499c(uVar6);
                        *(undefined1 *)(unaff_EBP + -4) = 0xb;
                        FUN_005b8770();
                      }
                    } while (*(char *)(unaff_EBP + -0xd) != '\0');
                    FUN_005d4956(unaff_EBP + -0x1bc);
                    *(undefined1 *)(unaff_EBP + -4) = 0xe;
                    FUN_005d499c(unaff_EBP + -0x60);
                    FUN_005d4d82();
                    uVar6 = FUN_005d4956(&DAT_006c0fd4);
                    *(undefined1 *)(unaff_EBP + -4) = 0xf;
                    uVar3 = FUN_004317d5(unaff_EBP + -0x60,uVar6);
                    *(undefined1 *)(unaff_EBP + -0xd) = uVar3;
                    *(undefined1 *)(unaff_EBP + -4) = 0xe;
                    FUN_005b8770();
                    if (*(char *)(unaff_EBP + -0xd) == '\0') {
                      *(CParkingWnd **)
                       (extraout_ECX +
                       (*(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x14)) * 4) = pCVar7;
                    }
                    else {
                      if (pCVar7 != (CParkingWnd *)0x0) {
                        CParkingWnd::_scalar_deleting_destructor_(pCVar7,1);
                      }
                      *(undefined4 *)
                       (extraout_ECX +
                       (*(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x14)) * 4) = 0;
                    }
                    *(undefined1 *)(unaff_EBP + -4) = 0xb;
                    FUN_005b8770();
                    *(undefined1 *)(unaff_EBP + -4) = 10;
                    FUN_005b8770();
                    *(undefined1 *)(unaff_EBP + -4) = 2;
                    FUN_005b8770();
                    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                  } while (*(int *)(unaff_EBP + -0x14) < *(int *)(extraout_ECX + 0x28));
                }
                *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x40;
              } while (*(int *)(unaff_EBP + -0x18) < *(int *)(extraout_ECX + 0x24));
            }
          }
          else if ((iVar4 == 6) || (iVar4 == 5)) {
            FUN_005b86bd(unaff_EBP + 8);
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_005ed5c3(unaff_EBP + -0x34,unaff_EBP + -0x34);
            uVar6 = FUN_005d4a0d(unaff_EBP + -0x78,&DAT_006c08dc);
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            FUN_005d499c(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_005b8770();
            uVar6 = FUN_005d4a0d(unaff_EBP + -0x78,&DAT_006c08dc);
            *(undefined1 *)(unaff_EBP + -4) = 0x12;
            FUN_005d499c(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_005b8770();
            (*(code *)PTR_FUN_006d6ff8)
                      (*(undefined4 *)(unaff_EBP + -0x28),
                       s__ld__ld__ld__ld__ld__ld__ld__ld___006cf2b8,extraout_ECX + 4,
                       extraout_ECX + 8,extraout_ECX + 0xc,extraout_ECX + 0x10,
                       (int *)(extraout_ECX + 0x24),extraout_ECX + 0x28,extraout_ECX + 0x2c,
                       extraout_ECX + 0x30,extraout_ECX + 0x20,extraout_ECX + 0x1c,
                       extraout_ECX + 0x34,extraout_ECX + 0x38,extraout_ECX + 0x14,
                       extraout_ECX + 0x18);
            uVar6 = FUN_005d4a0d(unaff_EBP + -0x78,&DAT_006c08dc);
            *(undefined1 *)(unaff_EBP + -4) = 0x13;
            FUN_005d499c(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_005b8770();
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
            if (0 < *(int *)(extraout_ECX + 0x24)) {
              *(undefined4 *)(unaff_EBP + -0x1c) = 0x11;
              do {
                *(undefined4 *)(unaff_EBP + -0x14) = 0;
                if (0 < *(int *)(extraout_ECX + 0x28)) {
                  do {
                    pvVar5 = operator_new(0x54);
                    *(void **)(unaff_EBP + -0x90) = pvVar5;
                    *(undefined1 *)(unaff_EBP + -4) = 0x14;
                    if (pvVar5 == (void *)0x0) {
                      pCVar7 = (CParkingWnd *)0x0;
                    }
                    else {
                      pCVar7 = (CParkingWnd *)FUN_00578fe9();
                    }
                    *(undefined1 *)(unaff_EBP + -4) = 0x10;
                    uVar6 = FUN_005d4a0d(unaff_EBP + -0x78,&DAT_006c08dc);
                    *(undefined1 *)(unaff_EBP + -4) = 0x15;
                    FUN_005d499c(uVar6);
                    *(undefined1 *)(unaff_EBP + -4) = 0x10;
                    FUN_005b8770();
                    _memset((void *)(unaff_EBP + -0x1bc),0,0x104);
                    (*(code *)PTR_FUN_006d6ff8)
                              (*(undefined4 *)(unaff_EBP + -0x28),
                               s__ld__ld__ld__ld__ld__ld__ld__ld___006cf21c,pCVar7 + 0x10,
                               unaff_EBP + -0x44,pCVar7 + 0x14,pCVar7 + 0x18,unaff_EBP + -0x4c,
                               pCVar7 + 0x20,pCVar7 + 0x24,pCVar7 + 0x28,unaff_EBP + -0x48,
                               pCVar7 + 0x34,unaff_EBP + -0x50,pCVar7 + 0x38,pCVar7 + 0x2c,
                               pCVar7 + 0x40,pCVar7 + 0x44,unaff_EBP + -0x54,pCVar7 + 0x48,
                               unaff_EBP + -0x1bc);
                    if (*(int *)(unaff_EBP + -0x4c) == 0) {
                      pCVar7[0x1d] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x1d] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x44) == 0) {
                      pCVar7[0x1c] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x1c] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x48) == 0) {
                      pCVar7[0x30] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x30] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x50) == 0) {
                      pCVar7[0x3c] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0x3c] = (CParkingWnd)0x1;
                    }
                    if (*(int *)(unaff_EBP + -0x54) == 0) {
                      pCVar7[0xc] = (CParkingWnd)0x0;
                    }
                    else {
                      pCVar7[0xc] = (CParkingWnd)0x1;
                    }
                    pCVar7[0x4c] = (CParkingWnd)0x0;
                    *(undefined1 *)(unaff_EBP + -0xd) = 1;
                    FUN_005d48d9();
                    *(undefined1 *)(unaff_EBP + -4) = 0x16;
                    FUN_005d4a0d(unaff_EBP + -0x60,&DAT_006c3cd0);
                    *(undefined1 *)(unaff_EBP + -4) = 0x17;
                    do {
                      if (*(int *)(unaff_EBP + -0x5c) == *(int *)(unaff_EBP + -0x60)) {
                        *(undefined1 *)(unaff_EBP + -0xd) = 0;
                      }
                      else {
                        uVar6 = FUN_005d4a0d(unaff_EBP + -0xa0,&DAT_006c3cd4);
                        *(undefined1 *)(unaff_EBP + -4) = 0x18;
                        FUN_005d499c(uVar6);
                        *(undefined1 *)(unaff_EBP + -4) = 0x17;
                        FUN_005b8770();
                        (*(code *)PTR_FUN_006d6ff8)
                                  (*(undefined4 *)(unaff_EBP + -0x8c),s__ld__ld_006cf264,
                                   unaff_EBP + -0x80,unaff_EBP + -0x7c);
                        FUN_0057a0ce(unaff_EBP + -0x80);
                        uVar6 = FUN_005d4a0d(unaff_EBP + -0xac,&DAT_006c3cd0);
                        *(undefined1 *)(unaff_EBP + -4) = 0x19;
                        FUN_005d499c(uVar6);
                        *(undefined1 *)(unaff_EBP + -4) = 0x17;
                        FUN_005b8770();
                      }
                    } while (*(char *)(unaff_EBP + -0xd) != '\0');
                    FUN_005d4956(unaff_EBP + -0x1bc);
                    *(undefined1 *)(unaff_EBP + -4) = 0x1a;
                    FUN_005d499c(unaff_EBP + -0x6c);
                    FUN_005d4d82();
                    uVar6 = FUN_005d4956(&DAT_006c0fd4);
                    *(undefined1 *)(unaff_EBP + -4) = 0x1b;
                    uVar3 = FUN_004317d5(unaff_EBP + -0x6c,uVar6);
                    *(undefined1 *)(unaff_EBP + -0xd) = uVar3;
                    *(undefined1 *)(unaff_EBP + -4) = 0x1a;
                    FUN_005b8770();
                    if (*(char *)(unaff_EBP + -0xd) == '\0') {
                      *(CParkingWnd **)
                       (extraout_ECX +
                       (*(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x14)) * 4) = pCVar7;
                    }
                    else {
                      if (pCVar7 != (CParkingWnd *)0x0) {
                        CParkingWnd::_scalar_deleting_destructor_(pCVar7,1);
                      }
                      *(undefined4 *)
                       (extraout_ECX +
                       (*(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x14)) * 4) = 0;
                    }
                    *(undefined1 *)(unaff_EBP + -4) = 0x17;
                    FUN_005b8770();
                    *(undefined1 *)(unaff_EBP + -4) = 0x16;
                    FUN_005b8770();
                    *(undefined1 *)(unaff_EBP + -4) = 0x10;
                    FUN_005b8770();
                    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                  } while (*(int *)(unaff_EBP + -0x14) < *(int *)(extraout_ECX + 0x28));
                }
                *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x40;
              } while (*(int *)(unaff_EBP + -0x18) < *(int *)(extraout_ECX + 0x24));
            }
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_005b8770();
          }
        }
        uVar3 = 1;
        goto LAB_005791b1;
      }
    }
  }
  uVar3 = 0;
LAB_005791b1:
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

