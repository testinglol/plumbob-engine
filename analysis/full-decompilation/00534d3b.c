
void FUN_00534d3b(void)

{
  int iVar1;
  char cVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined1 auStack_58 [28];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  int iStack_30;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 0xc);
  iStack_34 = 0x534d55;
  iStack_30 = iVar1;
  FUN_00533d58();
  iStack_30 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iStack_34 = unaff_EBP + -0x34;
  uStack_38 = 0x534d63;
  cVar2 = (**(code **)(unaff_EBP + 0x14))();
  if (cVar2 == '\0') {
    iStack_30 = *(undefined4 *)(unaff_EBP + 0x14);
    *(undefined1 **)(unaff_EBP + 8) = auStack_58;
    FUN_00533d58(unaff_EBP + -0x34);
    FUN_00534f0f(iVar1);
  }
  else {
    iStack_30 = iVar1 + 0x28;
    uStack_38 = *(undefined4 *)(unaff_EBP + 8);
    uStack_3c = 0x534d76;
    iStack_34 = iVar1;
    FUN_00534dbd();
    iStack_30 = unaff_EBP + -0x34;
    iStack_34 = 0x534d85;
    FUN_00533dae();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_30 = 0x534db0;
  FUN_005b8770();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

