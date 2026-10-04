
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_005219e0(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  void *pvVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar3 = (**(code **)(*extraout_ECX + 200))();
  if (cVar3 == '\0') {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x94) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar5 = FUN_0041532c(9,unaff_EBP + -0x94,0);
    cVar3 = FUN_004fff98(0xdd,uVar5);
    if (cVar3 == '\0') {
      uVar4 = 0;
    }
    else {
      FUN_00471655(unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar5 = FUN_0046fc7a();
      FUN_005d4bbf(uVar5);
      FUN_005c11ce();
      uVar5 = FUN_0046fc7a();
      FUN_005d4bbf(uVar5);
      FUN_005c11ce();
      uVar5 = FUN_0046fc7a();
      FUN_005d4bbf(uVar5);
      FUN_005c11ce();
      uVar5 = FUN_0046fc7a();
      FUN_005d4bbf(uVar5);
      FUN_005c11ce();
      uVar5 = FUN_0046fc7a();
      FUN_005d4bbf(uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
      pvVar6 = operator_new(0x110);
      *(void **)(unaff_EBP + -0x10) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if (pvVar6 == (void *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = FUN_005e9913();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      extraout_ECX[0x37] = iVar7;
      if (iVar7 != 0) {
        iVar7 = extraout_ECX[0x48];
        (**(code **)(*DAT_006f2ab4 + 0x50))(unaff_EBP + -0x28,iVar7,extraout_ECX[0x49] - iVar7);
        (**(code **)(*(int *)extraout_ECX[0x37] + 0x60))
                  (*(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + -0x24),
                   *(int *)(unaff_EBP + -0x20) + 5,*(undefined4 *)(unaff_EBP + -0x1c));
        (**(code **)(*(int *)(extraout_ECX[0x37] + 0xd4) + 0x18))(DAT_006f2ab4);
        (**(code **)(*(int *)extraout_ECX[0x37] + 0x9c))(extraout_ECX + 0x48);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x37]);
        (**(code **)(*(int *)(extraout_ECX[0x37] + 0xd4) + 0x1c))(2);
        (**(code **)(*(int *)(extraout_ECX[0x37] + 0xd4) + 0x14))(0);
      }
      piVar8 = (int *)FUN_005e7743();
      iVar7 = *piVar8;
      uVar5 = FUN_005e50fa(3);
      iVar7 = (**(code **)(iVar7 + 0x24))(0,uVar5);
      extraout_ECX[0x3a] = iVar7;
      if (iVar7 != 0) {
        FUN_005e4b90(1);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3a]);
      }
      piVar8 = (int *)FUN_005e7743();
      iVar7 = (**(code **)(*piVar8 + 0x24))(1,extraout_ECX + 0x45);
      extraout_ECX[0x3b] = iVar7;
      if (iVar7 != 0) {
        FUN_005e4b90(1);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3b]);
      }
      iVar7 = extraout_ECX[0x37];
      iVar9 = extraout_ECX[0x21] - extraout_ECX[0x1f];
      if (iVar9 < *(int *)(iVar7 + 0x84) - *(int *)(iVar7 + 0x7c)) {
        iVar9 = *(int *)(iVar7 + 0x84) - *(int *)(iVar7 + 0x7c);
      }
      iVar7 = extraout_ECX[0x3b];
      iVar11 = extraout_ECX[0x3a];
      if (iVar9 < (((*(int *)(iVar7 + 0x84) + *(int *)(iVar11 + 0x84)) - *(int *)(iVar7 + 0x7c)) -
                  *(int *)(iVar11 + 0x7c)) + 0xf) {
        iVar9 = (((*(int *)(iVar7 + 0x84) + *(int *)(iVar11 + 0x84)) - *(int *)(iVar7 + 0x7c)) -
                *(int *)(iVar11 + 0x7c)) + 0xf;
      }
      if (extraout_ECX[0x21] - extraout_ECX[0x1f] < iVar9) {
        iVar7 = extraout_ECX[0x22];
        iVar11 = extraout_ECX[0x20];
        *(int *)(unaff_EBP + -0x20) = iVar9 + 10;
        iVar10 = FUN_004b46a0();
        iVar1 = *(int *)(iVar10 + 0x88);
        iVar2 = *(int *)(iVar10 + 0x80);
        iVar10 = ((*(int *)(iVar10 + 0x84) - *(int *)(iVar10 + 0x7c)) - (iVar9 + 10)) / 2;
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + iVar10;
        iVar9 = ((iVar1 - iVar2) - (iVar7 - iVar11)) / 2;
        (**(code **)(*extraout_ECX + 0x60))
                  (iVar10,iVar9,*(undefined4 *)(unaff_EBP + -0x20),(iVar7 - iVar11) + iVar9);
      }
      iVar7 = extraout_ECX[0x37];
      if (iVar7 != 0) {
        iVar9 = extraout_ECX[0x4b];
        if (iVar9 == 0) {
          iVar11 = 0;
          iVar9 = 0;
        }
        else {
          iVar11 = *(int *)(iVar9 + 0x20) / 3;
          iVar9 = *(int *)(iVar9 + 0x1c) / 3;
        }
        FUN_004cb21d(iVar9 + (((extraout_ECX[0x21] - *(int *)(iVar7 + 0x84)) - extraout_ECX[0x1f]) +
                             *(int *)(iVar7 + 0x7c)) / 2,iVar11 + 9);
      }
      iVar7 = extraout_ECX[0x4b];
      if (iVar7 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar7 + 0x20) / 3;
      }
      iVar11 = extraout_ECX[0x3a];
      *(int *)(unaff_EBP + -0x10) =
           ((extraout_ECX[0x22] - extraout_ECX[0x20]) - *(int *)(iVar11 + 0x88)) +
           *(int *)(iVar11 + 0x80) + -9 + iVar9;
      if ((iVar11 != 0) && (iVar9 = extraout_ECX[0x3b], iVar9 != 0)) {
        iVar9 = ((extraout_ECX[0x21] - extraout_ECX[0x1f]) -
                (((*(int *)(iVar9 + 0x84) + *(int *)(iVar11 + 0x84)) - *(int *)(iVar11 + 0x7c)) -
                *(int *)(iVar9 + 0x7c))) / 3;
        if (iVar7 == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(iVar7 + 0x1c) / 3;
        }
        FUN_004cb21d(iVar7 + iVar9,*(undefined4 *)(unaff_EBP + -0x10));
        if (extraout_ECX[0x4b] == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(extraout_ECX[0x4b] + 0x1c) / 3;
        }
        FUN_004cb21d(((*(int *)(extraout_ECX[0x3a] + 0x84) + iVar9 * 2) -
                     *(int *)(extraout_ECX[0x3a] + 0x7c)) + iVar7,*(undefined4 *)(unaff_EBP + -0x10)
                    );
      }
      FUN_005a5631(300,unaff_EBP + -0x18,4);
      if (*(int **)(unaff_EBP + -0x18) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x68))(DAT_006f2a64);
      }
      pvVar6 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (pvVar6 == (void *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)FUN_005e372a();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      extraout_ECX[0x38] = (int)piVar8;
      (**(code **)(*piVar8 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x18),4,1);
      *(undefined1 *)(extraout_ECX[0x38] + 0x16b) = 1;
      *(undefined4 *)(extraout_ECX[0x38] + 0xf4) = 1;
      FUN_005dd9c8(extraout_ECX + 0x3f);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x38]);
      FUN_005a5631(0x12d,unaff_EBP + -0x18,4);
      if (*(int **)(unaff_EBP + -0x18) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x68))(DAT_006f2a64);
      }
      pvVar6 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      if (pvVar6 == (void *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)FUN_005e372a();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      extraout_ECX[0x39] = (int)piVar8;
      (**(code **)(*piVar8 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x18),4,1);
      *(undefined1 *)(extraout_ECX[0x39] + 0x16b) = 1;
      *(undefined4 *)(extraout_ECX[0x39] + 0xf4) = 1;
      FUN_005dd9c8(extraout_ECX + 0x3c);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x39]);
      iVar7 = extraout_ECX[0x4b];
      if (iVar7 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar7 + 0x1c) / 3;
      }
      iVar11 = extraout_ECX[0x38];
      *(int *)(unaff_EBP + -0x28) = (*(int *)(iVar11 + 0x84) - *(int *)(iVar11 + 0x7c)) + 9 + iVar9;
      if (iVar7 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar7 + 0x1c) / 3;
      }
      *(int *)(unaff_EBP + -0x20) =
           ((extraout_ECX[0x21] - *(int *)(extraout_ECX[0x39] + 0x84)) - extraout_ECX[0x1f]) +
           *(int *)(extraout_ECX[0x39] + 0x7c) + -9 + iVar9;
      if (iVar7 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar7 + 0x20) / 3;
      }
      iVar9 = (*(int *)(extraout_ECX[0x37] + 0x88) - *(int *)(extraout_ECX[0x37] + 0x80)) + 0x12 +
              iVar9;
      if (iVar7 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(iVar7 + 0x20) / 3;
      }
      iVar7 = ((extraout_ECX[0x22] - extraout_ECX[0x20]) - *(int *)(extraout_ECX[0x3a] + 0x88)) +
              *(int *)(extraout_ECX[0x3a] + 0x80) + -0x24 + iVar7;
      iVar11 = (((*(int *)(iVar11 + 0x80) - *(int *)(iVar11 + 0x88)) - iVar9) + iVar7) / 2 + iVar9;
      *(int *)(unaff_EBP + -0x10) = iVar11;
      FUN_004cb21d(9,iVar11);
      FUN_004cb21d(((extraout_ECX[0x21] - *(int *)(extraout_ECX[0x39] + 0x84)) - extraout_ECX[0x1f])
                   + -9 + *(int *)(extraout_ECX[0x39] + 0x7c),*(undefined4 *)(unaff_EBP + -0x10));
      pvVar6 = operator_new(0x20a8);
      *(void **)(unaff_EBP + -0x10) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      if (pvVar6 == (void *)0x0) {
        iVar11 = 0;
      }
      else {
        iVar11 = FUN_0056d18e(_DAT_00667678);
      }
      iVar1 = *(int *)(unaff_EBP + -0x20);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      iVar2 = *(int *)(unaff_EBP + -0x28);
      extraout_ECX[0x4c] = iVar11;
      FUN_004cb1a2(iVar1 - iVar2,iVar7 - iVar9);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x4c]);
      iVar11 = extraout_ECX[0x4c];
      FUN_004cb21d((((*(int *)(iVar11 + 0x7c) - *(int *)(iVar11 + 0x84)) -
                    *(int *)(unaff_EBP + -0x28)) + *(int *)(unaff_EBP + -0x20)) / 2 +
                   *(int *)(unaff_EBP + -0x28),
                   (((*(int *)(iVar11 + 0x80) - *(int *)(iVar11 + 0x88)) - iVar9) + iVar7) / 2 +
                   iVar9);
      FUN_0056d52d(extraout_ECX[0x36],0);
      piVar8 = (int *)FUN_005e7743();
      iVar7 = (**(code **)(*piVar8 + 0x10))(5);
      extraout_ECX[0x4b] = iVar7;
      uVar4 = FUN_005dbf32();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  else {
    uVar4 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

