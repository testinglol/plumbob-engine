
undefined1 FUN_004e81a4(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int unaff_retaddr;
  
  uVar3 = 0;
  piVar1 = *(int **)(*(int *)(DAT_006e486c + 0x3c) + 0x5c);
  cVar2 = (**(code **)(*piVar1 + 0x20))(0x10);
  if (cVar2 != '\0') {
    uVar3 = (**(code **)(*piVar1 + 0x9c))
                      (*(undefined4 *)(unaff_retaddr + 0x5c),unaff_retaddr + 0x14,param_1,0);
    (**(code **)(*piVar1 + 0x24))(0x10);
  }
  return uVar3;
}

