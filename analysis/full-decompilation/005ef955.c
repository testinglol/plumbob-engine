
uint FUN_005ef955(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar4;
  
  FUN_00634c24();
  piVar2 = *(int **)(extraout_ECX + 0xc0);
  piVar4 = (int *)*piVar2;
  if (piVar4 != piVar2) {
    do {
      iVar1 = (**(code **)(*(int *)piVar4[6] + 0x20))((int *)piVar4[6],0,0,piVar4 + 2,FUN_005ef9d3);
      if (iVar1 != 0) {
        *(int *)(unaff_EBP + -0x14) = iVar1;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
        (*(code *)PTR_FUN_00675038)(0);
        *(undefined4 *)(unaff_EBP + -4) = 1;
        uVar3 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
        uVar3 = uVar3 & 0xffffff00;
        goto LAB_005ef998;
      }
      piVar4 = (int *)*piVar4;
      piVar2 = (int *)0x0;
    } while (piVar4 != (int *)*(int *)(extraout_ECX + 0xc0));
  }
  uVar3 = CONCAT31((int3)((uint)piVar2 >> 8),1);
LAB_005ef998:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

