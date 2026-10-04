
void FUN_004fb5e5(void)

{
  undefined4 uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  void *pvVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  FUN_00634c24();
  uVar4 = DAT_006fe8cc;
  *(undefined4 *)(unaff_EBP + -0x50) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x44) = uVar4;
  uVar4 = FUN_005ef4c8();
  *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
  FUN_004ff6fa(0x67727068,s_Initializing_graphics_006cc020);
  piVar5 = (int *)(**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
  piVar5 = (int *)(**(code **)(*piVar5 + 0x144))();
  piVar6 = (int *)(**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
  (**(code **)(*piVar6 + 0x148))();
  uVar2 = (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x18))();
  *(undefined1 *)(unaff_EBP + -0x20) = uVar2;
  iVar7 = (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
  if (*(char *)(iVar7 + 0x75) == '\0') {
    piVar5 = (int *)(**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
    iVar7 = (**(code **)(*piVar5 + 0x138))();
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar7 + 4);
    piVar5 = (int *)(**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
    iVar7 = (**(code **)(*piVar5 + 0x13c))();
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar7 + 0x170);
    piVar5 = (int *)(**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
    iVar7 = (**(code **)(*piVar5 + 0x13c))();
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar7 + 0x174);
    uVar4 = (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))();
  }
  else {
    iVar7 = (**(code **)(*piVar5 + 0x50))();
    *(int *)(unaff_EBP + -0x10) = iVar7;
    if (iVar7 == 0) {
      *(int *)(unaff_EBP + -0x10) = piVar5[1];
    }
    (**(code **)(*DAT_006fe8bc + 0x18))();
    piVar5 = (int *)FUN_004b46a0();
    iVar7 = (**(code **)(*piVar5 + 0x184))();
    if (iVar7 == 0) {
      (**(code **)(*piVar5 + 0x174))(1,0);
    }
    iVar7 = (**(code **)(*piVar5 + 0x184))();
    piVar6 = *(int **)(*(int *)(iVar7 + 0x48) + 4);
    _memset((void *)(unaff_EBP + -0xcc),0,0x6c);
    *(undefined4 *)(unaff_EBP + -0xcc) = 0x6c;
    (**(code **)(*piVar6 + 0x58))(piVar6,unaff_EBP + -0xcc);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0xc0);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0xc4);
    uVar4 = (**(code **)(*piVar5 + 0x184))();
  }
  *(undefined4 *)(DAT_006e486c + 0x3c) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x60) = DAT_006772a8;
  *(undefined4 *)(unaff_EBP + -0x5c) = DAT_006772ac;
  *(undefined4 *)(unaff_EBP + -0x58) = DAT_006772b0;
  *(int *)(unaff_EBP + -0x1c) = unaff_EBP + -0x60;
  *(undefined4 *)(unaff_EBP + -0x54) = DAT_006772b4;
  pvVar8 = (void *)FUN_005ef4ce();
  iVar7 = _memcmp(pvVar8,&DAT_006f2a14,0x10);
  if (iVar7 != 0) {
    uVar4 = FUN_005ef4ce();
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
  }
  piVar5 = *(int **)(DAT_006e486c + 0x3c);
  if (*(char *)(unaff_EBP + -0x20) != '\0') {
    _memset((void *)(unaff_EBP + -0x138),0,0x6c);
    *(undefined4 *)(unaff_EBP + -0x138) = 0x6c;
    (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x58))
              (*(int **)(unaff_EBP + -0x10),unaff_EBP + -0x138);
    if ((*(byte *)(unaff_EBP + -0xcf) & 8) != 0) {
      FUN_005bc69b(s_Warning__Fullscreen_primary_surf_006cbfdc);
    }
  }
  pvVar8 = operator_new(0xc9c);
  *(void **)(unaff_EBP + -0x48) = pvVar8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar8 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005c79d2();
  }
  iVar7 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar7 + 0x2c) = uVar4;
  pvVar8 = operator_new(0x54);
  *(void **)(unaff_EBP + -0x48) = pvVar8;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar8 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005cf9c8();
  }
  iVar7 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uVar1 = *(undefined4 *)(unaff_EBP + -0x1c);
  *(undefined4 *)(iVar7 + 0x30) = uVar4;
  FUN_005c8078(*(undefined4 *)(unaff_EBP + -0x44),*(undefined4 *)(unaff_EBP + -0x4c),
               *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(piVar5[0x12] + 4),0,
               *(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14),0x10,
               *(undefined4 *)(unaff_EBP + -0x20),DAT_006c9f90 == '\0',uVar1,1,4);
  iVar7 = *(int *)(*(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x48) + 8);
  if (iVar7 != 0) {
    FUN_005cfaaf(*(undefined4 *)(DAT_006e486c + 0x2c),iVar7);
  }
  (**(code **)(*piVar5 + 0x1c))();
  cVar3 = (**(code **)(*piVar5 + 0x20))(1);
  if (cVar3 != '\0') {
    (**(code **)(*piVar5 + 0x38))(0,0);
    (**(code **)(*piVar5 + 0x24))(1);
  }
  piVar5 = (int *)FUN_00603b99();
  _memset((void *)(unaff_EBP + -0x40),0,0x20);
  *(undefined4 *)(unaff_EBP + -0x40) = 0x20;
  (**(code **)(*piVar5 + 0x54))(piVar5,unaff_EBP + -0x40);
  if (*(int *)(unaff_EBP + -0x34) == 0x10) {
    if (*(int *)(unaff_EBP + -0x30) == 0x7c00) {
      if ((*(int *)(unaff_EBP + -0x2c) == 0x3e0) && (*(int *)(unaff_EBP + -0x28) == 0x1f)) {
        *(undefined4 *)(DAT_006e486c + 0x34) = 1;
        goto LAB_004fb9d5;
      }
    }
    else if (*(int *)(unaff_EBP + -0x30) == 0xf800) {
      if (*(int *)(unaff_EBP + -0x2c) == 0x7e0) {
        if (*(int *)(unaff_EBP + -0x28) == 0x1f) {
          *(undefined4 *)(DAT_006e486c + 0x34) = 2;
          goto LAB_004fb9d5;
        }
      }
      else if ((*(int *)(unaff_EBP + -0x2c) == 0x7c0) && (*(int *)(unaff_EBP + -0x28) == 0x3f)) {
        *(undefined4 *)(DAT_006e486c + 0x34) = 3;
        goto LAB_004fb9d5;
      }
    }
    else if (((*(int *)(unaff_EBP + -0x30) == 0xfc00) && (*(int *)(unaff_EBP + -0x2c) == 0x3e0)) &&
            (*(int *)(unaff_EBP + -0x28) == 0x1f)) {
      *(undefined4 *)(DAT_006e486c + 0x34) = 4;
      goto LAB_004fb9d5;
    }
    *(undefined4 *)(DAT_006e486c + 0x34) = 0;
  }
LAB_004fb9d5:
  piVar5 = (int *)FUN_005caf1a();
  (**(code **)(*piVar5 + 0x54))(piVar5,unaff_EBP + -0x40);
  puVar9 = (undefined4 *)(unaff_EBP + -0x40);
  puVar10 = (undefined4 *)(*(int *)(DAT_006e486c + 0x4c) + 0x2d0);
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  FUN_0049a42a();
  uVar4 = FUN_005cadef();
  *(undefined4 *)(*(int *)(unaff_EBP + -0x50) + 0x11c) = uVar4;
  piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  piVar5 = (int *)(**(code **)(*piVar5 + 8))();
  uVar4 = (**(code **)(*piVar5 + 0x1b8))();
  *(undefined4 *)(DAT_006e486c + 0x38) = uVar4;
  uVar4 = *(undefined4 *)(DAT_006e486c + 0x30);
  (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x24))(uVar4);
  FUN_005ecd57(uVar4);
  uVar4 = *(undefined4 *)(unaff_EBP + -0x18);
  iVar7 = *(int *)(DAT_006e486c + 0x4c);
  *(undefined4 *)(iVar7 + 0x2a4) = 0;
  *(undefined4 *)(iVar7 + 0x2a8) = 0;
  *(undefined4 *)(iVar7 + 0x2ac) = 0;
  *(undefined4 *)(iVar7 + 0x2b0) = 0;
  iVar7 = *(int *)(DAT_006e486c + 0x4c);
  *(undefined4 *)(iVar7 + 700) = uVar4;
  *(undefined4 *)(iVar7 + 0x2c0) = *(undefined4 *)(unaff_EBP + -0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(iVar7 + 0x2b4) = 0;
  *(undefined4 *)(iVar7 + 0x2b8) = 0;
  return;
}

