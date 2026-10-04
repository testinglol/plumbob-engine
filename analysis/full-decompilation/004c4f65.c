
undefined4 FUN_004c4f65(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int extraout_ECX;
  int iVar11;
  int iVar12;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x19c,0,0x104);
  *(undefined ***)(unaff_EBP + -0x1a8) = &PTR_FUN_006664e8;
  uVar2 = FUN_0041532c(5,unaff_EBP + -0x1a8);
  uVar2 = FUN_0041532c(0,uVar2);
  FUN_004ee9ce(uVar2);
  pvVar3 = operator_new(0x244);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_0046f5cd();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(unaff_EBP + -0x20) = piVar4;
  (**(code **)(*piVar4 + 0xc))(unaff_EBP + -0x1a8,0);
  pvVar3 = operator_new(0x28);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004c71c6(*(undefined4 *)(unaff_EBP + -0x20));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar2;
  FUN_004a1711(unaff_EBP + -0x20);
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_0041532c(0,s_build_006c67c0,unaff_EBP + -0x1a8);
  FUN_004ee9ce(uVar2);
  FUN_0046f71c(unaff_EBP + -0x1a8,0);
  FUN_00470383(unaff_EBP + -0x504,0x83,0);
  FUN_00470383(unaff_EBP + -0x504,0x87,0);
  iVar5 = FUN_004705f2(1,0xffffffff);
  if (iVar5 == 0) {
    *(undefined4 *)(extraout_ECX + 0x108) = 0;
  }
  else {
    uVar2 = FUN_004705f2(1,0xffffffff);
    uVar2 = FUN_00635f62(uVar2);
    *(undefined4 *)(extraout_ECX + 0x108) = uVar2;
  }
  iVar5 = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  do {
    if (iVar5 == 0x1f) {
      iVar5 = 0xf8;
      *(undefined4 *)(unaff_EBP + -0x18) = 0xf8;
    }
    pvVar3 = operator_new(0x30);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar3 == (void *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = (undefined4 *)FUN_004c56dd();
    }
    puVar6[4] = 0;
    iVar8 = iVar5 * 3 + -2;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar7 = FUN_004705f2(iVar8,0xffffffff);
    if (iVar7 != 0) {
      uVar2 = FUN_004705f2(iVar8,0xffffffff);
      uVar2 = FUN_00635f62(uVar2);
      puVar6[4] = uVar2;
    }
    puVar6[1] = iVar5 + 0x600;
    puVar6[2] = iVar5 + 0x700;
    *puVar6 = 0;
    puVar6[3] = iVar5 + 0x800;
    iVar8 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x38))(0x53505223,iVar5,0);
    *(int *)(unaff_EBP + -0x10) = iVar8;
    if (iVar8 != 0) {
      FUN_0046f824(unaff_EBP + -0x68,0,0x40);
      *(undefined ***)(unaff_EBP + -0x74) = &PTR_FUN_0066651c;
      (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x48))
                (*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x74);
      if (*(short *)(unaff_EBP + -0x6c) == 7) {
        iVar5 = *(int *)(unaff_EBP + -0x70);
        cVar1 = *(char *)(iVar5 + 1);
        if ((cVar1 < '0') || ('9' < cVar1)) {
          if ((cVar1 < 'A') || ('F' < cVar1)) {
            iVar8 = 0;
          }
          else {
            iVar8 = cVar1 + -0x37;
          }
        }
        else {
          iVar8 = cVar1 + -0x30;
        }
        cVar1 = *(char *)(iVar5 + 2);
        if ((cVar1 < '0') || ('9' < cVar1)) {
          if ((cVar1 < 'A') || ('F' < cVar1)) {
            iVar7 = 0;
          }
          else {
            iVar7 = cVar1 + -0x37;
          }
        }
        else {
          iVar7 = cVar1 + -0x30;
        }
        cVar1 = *(char *)(iVar5 + 3);
        if ((cVar1 < '0') || ('9' < cVar1)) {
          if ((cVar1 < 'A') || ('F' < cVar1)) {
            iVar9 = 0;
          }
          else {
            iVar9 = cVar1 + -0x37;
          }
        }
        else {
          iVar9 = cVar1 + -0x30;
        }
        cVar1 = *(char *)(iVar5 + 4);
        if ((cVar1 < '0') || ('9' < cVar1)) {
          if ((cVar1 < 'A') || ('F' < cVar1)) {
            iVar11 = 0;
          }
          else {
            iVar11 = cVar1 + -0x37;
          }
        }
        else {
          iVar11 = cVar1 + -0x30;
        }
        cVar1 = *(char *)(iVar5 + 5);
        if ((cVar1 < '0') || ('9' < cVar1)) {
          if ((cVar1 < 'A') || ('F' < cVar1)) {
            iVar10 = 0;
          }
          else {
            iVar10 = cVar1 + -0x37;
          }
        }
        else {
          iVar10 = cVar1 + -0x30;
        }
        cVar1 = *(char *)(iVar5 + 6);
        if ((cVar1 < '0') || ('9' < cVar1)) {
          if ((cVar1 < 'A') || ('F' < cVar1)) {
            iVar12 = 0;
          }
          else {
            iVar12 = cVar1 + -0x37;
          }
        }
        else {
          iVar12 = cVar1 + -0x30;
        }
        iVar5 = *(int *)(unaff_EBP + -0x18);
        puVar6[0xb] = (((iVar8 * 0x10 + iVar7) * 0x100 | iVar9 * 0x10 + iVar11) << 8 |
                      iVar10 * 0x10 + iVar12) << 8;
      }
      FUN_00465a06(*(undefined4 *)(unaff_EBP + -0x10));
    }
    *(int *)(unaff_EBP + -0x28) = iVar5;
    *(undefined4 **)(unaff_EBP + -0x24) = puVar6;
    FUN_004c662a(unaff_EBP + -0x1b0,unaff_EBP + -0x28);
    iVar5 = iVar5 + 1;
    *(int *)(unaff_EBP + -0x18) = iVar5;
  } while (iVar5 < 0x100);
  FUN_004a0820();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_0046f824(unaff_EBP + -0x2b4,0,0x104);
  *(undefined ***)(unaff_EBP + -0x2c0) = &PTR_FUN_006664e8;
  FUN_0046f847(&DAT_006c7730,0xffffffff);
  FUN_0046f8e4(unaff_EBP + -0x2c0);
  FUN_005b8e25();
  if ((*(byte *)(DAT_006e486c + 0x66) & 1) != 0) {
    uVar2 = FUN_0041532c(0x1c,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
    uVar2 = FUN_0041532c(0x1f,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
    uVar2 = FUN_0041532c(0x25,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
    uVar2 = FUN_0041532c(0x2b,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x10) != 0) {
    uVar2 = FUN_0041532c(0x31,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
    uVar2 = FUN_0041532c(0x37,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
    uVar2 = FUN_0041532c(0x3d,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
    uVar2 = FUN_0041532c(0x5b,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  if (3 < *(short *)(DAT_006e486c + 0x66)) {
    uVar2 = FUN_0041532c(0x43,unaff_EBP + -0x1a8);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a4));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a4),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a8);
  }
  uVar2 = FUN_0041532c(0x13,unaff_EBP + -0x1a8);
  uVar2 = FUN_0041532c(0,uVar2);
  FUN_004ee9ce(uVar2);
  FUN_00412825(unaff_EBP + -0x1a8);
  for (iVar5 = *(int *)(unaff_EBP + -0x38); iVar5 != *(int *)(unaff_EBP + -0x34);
      iVar5 = iVar5 + 0x110) {
    FUN_004c5715(iVar5);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004a08ab();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined1 *)(*(int *)(unaff_EBP + -0x14) + 0x10c) = 1;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

