
undefined4 FUN_00412825(void)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  FUN_006358b0(unaff_EBP + -0x11c,puVar1[1]);
  iVar5 = 0;
  iVar3 = (**(code **)*puVar1)();
  if (0 < iVar3) {
    do {
      if (*(char *)(unaff_EBP + -0x11c + iVar5) == '/') {
        *(undefined1 *)(unaff_EBP + -0x11c + iVar5) = 0x5c;
      }
      iVar5 = iVar5 + 1;
      iVar3 = (**(code **)*puVar1)();
    } while (iVar5 < iVar3);
  }
  FUN_005b870f(unaff_EBP + -0x11c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8e25();
  cVar2 = FUN_005b9b60(unaff_EBP + -0x11c);
  if (cVar2 == '\0') {
    uVar4 = FUN_0041229a(unaff_EBP + -0x18);
  }
  else {
    uVar4 = FUN_00412615(unaff_EBP + -0x18);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

