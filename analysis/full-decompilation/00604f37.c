
uint FUN_00604f37(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar4;
  
  FUN_00634c24();
  uVar1 = *(uint *)(extraout_ECX + 0x160);
  if (uVar1 != 0) {
    if (uVar1 < 2) {
      piVar2 = *(int **)(extraout_ECX + 8);
      if (piVar2 == (int *)0x0) {
        piVar2 = *(int **)(extraout_ECX + 4);
        uVar4 = *(undefined4 *)(extraout_ECX + 0x178);
        iVar3 = *piVar2;
      }
      else {
        iVar3 = *piVar2;
        uVar4 = 0;
      }
      iVar3 = (**(code **)(iVar3 + 0x80))(piVar2,uVar4);
      if (iVar3 != 0) {
        *(int *)(unaff_EBP + -0x14) = iVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
        (*(code *)PTR_FUN_00675038)(0);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        uVar1 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
        uVar1 = uVar1 & 0xffffff00;
        goto LAB_00604fb8;
      }
      *(undefined4 *)(extraout_ECX + 0x160) = 0;
      uVar1 = 0;
    }
    else {
      uVar1 = uVar1 - 1;
      *(uint *)(extraout_ECX + 0x160) = uVar1;
    }
  }
  uVar1 = CONCAT31((int3)(uVar1 >> 8),1);
LAB_00604fb8:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

