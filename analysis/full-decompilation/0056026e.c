
void FUN_0056026e(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 8) + -1;
  if ((iVar3 < 0) || (9 < iVar3)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(extraout_ECX + 0xf4 + iVar3 * 4) + 0x194;
  }
  if (iVar3 == 0) goto LAB_0056043a;
  if (*(int *)(iVar3 + 0x14) != 0) {
    FUN_004f6994(DAT_006f5ba4,DAT_006f5ba0,0,0);
    goto LAB_0056043a;
  }
  FUN_00429c21();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0x160),unaff_EBP + -0x2c);
  if (cVar2 == '\0') {
    FUN_00561954(0);
    goto LAB_0056042e;
  }
  uVar5 = DAT_006f5b6c;
  uVar6 = DAT_006f5b68;
  if (*(int *)(iVar3 + 0x10) == 0) {
LAB_00560419:
    FUN_004f6994(uVar5,uVar6,0,0);
  }
  else {
    uVar5 = DAT_006f5b9c;
    uVar6 = DAT_006f5b98;
    if (*(int *)(iVar3 + 0x18) == 0) {
      if ((*(int *)(iVar3 + 0x24) != -1) ||
         (uVar5 = DAT_006f5b6c, uVar6 = DAT_006f5b68,
         *(int *)(unaff_EBP + -0x20) < *(int *)(iVar3 + 0x1c))) goto LAB_00560419;
      iVar3 = FUN_004f6994(DAT_006f5b7c,DAT_006f5b78,2,0);
      if (iVar3 == 4) {
        FUN_00561954(0);
        goto LAB_005603ac;
      }
    }
    else {
      if ((*(int *)(iVar3 + 0x24) != -1) ||
         (uVar5 = DAT_006f5b6c, uVar6 = DAT_006f5b68,
         *(int *)(unaff_EBP + -0x20) < *(int *)(iVar3 + 0x1c))) goto LAB_00560419;
      iVar3 = FUN_004f6994(DAT_006f5b64,DAT_006f5b60,2,0);
      if (iVar3 == 4) {
        FUN_00561954(0);
        puVar4 = (undefined4 *)(extraout_ECX + 0xf4);
        *(undefined4 *)(unaff_EBP + -0x10) = 10;
        do {
          (**(code **)(*(int *)*puVar4 + 0x160))(0);
          puVar4 = puVar4 + 1;
          piVar1 = (int *)(unaff_EBP + -0x10);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
LAB_005603ac:
        FUN_0042b033();
        FUN_0042a9d1(0x1e);
        FUN_0042b902();
        FUN_0042b13f(10);
        FUN_004f1b96(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(extraout_ECX + 0x160));
        FUN_005dac30(0x10,extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
      }
    }
  }
LAB_0056042e:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_0056043a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

