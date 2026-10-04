
undefined1 FUN_004d8d7f(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 uVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar2 = (undefined4 *)FUN_004102ab(*(undefined4 *)(unaff_EBP + 0x10));
  if (puVar2 == (undefined4 *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = FUN_004e988f(*puVar2);
  }
  if (iVar3 == -1) {
    uVar6 = 0;
  }
  else {
    FUN_004e9c34(iVar3,unaff_EBP + -0x24);
    uVar4 = FUN_005b86bd(unaff_EBP + -0x24);
    puVar2 = *(undefined4 **)(unaff_EBP + 8);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    uVar4 = FUN_004d6554(unaff_EBP + -0x18,*(int *)(unaff_EBP + 0x10) + 1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    iVar5 = FUN_004eabb1(iVar3);
    uVar4 = DAT_006f0fc0;
    if (iVar5 != 0) {
      uVar4 = FUN_004096c2();
    }
    uVar4 = FUN_005b870f(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    iVar5 = FUN_004eaa44(iVar3);
    uVar4 = DAT_006f0f70;
    if (iVar5 != 0) {
      uVar4 = FUN_004096c2();
    }
    uVar4 = FUN_005b870f(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    iVar5 = FUN_004eaa44(iVar3);
    if (iVar5 == 0) {
      iVar5 = FUN_004ea79e(iVar3);
      if (((*(short *)(iVar5 + 0xa0) < 1) || (iVar5 = FUN_004ea83d(iVar3), iVar5 != 0)) ||
         ((*(byte *)(DAT_006e486c + 0x66) & 0x40) == 0)) {
        iVar5 = FUN_004ea83d(iVar3);
        if (iVar5 == 0) {
          uVar4 = FUN_004096c2();
        }
        else {
          FUN_004ea83d(iVar3);
          uVar4 = FUN_0060b848();
        }
        uVar4 = FUN_005b870f(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        iVar5 = FUN_004ea85e(iVar3);
        if (iVar5 == 0) {
          uVar4 = FUN_004096c2();
        }
        else {
          iVar5 = FUN_004eabb1(iVar3);
          uVar4 = CONCAT31((int3)((uint)-(iVar5 + -1) >> 8),'\x01' - (iVar5 + -1 != 0));
          FUN_004ea85e(iVar3,uVar4);
          uVar4 = FUN_004033ea(uVar4);
        }
        uVar4 = FUN_005b870f(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        uVar4 = FUN_004ea9c8(iVar3);
        uVar4 = FUN_004d6554(unaff_EBP + -0x3c,uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0xd;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        iVar5 = FUN_004ea85e(iVar3);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          FUN_004ea85e(iVar3);
          uVar4 = FUN_004cebb0();
        }
        uVar4 = FUN_004d6554(unaff_EBP + -0x3c,uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
      else {
        uVar4 = FUN_004096c2();
        uVar4 = FUN_005b870f(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        uVar4 = FUN_0040542d();
        *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
        FUN_005b870f(&DAT_006de560);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        if (*(int *)(unaff_EBP + 0xc) != 0) {
          iVar5 = FUN_004ea79e(iVar3);
          uVar4 = FUN_00405216(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0xa2));
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005d499c(uVar4);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_005b8770();
        }
        uVar4 = FUN_005b86bd(unaff_EBP + -0x18);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005b8770();
        uVar4 = FUN_004096c2();
        uVar4 = FUN_005b870f(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005b8770();
        uVar4 = FUN_004096c2();
        uVar4 = FUN_005b870f(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 10;
        FUN_005d499c(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + 0xc) = *puVar2;
      uVar4 = FUN_004096c2();
      FUN_005d4bbf(uVar4);
      *(undefined4 *)(unaff_EBP + 0xc) = *puVar2;
      uVar4 = FUN_004096c2();
      FUN_005d4bbf(uVar4);
      FUN_004ea85e(iVar3);
      *(undefined4 *)(unaff_EBP + 0xc) = *puVar2;
      uVar4 = FUN_004ea9c8(iVar3);
      uVar4 = FUN_004034e6(uVar4);
      FUN_005d4bbf(uVar4);
      iVar5 = FUN_004ea85e(iVar3);
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        FUN_004ea85e(iVar3);
        uVar4 = FUN_004cebb0();
      }
      uVar4 = FUN_004d6554(unaff_EBP + -0x3c,uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      FUN_005d499c(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0;
    }
    FUN_005b8770();
    uVar4 = FUN_004e9bbd(iVar3);
    FUN_005b86bd(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005d499c(unaff_EBP + -0x30);
    uVar4 = FUN_004e8d71(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x11;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0xe) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x12;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0xc) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x13;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 6) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x14;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 10) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x15;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 4) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x16;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0x14) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x17;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0x18) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x18;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0x16) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x19;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0x22) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x1a;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0x24) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x1b;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x3c,(int)*(short *)(iVar5 + 0x1e) / 100);
    *(undefined1 *)(unaff_EBP + -4) = 0x1c;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    uVar4 = FUN_004ea79e(iVar3);
    uVar4 = FUN_0048432f(uVar4);
    uVar4 = FUN_00484411(uVar4);
    uVar4 = FUN_005b870f(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x1d;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    iVar5 = FUN_004eac16(iVar3);
    if (iVar5 == 0) {
      uVar4 = FUN_004096c2();
      uVar4 = FUN_005b870f(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0x1e;
      FUN_005d499c(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
    }
    else if (iVar5 == 1) {
      uVar4 = FUN_004096c2();
      uVar4 = FUN_005b870f(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0x1f;
      FUN_005d499c(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
    }
    else if (iVar5 == 2) {
      uVar4 = FUN_004096c2();
      uVar4 = FUN_005b870f(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0x20;
      FUN_005d499c(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
    }
    else {
      uVar4 = FUN_004096c2();
      uVar4 = FUN_005b870f(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0x21;
      FUN_005d499c(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
    }
    FUN_005b8770();
    iVar5 = FUN_004ea79e(iVar3);
    uVar4 = FUN_004d6554(unaff_EBP + -0x54,(int)*(short *)(iVar5 + 0xa0));
    *(undefined1 *)(unaff_EBP + -4) = 0x22;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + 0x10) = 0;
    cVar1 = FUN_004eb1ae(iVar3);
    if (cVar1 != '\0') {
      *(undefined4 *)(unaff_EBP + 0x10) = 1;
    }
    uVar4 = FUN_004d6554(unaff_EBP + -0x54,*(undefined4 *)(unaff_EBP + 0x10));
    *(undefined1 *)(unaff_EBP + -4) = 0x23;
    FUN_005d499c(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0x10;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    uVar6 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

