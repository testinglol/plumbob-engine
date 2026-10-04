
void FUN_005813bf(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_3;
  puVar3 = param_2;
  while (puVar3 != puVar2) {
    puVar1 = (undefined4 *)*puVar3;
    FUN_00582531(&param_2,puVar3);
    puVar3 = puVar1;
  }
  *param_1 = puVar2;
  return;
}

