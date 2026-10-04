
undefined1 FUN_0054e5e9(void)

{
  char cVar1;
  undefined1 uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *extraout_ECX;
  int iVar10;
  int iVar11;
  int extraout_ECX_00;
  int iVar12;
  int iVar13;
  int unaff_EBP;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  undefined4 *puStack_80;
  undefined4 *puStack_7c;
  undefined4 uStack_78;
  int *piStack_74;
  
  FUN_00634c24();
  uStack_78 = *(undefined4 *)(unaff_EBP + 8);
  puStack_7c = (undefined4 *)0x54e60c;
  piStack_74 = extraout_ECX + 0x65;
  cVar1 = FUN_004e1f04();
  *(char *)(unaff_EBP + -0xd) = cVar1;
  uVar2 = 0;
  if (cVar1 == '\0') goto LAB_0054ebc2;
  if (((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) || (extraout_ECX[0x91] == 0)) {
    iVar9 = extraout_ECX[0x65];
    *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x66];
    *(int *)(unaff_EBP + -0x1c) = iVar9;
    piVar7 = extraout_ECX + 0x78;
  }
  else {
    iVar9 = extraout_ECX[0x67];
    *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x68];
    *(int *)(unaff_EBP + -0x1c) = iVar9;
    piVar7 = extraout_ECX + 0x7d;
  }
  iVar8 = DAT_006f5398;
  iVar13 = extraout_ECX[0x9a];
  *(int **)(unaff_EBP + -0x18) = piVar7;
  if ((char)iVar13 != '\x01') {
    iVar8 = DAT_006f5394;
  }
  if ((undefined4 *)extraout_ECX[0x99] != (undefined4 *)0x0) {
    piStack_74 = (int *)0x54e684;
    (*(code *)**(undefined4 **)extraout_ECX[0x99])();
  }
  piStack_74 = (int *)0x54e68b;
  pvVar3 = operator_new(100);
  *(void **)(unaff_EBP + -0x2c) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
  }
  else {
    uVar4 = FUN_005dfb13();
    *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
  }
  iVar13 = *(int *)(unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x99] = iVar13;
  if (iVar13 != 0) {
    iVar13 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0xc);
    if (iVar13 < 0) {
      if (*(int *)(unaff_EBP + -0x14) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x1c);
      }
      *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
      if (iVar9 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iVar9 + 0x1c);
      }
      *(int *)(unaff_EBP + -0x28) = iVar5 - iVar13;
      puVar6 = (undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x24) <= iVar5 - iVar13) {
        puVar6 = (undefined4 *)(unaff_EBP + -0x28);
      }
      *(undefined4 *)(unaff_EBP + -0x28) = *puVar6;
      iVar5 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      if (*(int *)(unaff_EBP + -0x14) == 0) {
        iVar5 = *(int *)(unaff_EBP + -0x14);
        iVar10 = 0;
      }
      else {
        iVar5 = *(int *)(unaff_EBP + -0x14);
        iVar10 = *(int *)(iVar5 + 0x1c);
      }
      *(int *)(unaff_EBP + -0x28) = iVar10 + iVar13;
      if (iVar9 == 0) {
        iVar12 = 0;
      }
      else {
        iVar12 = *(int *)(iVar9 + 0x1c);
      }
      *(int *)(unaff_EBP + -0x24) = iVar12;
      puVar6 = (undefined4 *)(unaff_EBP + -0x28);
      if (iVar10 + iVar13 <= iVar12) {
        puVar6 = (undefined4 *)(unaff_EBP + -0x24);
      }
      *(undefined4 *)(unaff_EBP + -0x28) = *puVar6;
    }
    iVar13 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x10);
    if (iVar13 < 0) {
      if (iVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(iVar5 + 0x20);
      }
      *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar9 + 0x20);
      }
      *(int *)(unaff_EBP + -0x2c) = iVar9 - iVar13;
      puStack_80 = (undefined4 *)(unaff_EBP + -0x24);
      if (*(int *)(unaff_EBP + -0x24) <= iVar9 - iVar13) {
        puStack_80 = (undefined4 *)(unaff_EBP + -0x2c);
      }
    }
    else {
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iVar5 + 0x20);
      }
      *(int *)(unaff_EBP + -0x24) = iVar5 + iVar13;
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar9 + 0x20);
      }
      *(int *)(unaff_EBP + -0x2c) = iVar9;
      puStack_80 = (undefined4 *)(unaff_EBP + -0x24);
      if (iVar5 + iVar13 <= iVar9) {
        puStack_80 = (undefined4 *)(unaff_EBP + -0x2c);
      }
    }
    *(undefined4 *)(unaff_EBP + -0x24) = *puStack_80;
    iVar9 = **(int **)(unaff_EBP + -0x20);
    piStack_74 = (int *)0x0;
    uStack_78 = 0;
    *(undefined4 ***)(unaff_EBP + -0x2c) = &puStack_80;
    puStack_7c = puStack_80;
    FUN_00436a50();
    cVar1 = (**(code **)(iVar9 + 0xc))();
    if (cVar1 == '\0') {
      if ((undefined4 *)extraout_ECX[0x99] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)extraout_ECX[0x99])();
      }
      extraout_ECX[0x99] = 0;
    }
    cVar1 = (**(code **)(*(int *)extraout_ECX[0x99] + 0x20))();
    if (cVar1 != '\0') {
      (**(code **)(*(int *)extraout_ECX[0x99] + 0x38))();
      iStack_9c = 0x54e808;
      (**(code **)(*(int *)extraout_ECX[0x99] + 0x24))();
    }
    (**(code **)(*(int *)extraout_ECX[0x99] + 0x68))();
    iVar9 = *(int *)(unaff_EBP + -0x14);
    if (iVar9 == 0) {
      *(undefined1 *)(extraout_ECX + 0x86) = 0;
      if (*(int *)(unaff_EBP + -0x1c) != 0) {
        iStack_9c = *(int *)(unaff_EBP + -0x1c);
        iStack_a0 = 0x54e935;
        (**(code **)(*extraout_ECX + 0x19c))();
      }
LAB_0054eb89:
      if ((*(char *)((int)extraout_ECX + 0x25d) == '\x01') &&
         (iVar9 = FUN_0042ba25(), iVar9 == extraout_ECX[0x98])) {
        iStack_9c = 0xf2;
        iStack_a0 = 1;
        iStack_a4 = 0x54ebbf;
        FUN_0054f51d();
      }
      uVar2 = *(undefined1 *)(unaff_EBP + -0xd);
      goto LAB_0054ebc2;
    }
    cVar1 = (**(code **)(*(int *)extraout_ECX[0x99] + 0x20))();
    if (cVar1 == '\0') {
      iVar9 = *(int *)(unaff_EBP + -0x1c);
    }
    else {
      iVar13 = *(int *)(iVar9 + 0x20);
      iVar9 = *(int *)(iVar9 + 0x1c);
      iVar5 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0xc);
      *(undefined4 *)(unaff_EBP + -0x6c) = 0;
      *(undefined4 *)(unaff_EBP + -0x68) = 0;
      *(int *)(unaff_EBP + -100) = iVar9;
      *(int *)(unaff_EBP + -0x60) = iVar13;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x48) = 0;
      *(int *)(unaff_EBP + -0x44) = iVar9;
      *(int *)(unaff_EBP + -0x40) = iVar13;
      if (0 < iVar5) {
        *(int *)(unaff_EBP + -0x4c) = iVar5;
        *(int *)(unaff_EBP + -0x44) = iVar5 + iVar9;
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
        *(int *)(unaff_EBP + -0x40) = iVar13;
      }
      iVar9 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x10);
      if (0 < iVar9) {
        *(int *)(unaff_EBP + -0x48) = iVar9;
        *(int *)(unaff_EBP + -0x40) = iVar9 + iVar13;
      }
      iStack_9c = unaff_EBP + -0x4c;
      iStack_a0 = unaff_EBP + -0x6c;
      iStack_a4 = *(int *)(unaff_EBP + -0x14);
      iStack_a8 = 0x54e89e;
      (**(code **)(*(int *)extraout_ECX[0x99] + 0x9c))();
      iVar9 = *(int *)(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(iVar8 + 0x14);
      iVar13 = *(int *)(iVar8 + 0x1c);
      *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(iVar8 + 0x18);
      iStack_a8 = 0;
      *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(iVar8 + 0x1c);
      *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(iVar8 + 0x20);
      iVar5 = *(int *)(iVar8 + 0x20);
      iVar10 = *(int *)(iVar9 + 0x20);
      iVar12 = *(int *)(iVar8 + 0x1c);
      iVar11 = (*(int *)(iVar9 + 0x1c) - iVar13) / 2;
      *(int *)(unaff_EBP + -0x4c) = iVar11;
      iVar13 = *(int *)(iVar8 + 0x20);
      *(int *)(unaff_EBP + -0x44) = iVar12 + iVar11;
      iVar5 = (iVar10 - iVar5) / 2;
      *(int *)(unaff_EBP + -0x40) = iVar13 + iVar5;
      piVar7 = (int *)extraout_ECX[0x99];
      *(int *)(unaff_EBP + -0x48) = iVar5;
      (**(code **)(*piVar7 + 0x9c))(iVar8,unaff_EBP + -0x6c,unaff_EBP + -0x4c);
      (**(code **)(*(int *)extraout_ECX[0x99] + 0x24))(0x10);
    }
    iVar13 = *(int *)(unaff_EBP + -0x18);
    *(undefined1 *)(extraout_ECX + 0x86) = 1;
    iVar13 = *(int *)(iVar13 + 0xc);
    iVar8 = *(int *)(unaff_EBP + -0x14);
    if (iVar13 < 0) {
      iVar5 = *(int *)(iVar8 + 0x1c);
      iVar13 = *(int *)(iVar9 + 0x1c) - iVar13;
      *(int *)(unaff_EBP + -0x2c) = iVar5;
      *(int *)(unaff_EBP + -0x28) = iVar13;
      piVar7 = (int *)(unaff_EBP + -0x2c);
      if (iVar5 <= iVar13) {
        piVar7 = (int *)(unaff_EBP + -0x28);
      }
    }
    else {
      iVar13 = iVar13 + *(int *)(iVar8 + 0x1c);
      iVar5 = *(int *)(iVar9 + 0x1c);
      *(int *)(unaff_EBP + -0x28) = iVar5;
      *(int *)(unaff_EBP + -0x2c) = iVar13;
      piVar7 = (int *)(unaff_EBP + -0x2c);
      if (iVar13 <= iVar5) {
        piVar7 = (int *)(unaff_EBP + -0x28);
      }
    }
    iVar13 = *(int *)(iVar8 + 0x20);
    *(int *)(unaff_EBP + -0x20) = *piVar7 << 1;
    iVar8 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x10);
    if (iVar8 < 0) {
      iVar5 = *(int *)(iVar9 + 0x20);
      *(int *)(unaff_EBP + -0x2c) = iVar13;
      iVar5 = iVar5 - iVar8;
      *(int *)(unaff_EBP + -0x28) = iVar5;
      puVar6 = (undefined4 *)(unaff_EBP + -0x2c);
      if (iVar13 <= iVar5) {
        puVar6 = (undefined4 *)(unaff_EBP + -0x28);
      }
    }
    else {
      iVar5 = *(int *)(iVar9 + 0x20);
      *(int *)(unaff_EBP + -0x28) = iVar5;
      *(int *)(unaff_EBP + -0x2c) = iVar8 + iVar13;
      puVar6 = (undefined4 *)(unaff_EBP + -0x2c);
      if (iVar8 + iVar13 <= iVar5) {
        puVar6 = (undefined4 *)(unaff_EBP + -0x28);
      }
    }
    iVar13 = 100;
    *(undefined4 *)(unaff_EBP + -0x28) = *puVar6;
    iStack_9c = 0x54e9d0;
    pvVar3 = operator_new(100);
    *(void **)(unaff_EBP + -0x2c) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar3 == (void *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = (int *)FUN_005dfb13();
      iVar13 = extraout_ECX_00;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (piVar7 == (int *)0x0) {
      iVar13 = *extraout_ECX;
      iStack_a0 = iVar9;
    }
    else {
      iVar9 = *piVar7;
      iStack_9c = 0;
      iStack_a0 = 0;
      *(int **)(unaff_EBP + -0x2c) = &iStack_a8;
      iStack_a8 = iVar13;
      iStack_a4 = iVar13;
      FUN_00436a50(4);
      cVar1 = (**(code **)(iVar9 + 0xc))
                        (*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x28));
      if (cVar1 != '\0') {
        cVar1 = (*(code *)((undefined4 *)*piVar7)[8])(1);
        if (cVar1 != '\0') {
          (**(code **)(*piVar7 + 0x38))(DAT_006f2a64,0);
          (**(code **)(*piVar7 + 0x24))(1);
        }
        (**(code **)(*piVar7 + 0x68))(DAT_006f2a64);
        cVar1 = (**(code **)(*piVar7 + 0x20))(0x10);
        if (cVar1 != '\0') {
          *(undefined4 *)(unaff_EBP + -0x5c) = 0;
          *(undefined4 *)(unaff_EBP + -0x58) = 0;
          *(undefined4 *)(unaff_EBP + -0x3c) = 0;
          iVar9 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x1c);
          iVar13 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x20);
          *(int *)(unaff_EBP + -0x54) = iVar9;
          *(int *)(unaff_EBP + -0x50) = iVar13;
          *(undefined4 *)(unaff_EBP + -0x38) = 0;
          iVar8 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0xc);
          *(int *)(unaff_EBP + -0x34) = iVar9;
          *(int *)(unaff_EBP + -0x30) = iVar13;
          if (iVar8 < 0) {
            iVar8 = -iVar8;
            *(int *)(unaff_EBP + -0x3c) = iVar8;
            *(int *)(unaff_EBP + -0x34) = iVar9 + iVar8;
            *(undefined4 *)(unaff_EBP + -0x38) = 0;
            *(int *)(unaff_EBP + -0x30) = iVar13;
          }
          iVar9 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x10);
          if (iVar9 < 0) {
            iVar9 = -iVar9;
            *(int *)(unaff_EBP + -0x38) = iVar9;
            *(int *)(unaff_EBP + -0x30) = iVar9 + iVar13;
          }
          iStack_9c = unaff_EBP + -0x5c;
          iStack_a0 = *(int *)(unaff_EBP + -0x1c);
          iStack_a4 = 0x54eae8;
          (**(code **)(*piVar7 + 0x9c))();
          iStack_a8 = unaff_EBP + -0x3c;
          iStack_a4 = 0;
          iVar9 = *(int *)(unaff_EBP + -0x20) >> 1;
          *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + iVar9;
          *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + iVar9;
          (**(code **)(*piVar7 + 0x9c))(*(undefined4 *)(unaff_EBP + -0x1c),unaff_EBP + -0x5c);
          *(undefined4 *)(unaff_EBP + -0x5c) = 0;
          *(undefined4 *)(unaff_EBP + -0x58) = 0;
          iVar9 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x1c);
          iVar13 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0xc);
          iVar8 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x20);
          *(int *)(unaff_EBP + -0x54) = iVar9;
          *(int *)(unaff_EBP + -0x50) = iVar8;
          *(undefined4 *)(unaff_EBP + -0x3c) = 0;
          *(undefined4 *)(unaff_EBP + -0x38) = 0;
          *(int *)(unaff_EBP + -0x34) = iVar9;
          *(int *)(unaff_EBP + -0x30) = iVar8;
          if (0 < iVar13) {
            *(int *)(unaff_EBP + -0x3c) = iVar13;
            *(int *)(unaff_EBP + -0x34) = iVar9 + iVar13;
            *(undefined4 *)(unaff_EBP + -0x38) = 0;
            *(int *)(unaff_EBP + -0x30) = iVar8;
          }
          iVar9 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x10);
          if (0 < iVar9) {
            *(int *)(unaff_EBP + -0x38) = iVar9;
            *(int *)(unaff_EBP + -0x30) = iVar9 + iVar8;
          }
          (**(code **)(*piVar7 + 0x9c))
                    (*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x5c,unaff_EBP + -0x3c,0);
          (**(code **)(*piVar7 + 0x24))(0x10);
          (**(code **)(*extraout_ECX + 0x19c))(piVar7,2,1);
          *(undefined1 *)((int)extraout_ECX + 0x16b) = 1;
        }
        goto LAB_0054eb89;
      }
      (**(code **)*piVar7)();
      iVar13 = *extraout_ECX;
      iStack_a0 = *(int *)(unaff_EBP + -0x1c);
    }
    iStack_9c = 1;
    iStack_a4 = 0x54ea3a;
    (**(code **)(iVar13 + 0x19c))();
  }
  uVar2 = 1;
LAB_0054ebc2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

