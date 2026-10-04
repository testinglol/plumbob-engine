
undefined1 FUN_0050d1f9(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  int iVar9;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar10;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    cVar2 = FUN_005dbf32();
    uVar3 = 0;
    if (cVar2 != '\0') {
      FUN_005a5631(0xbc0,extraout_ECX + 0x38,4);
      FUN_005a5631(0x137f,extraout_ECX + 0x37,4);
      iVar6 = extraout_ECX[0x37];
      if (iVar6 != 0) {
        iVar9 = *(int *)(iVar6 + 0x14);
        iVar1 = *(int *)(iVar6 + 0x1c);
        iVar10 = *(int *)(iVar6 + 0x20);
        *(int *)(unaff_EBP + -0x28) = *(int *)(iVar6 + 0x18) + -0x10;
        *(int *)(unaff_EBP + -0x2c) = iVar9 + -0x10;
        *(int *)(unaff_EBP + -0x24) = iVar1 + 0x10;
        iVar10 = iVar10 + 0x10;
        piVar4 = (int *)FUN_005e7743();
        iVar6 = *piVar4;
        *(int **)(unaff_EBP + -0x10) = piVar4;
        uVar5 = FUN_005e50fa(3);
        iVar6 = (**(code **)(iVar6 + 0x24))(3,uVar5);
        extraout_ECX[0x39] = iVar6;
        if (iVar6 != 0) {
          (**(code **)(*extraout_ECX + 0x20))(iVar6);
        }
        piVar4 = (int *)FUN_005e7743();
        iVar6 = *piVar4;
        *(int **)(unaff_EBP + -0x10) = piVar4;
        uVar5 = FUN_005e50fa(1);
        iVar6 = (**(code **)(iVar6 + 0x24))(1,uVar5);
        extraout_ECX[0x3a] = iVar6;
        if (iVar6 != 0) {
          (**(code **)(*extraout_ECX + 0x20))(iVar6);
        }
        iVar6 = extraout_ECX[0x39];
        if (iVar6 != 0) {
          iVar10 = iVar10 + (*(int *)(iVar6 + 0x88) - *(int *)(iVar6 + 0x80));
        }
        iVar6 = *(int *)(unaff_EBP + -0x28);
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + -iVar6;
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + -*(int *)(unaff_EBP + -0x2c);
        *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + -*(int *)(unaff_EBP + -0x2c);
        (**(code **)(*extraout_ECX + 0x60))
                  (*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28),
                   *(undefined4 *)(unaff_EBP + -0x24),iVar10 + 0x10 + -iVar6);
        FUN_005ddfdc(1);
        extraout_ECX[0x3b] = 0x10;
        extraout_ECX[0x3c] = 0x10;
        pvVar7 = operator_new(0x1b8);
        *(void **)(unaff_EBP + -0x10) = pvVar7;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar7 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_005f179a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x36] = iVar6;
        if (iVar6 != 0) {
          FUN_005f42c3(DAT_006f2a9c);
          FUN_005f4336(DAT_006f2a48);
          FUN_005f4256(0,DAT_006f2a48,DAT_006f2a48);
          FUN_005f42b6(0xffffffff);
          FUN_005f489f(1);
          iVar6 = extraout_ECX[0x37];
          iVar9 = *(int *)(iVar6 + 0x14);
          iVar1 = *(int *)(iVar6 + 0x18);
          iVar10 = *(int *)(iVar6 + 0x20);
          *(int *)(unaff_EBP + -0x24) = *(int *)(iVar6 + 0x1c) + -4;
          iVar6 = extraout_ECX[0x3c];
          *(int *)(unaff_EBP + -0x20) = iVar10 + -4;
          iVar10 = extraout_ECX[0x3b];
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + iVar6 + 4;
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar10 + 4;
          (**(code **)(*(int *)extraout_ECX[0x36] + 0x60))
                    (iVar9 + 4 + iVar10 + 4,iVar1 + 4 + iVar6 + 4,*(undefined4 *)(unaff_EBP + -0x24)
                     ,*(undefined4 *)(unaff_EBP + -0x20));
          *(int *)(extraout_ECX[0x36] + 8) = extraout_ECX[0x36];
          FUN_005f4294(0);
          (**(code **)(*(int *)extraout_ECX[0x36] + 0x90))(0x2000,0);
          FUN_005f42a1(0);
          FUN_005f435f(0x800);
          (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x36]);
          puVar8 = (undefined4 *)FUN_004e9bbd(extraout_ECX[0x35]);
          FUN_005d4956(*puVar8);
          *(undefined4 *)(unaff_EBP + -4) = 1;
          FUN_005f436c(*(undefined4 *)(unaff_EBP + -0x1c),0,1);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        iVar6 = extraout_ECX[0x39];
        iVar9 = ((((extraout_ECX[0x21] - *(int *)(extraout_ECX[0x3a] + 0x84)) -
                  *(int *)(iVar6 + 0x84)) - extraout_ECX[0x1f]) + *(int *)(iVar6 + 0x7c) +
                *(int *)(extraout_ECX[0x3a] + 0x7c)) / 3;
        *(int *)(unaff_EBP + -0x10) = iVar9;
        if (iVar6 != 0) {
          FUN_004cb21d(iVar9,((*(int *)(iVar6 + 0x80) - *(int *)(iVar6 + 0x88)) - extraout_ECX[0x20]
                             ) + -0x10 + extraout_ECX[0x22]);
        }
        iVar6 = extraout_ECX[0x3a];
        if (iVar6 != 0) {
          FUN_004cb21d((*(int *)(extraout_ECX[0x39] + 0x84) + *(int *)(unaff_EBP + -0x10) * 2) -
                       *(int *)(extraout_ECX[0x39] + 0x7c),
                       ((*(int *)(iVar6 + 0x80) - *(int *)(iVar6 + 0x88)) - extraout_ECX[0x20]) +
                       -0x10 + extraout_ECX[0x22]);
        }
        (**(code **)(*extraout_ECX + 0x90))(0x2000,1);
        (**(code **)(*(int *)extraout_ECX[0x39] + 0x90))(0x2000,1);
        (**(code **)(*(int *)extraout_ECX[0x3a] + 0x90))(0x2000,1);
      }
      uVar3 = 1;
    }
  }
  else {
    uVar3 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

