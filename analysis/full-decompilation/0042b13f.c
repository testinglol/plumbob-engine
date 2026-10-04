
void FUN_0042b13f(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  uint uVar5;
  undefined4 extraout_ECX;
  uint uVar6;
  int unaff_EBP;
  int iVar7;
  undefined **ppuStack_384;
  undefined *puStack_380;
  int iStack_37c;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  timeGetTime();
  iStack_37c = 0x42b168;
  FUN_005bc6cb();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  FUN_0042af8c();
  piVar4 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(byte *)((int)piVar4 + 0x66) & 8) == 0) goto LAB_0042b8e2;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  while( true ) {
    iStack_37c = 0x42b198;
    iVar1 = FUN_0043ad1f();
    if (iVar1 == 0) break;
    if ((*(short *)(*(int *)(iVar1 + 0x60) + 0x12) == 0x200) && (*(int *)(unaff_EBP + -0x1c) == 0))
    {
      uVar2 = FUN_0045741b();
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar2;
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  }
  iVar7 = 3000;
  *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + 8);
  iVar1 = *(int *)(unaff_EBP + -0x14);
  piVar4 = (int *)(iVar1 + 0x154);
  do {
    uVar6 = 0;
    if (*(int *)(iVar1 + 0x158) - *piVar4 >> 2 != 0) {
      do {
        if (*(int *)(*(int *)(*piVar4 + uVar6 * 4) + 0x10c) == iVar7) {
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + -1;
          break;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)(*(int *)(iVar1 + 0x158) - *piVar4 >> 2));
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xbc2);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x128) = &PTR_FUN_0066643c;
  iStack_37c = unaff_EBP + -0x128;
  puStack_380 = &DAT_006c265c;
  ppuStack_384 = (undefined **)0xa0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004fff98();
  if (0 < *(int *)(unaff_EBP + 8)) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x29c) = &PTR_FUN_0066643c;
    iStack_37c = unaff_EBP + -0x29c;
    puStack_380 = (undefined *)0x9;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    ppuStack_384 = (undefined **)0x42b267;
    puStack_380 = (undefined *)FUN_0041532c();
    ppuStack_384 = (undefined **)0xe6;
    FUN_004fff98();
    pvVar3 = operator_new(0x13c);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar3 == (void *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
    }
    else {
      uVar2 = FUN_00525cfd();
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (*(int *)(unaff_EBP + -0x18) != 0) {
      iStack_37c = 2;
      puStack_380 = (undefined *)0x42b2b6;
      FUN_004705f2();
      iStack_37c = 0x42b2bf;
      FUN_005d4956();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      iStack_37c = 0x42b2cf;
      FUN_00525fb7();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      iStack_37c = 3;
      puStack_380 = (undefined *)0x42b2ea;
      FUN_004705f2();
      iStack_37c = 0x42b2f3;
      FUN_005d4956();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      iStack_37c = 0x42b303;
      FUN_005260e7();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      iStack_37c = unaff_EBP + -0x10;
      puStack_380 = (undefined *)0x1383;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      ppuStack_384 = (undefined **)0x42b322;
      FUN_005a5631();
      if (*(int *)(unaff_EBP + -0x10) != 0) {
        iStack_37c = *(int *)(unaff_EBP + -0x10);
        puStack_380 = (undefined *)0x42b337;
        FUN_005260b1();
      }
      piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
      piVar4 = (int *)(**(code **)(*piVar4 + 8))();
      (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x138))();
      iStack_37c = 0x42b360;
      (**(code **)(*piVar4 + 0x20))();
      piVar4 = *(int **)(unaff_EBP + -0x18);
      iStack_37c = 0x42b36d;
      (**(code **)(*piVar4 + 0x94))();
      iStack_37c = 0x42b374;
      (**(code **)(*piVar4 + 0x44))();
      iStack_37c = *(undefined4 *)(unaff_EBP + 8);
      puStack_380 = (undefined *)0x42b37e;
      FUN_00526e66();
      iStack_37c = 0x42b38e;
      (*(code *)**(undefined4 **)(DAT_006e486c[0x13] + 0x48))();
    }
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x374) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x1c4) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x308) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x230) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(unaff_EBP + -0x10) = 3000;
LAB_0042b3f4:
    uVar6 = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    piVar4 = (int *)(*(int *)(unaff_EBP + -0x14) + 0x154);
    if (*(int *)(*(int *)(unaff_EBP + -0x14) + 0x158) - *piVar4 >> 2 != 0) {
      iVar1 = *piVar4;
      do {
        if (*(int *)(*(int *)(iVar1 + uVar6 * 4) + 0x10c) == *(int *)(unaff_EBP + -0x10)) {
          iVar1 = *(int *)(iVar1 + uVar6 * 4);
          *(int *)(unaff_EBP + -0x28) = iVar1;
          if (iVar1 != 0) goto LAB_0042b852;
          break;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)(*(int *)(*(int *)(unaff_EBP + -0x14) + 0x158) -
                              *(int *)(*(int *)(unaff_EBP + -0x14) + 0x154) >> 2));
    }
    iStack_37c = unaff_EBP + -0x374;
    puStack_380 = &DAT_006c265c;
    ppuStack_384 = (undefined **)0xa1;
    FUN_004fff98();
    FUN_004fff98(0xa2,&DAT_006c265c,unaff_EBP + -0x1c4,0);
    FUN_004fff98(0xa3,&DAT_006c265c,unaff_EBP + -0x308,0);
    FUN_004fff98(0xa4,&DAT_006c265c,unaff_EBP + -0x230,0);
    iStack_37c = 0x42b4b3;
    pvVar3 = operator_new(0x15c);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    if (pvVar3 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      iStack_37c = *(undefined4 *)(*DAT_006e486c + 0x14);
      puStack_380 = (undefined *)0x42b4d4;
      uVar2 = FUN_004100cf();
    }
    *(undefined1 *)(unaff_EBP + -4) = 9;
    *(undefined4 *)(unaff_EBP + -0x28) = uVar2;
    iStack_37c = 0x42b4e7;
    uVar6 = FUN_005bc722();
    iStack_37c = 0x42b4f6;
    uVar5 = FUN_0046fbe5();
    iVar1 = uVar6 % uVar5 + 1;
    puStack_380 = (undefined *)0x42b50f;
    iStack_37c = iVar1;
    FUN_004705f2();
    iStack_37c = 0x42b518;
    FUN_004108d0();
    puStack_380 = (undefined *)0x42b526;
    iStack_37c = iVar1;
    FUN_0047053c();
    iStack_37c = 0x42b534;
    FUN_0040bfed();
    iStack_37c = 0x42b53d;
    FUN_0040bfed();
    iStack_37c = 0x42b545;
    uVar6 = FUN_005bc722();
    if (uVar6 % 100 < 0x3c) {
      *(undefined4 *)(unaff_EBP + -0x2c) = 1;
      *(undefined4 *)(unaff_EBP + -0x24) = 1;
    }
    else if (uVar6 % 100 < 0x50) {
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 1;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 1;
    }
    iStack_37c = 0x42b583;
    uVar6 = FUN_005bc722();
    uVar6 = uVar6 % 100;
    if (uVar6 < 0x19) {
      *(undefined4 *)(unaff_EBP + -0x20) = 1;
    }
    else if (uVar6 < 0x46) {
      *(undefined4 *)(unaff_EBP + -0x20) = 2;
    }
    else {
      *(uint *)(unaff_EBP + -0x20) = 2 - (uint)(uVar6 < 0x55);
    }
    iStack_37c = 0x42b5b7;
    uVar6 = FUN_005bc722();
    if (uVar6 % 100 < 0x21) {
      iStack_37c = 0x42b5cf;
      FUN_0040bfed();
    }
    else if (uVar6 % 100 < 0x42) {
      iStack_37c = 0x42b5e9;
      FUN_0040bfed();
    }
    else {
      iStack_37c = 0x42b601;
      FUN_0040bfed();
    }
    iStack_37c = 0x42b610;
    FUN_0046f8e4();
    iStack_37c = 0x42b618;
    uVar6 = FUN_005bc722();
    if (0x45 < uVar6 % 100) {
      iStack_37c = 0x42b630;
      uVar6 = FUN_005bc722();
      if (uVar6 % 100 < 0x21) {
        iStack_37c = 0x42b646;
        FUN_0040bfed();
      }
      else if (uVar6 % 100 < 0x42) {
        iStack_37c = 0x42b660;
        FUN_0040bfed();
      }
      else {
        iStack_37c = 0x42b678;
        FUN_0040bfed();
      }
    }
    iStack_37c = 0x42b687;
    FUN_0046f8e4();
LAB_0042b687:
    if (*(int *)(unaff_EBP + -0x2c) == 0) {
      if (*(int *)(unaff_EBP + -0x24) == 0) {
        if (*(int *)(unaff_EBP + -0x20) == 0) goto LAB_0042b824;
        iStack_37c = 0x42b6a9;
        FUN_0040bfed();
        *(undefined1 *)(unaff_EBP + 0xb) = 0;
        iStack_37c = 0x42b6b5;
        uVar6 = FUN_005bc722();
        if ((uVar6 % 100 < 0x2d) || (uVar6 % 100 < 0x5a)) {
          iStack_37c = 0x42b6d1;
          FUN_0046f8e4();
        }
        else {
          *(undefined1 *)(unaff_EBP + 0xb) = 1;
        }
        iStack_37c = 0x42b77e;
        uVar6 = FUN_005bc722();
        if (uVar6 % 100 < 0x32) {
          if (*(char *)(unaff_EBP + 0xb) != '\x01') {
            *(undefined ****)(unaff_EBP + 8) = &ppuStack_384;
            FUN_0040f4b7(unaff_EBP + -0x5c);
            iVar1 = unaff_EBP + -0x308;
            uVar2 = 0;
            goto LAB_0042b7fe;
          }
          iStack_37c = 0;
LAB_0042b798:
          puStack_380 = (undefined *)0x1;
          ppuStack_384 = *(undefined ***)(unaff_EBP + -0x1c);
          iVar1 = FUN_00426ba5();
        }
        else {
          if (*(char *)(unaff_EBP + 0xb) == '\x01') {
            iStack_37c = 1;
            goto LAB_0042b798;
          }
          *(undefined ****)(unaff_EBP + 8) = &ppuStack_384;
          FUN_0040f4b7(unaff_EBP + -0x5c);
          iVar1 = unaff_EBP + -0x230;
          uVar2 = 1;
LAB_0042b7fe:
          ppuStack_384 = &PTR_FUN_00666634;
          iVar1 = FUN_00426c0a(*(undefined4 *)(unaff_EBP + -0x1c),1,uVar2,iVar1);
        }
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + -1;
      }
      else {
        iStack_37c = 0x42b715;
        uVar6 = FUN_005bc722();
        if (uVar6 % 100 < 0x4b) {
          iVar1 = unaff_EBP + -0x3c;
          *(undefined ****)(unaff_EBP + 8) = &ppuStack_384;
        }
        else {
          iVar1 = unaff_EBP + -0x4c;
          *(undefined ****)(unaff_EBP + 8) = &ppuStack_384;
        }
        FUN_0040f4b7(iVar1);
        ppuStack_384 = &PTR_FUN_00666634;
        iVar1 = FUN_00426c0a(*(undefined4 *)(unaff_EBP + -0x1c),0,1,unaff_EBP + -0x1c4);
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + -1;
      }
    }
    else {
      *(undefined ****)(unaff_EBP + 8) = &ppuStack_384;
      FUN_0040f4b7(unaff_EBP + -0x3c);
      ppuStack_384 = &PTR_FUN_00666634;
      iVar1 = FUN_00426c0a(*(undefined4 *)(unaff_EBP + -0x1c),0,0,unaff_EBP + -0x374);
      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + -1;
    }
    if (iVar1 != 0) {
      iStack_37c = 0x42b81f;
      FUN_004108dc();
    }
    goto LAB_0042b687;
  }
  goto LAB_0042b8d3;
LAB_0042b824:
  iStack_37c = 0x42b836;
  FUN_0042eb8e();
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_00526e73();
  }
  (*(code *)**(undefined4 **)(DAT_006e486c[0x13] + 0x48))();
LAB_0042b852:
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  if (0xbc1 < *(int *)(unaff_EBP + -0x10)) goto code_r0x0042b862;
  goto LAB_0042b3f4;
code_r0x0042b862:
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    iStack_37c = 0x42b878;
    FUN_005da4c7();
  }
  iStack_37c = 0x42b888;
  FUN_00425316();
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00470467();
LAB_0042b8d3:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00470467();
LAB_0042b8e2:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0042afde();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

