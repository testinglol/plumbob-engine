
uint FUN_00605058(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  
  FUN_00634c24();
  piVar3 = (int *)extraout_ECX[2];
  if (piVar3 == (int *)0x0) {
    piVar5 = *(int **)(unaff_EBP + 8);
    piVar8 = piVar5 + 0x3d;
    iVar1 = (**(code **)(*(int *)extraout_ECX[1] + 0x14))
                      ((int *)extraout_ECX[1],*(undefined4 *)(unaff_EBP + 0x10),piVar5[1],
                       *(undefined4 *)(unaff_EBP + 0xc),piVar5[0x56],piVar8);
    if (iVar1 != -0x7789fe3e) goto LAB_00605156;
    iVar1 = (**(code **)(*(int *)extraout_ECX[1] + 0x60))((int *)extraout_ECX[1]);
    if (iVar1 != 0) {
      uVar2 = (**(code **)(*extraout_ECX + 8))();
      if ((char)uVar2 == '\0') goto LAB_00605139;
    }
    iVar1 = (**(code **)(*(int *)piVar5[1] + 0x60))((int *)piVar5[1]);
    if (iVar1 != 0) {
      uVar2 = (**(code **)(*piVar5 + 8))();
      if ((char)uVar2 == '\0') goto LAB_00605139;
    }
    piVar3 = (int *)extraout_ECX[1];
    iVar1 = piVar5[0x56];
    iVar4 = *piVar3;
    uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
    iVar6 = piVar5[1];
LAB_0060514f:
    iVar1 = (**(code **)(iVar4 + 0x14))
                      (piVar3,*(undefined4 *)(unaff_EBP + 0x10),iVar6,uVar7,iVar1,piVar8);
  }
  else {
    piVar5 = *(int **)(unaff_EBP + 8);
    piVar8 = piVar5 + 0x3d;
    iVar1 = (**(code **)(*piVar3 + 0x14))
                      (piVar3,*(undefined4 *)(unaff_EBP + 0x10),piVar5[2],
                       *(undefined4 *)(unaff_EBP + 0xc),piVar5[0x56],piVar8);
    if (iVar1 == -0x7789fe3e) {
      iVar1 = (**(code **)(*(int *)extraout_ECX[2] + 0x60))((int *)extraout_ECX[2]);
      if (iVar1 != 0) {
        uVar2 = (**(code **)(*extraout_ECX + 8))();
        if ((char)uVar2 != '\0') goto LAB_006050b4;
LAB_00605139:
        uVar2 = uVar2 & 0xffffff00;
        goto LAB_0060516c;
      }
LAB_006050b4:
      iVar1 = (**(code **)(*(int *)piVar5[2] + 0x60))((int *)piVar5[2]);
      if (iVar1 != 0) {
        uVar2 = (**(code **)(*piVar5 + 8))();
        if ((char)uVar2 == '\0') goto LAB_00605139;
      }
      piVar3 = (int *)extraout_ECX[2];
      iVar1 = piVar5[0x56];
      iVar4 = *piVar3;
      uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
      iVar6 = piVar5[2];
      goto LAB_0060514f;
    }
  }
LAB_00605156:
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = (**(code **)(*extraout_ECX + 0x20))
                      (piVar5,*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
  }
LAB_0060516c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

