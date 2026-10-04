
uint FUN_00604e57(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *extraout_ECX;
  int *piVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  if (extraout_ECX[0x58] == 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    do {
      piVar2 = (int *)extraout_ECX[2];
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)extraout_ECX[1];
        piVar4 = extraout_ECX + 3;
        iVar1 = *piVar2;
      }
      else {
        iVar1 = *piVar2;
        piVar4 = extraout_ECX + 0x1e;
      }
      iVar1 = (**(code **)(iVar1 + 100))(piVar2,0,piVar4,1,0);
      if (iVar1 != -0x7789fe3e) {
        if (iVar1 == 0) {
          if (extraout_ECX[2] == 0) {
            extraout_ECX[0x5e] = extraout_ECX[0xc];
            iVar1 = extraout_ECX[7];
          }
          else {
            extraout_ECX[0x5e] = extraout_ECX[0x27];
            iVar1 = extraout_ECX[0x22];
          }
          extraout_ECX[0x58] = extraout_ECX[0x58] + 1;
          extraout_ECX[0x5f] = iVar1;
          goto LAB_00604f26;
        }
        break;
      }
      uVar3 = (**(code **)(*extraout_ECX + 8))();
      if ((char)uVar3 == '\0') goto LAB_00604ef1;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < 2);
    *(int *)(unaff_EBP + -0x18) = iVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar3 = (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0x10))();
LAB_00604ef1:
    uVar3 = uVar3 & 0xffffff00;
  }
  else {
    iVar1 = extraout_ECX[0x58] + 1;
    extraout_ECX[0x58] = iVar1;
LAB_00604f26:
    uVar3 = CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

