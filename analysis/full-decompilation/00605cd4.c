
uint FUN_00605cd4(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar2 = (int *)FUN_005ef4c8();
  puVar1 = (undefined4 *)(extraout_ECX + 0x184);
  iVar3 = (**(code **)(*piVar2 + 0x10))(piVar2,0,puVar1,0);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*(int *)*puVar1 + 0x20))((int *)*puVar1,0,*(undefined4 *)(unaff_EBP + 8));
    if (iVar3 == 0) {
      piVar2 = *(int **)(extraout_ECX + 8);
      if (piVar2 == (int *)0x0) {
        iVar3 = (**(code **)(**(int **)(extraout_ECX + 4) + 0x70))
                          (*(int **)(extraout_ECX + 4),*puVar1);
      }
      else {
        iVar3 = (**(code **)(*piVar2 + 0x70))(piVar2,*puVar1);
      }
      if (iVar3 == 0) {
        uVar4 = 1;
        goto LAB_00605db4;
      }
      *(int *)(unaff_EBP + -0x14) = iVar3;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
      (*(code *)PTR_FUN_00675038)(0);
      iVar3 = *(int *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 5;
    }
    else {
      *(int *)(unaff_EBP + -0x14) = iVar3;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
      (*(code *)PTR_FUN_00675038)(0);
      iVar3 = *(int *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 3;
    }
  }
  else {
    *(int *)(unaff_EBP + -0x14) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    iVar3 = *(int *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 1;
  }
  uVar4 = (**(code **)(iVar3 + 0x10))();
  uVar4 = uVar4 & 0xffffff00;
LAB_00605db4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

