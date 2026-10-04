
void __thiscall FUN_0053ad22(int *param_1,int param_2)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  int *piVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar9 = param_2;
  uVar3 = *(uint *)(param_2 + 0xc);
  if ((uVar3 & 2) != 0) {
    (**(code **)(*param_1 + 0x168))();
    FUN_0053b6eb(3);
    uVar13 = 0;
    uVar12 = 0;
    uStack_10 = 0;
    uVar11 = 0;
    uStack_c = 0;
    uStack_8 = 0;
    iVar7 = FUN_00401f6f();
    if (iVar7 == 0) {
      uVar13 = 2;
      uVar11 = 1;
    }
    else if (iVar7 == 1) {
      uVar13 = 1;
      uStack_10 = 1;
    }
    else if (iVar7 == 2) {
      uVar13 = 0;
      uVar12 = 1;
    }
    else if (iVar7 == 3) {
      uStack_c = 1;
      uVar13 = 3;
    }
    else if (iVar7 == 4) {
      uStack_8 = 1;
      uVar13 = 5;
    }
    FUN_0050a8c0(uVar13);
    FUN_005e46f0(uVar12);
    FUN_005e46f0(uStack_10);
    FUN_005e46f0(uVar11);
    FUN_005e46f0(uStack_c);
    FUN_005e46f0(uStack_8);
  }
  if ((uVar3 & 0x100) != 0) {
    iVar7 = FUN_004cebac();
    FUN_005e46f0(iVar7 == 1);
    iVar7 = FUN_004cebac();
    FUN_005e46f0(iVar7 == 2);
    piVar10 = (int *)param_1[0x43];
    if ((char)piVar10[0x5a] != '\x01') {
      *(undefined1 *)(piVar10 + 0x5a) = 1;
      (**(code **)(*piVar10 + 0x168))();
    }
    iVar7 = FUN_00401f6f();
    if (((iVar7 == 0) && (cVar5 = FUN_004cfc5c(), cVar5 != '\0')) ||
       (cVar5 = FUN_004cfc50(), cVar5 != '\0')) {
      piVar10 = (int *)param_1[0x44];
      if ((char)piVar10[0x5a] != '\x01') {
        *(undefined1 *)(piVar10 + 0x5a) = 1;
        (**(code **)(*piVar10 + 0x168))();
      }
    }
    else {
      piVar10 = (int *)param_1[0x44];
      if ((char)piVar10[0x5a] != '\0') {
        *(undefined1 *)(piVar10 + 0x5a) = 0;
        (**(code **)(*piVar10 + 0x168))();
      }
      iVar7 = FUN_004cebac();
      if (iVar7 == 2) {
        FUN_004cefa3(1,0);
        FUN_005e46f0(1);
      }
    }
  }
  if ((uVar3 & 0x80) != 0) {
    uVar13 = 0;
    uVar12 = 0;
    param_2 = 0;
    uStack_8 = 0;
    iVar7 = FUN_005ecb6f();
    if (iVar7 == 1) {
      uVar12 = 1;
    }
    else if (iVar7 == 2) {
      uVar13 = 1;
    }
    else if (iVar7 == 4) {
      param_2 = 1;
    }
    else if (iVar7 == 8) {
      uStack_8 = 1;
    }
    FUN_005e46f0(uVar12);
    FUN_005e46f0(param_2);
    FUN_005e46f0(uVar13);
    FUN_005e46f0(uStack_8);
    uVar8 = FUN_004cfc3b();
    piVar4 = (int *)param_1[0x3a];
    piVar10 = piVar4 + 0x5a;
    if ((uVar8 & 1) == 0) {
      if ((char)*piVar10 != '\0') {
        *(char *)piVar10 = '\0';
        goto LAB_0053af96;
      }
    }
    else if ((char)*piVar10 != '\x01') {
      *(char *)piVar10 = '\x01';
LAB_0053af96:
      (**(code **)(*piVar4 + 0x168))();
    }
    piVar4 = (int *)param_1[0x3b];
    piVar10 = piVar4 + 0x5a;
    if ((uVar8 & 4) == 0) {
      if ((char)*piVar10 != '\0') {
        *(char *)piVar10 = '\0';
        goto LAB_0053afc1;
      }
    }
    else if ((char)*piVar10 != '\x01') {
      *(char *)piVar10 = '\x01';
LAB_0053afc1:
      (**(code **)(*piVar4 + 0x168))();
    }
    piVar4 = (int *)param_1[0x3c];
    piVar10 = piVar4 + 0x5a;
    if ((uVar8 & 2) == 0) {
      if ((char)*piVar10 != '\0') {
        *(char *)piVar10 = '\0';
        goto LAB_0053afec;
      }
    }
    else if ((char)*piVar10 != '\x01') {
      *(char *)piVar10 = '\x01';
LAB_0053afec:
      (**(code **)(*piVar4 + 0x168))();
    }
  }
  if ((uVar3 & 0x1000) != 0) {
    cVar5 = FUN_004ceb81();
    cVar6 = FUN_004ceb8b();
    piVar10 = (int *)param_1[0x38];
    if ((cVar5 != (char)piVar10[0x5a]) && ((char)piVar10[0x5a] != cVar5)) {
      *(char *)(piVar10 + 0x5a) = cVar5;
      (**(code **)(*piVar10 + 0x168))();
    }
    piVar10 = (int *)param_1[0x39];
    if ((cVar6 != (char)piVar10[0x5a]) && ((char)piVar10[0x5a] != cVar6)) {
      *(char *)(piVar10 + 0x5a) = cVar6;
      (**(code **)(*piVar10 + 0x168))();
    }
  }
  if ((uVar3 & 0x4000) != 0) {
    uVar13 = FUN_004ceb7d();
    iVar7 = FUN_005d49d6();
    if ((iVar7 == 0) || (iVar7 = FUN_005d49d6(), iVar7 == 0)) {
      piVar10 = (int *)param_1[0x42];
      (**(code **)(*piVar10 + 0x9c))(uVar13);
      (**(code **)(*piVar10 + 0x168))();
      param_1[0x5f] = 0;
    }
    else {
      cVar5 = FUN_005d49dc(param_1[0x42] + 0x4c);
      if (param_1[0x5f] == 0) {
        if (cVar5 == '\0') {
          FUN_005d499c(uVar13);
          param_1[0x5f] = 1;
          param_1[0x60] = param_1[99];
          iVar7 = param_1[99] + DAT_006e5490;
          param_1[0x61] = iVar7;
          param_1[0x62] = iVar7;
          puVar1 = (uint *)(iVar9 + 0x10);
          *puVar1 = *puVar1 | 0x4000;
          FUN_005e46f0(1);
        }
      }
      else if (DAT_006e5490 < (uint)param_1[0x61]) {
        if (cVar5 == '\0') {
          if (param_1[0x5f] == 1) {
            FUN_005d499c(uVar13);
          }
          else {
            piVar10 = (int *)param_1[0x42];
            (**(code **)(*piVar10 + 0x9c))(uVar13);
            (**(code **)(*piVar10 + 0x168))();
          }
        }
      }
      else {
        param_1[0x61] = 0xffffffff;
        if (param_1[0x5f] == 1) {
          piVar10 = (int *)param_1[0x42];
          (**(code **)(*piVar10 + 0x9c))(param_1 + 0x65);
          (**(code **)(*piVar10 + 0x168))();
          param_1[0x5f] = 2;
          param_1[0x60] = param_1[100];
          iVar9 = param_1[100] + DAT_006e5490;
          param_1[0x61] = iVar9;
          param_1[0x62] = iVar9;
        }
        else if (param_1[0x5f] == 2) {
          FUN_005e46f0(0);
          param_1[0x5f] = 0;
          pbVar2 = (byte *)(iVar9 + 0x11);
          *pbVar2 = *pbVar2 & 0xbf;
        }
      }
    }
  }
  if ((uVar3 & 0x2000) != 0) {
    uVar13 = FUN_004ceb79();
    cVar5 = FUN_005d49dc(param_1 + 0x5c);
    if (cVar5 == '\0') {
      FUN_005d499c(uVar13);
      (**(code **)(*param_1 + 0x168))();
    }
  }
  if ((uVar3 & 0x80000) != 0) {
    uVar13 = FUN_004425e2();
    FUN_004cf024(uVar13);
    cVar5 = FUN_0046d982();
    if (cVar5 != '\0') {
      FUN_004cefe5(1);
    }
    uVar13 = FUN_004cff43();
    FUN_005d4bbf(uVar13);
  }
  if ((uVar3 & 0x42) != 0) {
    FUN_0053b6eb(0);
    cVar5 = FUN_0046d8e8();
    if (cVar5 == '\0') {
      iVar9 = FUN_0046d8a7();
    }
    else {
      iVar9 = FUN_0046d8f2();
    }
    iVar7 = FUN_004425e2();
    if (iVar9 == iVar7) {
      uVar13 = 1;
LAB_0053b2c5:
      FUN_005e46f0(uVar13);
      uVar13 = 0;
LAB_0053b2cb:
      FUN_005e46f0(uVar13);
      uVar13 = 0;
    }
    else {
      iVar7 = FUN_0046d380();
      if (iVar9 == iVar7) {
        FUN_005e46f0(0);
        uVar13 = 1;
        goto LAB_0053b2cb;
      }
      iVar7 = FUN_0046d386();
      uVar13 = 0;
      if (iVar9 != iVar7) goto LAB_0053b2c5;
      FUN_005e46f0(0);
      FUN_005e46f0(0);
      uVar13 = 1;
    }
    FUN_005e46f0(uVar13);
  }
  if ((uVar3 & 0x800000) != 0) {
    FUN_0053b6eb(1);
  }
  if ((uVar3 & 0x100000) != 0) {
    iVar9 = FUN_004cfe0d();
    if (iVar9 == 0) {
      uVar13 = 0;
    }
    else {
      iVar9 = FUN_004cfe0d();
      if (iVar9 != 1) goto LAB_0053b363;
      uVar13 = 1;
    }
    FUN_0053b4a0(uVar13);
  }
LAB_0053b363:
  if ((uVar3 & 0x1000000) != 0) {
    cVar5 = FUN_004cebb8();
    piVar4 = (int *)param_1[0x3e];
    piVar10 = piVar4 + 0x5a;
    if (cVar5 == '\0') {
      if ((char)*piVar10 != '\x01') {
        *(char *)piVar10 = '\x01';
        (**(code **)(*piVar4 + 0x168))();
      }
      piVar10 = (int *)param_1[0x3f];
      if ((char)piVar10[0x5a] != '\x01') {
        *(undefined1 *)(piVar10 + 0x5a) = 1;
        goto LAB_0053b3d4;
      }
    }
    else {
      if ((char)*piVar10 != '\0') {
        *(char *)piVar10 = '\0';
        (**(code **)(*piVar4 + 0x168))();
      }
      piVar10 = (int *)param_1[0x3f];
      if ((char)piVar10[0x5a] != '\0') {
        *(undefined1 *)(piVar10 + 0x5a) = 0;
LAB_0053b3d4:
        (**(code **)(*piVar10 + 0x168))();
      }
    }
  }
  if ((uVar3 & 0x8000000) == 0) {
    return;
  }
  cVar5 = FUN_004cebca();
  piVar4 = (int *)param_1[0x3d];
  piVar10 = piVar4 + 0x5a;
  if (cVar5 == '\x01') {
    if ((char)*piVar10 != '\0') {
      *(char *)piVar10 = '\0';
      (**(code **)(*piVar4 + 0x168))();
    }
    piVar10 = (int *)param_1[0x41];
    if ((char)piVar10[0x5a] == '\0') goto LAB_0053b459;
    *(undefined1 *)(piVar10 + 0x5a) = 0;
  }
  else {
    if ((char)*piVar10 != '\x01') {
      *(char *)piVar10 = '\x01';
      (**(code **)(*piVar4 + 0x168))();
    }
    piVar10 = (int *)param_1[0x41];
    if ((char)piVar10[0x5a] == '\x01') goto LAB_0053b459;
    *(undefined1 *)(piVar10 + 0x5a) = 1;
  }
  (**(code **)(*piVar10 + 0x168))();
LAB_0053b459:
  cVar5 = FUN_004cffb7();
  if (cVar5 == '\x01') {
    (**(code **)(*(int *)param_1[0x42] + 0x98))();
    (**(code **)(*(int *)param_1[0x74] + 0x98))();
  }
  else {
    (**(code **)(*(int *)param_1[0x42] + 0x94))();
    (**(code **)(*(int *)param_1[0x74] + 0x94))();
  }
  return;
}

