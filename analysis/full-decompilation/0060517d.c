
uint FUN_0060517d(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *extraout_ECX;
  int *piVar4;
  int unaff_EBP;
  int iVar5;
  undefined4 uVar6;
  
  FUN_00634c24();
  piVar4 = (int *)extraout_ECX[2];
  if (piVar4 == (int *)0x0) {
    piVar1 = *(int **)(unaff_EBP + 8);
    iVar2 = (**(code **)(*(int *)extraout_ECX[1] + 0x14))
                      ((int *)extraout_ECX[1],*(undefined4 *)(unaff_EBP + 0x10),piVar1[1],
                       *(undefined4 *)(unaff_EBP + 0xc),piVar1[0x56] | 0x1000000,piVar1 + 0x3d);
    if (iVar2 != -0x7789fe3e) goto LAB_006052a4;
    iVar2 = (**(code **)(*(int *)extraout_ECX[1] + 0x60))((int *)extraout_ECX[1]);
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*extraout_ECX + 8))();
      if ((char)uVar3 == '\0') goto LAB_006052d1;
    }
    iVar2 = (**(code **)(*(int *)piVar1[1] + 0x60))((int *)piVar1[1]);
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*piVar1 + 8))();
      if ((char)uVar3 == '\0') goto LAB_006052d1;
    }
    piVar4 = (int *)extraout_ECX[1];
    uVar3 = piVar1[0x56];
    iVar2 = *piVar4;
    uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
    iVar5 = piVar1[1];
LAB_0060529d:
    iVar2 = (**(code **)(iVar2 + 0x14))
                      (piVar4,*(undefined4 *)(unaff_EBP + 0x10),iVar5,uVar6,uVar3 | 0x1000000,
                       piVar1 + 0x3d);
LAB_006052a4:
    if (iVar2 == 0) {
      uVar3 = 1;
      goto LAB_006052d7;
    }
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar3 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
  }
  else {
    piVar1 = *(int **)(unaff_EBP + 8);
    iVar2 = (**(code **)(*piVar4 + 0x14))
                      (piVar4,*(undefined4 *)(unaff_EBP + 0x10),piVar1[2],
                       *(undefined4 *)(unaff_EBP + 0xc),piVar1[0x56] | 0x1000000,piVar1 + 0x3d);
    if (iVar2 != -0x7789fe3e) goto LAB_006052a4;
    iVar2 = (**(code **)(*(int *)extraout_ECX[2] + 0x60))((int *)extraout_ECX[2]);
    if (iVar2 == 0) {
LAB_006051e8:
      iVar2 = (**(code **)(*(int *)piVar1[2] + 0x60))((int *)piVar1[2]);
      if (iVar2 != 0) {
        uVar3 = (**(code **)(*piVar1 + 8))();
        if ((char)uVar3 == '\0') goto LAB_006052d1;
      }
      piVar4 = (int *)extraout_ECX[2];
      uVar3 = piVar1[0x56];
      iVar2 = *piVar4;
      uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
      iVar5 = piVar1[2];
      goto LAB_0060529d;
    }
    uVar3 = (**(code **)(*extraout_ECX + 8))();
    if ((char)uVar3 != '\0') goto LAB_006051e8;
  }
LAB_006052d1:
  uVar3 = uVar3 & 0xffffff00;
LAB_006052d7:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

