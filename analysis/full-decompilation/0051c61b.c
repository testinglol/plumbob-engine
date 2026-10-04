
void FUN_0051c61b(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int *extraout_ECX;
  int *piVar8;
  int unaff_EBP;
  int iVar9;
  uint uVar10;
  
  FUN_00634c24();
  uVar3 = FUN_004e9902();
  *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
  uVar3 = FUN_004e99a9();
  iVar5 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
  iVar9 = extraout_ECX[0x3a];
  *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
  extraout_ECX[0x3a] = -1;
  if (iVar5 == -1) {
    if (iVar9 != -1) {
      (**(code **)(*extraout_ECX + 0x168))();
    }
    goto LAB_0051ceab;
  }
  iVar9 = 0;
  if (0 < *(int *)(unaff_EBP + -0x20)) {
    do {
      iVar4 = FUN_004e9918(iVar9);
      if (iVar5 == iVar4) {
        extraout_ECX[0x3a] = iVar9;
        *(int *)(unaff_EBP + -0x1c) = iVar5;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < *(int *)(unaff_EBP + -0x20));
  }
  iVar5 = FUN_004e9744(*(undefined4 *)(unaff_EBP + -0x1c));
  *(int *)(unaff_EBP + -0x28) = iVar5;
  if ((iVar5 == 0) || (1 < *(short *)(iVar5 + 0x60e))) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x94) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 8;
    cVar1 = FUN_004fff98(0x86,&DAT_006c265c,unaff_EBP + -0x94,0);
    if (cVar1 != '\0') {
      uVar3 = FUN_004705f2(8,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005b8770();
      uVar3 = FUN_004705f2(10,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005b8770();
      piVar8 = (int *)extraout_ECX[0x5c];
      if ((char)piVar8[0x5a] != '\0') {
        *(undefined1 *)(piVar8 + 0x5a) = 0;
        (**(code **)(*piVar8 + 0x168))();
      }
      uVar3 = FUN_004705f2(10,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005b8770();
      piVar8 = (int *)extraout_ECX[0x5d];
      if ((char)piVar8[0x5a] != '\0') {
        *(undefined1 *)(piVar8 + 0x5a) = 0;
        (**(code **)(*piVar8 + 0x168))();
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else if ((*(short *)(iVar5 + 0x600) == 0) || (0x11 < *(short *)(iVar5 + 0x600))) {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x94) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_004fff98(0x86,&DAT_006c265c,unaff_EBP + -0x94,0);
    if (cVar1 != '\0') {
      uVar3 = FUN_004705f2(3,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      uVar3 = FUN_004705f2(6,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      piVar8 = (int *)extraout_ECX[0x5c];
      if ((char)piVar8[0x5a] != '\x01') {
        *(undefined1 *)(piVar8 + 0x5a) = 1;
        (**(code **)(*piVar8 + 0x168))();
      }
      uVar3 = FUN_004705f2(7,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      piVar8 = (int *)extraout_ECX[0x5d];
      if ((char)piVar8[0x5a] != '\x01') {
        *(undefined1 *)(piVar8 + 0x5a) = 1;
        (**(code **)(*piVar8 + 0x168))();
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x94) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    cVar1 = FUN_004fff98(0x86,&DAT_006c265c,unaff_EBP + -0x94,0);
    if (cVar1 != '\0') {
      uVar3 = FUN_004705f2(9,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      uVar3 = FUN_004705f2(6,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      piVar8 = (int *)extraout_ECX[0x5c];
      if ((char)piVar8[0x5a] != '\x01') {
        *(undefined1 *)(piVar8 + 0x5a) = 1;
        (**(code **)(*piVar8 + 0x168))();
      }
      uVar3 = FUN_004705f2(7,0xffffffff);
      FUN_005d4956(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005dd9c8(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      piVar8 = (int *)extraout_ECX[0x5d];
      if ((char)piVar8[0x5a] != '\x01') {
        *(undefined1 *)(piVar8 + 0x5a) = 1;
        (**(code **)(*piVar8 + 0x168))();
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_00470467();
  if (extraout_ECX[0x3f] == 1) {
    iVar5 = FUN_004e9744(*(undefined4 *)(unaff_EBP + -0x1c));
    if ((iVar5 == 0) || (1 < *(short *)(iVar5 + 0x60e))) {
      (**(code **)(*(int *)extraout_ECX[0x40] + 0x98))();
      (**(code **)(*(int *)extraout_ECX[0x41] + 0x94))();
    }
    else {
      (**(code **)(*(int *)extraout_ECX[0x40] + 0x94))();
      (**(code **)(*(int *)extraout_ECX[0x41] + 0x98))();
    }
    iVar5 = 0;
    do {
      FUN_00513b1d(*(undefined4 *)(unaff_EBP + -0x1c));
      FUN_00513b1d(*(undefined4 *)(unaff_EBP + -0x1c));
      iVar5 = iVar5 + 4;
    } while (iVar5 < 0x20);
  }
  (**(code **)(*extraout_ECX + 0x168))();
  uVar10 = 0;
  if (extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2 != 0) {
    do {
      FUN_005e46f0(uVar10 == extraout_ECX[0x3a]);
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)(extraout_ECX[0x3d] - extraout_ECX[0x3c] >> 2));
  }
  if (((extraout_ECX[0x3f] == 5) && (*(char *)(extraout_ECX[0x56] + 0xe0) != '\0')) &&
     (uVar10 = 0, extraout_ECX[0x54] - extraout_ECX[0x53] >> 2 != 0)) {
    do {
      if (*(int *)(*(int *)(extraout_ECX[0x53] + uVar10 * 4) + 0xe0) != 0) {
        FUN_00528ce1();
        FUN_0050fc6a(*(undefined4 *)(*(int *)(extraout_ECX[0x53] + uVar10 * 4) + 0x1ac));
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)(extraout_ECX[0x54] - extraout_ECX[0x53] >> 2));
  }
  if ((extraout_ECX[0x3f] == 6) && (*(char *)(extraout_ECX[0x56] + 0xe0) == '\x01')) {
    piVar8 = extraout_ECX + 0xd7;
    iVar5 = 0x13;
    do {
      if (*(int *)(*piVar8 + 0xe0) != 0) {
        FUN_0050f513();
        FUN_0050fc6a(*(undefined4 *)(*piVar8 + 0x19c));
      }
      piVar8 = piVar8 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (extraout_ECX[0x3f] == 3) {
    iVar5 = FUN_004e9744(*(undefined4 *)(unaff_EBP + -0x1c));
    if (((iVar5 == 0) || (*(short *)(iVar5 + 0x600) == 0)) || (0x11 < *(short *)(iVar5 + 0x600))) {
      if (((uint)(int)*(short *)(iVar5 + 0x60e) >> 1 & 1) == 0) {
        if (((uint)(int)*(short *)(iVar5 + 0x60e) >> 2 & 1) != 0) {
          (**(code **)(*(int *)extraout_ECX[0x44] + 0x98))();
          (**(code **)(*(int *)extraout_ECX[0x45] + 0x98))();
          (**(code **)(*(int *)extraout_ECX[0x46] + 0x94))();
          goto LAB_0051cd55;
        }
        cVar1 = FUN_004cffcb(*(undefined4 *)(unaff_EBP + -0x24));
        if (cVar1 == '\0') {
          (**(code **)(*(int *)extraout_ECX[0x44] + 0x94))();
          (**(code **)(*(int *)extraout_ECX[0x45] + 0x98))();
          goto LAB_0051cd47;
        }
        (**(code **)(*(int *)extraout_ECX[0x47] + 0x94))();
        (**(code **)(*(int *)extraout_ECX[0x44] + 0x98))();
        (**(code **)(*(int *)extraout_ECX[0x45] + 0x98))();
        (**(code **)(*(int *)extraout_ECX[0x46] + 0x98))();
        piVar8 = (int *)extraout_ECX[0x49];
      }
      else {
        (**(code **)(*(int *)extraout_ECX[0x44] + 0x98))();
        (**(code **)(*(int *)extraout_ECX[0x45] + 0x94))();
LAB_0051cd47:
        (**(code **)(*(int *)extraout_ECX[0x46] + 0x98))();
LAB_0051cd55:
        (**(code **)(*(int *)extraout_ECX[0x49] + 0x98))();
        piVar8 = (int *)extraout_ECX[0x47];
      }
      (**(code **)(*piVar8 + 0x98))();
    }
    else {
      (**(code **)(*(int *)extraout_ECX[0x44] + 0x98))();
      (**(code **)(*(int *)extraout_ECX[0x45] + 0x98))();
      (**(code **)(*(int *)extraout_ECX[0x46] + 0x98))();
      (**(code **)(*(int *)extraout_ECX[0x47] + 0x98))();
      (**(code **)(*(int *)extraout_ECX[0x49] + 0x94))();
    }
  }
  if (*(int *)(unaff_EBP + -0x1c) != -1) {
    iVar5 = FUN_004ea79e(*(undefined4 *)(unaff_EBP + -0x1c));
    if (*(short *)(iVar5 + 0x82) < 2) {
      (**(code **)(*(int *)extraout_ECX[0x71] + 0x94))();
      if (*(short *)(iVar5 + 0x8c) == 0) {
        uVar2 = FUN_0048432f(iVar5);
        *(undefined2 *)(iVar5 + 0x8c) = uVar2;
      }
      uVar3 = FUN_00484411(*(undefined2 *)(iVar5 + 0x8c));
      FUN_005d4956(uVar3);
      piVar8 = (int *)extraout_ECX[0x71];
      *(undefined4 *)(unaff_EBP + -4) = 0xc;
      (**(code **)(*piVar8 + 0x9c))(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar3 = FUN_005e40a5();
      iVar5 = extraout_ECX[0x71];
      *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
      iVar9 = *(int *)(iVar5 + 0x50);
      iVar5 = *(int *)(iVar5 + 0x4c);
      puVar6 = (undefined4 *)FUN_005e40a5();
      uVar3 = *puVar6;
      *(undefined4 **)(unaff_EBP + 8) = puVar6;
      *(undefined4 *)(unaff_EBP + -0x24) = uVar3;
      uVar3 = FUN_004096c2(iVar9 - iVar5);
      uVar3 = (**(code **)(*(int *)(unaff_EBP + -0x24) + 0x68))(uVar3);
      uVar7 = (**(code **)(**(int **)(unaff_EBP + -0x20) + 0x58))();
      FUN_004cb1a2(uVar3,uVar7);
      iVar5 = (**(code **)(*(int *)extraout_ECX[0x71] + 0x18))();
      FUN_004cb21d(5,((*(int *)(extraout_ECX[0x71] + 0x80) - *(int *)(extraout_ECX[0x71] + 0x88)) -
                     *(int *)(iVar5 + 0x80)) + -5 + *(int *)(iVar5 + 0x88));
    }
    else {
      (**(code **)(*(int *)extraout_ECX[0x71] + 0x98))();
    }
  }
  if (((*(int *)(unaff_EBP + -0x28) != 0) && (1 < *(short *)(*(int *)(unaff_EBP + -0x28) + 0x60e)))
     && ((extraout_ECX[0x3f] == 6 || (extraout_ECX[0x3f] == 7)))) {
    FUN_0051d3e7(1);
  }
LAB_0051ceab:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

