
void FUN_0045e8fd(void)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int *extraout_ECX;
  int iVar9;
  int unaff_EBP;
  uint uVar10;
  
  FUN_00634c24();
  if (((uint)extraout_ECX[0x45] >> 0xb & 1) != 0) goto LAB_0045ee4e;
  iVar9 = *(int *)(unaff_EBP + 8);
  uVar10 = extraout_ECX[0x45] | 0x800;
  extraout_ECX[0x45] = uVar10;
  if (iVar9 != 0) {
    uVar10 = *(uint *)(iVar9 + 0x114);
  }
  if ((uVar10 >> 0xc & 1) == 0) {
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  bVar1 = false;
  if (iVar9 == 0) {
LAB_0045e980:
    while ((extraout_ECX[0x2c1] - extraout_ECX[0x2c0]) / 0xc != 0) {
      iVar9 = *(int *)(extraout_ECX[0x2c1] + -8);
      piVar4 = *(int **)(extraout_ECX[0x2c1] + -0xc);
      while( true ) {
        iVar5 = FUN_004754ce();
        if (iVar5 <= iVar9 + -1) break;
        FUN_00475463();
        (**(code **)(*extraout_ECX + 8))();
      }
      if (*(char *)(unaff_EBP + -0xd) != '\0') {
        FUN_00444346(piVar4);
        (**(code **)(*piVar4 + 0x38))(0);
      }
    }
    FUN_0059294c(0);
    (**(code **)(*(int *)extraout_ECX[0x2b7] + 0xc))();
    (**(code **)(*(int *)extraout_ECX[0x2b7] + 0x14))();
    FUN_0045fc43(extraout_ECX[700],extraout_ECX[0x2bd]);
    for (iVar9 = extraout_ECX[0x52]; iVar9 != extraout_ECX[0x53]; iVar9 = iVar9 + 0x3c) {
      FUN_0046e15e(0);
    }
    FUN_0043270d(extraout_ECX);
    if (*(int *)(unaff_EBP + -0x24) != 0) {
      (**(code **)(*extraout_ECX + 0x50))(1);
      iVar9 = extraout_ECX[0x44];
      *(int *)(unaff_EBP + -0x18) = extraout_ECX[0x3d];
      *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x3e];
      cVar3 = (**(code **)(*extraout_ECX + 0x54))(unaff_EBP + -0x18,iVar9,0,0);
      if (cVar3 == '\0') {
        FUN_00434876();
        *(undefined1 *)(unaff_EBP + -0x1b) = 0;
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x18);
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x14);
        *(undefined1 *)(unaff_EBP + -0x30) = 1;
        *(int *)(unaff_EBP + -0x24) = iVar9;
        *(undefined1 *)(unaff_EBP + -0x1c) = 1;
        cVar3 = FUN_00434895(unaff_EBP + -0x30,unaff_EBP + -0x18);
        if (cVar3 == '\0') {
          *(undefined1 *)(unaff_EBP + -0x1c) = 0;
          FUN_00434895(unaff_EBP + -0x30,unaff_EBP + -0x18);
        }
      }
    }
    if (((uint)extraout_ECX[0x45] >> 6 & 1) == 0) {
      cVar3 = FUN_00432644();
      if (cVar3 == '\0') {
        (**(code **)(*extraout_ECX + 0x50))(1);
        iVar2 = DAT_006e54d8;
        iVar9 = extraout_ECX[0x3d];
        *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x3e];
        iVar5 = extraout_ECX[0x44];
        *(int *)(unaff_EBP + -0x18) = iVar9;
        *(int *)(unaff_EBP + -0x34) = iVar5;
        uVar10 = *(int *)(iVar2 + 0x10) / 2 << 4;
        *(uint *)(unaff_EBP + -0x14) = uVar10 | *(uint *)(unaff_EBP + -0x14) & 0xf;
        iVar5 = *(int *)(iVar2 + 0x10) / 2 << 4;
        uVar7 = *(undefined4 *)(unaff_EBP + -0x34);
        *(uint *)(unaff_EBP + -0x14) = uVar10 | 8;
        *(uint *)(unaff_EBP + -0x18) =
             CONCAT31((int3)((uint)iVar5 >> 8),(byte)iVar5 | (byte)iVar9 & 0xf) & 0xfffffff8 | 8;
        cVar3 = (**(code **)(*extraout_ECX + 0x54))(unaff_EBP + -0x18,uVar7,0,0);
        if (cVar3 == '\0') {
          FUN_00434876();
          *(undefined1 *)(unaff_EBP + -0x1b) = 0;
          *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x18);
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x14);
          *(undefined1 *)(unaff_EBP + -0x30) = 1;
          *(undefined4 *)(unaff_EBP + -0x24) = uVar7;
          *(undefined1 *)(unaff_EBP + -0x1c) = 1;
          cVar3 = FUN_00434895(unaff_EBP + -0x30,unaff_EBP + -0x18);
          if (cVar3 == '\0') {
            *(undefined1 *)(unaff_EBP + -0x1c) = 0;
            FUN_00434895(unaff_EBP + -0x30,unaff_EBP + -0x18);
          }
        }
        (**(code **)(*extraout_ECX + 0x88))(unaff_EBP + -0x18,uVar7,0,0);
        (**(code **)(*extraout_ECX + 0x74))();
      }
    }
    FUN_00457da4();
    uVar7 = *(undefined4 *)(extraout_ECX[0x47] + 0xc);
    uVar6 = FUN_004561a0(1);
    FUN_00474979(uVar7,uVar6);
    FUN_00422d79(3,0,0);
    *(undefined2 *)(extraout_ECX + 0x163) = 0;
    *(undefined2 *)(extraout_ECX + 0x177) = 0;
    *(undefined2 *)((int)extraout_ECX + 0x602) = 0;
    *(undefined2 *)((int)extraout_ECX + 0x8e) = 0;
    *(undefined2 *)(extraout_ECX + 0x17) = 0;
    uVar7 = FUN_0041ed45();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0045e839(uVar7);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    iVar9 = *(int *)(unaff_EBP + 8);
  }
  else {
    piVar4 = (int *)extraout_ECX[0x2c0];
    if (piVar4 != (int *)extraout_ECX[0x2c1]) {
      do {
        if (*piVar4 == iVar9) {
          bVar1 = true;
        }
        piVar4 = piVar4 + 3;
      } while (piVar4 != (int *)extraout_ECX[0x2c1]);
      if (bVar1) goto LAB_0045e980;
    }
    if (extraout_ECX[0x295] == iVar9) goto LAB_0045e980;
  }
  if (iVar9 == 0) {
    while (extraout_ECX[0x291] != extraout_ECX[0x290]) {
      FUN_0045ee5d();
    }
  }
  else {
    bVar1 = false;
    uVar10 = 0;
    if (extraout_ECX[0x291] != extraout_ECX[0x290]) {
      do {
        uVar8 = extraout_ECX[0x290] + uVar10 & 7;
        if ((extraout_ECX[uVar8 * 0x11 + 0x20a] == iVar9) ||
           (extraout_ECX[uVar8 * 0x11 + 0x20b] == iVar9)) {
          bVar1 = true;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < (uint)(extraout_ECX[0x291] - extraout_ECX[0x290]));
      if (bVar1) {
        FUN_0045f887();
        *(undefined4 *)(unaff_EBP + -4) = 1;
        while (extraout_ECX[0x291] != extraout_ECX[0x290]) {
          piVar4 = extraout_ECX + (extraout_ECX[0x290] & 7U) * 0x11 + 0x208;
          if ((piVar4[2] == iVar9) || (piVar4[3] == iVar9)) {
            FUN_0045ee5d();
          }
          else {
            FUN_0045f8b0(piVar4);
            FUN_0041ed45();
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_0045f8e7(unaff_EBP + -0x78);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            FUN_005b8770();
          }
        }
        extraout_ECX[0x291] = 0;
        extraout_ECX[0x290] = 0;
        while (*(int *)(unaff_EBP + -0xc0) != *(int *)(unaff_EBP + -0xc4)) {
          FUN_0041ed45();
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_0045f8e7(unaff_EBP + -0x78);
          FUN_0045f8b0(unaff_EBP + -0x78);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00635f6d(unaff_EBP + -0x2e4,0x44,8,FUN_004434c5);
      }
    }
    if (extraout_ECX[0x2a5] == iVar9) {
      uVar7 = FUN_0041ed45();
      *(undefined4 *)(unaff_EBP + -4) = 4;
      FUN_0041edc1(uVar7);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    else if (extraout_ECX[0x2a6] == iVar9) {
      extraout_ECX[0x2a6] = 0;
    }
    if (extraout_ECX[0x294] == iVar9) {
      uVar7 = FUN_0041ed45();
      *(undefined4 *)(unaff_EBP + -4) = 5;
      FUN_0045e839(uVar7);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    else if (extraout_ECX[0x295] == iVar9) {
      extraout_ECX[0x295] = 0;
    }
    if (*(short *)(*(int *)(iVar9 + 0x118) + 0x12) == 2) {
      for (iVar5 = extraout_ECX[700]; iVar5 != extraout_ECX[0x2bd]; iVar5 = iVar5 + 0x9c) {
        if (*(int *)(iVar5 + 0x80) == iVar9) {
          *(undefined1 *)(iVar5 + 0x84) = 1;
          *(undefined4 *)(iVar5 + 0x80) = 0;
          *(undefined4 *)(iVar5 + 0x90) = 0;
        }
      }
    }
  }
  *(byte *)((int)extraout_ECX + 0x115) = *(byte *)((int)extraout_ECX + 0x115) & 0xf7;
LAB_0045ee4e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

