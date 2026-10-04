
undefined4 FUN_004f29ba(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((int *)extraout_ECX[0x32] == (int *)0x0) {
LAB_004f29e9:
    if (DAT_006f2a10 == '\0') {
      *(undefined1 *)(extraout_ECX + 0x2c) = 1;
      DAT_006f2a10 = 1;
      cVar1 = *(char *)((int)extraout_ECX + 0xaf);
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      if (cVar1 == '\0') {
LAB_004f2a23:
        *(undefined1 *)(unaff_EBP + -0xe) = 0;
      }
      else {
        iVar3 = FUN_00428886();
        *(undefined1 *)(unaff_EBP + -0xe) = 1;
        if (iVar3 == 0) goto LAB_004f2a23;
      }
      cVar1 = FUN_004cebf4();
      if (cVar1 == '\0') {
        if (*(char *)(unaff_EBP + -0xe) == '\0') {
          FUN_005b86bd(&DAT_006f2920);
          *(undefined4 *)(unaff_EBP + -4) = 2;
          FUN_005b86bd(&DAT_006f2910);
          iVar3 = *extraout_ECX;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          iVar3 = (**(code **)(iVar3 + 0x2c))(unaff_EBP + -0x28,unaff_EBP + -0x1c,1,0);
          if (iVar3 == 3) {
            *(undefined1 *)(unaff_EBP + -0xd) = 1;
          }
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        }
        else {
          FUN_005b86bd(&DAT_006f28e0);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_005b86bd(&DAT_006f28d0);
          iVar3 = *extraout_ECX;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          iVar3 = (**(code **)(iVar3 + 0x2c))(unaff_EBP + -0x1c,unaff_EBP + -0x28,3,0);
          if (iVar3 == 2) {
            *(undefined1 *)(unaff_EBP + -0xd) = 1;
          }
          else if (iVar3 == 4) {
            uVar2 = FUN_004f277c();
            *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005b8770();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        }
      }
      else {
        FUN_005b86bd(&DAT_006f2920);
        *(undefined4 *)(unaff_EBP + -4) = 4;
        FUN_005b86bd(&DAT_006f2910);
        iVar3 = *extraout_ECX;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        iVar3 = (**(code **)(iVar3 + 0x2c))(unaff_EBP + -0x34,unaff_EBP + -0x40,1,0);
        if (iVar3 == 3) {
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
        }
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      FUN_005b8770();
      DAT_006f2a10 = '\0';
      if (DAT_006e5438 != '\0') {
        iVar3 = FUN_004f6994(s_Do_you_want_to_save_out_the_log_f_006cac54,s_Sim_Log_006cac7c,2,0);
        if (iVar3 == 4) {
          FUN_0046c225();
        }
      }
      if (*(char *)(unaff_EBP + -0xd) != '\0') {
        *(undefined1 *)(extraout_ECX + 0x2c) = 1;
        (**(code **)(*DAT_006fe8bc + 0x24))(0);
        uVar4 = 1;
        goto LAB_004f2ba1;
      }
      *(undefined1 *)(extraout_ECX + 0x2c) = 0;
    }
  }
  else {
    cVar1 = (**(code **)(*(int *)extraout_ECX[0x32] + 0x8c))(1);
    if (cVar1 == '\0') goto LAB_004f29e9;
  }
  uVar4 = 0;
LAB_004f2ba1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

