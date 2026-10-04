
void FUN_00558a29(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *extraout_ECX;
  int unaff_EBP;
  char *pcVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  iVar2 = FUN_0055c216(*(undefined4 *)(unaff_EBP + 8));
  if (iVar2 == 0) goto LAB_00558d46;
  puVar3 = (undefined4 *)FUN_00425e2d();
  for (piVar5 = (int *)*puVar3; piVar5 != (int *)puVar3[1]; piVar5 = piVar5 + 1) {
    if ((*(int *)(*piVar5 + 0x110) == *(int *)(unaff_EBP + 8)) &&
       (uVar4 = DAT_006f5938, uVar8 = DAT_006f593c, *(int *)(*piVar5 + 0x13c) != 0))
    goto LAB_00558b7d;
  }
  if (*(int *)(iVar2 + 0x24) == -1) {
    if (*(int *)(iVar2 + 0x18) == 0) {
      FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
      FUN_004f6994(DAT_006f5954,DAT_006f5950,0,0);
      FUN_0057a7f7(s_UI_Nhood_bdoze_006cda34,0xfffffffc);
      goto LAB_00558d46;
    }
    iVar2 = FUN_004f6994(DAT_006f58fc,DAT_006f58f8,2,0);
    if (iVar2 != 4) goto LAB_00558d46;
    FUN_0057a7f7(s_UI_Nhood_bdoze_demolish_006cda1c,0xfffffffc);
    iVar2 = extraout_ECX[0x1a];
    uVar4 = FUN_005e74ca(3);
    FUN_005dde6d(uVar4);
    uVar1 = FUN_004e2b07(*(undefined4 *)(unaff_EBP + 8),1);
    *(undefined1 *)(unaff_EBP + -0xd) = uVar1;
    FUN_005dde6d(iVar2);
    FUN_005db1e2();
    uVar4 = DAT_006f5924;
    uVar8 = DAT_006f5920;
    if (*(char *)(unaff_EBP + -0xd) == '\0') {
LAB_00558b7d:
      FUN_004f6994(uVar4,uVar8,0,0);
      goto LAB_00558d46;
    }
  }
  else {
    FUN_005d48d9();
    piVar5 = DAT_006fe8bc;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar5 = (int *)(**(code **)(*piVar5 + 4))();
    (**(code **)(*piVar5 + 0x7c))
              (*(int *)(iVar2 + 0x34),*(int *)(iVar2 + 0x34) >> 0x1f,unaff_EBP + -0x20);
    wsprintfA((LPSTR)(unaff_EBP + -0x124),DAT_006f5904,*(undefined4 *)(iVar2 + 0x28),
              *(undefined4 *)(unaff_EBP + -0x20));
    iVar6 = FUN_004f6994(unaff_EBP + -0x124,DAT_006f5900,2,0);
    if (iVar6 == 4) {
      iVar2 = *(int *)(iVar2 + 0x18);
      *(undefined1 *)(unaff_EBP + -0x14) = 0;
      if ((iVar2 == 0) || (iVar2 = FUN_004f6994(DAT_006f58fc,DAT_006f58f8,2,0), iVar2 != 4)) {
        pcVar7 = s_UI_Nhood_bdoze_evict_006cdd48;
      }
      else {
        *(undefined1 *)(unaff_EBP + -0x14) = 1;
        pcVar7 = s_UI_Nhood_bdoze_demolish_006cda1c;
      }
      FUN_0057a7f7(pcVar7,0xfffffffc);
      iVar2 = extraout_ECX[0x1a];
      uVar4 = FUN_005e74ca(3);
      FUN_005dde6d(uVar4);
      uVar1 = FUN_004e2b07(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14));
      *(undefined1 *)(unaff_EBP + -0xd) = uVar1;
      FUN_005dde6d(iVar2);
      FUN_005db1e2();
      if (*(char *)(unaff_EBP + -0xd) == '\0') {
        FUN_004f6994(DAT_006f5924,DAT_006f5920,0,0);
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  iVar2 = extraout_ECX[0x52];
  iVar6 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + -0x14) = iVar6;
  if (iVar6 != iVar2) {
    do {
      if (*(int *)(*(int *)(iVar6 + 0x14) + 0x1d8) == *(int *)(unaff_EBP + 8)) {
        FUN_0054ebd3();
      }
      FUN_0041674f();
      iVar6 = *(int *)(unaff_EBP + -0x14);
    } while (iVar6 != extraout_ECX[0x52]);
  }
  iVar2 = extraout_ECX[0x52];
  iVar6 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + 8) = iVar6;
  if (iVar6 != iVar2) {
    do {
      piVar5 = *(int **)(iVar6 + 0x14);
      if (((piVar5 != (int *)0xfffffe6c) && (piVar5[0x6a] != 0)) &&
         (*(short *)(*(int *)(DAT_006e486c + 0x24) + 0x12e) == 0)) {
        (**(code **)(*piVar5 + 0x160))(1);
      }
      FUN_0041674f();
      iVar6 = *(int *)(unaff_EBP + 8);
    } while (iVar6 != extraout_ECX[0x52]);
  }
  (**(code **)(*extraout_ECX + 0x168))();
LAB_00558d46:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

