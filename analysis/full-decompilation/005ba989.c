
undefined4 FUN_005ba989(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
LAB_005ba9dc:
    uVar3 = 0;
  }
  else {
    do {
      FUN_005bb2f8();
      iVar1 = *(int *)(param_1 + 0x2c);
      if (iVar1 == 0) goto LAB_005ba9dc;
      cVar2 = FUN_005ba810(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(param_1 + 0x1c),0);
    } while (cVar2 == '\0');
    *(undefined1 *)(param_1 + 0x18) = *(undefined1 *)(iVar1 + 0x22);
    *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(iVar1 + 0x21);
    FUN_005d499c(*(int *)(param_1 + 0x2c) + 4);
    uVar3 = 1;
  }
  return uVar3;
}

