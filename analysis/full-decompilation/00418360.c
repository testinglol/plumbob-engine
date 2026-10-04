
undefined4 * FUN_00418360(undefined4 *param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  
  if (param_2 != 0) {
    for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
      for (puVar1 = (undefined4 *)param_1[2]; puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        if ((puVar1[4] != 0) && (puVar1[4] == param_2)) {
          if (param_4 != 0) {
            param_1[3] = param_4;
          }
          *param_3 = param_1[1];
          return puVar1;
        }
      }
    }
  }
  return (undefined4 *)0x0;
}

