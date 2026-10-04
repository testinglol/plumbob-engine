
void FUN_00552fa9(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar8;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  if (iVar1 == 0) {
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    FUN_005dac30(0x10,extraout_ECX,0x3fc);
  }
  else if (iVar1 == 1) {
    ShellExecuteA((HWND)0x0,&DAT_006cd9cc,s_http___thesims_ea_com_exchange_m_006cdd1c,(LPCSTR)0x0,
                  (LPCSTR)0x0,1);
  }
  else if (iVar1 == 2) {
    if (DAT_006f5731 == '\0') {
      DAT_006f5731 = 1;
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
        FUN_0057a7f7(s_music_magictown_credits_006cdd60,0xffffffff);
        iVar1 = extraout_ECX[0x1f];
        iVar2 = extraout_ECX[0x20];
        *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x21];
        (**(code **)(*piVar5 + 0x60))
                  (iVar1,iVar2,*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x22]);
        piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        piVar8 = piVar5;
        uVar7 = (**(code **)(*piVar6 + 8))(piVar5);
        FUN_005daa44(uVar7,piVar8);
        FUN_005da4c7(piVar5);
        FUN_0057a7f7(s_music_magictown_006c7a8c,0xffffffff);
        (**(code **)(*extraout_ECX + 0x94))();
        FUN_00436e16();
        extraout_ECX[0x71] = -1;
        FUN_005db1e2();
      }
      DAT_006f5731 = '\0';
    }
  }
  else if (iVar1 == 3) {
    cVar3 = FUN_00553345();
    if ((cVar3 != '\0') || (cVar3 = FUN_00553f5a(), cVar3 != '\0')) {
      FUN_004f5b8a(1);
    }
    FUN_00554f58();
  }
  else if (iVar1 == 4) {
    FUN_005547b8(2);
  }
  else if ((iVar1 == 5) && (DAT_006f5730 == '\0')) {
    DAT_006f5730 = 1;
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
    FUN_005547b8(0);
    if (piVar5 != (int *)0x0) {
      FUN_0054fcb8(0,0,0);
      (**(code **)(*extraout_ECX + 0x98))();
      iVar1 = extraout_ECX[0x1f];
      iVar2 = extraout_ECX[0x20];
      *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x21];
      (**(code **)(*piVar5 + 0x60))
                (iVar1,iVar2,*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x22]);
      piVar5[0x51] = (int)extraout_ECX;
      *(undefined1 *)((int)piVar5 + 0x159) = 1;
      if (extraout_ECX[0x35] == 1) {
        piVar5[0x52] = extraout_ECX[0x39];
      }
      if (extraout_ECX[0x35] == 2) {
        FUN_0057a7f7(s_UI_Nhood_bdoze_cancel_006cda44,0xfffffffc);
      }
      FUN_0057a7f7(s_bkground_family_006cdd78,0xffffffff);
      piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
      piVar8 = piVar5;
      uVar7 = (**(code **)(*piVar6 + 8))(piVar5);
      FUN_005daa44(uVar7,piVar8);
      FUN_005da4c7(piVar5);
      FUN_0057a7f7(s_music_magictown_006c7a8c,0xffffffff);
      (**(code **)(*extraout_ECX + 0x94))();
      if (extraout_ECX[0x35] != 1) {
        FUN_005e46f0(0);
      }
      FUN_00436e16();
      extraout_ECX[0x71] = -1;
      FUN_005db1e2();
    }
    DAT_006f5730 = '\0';
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

