
void FUN_004d3618(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  iVar1 = *unaff_ESI;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar1 + 0x24))(1);
  if (*(char *)(unaff_EBP + 0xb) != '\0') {
    uVar2 = (**(code **)(*unaff_EDI + 0x1c))();
    *(undefined4 *)(unaff_EBP + 8) = uVar2;
    (**(code **)(*unaff_EDI + 0x20))(*(undefined4 *)(unaff_EBP + 0x14));
    iVar1 = *unaff_EDI;
    uVar2 = FUN_005d49d6(0,0,0);
    FUN_004096c2(uVar2);
    (**(code **)(iVar1 + 0x78))();
    (**(code **)(*unaff_EDI + 0x20))(*(undefined4 *)(unaff_EBP + 8));
    iVar1 = *(int *)(unaff_EBP + -0x14);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(unaff_EBP + 0xc);
    *(undefined1 *)(iVar1 + 0x18) = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

