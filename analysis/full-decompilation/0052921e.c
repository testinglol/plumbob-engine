
undefined1 FUN_0052921e(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  void *pvVar4;
  int *extraout_ECX;
  undefined1 uVar5;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xf0) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = FUN_0041532c(9,unaff_EBP + -0xf0,0);
  cVar1 = FUN_004fff98(0x93,uVar2);
  if (cVar1 == '\0') {
    uVar5 = 0;
  }
  else {
    FUN_00471655(unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    do {
      if (*(int *)(unaff_EBP + -0x10) == 4) {
        if (*(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x1c) -
            *(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x14) == 800) {
          FUN_0046fc87(unaff_EBP + -0x74,0);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          uVar2 = FUN_0046fc7a();
          piVar3 = (int *)FUN_00500249(unaff_EBP + -0x84,uVar2);
          iVar6 = *piVar3;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          iVar7 = piVar3[1];
          FUN_0042004f();
          FUN_005c11ce();
          extraout_ECX[0x45] = 8;
          iVar6 = iVar6 + -3;
          goto LAB_005292ce;
        }
        FUN_005c11ce();
        FUN_0046fc87(unaff_EBP + -0x50,0);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        uVar2 = FUN_0046fc7a();
        piVar3 = (int *)FUN_00500249(unaff_EBP + -0x60,uVar2);
        iVar6 = *piVar3;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        iVar7 = piVar3[1];
        FUN_0042004f();
        iVar6 = iVar6 + -0x1b;
        *(int *)(unaff_EBP + -0x2c) = iVar7;
        extraout_ECX[0x45] = 0x10;
      }
      else {
        FUN_0046fc87(unaff_EBP + -0x58,0);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        uVar2 = FUN_0046fc7a();
        piVar3 = (int *)FUN_00500249(unaff_EBP + -0x7c,uVar2);
        iVar6 = *piVar3;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        iVar7 = piVar3[1];
        FUN_0042004f();
        iVar6 = iVar6 + -4;
LAB_005292ce:
        *(int *)(unaff_EBP + -0x2c) = iVar7;
      }
      pvVar4 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x28) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      if (pvVar4 == (void *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)FUN_005e372a();
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (piVar3 == (int *)0x0) goto LAB_005295d4;
      FUN_005a5631(*(undefined4 *)(&DAT_0066d73c + *(int *)(unaff_EBP + -0x10) * 4),
                   unaff_EBP + -0x14,4);
      if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
        if ((*(int *)(&DAT_0066d73c + *(int *)(unaff_EBP + -0x10) * 4) == 100) ||
           (*(int *)(&DAT_0066d73c + *(int *)(unaff_EBP + -0x10) * 4) == 0x65)) {
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x68))(DAT_006f2a64);
        }
        (**(code **)(*piVar3 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x14),4,1);
        *(undefined1 *)((int)piVar3 + 0x16b) = 1;
      }
      iVar7 = *(int *)(unaff_EBP + -0x10);
      piVar3[0x3d] = 1;
      if ((iVar7 < 3) || (4 < *(int *)(unaff_EBP + -0x10))) {
        piVar3[0x3e] = 1;
        iVar7 = DAT_006d74f0;
        if (DAT_006d74f0 == 0) {
          piVar3[0x55] = 0;
        }
        else {
          piVar3[0x55] = 6;
          piVar3[0x56] = iVar7;
        }
        *(undefined1 *)(piVar3 + 0x5b) = 0;
      }
      else {
        piVar3[0x3e] = 0;
        FUN_005e4a73(1);
      }
      FUN_004cb21d(iVar6,*(undefined4 *)(unaff_EBP + -0x2c));
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      uVar2 = FUN_0046fc7a();
      FUN_005d4956(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005dd9c8(unaff_EBP + -0x6c);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      (**(code **)(*extraout_ECX + 0x20))(piVar3);
      iVar6 = *(int *)(unaff_EBP + -0x10);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar7 = *(int *)(unaff_EBP + -0x10);
      extraout_ECX[iVar6 + 0x35] = (int)piVar3;
    } while (iVar7 < 6);
    FUN_0046fc87(unaff_EBP + -0x24,0);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    uVar2 = FUN_0046fc7a();
    piVar3 = (int *)FUN_00500249(unaff_EBP + -0x60,uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x47] = *piVar3;
    extraout_ECX[0x48] = piVar3[1];
    FUN_0042004f();
    extraout_ECX[0x47] = extraout_ECX[0x47] + -4;
    extraout_ECX[0x48] = extraout_ECX[0x48] + -2;
    cVar1 = FUN_00529711();
    if ((cVar1 == '\0') || (cVar1 = FUN_0052984c(), cVar1 == '\0')) {
LAB_005295d4:
      uVar5 = 0;
    }
    else {
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      uVar2 = FUN_0046fc7a();
      FUN_005d4bbf(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      uVar2 = FUN_0046fc7a();
      FUN_005d4bbf(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_0042004f();
      pvVar4 = operator_new(0x60);
      *(void **)(unaff_EBP + -0x28) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      if (pvVar4 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004cb8d2();
      }
      *(undefined1 *)(unaff_EBP + -4) = 10;
      extraout_ECX[0x4a] = iVar6;
      if (iVar6 != 0) {
        FUN_005a5631(0xe15,unaff_EBP + -0x14,4);
        FUN_004cd046(0,10,*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x3c,unaff_EBP + -0x48,0);
      }
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      uVar2 = FUN_0046fc7a();
      FUN_005d4bbf(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x24,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      uVar2 = FUN_0046fc7a();
      FUN_005d4bbf(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_0042004f();
      pvVar4 = operator_new(0x60);
      *(void **)(unaff_EBP + -0x28) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      if (pvVar4 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_004cb8d2();
      }
      *(undefined1 *)(unaff_EBP + -4) = 10;
      extraout_ECX[0x4b] = iVar6;
      if (iVar6 != 0) {
        FUN_005a5631(0xe16,unaff_EBP + -0x14,4);
        FUN_004cd046(0,10,*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x3c,unaff_EBP + -0x48,0);
      }
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      uVar5 = 1;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

