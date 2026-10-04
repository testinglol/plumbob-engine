
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cd2d8(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int extraout_ECX;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_0046f824(unaff_EBP + -0x1b4,0,0x104);
  *(undefined ***)(unaff_EBP + -0x1c0) = &PTR_FUN_006664e8;
  uVar4 = FUN_0041532c(0,s_build_006c67c0,unaff_EBP + -0x1c0);
  FUN_004ee9ce(uVar4);
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f71c(unaff_EBP + -0x1c0,0);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xb0) = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  FUN_004a0e49();
  while( true ) {
    cVar3 = FUN_004a0e55(unaff_EBP + -0x20,unaff_EBP + -0x2c,unaff_EBP + -0x38,unaff_EBP + -0x14);
    if (cVar3 == '\0') break;
    pvVar5 = operator_new(0x60);
    *(void **)(unaff_EBP + -0x3c) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (pvVar5 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_004cb8d2();
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(unaff_EBP + -0x40) = uVar4;
    FUN_004ccefe(*(undefined4 *)(unaff_EBP + -0x20),unaff_EBP + -0x2c,unaff_EBP + -0x38,
                 *(undefined4 *)(unaff_EBP + -0x14));
    FUN_004cdcd0(unaff_EBP + -0x40);
  }
  FUN_004a0f5d();
  FUN_00470383(unaff_EBP + -0x404,0x80,0);
  uVar4 = FUN_004cdbd1(0xdbe,unaff_EBP + -0xb0,1,unaff_EBP + -0x1c,unaff_EBP + -0x2c,
                       unaff_EBP + -0x38,unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  DAT_006e57d0 = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_005a5631(0xe10,unaff_EBP + -0x18,4);
  FUN_004cd046(*(undefined4 *)(unaff_EBP + -0x1c),0,*(undefined4 *)(unaff_EBP + -0x18),
               unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  piVar1 = (int *)(extraout_ECX + 4);
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 0;
  FUN_004cdcd0(unaff_EBP + -0x10);
  uVar4 = FUN_004cdbd1(0xdbc,unaff_EBP + -0xb0,2,unaff_EBP + -0x1c,unaff_EBP + -0x2c,
                       unaff_EBP + -0x38,unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_005a5631(0xe11,unaff_EBP + -0x18,4);
  FUN_004cd046(*(undefined4 *)(unaff_EBP + -0x1c),0,*(undefined4 *)(unaff_EBP + -0x18),
               unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 1;
  FUN_004cdcd0(unaff_EBP + -0x10);
  uVar4 = FUN_004cdbd1(0xdbd,unaff_EBP + -0xb0,3,unaff_EBP + -0x1c,unaff_EBP + -0x2c,
                       unaff_EBP + -0x38,unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_005a5631(0xe12,unaff_EBP + -0x18,4);
  FUN_004cd046(*(undefined4 *)(unaff_EBP + -0x1c),0,*(undefined4 *)(unaff_EBP + -0x18),
               unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 2;
  FUN_004cdcd0(unaff_EBP + -0x10);
  uVar4 = FUN_004cdbd1(0xdbf,unaff_EBP + -0xb0,4,unaff_EBP + -0x1c,unaff_EBP + -0x2c,
                       unaff_EBP + -0x38,unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_005a5631(0xe17,unaff_EBP + -0x18,4);
  FUN_004cd046(*(undefined4 *)(unaff_EBP + -0x1c),0,*(undefined4 *)(unaff_EBP + -0x18),
               unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 3;
  FUN_004cdcd0(unaff_EBP + -0x10);
  FUN_00470383(unaff_EBP + -0x404,0x81,0);
  uVar6 = FUN_004cdbd1(0xffffffff,unaff_EBP + -0xb0,1,0,unaff_EBP + -0x2c,unaff_EBP + -0x38,
                       unaff_EBP + -0x14);
  uVar4 = *(undefined4 *)(unaff_EBP + -0x14);
  _DAT_006e57ec = uVar4;
  _DAT_006e5be4 = uVar4;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
  FUN_004ccf5b(1,unaff_EBP + -0x2c,unaff_EBP + -0x38,uVar4);
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 0;
  FUN_004cdcd0(unaff_EBP + -0x10);
  uVar4 = FUN_004cdbd1(0xffffffff,unaff_EBP + -0xb0,2,0,unaff_EBP + -0x2c,unaff_EBP + -0x38,
                       unaff_EBP + -0x14);
  _DAT_006e57f0 = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  FUN_004ccf5b(2,unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 1;
  FUN_004cdcd0(unaff_EBP + -0x10);
  uVar4 = FUN_004cdbd1(0xffffffff,unaff_EBP + -0xb0,3,0,unaff_EBP + -0x2c,unaff_EBP + -0x38,
                       unaff_EBP + -0x14);
  _DAT_006e581c = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  FUN_004ccf5b(0xd,unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 3;
  FUN_004cdcd0(unaff_EBP + -0x10);
  uVar4 = FUN_004cdbd1(0xffffffff,unaff_EBP + -0xb0,4,0,unaff_EBP + -0x2c,unaff_EBP + -0x38,
                       unaff_EBP + -0x14);
  _DAT_006e5818 = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  FUN_004ccf5b(0xc,unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 2;
  FUN_004cdcd0(unaff_EBP + -0x10);
  uVar4 = FUN_004cdbd1(0xffffffff,unaff_EBP + -0xb0,5,0,unaff_EBP + -0x2c,unaff_EBP + -0x38,
                       unaff_EBP + -0x14);
  _DAT_006e5820 = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  FUN_004ccf5b(0xe,unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 4;
  FUN_004cdcd0(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -0x3c) = DAT_006f0ba8;
  FUN_004c5d8d();
  while( true ) {
    cVar3 = FUN_004c5da6(unaff_EBP + -0x20,unaff_EBP + -0x2c,unaff_EBP + -0x38,unaff_EBP + -0x14);
    if (cVar3 == '\0') break;
    pvVar5 = operator_new(0x60);
    *(void **)(unaff_EBP + -0x44) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    if (pvVar5 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_004cb8d2();
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(undefined4 *)(unaff_EBP + -0x40) = uVar4;
    FUN_004ccfef(*(undefined4 *)(unaff_EBP + -0x20),unaff_EBP + -0x2c,unaff_EBP + -0x38,
                 *(undefined4 *)(unaff_EBP + -0x14));
    *(int *)(*(int *)(*(int *)(unaff_EBP + -0x40) + 0x20) + 8) = *(int *)(unaff_EBP + -0x20) + 1;
    FUN_004cdcd0(unaff_EBP + -0x40);
  }
  FUN_004c5ec5();
  FUN_00470383(unaff_EBP + -0x404,0x84,0);
  uVar4 = FUN_004cdbd1(0xdcd,unaff_EBP + -0xb0,1,unaff_EBP + -0x1c,unaff_EBP + -0x2c,
                       unaff_EBP + -0x38,unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_005a5631(0xe13,unaff_EBP + -0x18,4);
  FUN_004cd046(*(undefined4 *)(unaff_EBP + -0x1c),0xb,*(undefined4 *)(unaff_EBP + -0x18),
               unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 0;
  FUN_004cdcd0(unaff_EBP + -0x10);
  FUN_00470383(unaff_EBP + -0x404,0x85,0);
  uVar4 = FUN_004cdbd1(0xed8,unaff_EBP + -0xb0,1,unaff_EBP + -0x1c,unaff_EBP + -0x2c,
                       unaff_EBP + -0x38,unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  DAT_006c5fe8 = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_005a5631(0xe14,unaff_EBP + -0x18,4);
  FUN_004cd046(*(undefined4 *)(unaff_EBP + -0x1c),1,*(undefined4 *)(unaff_EBP + -0x18),
               unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 0;
  FUN_004cdcd0(unaff_EBP + -0x10);
  uVar4 = FUN_004cdbd1(0xdc0,unaff_EBP + -0xb0,2,unaff_EBP + -0x1c,unaff_EBP + -0x2c,
                       unaff_EBP + -0x38,unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  DAT_006c618c = *(undefined4 *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_005a5631(0xe18,unaff_EBP + -0x18,4);
  FUN_004cd046(*(undefined4 *)(unaff_EBP + -0x1c),1,*(undefined4 *)(unaff_EBP + -0x18),
               unaff_EBP + -0x2c,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x20) + 8) = 1;
  FUN_004cdcd0(unaff_EBP + -0x10);
  iVar7 = FUN_0043ac6a();
  *(int *)(unaff_EBP + -0x40) = iVar7;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  if (0 < iVar7) {
    do {
      uVar4 = FUN_0043ad1f(*(undefined4 *)(unaff_EBP + -0x20));
      *(undefined4 *)(unaff_EBP + -0x3c) = uVar4;
      cVar3 = FUN_00457724();
      if (cVar3 == '\0') {
        cVar3 = FUN_0045773e();
        if (cVar3 == '\0') {
          cVar3 = FUN_004576f4();
          if (cVar3 == '\0') {
            cVar3 = FUN_0045770d();
            if (cVar3 == '\0') goto LAB_004cda3a;
          }
          pvVar5 = operator_new(0x60);
          *(void **)(unaff_EBP + -0x44) = pvVar5;
          *(undefined1 *)(unaff_EBP + -4) = 6;
          if (pvVar5 == (void *)0x0) {
            iVar7 = 0;
          }
          else {
            iVar7 = FUN_004cb8d2();
          }
          *(undefined1 *)(unaff_EBP + -4) = 3;
          *(int *)(unaff_EBP + -0x10) = iVar7;
          if (iVar7 != 0) {
            FUN_004cbed3(*(undefined4 *)(unaff_EBP + -0x3c));
            FUN_004cdcd0(unaff_EBP + -0x10);
          }
        }
      }
LAB_004cda3a:
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
    } while (*(int *)(unaff_EBP + -0x20) < *(int *)(unaff_EBP + -0x40));
  }
  if (2 < (uint)(*(int *)(extraout_ECX + 8) - *piVar1 >> 2)) {
    FUN_004cde26(*piVar1,*(undefined4 *)(extraout_ECX + 8),FUN_004cdb34);
  }
  if (DAT_006f29ec != '\0') {
    FUN_005c1719();
    iVar7 = *(int *)(extraout_ECX + 8);
    iVar8 = 0;
    iVar2 = *piVar1;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    if (0 < (int)(iVar7 - iVar2 & 0xfffffffcU)) {
      do {
        FUN_004cc7f7(unaff_EBP + 8);
        FUN_005a5e48(0);
        FUN_004cc832(2,unaff_EBP + 8);
        FUN_005a5e48(0);
        FUN_004cc832(3,unaff_EBP + 8);
        FUN_005a5e48(0);
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(extraout_ECX + 8) - *piVar1 >> 2);
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005a5e09();
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00470467();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

