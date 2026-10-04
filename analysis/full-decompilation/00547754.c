
void FUN_00547754(void)

{
  undefined1 *puVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar6;
  int *piVar7;
  size_t sVar8;
  int *extraout_ECX;
  int iVar9;
  uint uVar10;
  int unaff_EBP;
  int iVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  if ((char)extraout_ECX[0x79] != '\0') {
    FUN_00547d55();
    *(undefined1 *)(extraout_ECX + 0x79) = 0;
  }
  iVar6 = extraout_ECX[0x45];
  if ((iVar6 == 0) || (*(int *)(iVar6 + 0xe8) - *(int *)(iVar6 + 0xe4) == 1)) {
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
  }
  iVar11 = 0;
  iVar9 = *(int *)(iVar6 + 0xe8) - *(int *)(iVar6 + 0xe4);
  bVar2 = true;
  if (iVar9 != 1 && -1 < iVar9 + -1) {
    do {
      if (*(char *)(*(int *)(iVar6 + 0xe4) + iVar11) != '\0') {
        cVar3 = *(char *)(*(int *)(iVar6 + 0xe4) + iVar11);
        *(undefined4 *)(unaff_EBP + -0x14) = **(undefined4 **)(iVar6 + 0x114);
        cVar3 = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x38))((int)cVar3);
        if (cVar3 == '\0') {
          bVar2 = false;
        }
      }
      iVar6 = extraout_ECX[0x45];
      iVar11 = iVar11 + 1;
    } while (iVar11 < (*(int *)(iVar6 + 0xe8) - *(int *)(iVar6 + 0xe4)) + -1);
    if (!bVar2) goto LAB_00547804;
  }
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
LAB_00547804:
  iVar6 = FUN_004eacb7(extraout_ECX[0x47]);
  *(int *)(unaff_EBP + -0x14) = iVar6;
  if (iVar6 < 2) {
    (**(code **)(*(int *)extraout_ECX[0x52] + 0x98))();
  }
  else {
    (**(code **)(*(int *)extraout_ECX[0x52] + 0x94))();
  }
  if (*(int *)(unaff_EBP + -0x14) < 2) {
    (**(code **)(*(int *)extraout_ECX[0x53] + 0x98))();
  }
  else {
    (**(code **)(*(int *)extraout_ECX[0x53] + 0x94))();
  }
  iVar6 = FUN_004ead68(extraout_ECX[0x47]);
  if (iVar6 < 2) {
    (**(code **)(*(int *)extraout_ECX[0x54] + 0x98))();
  }
  else {
    (**(code **)(*(int *)extraout_ECX[0x54] + 0x94))();
  }
  if (iVar6 < 2) {
    (**(code **)(*(int *)extraout_ECX[0x55] + 0x98))();
  }
  else {
    (**(code **)(*(int *)extraout_ECX[0x55] + 0x94))();
  }
  if (((*(char *)(unaff_EBP + -0xd) == '\0') || (*(int *)(unaff_EBP + -0x14) < 1)) || (iVar6 < 1)) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  piVar7 = (int *)extraout_ECX[0x56];
  if ((char)piVar7[0x5a] != cVar3) {
    *(char *)(piVar7 + 0x5a) = cVar3;
    (**(code **)(*piVar7 + 0x168))();
  }
  piVar7 = (int *)extraout_ECX[0x52];
  if ((char)piVar7[0x5a] != '\x01') {
    *(undefined1 *)(piVar7 + 0x5a) = 1;
    (**(code **)(*piVar7 + 0x168))();
  }
  piVar7 = (int *)extraout_ECX[0x53];
  if ((char)piVar7[0x5a] != '\x01') {
    *(undefined1 *)(piVar7 + 0x5a) = 1;
    (**(code **)(*piVar7 + 0x168))();
  }
  piVar7 = (int *)extraout_ECX[0x54];
  if ((char)piVar7[0x5a] != '\x01') {
    *(undefined1 *)(piVar7 + 0x5a) = 1;
    (**(code **)(*piVar7 + 0x168))();
  }
  piVar7 = (int *)extraout_ECX[0x55];
  if ((char)piVar7[0x5a] != '\x01') {
    *(undefined1 *)(piVar7 + 0x5a) = 1;
    (**(code **)(*piVar7 + 0x168))();
  }
  iVar6 = FUN_004eaa44(extraout_ECX[0x47]);
  if (iVar6 != 0) {
    FUN_005e46f0(0);
  }
  else {
    FUN_005e46f0(1);
  }
  FUN_005e46f0(iVar6 != 0);
  iVar6 = FUN_004eabb1(extraout_ECX[0x47]);
  if (iVar6 != 0) {
    FUN_005e46f0(0);
  }
  else {
    FUN_005e46f0(1);
  }
  FUN_005e46f0(iVar6 != 0);
  FUN_0040bfed(&DAT_006c1008);
  FUN_004eac5a(unaff_EBP + -0x4c,extraout_ECX[0x47]);
  iVar6 = FUN_0046f973(unaff_EBP + -0x3c);
  if (iVar6 == 0) {
    FUN_005e46f0(0);
    FUN_005e46f0(0);
    uVar12 = 1;
  }
  else {
    FUN_0040bfed(&DAT_006c100c);
    FUN_004eac5a(unaff_EBP + -0x4c,extraout_ECX[0x47]);
    iVar6 = FUN_0046f973(unaff_EBP + -0x3c);
    if (iVar6 != 0) {
      FUN_005e46f0(1);
    }
    else {
      FUN_005e46f0(0);
    }
    FUN_005e46f0(iVar6 == 0);
    uVar12 = 0;
  }
  FUN_005e46f0(uVar12);
  iVar6 = *(int *)(extraout_ECX[0x45] + 0xe8) - *(int *)(extraout_ECX[0x45] + 0xe4);
  if (iVar6 == 1 || iVar6 + -1 < 0) {
    iVar6 = (**(code **)(**(int **)(extraout_ECX[0x6c] + 0xd8) + 0x68))
                      (extraout_ECX[0x73],extraout_ECX[0x74] - extraout_ECX[0x73]);
    FUN_004ec186(iVar6 + 0x14);
    (**(code **)(*(int *)extraout_ECX[0x6c] + 0x1a0))(extraout_ECX[0x73]);
  }
  else {
    piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
    cVar3 = (**(code **)(*piVar7 + 0x84))(0xffffffff);
    if (cVar3 == '\0') {
      iVar9 = extraout_ECX[0x70];
      iVar6 = *(int *)(extraout_ECX[0x45] + 0xe4);
    }
    else {
      iVar6 = extraout_ECX[0x70];
      iVar9 = *(int *)(extraout_ECX[0x45] + 0xe4);
    }
    wsprintfA((LPSTR)(unaff_EBP + -600),s__s__s_006cd6e8,iVar6,iVar9);
    wsprintfA((LPSTR)(unaff_EBP + -0x158),(LPCSTR)extraout_ECX[0x6d],unaff_EBP + -600);
    iVar6 = **(int **)(extraout_ECX[0x6c] + 0xd8);
    sVar8 = _strlen((char *)(unaff_EBP + -0x158));
    iVar6 = (**(code **)(iVar6 + 0x68))(unaff_EBP + -0x158,sVar8);
    FUN_004ec186(iVar6 + 0x14);
    (**(code **)(*(int *)extraout_ECX[0x6c] + 0x1a0))(unaff_EBP + -0x158);
  }
  uVar10 = 0;
  if (extraout_ECX[0x59] - extraout_ECX[0x58] >> 2 != 0) {
    do {
      sVar4 = FUN_00563107();
      iVar6 = FUN_004ea79e(extraout_ECX[0x47]);
      piVar7 = &DAT_0066c600 + uVar10;
      uVar10 = uVar10 + 1;
      *(short *)(iVar6 + *piVar7 * 2) = sVar4 * 100;
    } while (uVar10 < (uint)(extraout_ECX[0x59] - extraout_ECX[0x58] >> 2));
  }
  if (extraout_ECX[0x77] != 0) {
    if (extraout_ECX[0x49] < 0x19) {
      iVar6 = FUN_004ea79e(extraout_ECX[0x47]);
      uVar5 = FUN_0048432f(iVar6);
      *(undefined2 *)(iVar6 + 0x8c) = uVar5;
      FUN_005d48d9();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005481eb(1,0);
      **(undefined1 **)(unaff_EBP + -0x48) = 0x28;
      FUN_005481eb(1,0);
      puVar1 = *(undefined1 **)(unaff_EBP + -0x2c);
      *puVar1 = 0x29;
      uVar12 = FUN_00484411(CONCAT22((short)((uint)puVar1 >> 0x10),*(undefined2 *)(iVar6 + 0x8c)));
      FUN_005d4956(uVar12);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005d499c(unaff_EBP + -0x48);
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x38),*(undefined4 *)(unaff_EBP + -0x34));
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x2c),*(undefined4 *)(unaff_EBP + -0x28));
      (**(code **)(*(int *)extraout_ECX[0x77] + 0x9c))(unaff_EBP + -0x20);
      (**(code **)(*(int *)extraout_ECX[0x77] + 0x90))(0x400,1);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    else {
      FUN_005d4956(&DAT_006de560);
      piVar7 = (int *)extraout_ECX[0x77];
      *(undefined4 *)(unaff_EBP + -4) = 4;
      (**(code **)(*piVar7 + 0x9c))(unaff_EBP + -0x58);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      (**(code **)(*(int *)extraout_ECX[0x77] + 0x90))(0x400,0);
    }
  }
  (**(code **)(*extraout_ECX + 0x168))();
  FUN_005db0b7();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

