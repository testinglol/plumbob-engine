
void FUN_0056a5f4(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar7;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  if (iVar1 == 0) {
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    FUN_005dac30(0x10,extraout_ECX,0x3fc);
  }
  else if (iVar1 == 1) {
    ShellExecuteA((HWND)0x0,&DAT_006cd9cc,s_http___thesims_ea_com_exchange_v_006ce454,(LPCSTR)0x0,
                  (LPCSTR)0x0,1);
  }
  else if (iVar1 == 2) {
    if (DAT_006f6278 == '\0') {
      DAT_006f6278 = 1;
      pvVar3 = operator_new(0x160);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
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
        iVar1 = extraout_ECX[0x1f];
        iVar2 = extraout_ECX[0x20];
        *(int *)(unaff_EBP + -0x14) = extraout_ECX[0x21];
        (**(code **)(*piVar4 + 0x60))
                  (iVar1,iVar2,*(undefined4 *)(unaff_EBP + -0x14),extraout_ECX[0x22]);
        piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        piVar7 = piVar4;
        uVar6 = (**(code **)(*piVar5 + 8))(piVar4);
        FUN_005daa44(uVar6,piVar7);
        FUN_005da4c7(piVar4);
        FUN_0057a7f7(s_station_vacation_006c7ac4,0xffffffff);
        (**(code **)(*extraout_ECX + 0x94))();
        FUN_00436e16();
        extraout_ECX[0x74] = -1;
        FUN_005db1e2();
      }
      DAT_006f6278 = '\0';
    }
  }
  else if (iVar1 == 3) {
    FUN_0056a7f3();
  }
  else if (iVar1 == 4) {
    FUN_0056b2f2(2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

