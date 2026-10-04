
undefined4 FUN_005bce85(void)

{
  char *_Str;
  size_t sVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(unaff_EBP + 0x10) == '\0') {
    FUN_005bd6b3(-(uint)(extraout_ECX != 0) & extraout_ECX + 4U,0,0xffffffff,unaff_EBP + 0x13);
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    sVar1 = _strlen(*(char **)(unaff_EBP + 8));
    FUN_005bddb3(*(undefined4 *)(unaff_EBP + 8),sVar1);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005bc7c7();
    FUN_005bc7c7();
    _Str = *(char **)(unaff_EBP + -0x30);
    sVar1 = _strlen(_Str);
    uVar2 = FUN_005bd86a(_Str,*(undefined4 *)(unaff_EBP + 0xc),sVar1);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x34) = &PTR_LAB_0066933c;
    FUN_00401729();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    sVar1 = _strlen(*(char **)(unaff_EBP + 8));
    uVar2 = FUN_005bd86a(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),sVar1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

