
undefined1 FUN_005b9a53(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = FUN_005b9bbe(*(undefined4 *)(unaff_EBP + 8),0);
  if (cVar1 == '\0') {
    uVar3 = FUN_005bad81(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar2 = FUN_005bf513(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  else {
    uVar2 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

