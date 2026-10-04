
undefined1 FUN_0050347f(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  size_t sVar8;
  int iVar9;
  int *piVar10;
  int *extraout_ECX;
  int iVar11;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 != '\0') {
    uVar2 = FUN_005dbf32();
    goto LAB_00503986;
  }
  cVar1 = FUN_005dbf32();
  uVar2 = 0;
  if (cVar1 == '\0') goto LAB_00503986;
  FUN_004e609e();
  uVar2 = FUN_004e63de();
  *(undefined1 *)(extraout_ECX + 0x47) = uVar2;
  FUN_005a5631(0x455,extraout_ECX + 0x43,4);
  FUN_005a5631(0x456,extraout_ECX + 0x46,4);
  FUN_005a5631(0x1332,extraout_ECX + 0x48,4);
  FUN_005a5631(0x1333,extraout_ECX + 0x49,4);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xb0) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_0041532c(9,unaff_EBP + -0xb0,0);
  cVar1 = FUN_004fff98(0x8c,uVar3);
  if (cVar1 != '\0') {
    FUN_00471655(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    do {
      iVar9 = *(int *)(unaff_EBP + -0x14);
      if (iVar9 == 3) {
        puVar6 = operator_new(0x194);
        *(undefined4 **)(unaff_EBP + -0x10) = puVar6;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (puVar6 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          FUN_005e372a();
          *puVar6 = &PTR_FUN_0066a4d4;
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        extraout_ECX[0x3a] = (int)puVar6;
      }
      else {
        pvVar4 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x10) = pvVar4;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        if (pvVar4 == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_005e372a();
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        extraout_ECX[iVar9 + 0x37] = iVar5;
      }
      piVar10 = extraout_ECX + *(int *)(unaff_EBP + -0x14) + 0x37;
      if (extraout_ECX[*(int *)(unaff_EBP + -0x14) + 0x37] != 0) {
        *(undefined4 *)(extraout_ECX[*(int *)(unaff_EBP + -0x14) + 0x37] + 0xf4) = 1;
        *(undefined4 *)(*piVar10 + 0xf8) = 1;
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        FUN_005a5631(*(undefined4 *)(&DAT_0066a310 + *(int *)(unaff_EBP + -0x14) * 4),
                     unaff_EBP + -0x10,4);
        if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
        }
        (**(code **)(*(int *)*piVar10 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
        *(undefined1 *)(*piVar10 + 0x16b) = 1;
        (**(code **)(*extraout_ECX + 0x20))(*piVar10);
        FUN_0046fc87(unaff_EBP + -0x2c,0);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        uVar3 = FUN_0046fc7a();
        puVar6 = (undefined4 *)FUN_00500249(unaff_EBP + -0x44,uVar3);
        FUN_004cb21d(*puVar6,puVar6[1]);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
        FUN_0046fc87(unaff_EBP + -0x1c,0);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        uVar3 = FUN_0046fc7a();
        uVar3 = FUN_005d4956(uVar3);
        *(undefined1 *)(unaff_EBP + -4) = 6;
        FUN_005dd9c8(uVar3);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
      }
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    } while (*(int *)(unaff_EBP + -0x14) < 8);
    if (extraout_ECX[0x3b] != 0) {
      *(undefined4 *)(extraout_ECX[0x3b] + 0xf8) = 0;
    }
    if (extraout_ECX[0x3a] != 0) {
      FUN_005e4071(DAT_006f2a98);
      iVar9 = extraout_ECX[0x3a];
      iVar11 = *(int *)(iVar9 + 0x88) - *(int *)(iVar9 + 0x80);
      iVar5 = *DAT_006f2a98;
      *(int *)(unaff_EBP + -0x34) = *(int *)(iVar9 + 0x84) - *(int *)(iVar9 + 0x7c);
      iVar5 = (**(code **)(iVar5 + 0x58))();
      iVar9 = extraout_ECX[0x3a];
      *(undefined4 *)(iVar9 + 0x160) = 1;
      *(int *)(iVar9 + 0x120) = iVar11 - iVar5;
      uVar3 = *(undefined4 *)(unaff_EBP + -0x34);
      *(undefined4 *)(iVar9 + 0x11c) = 0;
      *(undefined4 *)(iVar9 + 0x124) = uVar3;
      *(int *)(iVar9 + 0x128) = iVar11;
      *(undefined4 *)(iVar9 + 0x164) = 1;
    }
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    pcVar7 = (char *)FUN_0046fc7a();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    sVar8 = _strlen(pcVar7);
    pvVar4 = operator_new(sVar8 + 1);
    extraout_ECX[0x41] = (int)pvVar4;
    if (pvVar4 != (void *)0x0) {
      FUN_006358b0(pvVar4,pcVar7);
    }
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    pcVar7 = (char *)FUN_0046fc7a();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    sVar8 = _strlen(pcVar7);
    pvVar4 = operator_new(sVar8 + 1);
    extraout_ECX[0x42] = (int)pvVar4;
    if (pvVar4 != (void *)0x0) {
      FUN_006358b0(pvVar4,pcVar7);
    }
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    pcVar7 = (char *)FUN_0046fc7a();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    sVar8 = _strlen(pcVar7);
    pvVar4 = operator_new(sVar8 + 1);
    extraout_ECX[0x44] = (int)pvVar4;
    if (pvVar4 != (void *)0x0) {
      FUN_006358b0(pvVar4,pcVar7);
    }
    FUN_0046fc87(unaff_EBP + -0x1c,0);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    pcVar7 = (char *)FUN_0046fc7a();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    sVar8 = _strlen(pcVar7);
    pvVar4 = operator_new(sVar8 + 1);
    extraout_ECX[0x45] = (int)pvVar4;
    if (pvVar4 != (void *)0x0) {
      FUN_006358b0(pvVar4,pcVar7);
    }
    pvVar4 = operator_new(0x84);
    *(void **)(unaff_EBP + -0x10) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    if (pvVar4 == (void *)0x0) {
      iVar9 = 0;
    }
    else {
      iVar9 = FUN_00510166(extraout_ECX[0x41],extraout_ECX[0x42],0,0,0,0,0,0,0);
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    extraout_ECX[0x40] = iVar9;
    if (iVar9 != 0) {
      FUN_00510489(0,extraout_ECX[0x43]);
      *(undefined1 *)(extraout_ECX[0x40] + 0x80) = 0;
      FUN_00503993(s_camera_006cc3cc);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
  }
  pvVar4 = operator_new(0x118);
  *(void **)(unaff_EBP + -0x10) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  if (pvVar4 == (void *)0x0) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = (int *)FUN_0050f7c5(extraout_ECX[0x35]);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x3f] = (int)piVar10;
  if (piVar10 == (int *)0x0) {
LAB_00503930:
    uVar2 = 0;
  }
  else {
    cVar1 = (**(code **)(*piVar10 + 0xc))();
    if (cVar1 == '\0') goto LAB_00503930;
    (**(code **)(*(int *)extraout_ECX[0x3f] + 0x98))();
    (**(code **)(**(int **)(DAT_006f2a08 + 0x84) + 0x20))(extraout_ECX[0x3f]);
    FUN_005043ef((char)extraout_ECX[0x47]);
    uVar2 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
LAB_00503986:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

