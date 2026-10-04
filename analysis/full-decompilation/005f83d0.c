
undefined4 FUN_005f83d0(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  uint uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x2c) = 1;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  uVar3 = FUN_005fd96f();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  piVar5 = DAT_006fed70;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = (**(code **)(*piVar5 + 8))();
  if (cVar2 != '\0') {
    cVar2 = *(char *)(unaff_EBP + 0x14);
    *(undefined1 *)(extraout_ECX + 0x1b) = *(undefined1 *)(unaff_EBP + 0x18);
    if (cVar2 == '\0') {
      iVar7 = *(int *)(unaff_EBP + 8);
      *(int *)(unaff_EBP + 8) = (*(int *)(unaff_EBP + 0xc) - iVar7) / 10;
      *(uint *)(unaff_EBP + 0x18) = *(uint *)(unaff_EBP + 0x10) / 10;
      (**(code **)(*extraout_ECX + 0x78))(iVar7);
      *(undefined4 *)(unaff_EBP + 0x14) = 10;
      do {
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        FUN_005772e2();
        while( true ) {
          uVar6 = FUN_005fd8ea();
          if (*(uint *)(unaff_EBP + 0x18) <= uVar6) break;
          FUN_005d8e59(0);
        }
        iVar7 = iVar7 + *(int *)(unaff_EBP + 8);
        (**(code **)(*extraout_ECX + 0x78))(iVar7);
        piVar5 = (int *)(unaff_EBP + 0x14);
        *piVar5 = *piVar5 + -1;
      } while (*piVar5 != 0);
    }
    else {
      if (extraout_ECX[0x1a] != 0) {
        uVar3 = 0;
        goto LAB_005f84ff;
      }
      pvVar4 = operator_new(0x20);
      *(void **)(unaff_EBP + 0x18) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar4 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_005ed88f();
      }
      extraout_ECX[0x1a] = (int)piVar5;
      iVar7 = *piVar5;
      *(undefined1 *)(unaff_EBP + -4) = 0;
      (**(code **)(iVar7 + 0x20))(FUN_005f8510,extraout_ECX);
      (*(code *)**(undefined4 **)extraout_ECX[0x1a])(100);
      iVar7 = *(int *)(unaff_EBP + 0xc);
      iVar1 = *(int *)(unaff_EBP + 8);
      uVar3 = *(undefined4 *)(unaff_EBP + 8);
      extraout_ECX[0x1d] = iVar7;
      extraout_ECX[0x1c] = (iVar7 - iVar1) / 10;
      (**(code **)(*extraout_ECX + 0x78))(uVar3);
      (**(code **)(*(int *)extraout_ECX[0x1a] + 0x10))(*(uint *)(unaff_EBP + 0x10) / 10);
    }
  }
  uVar3 = 1;
LAB_005f84ff:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

