
void FUN_00574a2b(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  
  do {
    *(undefined4 *)(unaff_EBP + -4) = 1;
    unaff_ESI = unaff_ESI + 1;
    *(undefined4 **)(unaff_EBP + -0x14) = unaff_ESI;
    if (unaff_ESI == *(undefined4 **)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    piVar1 = (int *)*unaff_ESI;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar2 = (**(code **)(*piVar1 + 0x14))();
  } while ((((iVar2 == 0x605) || (iVar2 == 0x203)) || (iVar2 == 0xaa7)) ||
          ((iVar2 == 0xaad || (iVar2 == 0xab3))));
  (**(code **)(*(int *)*unaff_ESI + 0x58))();
  FUN_00574a2b();
  return;
}

