
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_005607f3(void)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  int *extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int *piVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  switch(*(undefined4 *)(unaff_EBP + 8)) {
  case 0:
    if (DAT_006f5bc0 == '\0') {
      DAT_006f5bc0 = 1;
      pvVar3 = operator_new(0x15c);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_005634a9();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00561954(0);
      if (piVar4 != (int *)0x0) {
        FUN_0054fcb8(0,0,0);
        (**(code **)(*extraout_ECX + 0x98))();
        iVar6 = extraout_ECX[0x1f];
        iVar1 = extraout_ECX[0x20];
        *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x21];
        (**(code **)(*piVar4 + 0x60))
                  (iVar6,iVar1,*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x22]);
        piVar4[0x51] = (int)extraout_ECX;
        if (extraout_ECX[0x35] == 1) {
          piVar4[0x52] = extraout_ECX[0x58];
        }
        if (extraout_ECX[0x35] == 2) {
          FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
        }
        FUN_0057a7f7(s_bkground_family_006cdd78,0xffffffff);
        piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        piVar7 = piVar4;
        uVar8 = (**(code **)(*piVar5 + 8))(piVar4);
        FUN_005daa44(uVar8,piVar7);
        FUN_005da4c7(piVar4);
        FUN_0057a7f7(s_bkground_nhood1_006cde14,0xffffffff);
        (**(code **)(*extraout_ECX + 0x94))();
        if (extraout_ECX[0x35] != 1) {
          FUN_005e46f0(0);
        }
        FUN_00436e16();
        extraout_ECX[99] = -1;
        FUN_005db1e2();
      }
      DAT_006f5bc0 = '\0';
    }
    break;
  case 1:
    FUN_00561954(2);
    break;
  case 2:
    cVar2 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x28))();
    if (cVar2 == '\0') break;
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x3e9;
    goto code_r0x00560acb;
  case 3:
    FUN_00562616();
    break;
  case 4:
  case 9:
    if (cRam006f5bc1 == '\0') {
      cRam006f5bc1 = 1;
      pvVar3 = operator_new(0x160);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar3 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_0050af9d();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (piVar4 != (int *)0x0) {
        (**(code **)(*extraout_ECX + 0x98))();
        FUN_0057a7f7(s_bkground_credits_006cda5c,0xffffffff);
        iVar6 = extraout_ECX[0x1f];
        iVar1 = extraout_ECX[0x20];
        *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x21];
        (**(code **)(*piVar4 + 0x60))
                  (iVar6,iVar1,*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x22]);
        piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        piVar7 = piVar4;
        uVar8 = (**(code **)(*piVar5 + 8))(piVar4);
        FUN_005daa44(uVar8,piVar7);
        FUN_005da4c7(piVar4);
        FUN_0057a7f7(s_bkground_nhood1_006cde14,0xffffffff);
        (**(code **)(*extraout_ECX + 0x94))();
        FUN_00436e16();
        extraout_ECX[99] = -1;
        FUN_005db1e2();
      }
      cRam006f5bc1 = '\0';
    }
    break;
  case 5:
    FUN_0042a368();
    goto code_r0x00560bfe;
  case 6:
    FUN_0042a3ca();
code_r0x00560bfe:
    func_0x00560c57();
    break;
  case 7:
    FUN_00560d21();
    break;
  case 8:
    piVar4 = extraout_ECX + 0x3d;
    iVar6 = 10;
    do {
      (**(code **)(*(int *)*piVar4 + 0x160))(0);
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_0042b033();
    FUN_0042a9d1(0x1e);
    FUN_0042b902();
    FUN_0042b13f(10);
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x3fc;
    goto code_r0x00560acb;
  case 10:
    piVar4 = extraout_ECX + 0x3d;
    iVar6 = 10;
    do {
      (**(code **)(*(int *)*piVar4 + 0x160))(0);
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x406;
    goto code_r0x00560acb;
  case 0xc:
    piVar4 = extraout_ECX + 0x3d;
    iVar6 = 10;
    do {
      (**(code **)(*(int *)*piVar4 + 0x160))(0);
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x410;
    goto code_r0x00560acb;
  case 0xd:
    piVar4 = extraout_ECX + 0x3d;
    iVar6 = 10;
    do {
      (**(code **)(*(int *)*piVar4 + 0x160))(0);
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    uVar8 = 0x41a;
code_r0x00560acb:
    FUN_005dac30(0x10,extraout_ECX,uVar8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

