
undefined4 FUN_004a01ca(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x198,0,0x104);
  *(undefined ***)(unaff_EBP + -0x1a4) = &PTR_FUN_006664e8;
  uVar2 = FUN_0041532c(6,unaff_EBP + -0x1a4);
  uVar2 = FUN_0041532c(0,uVar2);
  FUN_004ee9ce(uVar2);
  pvVar3 = operator_new(0x244);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_0046f5cd();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(unaff_EBP + -0x1c) = piVar4;
  (**(code **)(*piVar4 + 0xc))(unaff_EBP + -0x1a4,0);
  pvVar3 = operator_new(0x28);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004c71c6(*(undefined4 *)(unaff_EBP + -0x1c));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  FUN_004a1711(unaff_EBP + -0x1c);
  FUN_004c922e(extraout_ECX + 0x30);
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_0041532c(0,s_build_006c67c0,unaff_EBP + -0x1a4);
  FUN_004ee9ce(uVar2);
  FUN_0046f71c(unaff_EBP + -0x1a4,0);
  FUN_00470383(unaff_EBP + -0x500,0x82,0);
  FUN_00470383(unaff_EBP + -0x500,0x86,0);
  iVar5 = FUN_004705f2(1,0xffffffff);
  if (iVar5 == 0) {
    *(undefined4 *)(extraout_ECX + 0x114) = 0;
  }
  else {
    uVar2 = FUN_004705f2(1,0xffffffff);
    uVar2 = FUN_00635f62(uVar2);
    *(undefined4 *)(extraout_ECX + 0x114) = uVar2;
  }
  iVar5 = 1;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  do {
    pvVar3 = operator_new(0x30);
    *(void **)(unaff_EBP + -0x14) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    if (pvVar3 == (void *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = (undefined4 *)FUN_004a0873();
    }
    puVar6[4] = 0;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar7 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
    if (iVar7 != 0) {
      uVar2 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
      uVar2 = FUN_00635f62(uVar2);
      puVar6[4] = uVar2;
    }
    *puVar6 = 0;
    puVar6[1] = iVar5;
    puVar6[3] = iVar5 + 0x200;
    puVar6[2] = iVar5 + 0x100;
    iVar7 = (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x38))(0x53505232,iVar5,0);
    *(int *)(unaff_EBP + -0x14) = iVar7;
    if (iVar7 != 0) {
      FUN_0046f824(unaff_EBP + -100,0,0x40);
      *(undefined ***)(unaff_EBP + -0x70) = &PTR_FUN_0066651c;
      (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x48))
                (*(undefined4 *)(unaff_EBP + -0x14),unaff_EBP + -0x70);
      FUN_0049ff0e(unaff_EBP + -0x70);
      FUN_00465a06(*(undefined4 *)(unaff_EBP + -0x14));
    }
    *(int *)(unaff_EBP + -0x24) = iVar5;
    *(undefined4 **)(unaff_EBP + -0x20) = puVar6;
    FUN_004c662a(unaff_EBP + -0x1ac,unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 3;
    iVar5 = iVar5 + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 0x56);
  FUN_004a0820();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_0046f824(unaff_EBP + -0x2b0,0,0x104);
  *(undefined ***)(unaff_EBP + -700) = &PTR_FUN_006664e8;
  FUN_0046f847(&DAT_006c67b8,0xffffffff);
  FUN_0046f8e4(unaff_EBP + -700);
  FUN_005b8e25();
  if ((*(byte *)(DAT_006e486c + 0x66) & 1) != 0) {
    uVar2 = FUN_0041532c(0x1c,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
    uVar2 = FUN_0041532c(0x1f,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
    uVar2 = FUN_0041532c(0x25,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
    uVar2 = FUN_0041532c(0x2b,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x10) != 0) {
    uVar2 = FUN_0041532c(0x31,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
    uVar2 = FUN_0041532c(0x37,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
    uVar2 = FUN_0041532c(0x3d,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
    uVar2 = FUN_0041532c(0x5b,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  if (3 < *(short *)(DAT_006e486c + 0x66)) {
    uVar2 = FUN_0041532c(0x43,unaff_EBP + -0x1a4);
    FUN_004ee9ce(&DAT_006de560,uVar2);
    cVar1 = FUN_005b9b60(*(undefined4 *)(unaff_EBP + -0x1a0));
    if (cVar1 == '\0') {
      FUN_005b92ee(*(undefined4 *)(unaff_EBP + -0x1a0),1,1);
    }
    FUN_00412825(unaff_EBP + -0x1a4);
  }
  uVar2 = FUN_0041532c(0x12,unaff_EBP + -0x1a4);
  uVar2 = FUN_0041532c(0,uVar2);
  FUN_004ee9ce(uVar2);
  FUN_00412825(unaff_EBP + -0x1a4);
  for (iVar5 = *(int *)(unaff_EBP + -0x34); iVar5 != *(int *)(unaff_EBP + -0x30);
      iVar5 = iVar5 + 0x110) {
    FUN_004a08bd(iVar5);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004a08ab();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 0x118) = 1;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

