
undefined4 FUN_005bcf68(void)

{
  char *pcVar1;
  size_t sVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(unaff_EBP + 0x10) == '\0') {
    FUN_005bd6b3(-(uint)(extraout_ECX != 0) & extraout_ECX + 4U,0,0xffffffff,unaff_EBP + 0x13);
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005bdd58(*(undefined4 *)(unaff_EBP + 8));
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005bc7c7();
    FUN_005bc7c7();
    pcVar1 = *(char **)(unaff_EBP + -0x30);
    sVar2 = _strlen(pcVar1);
    uVar3 = FUN_005bd86a(pcVar1,*(undefined4 *)(unaff_EBP + 0xc),sVar2);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x34) = &PTR_LAB_0066933c;
    FUN_00401729();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    pcVar1 = (char *)(**(code **)(**(int **)(unaff_EBP + 8) + 0x14))();
    sVar2 = _strlen(pcVar1);
    uVar3 = FUN_005bd86a(pcVar1,*(undefined4 *)(unaff_EBP + 0xc),sVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

