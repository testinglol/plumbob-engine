
void FUN_0056044b(void)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  
  FUN_00634c24();
  iVar6 = *(int *)(unaff_EBP + 8) + -1;
  *(int *)(unaff_EBP + -0x10) = iVar6;
  if ((iVar6 < 0) || (9 < iVar6)) {
    iVar7 = 0;
  }
  else {
    iVar7 = extraout_ECX[*(int *)(unaff_EBP + 8) + 0x3c] + 0x194;
  }
  if (iVar7 != 0) {
    piVar3 = (int *)FUN_00425e2d();
    piVar5 = (int *)*piVar3;
    if (piVar5 != (int *)piVar3[1]) {
      do {
        if ((*(int *)(*piVar5 + 0x110) == *(int *)(unaff_EBP + 8)) &&
           (uVar4 = DAT_006f5b58, uVar9 = DAT_006f5b5c, *(int *)(*piVar5 + 0x13c) != 0))
        goto LAB_005605be;
        piVar5 = piVar5 + 1;
      } while (piVar5 != (int *)piVar3[1]);
      iVar6 = *(int *)(unaff_EBP + -0x10);
    }
    if (*(int *)(iVar7 + 0x24) == -1) {
      if (*(int *)(iVar7 + 0x18) == 0) {
        FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
        FUN_004f6994(DAT_006f5b74,DAT_006f5b70,0,0);
        FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
        goto LAB_00560752;
      }
      iVar7 = FUN_004f6994(DAT_006f5b1c,DAT_006f5b18,2,0);
      if (iVar7 == 4) {
        FUN_0057a7f7(s_UI_Nhood_bdoze_demolish_006cda1c,0xfffffffc);
        iVar7 = extraout_ECX[0x1a];
        uVar4 = FUN_005e74ca(3);
        FUN_005dde6d(uVar4);
        uVar1 = FUN_004e2b07(*(undefined4 *)(unaff_EBP + 8),1);
        *(undefined1 *)(unaff_EBP + 0xb) = uVar1;
        FUN_005dde6d(iVar7);
        FUN_005db1e2();
        uVar4 = DAT_006f5b44;
        uVar9 = DAT_006f5b40;
        if (*(char *)(unaff_EBP + 0xb) == '\0') {
LAB_005605be:
          FUN_004f6994(uVar4,uVar9,0,0);
          goto LAB_00560752;
        }
      }
    }
    else {
      FUN_005d48d9();
      piVar5 = DAT_006fe8bc;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      piVar5 = (int *)(**(code **)(*piVar5 + 4))();
      (**(code **)(*piVar5 + 0x7c))
                (*(int *)(iVar7 + 0x34),*(int *)(iVar7 + 0x34) >> 0x1f,unaff_EBP + -0x20);
      wsprintfA((LPSTR)(unaff_EBP + -0x124),DAT_006f5b24,*(undefined4 *)(iVar7 + 0x28),
                *(undefined4 *)(unaff_EBP + -0x20));
      iVar6 = FUN_004f6994(unaff_EBP + -0x124,DAT_006f5b20,2,0);
      if (iVar6 == 4) {
        *(undefined1 *)(unaff_EBP + -0x14) = 0;
        if ((*(int *)(iVar7 + 0x18) == 0) ||
           (iVar6 = FUN_004f6994(DAT_006f5b1c,DAT_006f5b18,2,0), iVar6 != 4)) {
          pcVar8 = s_UI_Nhood_bdoze_evict_006cdd48;
        }
        else {
          *(undefined1 *)(unaff_EBP + -0x14) = 1;
          pcVar8 = s_UI_Nhood_bdoze_demolish_006cda1c;
        }
        FUN_0057a7f7(pcVar8,0xfffffffc);
        iVar6 = extraout_ECX[0x1a];
        uVar4 = FUN_005e74ca(3);
        FUN_005dde6d(uVar4);
        cVar2 = FUN_004e2b07(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14));
        FUN_005dde6d(iVar6);
        FUN_005db1e2();
        if (cVar2 == '\0') {
          FUN_004f6994(DAT_006f5b44,DAT_006f5b40,0,0);
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar6 = *(int *)(unaff_EBP + -0x10);
    }
    if ((-1 < iVar6) && (iVar6 < 10)) {
      FUN_0054ebd3();
    }
    piVar5 = extraout_ECX + 0x3d;
    iVar6 = 10;
    do {
      piVar3 = (int *)*piVar5;
      if (((piVar3 != (int *)0xfffffe6c) && (piVar3[0x6a] != 0)) &&
         (*(short *)(*(int *)(DAT_006e486c + 0x24) + 0x12e) == 0)) {
        (**(code **)(*piVar3 + 0x160))(1);
      }
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    (**(code **)(*extraout_ECX + 0x168))();
  }
LAB_00560752:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

