
undefined4 FUN_00528493(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  DWORD DVar11;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*extraout_ECX + 0x1b0))();
  FUN_005c1719();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar1 = FUN_004e95e0(extraout_ECX[0x65],unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  if (cVar1 != '\0') {
    iVar2 = FUN_004096c2();
    piVar7 = (int *)extraout_ECX[0x17];
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar2 + 0x20);
    cVar1 = (**(code **)(*piVar7 + 0x20))(0x10);
    if (cVar1 != '\0') {
      iVar2 = FUN_004096c2();
      iVar3 = *(int *)(iVar2 + 0x1c) / 5;
      iVar2 = FUN_004096c2();
      iVar2 = *(int *)(iVar2 + 0x20);
      iVar4 = (extraout_ECX[0x67] + 100) / iVar3;
      if (4 < iVar4) {
        iVar4 = 4;
      }
      *(int *)(unaff_EBP + -0x50) = iVar4 * iVar3;
      *(int *)(unaff_EBP + -0x48) = iVar4 * iVar3 + iVar3;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(int *)(unaff_EBP + -0x44) = iVar2;
      iVar4 = extraout_ECX[8];
      iVar5 = ((extraout_ECX[0x21] - iVar3) - extraout_ECX[0x1f]) / 2 + extraout_ECX[7];
      *(int *)(unaff_EBP + -0x3c) = iVar4;
      *(int *)(unaff_EBP + -0x40) = iVar5;
      *(int *)(unaff_EBP + -0x38) = iVar5 + iVar3;
      piVar7 = (int *)extraout_ECX[0x17];
      *(int *)(unaff_EBP + -0x34) = iVar4 + iVar2;
      iVar2 = *piVar7;
      uVar6 = FUN_004096c2(unaff_EBP + -0x50,unaff_EBP + -0x40,0);
      (**(code **)(iVar2 + 0x9c))(uVar6);
      (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(0x10);
    }
  }
  piVar7 = (int *)FUN_005e40a5();
  *(int **)(unaff_EBP + -0x18) = piVar7;
  if (piVar7 == (int *)0x0) {
    iVar2 = *(int *)(unaff_EBP + -0x1c);
  }
  else {
    uVar6 = (**(code **)(*piVar7 + 0x1c))();
    *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
    piVar8 = (int *)FUN_005e7743();
    iVar2 = *piVar7;
    iVar3 = (**(code **)(*piVar8 + 0x50))(extraout_ECX[0x3c]);
    iVar4 = extraout_ECX[0x3a];
    *(int *)(unaff_EBP + -0x10) = iVar2;
    piVar7 = *(int **)(unaff_EBP + -0x18);
    (**(code **)(*(int *)(unaff_EBP + -0x10) + 0x20))(*(undefined4 *)(iVar3 + iVar4 * 4));
    iVar2 = wsprintfA((LPSTR)(unaff_EBP + -0x60),(LPCSTR)&DAT_006c08e4,extraout_ECX[0x68]);
    *(int *)(unaff_EBP + -0x10) = iVar2;
    *(int *)(unaff_EBP + -0x3c) = extraout_ECX[8] + -2 + *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x40) = extraout_ECX[7];
    *(int *)(unaff_EBP + -0x38) = extraout_ECX[9];
    iVar2 = (**(code **)(*piVar7 + 0x58))();
    piVar7 = (int *)extraout_ECX[0x17];
    iVar2 = iVar2 + *(int *)(unaff_EBP + -0x3c);
    *(int *)(unaff_EBP + -0x34) = iVar2;
    cVar1 = (**(code **)(*piVar7 + 0x20))(1);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)extraout_ECX[0x17] + 0x4c))(DAT_006f2a58,unaff_EBP + -0x40);
      (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(1);
    }
    (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x80))
              (extraout_ECX[0x17],unaff_EBP + -0x40,unaff_EBP + -0x60,
               *(undefined4 *)(unaff_EBP + -0x10),1);
    (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x20))(*(undefined4 *)(unaff_EBP + -0x20));
  }
  iVar2 = iVar2 - extraout_ECX[8];
  *(int *)(unaff_EBP + -0x20) = extraout_ECX[0x67] + 100;
  *(int *)(unaff_EBP + -0x1c) = iVar2;
  iVar3 = __ftol();
  iVar4 = DAT_006e486c;
  *(int *)(unaff_EBP + -0x10) = iVar3;
  if (*(int *)(iVar4 + 0x34) == 1) {
    if (((char)extraout_ECX[0x5a] != '\0') &&
       ((*(char *)((int)extraout_ECX + 0x169) != '\0' || (extraout_ECX[0x38] != 0)))) {
      piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
      uVar9 = (**(code **)(*piVar7 + 0x38))(0xff,0,0);
      piVar7 = DAT_006fe8bc;
      *(uint *)(unaff_EBP + -0x20) = uVar9 & 0xffff;
      piVar7 = (int *)(**(code **)(*piVar7 + 0x1c))();
      (**(code **)(*piVar7 + 0x38))(0,0xff,0);
      uVar9 = FUN_0049a996(*(int *)(unaff_EBP + -0x10) >> 3);
      *(uint *)(unaff_EBP + -0x18) = uVar9 & 0xffff;
      uVar9 = FUN_0049a996(0xff - *(int *)(unaff_EBP + -0x10) >> 3);
      goto LAB_00528723;
    }
    uVar9 = FUN_0049a996(iVar3 >> 3);
    *(uint *)(unaff_EBP + -0x18) = uVar9 & 0xffff;
    uVar9 = FUN_0049a996(0xff - *(int *)(unaff_EBP + -0x10) >> 3);
LAB_00528828:
    *(uint *)(unaff_EBP + -0x10) = uVar9 & 0xffff;
  }
  else {
    if (((char)extraout_ECX[0x5a] == '\0') ||
       ((*(char *)((int)extraout_ECX + 0x169) == '\0' && (extraout_ECX[0x38] == 0)))) {
      uVar9 = FUN_0049a775(iVar3 >> 3);
      *(uint *)(unaff_EBP + -0x18) = uVar9 & 0xffff;
      uVar9 = FUN_0049a775(0xff - *(int *)(unaff_EBP + -0x10) >> 3);
      goto LAB_00528828;
    }
    piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    uVar9 = (**(code **)(*piVar7 + 0x38))(0xff,0,0);
    piVar7 = DAT_006fe8bc;
    *(uint *)(unaff_EBP + -0x20) = uVar9 & 0xffff;
    piVar7 = (int *)(**(code **)(*piVar7 + 0x1c))();
    (**(code **)(*piVar7 + 0x38))(0,0xff,0);
    uVar9 = FUN_0049a775(*(int *)(unaff_EBP + -0x10) >> 3);
    *(uint *)(unaff_EBP + -0x18) = uVar9 & 0xffff;
    uVar9 = FUN_0049a775(0xff - *(int *)(unaff_EBP + -0x10) >> 3);
LAB_00528723:
    iVar2 = *(int *)(unaff_EBP + -0x1c);
    *(uint *)(unaff_EBP + -0x10) = uVar9 & 0xffff;
  }
  iVar4 = (extraout_ECX[0x21] - extraout_ECX[0x1f]) + -0x28;
  *(int *)(unaff_EBP + -0x1c) = iVar4 - (iVar4 >> 0x1f);
  iVar4 = extraout_ECX[0x68];
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) >> 1;
  *(int *)(unaff_EBP + -0x20) = iVar4 + 100;
  iVar10 = __ftol();
  iVar4 = extraout_ECX[0x21];
  iVar3 = extraout_ECX[0x1f];
  *(int *)(unaff_EBP + -0x24) = iVar2 + 2;
  iVar5 = extraout_ECX[7];
  *(int *)(unaff_EBP + -0x30) = ((iVar4 - iVar3) + -0x28) / 2 + iVar5;
  iVar4 = extraout_ECX[8];
  *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar4;
  *(int *)(unaff_EBP + -0x28) = iVar5 + (*(int *)(unaff_EBP + -0x1c) - iVar10);
  *(int *)(unaff_EBP + -0x2c) = iVar4 + iVar2;
  cVar1 = (**(code **)(*(int *)extraout_ECX[0x17] + 0x20))(1);
  if (cVar1 != '\0') {
    (**(code **)(*(int *)extraout_ECX[0x17] + 0x40))
              (*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0x30,0);
    piVar7 = (int *)extraout_ECX[0x17];
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x28);
    *(int *)(unaff_EBP + -0x38) =
         ((extraout_ECX[0x21] - extraout_ECX[0x1f]) + 0x28) / 2 + extraout_ECX[7];
    (**(code **)(*piVar7 + 0x40))(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x40,0);
    if (1 < *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x40)) {
      *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x2c);
      iVar2 = *(int *)(unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x24);
      *(int *)(unaff_EBP + -0x48) = iVar2;
      *(int *)(unaff_EBP + -0x50) = iVar2 + -1;
      if (iVar2 != iVar2 + -1) {
        (**(code **)(*(int *)extraout_ECX[0x17] + 0x40))(0,unaff_EBP + -0x50,0);
      }
    }
    (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(1);
  }
  *(int *)(unaff_EBP + -0x20) = extraout_ECX[0x67] + 100;
  iVar2 = __ftol();
  *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x24) + 2;
  piVar7 = (int *)extraout_ECX[0x17];
  *(int *)(unaff_EBP + -0x28) = iVar2 + *(int *)(unaff_EBP + -0x30);
  *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 6;
  cVar1 = (**(code **)(*piVar7 + 0x20))(1);
  if (cVar1 != '\0') {
    (**(code **)(*(int *)extraout_ECX[0x17] + 0x40))
              (*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0x30,0);
    piVar7 = (int *)extraout_ECX[0x17];
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x2c);
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x28);
    *(int *)(unaff_EBP + -0x38) =
         ((extraout_ECX[0x21] - extraout_ECX[0x1f]) + 0x28) / 2 + extraout_ECX[7];
    (**(code **)(*piVar7 + 0x40))(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x40,0);
    if (1 < *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x40)) {
      *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x2c);
      iVar2 = *(int *)(unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x24);
      *(int *)(unaff_EBP + -0x48) = iVar2;
      *(int *)(unaff_EBP + -0x50) = iVar2 + -1;
      if (iVar2 != iVar2 + -1) {
        (**(code **)(*(int *)extraout_ECX[0x17] + 0x40))(0,unaff_EBP + -0x50,0);
      }
    }
    (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(1);
  }
  piVar7 = (int *)FUN_005e40a5();
  *(int **)(unaff_EBP + -0x20) = piVar7;
  if (piVar7 != (int *)0x0) {
    uVar6 = (**(code **)(*piVar7 + 0x1c))();
    *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
    piVar8 = (int *)FUN_005e7743();
    iVar2 = *piVar7;
    iVar3 = (**(code **)(*piVar8 + 0x50))(extraout_ECX[0x3c]);
    iVar4 = extraout_ECX[0x3a];
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    piVar7 = *(int **)(unaff_EBP + -0x20);
    (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0x20))(*(undefined4 *)(iVar3 + iVar4 * 4));
    iVar2 = wsprintfA((LPSTR)(unaff_EBP + -0x60),(LPCSTR)&DAT_006c08e4,extraout_ECX[0x67]);
    *(int *)(unaff_EBP + -0x20) = iVar2;
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x30);
    *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x30) + 0x28;
    iVar2 = (**(code **)(*piVar7 + 0x58))();
    piVar8 = (int *)extraout_ECX[0x17];
    *(int *)(unaff_EBP + -0x34) = iVar2 + *(int *)(unaff_EBP + -0x3c);
    cVar1 = (**(code **)(*piVar8 + 0x20))(1);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)extraout_ECX[0x17] + 0x4c))(DAT_006f2a58,unaff_EBP + -0x40);
      (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(1);
    }
    (**(code **)(*piVar7 + 0x80))
              (extraout_ECX[0x17],unaff_EBP + -0x40,unaff_EBP + -0x60,
               *(undefined4 *)(unaff_EBP + -0x20),1);
    (**(code **)(*piVar7 + 0x20))(*(undefined4 *)(unaff_EBP + -0x18));
  }
  piVar7 = (int *)FUN_005e40a5();
  iVar2 = (**(code **)(*piVar7 + 0x58))();
  cVar1 = *(char *)((int)extraout_ECX + 0x1a5);
  *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + -3 + iVar2;
  if (((cVar1 == '\0') && ((char)extraout_ECX[0x69] == '\0')) &&
     (*(char *)((int)extraout_ECX + 0x1a6) == '\0')) goto LAB_00528c4a;
  cVar1 = (**(code **)(*(int *)extraout_ECX[0x17] + 0x20))(0x10);
  iVar2 = DAT_006f3b9c;
  if (cVar1 == '\0') goto LAB_00528c4a;
  if (((char)extraout_ECX[0x69] != '\0') && (DAT_006f3b9c != 0)) {
    iVar4 = *(int *)(DAT_006f3b9c + 0x1c);
    iVar3 = *(int *)(DAT_006f3b9c + 0x20);
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x24) + 1;
    *(int *)(unaff_EBP + -0x38) = iVar4;
    *(int *)(unaff_EBP + -0x48) = iVar4 + *(int *)(unaff_EBP + -0x30);
    *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x30);
    *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x20);
    *(int *)(unaff_EBP + -0x34) = iVar3;
    piVar7 = (int *)extraout_ECX[0x17];
    *(undefined4 *)(unaff_EBP + -0x40) = 0;
    *(undefined4 *)(unaff_EBP + -0x3c) = 0;
    *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x20) + iVar3;
    (**(code **)(*piVar7 + 0x9c))(iVar2,unaff_EBP + -0x40,unaff_EBP + -0x50,0);
  }
  iVar3 = DAT_006f3ba4;
  iVar4 = DAT_006f3ba0;
  iVar2 = DAT_006f3b9c;
  if ((*(char *)((int)extraout_ECX + 0x1a6) == '\0') || (DAT_006f3ba4 == 0)) {
    if ((*(char *)((int)extraout_ECX + 0x1a5) != '\0') && (DAT_006f3ba0 != 0)) {
      uVar6 = *(undefined4 *)(DAT_006f3ba0 + 0x1c);
      iVar3 = *(int *)(DAT_006f3ba0 + 0x20);
      *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
      *(undefined4 *)(unaff_EBP + -0x48) = uVar6;
      *(undefined4 *)(unaff_EBP + -0x38) = uVar6;
      *(undefined4 *)(unaff_EBP + -0x50) = 0;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(int *)(unaff_EBP + -0x44) = iVar3;
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(int *)(unaff_EBP + -0x34) = iVar3;
      iVar2 = *(int *)(iVar2 + 0x1c);
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x24) + 1;
      iVar2 = iVar2 + 3 + *(int *)(unaff_EBP + -0x30);
      *(int *)(unaff_EBP + -0x40) = iVar2;
      *(int *)(unaff_EBP + -0x38) = iVar2 + *(int *)(unaff_EBP + -0x20);
      *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x1c);
      piVar7 = (int *)extraout_ECX[0x17];
      *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x1c) + iVar3;
      iVar2 = *piVar7;
      goto LAB_00528c38;
    }
  }
  else {
    uVar6 = *(undefined4 *)(DAT_006f3ba4 + 0x1c);
    iVar4 = *(int *)(DAT_006f3ba4 + 0x20);
    *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
    *(undefined4 *)(unaff_EBP + -0x48) = uVar6;
    *(undefined4 *)(unaff_EBP + -0x38) = uVar6;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0;
    *(int *)(unaff_EBP + -0x44) = iVar4;
    *(undefined4 *)(unaff_EBP + -0x40) = 0;
    *(undefined4 *)(unaff_EBP + -0x3c) = 0;
    *(int *)(unaff_EBP + -0x34) = iVar4;
    iVar2 = *(int *)(iVar2 + 0x1c);
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x24) + 1;
    iVar2 = iVar2 + 3 + *(int *)(unaff_EBP + -0x30);
    *(int *)(unaff_EBP + -0x40) = iVar2;
    *(int *)(unaff_EBP + -0x38) = iVar2 + *(int *)(unaff_EBP + -0x20);
    *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x1c);
    piVar7 = (int *)extraout_ECX[0x17];
    *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x1c) + iVar4;
    iVar2 = *piVar7;
    iVar4 = iVar3;
LAB_00528c38:
    (**(code **)(iVar2 + 0x9c))(iVar4,unaff_EBP + -0x50,unaff_EBP + -0x40,0);
  }
  (**(code **)(*(int *)extraout_ECX[0x17] + 0x24))(0x10);
LAB_00528c4a:
  if ((char)extraout_ECX[0x5b] != '\0') {
    FUN_005d9928(unaff_EBP + -0x1c,unaff_EBP + -0x20);
    DVar11 = timeGetTime();
    if ((uint)extraout_ECX[0x56] < DVar11 - extraout_ECX[0x57]) {
      if (extraout_ECX[0x12] != 0) {
        FUN_005da644(extraout_ECX[0x12],3,0x13,extraout_ECX,0);
      }
      *(undefined1 *)(extraout_ECX + 0x5b) = 0;
    }
    else {
      (**(code **)(*extraout_ECX + 0x168))();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005a5e09();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

