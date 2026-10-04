
undefined1 FUN_005f8909(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  void *pvVar6;
  int iVar7;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar8;
  
  FUN_00634c24();
  piVar1 = DAT_006fed70;
  piVar8 = (int *)0x0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  cVar3 = (**(code **)(*piVar1 + 8))();
  if (cVar3 == '\0') {
    uVar4 = 1;
    goto LAB_005f8b70;
  }
  piVar1 = extraout_ECX + 2;
  if (extraout_ECX[3] == *piVar1) {
LAB_005f8b6e:
    uVar4 = 0;
    goto LAB_005f8b70;
  }
  FUN_005d4c15(unaff_EBP + -0x30,4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4d82();
  uVar5 = FUN_005d4c15(unaff_EBP + -0x3c,2);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar4 = FUN_00460748(uVar5,&DAT_006d8130);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + -0xd) = uVar4;
  FUN_005b8770();
  if (*(char *)(unaff_EBP + -0xd) == '\0') {
    cVar3 = FUN_00460748(unaff_EBP + -0x30,&DAT_006d8128);
    if (cVar3 == '\0') {
      uVar5 = FUN_005d4be4(unaff_EBP + -0x3c,3);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      uVar4 = FUN_00460748(uVar5,&PTR_LAB_006d8124);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(undefined1 *)(unaff_EBP + -0xd) = uVar4;
      FUN_005b8770();
      if (*(char *)(unaff_EBP + -0xd) == '\0') {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        goto LAB_005f8b6e;
      }
      pvVar6 = operator_new(0x108c);
      *(void **)(unaff_EBP + -0x14) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      if (pvVar6 != (void *)0x0) {
        piVar8 = (int *)FUN_005f8b7f();
      }
    }
    else {
      pvVar6 = operator_new(0x48);
      *(void **)(unaff_EBP + -0x14) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (pvVar6 != (void *)0x0) {
        piVar8 = (int *)FUN_005fba41();
      }
    }
    iVar7 = *piVar1;
    iVar2 = *piVar8;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(int **)(unaff_EBP + -0x14) = piVar8;
    cVar3 = (**(code **)(iVar2 + 4))(iVar7);
    if (cVar3 == '\0') goto LAB_005f8a6c;
    piVar8 = *(int **)(unaff_EBP + -0x14);
LAB_005f8a7b:
    iVar7 = (**(code **)(*piVar8 + 0x18))();
    extraout_ECX[0x29] = iVar7;
    piVar8 = (int *)(**(code **)(*piVar8 + 0x1c))();
    extraout_ECX[0x2a] = *piVar8;
    extraout_ECX[0x2b] = piVar8[1];
    extraout_ECX[0x2c] = piVar8[2];
    extraout_ECX[0x2d] = piVar8[3];
    *(short *)(extraout_ECX + 0x2e) = (short)piVar8[4];
    cVar3 = (**(code **)(*extraout_ECX + 0xe8))(0);
    if ((cVar3 == '\0') ||
       (iVar7 = (**(code **)(*(int *)extraout_ECX[0x20] + 0x2c))
                          ((int *)extraout_ECX[0x20],0,extraout_ECX[0x29],unaff_EBP + -0x18,
                           unaff_EBP + -0x24,unaff_EBP + -0x1c,unaff_EBP + -0x20,0), iVar7 != 0)) {
      piVar8 = *(int **)(unaff_EBP + -0x14);
LAB_005f8b1e:
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 8))();
        FUN_006321f0(piVar8);
      }
      (**(code **)(*extraout_ECX + 0xf0))();
      goto LAB_005f8b3a;
    }
    piVar8 = *(int **)(unaff_EBP + -0x14);
    (**(code **)(*piVar8 + 0x10))(*(undefined4 *)(unaff_EBP + -0x18),extraout_ECX[0x29]);
    FUN_005f7a3c(*(undefined4 *)(unaff_EBP + -0x18),extraout_ECX[0x29]);
    iVar7 = (**(code **)(*(int *)extraout_ECX[0x20] + 0x4c))
                      ((int *)extraout_ECX[0x20],*(undefined4 *)(unaff_EBP + -0x18),
                       *(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x1c),
                       *(undefined4 *)(unaff_EBP + -0x20));
    if (iVar7 != 0) goto LAB_005f8b1e;
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 8))();
      FUN_006321f0(piVar8);
    }
    uVar4 = 1;
  }
  else {
    pvVar6 = operator_new(0xf6c);
    *(void **)(unaff_EBP + -0x14) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar6 != (void *)0x0) {
      piVar8 = (int *)FUN_005fbcf8();
    }
    iVar7 = *piVar1;
    iVar2 = *piVar8;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(int **)(unaff_EBP + -0x14) = piVar8;
    cVar3 = (**(code **)(iVar2 + 4))(iVar7);
    if (cVar3 != '\0') goto LAB_005f8a7b;
LAB_005f8a6c:
    FUN_006321f0(piVar8);
LAB_005f8b3a:
    uVar4 = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_005f8b70:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

