
void FUN_005837c0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  void *pvVar4;
  undefined4 uVar5;
  size_t sVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  if (DAT_006f6b60 == '\0') {
    FUN_005bc36d();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005bc41e();
    FUN_005b8680();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8680();
    uVar5 = *(undefined4 *)(unaff_EBP + 8);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    DAT_006f6b68 = uVar5;
    pvVar4 = operator_new(0x44);
    *(void **)(unaff_EBP + 8) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar4 == (void *)0x0) {
      DAT_006f6b64 = 0;
    }
    else {
      DAT_006f6b64 = FUN_0059df18(uVar5);
    }
    pcVar7 = *(char **)(*(int *)(unaff_EBP + 0xc) + 4);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    *(char **)(unaff_EBP + 0xc) = pcVar7;
    FUN_005bc436();
    uVar5 = FUN_005b8e25();
    *(undefined4 *)(unaff_EBP + -0x28) = uVar5;
    FUN_005bc41e();
    FUN_005d4bbf(&DAT_006de560);
    sVar6 = _strlen(pcVar7);
    FUN_00412d8a(pcVar7,pcVar7 + sVar6);
    pcVar7 = (char *)FUN_0041532c(0x16);
    sVar6 = _strlen(pcVar7);
    FUN_00412d8a(pcVar7,pcVar7 + sVar6);
    sVar6 = _strlen(&DAT_006c145c);
    FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    *(undefined4 *)(unaff_EBP + 8) = 1;
    do {
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 0xc));
      sVar6 = _strlen(&DAT_006d0478);
      FUN_00412d8a(&DAT_006d0478,&DAT_006d0478 + sVar6);
      if (*(int *)(unaff_EBP + 8) != 1) {
        FUN_00635858(unaff_EBP + -0x44,&DAT_006c08e4,*(undefined4 *)(unaff_EBP + 8));
        sVar6 = _strlen((char *)(unaff_EBP + -0x44));
        FUN_00412d8a(unaff_EBP + -0x44,unaff_EBP + -0x44 + sVar6);
      }
      uVar5 = FUN_004096c2();
      cVar3 = FUN_005b9a53(uVar5);
      if (cVar3 != '\0') {
        sVar6 = _strlen(&DAT_006c145c);
        FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
        FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
      }
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
    } while (*(int *)(unaff_EBP + 8) < 0xb);
    FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 0xc));
    sVar6 = _strlen(s_cmxpreview_006d046c);
    FUN_00412d8a(s_cmxpreview_006d046c,s_cmxpreview_006d046c + sVar6);
    uVar5 = FUN_004096c2();
    cVar3 = FUN_005b9a53(uVar5);
    if (cVar3 != '\0') {
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
    }
    *(undefined4 *)(unaff_EBP + 8) = 1;
    do {
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 0xc));
      sVar6 = _strlen(s_People_006d0464);
      FUN_00412d8a(s_People_006d0464,s_People_006d0464 + sVar6);
      FUN_00635858(unaff_EBP + -0x44,&DAT_006c08e4,*(undefined4 *)(unaff_EBP + 8));
      sVar6 = _strlen((char *)(unaff_EBP + -0x44));
      FUN_00412d8a(unaff_EBP + -0x44,unaff_EBP + -0x44 + sVar6);
      uVar5 = FUN_004096c2();
      cVar3 = FUN_005b9a53(uVar5);
      if (cVar3 != '\0') {
        sVar6 = _strlen(&DAT_006c145c);
        FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
        FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
      }
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
    } while (*(int *)(unaff_EBP + 8) < 3);
    *(undefined4 *)(unaff_EBP + 8) = 1;
    do {
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 0xc));
      sVar6 = _strlen(s_Accessories_006d0458);
      FUN_00412d8a(s_Accessories_006d0458,s_Accessories_006d0458 + sVar6);
      FUN_00635858(unaff_EBP + -0x44,&DAT_006c08e4,*(undefined4 *)(unaff_EBP + 8));
      sVar6 = _strlen((char *)(unaff_EBP + -0x44));
      FUN_00412d8a(unaff_EBP + -0x44,unaff_EBP + -0x44 + sVar6);
      uVar5 = FUN_004096c2();
      cVar3 = FUN_005b9a53(uVar5);
      if (cVar3 != '\0') {
        sVar6 = _strlen(&DAT_006c145c);
        FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
        FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
      }
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
    } while (*(int *)(unaff_EBP + 8) < 3);
    if (3 < *(short *)(DAT_006e486c + 0x66)) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x45);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x46);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x48);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x49);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x52);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x44);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x5d);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x5f);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x5c);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x3f);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x41);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x3e);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x39);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x3b);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x38);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x10) != 0) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x33);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x35);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x32);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x2d);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x2f);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x2c);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x27);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x29);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x26);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x21);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x23);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x20);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    if ((*(byte *)(DAT_006e486c + 0x66) & 1) != 0) {
      sVar6 = _strlen(&DAT_006c5bc4);
      FUN_00412d8a(&DAT_006c5bc4,&DAT_006c5bc4 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x1b);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006d0454);
      FUN_00412d8a(&DAT_006d0454,&DAT_006d0454 + sVar6);
      pcVar7 = (char *)FUN_0041532c(0x1d);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0043beaa(unaff_EBP + -0x34);
    iVar8 = (*(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x34)) / 0x110;
    iVar9 = iVar8 + -1;
    if (-1 < iVar9) {
      iVar9 = iVar9 * 0x110;
      *(int *)(unaff_EBP + 8) = iVar9;
      *(int *)(unaff_EBP + -0x48) = iVar8;
      while( true ) {
        puVar10 = (undefined4 *)(iVar9 + *(int *)(unaff_EBP + -0x34));
        FUN_00405584(puVar10);
        (**(code **)*puVar10)();
        FUN_0046f824(unaff_EBP + -0x198,0,0x104);
        puVar2 = (undefined4 *)*puVar10;
        *(undefined ***)(unaff_EBP + -0x1a4) = &PTR_FUN_006664e8;
        iVar9 = (*(code *)*puVar2)();
        FUN_0046f917(puVar10,iVar9 + -1);
        FUN_0046f824(unaff_EBP + -0x2a8,0,0x104);
        *(undefined ***)(unaff_EBP + -0x2b4) = &PTR_FUN_006664e8;
        FUN_0046f824(unaff_EBP + -0x3b8,0,0x104);
        *(undefined ***)(unaff_EBP + -0x3c4) = &PTR_FUN_006664e8;
        FUN_0046f824(unaff_EBP + -0x4c8,0,0x104);
        *(undefined ***)(unaff_EBP + -0x4d4) = &PTR_FUN_006664e8;
        FUN_0041207e(unaff_EBP + -0x1a4,unaff_EBP + -0x4d4,unaff_EBP + -0x2b4,unaff_EBP + -0x3c4);
        FUN_0046f917(unaff_EBP + -0x2b4,0xffffffff);
        FUN_0046f847(&DAT_006d044c,0xffffffff);
        uVar5 = *(undefined4 *)(unaff_EBP + -0x5e0);
        FUN_005b8e25(uVar5);
        cVar3 = FUN_005b9a53(uVar5);
        if (cVar3 == '\0') {
          pcVar7 = (char *)puVar10[1];
          sVar6 = _strlen(pcVar7);
          FUN_00412d8a(pcVar7,pcVar7 + sVar6);
          sVar6 = _strlen(&DAT_006c145c);
          FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
          FUN_005873e1(*(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + -0x34));
        }
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + -0x110;
        piVar1 = (int *)(unaff_EBP + -0x48);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) break;
        iVar9 = *(int *)(unaff_EBP + 8);
      }
    }
    iVar9 = *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18);
    if ((0 < iVar9) && (*(char *)(iVar9 + -1 + *(int *)(unaff_EBP + -0x18)) == ';')) {
      FUN_005481eb(iVar9 + -1,0);
    }
    pvVar4 = operator_new(0xc);
    *(void **)(unaff_EBP + 8) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    if (pvVar4 == (void *)0x0) {
      DAT_006f6b70 = 0;
    }
    else {
      DAT_006f6b70 = FUN_005c2dfa(*(undefined4 *)(unaff_EBP + -0x18));
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    iVar9 = FUN_004096c2();
    iVar8 = FUN_00401f73();
    for (; iVar9 != iVar8; iVar9 = iVar9 + 0xc) {
      FUN_005b86bd(iVar9);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005bc36d();
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005bc41e();
      uVar5 = *(undefined4 *)(unaff_EBP + -0x54);
      FUN_005b8e25(uVar5);
      cVar3 = FUN_005b9b60(uVar5);
      if (cVar3 == '\0') {
        uVar12 = 1;
        uVar11 = 1;
        uVar5 = *(undefined4 *)(unaff_EBP + -0x54);
        FUN_005b8e25(uVar5,1,1);
        FUN_005b92ee(uVar5,uVar11,uVar12);
      }
      FUN_005bc436();
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005bc3da();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
    }
    FUN_005bc436();
    FUN_005bc41e();
    FUN_0059f6cf(DAT_006f6b70,0,0,0);
    FUN_005bc436();
    FUN_005bc41e();
    FUN_005d4bbf(&DAT_006de560);
    FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 0xc));
    sVar6 = _strlen(s_Animation_006d0440);
    FUN_00412d8a(s_Animation_006d0440,s_Animation_006d0440 + sVar6);
    uVar5 = FUN_004096c2();
    cVar3 = FUN_005b9a53(uVar5);
    if (cVar3 != '\0') {
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
    }
    for (iVar9 = *(int *)(unaff_EBP + -0x34); iVar9 != *(int *)(unaff_EBP + -0x30);
        iVar9 = iVar9 + 0x110) {
      pcVar7 = *(char **)(iVar9 + 4);
      sVar6 = _strlen(pcVar7);
      FUN_00412d8a(pcVar7,pcVar7 + sVar6);
      sVar6 = _strlen(&DAT_006c145c);
      FUN_00412d8a(&DAT_006c145c,&DAT_006c145c + sVar6);
    }
    iVar9 = *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18);
    if ((0 < iVar9) && (*(char *)(iVar9 + -1 + *(int *)(unaff_EBP + -0x18)) == ';')) {
      FUN_005481eb(iVar9 + -1,0);
    }
    pvVar4 = operator_new(0xc);
    *(void **)(unaff_EBP + 8) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    if (pvVar4 == (void *)0x0) {
      DAT_006f6b6c = 0;
    }
    else {
      DAT_006f6b6c = FUN_005c2dfa(*(undefined4 *)(unaff_EBP + -0x18));
    }
    *(undefined1 *)(unaff_EBP + -4) = 4;
    iVar9 = FUN_004096c2();
    iVar8 = FUN_00401f73();
    for (; iVar9 != iVar8; iVar9 = iVar9 + 0xc) {
      FUN_005b86bd(iVar9);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005bc36d();
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_005bc41e();
      uVar5 = *(undefined4 *)(unaff_EBP + -0x54);
      FUN_005b8e25(uVar5);
      cVar3 = FUN_005b9b60(uVar5);
      if (cVar3 == '\0') {
        uVar12 = 1;
        uVar11 = 1;
        uVar5 = *(undefined4 *)(unaff_EBP + -0x54);
        FUN_005b8e25(uVar5,1,1);
        FUN_005b92ee(uVar5,uVar11,uVar12);
      }
      FUN_005bc436();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005bc3da();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
    }
    FUN_005bc436();
    FUN_005bc41e();
    FUN_005a009d(DAT_006f6b6c);
    FUN_005bc436();
    DAT_006f6b60 = '\x01';
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00415722();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005bc3da();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

