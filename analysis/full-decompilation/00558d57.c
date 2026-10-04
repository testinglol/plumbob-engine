
void FUN_00558d57(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  iVar2 = FUN_0055c216(*(undefined4 *)(unaff_EBP + 8));
  if (iVar2 == 0) goto LAB_00559196;
  iVar3 = FUN_0042ba25(*(undefined4 *)(unaff_EBP + 8));
  if (iVar3 == 2) {
    uVar10 = DAT_006f57b8[3];
  }
  else {
    uVar10 = *DAT_006f57b8;
  }
  wsprintfA((LPSTR)(unaff_EBP + -0x334),DAT_006f59a4,uVar10);
  FUN_005d4956(DAT_006f59a0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4956(unaff_EBP + -0x334);
  iVar3 = *DAT_006f2a08;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar3 = (**(code **)(iVar3 + 0x3c))(unaff_EBP + -0x24,unaff_EBP + -0x30,2,&DAT_006f57b8,0);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x18) = iVar3;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  if (((iVar3 == -1) ||
      ((iVar3 == 0 && (iVar4 = FUN_0042ba25(*(undefined4 *)(unaff_EBP + 8)), iVar4 == 1)))) ||
     ((iVar3 == 1 && (iVar3 = FUN_0042ba25(*(undefined4 *)(unaff_EBP + 8)), iVar3 == 2))))
  goto LAB_00559196;
  piVar5 = (int *)FUN_00425e2d();
  piVar6 = (int *)*piVar5;
  piVar7 = extraout_ECX;
  if (piVar6 != (int *)piVar5[1]) {
    do {
      if ((*(int *)(*piVar6 + 0x110) == *(int *)(unaff_EBP + 8)) &&
         (uVar10 = DAT_006f5938, uVar9 = DAT_006f593c, *(int *)(*piVar6 + 0x13c) != 0))
      goto LAB_00558f51;
      piVar6 = piVar6 + 1;
    } while (piVar6 != (int *)piVar5[1]);
    piVar7 = *(int **)(unaff_EBP + -0x14);
  }
  if (*(int *)(iVar2 + 0x24) == -1) {
    if (*(int *)(iVar2 + 0x18) == 0) {
      iVar2 = *(int *)(unaff_EBP + -0x18);
      if (iVar2 != 0) goto LAB_00558f6d;
LAB_00558eaf:
      uVar10 = 1;
    }
    else {
      iVar2 = FUN_004f6994(DAT_006f591c,DAT_006f5918,2,0);
      if (iVar2 != 4) goto LAB_00559196;
      FUN_0057a7f7(s_UI_Nhood_bdoze_demolish_006cda1c,0xfffffffc);
      iVar2 = piVar7[0x1a];
      uVar10 = FUN_005e74ca(3);
      FUN_005dde6d(uVar10);
      cVar1 = FUN_004e2b07(*(undefined4 *)(unaff_EBP + 8),1);
      FUN_005dde6d(iVar2);
      FUN_005db1e2();
      uVar10 = DAT_006f5924;
      uVar9 = DAT_006f5920;
      if (cVar1 == '\0') {
LAB_00558f51:
        FUN_004f6994(uVar10,uVar9,0,0);
        goto LAB_00559196;
      }
      iVar2 = *(int *)(unaff_EBP + -0x18);
      if (iVar2 == 0) goto LAB_00558eaf;
LAB_00558f6d:
      if (iVar2 != 1) goto LAB_005590f8;
      uVar10 = 2;
    }
    FUN_0042ba55(*(undefined4 *)(unaff_EBP + 8),uVar10);
  }
  else {
    FUN_005d48d9();
    piVar6 = DAT_006fe8bc;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    piVar6 = (int *)(**(code **)(*piVar6 + 4))();
    (**(code **)(*piVar6 + 0x7c))
              (*(int *)(iVar2 + 0x34),*(int *)(iVar2 + 0x34) >> 0x1f,unaff_EBP + -0x24);
    wsprintfA((LPSTR)(unaff_EBP + -0x134),DAT_006f5914,*(undefined4 *)(iVar2 + 0x28),
              *(undefined4 *)(unaff_EBP + -0x24));
    iVar3 = FUN_004f6994(unaff_EBP + -0x134,DAT_006f5910,2,0);
    if (iVar3 == 4) {
      *(undefined1 *)(unaff_EBP + -0x10) = 0;
      if (*(int *)(iVar2 + 0x18) == 0) {
        pcVar8 = s_UI_Nhood_bdoze_evict_006cdd48;
LAB_00559047:
        FUN_0057a7f7(pcVar8,0xfffffffc);
        piVar7 = *(int **)(unaff_EBP + -0x14);
        iVar2 = piVar7[0x1a];
        uVar10 = FUN_005e74ca(3);
        FUN_005dde6d(uVar10);
        cVar1 = FUN_004e2b07(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x10));
        FUN_005dde6d(iVar2);
        FUN_005db1e2();
        if (cVar1 != '\0') {
          if (*(int *)(unaff_EBP + -0x18) == 0) {
            uVar10 = 1;
          }
          else {
            if (*(int *)(unaff_EBP + -0x18) != 1) goto LAB_005590ec;
            uVar10 = 2;
          }
          FUN_0042ba55(*(undefined4 *)(unaff_EBP + 8),uVar10);
          goto LAB_005590ec;
        }
        FUN_004f6994(DAT_006f5924,DAT_006f5920,0,0);
      }
      else {
        iVar2 = FUN_004f6994(DAT_006f591c,DAT_006f5918,2,0);
        if (iVar2 == 4) {
          *(undefined1 *)(unaff_EBP + -0x10) = 1;
          pcVar8 = s_UI_Nhood_bdoze_demolish_006cda1c;
          goto LAB_00559047;
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      goto LAB_00559196;
    }
    piVar7 = *(int **)(unaff_EBP + -0x14);
LAB_005590ec:
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
LAB_005590f8:
  iVar2 = piVar7[0x52];
  iVar3 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + -0x10) = iVar3;
  if (iVar3 != iVar2) {
    do {
      if (*(int *)(*(int *)(iVar3 + 0x14) + 0x1d8) == *(int *)(unaff_EBP + 8)) {
        FUN_0054ebd3();
      }
      FUN_0041674f();
      iVar3 = *(int *)(unaff_EBP + -0x10);
    } while (iVar3 != piVar7[0x52]);
  }
  iVar2 = piVar7[0x52];
  iVar3 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + 8) = iVar3;
  if (iVar3 != iVar2) {
    do {
      piVar6 = *(int **)(iVar3 + 0x14);
      if (((piVar6 != (int *)0xfffffe6c) && (piVar6[0x6a] != 0)) &&
         (*(short *)(*(int *)(DAT_006e486c + 0x24) + 0x12e) == 0)) {
        (**(code **)(*piVar6 + 0x160))(1);
      }
      FUN_0041674f();
      iVar3 = *(int *)(unaff_EBP + 8);
    } while (iVar3 != piVar7[0x52]);
  }
  FUN_0055d388();
  (**(code **)(*piVar7 + 0x168))();
LAB_00559196:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

