
undefined1 FUN_0052a6a6(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 != '\0') {
    uVar5 = FUN_005dbf32();
    goto LAB_0052add9;
  }
  cVar4 = FUN_005dbf32();
  uVar5 = 0;
  if (cVar4 == '\0') goto LAB_0052add9;
  (**(code **)(*extraout_ECX + 0x90))(0x2000,1);
  piVar10 = extraout_ECX + 0x35;
  FUN_005a5631(0x4b0,piVar10,4);
  FUN_004ec186(*(int *)(*piVar10 + 0x1c) - *(int *)(*piVar10 + 0x14));
  FUN_004ec1a7(*(int *)(*piVar10 + 0x20) - *(int *)(*piVar10 + 0x18));
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xec) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar6 = FUN_0041532c(9,unaff_EBP + -0xec,0);
  cVar4 = FUN_004fff98(0x90,uVar6);
  if (cVar4 != '\0') {
    FUN_00471655(unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 **)(unaff_EBP + -0x28) = &DAT_0066d8f4;
    piVar10 = extraout_ECX + 0x36;
    do {
      pvVar7 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x20) = pvVar7;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (pvVar7 == (void *)0x0) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_005e372a();
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      *piVar10 = iVar8;
      if (iVar8 != 0) {
        *(undefined4 *)(iVar8 + 0xf8) = 0;
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        FUN_005a5631(**(undefined4 **)(unaff_EBP + -0x28),unaff_EBP + -0x20,4);
        if (*(int **)(unaff_EBP + -0x20) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x68))(DAT_006f2a64);
        }
        (**(code **)(*(int *)*piVar10 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x20),4,1);
        *(undefined1 *)(*piVar10 + 0x16b) = 1;
        (**(code **)(*extraout_ECX + 0x20))(*piVar10);
        FUN_0046fc87(unaff_EBP + -0x74,0);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        uVar6 = FUN_0046fc7a();
        puVar9 = (undefined4 *)FUN_00500249(unaff_EBP + -0x44,uVar6);
        FUN_004cb21d(*puVar9,puVar9[1]);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
        if ((*(undefined4 **)(unaff_EBP + -0x28) == &DAT_0066d8f4) ||
           (*(undefined **)(unaff_EBP + -0x28) == &DAT_0066d8f8)) {
          FUN_0046fc87(unaff_EBP + -0x6c,0);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          uVar6 = FUN_0046fc7a();
          uVar6 = FUN_005d4956(uVar6);
          piVar1 = (int *)*piVar10;
          *(undefined1 *)(unaff_EBP + -4) = 5;
          (**(code **)(*piVar1 + 0x9c))(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0042004f();
          *(undefined4 *)(unaff_EBP + -100) = 0;
          *(undefined4 *)(unaff_EBP + -0x5c) = 2;
          *(undefined4 *)(unaff_EBP + -0x58) = 2;
          *(undefined4 *)(unaff_EBP + -0x60) = 0;
          *(undefined4 *)(unaff_EBP + -0x54) = 0;
          *(undefined4 *)(unaff_EBP + -0x50) = 0;
          *(undefined4 *)(unaff_EBP + -0x4c) = 0;
          *(undefined4 *)(unaff_EBP + -0x48) = 0;
          FUN_005e4104(unaff_EBP + -100);
          uVar6 = DAT_006f2aac;
          if (*(char *)(DAT_006e486c + 100) == '\a') {
            uVar6 = DAT_006f2aa4;
          }
          FUN_005e4071(uVar6);
        }
        *(undefined4 *)(*piVar10 + 0xf4) = 0;
        FUN_0046fc87(unaff_EBP + -0x14,0);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        uVar6 = FUN_0046fc7a();
        uVar6 = FUN_005d4956(uVar6);
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_005dd9c8(uVar6);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
        (**(code **)(*(int *)*piVar10 + 0x90))(0x2000,1);
      }
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 4;
      piVar10 = piVar10 + 1;
    } while (*(int *)(unaff_EBP + -0x28) < 0x66d90c);
    pvVar7 = operator_new(0x1b8);
    *(void **)(unaff_EBP + -0x20) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005f179a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x3e] = iVar8;
    if (iVar8 != 0) {
      FUN_005f42c3(DAT_006f2a9c);
      FUN_005f4336(DAT_006f2a48);
      FUN_0046fc87(unaff_EBP + -0x14,0);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      uVar6 = FUN_0046fc7a();
      piVar10 = (int *)FUN_00500249(unaff_EBP + -0x44,uVar6);
      iVar8 = *piVar10;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      *(int *)(unaff_EBP + -0x30) = piVar10[1];
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x14,0);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      uVar6 = FUN_0046fc7a();
      piVar10 = (int *)FUN_00500249(unaff_EBP + -0x44,uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      iVar2 = piVar10[1];
      iVar3 = *piVar10;
      *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + iVar2;
      *(int *)(unaff_EBP + -0x20) = iVar2;
      *(int *)(unaff_EBP + -0x28) = iVar3;
      FUN_0042004f();
      (**(code **)(*(int *)extraout_ECX[0x3e] + 0x60))
                (*(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + -0x20),iVar8 + iVar3
                 ,*(undefined4 *)(unaff_EBP + -0x30));
      *(int *)(extraout_ECX[0x3e] + 8) = extraout_ECX[0x3e];
      FUN_005f42b6(0xffffffff);
      FUN_005f4256((-(*(int *)(DAT_006e486c + 0x34) != 1) & 0x20U) + 5,DAT_006f2a48,DAT_006f2a48);
      FUN_005f435f(0x1000);
      FUN_005f4294(0);
      (**(code **)(*(int *)extraout_ECX[0x3e] + 0x90))(0x2000,0);
      FUN_005f42a1(0);
      FUN_005f489f(1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3e]);
    }
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    uVar6 = FUN_0046fc7a();
    piVar10 = (int *)FUN_00500249(unaff_EBP + -0x44,uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x49] = *piVar10;
    extraout_ECX[0x4a] = piVar10[1];
    FUN_0042004f();
    pvVar7 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x20) = pvVar7;
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005e9913();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x3f] = iVar8;
    if (iVar8 != 0) {
      FUN_0046fc87(unaff_EBP + -0x14,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      uVar6 = FUN_0046fc7a();
      FUN_00500249(unaff_EBP + -0x24,uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x14,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      uVar6 = FUN_0046fc7a();
      FUN_00500249(unaff_EBP + -0x2c,uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      (**(code **)(*(int *)(extraout_ECX[0x3f] + 0xd4) + 0x18))(DAT_006f2a94);
      (**(code **)(*(int *)(extraout_ECX[0x3f] + 0xd4) + 0x10))(DAT_006f2a48);
      (**(code **)(*(int *)(extraout_ECX[0x3f] + 0xd4) + 0x1c))(2);
      (**(code **)(*(int *)(extraout_ECX[0x3f] + 0xd4) + 0x14))(0);
      (**(code **)(*(int *)(extraout_ECX[0x3f] + 0xd4) + 0xc))(2,0);
      *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x2c) + *(int *)(unaff_EBP + -0x24);
      (**(code **)(*(int *)extraout_ECX[0x3f] + 0x60))
                (*(int *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
                 *(undefined4 *)(unaff_EBP + -0x34),
                 *(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x28));
      (**(code **)(*(int *)extraout_ECX[0x3f] + 0x90))(0x2000,1);
      FUN_0046fc87(unaff_EBP + -0x14,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      uVar6 = FUN_0046fc7a();
      uVar6 = FUN_005d4956(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_005dd9c8(uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3f]);
      (**(code **)(*(int *)extraout_ECX[0x3f] + 0x98))();
    }
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 0x11;
    uVar6 = FUN_0046fc7a();
    FUN_005d4bbf(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 0x12;
    uVar6 = FUN_0046fc7a();
    FUN_005d4bbf(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x14,0);
    *(undefined1 *)(unaff_EBP + -4) = 0x13;
    uVar6 = FUN_0046fc7a();
    FUN_005d4bbf(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
  }
  cVar4 = FUN_004074bc();
  if (cVar4 == '\x01') {
LAB_0052ada1:
    iVar8 = FUN_00410977();
    extraout_ECX[0x3d] = iVar8;
  }
  else {
    uVar6 = FUN_004e99a9();
    iVar8 = FUN_004e9744(uVar6);
    if ((iVar8 != 0) && (iVar8 = FUN_00425db3((int)*(short *)(iVar8 + 0x606)), iVar8 != 0))
    goto LAB_0052ada1;
  }
  uVar5 = extraout_ECX[0x3d] != 0;
  if ((bool)uVar5) {
    FUN_005ddfdc(1);
    FUN_0052b1e7();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
LAB_0052add9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

