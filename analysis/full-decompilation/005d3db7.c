
undefined4 __fastcall FUN_005d3db7(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x5c);
  while( true ) {
    if (puVar2 == *(undefined4 **)(param_1 + 0x60)) {
      return 0;
    }
    cVar1 = (**(code **)(*(int *)*puVar2 + 0x24))();
    if (cVar1 != '\0') break;
    puVar2 = puVar2 + 1;
  }
  return 1;
}

