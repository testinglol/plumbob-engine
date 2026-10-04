
void FUN_005e87ae(void)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBP;
  bool bVar7;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined1 auStack_4c [8];
  undefined4 uStack_44;
  undefined4 uStack_40;
  
  FUN_00634c24();
  bVar7 = extraout_ECX + 0x35 != *(int **)(unaff_EBP + 8);
  if (bVar7) {
    FUN_005d499c();
  }
  cVar1 = FUN_005e8a16();
  if ((bVar7) || (cVar1 != '\0')) {
    iVar2 = (**(code **)(*DAT_006fea20 + 0x68))();
    iVar4 = *DAT_006fea20;
    *(int *)(unaff_EBP + 8) = iVar2 + 6;
    iVar2 = (**(code **)(iVar4 + 0x58))();
    iVar4 = *extraout_ECX;
    *(int *)(unaff_EBP + 0xc) = iVar2 + 2;
    (**(code **)(iVar4 + 0x60))();
    if (extraout_ECX[0x38] == 0) {
      uStack_40 = 0x5e8837;
      pvVar3 = operator_new(100);
      *(void **)(unaff_EBP + -0x10) = pvVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_005dfb13();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x38] = iVar4;
    }
    cVar1 = (**(code **)(*(int *)extraout_ECX[0x38] + 0x18))();
    if (cVar1 == '\0') goto LAB_005e8a01;
    uStack_40 = 0;
    uStack_44 = 0;
    uVar5 = *(undefined4 *)extraout_ECX[0x38];
    *(undefined1 **)(unaff_EBP + -0x10) = auStack_4c;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
    FUN_00436a50();
    cVar1 = (**(code **)(*(int *)(unaff_EBP + -0x10) + 0xc))();
    if (cVar1 == '\0') goto LAB_005e8a01;
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x20))();
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x40))();
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x24))();
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x20))();
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x50))();
    (**(code **)(*(int *)extraout_ECX[0x38] + 0x24))();
    piVar6 = DAT_006fea20;
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    uVar5 = (**(code **)(*piVar6 + 0x1c))();
    *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
    if (extraout_ECX[0x39] == 0) {
      iVar4 = *DAT_006fea20;
LAB_005e8945:
      (**(code **)(iVar4 + 0x20))();
    }
    else if (extraout_ECX[0x39] == 1) {
      iVar4 = *DAT_006fea20;
      goto LAB_005e8945;
    }
    *(int *)(unaff_EBP + 8) = *DAT_006fea20;
    (**(code **)(*(int *)(unaff_EBP + 8) + 0x78))();
    (**(code **)(*DAT_006fea20 + 0x20))();
    if ((undefined4 *)extraout_ECX[0x3a] != (undefined4 *)0x0) {
      uStack_a8 = 0x5e8995;
      (*(code *)**(undefined4 **)extraout_ECX[0x3a])();
    }
    uStack_b4 = 100;
    uStack_a8 = 0x5e899c;
    pvVar3 = operator_new(100);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar3 == (void *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)FUN_005dfb13();
      uStack_b4 = extraout_ECX_00;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x3a] = (int)piVar6;
    if (piVar6 != (int *)0x0) {
      iVar4 = *piVar6;
      uStack_a8 = 0;
      uStack_ac = 0;
      *(undefined4 **)(unaff_EBP + 8) = &uStack_b4;
      uStack_b0 = uStack_b4;
      FUN_00436a50(4);
      FUN_005e8a12();
      uVar5 = FUN_004a946b();
      FUN_005e8a12(uVar5);
      uVar5 = FUN_004a9465();
      (**(code **)(iVar4 + 0xc))(uVar5);
    }
  }
  *(undefined1 *)(extraout_ECX + 0x3b) = 1;
LAB_005e8a01:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

