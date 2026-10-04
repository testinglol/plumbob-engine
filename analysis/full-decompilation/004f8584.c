
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004f8584(void)

{
  short sVar1;
  char *pcVar2;
  undefined4 *puVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  HANDLE pvVar10;
  int iVar11;
  void *pvVar12;
  undefined1 uVar13;
  int unaff_EBP;
  int iVar14;
  bool bVar15;
  PSIZE_T lpMinimumWorkingSetSize;
  SIZE_T SVar16;
  undefined2 uVar17;
  PSIZE_T lpMaximumWorkingSetSize;
  SIZE_T SVar18;
  
  FUN_00634c24();
  piVar8 = DAT_006f26d4;
  piVar9 = DAT_006f26d0;
  bVar15 = DAT_006f26d0 == DAT_006f26d4;
  *(int **)(unaff_EBP + -0x30) = DAT_006f26d0;
  if (bVar15) {
LAB_004f85be:
    FUN_005d4bbf();
    goto LAB_004f9600;
  }
  do {
    if (*piVar9 == *(int *)(unaff_EBP + 0xc)) break;
    piVar9 = piVar9 + 5;
    *(int **)(unaff_EBP + -0x30) = piVar9;
  } while (piVar9 != piVar8);
  if (piVar9 == piVar8) goto LAB_004f85be;
  uVar13 = 0;
  *(undefined1 *)(unaff_EBP + -0x1c) = 0;
  iVar14 = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  _strlen(s_Format_is___006cbf20);
  FUN_00412d8a();
  FUN_004faaff();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00412d8a();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  _strlen(&DAT_006c2afc);
  FUN_00412d8a();
  iVar11 = *(int *)(unaff_EBP + 8);
  iVar6 = *(int *)(*(int *)(unaff_EBP + -0x30) + 0x10);
  if (iVar6 == 2) {
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc == 2) {
      iVar6 = _strcmp(&DAT_006c7110,*(char **)(*(int *)(iVar11 + 4) + 0xc));
      if (iVar6 == 0) {
        bVar4 = 1;
        *(undefined1 *)(unaff_EBP + -0x1c) = 1;
        goto LAB_004f88a8;
      }
      iVar6 = _strcmp((char *)&PTR_DAT_006c710c,*(char **)(*(int *)(iVar11 + 4) + 0xc));
      if (iVar6 == 0) {
        *(undefined1 *)(unaff_EBP + -0x1c) = 0;
        goto LAB_004f88a5;
      }
      FUN_005d4956();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_00412a04();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      uVar7 = FUN_00412a04(unaff_EBP + -0x6c);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_00412ab1(unaff_EBP + -0x4c,uVar7,unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
    }
    else {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
LAB_004f86a8:
      FUN_00401729();
    }
    FUN_005d4bbf();
    goto LAB_004fa95c;
  }
  if (iVar6 == 1) {
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc != 1) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 10;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto LAB_004f86a8;
    }
  }
  else if (iVar6 == 3) {
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc != 2) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto LAB_004f86a8;
    }
    pcVar2 = *(char **)(*(int *)(iVar11 + 4) + 0xc);
    *(char **)(unaff_EBP + 8) = pcVar2;
    cVar5 = *pcVar2;
    while (cVar5 != '\0') {
      iVar6 = FUN_006368c3();
      if ((iVar6 == 0) && (**(char **)(unaff_EBP + 8) != '-')) {
        FUN_004fee54();
        *(undefined1 *)(unaff_EBP + -4) = 0xd;
        FUN_005b86bd();
        *(undefined1 *)(unaff_EBP + -4) = 0xe;
        FUN_005d499c();
        *(undefined1 *)(unaff_EBP + -4) = 0xd;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        goto LAB_004f86a8;
      }
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      cVar5 = **(char **)(unaff_EBP + 8);
    }
    iVar14 = FUN_00635f62();
  }
LAB_004f88a5:
  bVar4 = *(byte *)(unaff_EBP + -0x1c);
LAB_004f88a8:
  switch(*(undefined4 *)(unaff_EBP + 0xc)) {
  case 0:
    iVar11 = FUN_004e99a9();
    if (iVar11 != -1) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x5b0) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      iVar11 = FUN_00470383();
      if (iVar11 == 0) {
        FUN_004e99a9();
        FUN_004ea79e();
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x9bc) = &PTR_FUN_0066773c;
        iVar11 = 0x2e;
        do {
          iVar11 = iVar11 + 1;
          FUN_004705f2();
          FUN_0046f847();
          FUN_0046f847();
          FUN_0046fa40();
          FUN_0046f847();
        } while (iVar11 < 0x36);
        FUN_004f6994();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_00470467();
      break;
    }
    goto code_r0x004f88ca;
  case 1:
    uRam006e523c = (ushort)bVar4;
    break;
  case 2:
    uRam006e523e = (ushort)bVar4;
    break;
  case 3:
    DAT_006c7238 = (ushort)bVar4;
code_r0x004f99cb:
    FUN_004a6a39();
    break;
  case 4:
    DAT_006e5606 = (ushort)bVar4;
    break;
  case 5:
    DAT_006e5608 = (ushort)bVar4;
    break;
  case 6:
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc == 2) {
      iVar6 = _strcmp(*(char **)(*(int *)(iVar11 + 4) + 0xc),s_begin_006cbe6c);
      iVar11 = _strcmp(*(char **)(*(int *)(iVar11 + 4) + 0xc),(char *)0x6cbe68);
      if ((iVar6 == 0) || (iVar11 == 0)) {
        if (iVar6 == 0) {
          if (DAT_006e5438 != '\0') {
            FUN_005d4956();
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_00412ab1();
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            FUN_005b86bd();
            *(undefined1 *)(unaff_EBP + -4) = 0x12;
            FUN_005d499c();
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 0x10;
            FUN_00401729();
            *(undefined1 *)(unaff_EBP + -4) = 0;
code_r0x004f8b46:
            FUN_005b8770();
            goto code_r0x004f88ca;
          }
          func_0x0046c221();
        }
        else {
          if (DAT_006e5438 == '\0') {
            FUN_005d4956();
            *(undefined1 *)(unaff_EBP + -4) = 0x13;
            FUN_00412ab1();
            *(undefined1 *)(unaff_EBP + -4) = 0x14;
            FUN_005b86bd();
            *(undefined1 *)(unaff_EBP + -4) = 0x15;
            FUN_005d499c();
            *(undefined1 *)(unaff_EBP + -4) = 0x14;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 0x13;
            FUN_00401729();
            *(undefined1 *)(unaff_EBP + -4) = 0;
            goto code_r0x004f8b46;
          }
          FUN_0046c225();
        }
        break;
      }
    }
    goto code_r0x004f88ca;
  case 7:
    FUN_0040766a();
    break;
  case 8:
    if (DAT_006f0668 == 0) {
      if (bVar4 != 0) goto code_r0x004f8c90;
    }
    else if (bVar4 == 0) {
code_r0x004f8c90:
      piVar9 = (int *)FUN_00484901();
      if (piVar9 != (int *)0x0) {
        DAT_006f0668 = (uint)*(byte *)(unaff_EBP + -0x1c);
        FUN_004a6a39();
        if (*(char *)(unaff_EBP + -0x1c) != '\0') {
          iVar11 = *piVar9;
          goto code_r0x004f8cf3;
        }
        goto code_r0x004f8d04;
      }
    }
    break;
  case 9:
    piVar9 = (int *)FUN_00484901();
    if (piVar9 != (int *)0x0) {
      if (iVar14 != 0) {
        iVar11 = *piVar9;
code_r0x004f8cf3:
        (**(code **)(iVar11 + 0x30))();
      }
code_r0x004f8d04:
      func_0x004cf247();
    }
    break;
  case 10:
    DAT_006e4a84 = (uint)bVar4;
    break;
  case 0xb:
    if ((3 < iVar14) && (iVar14 < 0x41)) {
      FUN_00415e16();
      goto code_r0x004f99cb;
    }
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x318) = &PTR_FUN_00666524;
    FUN_0046f847();
    FUN_0046fa40();
    FUN_0046f847();
    goto code_r0x004f88ca;
  case 0xc:
    if ((iVar14 < 0) || (3 < iVar14)) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x16;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x17;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x16;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004fa645;
    }
    if (*(int *)(DAT_006f2a08 + 0xb0) != 0) {
      FUN_004ceefb();
    }
    break;
  case 0xd:
    iVar11 = *(int *)(*DAT_006e486c + 0x14);
    piVar9 = *(int **)(iVar11 + 0x84);
    if (piVar9 != *(int **)(iVar11 + 0x88)) {
      do {
        iVar6 = *piVar9;
        piVar9 = piVar9 + 1;
        *(ushort *)(iVar6 + 0x5c6) = (ushort)(bVar4 == 0);
      } while (piVar9 != *(int **)(iVar11 + 0x88));
    }
    break;
  case 0xe:
    iVar11 = *(int *)(*DAT_006e486c + 0x14);
    for (piVar9 = *(int **)(iVar11 + 0x84); piVar9 != *(int **)(iVar11 + 0x88); piVar9 = piVar9 + 1)
    {
      *(short *)(*piVar9 + 0x5d4) = (short)iVar14;
    }
    break;
  case 0xf:
    DAT_006e50e4 = bVar4;
    break;
  case 0x10:
    piVar9 = (int *)FUN_00484901();
    if (piVar9 != (int *)0x0) {
      (**(code **)(*piVar9 + 0x30))();
    }
    break;
  case 0x11:
    cVar5 = FUN_004f1b96();
    goto joined_r0x004fa5c2;
  case 0x12:
    cVar5 = FUN_004f1b96();
    goto joined_r0x004fa5c2;
  case 0x13:
    FUN_004e99a9();
    iVar11 = FUN_004e9744();
    if (iVar11 == 0) goto code_r0x004fa80b;
    FUN_0042004f();
    break;
  case 0x14:
    FUN_004e99a9();
    iVar11 = FUN_004e9744();
    if (iVar11 == 0) goto code_r0x004fa80b;
    FUN_004212aa();
    break;
  case 0x15:
    bRam006c4370 = bVar4;
    break;
  case 0x16:
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x318) = &PTR_FUN_00666524;
    FUN_00427cfb();
    FUN_004ceefb();
    FUN_004cefe5();
    FUN_004425e2();
    FUN_004cf024();
    FUN_004ceec9();
    FUN_004cf0ab();
    if (DAT_006f0668 != 0) {
      DAT_006f0668 = 0;
      func_0x004cf247();
    }
    iVar11 = *(int *)(*DAT_006e486c + 0x14);
    for (piVar9 = *(int **)(iVar11 + 0x84); piVar9 != *(int **)(iVar11 + 0x88); piVar9 = piVar9 + 1)
    {
      *(undefined2 *)(*piVar9 + 0x5d4) = 0x32;
      *(undefined2 *)(*piVar9 + 0x5c6) = 0;
    }
    FUN_00444346();
    sVar1 = *(short *)(unaff_EBP + -0x310);
joined_r0x004f9098:
    if (sVar1 != 0) goto code_r0x004fa80b;
    break;
  case 0x17:
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc == 3) {
      cVar5 = FUN_004fab8b();
      if ((cVar5 != '\0') && (cVar5 = FUN_004fab8b(), cVar5 != '\0')) {
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0x318) = &PTR_FUN_00666524;
        FUN_00427d9d();
        sVar1 = *(short *)(unaff_EBP + -0x310);
        goto joined_r0x004f9098;
      }
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x1a;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x1b;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x1a;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
    }
    else {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x18;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x19;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x18;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
    }
    goto code_r0x004fa645;
  case 0x18:
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc == 5) {
      cVar5 = FUN_004fab8b();
      if ((((cVar5 != '\0') && (cVar5 = FUN_004fab8b(), cVar5 != '\0')) &&
          (cVar5 = FUN_004fab8b(), cVar5 != '\0')) && (cVar5 = FUN_004fab8b(), cVar5 != '\0')) {
        FUN_0047c1f4();
        goto code_r0x004f99cb;
      }
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x1e;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x1f;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x1e;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
    }
    else {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x1c;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x1d;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x1c;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
    }
    goto code_r0x004fa645;
  case 0x19:
    FUN_004cf024();
    break;
  case 0x1a:
    if ((iVar14 < 0) || (0x17 < iVar14)) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x20;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x21;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x20;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004fa645;
    }
    FUN_0046d98b();
    break;
  case 0x1b:
    if (1 < (*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc) {
      FUN_005d48d9();
      iVar6 = *(int *)(iVar11 + 8);
      iVar14 = *(int *)(iVar11 + 4);
      *(undefined1 *)(unaff_EBP + -4) = 0x22;
      *(undefined4 *)(unaff_EBP + 8) = 1;
      if (1 < (iVar6 - iVar14) / 0xc) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0xc;
        do {
          _strlen(*(char **)(*(int *)(iVar11 + 0x10) + *(int *)(unaff_EBP + 0xc)));
          FUN_00412d8a();
          if (*(int *)(unaff_EBP + 8) < (*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc + -1) {
            _strlen(&DAT_006c3d7c);
            FUN_00412d8a();
          }
          iVar6 = *(int *)(iVar11 + 8);
          iVar14 = *(int *)(iVar11 + 4);
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
          *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 0xc;
        } while (*(int *)(unaff_EBP + 8) < (iVar6 - iVar14) / 0xc);
      }
      FUN_004d2f91();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004f9830;
    }
  default:
LAB_004f95f4:
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
LAB_004f9600:
    uVar13 = 0;
    goto LAB_004f9602;
  case 0x1c:
    goto code_r0x004f9892;
  case 0x1d:
    FUN_005b8680();
    *(undefined1 *)(unaff_EBP + -4) = 0x23;
    FUN_0043cc48();
    if (*(int *)(unaff_EBP + -0x38) != *(int *)(unaff_EBP + -0x3c)) {
      FUN_005d4956();
      *(undefined1 *)(unaff_EBP + -4) = 0x24;
      FUN_004096c2();
      FUN_005d4956();
      iVar11 = *(int *)(DAT_006f2a08 + 0x48);
      *(undefined1 *)(unaff_EBP + -4) = 0x25;
      (**(code **)(iVar11 + 0x2c))();
      *(undefined1 *)(unaff_EBP + -4) = 0x24;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0x23;
      FUN_005b8770();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    goto code_r0x004fa327;
  case 0x1e:
    FUN_004f6994();
    func_0x0043dde7();
    break;
  case 0x1f:
    func_0x004eaea4();
    break;
  case 0x20:
    FUN_0057a634();
    break;
  case 0x21:
    FUN_0057a69d();
    break;
  case 0x22:
    DAT_006c42bc = (uint)bVar4;
    break;
  case 0x23:
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc != 2) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x26;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x27;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x26;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004fa645;
    }
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x42c) = &PTR_FUN_006664e8;
    FUN_0041532c();
    FUN_004ee9ce();
    FUN_0046f5cd();
    *(undefined1 *)(unaff_EBP + -4) = 0x28;
    iVar11 = FUN_0046f71c();
    if (iVar11 == 0) {
      FUN_0046b7ee();
      FUN_0042888d();
      FUN_00424839();
      FUN_004f5aa0();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0046b2e6();
      break;
    }
    FUN_005d4956();
    *(undefined1 *)(unaff_EBP + -4) = 0x29;
    FUN_00412a04();
    *(undefined1 *)(unaff_EBP + -4) = 0x2a;
    FUN_005b86bd();
    *(undefined1 *)(unaff_EBP + -4) = 0x2b;
    FUN_005d499c();
    *(undefined1 *)(unaff_EBP + -4) = 0x2a;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0x29;
    FUN_00401729();
    *(undefined1 *)(unaff_EBP + -4) = 0x28;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0046b2e6();
    goto LAB_004f95f4;
  case 0x24:
    FUN_004cebf8();
    break;
  case 0x25:
    FUN_00587231();
    break;
  case 0x26:
  case 0x27:
    goto code_r0x004f968c;
  case 0x28:
code_r0x004f968c:
    FUN_005d4bbf();
    goto code_r0x004f88ca;
  case 0x29:
    if ((bVar4 == 0) && (DAT_006e4f10 != 0)) {
      FUN_00445489();
      bVar4 = *(byte *)(unaff_EBP + -0x1c);
    }
    DAT_006e4f14 = (uint)bVar4;
    if ((bVar4 == 0) && (DAT_006e4f10 != 0)) {
      FUN_00445541();
    }
    break;
  case 0x2a:
    if ((bRam006f26cc & 1) == 0) {
      bRam006f26cc = bRam006f26cc | 1;
      FUN_005d48d9();
      FUN_00635543();
    }
    if ((1 < (*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc) ||
       (iVar6 = FUN_005d49d6(), iVar6 != 0)) {
      FUN_005d48d9();
      iVar6 = *(int *)(iVar11 + 8);
      iVar11 = *(int *)(iVar11 + 4);
      *(undefined1 *)(unaff_EBP + -4) = 0x2e;
      if ((iVar6 - iVar11) / 0xc < 2) {
        FUN_005d499c();
      }
      else {
        FUN_005d4bbf();
      }
      FUN_005d499c();
      FUN_0057a7f7();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004f9830;
    }
    FUN_004fee54();
    *(undefined1 *)(unaff_EBP + -4) = 0x2c;
    FUN_005b86bd();
    *(undefined1 *)(unaff_EBP + -4) = 0x2d;
    FUN_005d499c();
    *(undefined1 *)(unaff_EBP + -4) = 0x2c;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
code_r0x004fa645:
    FUN_00401729();
    goto code_r0x004f88ca;
  case 0x2b:
    FUN_005d4956();
    *(undefined1 *)(unaff_EBP + -4) = 0x30;
    FUN_0057a7f7();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    goto code_r0x004f9830;
  case 0x2c:
    FUN_005d4956();
    *(undefined1 *)(unaff_EBP + -4) = 0x2f;
    FUN_0057a7f7();
    *(undefined1 *)(unaff_EBP + -4) = 0;
code_r0x004f9830:
    FUN_005b8770();
    break;
  case 0x2d:
    FUN_004f2661();
    break;
  case 0x2e:
    iVar11 = FUN_004f6994();
    if (iVar11 == 4) {
      FUN_00636b97();
    }
    break;
  case 0x2f:
code_r0x004f9892:
    FUN_0046dae0();
    break;
  case 0x30:
    FUN_004faf09();
    break;
  case 0x31:
    break;
  case 0x32:
    func_0x004eaf2b();
    break;
  case 0x33:
    iVar11 = FUN_004e99a9();
    if (iVar11 != -1) {
      pvVar12 = operator_new(0x208);
      *(void **)(unaff_EBP + 8) = pvVar12;
      *(undefined1 *)(unaff_EBP + -4) = 0x31;
      if (pvVar12 == (void *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)FUN_005458e5();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      if (piVar9 != (int *)0x0) {
        (**(code **)(**(int **)(DAT_006f2a08 + 0x84) + 0x98))();
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(DAT_006f2a08 + 0x84) + 0x88);
        (**(code **)(*piVar9 + 0x60))();
        FUN_00547736(iVar11);
        FUN_005ea5ab();
        cVar5 = (**(code **)(*piVar9 + 0xc))();
        if (cVar5 != '\0') {
          FUN_004b38e5();
          piVar8 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
          piVar9 = DAT_006fe8bc;
          uVar7 = (**(code **)(*piVar8 + 8))();
          (**(code **)(*piVar9 + 0x18))(uVar7);
          FUN_005daa44(uVar7);
          FUN_004b3938();
        }
        FUN_005da4c7();
        (**(code **)(**(int **)(DAT_006f2a08 + 0x84) + 0x94))();
        goto code_r0x004f99cb;
      }
    }
    break;
  case 0x34:
    DAT_006e5458 = bVar4;
    break;
  case 0x35:
    DAT_006f6b58 = bVar4;
    FUN_004d393d();
    break;
  case 0x36:
    _DAT_006d0434 = iVar14;
    break;
  case 0x37:
    FUN_004d3e9a();
    break;
  case 0x38:
    FUN_004fb014();
    break;
  case 0x39:
    if (0 < iVar14) {
      FUN_004e3382();
    }
    break;
  case 0x3a:
    FUN_004cf136();
    FUN_004cee86();
    break;
  case 0x3b:
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc != 2) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x32;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x33;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x32;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004fa645;
    }
    *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(*(int *)(iVar11 + 4) + 0xc);
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x42c) = &PTR_FUN_006664e8;
    FUN_0046f847();
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x31c) = &PTR_FUN_006664e8;
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x6c0) = &PTR_FUN_006664e8;
    FUN_00412209();
    if (*(short *)(unaff_EBP + -0x6b8) == 0) {
      FUN_0046f847();
    }
    cVar5 = FUN_004fabe9();
    if (cVar5 == '\0') {
      FUN_005d4bbf();
      _strlen(*(char **)(unaff_EBP + -0x428));
      FUN_00412d8a();
      _strlen(s___could_not_be_opened__006cbbbc);
      FUN_00412d8a();
      goto code_r0x004f88ca;
    }
    break;
  case 0x3c:
    if (2 < (*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc) {
      iVar6 = FUN_00635f62();
      *(int *)(unaff_EBP + 0xc) = iVar6;
      if (iVar6 < 9) {
        *(undefined4 *)(unaff_EBP + 0xc) = 9;
      }
      iVar6 = *(int *)(iVar11 + 8);
      iVar14 = *(int *)(iVar11 + 4);
      *(undefined1 *)(unaff_EBP + -0x51c) = 0;
      *(undefined4 *)(unaff_EBP + 8) = 2;
      if (2 < (iVar6 - iVar14) / 0xc) {
        do {
          FUN_006358c0();
          FUN_006358c0();
          iVar6 = *(int *)(iVar11 + 8);
          iVar14 = *(int *)(iVar11 + 4);
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        } while (*(int *)(unaff_EBP + 8) < (iVar6 - iVar14) / 0xc);
      }
      *(undefined4 **)(unaff_EBP + 8) = &DAT_006f2a74 + *(int *)(unaff_EBP + 0xc);
      piVar9 = (int *)(&DAT_006f2a74)[*(int *)(unaff_EBP + 0xc)];
      if (piVar9 != (int *)0x0) {
        iVar11 = *piVar9;
        _strlen((char *)(unaff_EBP + -0x51c));
        (**(code **)(iVar11 + 0x50))();
        pvVar12 = operator_new(100);
        *(void **)(unaff_EBP + 0xc) = pvVar12;
        *(undefined1 *)(unaff_EBP + -4) = 0x34;
        if (pvVar12 == (void *)0x0) {
          piVar9 = (int *)0x0;
        }
        else {
          piVar9 = (int *)FUN_005dfb13();
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        if (piVar9 != (int *)0x0) {
          iVar11 = *piVar9;
          *(undefined1 **)(unaff_EBP + 0xc) = &stack0xfffff300;
          FUN_00436a50(4);
          uVar7 = FUN_004a946b();
          uVar7 = FUN_004a9465(uVar7);
          cVar5 = (**(code **)(iVar11 + 0xc))(uVar7);
          if (cVar5 != '\0') {
            cVar5 = (**(code **)(*piVar9 + 0x20))();
            if (cVar5 != '\0') {
              (**(code **)(*piVar9 + 0x38))();
              (**(code **)(*piVar9 + 0x24))();
            }
            iVar11 = *(int *)**(undefined4 **)(unaff_EBP + 8);
            _strlen((char *)(unaff_EBP + -0x51c));
            (**(code **)(iVar11 + 0x78))(piVar9,0,0,unaff_EBP + -0x51c);
            iVar11 = piVar9[8];
            iVar6 = piVar9[7];
            *(int *)(unaff_EBP + -0x2c) = piVar9[5];
            iVar14 = piVar9[6];
            *(int *)(unaff_EBP + -0x20) = iVar11;
            *(int *)(unaff_EBP + -0x28) = iVar14;
            *(int *)(unaff_EBP + -0x24) = iVar6;
            iVar11 = iVar11 - iVar14;
            while (6 < iVar11) {
              *(int *)(unaff_EBP + -0x7c) = iVar11;
              *(int *)(unaff_EBP + -0x80) =
                   *(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x2c);
              iVar6 = FUN_004ba904(piVar9,unaff_EBP + -0x80,0,0);
              *(int *)(unaff_EBP + 8) = iVar6;
              if (iVar6 != 0) {
                wsprintfA((LPSTR)(unaff_EBP + -0x30c),s_shrunk__02d_bmp_006cbbac,iVar11);
                puVar3 = *(undefined4 **)(unaff_EBP + 8);
                func_0x004b7e8e(unaff_EBP + -0x30c,puVar3);
                (**(code **)*puVar3)(1);
              }
              *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + -1;
              *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + -1;
              iVar11 = *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x28);
            }
            (**(code **)*piVar9)(1);
          }
        }
      }
      break;
    }
    goto LAB_004f95f4;
  case 0x3d:
    DAT_006e4a58 = (uint)(bVar4 == 0);
    break;
  case 0x3e:
    FUN_004e609e();
    FUN_004e6449();
    break;
  case 0x3f:
    DAT_006c9f92 = bVar4;
    break;
  case 0x40:
    bRam006f29f9 = bVar4;
    break;
  case 0x41:
    DAT_006e504c = bVar4;
    FUN_004d3f5c();
    break;
  case 0x42:
    iVar11 = FUN_004f6994();
    if (iVar11 == 4) {
      GetLocalTime((LPSYSTEMTIME)(unaff_EBP + -0x2c));
      wsprintfA((LPSTR)(unaff_EBP + -0x310),s_core_dump__d_02d_02d__02d_02d_02_006cbb24,
                (uint)*(ushort *)(unaff_EBP + -0x2c));
      FUN_004df65b(unaff_EBP + -0x310);
    }
    break;
  case 0x43:
    FUN_00429f5e();
    break;
  case 0x44:
    iVar6 = FUN_00410a3c();
    *(int *)(unaff_EBP + 8) = iVar6;
    if (iVar6 != 0) {
      FUN_0046f824();
      *(undefined ***)(unaff_EBP + -0x42c) = &PTR_FUN_006664e8;
      FUN_0046f847();
      if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc == 2) {
        FUN_0046f824();
        *(undefined ***)(unaff_EBP + -0xacc) = &PTR_FUN_006664e8;
        FUN_0046f847();
        FUN_0046f8e4();
      }
      FUN_0041102a();
      break;
    }
    goto LAB_004f95f4;
  case 0x45:
    DAT_006c2972 = bVar4;
    break;
  case 0x46:
    *(byte *)(DAT_006e486c[7] + 0xd4) = bVar4;
    break;
  case 0x47:
    if (DAT_006f29ed != '\0') {
      lpMaximumWorkingSetSize = (PSIZE_T)(unaff_EBP + 8);
      lpMinimumWorkingSetSize = (PSIZE_T)(unaff_EBP + 0xc);
      pvVar10 = GetCurrentProcess();
      GetProcessWorkingSetSize(pvVar10,lpMinimumWorkingSetSize,lpMaximumWorkingSetSize);
      SVar18 = 0xffffffff;
      SVar16 = 0xffffffff;
      pvVar10 = GetCurrentProcess();
      SetProcessWorkingSetSize(pvVar10,SVar16,SVar18);
      SVar16 = *(SIZE_T *)(unaff_EBP + 8);
      SVar18 = *(SIZE_T *)(unaff_EBP + 0xc);
      pvVar10 = GetCurrentProcess();
      SetProcessWorkingSetSize(pvVar10,SVar18,SVar16);
      break;
    }
code_r0x004f88ca:
    FUN_005d4bbf();
    goto LAB_004f95f4;
  case 0x48:
    FUN_004f277c();
    break;
  case 0x49:
    *(undefined1 *)(DAT_006f2a08 + 0xf8) = 1;
    (**(code **)(*DAT_006fe8bc + 0x24))();
    break;
  case 0x4a:
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc != 2) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x35;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x36;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x35;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004fa645;
    }
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x42c) = &PTR_FUN_006664e8;
    FUN_0046f847();
    FUN_004e2e34();
    *(undefined1 *)(unaff_EBP + -4) = 0x37;
    cVar5 = FUN_004e2b6b();
    if ((cVar5 != '\0') && (cVar5 = FUN_004e2d6b(), cVar5 != '\0')) {
      if (*(char *)(unaff_EBP + -0x640) != '\0') {
        FUN_004f1b96();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004e2e81();
      break;
    }
    FUN_005d4bbf();
    _strlen(*(char **)(unaff_EBP + -0x428));
    FUN_00412d8a();
    _strlen(&DAT_006cbad0);
    FUN_00412d8a();
    FUN_005d4bbf();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_004e2e81();
    goto LAB_004f95f4;
  case 0x4b:
    DAT_006d0430 = bVar4;
    break;
  case 0x4c:
    DAT_006f29f5 = bVar4;
    break;
  case 0x4d:
    DAT_006c438c = iVar14;
    break;
  case 0x4e:
    if (DAT_006e486c[7] != 0) {
      if (DAT_006f2a04 == '\0') {
        FUN_0046d9e5();
      }
      FUN_0046d9f8();
    }
    break;
  case 0x4f:
    cVar5 = FUN_00404b4f();
    goto joined_r0x004fa5c2;
  case 0x50:
    FUN_005b8680();
    *(undefined1 *)(unaff_EBP + -4) = 0x38;
    FUN_0043d7c8();
    if (*(int *)(unaff_EBP + -0x38) != *(int *)(unaff_EBP + -0x3c)) {
      FUN_005b870f();
      *(undefined1 *)(unaff_EBP + -4) = 0x39;
      FUN_004fe9e2();
      if (0x200 < (uint)(*(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x3c))) {
        _strlen((char *)0x6cba68);
        FUN_00412d8a();
      }
      iVar11 = FUN_00635845();
      if (iVar11 != 0) {
        FUN_006357d8();
        FUN_0063558d();
      }
      FUN_005d4956();
      *(undefined1 *)(unaff_EBP + -4) = 0x3a;
      FUN_004096c2();
      FUN_005d4956();
      iVar11 = *(int *)(DAT_006f2a08 + 0x48);
      *(undefined1 *)(unaff_EBP + -4) = 0x3b;
      (**(code **)(iVar11 + 0x2c))();
      *(undefined1 *)(unaff_EBP + -4) = 0x3a;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0x39;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0x38;
      FUN_005b8770();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
code_r0x004fa327:
    FUN_005b8770();
    break;
  case 0x51:
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0xbdc) = &PTR_FUN_006664e8;
    FUN_0046f847();
    cVar5 = FUN_004043bd();
    goto joined_r0x004fa5c2;
  case 0x52:
    if ((*(int *)(iVar11 + 8) - *(int *)(iVar11 + 4)) / 0xc != 3) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x3c;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x3d;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x3c;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004fa645;
    }
    *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(*(int *)(iVar11 + 4) + 0xc);
    FUN_004fab8b();
    FUN_004e99a9();
    uVar7 = FUN_004e9744();
    *(undefined4 *)(unaff_EBP + -0x30) = uVar7;
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x428) = &PTR_FUN_00666524;
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x6bc) = &PTR_FUN_00666524;
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0x318) = &PTR_FUN_00666524;
    *(undefined2 *)(unaff_EBP + -0x310) = 0;
    **(undefined1 **)(unaff_EBP + -0x314) = 0;
    FUN_0046f847();
    iVar11 = FUN_0046f990();
    if (iVar11 == 0) {
      uVar17 = 8;
    }
    else {
      iVar11 = FUN_0046f990();
      if (iVar11 == 0) {
        uVar17 = 9;
      }
      else {
        iVar11 = FUN_0046f990();
        if (iVar11 == 0) {
          uVar17 = 10;
        }
        else {
          iVar11 = FUN_0046f990();
          if (iVar11 == 0) {
            uVar17 = 0xb;
          }
          else {
            iVar11 = FUN_0046f990();
            if (iVar11 == 0) {
              uVar17 = 0xc;
            }
            else {
              iVar11 = FUN_0046f990();
              if (iVar11 == 0) {
                uVar17 = 0xd;
              }
              else {
                iVar11 = FUN_0046f990();
                if (iVar11 == 0) {
                  uVar17 = 0xe;
                }
                else {
                  iVar11 = FUN_0046f990();
                  if (iVar11 == 0) {
                    uVar17 = 0x10;
                  }
                  else {
                    iVar11 = FUN_0046f990();
                    if (iVar11 != 0) goto LAB_004f95f4;
                    uVar17 = 0xf;
                  }
                }
              }
            }
          }
        }
      }
    }
    piVar9 = *(int **)(unaff_EBP + -0x30);
    *(undefined2 *)(piVar9 + 0x167) = uVar17;
    *(short *)((int)piVar9 + 0x5b6) = (short)*(undefined4 *)(unaff_EBP + 8) + -1;
    FUN_0045f5be();
    (**(code **)(*piVar9 + 0x8c))();
    FUN_0058d98d();
    break;
  case 0x53:
    FUN_0046f824();
    *(undefined ***)(unaff_EBP + -0xcec) = &PTR_FUN_006664e8;
    FUN_0046f847();
    cVar5 = FUN_004fe37e();
joined_r0x004fa5c2:
    if (cVar5 == '\0') {
code_r0x004fa80b:
      FUN_004f6994();
    }
    break;
  case 0x54:
    if ((iVar14 < 1) || (2 < iVar14)) {
      FUN_004fee54();
      *(undefined1 *)(unaff_EBP + -4) = 0x3e;
      FUN_005b86bd();
      *(undefined1 *)(unaff_EBP + -4) = 0x3f;
      FUN_005d499c();
      *(undefined1 *)(unaff_EBP + -4) = 0x3e;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto code_r0x004fa645;
    }
    FUN_004cefa3();
    break;
  case 0x55:
    DAT_006e4f18 = (uint)bVar4;
    break;
  case 0x56:
    *(byte *)((int)DAT_006e486c + 0x5a) = bVar4;
    break;
  case 0x57:
    *(byte *)((int)DAT_006e486c + 0x5b) = bVar4;
    break;
  case 0x58:
    *(byte *)(DAT_006e486c + 0x17) = bVar4;
    break;
  case 0x59:
    *(byte *)(*(int *)(DAT_006f2a08 + 0xb0) + 0x44c) = bVar4;
    break;
  case 0x5a:
    iVar11 = FUN_004e99a9();
    if ((iVar11 == -1) || (iVar11 = FUN_004e9744(), iVar11 == 0)) goto code_r0x004fa80b;
    pvVar12 = operator_new(0x468);
    *(void **)(unaff_EBP + 8) = pvVar12;
    *(undefined1 *)(unaff_EBP + -4) = 0x40;
joined_r0x004fa7cf:
    if (pvVar12 != (void *)0x0) {
      func_0x00510867();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_004f6c41();
code_r0x004fa8b9:
    FUN_005da4c7();
    break;
  case 0x5b:
    iVar11 = FUN_004e99a9();
    if ((iVar11 != -1) && (iVar11 = FUN_004e9744(), iVar11 != 0)) {
      pvVar12 = operator_new(0x13c);
      *(void **)(unaff_EBP + 8) = pvVar12;
      *(undefined1 *)(unaff_EBP + -4) = 0x42;
      if (pvVar12 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + 8) = 0;
      }
      else {
        uVar7 = FUN_00536c99();
        *(undefined4 *)(unaff_EBP + 8) = uVar7;
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      iVar11 = FUN_004b46a0();
      *(int *)(unaff_EBP + -0x24) =
           *(int *)(iVar11 + 0x7c) +
           ((*(int *)(iVar11 + 0x84) - *(int *)(iVar11 + 0x7c)) + -300) / 2 + 300;
      (**(code **)(**(int **)(unaff_EBP + 8) + 0x60))();
      FUN_004f6c41();
      goto code_r0x004fa8b9;
    }
    goto code_r0x004fa80b;
  case 0x5c:
    *(int *)(unaff_EBP + 0xc) = iVar14;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    FUN_0042db93();
    break;
  case 0x5d:
    *(int *)(unaff_EBP + 0xc) = iVar14;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    FUN_0042df00();
    break;
  case 0x5e:
    iVar11 = FUN_004e99a9();
    if ((iVar11 != -1) && (iVar11 = FUN_004e9744(), iVar11 != 0)) {
      pvVar12 = operator_new(0x468);
      *(void **)(unaff_EBP + 8) = pvVar12;
      *(undefined1 *)(unaff_EBP + -4) = 0x41;
      goto joined_r0x004fa7cf;
    }
    goto code_r0x004fa80b;
  case 0x5f:
    *(int *)(unaff_EBP + 0xc) = iVar14;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    func_0x0042df96();
    break;
  case 0x60:
    *(int *)(unaff_EBP + 0xc) = iVar14;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    func_0x0042e02c();
    break;
  case 0x61:
    *(int *)(unaff_EBP + -0x50) = iVar14;
    *(undefined4 *)(unaff_EBP + -0x54) = 0;
    func_0x0042e0c2();
    break;
  case 0x62:
    if ((((10000 < iVar14) || (iVar14 < 0)) || (iVar11 = FUN_004e99a9(), iVar11 == -1)) ||
       (iVar11 = FUN_004e9744(), iVar11 == 0)) goto code_r0x004fa80b;
    FUN_00425769();
    FUN_0042a8e3();
    FUN_0041f38f();
    break;
  case 99:
    DAT_006f5008 = bVar4;
  }
  uVar13 = 1;
LAB_004fa95c:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_004f9602:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar13;
}

