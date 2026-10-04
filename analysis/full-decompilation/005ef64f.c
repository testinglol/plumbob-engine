
void FUN_005ef64f(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int extraout_ECX;
  int *piVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*(int *)(extraout_ECX + 0x48) + 0x18))();
  if (*(char *)(unaff_EBP + 8) == cVar1) goto LAB_005ef7a7;
  iVar2 = *(int *)(extraout_ECX + 0x9c);
  piVar4 = (int *)(extraout_ECX + 0x9c);
  *(int **)(unaff_EBP + -0x10) = piVar4;
  (**(code **)(iVar2 + 4))();
  if (*(int *)(extraout_ECX + 0x4c) != 1) {
    (**(code **)(*(int *)(extraout_ECX + 0xfc) + 0x18))();
  }
  FUN_005efa04(*(undefined4 *)(unaff_EBP + 8));
  if (*(char *)(unaff_EBP + 8) == '\0') {
    piVar3 = DAT_006feca0;
    if (DAT_006feca0 == (int *)0x0) {
      piVar3 = DAT_006fec9c;
    }
    iVar2 = (**(code **)(*piVar3 + 0x4c))(piVar3);
    if (iVar2 == 0) goto LAB_005ef759;
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    iVar2 = *(int *)(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -4) = 3;
  }
  else {
    if (DAT_006feca0 == (int *)0x0) {
      iVar2 = (**(code **)(*DAT_006fec9c + 0x54))
                        (DAT_006fec9c,DAT_006ff088,DAT_006ff08c,DAT_006ff090);
    }
    else {
      iVar2 = (**(code **)(*DAT_006feca0 + 0x54))
                        (DAT_006feca0,DAT_006ff088,DAT_006ff08c,DAT_006ff090,0,0);
    }
    if (iVar2 == 0) {
      piVar4 = *(int **)(unaff_EBP + -0x10);
LAB_005ef759:
      *(undefined1 *)(extraout_ECX + 0x7c) = *(undefined1 *)(unaff_EBP + 8);
      if (*(int *)(extraout_ECX + 0x4c) != 2) {
        (**(code **)(*(int *)(extraout_ECX + 0xfc) + 0x10c))();
        (**(code **)(*(int *)(extraout_ECX + 0xfc) + 0x14))();
      }
      if (*(char *)(unaff_EBP + 8) == '\0') {
        (**(code **)(*(int *)(extraout_ECX + 0x1a8) + 0x1ac))();
      }
      else {
        (**(code **)(*(int *)(extraout_ECX + 0x1a8) + 0x1b0))();
      }
      (**(code **)(*piVar4 + 8))();
      goto LAB_005ef7a7;
    }
    *(int *)(unaff_EBP + -0x18) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    iVar2 = *(int *)(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -4) = 1;
  }
  (**(code **)(iVar2 + 0x10))();
LAB_005ef7a7:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

