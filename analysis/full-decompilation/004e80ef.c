
undefined1 FUN_004e80ef(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  undefined4 unaff_retaddr;
  
  piVar1 = *(int **)(DAT_006e486c + 0x3c);
  uVar3 = 0;
  cVar2 = (**(code **)(*piVar1 + 0x20))(1);
  if (cVar2 != '\0') {
    uVar3 = (**(code **)(*piVar1 + 0x38))(unaff_retaddr,param_1);
    (**(code **)(*piVar1 + 0x24))(0x10);
  }
  return uVar3;
}

