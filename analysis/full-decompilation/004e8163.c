
undefined1 FUN_004e8163(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int unaff_retaddr;
  
  piVar1 = *(int **)(DAT_006e486c + 0x3c);
  uVar3 = 0;
  cVar2 = (**(code **)(*piVar1 + 0x20))(0x10);
  if (cVar2 != '\0') {
    uVar3 = (**(code **)(*piVar1 + 0x9c))(unaff_retaddr,unaff_retaddr + 0x14,param_1,0);
    (**(code **)(*piVar1 + 0x24))(0x10);
  }
  return uVar3;
}

