
int __thiscall FUN_0059b142(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *param_1;
  puVar2 = (undefined4 *)param_1[1];
  if ((puVar2 == (undefined4 *)param_1[2]) || (param_2 != puVar2)) {
    FUN_0059ce71(param_2,param_3);
  }
  else {
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = *param_3;
    }
    param_1[1] = param_1[1] + 4;
  }
  return *param_1 + ((int)param_2 - iVar1 >> 2) * 4;
}

