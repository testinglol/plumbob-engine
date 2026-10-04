
undefined1 FUN_005f87ba(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar2 == '\0') {
    uVar3 = 1;
    goto LAB_005f8842;
  }
  iVar1 = extraout_ECX[0xf];
  *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0xf;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  (**(code **)(iVar1 + 4))();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = (**(code **)(iVar1 + 0x5c))();
  if (cVar2 == '\0') {
    if (*(char *)((int)extraout_ECX + 0x25) != '\0') goto LAB_005f8811;
    uVar3 = (**(code **)(*extraout_ECX + 0xd0))();
  }
  else {
    if (*(char *)((int)extraout_ECX + 0x25) != '\0') {
LAB_005f8811:
      if ((char)extraout_ECX[0x30] == '\0') {
        uVar3 = (**(code **)(*extraout_ECX + 0xd4))(1);
        goto LAB_005f8833;
      }
    }
    uVar3 = 1;
  }
LAB_005f8833:
  iVar1 = extraout_ECX[0xf];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
LAB_005f8842:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

