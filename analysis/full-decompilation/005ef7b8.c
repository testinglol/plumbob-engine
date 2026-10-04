
uint FUN_005ef7b8(void)

{
  int iVar1;
  uint uVar2;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar3;
  int *piVar4;
  
  FUN_00634c24();
  iVar1 = (**(code **)(extraout_ECX + 0x2cc))(FUN_005ef885,extraout_ECX);
  if (iVar1 == 0) {
    piVar4 = *(int **)(extraout_ECX + 0xc0);
    piVar3 = (int *)*piVar4;
    if (piVar3 != piVar4) {
      do {
        piVar4 = piVar3 + 2;
        iVar1 = _memcmp(piVar4,&DAT_006f2a14,0x10);
        if (iVar1 == 0) {
          piVar4 = (int *)0x0;
        }
        iVar1 = (**(code **)(extraout_ECX + 0x2c8))(piVar4,piVar3 + 6,0);
        if (iVar1 != 0) {
          *(int *)(unaff_EBP + -0x14) = iVar1;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
          (*(code *)PTR_FUN_00675038)(0);
          iVar1 = *(int *)(unaff_EBP + -0x18);
          *(undefined4 *)(unaff_EBP + -4) = 3;
          goto LAB_005ef87e;
        }
        piVar3 = (int *)*piVar3;
        piVar4 = (int *)0x0;
      } while (piVar3 != (int *)*(int *)(extraout_ECX + 0xc0));
    }
    uVar2 = CONCAT31((int3)((uint)piVar4 >> 8),1);
  }
  else {
    *(int *)(unaff_EBP + -0x14) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    iVar1 = *(int *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 1;
LAB_005ef87e:
    uVar2 = (**(code **)(iVar1 + 0x10))();
    uVar2 = uVar2 & 0xffffff00;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

