
void FUN_00552c63(void)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int *extraout_ECX;
  int unaff_EBP;
  char *pcVar8;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 8) + -0x5a;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(int *)(unaff_EBP + -0x18) = iVar3;
  if ((iVar3 < 0) || (8 < iVar3)) {
    iVar3 = 0;
  }
  else {
    iVar3 = extraout_ECX[*(int *)(unaff_EBP + 8) + -7] + 0x194;
  }
  if (iVar3 == 0) goto LAB_00552f98;
  piVar4 = (int *)FUN_00425e2d();
  piVar6 = (int *)*piVar4;
  piVar4 = (int *)piVar4[1];
  *(int **)(unaff_EBP + -0x10) = piVar4;
  if (piVar6 != piVar4) {
    do {
      if ((*(int *)(*piVar6 + 0x110) == *(int *)(unaff_EBP + 8)) && (*(int *)(*piVar6 + 0x13c) != 0)
         ) {
        (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))(&DAT_006f56e0,&DAT_006f56ec,0,0);
        goto LAB_00552f98;
      }
      piVar6 = piVar6 + 1;
    } while (piVar6 != *(int **)(unaff_EBP + -0x10));
  }
  if (*(int *)(iVar3 + 0x24) == -1) {
    if (*(int *)(iVar3 + 0x18) == 0) {
      FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
      (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))(&DAT_006f553c,&DAT_006f5530,0,0);
      FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
      goto LAB_00552f98;
    }
    iVar3 = FUN_004f6994(DAT_006f562c,DAT_006f5620,2,0);
    piVar6 = extraout_ECX;
    if (iVar3 == 4) {
      FUN_0057a7f7(s_UI_Nhood_bdoze_demolish_006cda1c,0xfffffffc);
      iVar3 = extraout_ECX[0x1a];
      uVar5 = FUN_005e74ca(3);
      FUN_005dde6d(uVar5);
      uVar2 = FUN_004e2b07(*(undefined4 *)(unaff_EBP + 8),1);
      *(undefined1 *)(unaff_EBP + 0xb) = uVar2;
      FUN_005dde6d(iVar3);
      FUN_005db1e2();
      if (*(char *)(unaff_EBP + 0xb) == '\0') {
        FUN_004f6994(DAT_006f56a4,DAT_006f5698,0,0);
        goto LAB_00552f98;
      }
    }
  }
  else {
    FUN_005d48d9();
    piVar6 = DAT_006fe8bc;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar6 = (int *)(**(code **)(*piVar6 + 4))();
    (**(code **)(*piVar6 + 0x7c))
              (*(int *)(iVar3 + 0x34),*(int *)(iVar3 + 0x34) >> 0x1f,unaff_EBP + -0x24);
    wsprintfA((LPSTR)(unaff_EBP + -0x134),DAT_006f5644,*(undefined4 *)(iVar3 + 0x28),
              *(undefined4 *)(unaff_EBP + -0x24));
    FUN_005d4956(unaff_EBP + -0x134);
    piVar6 = (int *)(DAT_006f2a08 + 0x48);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar7 = (**(code **)(*piVar6 + 0x2c))(unaff_EBP + -0x30,&DAT_006f5638,2,0);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    if (iVar7 == 4) {
      iVar3 = *(int *)(iVar3 + 0x18);
      *(undefined1 *)(unaff_EBP + -0x10) = 0;
      if (iVar3 == 0) {
LAB_00552eaf:
        pcVar8 = s_UI_Nhood_bdoze_evict_006cdd48;
      }
      else {
        iVar3 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))(&DAT_006f562c,&DAT_006f5620,2,0)
        ;
        if (iVar3 != 4) goto LAB_00552eaf;
        *(undefined1 *)(unaff_EBP + -0x10) = 1;
        pcVar8 = s_UI_Nhood_bdoze_demolish_006cda1c;
      }
      FUN_0057a7f7(pcVar8,0xfffffffc);
      piVar6 = *(int **)(unaff_EBP + -0x14);
      iVar3 = piVar6[0x1a];
      uVar5 = FUN_005e74ca(3);
      FUN_005dde6d(uVar5);
      uVar2 = FUN_004e2b07(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined1 *)(unaff_EBP + 0xb) = uVar2;
      FUN_005dde6d(iVar3);
      FUN_005db1e2();
      if (*(char *)(unaff_EBP + 0xb) == '\0') {
        (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))(&DAT_006f56a4,&DAT_006f5698,0,0);
      }
    }
    else {
      piVar6 = *(int **)(unaff_EBP + -0x14);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  if ((-1 < *(int *)(unaff_EBP + -0x18)) && (*(int *)(unaff_EBP + -0x18) < 9)) {
    FUN_0054ebd3();
  }
  piVar4 = piVar6 + 0x53;
  *(undefined4 *)(unaff_EBP + 8) = 9;
  do {
    piVar1 = (int *)*piVar4;
    if (((piVar1 != (int *)0xfffffe6c) && (piVar1[0x6a] != 0)) &&
       (*(short *)(*(int *)(DAT_006e486c + 0x24) + 0x12e) == 0)) {
      (**(code **)(*piVar1 + 0x160))(1);
    }
    piVar4 = piVar4 + 1;
    piVar1 = (int *)(unaff_EBP + 8);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  (**(code **)(*piVar6 + 0x168))();
LAB_00552f98:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

