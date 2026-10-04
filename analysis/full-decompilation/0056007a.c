
void FUN_0056007a(void)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 8) + -1;
  if ((iVar2 < 0) || (9 < iVar2)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(extraout_ECX + 0xf4 + iVar2 * 4) + 0x194;
  }
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0x24) == -1) {
      pvVar3 = operator_new(0x148);
      *(void **)(unaff_EBP + 8) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_00523434();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (iVar2 != 0) {
        FUN_005d4956(DAT_006f5bb0);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        FUN_00523771(unaff_EBP + -0x1c);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        FUN_005d4956(DAT_006f5bb4);
        *(undefined4 *)(unaff_EBP + -4) = 2;
        FUN_00523be3(unaff_EBP + -0x28);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        uVar7 = 3;
        uVar4 = FUN_005e50fa(3,3);
        FUN_0052386b(uVar4,uVar7);
        *(undefined4 *)(unaff_EBP + 8) = 0;
        FUN_005a5631(0x14b9,unaff_EBP + 8,4);
        if (*(int *)(unaff_EBP + 8) != 0) {
          FUN_00523b25(*(undefined4 *)(unaff_EBP + 8),1);
        }
        FUN_004f6c41(iVar2,1,3);
        FUN_005da4c7(iVar2);
      }
    }
    else {
      FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
      puVar6 = (undefined4 *)(extraout_ECX + 0xf4);
      *(undefined4 *)(unaff_EBP + -0x10) = 10;
      do {
        (**(code **)(*(int *)*puVar6 + 0x160))(0);
        puVar6 = puVar6 + 1;
        piVar1 = (int *)(unaff_EBP + -0x10);
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      FUN_0042b033();
      FUN_0042a9d1(0x1e);
      FUN_0042b902();
      FUN_0042b13f(10);
      iVar5 = FUN_00425db3(*(undefined4 *)(iVar2 + 0x24));
      if (*(int *)(iVar5 + 0x13c) == 0) {
        uVar4 = *(undefined4 *)(unaff_EBP + 8);
      }
      else {
        iVar2 = FUN_00425db3(*(undefined4 *)(iVar2 + 0x24));
        uVar4 = *(undefined4 *)(iVar2 + 0x13c);
      }
      FUN_004f1b96(uVar4,0xffffffff);
      FUN_005dac30(0x10,extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

