
void FUN_00534f0f(void)

{
  char cVar1;
  int unaff_EBP;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while( true ) {
    iVar2 = iVar2 + -0x28;
    cVar1 = (**(code **)(unaff_EBP + 0x34))(unaff_EBP + 0xc,iVar2);
    if (cVar1 == '\0') break;
    FUN_00533dae(iVar2);
  }
  FUN_00533dae(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

