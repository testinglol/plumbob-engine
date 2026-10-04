
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_005591ff(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  switch(*(undefined4 *)(unaff_EBP + 8)) {
  case 0:
    if (DAT_006f59a8 == '\0') {
      DAT_006f59a8 = 1;
      pvVar4 = operator_new(0x15c);
      *(void **)(unaff_EBP + 8) = pvVar4;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar4 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005634a9();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0055b4e6(0);
      if (piVar5 != (int *)0x0) {
        FUN_0054fcb8(0,0,0);
        (**(code **)(*extraout_ECX + 0x98))();
        iVar1 = extraout_ECX[0x1f];
        iVar3 = extraout_ECX[0x20];
        *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x21];
        (**(code **)(*piVar5 + 0x60))
                  (iVar1,iVar3,*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x22]);
        piVar5[0x51] = (int)extraout_ECX;
        if (extraout_ECX[0x35] == 1) {
          piVar5[0x52] = extraout_ECX[0x6b];
        }
        if (extraout_ECX[0x35] == 2) {
          FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
        }
        if (extraout_ECX[0x35] == 3) {
          FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
        }
        FUN_0057a7f7(s_bkground_family_006cdd78,0xffffffff);
        piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        piVar7 = piVar5;
        uVar8 = (**(code **)(*piVar6 + 8))(piVar5);
        FUN_005daa44(uVar8,piVar7);
        FUN_005da4c7(piVar5);
        FUN_0057a7f7(s_bkground_nhood1_006cde14,0xffffffff);
        (**(code **)(*extraout_ECX + 0x94))();
        if (extraout_ECX[0x35] != 1) {
          FUN_005e46f0(0);
        }
        FUN_00436e16();
        extraout_ECX[0x76] = -1;
        FUN_005db1e2();
      }
      DAT_006f59a8 = '\0';
    }
    break;
  case 1:
    uVar8 = 2;
    goto LAB_005593a4;
  case 2:
    cVar2 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x28))();
    if (cVar2 == '\0') break;
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x3e9;
    goto LAB_00559554;
  case 3:
    FUN_0055cb93();
    break;
  case 4:
  case 9:
    if (DAT_006f59a9 == '\0') {
      DAT_006f59a9 = 1;
      pvVar4 = operator_new(0x160);
      *(void **)(unaff_EBP + 8) = pvVar4;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar4 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_0050af9d();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*extraout_ECX + 0x98))();
        FUN_0057a7f7(s_bkground_credits_006cda5c,0xffffffff);
        iVar1 = extraout_ECX[0x1f];
        iVar3 = extraout_ECX[0x20];
        *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x21];
        (**(code **)(*piVar5 + 0x60))
                  (iVar1,iVar3,*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x22]);
        piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        piVar7 = piVar5;
        uVar8 = (**(code **)(*piVar6 + 8))(piVar5);
        FUN_005daa44(uVar8,piVar7);
        FUN_005da4c7(piVar5);
        FUN_0057a7f7(s_bkground_nhood1_006cde14,0xffffffff);
        (**(code **)(*extraout_ECX + 0x94))();
        FUN_00436e16();
        extraout_ECX[0x76] = -1;
        FUN_005db1e2();
      }
      DAT_006f59a9 = '\0';
    }
    break;
  case 5:
    FUN_0042a368();
    goto LAB_00559687;
  case 6:
    FUN_0042a3ca();
LAB_00559687:
    FUN_005596e0();
    break;
  case 7:
    FUN_005597aa();
    break;
  case 8:
    iVar1 = extraout_ECX[0x52];
    iVar3 = *(int *)(iVar1 + 8);
    *(int *)(unaff_EBP + 8) = iVar3;
    if (iVar3 != iVar1) {
      do {
        (**(code **)(**(int **)(iVar3 + 0x14) + 0x160))(0);
        FUN_0041674f();
        iVar3 = *(int *)(unaff_EBP + 8);
      } while (iVar3 != extraout_ECX[0x52]);
    }
    FUN_0042b033();
    FUN_0042a9d1(0x1e);
    FUN_0042b902();
    FUN_0042b13f(10);
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x3fc;
    goto LAB_00559554;
  case 10:
    iVar1 = extraout_ECX[0x52];
    iVar3 = *(int *)(iVar1 + 8);
    *(int *)(unaff_EBP + 8) = iVar3;
    if (iVar3 != iVar1) {
      do {
        (**(code **)(**(int **)(iVar3 + 0x14) + 0x160))(0);
        FUN_0041674f();
        iVar3 = *(int *)(unaff_EBP + 8);
      } while (iVar3 != extraout_ECX[0x52]);
    }
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x406;
    goto LAB_00559554;
  case 0xb:
    uVar8 = 3;
LAB_005593a4:
    FUN_0055b4e6(uVar8);
    break;
  case 0xc:
    iVar1 = extraout_ECX[0x52];
    iVar3 = *(int *)(iVar1 + 8);
    *(int *)(unaff_EBP + 8) = iVar3;
    if (iVar3 != iVar1) {
      do {
        (**(code **)(**(int **)(iVar3 + 0x14) + 0x160))(0);
        FUN_0041674f();
        iVar3 = *(int *)(unaff_EBP + 8);
      } while (iVar3 != extraout_ECX[0x52]);
    }
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x410;
    goto LAB_00559554;
  case 0xd:
    iVar1 = extraout_ECX[0x52];
    iVar3 = *(int *)(iVar1 + 8);
    *(int *)(unaff_EBP + 8) = iVar3;
    if (iVar3 != iVar1) {
      do {
        (**(code **)(**(int **)(iVar3 + 0x14) + 0x160))(0);
        FUN_0041674f();
        iVar3 = *(int *)(unaff_EBP + 8);
      } while (iVar3 != extraout_ECX[0x52]);
    }
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x41a;
LAB_00559554:
    FUN_005dac30(0x10,extraout_ECX,uVar8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

