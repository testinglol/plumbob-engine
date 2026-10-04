
undefined4 * FUN_00418326(undefined4 *param_1,int param_2,short param_3,int param_4)

{
  undefined4 *puVar1;
  
  while( true ) {
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (param_1[1] == param_2) break;
    param_1 = (undefined4 *)*param_1;
  }
  puVar1 = (undefined4 *)param_1[2];
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (*(short *)(puVar1 + 1) == param_3) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  if (param_4 != 0) {
    param_1[3] = param_4;
    return puVar1;
  }
  return puVar1;
}

