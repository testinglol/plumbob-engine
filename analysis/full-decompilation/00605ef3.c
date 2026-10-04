
uint FUN_00605ef3(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = (int *)extraout_ECX[99];
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)extraout_ECX[0x62];
  }
  iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,0,8);
  if (iVar2 == -0x7789fe3e) {
    uVar3 = (**(code **)(*extraout_ECX + 8))();
    if ((char)uVar3 != '\0') {
      piVar1 = (int *)extraout_ECX[99];
      if (piVar1 == (int *)0x0) {
        iVar2 = (**(code **)(*(int *)extraout_ECX[0x62] + 0x2c))((int *)extraout_ECX[0x62],0,1);
      }
      else {
        iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,0,1);
      }
      goto LAB_00605f55;
    }
  }
  else {
LAB_00605f55:
    if (iVar2 == 0) {
      uVar3 = 1;
      goto LAB_00605f86;
    }
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar3 = (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
  }
  uVar3 = uVar3 & 0xffffff00;
LAB_00605f86:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

