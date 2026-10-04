
undefined4 __thiscall FUN_0043e17b(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x1250);
  while( true ) {
    if (puVar1 == *(undefined4 **)(param_1 + 0x1254)) {
      return 0;
    }
    if (*(int *)*puVar1 == param_2) break;
    puVar1 = puVar1 + 1;
  }
  return *puVar1;
}

