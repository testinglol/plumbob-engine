
undefined1 FUN_004e8127(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 unaff_retaddr;
  
  uVar3 = 0;
  piVar1 = *(int **)(*(int *)(DAT_006e486c + 0x3c) + 0x5c);
  cVar2 = (**(code **)(*piVar1 + 0x20))(1);
  if (cVar2 != '\0') {
    uVar3 = (**(code **)(*piVar1 + 0x38))(0xffff,unaff_retaddr);
    (**(code **)(*piVar1 + 0x24))(0x10);
  }
  return uVar3;
}

