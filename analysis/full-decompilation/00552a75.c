
void FUN_00552a75(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined *puVar4;
  undefined4 uVar5;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8) + -0x5a;
  if ((iVar1 < 0) || (8 < iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(extraout_ECX + 0x14c + iVar1 * 4) + 0x194;
  }
  if (iVar1 == 0) goto LAB_00552c52;
  if ((*(int *)(iVar1 + 0x44) < 0x5a) || (0x5c < *(int *)(iVar1 + 0x44))) {
LAB_00552bdf:
    FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
    Sleep(100);
    if (*(char *)(extraout_ECX + 0x12a) != '\0') {
      if ((((*(int *)(iVar1 + 0x44) < 0x5a) || (0x5c < *(int *)(iVar1 + 0x44))) ||
          (iVar1 = FUN_00425db3(*(undefined4 *)(iVar1 + 0x24)), iVar1 == 0)) ||
         (iVar1 = *(int *)(iVar1 + 0x13c), iVar1 == 0)) {
        iVar1 = *(int *)(unaff_EBP + 8);
      }
      FUN_004f1b96(iVar1,0xffffffff);
    }
    FUN_005dac30(0x10,extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
  }
  else {
    if (*(char *)(extraout_ECX + 0x12a) == '\0') {
      pvVar2 = operator_new(0x148);
      *(void **)(unaff_EBP + 8) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (pvVar2 == (void *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_00523434();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      FUN_005a5631(0x14b9,unaff_EBP + -0x10,4);
      if (*(int *)(unaff_EBP + -0x10) != 0) {
        FUN_00523b25(*(undefined4 *)(unaff_EBP + -0x10),1);
      }
      if (iVar1 != 0) {
        FUN_00523771(&DAT_006f54b8);
        puVar4 = &DAT_006f54c4;
LAB_00552ba9:
        FUN_00523be3(puVar4);
        uVar5 = 3;
        uVar3 = FUN_005e50fa(3,3);
        FUN_0052386b(uVar3,uVar5);
      }
    }
    else {
      if (*(int *)(iVar1 + 0x24) != -1) goto LAB_00552bdf;
      pvVar2 = operator_new(0x148);
      *(void **)(unaff_EBP + -0x10) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar2 == (void *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_00523434();
      }
      *(undefined4 *)(unaff_EBP + 8) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005a5631(0x14b9,unaff_EBP + 8,4);
      if (*(int *)(unaff_EBP + 8) != 0) {
        FUN_00523b25(*(undefined4 *)(unaff_EBP + 8),1);
      }
      if (iVar1 != 0) {
        FUN_00523771(&DAT_006f54d0);
        puVar4 = &DAT_006f54dc;
        goto LAB_00552ba9;
      }
    }
    FUN_004f6c41(iVar1,1,3);
    FUN_005da4c7(iVar1);
  }
LAB_00552c52:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

