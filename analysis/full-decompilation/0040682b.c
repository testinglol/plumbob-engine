
undefined4 __fastcall FUN_0040682b(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  FUN_004659fc(0);
  iVar3 = 0;
  piVar2 = (int *)(param_1 + 0xc);
  while( true ) {
    if ((int *)*piVar2 == (int *)0x0) {
      return 0;
    }
    cVar1 = (**(code **)(*(int *)*piVar2 + 0x28))();
    if (cVar1 != '\0') break;
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 5;
    if (7 < iVar3) {
      return 0;
    }
  }
  return 1;
}

