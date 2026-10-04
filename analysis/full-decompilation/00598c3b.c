
undefined1 FUN_00598c3b(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  
  while( true ) {
    if (param_1 == 0) {
      return 1;
    }
    iVar1 = *(int *)(param_1 + 0x28);
    cVar2 = FUN_00595b1f(param_2);
    if ((cVar2 == '\0') || ((iVar1 != 0 && (cVar2 = FUN_00598c3b(iVar1,param_2), cVar2 == '\0'))))
    break;
    param_1 = *(int *)(param_1 + 0x20);
  }
  return 0;
}

