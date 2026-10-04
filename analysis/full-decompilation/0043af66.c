
void FUN_0043af66(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  puVar3 = operator_new(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
  }
  *(undefined4 **)(extraout_ECX + 0x1c) = puVar3;
  pvVar4 = operator_new(0x14);
  *(void **)(unaff_EBP + -0x1c) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else {
    FUN_0043e465();
  }
  uVar5 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(void **)(extraout_ECX + 0x18) = pvVar4;
  *(undefined1 *)(extraout_ECX + 0x1240) = *(undefined1 *)(unaff_EBP + 0xc);
  FUN_0046f8cb(uVar5);
  FUN_0046f8e4(extraout_ECX + 0x470);
  uVar6 = 0xffffffff;
  uVar5 = FUN_0041532c(0x18,0xffffffff);
  FUN_0046f847(uVar5,uVar6);
  uVar5 = *(undefined4 *)(extraout_ECX + 0x34);
  FUN_005b8e25(uVar5);
  cVar2 = FUN_005b9b60(uVar5);
  if (cVar2 == '\0') {
    uVar5 = *(undefined4 *)(extraout_ECX + 0x34);
    uVar7 = 1;
    uVar6 = 1;
    FUN_005b8e25(uVar5,1,1);
    FUN_005b92ee(uVar5,uVar6,uVar7);
  }
  FUN_0046f8e4(extraout_ECX + 0x470);
  uVar6 = 0xffffffff;
  uVar5 = FUN_0041532c(0x17,0xffffffff);
  FUN_0046f847(uVar5,uVar6);
  uVar5 = *(undefined4 *)(extraout_ECX + 0x144);
  FUN_005b8e25(uVar5);
  cVar2 = FUN_005b9b60(uVar5);
  if (cVar2 == '\0') {
    uVar5 = *(undefined4 *)(extraout_ECX + 0x144);
    uVar7 = 1;
    uVar6 = 1;
    FUN_005b8e25(uVar5,1,1);
    FUN_005b92ee(uVar5,uVar6,uVar7);
  }
  FUN_0046f8e4(extraout_ECX + 0x470);
  uVar6 = 0xffffffff;
  uVar5 = FUN_0041532c(0x19,0xffffffff);
  FUN_0046f847(uVar5,uVar6);
  uVar5 = *(undefined4 *)(extraout_ECX + 0x254);
  FUN_005b8e25(uVar5);
  cVar2 = FUN_005b9b60(uVar5);
  if (cVar2 == '\0') {
    uVar5 = *(undefined4 *)(extraout_ECX + 0x254);
    uVar7 = 1;
    uVar6 = 1;
    FUN_005b8e25(uVar5,1,1);
    FUN_005b92ee(uVar5,uVar6,uVar7);
  }
  bVar1 = *(byte *)(DAT_006e486c + 0x66);
  *(undefined1 *)(unaff_EBP + 0xf) = *(undefined1 *)(DAT_006e486c + 0x68);
  if ((bVar1 & 1) != 0) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar5 = 0xffffffff;
    if (*(char *)(unaff_EBP + 0xf) == '\0') {
      uVar6 = 0x1b;
    }
    else {
      uVar6 = 0x4b;
    }
    uVar6 = FUN_0041532c(uVar6,0xffffffff);
    FUN_0046f847(uVar6,uVar5);
    uVar5 = *(undefined4 *)(extraout_ECX + 0x694);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0x694);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar5 = 0xffffffff;
    if (*(char *)(unaff_EBP + 0xf) == '\0') {
      uVar6 = 0x1e;
    }
    else {
      uVar6 = 0x4c;
    }
    uVar6 = FUN_0041532c(uVar6,0xffffffff);
    FUN_0046f847(uVar6,uVar5);
    uVar5 = *(undefined4 *)(extraout_ECX + 0x7a4);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0x7a4);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar5 = 0xffffffff;
    if (*(char *)(unaff_EBP + 0xf) == '\0') {
      uVar6 = 0x24;
    }
    else {
      uVar6 = 0x4d;
    }
    uVar6 = FUN_0041532c(uVar6,0xffffffff);
    FUN_0046f847(uVar6,uVar5);
    uVar5 = *(undefined4 *)(extraout_ECX + 0x8b4);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0x8b4);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar5 = 0xffffffff;
    if (*(char *)(unaff_EBP + 0xf) == '\0') {
      uVar6 = 0x2a;
    }
    else {
      uVar6 = 0x4e;
    }
    uVar6 = FUN_0041532c(uVar6,0xffffffff);
    FUN_0046f847(uVar6,uVar5);
    uVar5 = *(undefined4 *)(extraout_ECX + 0x9c4);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0x9c4);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x10) != 0) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar5 = 0xffffffff;
    if (*(char *)(unaff_EBP + 0xf) == '\0') {
      uVar6 = 0x30;
    }
    else {
      uVar6 = 0x4a;
    }
    uVar6 = FUN_0041532c(uVar6,0xffffffff);
    FUN_0046f847(uVar6,uVar5);
    uVar5 = *(undefined4 *)(extraout_ECX + 0xad4);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0xad4);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar5 = 0xffffffff;
    if (*(char *)(unaff_EBP + 0xf) == '\0') {
      uVar6 = 0x36;
    }
    else {
      uVar6 = 0x4f;
    }
    uVar6 = FUN_0041532c(uVar6,0xffffffff);
    FUN_0046f847(uVar6,uVar5);
    uVar5 = *(undefined4 *)(extraout_ECX + 0xbe4);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0xbe4);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar6 = 0xffffffff;
    uVar5 = FUN_0041532c(0x3c,0xffffffff);
    FUN_0046f847(uVar5,uVar6);
    uVar5 = *(undefined4 *)(extraout_ECX + 0xcf4);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0xcf4);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar5 = 0xffffffff;
    if (*(char *)(unaff_EBP + 0xf) == '\0') {
      uVar6 = 0x5a;
    }
    else {
      uVar6 = 0x51;
    }
    uVar6 = FUN_0041532c(uVar6,0xffffffff);
    FUN_0046f847(uVar6,uVar5);
    uVar5 = *(undefined4 *)(extraout_ECX + 0xe04);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0xe04);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  if (3 < *(short *)(DAT_006e486c + 0x66)) {
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar6 = 0xffffffff;
    uVar5 = FUN_0041532c(0x42,0xffffffff);
    FUN_0046f847(uVar5,uVar6);
    uVar5 = *(undefined4 *)(extraout_ECX + 0xf14);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0xf14);
      uVar7 = 1;
      uVar6 = 1;
      FUN_005b8e25(uVar5,1,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
    FUN_0046f8e4(extraout_ECX + 0x470);
    uVar6 = 0xffffffff;
    uVar5 = FUN_0041532c(0x52,0xffffffff);
    FUN_0046f847(uVar5,uVar6);
    uVar5 = *(undefined4 *)(extraout_ECX + 0x1024);
    FUN_005b8e25(uVar5);
    cVar2 = FUN_005b9b60(uVar5);
    if (cVar2 == '\0') {
      uVar5 = *(undefined4 *)(extraout_ECX + 0x1024);
      uVar7 = 1;
      uVar6 = 0;
      FUN_005b8e25(uVar5,0,1);
      FUN_005b92ee(uVar5,uVar6,uVar7);
    }
  }
  FUN_0046f8e4(extraout_ECX + 0x470);
  uVar6 = 0xffffffff;
  uVar5 = FUN_0041532c(0x1a,0xffffffff);
  FUN_0046f847(uVar5,uVar6);
  uVar5 = *(undefined4 *)(extraout_ECX + 0x584);
  FUN_005b8e25(uVar5);
  cVar2 = FUN_005b9b60(uVar5);
  if (cVar2 == '\0') {
    uVar5 = *(undefined4 *)(extraout_ECX + 0x584);
    uVar7 = 1;
    uVar6 = 1;
    FUN_005b8e25(uVar5,1,1);
    FUN_005b92ee(uVar5,uVar6,uVar7);
  }
  FUN_0043b76d(extraout_ECX + 0x470);
  FUN_0043b76d(extraout_ECX + 0x30);
  FUN_0043b76d(extraout_ECX + 0x140);
  FUN_0043b76d(extraout_ECX + 0x250);
  FUN_0043b76d(extraout_ECX + 0x580);
  if ((*(byte *)(DAT_006e486c + 0x66) & 1) != 0) {
    FUN_0043b76d(extraout_ECX + 0x690);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
    FUN_0043b76d(extraout_ECX + 0x7a0);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
    FUN_0043b76d(extraout_ECX + 0x8b0);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
    FUN_0043b76d(extraout_ECX + 0x9c0);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x10) != 0) {
    FUN_0043b76d(extraout_ECX + 0xad0);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
    FUN_0043b76d(extraout_ECX + 0xbe0);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
    FUN_0043b76d(extraout_ECX + 0xcf0);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
    FUN_0043b76d(extraout_ECX + 0xe00);
  }
  if (3 < *(short *)(DAT_006e486c + 0x66)) {
    FUN_0043b76d(extraout_ECX + 0xf10);
    FUN_0043b76d(extraout_ECX + 0x1020);
  }
  FUN_0046f824(unaff_EBP + -0x230,0,0x104);
  *(undefined ***)(unaff_EBP + -0x23c) = &PTR_FUN_006664e8;
  FUN_0046f8e4(extraout_ECX + 0x30);
  FUN_0046f847(s_Global_006c0a60,0xffffffff);
  uVar5 = FUN_0043e530(unaff_EBP + -0x23c,*(undefined1 *)(extraout_ECX + 0x1243));
  *(undefined4 *)(extraout_ECX + 0x2c) = uVar5;
  FUN_0046f824(unaff_EBP + -0x120,0,0x104);
  *(undefined ***)(unaff_EBP + -300) = &PTR_FUN_006664e8;
  FUN_0046f8e4(extraout_ECX + 0x470);
  uVar6 = 0xffffffff;
  uVar5 = FUN_0041532c(0,0xffffffff);
  FUN_0046f847(uVar5,uVar6);
  FUN_0046f847(s_Breakpts_txt_006c3548,0xffffffff);
  FUN_004023f7(unaff_EBP + -300);
  FUN_00403d7c();
  FUN_00405376();
  FUN_0043c6ee();
  FUN_004ff6fa(0x61616161,s_Loading_Global_Animations_006c352c);
  FUN_0059d6eb();
  FUN_004ff6fa(0x6f636e73,s_Importing_Tuning_txt_006c3514);
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0043cc48(unaff_EBP + -0x18);
  *(undefined1 *)(extraout_ECX + 0x14) = 1;
  FUN_0040766a(0xe0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

