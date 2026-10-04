
void __fastcall FUN_0042ef0d(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)*param_1;
  puVar3 = (undefined4 *)*puVar1;
  while (puVar3 != puVar1) {
    puVar2 = (undefined4 *)*puVar3;
    FUN_005b8770();
    FUN_0040189d(puVar3,0x14);
    puVar3 = puVar2;
  }
  *puVar1 = puVar1;
  puVar1[1] = puVar1;
  return;
}

